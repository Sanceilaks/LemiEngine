#include "Window.h"

Window::Window(const std::string& title, int w, int h, bool fullscreen) : title(title), size(w, h)
{
	mWindow = nullptr;
}

Window::Window(const std::string& title, Vec2 size, bool fullscreen) : size(size), title(title)
{
	mWindow = nullptr;
}

Window::~Window()
{
	glfwDestroyWindow(mWindow);
	
}

void Window::create_window()
{
	mWindow = glfwCreateWindow(size.x, size.y, title.c_str(), nullptr, nullptr);

	if (!mWindow)
	{
		const char* str;
		int code = glfwGetError(&str);
		fprintf(stderr, "Window creation error : %d : %s", code, str);
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent(mWindow);
}

void Window::swap_buffers()
{
	glfwSwapBuffers(mWindow);
}

void Window::set_size(Vec2 size)
{
	set_size(size.x, size.y);
}

void Window::set_size(int x, int y)
{
	this->size = Vec2(x, y);
	glViewport(0, 0, x, y);
}

void Window::set_title(const std::string& str)
{
	glfwSetWindowTitle(mWindow, str.c_str());
}

Vec2 Window::get_size()
{
	return size;
}

std::string Window::get_title()
{
	return title;
}

void Window::close()
{
	glfwSetWindowShouldClose(mWindow, true);
}

bool Window::on_close()
{
	return glfwWindowShouldClose(mWindow);
}

void Window::update()
{
	if (title.c_str() != get_title())
		set_title(title);

	glfwSetWindowSize(mWindow, size.x, size.y);
}
