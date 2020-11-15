#include "EventManager.h"

Window* window = nullptr;

std::vector<Event*> event_list;


bool* EventManager::keysState;
uint* EventManager::frames;
uint EventManager::currentFrame = 0;
float EventManager::deltaX = 0.0f;
float EventManager::deltaY = 0.0f;
float EventManager::mouseX = 0.0f;
float EventManager::mouseY = 0.0f;
bool EventManager::cursorLocked = false;
bool EventManager::cursorStarted = false;

#define MOUSE_BUTTONS 1024

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (action == GLFW_PRESS)
	{
		EventManager::keysState[key] = true;
		EventManager::frames[key] = EventManager::currentFrame;
	}
	else if (action == GLFW_RELEASE)
	{
		EventManager::keysState[key] = true;
		EventManager::frames[key] = EventManager::currentFrame;
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (EventManager::cursorStarted) 
	{
		EventManager::deltaX += xpos - EventManager::mouseX;
		EventManager::deltaY += ypos - EventManager::mouseY;
	}
	else 
	{
		EventManager::cursorStarted = true;
	}
	EventManager::mouseX = xpos;
	EventManager::mouseY = ypos;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mode)
{
	if (action == GLFW_PRESS)
	{
		EventManager::keysState[button + MOUSE_BUTTONS] = true;
		EventManager::frames[button + MOUSE_BUTTONS] = EventManager::currentFrame;
	}
	else if (action == GLFW_RELEASE)
	{
		EventManager::keysState[button + MOUSE_BUTTONS] = true;
		EventManager::frames[button + MOUSE_BUTTONS] = EventManager::currentFrame;
	}
}

void EventManager::init(Window* _window)
{
	window = _window;

	keysState = new bool[1032];
	frames = new uint[1032];

	memset(keysState, false, 1032 * sizeof(bool));
	memset(frames, 0, 1032 * sizeof(uint));

	glfwSetKeyCallback(window->glfwWindow, key_callback);
	glfwSetMouseButtonCallback(window->glfwWindow, mouse_button_callback);
	glfwSetCursorPosCallback(window->glfwWindow, cursor_position_callback);
}

bool EventManager::pressed(int code)
{
	if (code < 0 || code >= MOUSE_BUTTONS)
		return false;
	return keysState[code];
}

bool EventManager::justPressed(int code)
{
	if (code < 0 || code >= MOUSE_BUTTONS)
		return false;
	return keysState[code] && frames[code] == currentFrame;
}

bool EventManager::clicked(int key)
{
	int index = MOUSE_BUTTONS + key;
	return keysState[index];
}

bool EventManager::justClicked(int key)
{
	int index = MOUSE_BUTTONS + key;
	return keysState[index] && frames[index] == currentFrame;
}

void EventManager::pullEvents()
{
	currentFrame++;
	deltaX = 0.0f;
	deltaY = 0.0f;
	glfwPollEvents();
}

void EventManager::handleEvents()
{
	for (auto i : event_list)
	{
		i->handle(window);
	}
}

void EventManager::addEvent(Event* _event)
{
	event_list.push_back(_event);
}
