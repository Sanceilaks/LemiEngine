#include <iostream>

#include "Application.h"
#include <Event/Events/KeysEvents.h>

class TestApp : public Application
{
	void init()
	{
		Application::init();

		Application::window->setSize(800, 600);
		Application::window->setTitle("Marat xyi");

		EventManager::addEvent(new EscEvent());
	}

};

int main()
{
	TestApp app;

	app.run();
}