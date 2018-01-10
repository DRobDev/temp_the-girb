////////////////////////////////
// Time
//////////////////////////////////


#pragma once

class Time
{
	//TEMP:
public:
	//time variables
	static float	deltaTime;
	static float	gameTime;
	static int		fps;

public:
	//only one instance can be created
	Time();

	//updates game time variables
	static void UpdateGameTime();

	//returns delta time
	static float GetDelta();

	//destructor
	~Time();
};