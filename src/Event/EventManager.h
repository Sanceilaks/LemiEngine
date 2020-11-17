#pragma once
#include <gl.hpp>
#include <vector>

#include <Window/Window.h>
#include "Event.h"

typedef unsigned int uint;


class event_manger
{
public:
	static bool* keys_state;
	static uint* frames;
	static uint current_frame;
	static float delta_x;
	static float delta_y;
	static float mouse_x;
	static float mouse_y;
	static bool cursor_locked;
	static bool cursor_started;

	static void init(Window* window);

	static bool pressed(int code);
	static bool just_pressed(int code);

	static bool clicked(int key);
	static bool just_clicked(int key);

	static void pull_events();

	static void handle_events();

	static void add_event(Event* _event);
};