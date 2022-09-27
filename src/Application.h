#pragma once

#include <memory>
#include <array>
#include <deque>
#include <unordered_map>
#include <string>

#include "Window.h"
#include "Block.h"
#include "Button.h"
#include "Slot.h"
#include "Renderer.h"
#include "Events.h"
#include "../src/states/IdleState.h"
#include "../src/states/ActiveState.h"

namespace gameModule
{
    class Application
    {
    public:
	Application(const char *title, unsigned int width, unsigned int height);
	~Application() = default;

	void run();
	void onEvent(Event& event);

	Application() = delete;
	Application(const Application& app) = delete;
	Application& operator=(const Application& app) = delete;

    private:
	const unsigned int m_slotsInDrum = 6;
	enum BorderDirs
	{
	    Up,
	    Down,
	    Left,
	    Right
	};

	std::unique_ptr<Window> m_window;
	std::unique_ptr<Button> m_startButton;
	std::unique_ptr<Button> m_stopButton;
	std::unique_ptr<Renderer> m_renderer;
	std::unique_ptr<State> m_gameState;
	
	std::array<std::deque<Slot>, 4> m_slots;
	std::array<Block, 4> m_borders;

	std::unordered_map<SlotType, std::string> m_slotTypeHolder;

	bool m_isRunning = false;
		
    private:
	void init(WindowData& data);
	void setBorders();
	void setButtons();
	void setSlots();
	void render();
    };
}
