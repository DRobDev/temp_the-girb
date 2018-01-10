#include "elements\Simple.h"

Simple::Simple(PredefinedSprite a_sprite,									//sprite to use 
		Vec2 a_worldPos,									//position (default zero)
		Drawer::DrawPriority a_priority)
{
	sprite = new SpriteSimple(a_sprite);
	tranformBase = new TransformBase();
	SetWorldPosition(a_worldPos);
	currentSpriteId = sprite->GetId();
	drawPriority = a_priority;
	Drawer::AddSpriteToDraw(currentSpriteId, drawPriority);
}

void Simple::SetWorldPosition(Vec2 a_pos)
{
	tranformBase->SetWorldPosition(a_pos);
	sprite->SetMatrix(tranformBase->GetTransformMatrix());
}

void Simple::Move(Vec2 a_moveVec)
{
	tranformBase->Move(a_moveVec);
	sprite->SetMatrix(tranformBase->GetTransformMatrix());
}

void Simple::SetRotation(float a_degrees)
{
	tranformBase->SetRotation(a_degrees);
	sprite->SetMatrix(tranformBase->GetTransformMatrix());
}

void Simple::LookAt(Vec2 a_worldPos)
{
	tranformBase->LookAt(a_worldPos);
	sprite->SetMatrix(tranformBase->GetTransformMatrix());
}

Simple::~Simple()
{
	Drawer::RemoveSpriteFromDrawer(currentSpriteId, drawPriority);
}
