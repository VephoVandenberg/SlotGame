#pragma once

#include <GLFW/glfw3.h>

namespace gameModule
{
    struct WindowData
    {
	const char *title;
	unsigned int width, height;
    };
    
    class Window
    {
    public:
	Window(const WindowData& data);
	~Window();

	void update();
	void clear();
	
	void setMouseButtonCallback();
	void setMouseMoveCallback();
	void setWindowCloseCallback();
	
	inline unsigned int getWidth() const { return m_data.width; }
	inline unsigned int getHeight() const { return m_data.height; } 

	Window() = delete;
	Window& operator=(const Window& window) = delete;
    private:
	GLFWwindow *m_window = nullptr;
	WindowData m_data;
	
	static bool s_GLFWInitialized;
	static bool s_GLEWInitialized;

    private:
	void init();
    };
}
