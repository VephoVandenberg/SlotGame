
#include <glm/gtc/matrix_transform.hpp>

#include <functional>
#include <algorithm>
#include <iostream>
#include <random>

#include "ResourceManager.h"
#include "Application.h"

using namespace gameModule;


Application::Application(const char *title, unsigned int width, unsigned int height) :
    m_isRunning(true)
{
    WindowData data;
    data.title = title;
    data.width = width;
    data.height = height;
    data.func = std::bind(&Application::onEvent, this, std::placeholders::_1);
    
    init(data);
}

void Application::init(WindowData& data)
{
    m_window = std::unique_ptr<Window>(new Window(data));
    m_renderer = std::unique_ptr<Renderer>(new Renderer());

    m_slotTypeHolder[SlotType::Blue] = "blue";
    m_slotTypeHolder[SlotType::Purple] = "purple";
    m_slotTypeHolder[SlotType::Gold] = "gold";
    m_slotTypeHolder[SlotType::Red] = "red";
    m_slotTypeHolder[SlotType::Grey] = "grey";
    m_slotTypeHolder[SlotType::Pink] = "pink";

    ResourceManager::loadTexture("textures/start.png", "start");
    ResourceManager::loadTexture("textures/stop.png", "stop");
    
    ResourceManager::loadTexture("textures/blue.png", m_slotTypeHolder[SlotType::Blue].c_str());
    ResourceManager::loadTexture("textures/purple.png", m_slotTypeHolder[SlotType::Purple].c_str());
    ResourceManager::loadTexture("textures/gold.png", m_slotTypeHolder[SlotType::Gold].c_str());
    ResourceManager::loadTexture("textures/red.png", m_slotTypeHolder[SlotType::Red].c_str());
    ResourceManager::loadTexture("textures/grey.png", m_slotTypeHolder[SlotType::Grey].c_str());
    ResourceManager::loadTexture("textures/pink.png", m_slotTypeHolder[SlotType::Pink].c_str());

    ResourceManager::loadTexture("textures/0.png", "0");
    ResourceManager::loadTexture("textures/1.png", "1");
    ResourceManager::loadTexture("textures/2.png", "2");
    ResourceManager::loadTexture("textures/3.png", "3");
    ResourceManager::loadTexture("textures/4.png", "4");
    ResourceManager::loadTexture("textures/5.png", "5");
    ResourceManager::loadTexture("textures/6.png", "6");
    ResourceManager::loadTexture("textures/7.png", "7");
    ResourceManager::loadTexture("textures/8.png", "8");
    ResourceManager::loadTexture("textures/9.png", "9");
    
    
    setBorders();
    setButtons();
    setSlots();
    setScore();

    m_gameState = std::unique_ptr<State>(new IdleState(m_slots));

    
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(m_window->getWidth()), static_cast<float>(m_window->getHeight()), 0.0f, -1.0f, 1.0f);
    
    ResourceManager::loadShader("shaders/generalShader.vert", "shaders/generalShader.frag", "general");
    
    ResourceManager::getShader("general").use();
    ResourceManager::getShader("general").setUniform1i("image", 0);
    ResourceManager::getShader("general").setUniform4m("projection", projection);
}

void Application::onEvent(Event& event)
{
    switch(event.getType())
    {
    case EventType::ButtonClicked:
    {
	if (m_startButton->checkIfTarget() && !m_startButton->isClicked() && m_gameState->getType() == StateType::Idle)
	{
	    m_gameState = std::make_unique<ActiveState>(m_slots);
	    m_startButton->click();
	}
	else if (m_stopButton->checkIfTarget() && !m_stopButton->isClicked() && m_gameState->getType() == StateType::Active)
	{
	    dynamic_cast<ActiveState&>(*m_gameState).stop();
	    m_stopButton->click();
	}
	break;
    }
    case EventType::CursorMoved:
    {
        m_startButton->checkCursorButtonCollide(dynamic_cast<CursorMovedEvent&>(event).position);
	m_stopButton->checkCursorButtonCollide(dynamic_cast<CursorMovedEvent&>(event).position);
	break;
    }
    case EventType::WindowClosed:
    {
	m_isRunning = false;
	break;
    }
    }
}

void Application::run()
{
    float prevFrame = 0.0f;
    while (m_isRunning)
    {
	float currentFrame = glfwGetTime();
	float dt = currentFrame - prevFrame;
	prevFrame = currentFrame;
	
        m_window->clear();

	
	if (!m_gameState->update(dt))
	{
	    m_gameState = std::make_unique<ScoreState>(m_slots, m_scoreNumber);
	}
	else if (m_gameState->getType() == StateType::Score &&
		 m_gameState->getStatus() == true)
	{
	    updateScore();
	    m_gameState = std::make_unique<IdleState>(m_slots);
	    m_startButton->loosen();
	    m_stopButton->loosen();
	}
	render();

	m_window->update();
    }
}


