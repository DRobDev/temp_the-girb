/////////////////////////////////////////////////////////
// Main game loop for The Girb
/////////////////////////////////////////////////////////

#pragma once
#include "tools\vec2.h"

class PlayerMain;
class GameTime;
class UniqueSprite;
class TheGirb
{
	GameTime* gametime;
	PlayerMain* playerMain;
	UniqueSprite* backgroundImage;

public:
	TheGirb();

	static Vec2 ScreenSize;

	// Run Game
	void RunGame();

private:
	void m_DrawBackground();

};