#include "tools\GameObjectsUpdater.h"

std::list<GameObjectsUpdater*> GameObjectsUpdater::allGameObjects = std::list<GameObjectsUpdater*>();

void GameObjectsUpdater::UpdateAllGameObjects()
{
	//call update on all game objects
	for(auto i = allGameObjects.begin(); i != allGameObjects.end(); i++)
		(*i)->m_GameObjectsUpdate();
}

GameObjectsUpdater::GameObjectsUpdater()
{
	//add instance to list on creation
	allGameObjects.push_back(this);
}