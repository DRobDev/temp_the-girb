#include "elements\CollisionSimple.h"

CollisionSimple::CollisionSimple(
	PredefinedSprite a_sprite,
	ColliderType a_objectType,
	Vec2 a_worldPos,									
	Drawer::DrawPriority a_priority) 
	: Simple(a_sprite, a_worldPos, a_priority)
	, Collider(a_objectType, a_sprite.baseSize.x / 2)
{
}

void CollisionSimple::m_Hit(Collider* a_otherCol)
{
}

Vec2 CollisionSimple::GetWorldPosition()
{
	return tranformBase->GetWorldPosition();
}