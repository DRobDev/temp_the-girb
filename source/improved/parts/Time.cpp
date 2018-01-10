#include "tools/Time.h"

#include "TheGirb.h"

float Time::deltaTime = 0;
int Time::fps = 0;

float Time::gameTime = 0;

//local
Time::Time()
{
}	

void Time::UpdateGameTime()
{
	deltaTime = GetDeltaTime();
	fps = 1 / deltaTime;
	gameTime += deltaTime;
}

Time::~Time()
{
}

//static
float Time::GetDelta()
{
	return deltaTime;
}