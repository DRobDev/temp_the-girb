/////////////////////
// tools for traversing the looping game map
////////////////////

#pragma once

#include "Tools.h"

class Map
{
protected:
	//default constructor
	Map();

private:
	//size of world (used for collision and stuff)
	static Vec2* worldSize;
	static Vec2 foregroundSize;
	static float scaleMultiplyer;


public:
	//position of camera in game
	static Vec2 CameraPosition;

	//returns size of the world
	static Vec2 GetWorldSize();

	//keeps position inside gameworld
	void LoopWorldPosition(Vec2& a_posR); 
	Vec2 GetLoopWorldPosition(Vec2 a_pos);

};



