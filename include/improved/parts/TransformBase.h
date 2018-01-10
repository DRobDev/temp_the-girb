///////////////////////////////
// simple transforms for moving stuff around the world
//////////////////////////////

#pragma once
#include "tools\Map.h"

///////////////////////////
// Holds simple controls for positioning and rotating
//  simple non-moving game elements
///////////////////////////
class TransformBase : private Map
{
	//used for converting to/from degrees
	static const float RADIAN;
	//matrix size and positions
	static const int MATRIXSIZE = 16; 
	static const int MAT_POSX = 12; 
	static const int MAT_POSY = 13;

	//when using LookAt, the target has to be further away than this to update
	static const float LOOKATMIN;

protected:
	//transform details held in matrix
	float transformMatrix[MATRIXSIZE];

public:
	//constructor
	TransformBase();

	//sets world position for transform
	void SetWorldPosition(Vec2& a_pos);

	//moves transformm along world axis
	virtual void Move(Vec2 a_movVec);

	//sets rotation of transform in degrees (counter clockwise)
	void SetRotation(float a_degrees);

	//looks at world point (accounts for wrap)
	void LookAt(Vec2 a_worldPosition);

	//gets transform matrix
	float* GetTransformMatrix();

	//gets world position as a vector2
	Vec2 GetWorldPosition();
};