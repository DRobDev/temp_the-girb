///////////////////////////////////////////
// The main player in the game
// controls the camera
// responds to user input
///////////////////////////////////////////

#pragma once

#include "tools\playerBase.h"

class Camera;
class PlayerMain : public PlayerBase
{
	//only allow one main player
	static bool isCreated;
	//use offset to draw player sprite in center (TODO: use collider)
	static Vec2 centerOffset;
	//scene camera attatched to player (TODO: spring joint)
	Camera* camera;


public:
	//default constructor
	PlayerMain();

	//update main player (call once per frame)
	void UpdatePlayer();



	//override the draw (no background needed)
	void Draw();

	//looks at mouse position
	void m_LookAtMouse();
	//move
	void m_MovePlayer();
	//fire a bullet
	void m_fire();

	//sets move speed 
	//void m_setMoveSpeed(
};