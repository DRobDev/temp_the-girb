///////////////////////
// Sprite classes
//  one sprite, no complex movement or collision
//////////////////////

#pragma once

#include "tools\PreDefSprites.h"


//can be positioned in world space
// does not have any collision or movement functionalityc
class SpriteSimple
{
	//local variables
	int id;

public:
	//constructor
	SpriteSimple(PredefinedSprite a_preDefSpr);

	//set sprite matrix to a_
	void SetMatrix(float* a_matrix);

	//returns sprite id
	int GetId();

	//destructor
	~SpriteSimple();
};