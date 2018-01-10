/////////////////////////////////////
// used for handling all draw related tasks
////////////////////////////////////

#pragma once

#include "Tools.h"

class Drawer
{
	//containtrs for sprites based on priority
	static std::list<int*> top;	//drawn on top
	static std::list<int*> mid;	//drawn on middle
	static std::list<int*> back;	//drawn on bottom

public:
	//create instace of drawer; (only one can be made)
	Drawer();

	//draws all sprites
	static void DrawGame();

	//enum for draw priority
	enum DrawPriority
	{
		TOP,
		MID,
		BACK,
		DEFAULT
	};

	//adds reference to sprite ID to drawer
	static void AddSpriteToDraw(int& a_idR, DrawPriority a_priority);

	//removes sprite id from list
	static void RemoveSpriteFromDrawer(int& a_idR, DrawPriority a_spritePriority);

	~Drawer();
};