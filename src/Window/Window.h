#pragma once
#include <gl.hpp>
#include <Math/Vec2.h>


#include <iostream>

class Window
{
	Vec2 size;
	std::string title;

public:
	GLFWwindow* glfwWindow;
	
	Window(const std::string& title, int w, int h, bool fullscreen = false);
	Window(const std::string& title, Vec2 size, bool fullscreen = false);

	void createWindow();

	void swapBuffers();

	void setSize(Vec2 size);
	void setSize(int x, int y);
	void setTitle(const std::string& str);

	Vec2 getSize();
	std::string getTitle();

	void close();

	bool onClose();

	void update();
};