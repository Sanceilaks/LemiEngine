#pragma once
#include "../Event.h"
#include "../EventManager.h"

class EscEvent : public Event
{
public:
	virtual void handle(Window* window) override
	{
		if (event_manger::just_pressed(GLFW_KEY_ESCAPE))
			window->close();
	}
};
