#include "elements\SimplePhysics.h"


SimplePhysics::SimplePhysics(PredefinedSprite a_sprite,		
							 float a_mass,										
							 float a_drag,										
							 Vec2 a_worldPos,									
							 Drawer::DrawPriority a_priority)
							 : Simple(a_sprite, a_worldPos, a_priority)
{
	//create dynamic transform
	tranformDynam = new TransformDynamic(a_mass, a_drag);

	//override BaseTransform in Simple with dynamic one
	delete tranformBase;
	tranformBase = tranformDynam;

	//set position
	SetWorldPosition(a_worldPos);
}

void SimplePhysics::m_PhysicsUpdate()
{
	//update dynamic sprite (velocity)
	tranformDynam->Update();
	//updat sprite to match transform
	sprite->SetMatrix(tranformDynam->GetTransformMatrix());
}

SimplePhysics::~SimplePhysics()
{
	Drawer::RemoveSpriteFromDrawer(currentSpriteId, drawPriority);
}