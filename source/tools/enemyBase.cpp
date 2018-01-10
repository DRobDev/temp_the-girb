
#include "tools\enemyBase.h"
#include "tools\spriteKit.h"
#include "AIE.h"
#include "tools\animation.h"
#include "debugging\debugWindow.h"

//set up player levels
EnemyUpgradeLevel* EnemyBase::Level1 = nullptr;
std::vector<EnemyBase*> EnemyBase::AllEnemies = std::vector<EnemyBase*>();

EnemyBase::EnemyBase() : BallCollider(ColliderTypes::ENEMYBODY)
{
	//set up player levels TODO: this is gay
	if(Level1 == nullptr)
	{
		Level1 = new EnemyUpgradeLevel(
			20,												//move speed
			SpriteKit::GetInstance()->animCharlieLvl1Idle,	//idle anim
			SpriteKit::GetInstance()->animCharlieLvlMove	//move anim
			);
	}

	currentLevel = Level1;
	animator = new Animation();
	SetCollisionRadius(animator->GetCurrentFrame()->baseSize->x *.5f);
	AllEnemies.push_back(this);
}

void EnemyBase::UpdateAllEnemies()
{
	for(auto i = AllEnemies.begin(); i != AllEnemies.end(); i++)
	{
		(*i)->UpdateEnemy();
	}
}

void EnemyBase::DrawAllEnemies()
{
	for(auto i = AllEnemies.begin(); i != AllEnemies.end(); i++)
	{
		(*i)->Draw();
	}
}

void EnemyBase::Draw()
{
	//draw background sprite
	//set scale
	Vec2 m_size = *animator->GetCurrentFrame()->baseSize / ScaleMultiplyer;
	SetSpriteScale(animator->GetCurrentFrame()->id, m_size.x, m_size.y);

	//set position
	MoveSprite(animator->GetCurrentFrame()->id, reletivePosition.x, reletivePosition.y);

	//set rotatin (face move direction)
	float m_angle = atan2f(velocity.x, velocity.y);
	spriteMatrix[0] = cosf(m_angle);	spriteMatrix[1] = -sinf(m_angle);
	spriteMatrix[4] = sinf(m_angle);	spriteMatrix[5] = cosf(m_angle);
	SetSpriteMatrix(animator->GetCurrentFrame()->id, spriteMatrix);

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

void EnemyBase::Hit(Collider* a_otherCol)
{
	if(a_otherCol->colliderWorldPos == colliderWorldPos) return;
	//bounce off enemy if hit
	const float bounceAmount = 1;
	//if(a_otherCol->colType == ColliderTypes::PLAYERBODY)
	{
		velocity = colliderWorldPos - a_otherCol->colliderWorldPos;
		velocity = velocity * ( bounceAmount / sqrtf(powf(velocity.x,2) + powf(velocity.y, 2)));
	}
}

void EnemyBase::UpdateEnemy()
{
	SetColliderPosition(worldPosition);
	SetCollisionRadius((animator->GetCurrentFrame()->baseSize->x * .5f) / ScaleMultiplyer);
}

EnemyUpgradeLevel::EnemyUpgradeLevel(float a_moveSpeed, UniqueAnimation* a_idleAnim, UniqueAnimation* a_moveAnim)
{
	moveSpeed = a_moveSpeed;
	idleAnim = a_idleAnim;
	moveAnim = a_moveAnim;
}


