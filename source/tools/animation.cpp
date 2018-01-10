#include "tools\animation.h"
#include "tools\gameTime.h"
#include "tools\spriteKit.h"

std::vector<Animation*> Animation::allAnimations = std::vector<Animation*>();

Animation::Animation()
{
	allAnimations.push_back(this);
	gameTime = GameTime::GetInstance();

	Play(SpriteKit::GetInstance()->alienDefault);
}

void Animation::UpdateAllAnimations()
{
	for(auto i = allAnimations.begin(); i != allAnimations.end(); i++)
	{
		(*i)->m_UpdateAnimation();
	}
}

void Animation::Play(UniqueAnimation* a_anim)
{
	//wait for last animation
	bool m_startAnimation = false;
	switch (a_anim->playType)
	{
	case UniqueAnimation::ONCE:
		m_startAnimation = true;
		break;
	case UniqueAnimation::LOOP:
	case UniqueAnimation::PINGPONG:
		if(a_anim != currentAnimation)
			if(currentAnimation->playType != UniqueAnimation::ONCE || isFinished)
				m_startAnimation = true;
		break;
	case UniqueAnimation::HOLD:
		break;
	case UniqueAnimation::DEFAULT:
		break;
	default:
		break;
	}

	if(m_startAnimation)
	{
		frameLength = (1 / a_anim->frameRate);
		animationLength = a_anim->frameCount * frameLength;

		animationStartTime = gameTime->gameTime;
		animationCurrentTime = 0;
		isFinished = false;

		currentAnimation = a_anim;
		currentFrame = a_anim->frames[0];
	}
}

UniqueSprite* Animation::GetCurrentFrame()
{
	return currentFrame;
}

void Animation::m_UpdateAnimation()
{
	if(isFinished) return;

	switch (currentAnimation->playType)
	{
	case UniqueAnimation::ONCE:
		animationCurrentTime = gameTime->gameTime - animationStartTime;
		if(animationCurrentTime > animationLength)
		{isFinished = true; return;} //get to the end and stop

		for(int i = 0; i < currentAnimation->frameCount; i++)//play animation once
		{
			if(animationCurrentTime < frameLength + (frameLength*i))
			{
				currentFrame = currentAnimation->frames[i];
				return;
			}
		}
		break;
	case UniqueAnimation::LOOP:
		animationCurrentTime = gameTime->gameTime - animationStartTime; //get animation time
		if(animationCurrentTime > animationLength)
		{
			animationCurrentTime = 0; //loop time when end hit
			animationStartTime = gameTime->gameTime;
		}
		for(int i = 0; i < currentAnimation->frameCount; i++)
		{
			if(animationCurrentTime < frameLength + (frameLength*i))
			{
				currentFrame = currentAnimation->frames[i];
				return;
			}
		}
		break;
	case UniqueAnimation::PINGPONG:
		//loop at end of ping pong
		animationCurrentTime = gameTime->gameTime - animationStartTime; //get animation time
		if(animationCurrentTime > (animationLength * 2)-(frameLength * 2)) //(remove two frames (first and last frame being called twice) 
		{
			animationCurrentTime = 0; //loop time when back at start
			animationStartTime = gameTime->gameTime;
		}

		//ping pong through frames
		for(int i = 0; animationCurrentTime < animationStartTime + ((animationLength * 2)-(frameLength * 2)); i++)
		{
			if(animationCurrentTime < frameLength + (frameLength *i)) //pick frame based on time
			{
				if(i < currentAnimation->frameCount) //play normal
					currentFrame = currentAnimation->frames[i];
				else
					currentFrame = currentAnimation->frames[ currentAnimation->frameCount*2 - (i+2)  ];
				return;
			}
		}

		break;
	case UniqueAnimation::HOLD:
		break;
	case UniqueAnimation::DEFAULT:
		break;
	default:
		break;
	}

}



