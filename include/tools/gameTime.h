/////////////////////////////////
// controls functionality pertaining to time
////////////////////////////////


#pragma once

class GameTime
{
	//TEMP:
public:

	static GameTime* gameTimeInstance;
	GameTime();

	float deltaTime;
	float gameTime;
	float fps;
	

public:
	//returns instance of game time
	static GameTime* GetInstance();

	//updates time variables (call once per frame)
	void UpdateTime();

	//returns the 'frames per second'
	float GetFPS();

	
};