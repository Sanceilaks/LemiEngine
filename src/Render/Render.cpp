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

	glViewport(0, 0, window->get_size().x, window->get_size().y);
}

void Render::render_end()
{
	swap_buffers();
}

void Render::render_start()
{
	glClearColor(0.6f, 0.62f, 0.65f, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Render::swap_buffers()
{
	window->swap_buffers();
}

void Render::render()
{


	
}
