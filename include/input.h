#ifndef INPUT_H__
#define INPUT_H__

#include <GL/glfw.h>
#include "omath.h"

class InputManager
{
private:
	//TODO: use Vec2 instead for mouse positions.

	static bool _bKeys[512];
	static int	_iMouseX;
	static int	_iMouseY;
	static int	_iMouseClickStartX;
	static int	_iMouseClickStartY;
	static int  _iMouseClickEndX;
	static int  _iMouseClickEndY;
	static int  _iMouseReferenceX;
	static int  _iMouseReferenceY;
	static int  _iMouseLastPosX;
	static int  _iMouseLastPosY;
	static int  _iMouseDeltaX;
	static int  _iMouseDeltaY;

	static bool _bForceMouseToRefPos;
	static bool _bMouseHidden;

public:
	InputManager(){};
	~InputManager(){};

	static void Initialize();
	static void Update(double dt);

	static void GLFWCALL SetCharEvent(int key, int action);
	static void GLFWCALL SetKeyEvent(int key, int action);
	static void GLFWCALL SetMousePosEvent(int x, int y);
	static void GLFWCALL SetMouseButtonEvent(int button, int action);

	static void ToggleMouseStick();
	static void ToggleMouseHide();

	static void SetMousePos(const int xPos, const int yPos);
	static void GetMousePos(int *xPos, int *yPos);

	static void SetMouseRefPos(const int xPos, const int yPos);
	static void GetMouseRefPos(int *xPos, int *yPos);

	static void SetKey (int key, bool state);
	static bool GetKey(int key);

	static int GetMouseDeltaX();
	static int GetMouseDeltaY();
};

#endif /*INPUT_H__*/
