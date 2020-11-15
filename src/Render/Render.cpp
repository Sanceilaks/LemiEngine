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
	swapBuffers();
}

void Render::renderStart()
{
	glClearColor(0.6f, 0.62f, 0.65f, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Render::swapBuffers()
{
	window->swapBuffers();
}
