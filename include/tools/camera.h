//////////////////////////////
// Game Camera
// only one per game instance allowed
////////////////////////////////
#pragma once

#include "tools\transform.h"

class Camera : public Transform
{
	static Camera* cameraInstance;
	Camera();
public:

	//returns instance of camera
	static Camera* GetInstance();

	void SetWorldPosition(Vec2 a_position);

};