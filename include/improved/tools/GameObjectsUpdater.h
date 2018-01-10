//////////////////////
// Used to call local updates per frame on all game objects
/////////////////////

#pragma once

#include "Tools.h"

class GameObjectsUpdater
{
	static std::list<GameObjectsUpdater*>allGameObjects;
protected:
	//protected constructor
	GameObjectsUpdater();

	//pure virtual update
	virtual void m_GameObjectsUpdate() = 0;

public:
	//calls update for all objects in game
	static void UpdateAllGameObjects();
};