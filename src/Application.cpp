#include <glm/gtc/matrix_transform.hpp>

#include "ResourceManager.h"
#include "Application.h"

using namespace gameModule;

Application::Application(const char *title, unsigned int width, unsigned int height)
{
    WindowData data = {title, width, height};
    init(data);
}

void Application::init(WindowData& data)
{   
    m_window = std::unique_ptr<Window>(new Window(data));
    m_renderer = std::unique_ptr<Renderer>(new Renderer());

    setBorders();
    setButtons();
    
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(m_window->getWidth()), static_cast<float>(m_window->getHeight()), 0.0f, -1.0f, 1.0f);

    ResourceManager::loadShader("shaders/generalShader.vert", "shaders/generalShader.frag", "general");
    ResourceManager::getShader("general").use();
    ResourceManager::getShader("general").setUniform4m("projection", projection);
}

void Application::run()
{
    while (m_isRunning)
    {
        m_window->clear();

	for (auto& border : m_borders)
	{
	    border.draw(*m_renderer, ResourceManager::getShader("general"));
	}
	
	m_startButton->draw(*m_renderer, ResourceManager::getShader("general"));
	m_stopButton->draw(*m_renderer, ResourceManager::getShader("general"));

	m_window->update();
    }
}

void Application::setBorders()
{
    glm::vec3 borderColor = glm::vec3(0.2f, 0.3f, 0.3f);
    // Up
    glm::vec2 borderSize = glm::vec2(m_window->getWidth(), 100.0f);
    glm::vec2 borderCoords = glm::vec2(0.0f, 0.0f);
    m_borders[BorderDirs::Up] = Block(borderCoords, borderSize, borderColor);
    
    // Down
    borderSize = glm::vec2(m_window->getWidth(), 100.0f);
    borderCoords = glm::vec2(0.0f, m_window->getHeight() - borderSize.y);
    m_borders[BorderDirs::Down] = Block(borderCoords, borderSize, borderColor);

    // Left
    borderSize = glm::vec2(100.0f, m_window->getHeight() - 200.0f);
    borderCoords = glm::vec2(0.0f, 100.0f);
    m_borders[BorderDirs::Left] = Block(borderCoords, borderSize, borderColor);

    // Right
    borderSize = glm::vec2(400.0f, m_window->getHeight() - 200.0f);
    borderCoords = glm::vec2(m_window->getWidth() - borderSize.x, 100.0f);
    m_borders[BorderDirs::Right] = Block(borderCoords, borderSize, borderColor);
}

void Application::setButtons()
{
    glm::vec3 color = glm::vec3(0.0f, 0.9f, 0.0f);
    glm::vec2 buttonSize = glm::vec2(200.0f, 50.0f);
    glm::vec2 buttonCoords = glm::vec2(m_window->getWidth() - 300, 2 * buttonSize.y);
    
    m_startButton = std::unique_ptr<Button>(new Button(buttonCoords, buttonSize, color));

    color = glm::vec3(0.9f, 0.0f, 0.0f);
    buttonSize = glm::vec2(200.0f, 50.0f);
    buttonCoords = glm::vec2(m_window->getWidth() - 300, m_window->getHeight() - 3 * buttonSize.y);
    
    m_stopButton = std::unique_ptr<Button>(new Button(buttonCoords, buttonSize, color));
}
