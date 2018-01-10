/////////////////////////
// base player (to be used for other multiplayer'rs)
///////////////////////////

#pragma once

#include "tools\transform.h"
#include "tools\collider.h"

class BulletType;
class UniqueSprite;
class UniqueAnimation;
class PlayerUpgradeLevel;
class Animation;

class PlayerBase : public Transform, public BallCollider
{
protected:
	//player levels
	static PlayerUpgradeLevel* Level1;

	//default constructor
	PlayerBase();


	//handles animation controls
	Animation* animator;

	//current player level (upgrade level)
	PlayerUpgradeLevel* currentLevel;

	//called when collider hits another
	virtual void Hit(Collider* a_otherCol);


	// draw enemy
	virtual void Draw();
};

class PlayerUpgradeLevel
{
public:
	//constructor
	PlayerUpgradeLevel(
		BulletType* a_bulletType,
		float a_moveSpeed,
		UniqueAnimation* a_idleAnim,
		UniqueAnimation* a_moveAnim);

	UniqueAnimation* idleAnim;
	UniqueAnimation* moveAnim;
	UniqueAnimation* meleAnim;

	BulletType* bulletType;

	float moveSpeed;
	//handling
	//etc
};