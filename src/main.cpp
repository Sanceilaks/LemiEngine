#include <iostream>

#include "Application.h"
#include <Event/Events/KeysEvents.h>


class TestApp : public Application
{
	void init()
	{
		Application::init();

		EventManager::addEvent(new EscEvent());
	}
};

int main()
{
	TestApp app;

	app.run();
}