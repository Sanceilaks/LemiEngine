#include "Application.h"


Application::Application()
{
	window = nullptr;

}

Application::~Application()
{
	delete window;
}

void Application::init(void)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	

	window = new Window(name, STARTUPSIZE);
	window->create_window();

	//glfwSwapInterval(0);

	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		auto code = glGetError();
		const unsigned char* str = glewGetErrorString(code);
		fprintf(stderr, "GLEW Initialization error : %s", str);
		glfwTerminate();
		exit(-1);
	}

	Render::init(window);
	event_manger::init(window);
	
}

void Application::render(void)
{
	Render::render_start();
}

void Application::update(double dt)
{
}

void Application::main_loop(void)
{
	VAO vao;

	vao.add_vertex_buffer_object({
		0, 0.5f, 0,
		-0.5f, -0.5f, 0,
		0.5f, -0.5f, 0
		});

	while (!window->on_close())
	{
		window->update();

		event_manger::pull_events();
		event_manger::handle_events();

		render();

		Render::render_end();
	}
}

void Application::run()
{
	init();
	main_loop();
}
