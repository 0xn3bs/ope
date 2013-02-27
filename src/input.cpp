#include "input.h"
#include <iostream>

InputManager g_inputManager;
bool InputManager::_bKeys[512];
int  InputManager::_iMouseX = 0;
int  InputManager::_iMouseY = 0;
int  InputManager::_iMouseClickStartX = 0;
int  InputManager::_iMouseClickStartY = 0;
int  InputManager::_iMouseClickEndX = 0;
int  InputManager::_iMouseClickEndY = 0;

void InputManager::Initialize()
{
	glfwSetCharCallback(InputManager::SetKeyEvent);
	glfwSetKeyCallback(InputManager::SetKeyEvent);
	glfwSetMousePosCallback(InputManager::SetMousePosEvent);
	glfwSetMouseButtonCallback(InputManager::SetMouseButtonEvent);
	glfwEnable(GLFW_KEY_REPEAT);
	glfwEnable(GLFW_STICKY_KEYS);
	glfwEnable(GLFW_SYSTEM_KEYS);
}

void InputManager::SetCharEvent(int key, int action)
{
	_bKeys[key] = static_cast<bool>(action == GLFW_PRESS);
}

void InputManager::SetKeyEvent(int key, int action)
{
	_bKeys[key] = static_cast<bool>(action == GLFW_PRESS);
}

void InputManager::SetMousePosEvent(int x, int y)
{
	_iMouseX = x;
	_iMouseY = y;
}

void InputManager::SetMouseButtonEvent(int button, int action)
{
	static bool isMouseAlreadyDown = false;
	bool isClick = false;

	if(button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
	{
		isMouseAlreadyDown = true;
		_iMouseClickStartX = _iMouseX;
		_iMouseClickStartY = _iMouseY;
	}

	if(button == GLFW_MOUSE_BUTTON_1 && action == GLFW_RELEASE && isMouseAlreadyDown)
	{
		isMouseAlreadyDown = true;
		_iMouseClickStartX = _iMouseX;
		_iMouseClickStartY = _iMouseY;
		isClick = true;
	}
}
