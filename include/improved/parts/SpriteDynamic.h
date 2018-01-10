/////////////////////////////////////
// Sprite Dynamic
//  single sprite with collider and physics info
////////////////////////////////////

#pragma once

#include "parts\SpriteSimple.h"

class TransformDynamic;

class SpriteDynamic :public SpriteSimple
{
	TransformDynamic* transformDynamic;
protected:

	virtual void SetSimpleTransform();
public:
	//constructor
	//SpriteDynamic(PredefinedSprite a_preDefSpr, 
	//	float a_colRad,
	//	Drawer::DrawPriority a_drawPriority = Drawer::DrawPriority::BACK, 
	//	float a_mass = 10,
	//	float a_drag = .2f);

	//moves sprite according to vector a_
	virtual void Move(Vec2 a_movVec);
};