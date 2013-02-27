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
int  InputManager::_iMouseReferenceX = 0;
int  InputManager::_iMouseReferenceY = 0;
int  InputManager::_iMouseLastPosX = 0;
int  InputManager::_iMouseLastPosY = 0;
int  InputManager::_iMouseDeltaX = 0;
int  InputManager::_iMouseDeltaY = 0;

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

	//	We need to reset the mouse to the "center" reference
	//	position to generate delta values for mouse movement.
	if(_bForceMouseToRefPos && _bMouseHidden)
	{
		_iMouseDeltaX = _iMouseReferenceX - x;
		_iMouseDeltaY = _iMouseReferenceY - y;

		SetMousePos(_iMouseReferenceX, _iMouseReferenceY);

		_iMouseLastPosX = _iMouseX;
		_iMouseLastPosY = _iMouseY;
	}
	else
	{
		_iMouseDeltaX = _iMouseLastPosX - x;
		_iMouseDeltaY = _iMouseLastPosY - y;
		_iMouseLastPosX = x;
		_iMouseLastPosY = y;
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
	_iMouseReferenceX = xPos;
	_iMouseReferenceY = yPos;
}

void InputManager::GetMouseRefPos(int *xPos, int *yPos)
{
	*xPos = _iMouseReferenceX;
	*yPos = _iMouseReferenceY;
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

int InputManager::GetMouseDeltaX()
{
	return _iMouseDeltaX;
}

int InputManager::GetMouseDeltaY()
{
	return _iMouseDeltaY;
}
