///////////////////////////////////
// Simple Physics 
// Displays one sprite
// Has weight velocity etc (no collision)
//////////////////////////////////

#pragma once

#include "elements\Simple.h"
#include "parts\TransformDynamic.h"
#include "tools\PhysicsUpdater.h"

class SimplePhysics : public Simple, PhysicsUpdater
{
	//TEMP:
public:

	//dynamic transform
	TransformDynamic* tranformDynam;

	//local update called every frame
	virtual void m_PhysicsUpdate();

public:
	//constructor
	SimplePhysics(PredefinedSprite a_sprite,							//sprite
		float a_mass = 10,												//weight
		float a_drag = .2f,												//drag
		Vec2 a_worldPos = Vec2::ZERO,									//position
		Drawer::DrawPriority a_priority = Drawer::DrawPriority::BACK);	//draw priority

	//destructor
	virtual ~SimplePhysics();
};