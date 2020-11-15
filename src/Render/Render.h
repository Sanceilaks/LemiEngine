#pragma once
#include <iostream>
#include <Singleton.hpp>

#include <Math/Vec2.h>
#include <Window/Window.h>

#include "GL/VAO.h"

class Render
{
public:
	static void init(Window* win);
	static void renderEnd();
	static void renderStart();
	static void swapBuffers();
};

