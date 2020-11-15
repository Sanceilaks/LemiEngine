#pragma once
#include "../Event.h"
#include "../EventManager.h"

class EscEvent : public Event
{
public:
	virtual void handle(Window* window) override
	{
		if (EventManager::justPressed(GLFW_KEY_ESCAPE))
			window->close();
	}
};
