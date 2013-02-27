#include <iostream>
#include <GL/glfw.h>
#include <GL/glut.h>

#include "input.h"
#include "camera.h"

bool g_bIsRunning = true;

int g_iWindowWidth;
int g_iWindowHeight;

double g_dDeltaTime = 0;
double g_dLastTime = 0;

void Initialize();
void Update(double dt);
void Draw(double dt);

Camera* g_pCamera = NULL;

int main()
{
	g_dLastTime = glfwGetTime();
	int err = glfwInit();
	if(err != GL_TRUE)
	{
		std::cerr << "Error initializing glfw" << std::endl;
		glfwTerminate();
	}

	g_iWindowWidth	= 800;
	g_iWindowHeight = 600;

	int window = glfwOpenWindow(g_iWindowWidth, g_iWindowHeight, 8, 8, 8, 8, 24, 8, GLFW_WINDOW);

	if(window != GL_TRUE)
	{
		std::cerr << "Failed to create OpenGL context" << std::endl;
		glfwTerminate();
	}

	Initialize();

	g_pCamera = new Camera(0,0,1,0,0,0,0,1,0);
	g_pCamera->Update(0);

	while(g_bIsRunning)
	{
		double time = glfwGetTime();
		g_dDeltaTime = time - g_dLastTime;
		Update(g_dDeltaTime);
		Draw(g_dDeltaTime);
		glFlush();
		glfwSwapBuffers();
		g_dLastTime = time;
	}

	glfwTerminate();

	return 0;
}

void Exit()
{
	g_bIsRunning = false;
}

int GLFWCALL WindowCloseEvent()
{
	Exit();
	return true;
}

void GLFWCALL WindowSizeEvent(int width, int height)
{
	g_iWindowWidth = width;
	g_iWindowHeight = height;
	InputManager::SetMouseRefPos(width/2, height/2);
}

void Initialize()
{
	InputManager::Initialize();
	glfwSetWindowTitle("OPE");
	glfwSetWindowCloseCallback(WindowCloseEvent);
	glfwSetWindowSizeCallback(WindowSizeEvent);

	glShadeModel(GL_SMOOTH);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);

	glEnable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);

	glPointSize(2.0f);
	glLineWidth(1.0f);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
}

void Update(double dt)
{	
	InputManager::Update(dt);
	g_pCamera->Update(dt);

	if(glfwGetKey(GLFW_KEY_TAB)==GLFW_PRESS)
	{
		InputManager::ToggleMouseStick();
		InputManager::ToggleMouseHide();
	}

	if(glfwGetKey(GLFW_KEY_ESC)==GLFW_PRESS)
		Exit();
}

void Draw(double dt)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4ub(255,255,255,255);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPushMatrix();
	gluPerspective(65, (GLfloat)g_iWindowWidth/(GLfloat)g_iWindowHeight, 1.0f, 10000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	g_pCamera->Render();
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_ALPHA_TEST);
	glutSolidCube(100.0);
	//bspParser->DebugRender(static_cast<float>(dt), g_pCamera);
	glPopMatrix();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D,0);
	//if(InputManager::IsCursorVisible())
	//{
	//	windowManager->Render(deltaTime);
	//}
	glViewport(0, 0, g_iWindowWidth, g_iWindowHeight);
}
