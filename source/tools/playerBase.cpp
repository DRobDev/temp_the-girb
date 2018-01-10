
#include "tools\playerBase.h"
#include "tools\spriteKit.h"
#include "AIE.h"
#include "tools\animation.h"
#include "tools\bullet.h"

//set up player levels
PlayerUpgradeLevel* PlayerBase::Level1 = nullptr;

PlayerBase::PlayerBase():
	BallCollider(ColliderTypes::PLAYERBODY)
{
	//set up player levels TODO: this is gay
	if(Level1 == nullptr)
	{
		Level1 = new PlayerUpgradeLevel(
			new BulletType(SpriteKit::GetInstance()->alien, 10),//bullet
			4,												//move speed
			SpriteKit::GetInstance()->animPlayerLvl1Idle,	//idle anim
			SpriteKit::GetInstance()->animPlayerLvl1Move	//move anim
			);
	}

	currentLevel = Level1;
	animator = new Animation();
	SetCollisionRadius(animator->GetCurrentFrame()->baseSize->x *.5f);

}

void PlayerBase::Draw()
{
	//draw background sprite
	//set scale
	Vec2 m_size = *animator->GetCurrentFrame()->baseSize / ScaleMultiplyer;
	SetSpriteScale(animator->GetCurrentFrame()->id, m_size.x, m_size.y);
	//set position
	MoveSprite(animator->GetCurrentFrame()->id, reletivePosition.x, reletivePosition.y);
	//draw 
	DrawSprite(animator->GetCurrentFrame()->id);

	//draw foreground (if)
	if(isForeground)
	{
		//set scale
		m_size = *animator->GetCurrentFrame()->baseSize;
		SetSpriteScale(animator->GetCurrentFrame()->id, m_size.x, m_size.y);
		//set position
		MoveSprite(animator->GetCurrentFrame()->id, foregroundPosition.x, foregroundPosition.y);
		//draw
		DrawSprite(animator->GetCurrentFrame()->id);
	}
}

void PlayerBase::Hit(Collider* a_otherCol)
{
	//bounce off enemy if hit
	const float bounceAmount = 1;
	if(a_otherCol->colType == ColliderTypes::ENEMYBODY)
	{
		velocity = colliderWorldPos - a_otherCol->colliderWorldPos;
		velocity = velocity * ( bounceAmount / sqrtf(powf(velocity.x,2) + powf(velocity.y, 2)));
	}
}


PlayerUpgradeLevel::PlayerUpgradeLevel(BulletType* a_bulletType, float a_moveSpeed, UniqueAnimation* a_idleAnim, UniqueAnimation* a_moveAnim)
{
	bulletType = a_bulletType;
	moveSpeed = a_moveSpeed;
	idleAnim = a_idleAnim;
	moveAnim = a_moveAnim;
}