void Application::setBorders()
{
    glm::vec3 borderColor = glm::vec3(0.2f, 0.3f, 0.3f);
    // Up
    glm::vec2 borderSize = glm::vec2(m_window->getWidth(), 50.0f);
    glm::vec2 borderCoords = glm::vec2(0.0f, 0.0f);
    m_borders[BorderDirs::Up] = Block(borderCoords, borderSize, borderColor);
    
    // Down
    borderSize = glm::vec2(m_window->getWidth(), 50.0f);
    borderCoords = glm::vec2(0.0f, m_window->getHeight() - borderSize.y);
    m_borders[BorderDirs::Down] = Block(borderCoords, borderSize, borderColor);

    // Left
    borderSize = glm::vec2(100.0f, m_window->getHeight() - 100.0f);
    borderCoords = glm::vec2(0.0f, 50.0f);
    m_borders[BorderDirs::Left] = Block(borderCoords, borderSize, borderColor);

    // Right
    borderSize = glm::vec2(400.0f, m_window->getHeight() - 100.0f);
    borderCoords = glm::vec2(m_window->getWidth() - borderSize.x, 50.0f);
    m_borders[BorderDirs::Right] = Block(borderCoords, borderSize, borderColor);
}

void Application::setButtons()
{
    glm::vec3 color = glm::vec3(0.0f, 0.9f, 0.0f);
    glm::vec2 buttonSize = glm::vec2(200.0f, 100.0f);
    glm::vec2 buttonCoords = glm::vec2(m_window->getWidth() - 300, buttonSize.y);

    m_startButton = std::unique_ptr<Button>(new Button(buttonCoords, buttonSize, color,
						       ResourceManager::getTexture("start")));

    color = glm::vec3(0.9f, 0.0f, 0.0f);
    buttonSize = glm::vec2(200.0f, 100.0f);
    buttonCoords = glm::vec2(m_window->getWidth() - 300, m_window->getHeight() - 2 * buttonSize.y);
    
    m_stopButton = std::unique_ptr<Button>(new Button(buttonCoords, buttonSize, color,
						      ResourceManager::getTexture("stop")));
}

void Application::setScore()
{
    glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec2 numberSize = glm::vec2(70.0f, 70.0f);
    glm::vec2 numberCoords = glm::vec2(m_window->getWidth() - 375, m_window->getHeight() / 2 - numberSize.y/2);

    for (unsigned int number = 0; number < m_score.size(); number++)
    {
	m_score[number] = Block(numberCoords, numberSize, color, ResourceManager::getTexture("2"));
	numberCoords.x += numberSize.x;
    }
}

void Application::updateScore()
{
    if (m_scoreNumber > 0)
    {
	glm::vec2 numberSize = glm::vec2(70.0f, 70.0f);      
	
	std::string scoreString = std::to_string(m_scoreNumber);
	std::reverse(scoreString.begin(), scoreString.end());
	
	unsigned int stringInd = 0;
	
	std::cout << m_scoreNumber << std::endl;
	std::cout << scoreString << std::endl;
	for (unsigned int index = m_score.size() - 1; index > scoreString.length(); index--)
	{
	    
	    m_score[index] = Block(m_score[index].getPosition(), numberSize, m_score[index].getColor(),
				   ResourceManager::getTexture(std::string(1, scoreString[stringInd]).c_str()));
	    stringInd++;
	}
    }
}

void Application::setSlots()
{
    glm::vec2 slotSize = glm::vec2(150.0f, 100.0f);
    unsigned int slotTypes[m_slotsInDrum];
    
    for (unsigned int drum = 0; drum < m_slots.size(); drum++)
    {
	double posX = 100.0f + (slotSize.x * drum);
	for (unsigned int slot = 0; slot < m_slotsInDrum; slot++)
	{
	    double posY = -50.0f + (slotSize.y * slot);
	    glm::vec2 slotCoords = glm::vec2(posX, posY);

	    if (drum == 0)
	    {
		slotTypes[slot] = slot;
	    }
	    auto type = static_cast<SlotType>(slotTypes[slot]);
	    m_slots[drum].push_back(Slot(type,
					 slotCoords, slotSize,
					 ResourceManager::getTexture(m_slotTypeHolder[type].c_str())));

	}

	auto rnd = std::default_random_engine {};
	std::shuffle(slotTypes, slotTypes + m_slotsInDrum, rnd);
    }
}

void Application::render()
{
    for (auto& drum : m_slots)
    {
	for (auto& slot: drum)
	{
	    slot.draw(*m_renderer, ResourceManager::getShader("general"));
	}
    }

    for (auto& border : m_borders)
    {
	border.draw(*m_renderer, ResourceManager::getShader("general"));
    }

    for (auto& number : m_score)
    {
	number.draw(*m_renderer, ResourceManager::getShader("general"));
    }
	
    m_startButton->draw(*m_renderer, ResourceManager::getShader("general"));
    m_stopButton->draw(*m_renderer, ResourceManager::getShader("general"));
}
