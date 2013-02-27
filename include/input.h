#ifndef __INPUT_H__
#define __INPUT_H__

#include <GL/glfw.h>

class InputManager
{
private:
	static bool _bKeys[512];
	static int	_iMouseX;
	static int	_iMouseY;
	static int	_iMouseClickStartX;
	static int	_iMouseClickStartY;
	static int  _iMouseClickEndX;
	static int  _iMouseClickEndY;

public:
	InputManager(){};
	~InputManager(){};

	static void Initialize();

	static void GLFWCALL SetCharEvent(int key, int action);
	static void GLFWCALL SetKeyEvent(int key, int action);
	static void GLFWCALL SetMousePosEvent(int x, int y);
	static void GLFWCALL SetMouseButtonEvent(int button, int action);

	static void GetMousePos(int *xPos, int *yPos);
};

#endif /*__INPUT_H__*/
