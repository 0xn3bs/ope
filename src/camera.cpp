#include "camera.h"
#include "vector.h"
#include "omath.h"
#include "input.h"

#include <GL/GLU.h>
#include <iostream>

void Camera::MoveForward(const float dt)
{
	_v3dEye += this->GetDirection().Normalize()*_dCameraSpeed*dt;
}

void Camera::MoveBackward(const float dt)
{
	_v3dEye -= this->GetDirection().Normalize()*_dCameraSpeed*dt;
}

void Camera::StrafeLeft(const float dt)
{
	_v3dCenter.x = _v3dEye.x + sin(_v3dChange.y+PI2);
	_v3dCenter.z = _v3dEye.z + cos(_v3dChange.y+PI2);

	Vec3<double> direction;
	direction = this->GetDirection().Normalize();
	direction.y = 0;	//	Our y direction should not affect our strafe speed when pitched.

	float magnitude = static_cast<float>(direction.Magnitude());

	_v3dEye.x += ((direction.x/magnitude)*_dCameraSpeed)*dt;
	_v3dEye.z += ((direction.z/magnitude)*_dCameraSpeed)*dt;

	_v3dCenter.x -= _v3dEye.x + sin(_v3dChange.y+PI2);
	_v3dCenter.z -= _v3dEye.z + cos(_v3dChange.y+PI2);
}

void Camera::StrafeRight(const float dt)
{
	_v3dCenter.x = _v3dEye.x + sin(_v3dChange.y-PI2);
	_v3dCenter.z = _v3dEye.z + cos(_v3dChange.y-PI2);

	Vec3<double> direction;
	direction = this->GetDirection().Normalize();
	direction.y = 0;	//	Our y direction should not affect our strafe speed when pitched.

	float magnitude = static_cast<float>(direction.Magnitude());

	_v3dEye.x += ((direction.x/magnitude)*_dCameraSpeed)*dt;
	_v3dEye.z += ((direction.z/magnitude)*_dCameraSpeed)*dt;

	_v3dCenter.x -= _v3dEye.x + sin(_v3dChange.y-PI2);
	_v3dCenter.z -= _v3dEye.z + cos(_v3dChange.y-PI2);
}

void Camera::Update(const float dt)
{
	if(InputManager::GetKey('W'))
	{
		MoveForward(dt);
	}
	if(InputManager::GetKey('S'))
	{
		MoveBackward(dt);
	}
	if(InputManager::GetKey('A'))
	{
		StrafeLeft(dt);
	}
	if(InputManager::GetKey('D'))
	{
		StrafeRight(dt);
	}

	_v3dChange.y += (InputManager::GetMouseDelta().x*0.01f)*_dMouseSensitivity;
	_v3dChange.x += (InputManager::GetMouseDelta().y*0.01f)*_dMouseSensitivity;

	if(_v3dChange.x > PI2)
		_v3dChange.x = PI2;

	if(_v3dChange.x < -PI2)
		_v3dChange.x = -PI2;

	_v3dCenter.x = _v3dEye.x + sin(_v3dChange.y);
	_v3dCenter.z = _v3dEye.z + cos(_v3dChange.y);
	_v3dCenter.y = _v3dEye.y + tan(_v3dChange.x);
}

void Camera::Render()
{
	gluLookAt(_v3dEye.x,_v3dEye.y,_v3dEye.z,_v3dCenter.x,_v3dCenter.y,_v3dCenter.z,_v3dUp.x,_v3dUp.y,_v3dUp.z);
}
