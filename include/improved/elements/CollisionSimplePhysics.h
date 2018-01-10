////////////////////////////////
// Simple non-animated sprite with collision and 
// physical properties
///////////////////////////////

#pragma once

#include "elements\SimplePhysics.h"
#include "tools\Collider.h"

class CollisionSimplePhysics : public SimplePhysics, public Collider
{
	//returns world position of transform
	virtual Vec2 GetWorldPosition();

	//what to do when hit
	virtual void m_Hit(Collider* a_otherCol);

public:
	//constructor
	CollisionSimplePhysics(
		PredefinedSprite a_sprite,
		ColliderType a_colType,
		Vec2 a_worldPos = Vec2::ZERO,
		float a_mass = 10,
		float a_drag = 20,
		Drawer::DrawPriority a_drawPriority = Drawer::DrawPriority::MID);


};