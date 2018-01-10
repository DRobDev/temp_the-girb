#include "parts\SpriteDynamic.h"

#include "parts\TransformDynamic.h"

//SpriteDynamic::SpriteDynamic(PredefinedSprite a_preDefSpr, 
//		float a_colRad,
//		Drawer::DrawPriority a_drawPriority, 
//		float a_mass,
//		float a_drag)
//		: SpriteSimple(a_preDefSpr, a_drawPriority)
//{
//	transformDynamic = new TransformDynamic(a_colRad,a_mass, a_drag);
//}

void SpriteDynamic::SetSimpleTransform()
{
	//transformBase = transformDynamic;
}

void SpriteDynamic::Move(Vec2 a_movVec)
{
	transformDynamic->Move(a_movVec);
//	SetSpritePosition(transformDynamic->GetWorldPosition());
}