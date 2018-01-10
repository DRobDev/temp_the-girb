/////////////////////////////////////////////////////////
// Main game  (singleton)
// holds game settings
// controls game time
/////////////////////////////////////////////////////////

#pragma once

#include "Tools.h"

#include "AIE.h"


class TheGirb
{
	//constructor
	TheGirb();

	//used to access the game
	static TheGirb* instance;

	//screen size (used for world size)
	static Vec2 screenSize;

	//base setting for framework window
	struct
	{
		const char * title;
		bool isFullscreen;
		Vec2* screenSize;
		SColour backgroundColour;
	}frameworkSettings;

	//destructor
	~TheGirb();

public:
	//returns single instance of game
	static TheGirb* GetInstance();

	//gets the screen size
	static Vec2& GetScreenSize();

	//main game loop
	void RunGame();
};