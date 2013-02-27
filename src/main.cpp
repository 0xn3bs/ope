#include <iostream>
#include <GL/glfw.h>

#include "input.h"

bool g_bIsRunning = true;

void Update();

int main()
{
	int err = glfwInit();
	if(err != GL_TRUE)
	{
		std::cerr << "Error initializing glfw" << std::endl;
		glfwTerminate();
	}

	int window = glfwOpenWindow(800, 600, 8, 8, 8, 8, 24, 8, GLFW_WINDOW);

	if(window != GL_TRUE)
	{
		std::cerr << "Failed to create OpenGL context" << std::endl;
		glfwTerminate();
	}

	InputManager::Initialize();

	while(g_bIsRunning)
	{
		Update();
		glFlush();
		glfwSwapBuffers();
	}

	glfwTerminate();

	return 0;
}

void Update()
{

}

void Initialize()
{

}
