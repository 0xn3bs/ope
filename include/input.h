#ifndef INPUT_H__
#define INPUT_H__

#include <GL/glfw.h>
#include "vector.h"

class InputManager
{
private:
	//TODO: use Vec2 instead for mouse positions.

	static bool _bKeys[512];
	static Vec2<int> _v2dMouse;
	static Vec2<int> _v2dMouseClickStart;
	static Vec2<int> _v2dMouseClickEnd;
	static Vec2<int> _v2dMouseReference;
	static Vec2<int> _v2dMouseLastPos;
	static Vec2<int> _v2dMouseDelta;

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

	static void SetMousePos(const Vec2<int> pos);
	static void SetMousePos(const int xPos, const int yPos);
	static void GetMousePos(int *xPos, int *yPos);

	static void SetMouseRefPos(const int xPos, const int yPos);
	static void GetMouseRefPos(int *xPos, int *yPos);

	static void SetKey (int key, bool state);
	static bool GetKey(int key);

	static Vec2<int> GetMouseDelta();
};

#endif /*INPUT_H__*/
