#pragma once
#include <gl.hpp>

#include <Window/Window.h>
#include <Render/Render.h>
#include <Event/EventManager.h>

class Application
{
	std::string name = "Engine";
	Vec2 STARTUPSIZE = (800, 600);

public:
	Window* window;

	Application();
	~Application();
	
	/*
	Use:
	<code>
		void init()
		{
			base->init();
			//Your code
		}
	</code>
	*/
	virtual void init(void);
	virtual void render(void);
	virtual void update(double dt);
	virtual void main_loop(void);

	void run();
};