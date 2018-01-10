#include "gameObjects\enemyCharlie.h"
#include "AIE.h"
#include "tools\spriteKit.h"
#include "tools\gameTime.h"
#include "tools\animation.h"
#include "debugging\debugWindow.h"
#include "tools\vec2.h"


GameTime* EnemyCharlie::gameTime = nullptr;
const float EnemyCharlie::worldSpaceNeeded = .2f;

EnemyCharlie::EnemyCharlie()
{
	gameTime = GameTime::GetInstance();
	timer = 0; timerStart = 0;
	SetScaleMultiplyer(worldSpaceNeeded + ScaleMultiplyer);
}

void EnemyCharlie::UpdateEnemy()
{
	m_dartAbout();
	timer = gameTime->gameTime - timerStart;
	EnemyBase::UpdateEnemy();
}

void EnemyCharlie::Draw()
{
	//select animation to draw
	if(velocity == Vec2::ZERO)
		animator->Play(currentLevel->idleAnim); //idle when not moving
	else
		animator->Play(currentLevel->moveAnim);

	//draw
	EnemyBase::Draw();
}


void EnemyCharlie::m_dartAbout()
{
	//true if darted
	static bool hasDarted = false;

	//strength of dart
	const float dartStrength = 1000;
	//time between darts
	const float pauseDuration = 3;

	//time to complete cycle
	const float routineLength = pauseDuration;


	if(timer > routineLength) {timerStart = gameTime->gameTime; hasDarted = false;} //reset timer if routine complete

	if(!hasDarted)
	{
		Vec2 dartDirection;

		float randomPercentage = rand() % 100;
		randomPercentage = randomPercentage / 100;
		dartDirection.x = (dartStrength*2) * randomPercentage;
		randomPercentage = rand() % 100;
		randomPercentage = randomPercentage / 100;
		dartDirection.y = (dartStrength*2) * randomPercentage;

		dartDirection.x = dartDirection.x - dartStrength;
		dartDirection.y = dartDirection.y - dartStrength;

		randomPercentage = sqrtf(powf(dartDirection.x, 2) + powf(dartDirection.y, 2));
		randomPercentage = dartStrength / randomPercentage;

		dartDirection.x *= randomPercentage;
		dartDirection.y *= randomPercentage;

		velocity = dartDirection * gameTime->deltaTime;

		hasDarted = true;
	}



};
