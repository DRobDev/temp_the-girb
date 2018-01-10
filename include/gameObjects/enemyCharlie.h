//////////////////////////////////////////
// First enemy type (hope to get more)
//////////////////////////////////////////

#pragma once

#include "tools\enemyBase.h"
#include <vector>

class GameTime;
class EnemyCharlie : public EnemyBase
{
	static std::vector<EnemyCharlie*> allCharlies;
	static GameTime* gameTime;
	//amount the worldsize changes when this is created or destroyed
	static const float worldSpaceNeeded; 

	float timerStart;
	float timer;

public:
	//default constructor
	EnemyCharlie();



	//override the draw (no background needed)
	virtual void Draw();

	//update main player (call once per frame)
	void UpdateEnemy();

	//darts about like a fish
	void m_dartAbout();
};