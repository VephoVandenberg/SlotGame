#include "Window.h"

using namespace gameModule;

bool Window::s_GLFWInitialized = false;

Window::Window(const WindowData& data) :
    m_data(data)
{
    init();
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
}

void Window::init()
{
    if (!s_GLFWInitialized)
    {
	glfwInit();
	s_GLFWInitialized = true;
    }
    m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title, nullptr, nullptr);
    glfwMakeContextCurrent(m_window);
}

void Window::update()
{
    glfwPollEvents();
    glfwSwapBuffers(m_window);
}
