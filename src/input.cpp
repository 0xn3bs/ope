#include "input.h"
#include <iostream>

InputManager g_inputManager;
bool InputManager::_bKeys[512];
Vec2<int> InputManager::_v2dMouse;
Vec2<int> InputManager::_v2dMouseClickStart;
Vec2<int> InputManager::_v2dMouseClickEnd;
Vec2<int> InputManager::_v2dMouseReference;
Vec2<int> InputManager::_v2dMouseLastPos;
Vec2<int> InputManager::_v2dMouseDelta;

bool InputManager::_bForceMouseToRefPos = false;
bool InputManager::_bMouseHidden = false;

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

void InputManager::Update(double dt)
{
	int x, y;
	GetMousePos(&x, &y);
	Vec2<int> pos(x, y);	

	//	We need to reset the mouse to the "center" reference
	//	position to generate delta values for mouse movement.
	if(_bForceMouseToRefPos && _bMouseHidden)
	{
		_v2dMouseDelta = _v2dMouseReference - pos;

		SetMousePos(_v2dMouseReference.x, _v2dMouseReference.y);

		_v2dMouseLastPos = _v2dMouse;
	}
	else
	{
		_v2dMouseDelta = _v2dMouseLastPos - pos;
		_v2dMouseLastPos = pos;
	}
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
	_v2dMouse.x = x;
	_v2dMouse.y = y;
}

void InputManager::SetMouseButtonEvent(int button, int action)
{
	static bool isMouseAlreadyDown = false;
	bool isClick = false;

	if(button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
	{
		isMouseAlreadyDown = true;
		_v2dMouseClickStart = _v2dMouse;
	}

	if(button == GLFW_MOUSE_BUTTON_1 && action == GLFW_RELEASE && isMouseAlreadyDown)
	{
		isMouseAlreadyDown = true;
		_v2dMouseClickEnd = _v2dMouse;
		isClick = true;
	}
}

void InputManager::ToggleMouseStick()
{
	_bForceMouseToRefPos = !_bForceMouseToRefPos;
}

void InputManager::ToggleMouseHide()
{
	_bMouseHidden = !_bMouseHidden;

	if(_bMouseHidden)
		glfwDisable(GLFW_MOUSE_CURSOR);
	else
		glfwEnable(GLFW_MOUSE_CURSOR);
}

void InputManager::SetMousePos(const Vec2<int> pos)
{
	glfwSetMousePos(pos.x, pos.y);
}

void InputManager::SetMousePos(const int xPos, const int yPos)
{
	glfwSetMousePos(xPos, yPos);
}

void InputManager::GetMousePos(int *xPos, int *yPos)
{
	glfwGetMousePos(xPos, yPos);
}

void InputManager::SetMouseRefPos(const int xPos, const int yPos)
{
	_v2dMouseReference.x = xPos;
	_v2dMouseReference.y = yPos;
}

void InputManager::GetMouseRefPos(int *xPos, int *yPos)
{
	*xPos = _v2dMouseReference.x;
	*yPos = _v2dMouseReference.y;
}

bool InputManager::GetKey(int key)
{
	if(key < 512 && key >= 0)
		return _bKeys[key];

	return false;
}

void InputManager::SetKey(int key, bool state)
{
	if(key < 512 && key >= 0)
		_bKeys[key] = state;
}

Vec2<int> InputManager::GetMouseDelta()
{
	return _v2dMouseDelta;
}
