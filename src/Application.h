#pragma once

#include <memory>
#include <array>

#include "Block.h"
#include "Window.h"
#include "Button.h"
#include "Renderer.h"

namespace gameModule
{
    class Application
    {
    public:
	Application(const char *title, unsigned int width, unsigned int height);
	~Application() = default;

	void run();

	Application() = delete;
	Application(const Application& app) = delete;
	Application& operator=(const Application& app) = delete;

    private:
	std::unique_ptr<Window> m_window;
	std::unique_ptr<Button> m_startButton;
	std::unique_ptr<Button> m_stopButton;
	std::unique_ptr<Renderer> m_renderer;

	enum BorderDirs
	{
	    Up,
	    Down,
	    Left,
	    Right
	};

	std::array<Block, 4> m_borders;                
	
	bool m_isRunning = true;
	
    private:
	void init(WindowData& data);
	void setBorders();
	void setButtons();
    };
}
