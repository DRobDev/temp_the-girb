#include "tools\fx.h"
#include "tools\Vec2.h"
#include "tools\spriteKit.h"
#include "AIE.h"
#include "tools\gameTime.h"

Fx* Fx::instance = nullptr;
GameTime* Fx::gameTime = nullptr;

Fx::Fx()
{
	gameTime = GameTime::GetInstance();
}

Fx* Fx::GetInstance()
{
	if(instance == nullptr)
	{
		instance = new Fx();
	}
	return instance;
}


void Fx::UpdateFX()
{
	Particle::UpdateAllParticles();
}	

void Fx::DrawFx()
{
	Particle::DrawAllParticles();
}

void Fx::LeaveBubbles(Vec2 a_position, float a_frequency)
{
	//if(fmodf(gameTime->gameTime, 
}




std::vector<Particle*> Particle::allParticles = std::vector<Particle*>();

Particle::Particle(UniqueSprite* a_sprite)
{
	sprite = a_sprite;
	duration = 5;
	m_startTime = gameTime->gameTime;
	allParticles.push_back(this);	
}

void Particle::UpdateAllParticles()
{
	for (auto i = allParticles.begin(); i != allParticles.end(); i++)
	{
		(*i)->Update();
	}
}

void Particle::DrawAllParticles()
{
	for (auto i = allParticles.begin(); i != allParticles.end(); i++)
	{
		(*i)->Draw();
	}
}

void Particle::Draw()
{
	//draw background sprite
	//set scale
	Vec2 m_size = *sprite->baseSize / ScaleMultiplyer;
	SetSpriteScale(sprite->id, m_size.x, m_size.y);

	//set position
	MoveSprite(sprite->id, reletivePosition.x, reletivePosition.y);

	//draw 
	DrawSprite(sprite->id);

	//draw foreground (if)
	if(isForeground)
	{
		//set scale
		m_size = *sprite->baseSize;
		SetSpriteScale(sprite->id, m_size.x, m_size.y);
		//set position
		MoveSprite(sprite->id, foregroundPosition.x, foregroundPosition.y);
		//draw
		DrawSprite(sprite->id);
	}
}

void Particle::Update()
{
	
}








