///////////////////////////
// handles all ingame collision
//////////////////////////

#pragma once

#include <vector>
#include "vec2.h"

class Collider
{
	static std::vector<Collider*> allColliders;

public:
	//collider types
	enum ColliderTypes
	{
		PLAYERBODY,
		PLAYERBULLET,
		ENEMYBODY,
		ENEMYBULLET,
		DEFAULT
	};

	//constructor
	Collider(ColliderTypes a_colType = ColliderTypes::DEFAULT);

	//updates all colliders in the game
	static void UpdateAllColliders();

	//called in each collider when hit
	virtual void Hit(Collider* a_otherCol) = 0;

	//used to update all colliders
	//virtual void m_UpdateCollider() = 0;	

	//gets extent of collider between tow colliders
	virtual float GetExtent(Collider* a_otherCol) = 0;


	//world position of collider origin
	Vec2 colliderWorldPos;
	//collision extent
	//float collisionExtent;
	//this collider type
	ColliderTypes colType;
};

class BallCollider : public Collider
{
public:
	//constructor
	BallCollider(ColliderTypes a_colType = ColliderTypes::DEFAULT);

	//sets collision radius
	void SetCollisionRadius(float a_rad);

	//sets collider position
	void SetColliderPosition(Vec2 a_pos);

	//updates this collider
	//void m_UpdateCollider();

	float GetExtent(Collider* a_otherCol);

	//collision radius
	float colRad;

};