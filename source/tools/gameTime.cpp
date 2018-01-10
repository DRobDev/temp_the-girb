#include "tools\gameTime.h"
#include "AIE.h"

GameTime* GameTime::gameTimeInstance = nullptr;

GameTime::GameTime()
{
	deltaTime = 0;
	gameTime = 0;
}

GameTime* GameTime::GetInstance()
{
	if(gameTimeInstance == nullptr)
		gameTimeInstance = new GameTime();
	return gameTimeInstance;
}

void GameTime::UpdateTime()
{
	deltaTime = GetDeltaTime();
	fps = 1 / deltaTime;
	gameTime += deltaTime;
}

float GameTime::GetFPS()
{
	return fps;
}