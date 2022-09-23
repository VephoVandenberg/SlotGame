#include <GL/glew.h>
#include <stdlib.h>

#include "Window.h"

using namespace gameModule;

bool Window::s_GLFWInitialized = false;
bool Window::s_GLEWInitialized = false;

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
	if (!glfwInit())
	{
	    exit(EXIT_FAILURE); // Failed to initialize glfw
	}
	s_GLFWInitialized = true;
    }
    m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title, nullptr, nullptr);
    glfwMakeContextCurrent(m_window);

    if (!s_GLEWInitialized)
    {
	if (glewInit() != GLEW_OK)
	{
	    exit(EXIT_FAILURE); // Failed to initialize glew
	}
	s_GLEWInitialized = true;
    }
}

void Window::clear()
{
    glClearColor(0.3f, 0.4f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::update()
{
    glfwPollEvents();
    glfwSwapBuffers(m_window);
}

void Window::setMouseButtonCallback()
{
    
}

void Window::setMouseMoveCallback()
{

}

void Window::setWindowCloseCallback()
{

}
