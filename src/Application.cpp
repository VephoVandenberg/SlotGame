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
}

void Application::run()
{
    while (m_isRunning)
    {
        m_window->update();
    }
}
