//////////////////////////////////////////////////
// Behaviour types
// regulate movement, aggresion etc
///////////////////////////////////////////////////


#pragma once

#include "tools\transform.h"
#include <vector>

class Vec2;
class UniqueSprite;
class Particle;
class GameTime;
class Fx
{
	static GameTime* gameTime;
	static Fx* instance;
	Fx();

public:
	//get class instance
	static Fx* GetInstance();

	//updates all fxs
	static void UpdateFX();
	//draws all fxs
	static void DrawFx();

	//leaves a trail of bubbles
	void LeaveBubbles(Vec2 a_position, float a_frequency);
};

class VelocityBubbleTrail
{

};

class Particle : public Transform 
{
	static std::vector<Particle*> allParticles;

public:
	Particle(UniqueSprite* a_sprite);

	static void UpdateAllParticles();
	static void DrawAllParticles();

	float duration;
	float m_startTime;

	UniqueSprite* sprite;

	void Update();
	void Draw();

};




