#include "elements\CollisionSimplePhysics.h"

CollisionSimplePhysics::CollisionSimplePhysics(
		PredefinedSprite	a_sprite,
		ColliderType		a_colType,
		Vec2				a_worldPos,
		float				a_mass,
		float				a_drag,
		Drawer::DrawPriority a_drawPriority)
		: SimplePhysics(a_sprite, a_mass, a_drag, a_worldPos, a_drawPriority)
		, Collider(a_colType, a_sprite.baseSize.x / 2)
{

}

Vec2 CollisionSimplePhysics::GetWorldPosition()
{
	return tranformDynam->GetWorldPosition();
}

void CollisionSimplePhysics::m_Hit(Collider* a_othercol)
{
	//TEMP:
	Move( (GetWorldPosition() - a_othercol->GetWorldPosition()) * .2f);
}