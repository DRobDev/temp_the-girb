/////////////////////////////////
// Handles animation
////////////////////////////////

#pragma once

#include <vector>

class UniqueSprite;
class UniqueAnimation;
class GameTime;
class Animation
{
public:
	//updates all animations in holder
	static void UpdateAllAnimations();

private:
	//holder for all animated sprites
	static std::vector<Animation*> allAnimations;

	//current animation
	UniqueAnimation* currentAnimation;
	//current frame
	UniqueSprite* currentFrame;
	//tiemr
	GameTime* gameTime;


	//true if animation has finished
	bool isFinished;
	//play length for animation
	float animationLength;
	//lenght of eatch frame
	float frameLength;
	//start time for animation
	float animationStartTime;
	//current time for animation
	float animationCurrentTime;

public:


	//constructo
	Animation();

	//returns current frame
	UniqueSprite* GetCurrentFrame();
	//plays animation
	void Play(UniqueAnimation* a_anim);

	//update animation
	void m_UpdateAnimation();

};
