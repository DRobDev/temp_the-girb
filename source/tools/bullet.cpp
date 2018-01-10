#include "tools\bullet.h"
#include "tools\spriteKit.h"
#include "AIE.h"

std::vector<Bullet*> Bullet::allBullets = std::vector<Bullet*>();

Bullet::Bullet(BulletType* a_type) : BallCollider(ColliderTypes::PLAYERBULLET)
{
	allBullets.push_back(this);
	bulletType = a_type;
}

void Bullet::UpdateAllBullets()
{
	for (auto i = allBullets.begin(); i != allBullets.end(); i++)
	{
		(*i)->m_Update();
	}
}

void Bullet::DrawAllBullets()
{
	for (auto i = allBullets.begin(); i != allBullets.end(); i++)
	{
		(*i)->m_Draw();
	}
}

void Bullet::m_Update()
{
	//update collider info
	colRad = (bulletType->sprite->baseSize->x *.5f) / ScaleMultiplyer;
	colliderWorldPos = worldPosition;
	m_moveBullet();
}


void Bullet::m_moveBullet()
{
	MoveLocal(Vec2(0, bulletType->moveSpeed));
}

void Bullet::Hit(Collider* a_othercollider)
{
	velocity = Vec2(2,0);
}

void Bullet::m_Draw()
{
	Vec2 m_size =  *bulletType->sprite->baseSize / ScaleMultiplyer;
	SetSpriteScale(bulletType->sprite->id, m_size.x, m_size.y);

	//set position
	MoveSprite(bulletType->sprite->id, reletivePosition.x, reletivePosition.y);

	//set rotatin (face move direction)
	SetSpriteMatrix(bulletType->sprite->id, spriteMatrix);

	//draw 
	DrawSprite(bulletType->sprite->id);

	//draw foreground (if)
	if(isForeground)
	{
		//set scale
		m_size = *bulletType->sprite->baseSize;
		SetSpriteScale(bulletType->sprite->id, m_size.x, m_size.y);
		//set position
		MoveSprite(bulletType->sprite->id, foregroundPosition.x, foregroundPosition.y);
		//draw
		DrawSprite(bulletType->sprite->id);
	}
}





BulletType::BulletType(UniqueSprite* a_sprite, float a_movSpeed)
{
	sprite = a_sprite;
	moveSpeed = a_movSpeed;
}