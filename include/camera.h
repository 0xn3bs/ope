#ifndef CAMERA_H__
#define CAMERA_H__

#include "vector.h"

class Camera
{
public:
	Camera(Vec3<double> eye, Vec3<double> center, Vec3<double> up)
	{
		_v3dEye = eye;
		_v3dCenter = center;
		_v3dUp = up;
		_dCameraSpeed = 250;
		_dMouseSensitivity =  0.2;
	}

	Camera(double eyeX, double eyeY, double eyeZ, double centerX, double centerY, double centerZ,
		double upX, double upY, double upZ)
	{
		_v3dEye.x = eyeX;
		_v3dEye.y = eyeY;
		_v3dEye.z = eyeZ;
		_v3dCenter.x = centerX;
		_v3dCenter.y = centerY;
		_v3dCenter.z = centerZ;
		_v3dUp.x = upX;
		_v3dUp.y = upY;
		_v3dUp.z = upZ;
		_dCameraSpeed = 250;
		_dMouseSensitivity =  0.2;
	}

	~Camera()
	{
	}

	void MoveForward(const float dt);
	void MoveBackward(const float dt);
	void StrafeLeft(const float dt);
	void StrafeRight(const float dt);

	void Update(const float dt);
	void Render();

	Vec3<double> GetDirection()
	{
		return (_v3dCenter  - _v3dEye);
	}

	Vec3<double> GetPos()
	{
		return _v3dEye;
	}

	Vec3<double> _v3dEye;

private:
	Vec3<double> _v3dCenter;
	Vec3<double> _v3dUp;
	Vec3<double> _v3dChange;

	double _dCameraSpeed;
	double _dMouseSensitivity;
};

#endif /*CAMERA_H__*/
