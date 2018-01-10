/////////////////////////////////////
// Holds tranform information for dinamic objects
//  (things with mass and collision)
////////////////////////////////////

#pragma once

#include "parts\TransformBase.h"

class TransformDynamic : public TransformBase
{
	float mass;		//weight
	float drag;		//decelleration rate
	Vec2 velocityDirection;
	float velocityMagnitude;

	//object sleeps if movement speed is less than
	static const float sleep;

	//get normalised direction vector for velocity
	void m_getVelocityDirection();

	//add drag to velocity (you can limit the drag to one axis)(or invert it)
	void m_addDrag(bool a_addToX = true, bool a_addToY= true, bool a_removeInstead = false);

public: 
	//constructor
	TransformDynamic(float a_mass, float a_drag);

	//called every frame (used to update physics infomation)
	void Update();

	//current velocity
	Vec2 velocity;

	//translates object (worldspace direction) ignoring mass and velocity
	virtual void Move(Vec2 a_movVec);

	//adds force in spefified direction (world space)
	//void AddForce(Vec2 a_force);

	//adds force in specified direction (local space)
	void AddForceLocal(Vec2 a_force);

	//adds torque around the 'z' axis	//tollerance before sleeping

	//destructor
	~TransformDynamic();

};