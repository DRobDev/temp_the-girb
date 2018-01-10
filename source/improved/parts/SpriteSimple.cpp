
#include "parts\SpriteSimple.h"

#include "TheGirb.h"

SpriteSimple::SpriteSimple(PredefinedSprite a_preDefSpr)
{
	//add srpite to framework
	id = CreateSprite(a_preDefSpr.spriteDir, a_preDefSpr.baseSize.x, a_preDefSpr.baseSize.y, true);
}

void SpriteSimple::SetMatrix(float* a_matrix)
{
	SetSpriteMatrix(id, a_matrix);
}

int SpriteSimple::GetId()
{
	return id;
}

SpriteSimple::~SpriteSimple()
{
	//remove sprite from framework
	DestroySprite(id);
}