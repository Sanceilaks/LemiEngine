#pragma once
#include <iostream>
#include <Singleton.hpp>

#include <Math/Vec2.h>
#include <Window/Window.h>


class Render
{
public:
	static void init(Window* win);
	static void renderEnd();
	static void swapBuffers();
};

