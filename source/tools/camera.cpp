
#include "tools/camera.h"

Camera* Camera::cameraInstance = nullptr;

Camera::Camera()
{
	SetAsCamera();
	SetWorldPosition(Vec2());
}

Camera* Camera::GetInstance()
{
	if(cameraInstance == nullptr)
		cameraInstance = new Camera();
	return cameraInstance;
}

void Camera::SetWorldPosition(Vec2 a_position)
{
	m_LoopWorld(a_position);

	ForegroundStart = (worldCenter) - (ForegroundSize / 2); //offset to center of screen
	m_LoopWorld(ForegroundStart);

	ForegroundEnd = ForegroundStart + ForegroundSize;
	m_LoopWorld(ForegroundEnd);

	Transform::SetWorldPosition(a_position);
}