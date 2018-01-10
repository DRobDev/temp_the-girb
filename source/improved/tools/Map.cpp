#include "tools\Map.h"
#include "TheGirb.h"

Vec2 Map::CameraPosition = Vec2::ZERO;

Vec2* Map::worldSize = &TheGirb::GetScreenSize();
float Map::scaleMultiplyer = 1;
Vec2 Map::foregroundSize = (*Map::worldSize) / Map::scaleMultiplyer;

Map::Map()
{
	
}

void Map::LoopWorldPosition(Vec2& a_posR)
{
	//loop if negative
	while(a_posR.x < 0) a_posR.x = worldSize->x + a_posR.x;
	while(a_posR.y < 0) a_posR.y = worldSize->y + a_posR.y;
	//loop positive
	a_posR.x = fmodf(a_posR.x, worldSize->x);
	a_posR.y = fmodf(a_posR.y, worldSize->y);
}

Vec2 Map::GetLoopWorldPosition(Vec2 a_pos)
{
	LoopWorldPosition(a_pos);
	return a_pos;
}

Vec2 Map::GetWorldSize()
{
	return *worldSize;
}