//////////////////////////
// Updates all colliders in world
// (simple spherical collision)
//////////////////////////

#pragma once

#include "Tools.h"

class Collider
{
public:
	enum ColliderType
	{
		OBJECT,
		PLAYERBODY,
		ENEMYBODY,
		BULLETENEMY,
		BULLETFRIENDLY,
		DEFAULT
	};

	//called once per fram
	static void UpdateAllColliders();

		//pure v (use get position from derrived)
	virtual Vec2 GetWorldPosition() = 0;

private:
	//pointer list for all colliders in game
	static std::list<Collider*>allColliders;

	//collision radius
	float colRadius;
	//position of collider
	ColliderType colliderType;

protected:
	//constructr
	Collider(ColliderType a_type, float a_colRad);



	//pure virtual hit
	virtual void m_Hit(Collider* a_otherCol)= 0;

	//sets the collision radius
	//void SetCollisionRadius(float a_radValue);

	//distructor
	virtual ~Collider();
};