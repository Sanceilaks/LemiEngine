#include "Window.h"

Window::Window(const std::string& title, int w, int h, bool fullscreen) : title(title), size(w, h)
{
	glfwWindow = nullptr;


}

Window::Window(const std::string& title, Vec2 size, bool fullscreen) : title(title), size(size)
{
}

void Window::createWindow()
{
	glfwWindow = glfwCreateWindow(size.x, size.y, title.c_str(), nullptr, nullptr);

	if (!glfwWindow)
	{
		const char* str;
		int code = glfwGetError(&str);
		fprintf(stderr, "Window creation error : %d : %s", code, str);
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent(glfwWindow);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(glfwWindow);
}

void Window::setSize(Vec2 size)
{
	setSize(size.x, size.y);
}

void Window::setSize(int x, int y)
{
	this->size = Vec2(x, y);
	glViewport(0, 0, x, y);
}

void Window::setTitle(const std::string& str)
{
	glfwSetWindowTitle(glfwWindow, str.c_str());
}

Vec2 Window::getSize()
{
	return size;
}

std::string Window::getTitle()
{
	return title;
}

void Window::close()
{
	glfwSetWindowShouldClose(glfwWindow, true);
}

bool Window::onClose()
{
	return glfwWindowShouldClose(glfwWindow);
}
