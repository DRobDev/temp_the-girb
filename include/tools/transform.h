//////////////////////////////////
// Used for positioning objects in the game world
/////////////////////////////////

#pragma once

#include "tools/vec2.h"
#include <vector>
class GameTime;
class Transform
{
	static std::vector<Transform*> allTransforms;
public:
	//temp bool
	bool isForeground;

	//constructor
	Transform();

	//access game time
	static GameTime* gameTime;

	//world size constant
	static Vec2* worldSize;
	//world center
	static Vec2 worldCenter;
	//transform for camare 
	static Transform* CameraTran;
	//foreground size
	static Vec2 ForegroundSize;
	//foreground lower left point
	static Vec2 ForegroundStart;
	//foreground upper right point
	static Vec2 ForegroundEnd;

	//used to simulate world scale
	static float ScaleMultiplyer;

	//calls update for all transforms (call once per frame)
	static void UpdateAllTransforms();


	//position in constant world
	Vec2 worldPosition;
	//position relative to the camera
	Vec2 reletivePosition;
	//position on the screen
	Vec2 foregroundPosition;
	//rotation
	static const int MATRIXSIZE = 16;
	static const float RADIAN;
	static const float IDENTITY[MATRIXSIZE];
	float spriteMatrix[MATRIXSIZE];

	//drag
	static const float dragBase;
	static float drag;
	//sleep (stops when moving slower than)
	static const float sleepBase;
	static float sleep;
	//current velocity
	Vec2 velocity;

	//sets position (single call)
	void SetWorldPosition(Vec2& a_position);
	//sets the velecity
	void SetVelocity(Vec2 a_velocity);
	//moves transform uses velocity
	void Move(Vec2 a_moveAmmount);
	//moves tranform based on local axis
	void MoveLocal(Vec2 a_moveAmount);


	//check if point is in range (even on loop break)
	bool m_IsInRange(Vec2& a_point, Vec2& a_rangeStart, Vec2& a_rangeEnd);
	//loop world
	void m_LoopWorld(Vec2& a_position);
	//update position information
	void m_update();

protected:
	//set this transform as camera
	void SetAsCamera();

	//adjust the scale multiplyer
	void SetScaleMultiplyer(float a_desiredScale);
};
