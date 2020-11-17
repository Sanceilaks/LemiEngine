#include "EventManager.h"

Window* window = nullptr;

std::vector<Event*> event_list;


bool* event_manger::keys_state;
uint* event_manger::frames;
uint event_manger::current_frame = 0;
float event_manger::delta_x = 0.0f;
float event_manger::delta_y = 0.0f;
float event_manger::mouse_x = 0.0f;
float event_manger::mouse_y = 0.0f;
bool event_manger::cursor_locked = false;
bool event_manger::cursor_started = false;

#define MOUSE_BUTTONS 1024

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (action == GLFW_PRESS)
	{
		event_manger::keys_state[key] = true;
		event_manger::frames[key] = event_manger::current_frame;
	}
	else if (action == GLFW_RELEASE)
	{
		event_manger::keys_state[key] = true;
		event_manger::frames[key] = event_manger::current_frame;
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (event_manger::cursor_started) 
	{
		event_manger::delta_x += xpos - event_manger::mouse_x;
		event_manger::delta_y += ypos - event_manger::mouse_y;
	}
	else 
	{
		event_manger::cursor_started = true;
	}
	event_manger::mouse_x = xpos;
	event_manger::mouse_y = ypos;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mode)
{
	if (action == GLFW_PRESS)
	{
		event_manger::keys_state[button + MOUSE_BUTTONS] = true;
		event_manger::frames[button + MOUSE_BUTTONS] = event_manger::current_frame;
	}
	else if (action == GLFW_RELEASE)
	{
		event_manger::keys_state[button + MOUSE_BUTTONS] = true;
		event_manger::frames[button + MOUSE_BUTTONS] = event_manger::current_frame;
	}
}

void event_manger::init(Window* _window)
{
	window = _window;

	keys_state = new bool[1032];
	frames = new uint[1032];

	memset(keys_state, false, 1032 * sizeof(bool));
	memset(frames, 0, 1032 * sizeof(uint));

	glfwSetKeyCallback(window->mWindow, key_callback);
	glfwSetMouseButtonCallback(window->mWindow, mouse_button_callback);
	glfwSetCursorPosCallback(window->mWindow, cursor_position_callback);
}

bool event_manger::pressed(int code)
{
	if (code < 0 || code >= MOUSE_BUTTONS)
		return false;
	return keys_state[code];
}

bool event_manger::just_pressed(int code)
{
	if (code < 0 || code >= MOUSE_BUTTONS)
		return false;
	return keys_state[code] && frames[code] == current_frame;
}

bool event_manger::clicked(int key)
{
	int index = MOUSE_BUTTONS + key;
	return keys_state[index];
}

bool event_manger::just_clicked(int key)
{
	int index = MOUSE_BUTTONS + key;
	return keys_state[index] && frames[index] == current_frame;
}

void event_manger::pull_events()
{
	current_frame++;
	delta_x = 0.0f;
	delta_y = 0.0f;
	glfwPollEvents();
}

void event_manger::handle_events()
{
	for (auto i : event_list)
	{
		i->handle(window);
	}
}


void event_manger::add_event(Event* _event)
{
	event_list.push_back(_event);
}
