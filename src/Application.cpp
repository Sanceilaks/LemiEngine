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
	EventManager::init(window);
	
}

void Application::render(void)
{
	Render::renderStart();
}

void Application::update(double dt)
{
}

void Application::mainLoop(void)
{
	VAO vao;

	vao.addVertexBufferObject({
		0, 0.5f, 0,
		-0.5f, -0.5f, 0,
		0.5f, -0.5f, 0
		});

	while (!window->onClose())
	{
		window->update();

		EventManager::pullEvents();
		EventManager::handleEvents();

		render();

		vao.drawTriangle(3);

		Render::renderEnd();
	}
}

void Application::run()
{
	init();
	mainLoop();
}
