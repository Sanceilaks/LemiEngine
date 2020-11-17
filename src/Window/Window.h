#pragma once
#include <gl.hpp>
#include <Math/Vec2.h>


#include <iostream>

class Window
{
	Vec2 size;
	std::string title;

public:
	GLFWwindow* mWindow;
	
	Window(const std::string& title, int w, int h, bool fullscreen = false);
	Window(const std::string& title, Vec2 size, bool fullscreen = false);
	~Window();
	
	void create_window();

	void swap_buffers();

	void set_size(Vec2 size);
	void set_size(int x, int y);
	void set_title(const std::string& str);

	Vec2 get_size();
	std::string get_title();

	void close();

	bool on_close();

	void update();
};