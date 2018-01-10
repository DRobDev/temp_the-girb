/////////////////////////////////////
// Main player
// all functionality relating to the maing player
// movement
///////////////////////////////////

#pragma once

#include "elements\CollisionSimplePhysics.h"
#include "tools\GameObjectsUpdater.h"
#include "TheGirb.h"

class PlayerMain : public CollisionSimplePhysics, GameObjectsUpdater
{
#ifdef _DEBUG
	//only one instance is allowed
	static bool alreadyCreated;
#endif // _DEBUG

	//TODO: make level class
	Vec2 moveSpeed;
	float maxMoveSpeed;

	//controls
	static const int MOVE_BUTTON = MOUSE_BUTTON_2;
	static const int FIRE_BUTTON = MOUSE_BUTTON_1;

protected:
	//update called once per frame
	virtual void m_GameObjectsUpdate();

public:
	//constructor 
	PlayerMain();


private: //internal functions
	//look at moust
	void m_LookAtCursor();

	//move in facing direction on mouse press
	void m_PlayerMove();


};