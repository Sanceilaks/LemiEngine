#include "Render.h"


static Window* window = nullptr;


void Render::init(Window* win)
{
	window = win;

	if (!window)
	{
		fprintf(stderr, "Render::init error - window is nullptr");
		exit(-1);
	}

	glViewport(0, 0, window->getSize().x, window->getSize().y);
}

void Render::renderEnd()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	swapBuffers();
}

void Render::swapBuffers()
{
	window->swapBuffers();
}
