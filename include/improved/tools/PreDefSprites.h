////////////////////////////////////
// Holds all sprites
// Single sprite used multiple times (moved between draws)
///////////////////////////////////

#pragma once
#include "Tools.h"


class PredefinedSprite
{
public:
	PredefinedSprite(const char* a_dir, Vec2 a_baseSize)
	{
		spriteDir = a_dir;
		baseSize = a_baseSize;
	}
	const char* spriteDir;
	Vec2 baseSize;
};

class PreDefSprites
{
	PreDefSprites();
public:

	//Default anim used to initialize
	static const PredefinedSprite DEFAULT;

	//Player
	//idle anim frames
	static const PredefinedSprite PLAYER_LVL1_IDLE_1;
		/*
	UniqueSprite* player_lvl1_idle_2;
	UniqueSprite* player_lvl1_idle_3;
	UniqueAnimation* animPlayerLvl1Idle;
	//move anim
	UniqueSprite* player_lvl1_move_1;
	UniqueSprite* player_lvl1_move_2;
	UniqueSprite* player_lvl1_move_3;
	UniqueAnimation* animPlayerLvl1Move;

	//Enemy Charlie
	//idle anim frames
	UniqueSprite* enemy_Charlie_lvl1_idle_1;
	UniqueSprite* enemy_Charlie_lvl1_idle_2;
	UniqueSprite* enemy_Charlie_lvl1_idle_3;
	UniqueAnimation* animCharlieLvl1Idle;
	//move anim
	UniqueSprite* enemy_Charlie_lvl1_move_1;
	UniqueSprite* enemy_Charlie_lvl1_move_2;
	UniqueSprite* enemy_Charlie_lvl1_move_3;
	UniqueAnimation* animCharlieLvlMove;
	
	//fx
	UniqueSprite* fx_bubble1;
	UniqueSprite* backgroundPaper;*/

	

};




//class PredefinedAnimation
//{
//	static const int MAXFRAMES = 4;
//
//public:
//	enum PlayTypes
//	{
//		ONCE,
//		LOOP,
//		PINGPONG,
//		HOLD,
//		DEFAULT
//	};
//	//constructor
//	PredefinedAnimation(float a_frameRate, PlayTypes a_playType, 
//		UniqueSprite* a_frame1, 
//		UniqueSprite* a_frame2 = nullptr,
//		UniqueSprite* a_frame3 = nullptr,
//		UniqueSprite* a_frame4 = nullptr);
//
//	//how fast to play the animation
//	float frameRate;
//	//number of frames in animation
//	int frameCount;
//	//play type
//	PlayTypes playType;
//
//	//frames in this animation
//	UniqueSprite* frames[MAXFRAMES];
//};
