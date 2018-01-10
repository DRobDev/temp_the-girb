/////////////////////////////////////
// bullet
/////////////////////////////////////

#pragma once

#include "tools\transform.h"
#include "tools\collider.h"
#include <vector>

class UniqueSprite;
class BulletType;
class Bullet : public Transform, public BallCollider
{
	static std::vector<Bullet*>allBullets;
public:
	//add new bullet to vector when created
	Bullet(BulletType* a_type);

	BulletType* bulletType;


	//updates all bullets
	static void UpdateAllBullets();

	//draw all bullets
	static void DrawAllBullets();


	//draw this bullet
	void m_Draw();

	//update this bullet
	void m_Update();

	//move bullet along it's own axis
	void m_moveBullet();

	virtual void Hit(Collider* a_otherCol);

};

class BulletType
{
public:
	BulletType(UniqueSprite* a_sprite, float a_movSpeed);
	UniqueSprite* sprite;
	float moveSpeed;
};