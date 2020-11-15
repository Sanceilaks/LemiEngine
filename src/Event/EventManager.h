#pragma once
#include <gl.hpp>
#include <vector>

#include <Window/Window.h>
#include "Event.h"

typedef unsigned int uint;


class EventManager
{
public:
	static bool* keysState;
	static uint* frames;
	static uint currentFrame;
	static float deltaX;
	static float deltaY;
	static float mouseX;
	static float mouseY;
	static bool cursorLocked;
	static bool cursorStarted;

	static void init(Window* window);

	static bool pressed(int code);
	static bool justPressed(int code);

	static bool clicked(int key);
	static bool justClicked(int key);

	static void pullEvents();

	static void handleEvents();

	static void addEvent(Event* _event);
};