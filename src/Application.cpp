#include "Application.h"


Application::Application()
{
	window = nullptr;

}

void Application::init(void)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = new Window(name, STARTUPSIZE);
	window->createWindow();

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
	EventManager::init(window);
	
}

void Application::render(void)
{

	Render::renderEnd();
}

void Application::update(double dt)
{
}

void Application::mainLoop(void)
{
	


	while (!window->onClose())
	{
		EventManager::pullEvents();
		EventManager::handleEvents();

		render();
	}
}

void Application::run()
{
	init();
	mainLoop();
}
