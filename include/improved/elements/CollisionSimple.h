//////////////////////////////
// Simple non animated static sprite
// has collision detection
//////////////////////////////

#pragma once

#include "elements\Simple.h"
#include "tools\Collider.h"

class CollisionSimple: public Simple, Collider
{
	//returns world position of transform
	virtual Vec2 GetWorldPosition();
	
public:
	//constructor
	CollisionSimple(
		PredefinedSprite a_sprite,
		ColliderType a_objectType,
		Vec2 a_worldPos = Vec2::ZERO,									
		Drawer::DrawPriority a_priority = Drawer::DrawPriority::MID);

	//called when hit by other collider
	virtual void m_Hit(Collider* a_otherCol);
};