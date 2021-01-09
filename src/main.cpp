#include <iostream>

#include "Application.h"
#include <Event/Events/KeysEvents.h>

class TestApp : public Application
{
	void init()
	{
		Application::init();

		Application::window->set_size(800, 600);
		Application::window->set_title("Marat");

		event_manger::add_event(new EscEvent());
	}

	void render()
	{
		Application::render();

		
	}
};

int main()
{
	TestApp app;

	app.run();
}