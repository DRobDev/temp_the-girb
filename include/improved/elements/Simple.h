//////////////////////////////////
// Simple game element
//  set the position of a single sprite
//////////////////////////////////

#pragma once

#include "parts\SpriteSimple.h"
#include "parts\TransformBase.h"
#include "elements\Drawer.h"

class Simple
{
protected:
	Drawer::DrawPriority drawPriority;
	int currentSpriteId;
	SpriteSimple* sprite;
	TransformBase* tranformBase;
	

public:
	//constructor for Simple
	Simple(PredefinedSprite a_sprite,									//sprite to use 
		Vec2 a_worldPos = Vec2::ZERO,									//position (default zero)
		Drawer::DrawPriority a_priority = Drawer::DrawPriority::BACK);	//draw priority

	//sets world position 
	void SetWorldPosition(Vec2 a_pos);

	//moves in world space 
	void Move(Vec2 a_movVec);

	//sets rotation around the 'z' axis (0 = up)
	void SetRotation(float a_degrees);

	//look at world position
	void LookAt(Vec2 a_worldPos);

	//destructor
	virtual ~Simple();

};