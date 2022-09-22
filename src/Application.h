#pragma once

#include <memory>
#include "Window.h"

namespace gameModule
{
    class Application
    {
    public:
	Application(const char *title, unsigned int width, unsigned int height);
	~Application() = default;

	Application() = delete;
	Application(const Application& app) = delete;
	Application& operator=(const Application& app) = delete;

	void run();

    private:
	std::unique_ptr<Window> m_window;
	bool m_isRunning = true;

    private:
	void init(WindowData& data);
    };
}
