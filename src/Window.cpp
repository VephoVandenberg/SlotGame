#include <GL/glew.h>
#include <stdlib.h>

#include "Window.h"
#include "Events.h"

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
    glfwSetWindowUserPointer(m_window, &m_data);
    
    if (!s_GLEWInitialized)
    {
	if (glewInit() != GLEW_OK)
	{
	    exit(EXIT_FAILURE); // Failed to initialize glew
	}
	s_GLEWInitialized = true;
    }

    glfwSetWindowCloseCallback(m_window, [](GLFWwindow *window)
					     {
						 auto data = *(WindowData*)glfwGetWindowUserPointer(window);

						 WindowClosedEvent event;

						 data.func(event);
					     });

    glfwSetCursorPosCallback(m_window, [](GLFWwindow *window, double xPos, double yPos)
					   {
					       auto data = *(WindowData*)glfwGetWindowUserPointer(window);

					       CursorMovedEvent event;
					       event.position.x = xPos;
					       event.position.y = yPos;
					       
					       data.func(event);
					   });

    glfwSetMouseButtonCallback(m_window, [](GLFWwindow *window, int button, int action, int mods)
					     {
						 auto data = *(WindowData*)glfwGetWindowUserPointer(window);
						 MouseButtonClickedEvent event;
						 event.button = button;
						 event.action = action;
						 event.mods = mods;

						 switch(event.action)
						 {
						 case GLFW_PRESS:
						 {
						     data.func(event);
						     break;
						 }
						 }
						 
					     });
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

