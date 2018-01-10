//////////////////////////////
// Enemy base class
//////////////////////////////

#pragma once

#include "tools\vec2.h"
#include "tools\transform.h"
#include "tools\collider.h"
#include <vector>

class UniqueSprite;
class UniqueAnimation;
class EnemyUpgradeLevel;
class Animation;

class EnemyBase : public Transform, public BallCollider
{
	static std::vector<EnemyBase*>AllEnemies;
public:
	static void UpdateAllEnemies();
	static void DrawAllEnemies();
protected:
	//player levels
	static EnemyUpgradeLevel* Level1;

	//default constructor
	EnemyBase();


	//handles animation controls
	Animation* animator;

	//current player level (upgrade level)
	EnemyUpgradeLevel* currentLevel;

	virtual void Hit(Collider* a_otherCol);

	//update enemy
	virtual void UpdateEnemy();
	// draw enemy
	virtual void Draw();
};

class EnemyUpgradeLevel
{
public:
	//constructor
	EnemyUpgradeLevel(float a_moveSpeed, 
		UniqueAnimation* a_idleAnim,
		UniqueAnimation* a_moveAnim);

	UniqueAnimation* idleAnim;
	UniqueAnimation* moveAnim;
	UniqueAnimation* meleAnim;

	float moveSpeed;
	//handling
	//etc
};