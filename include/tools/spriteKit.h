////////////////////////////////////
// Holds all sprites
// Single sprite used multiple times (moved between draws)
///////////////////////////////////

#pragma once



class UniqueSprite;
class UniqueAnimation;
class Vec2;

class SpriteKit
{
	static SpriteKit* instance;
	SpriteKit();
public:
	static SpriteKit* GetInstance();

	static const float BASEANIMSPEED;

	//Default anim used to initialize
	UniqueSprite* alien;
	UniqueAnimation* alienDefault;

	//Player
	//idle anim frames
	UniqueSprite* player_lvl1_idle_1;
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

	UniqueSprite* backgroundPaper;

	

};


class UniqueSprite
{
public:
	UniqueSprite(const char* a_dir, Vec2 a_baseSize);

	const char* spriteDir;
	int id;
	Vec2* baseSize;
};

class UniqueAnimation
{
	static const int MAXFRAMES = 4;

public:
	enum PlayTypes
	{
		ONCE,
		LOOP,
		PINGPONG,
		HOLD,
		DEFAULT
	};
	//constructor
	UniqueAnimation(float a_frameRate, PlayTypes a_playType, 
		UniqueSprite* a_frame1, 
		UniqueSprite* a_frame2 = nullptr,
		UniqueSprite* a_frame3 = nullptr,
		UniqueSprite* a_frame4 = nullptr);

	//how fast to play the animation
	float frameRate;
	//number of frames in animation
	int frameCount;
	//play type
	PlayTypes playType;

	//frames in this animation
	UniqueSprite* frames[MAXFRAMES];
};
