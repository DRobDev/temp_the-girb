#include "tools\spriteKit.h"
#include "AIE.h"
#include "tools\vec2.h"


SpriteKit* SpriteKit::instance = nullptr;

//TEMP:
const float SpriteKit::BASEANIMSPEED = 6;


SpriteKit::SpriteKit()
{
	//default anim (place holder)
	alien = new UniqueSprite("./images/charlie/charlie_lvl1_idle_1.png",Vec2(64,64));
	alienDefault = new UniqueAnimation(BASEANIMSPEED, UniqueAnimation::ONCE, 
		alien);

	//player idle
	player_lvl1_idle_1 = new UniqueSprite("./images/player/player_lvl1_idle_1.png", Vec2(128,128));
	player_lvl1_idle_2 = new UniqueSprite("./images/player/player_lvl1_idle_2.png", Vec2(128,128));
	player_lvl1_idle_3 = new UniqueSprite("./images/player/player_lvl1_idle_3.png", Vec2(128,128));
	animPlayerLvl1Idle = new UniqueAnimation(BASEANIMSPEED, UniqueAnimation::PINGPONG, 
		player_lvl1_idle_1, 
		player_lvl1_idle_2, 
		player_lvl1_idle_3);

	//player move
	player_lvl1_move_1 = new UniqueSprite("./images/player/player_lvl1_move_1.png", Vec2(128,128));
	player_lvl1_move_2 = new UniqueSprite("./images/player/player_lvl1_move_2.png", Vec2(128,128));
	player_lvl1_move_3 = new UniqueSprite("./images/player/player_lvl1_move_3.png", Vec2(128,128));
	animPlayerLvl1Move = new UniqueAnimation(BASEANIMSPEED, UniqueAnimation::PINGPONG,
		player_lvl1_move_1,
		player_lvl1_move_2,
		player_lvl1_move_3);

	//enemy idle
	enemy_Charlie_lvl1_idle_1 = new UniqueSprite("./images/charlie/charlie_lvl1_idle_1.png",Vec2(128,128));
	enemy_Charlie_lvl1_idle_2 = new UniqueSprite("./images/charlie/charlie_lvl1_idle_2.png",Vec2(128,128));
	enemy_Charlie_lvl1_idle_3 = new UniqueSprite("./images/charlie/charlie_lvl1_idle_3.png",Vec2(128,128));
	animCharlieLvl1Idle = new UniqueAnimation(BASEANIMSPEED, UniqueAnimation::PINGPONG, 
		enemy_Charlie_lvl1_idle_1, 
		enemy_Charlie_lvl1_idle_2, 
		enemy_Charlie_lvl1_idle_3);

	//enemy move
	enemy_Charlie_lvl1_move_1 = new UniqueSprite("./images/charlie/charlie_lvl1_move_1.png", Vec2(128,128));
	enemy_Charlie_lvl1_move_2 = new UniqueSprite("./images/charlie/charlie_lvl1_move_2.png", Vec2(128,128));
	enemy_Charlie_lvl1_move_3 = new UniqueSprite("./images/charlie/charlie_lvl1_move_3.png", Vec2(128,128));
	animCharlieLvlMove = new UniqueAnimation(BASEANIMSPEED, UniqueAnimation::PINGPONG,
		enemy_Charlie_lvl1_move_1,
		enemy_Charlie_lvl1_move_2,
		enemy_Charlie_lvl1_move_3);

	//fx
	fx_bubble1 = new UniqueSprite("./images/fx/bubble.png", Vec2(32,32));

	//TEMP: background paper TODO: make background move
	backgroundPaper = new UniqueSprite("./images/background/background_paper.png", Vec2(512,512));
}

SpriteKit* SpriteKit::GetInstance()
{
	if(instance == nullptr)
		instance = new SpriteKit();
	return instance;
}



UniqueSprite::UniqueSprite(const char* a_dir, Vec2 a_baseSize)
{
	spriteDir = a_dir;
	baseSize = new Vec2(a_baseSize);
	id = CreateSprite(spriteDir, baseSize->x, baseSize->y, true);
}


UniqueAnimation::UniqueAnimation(float a_frameRate,PlayTypes a_playType, 
								 UniqueSprite* a_frame1, 
								 UniqueSprite* a_frame2,
								 UniqueSprite* a_frame3,
								 UniqueSprite* a_frame4)
{
	playType = a_playType;
	frameRate = a_frameRate;
	frames[0] = a_frame1;
	frameCount = 1;
	if(a_frame2 == nullptr) return; //TODO: set up auto playTypes (frames<2 can't be pingpong, all 1 frame is hold etc)
	frames[1] = a_frame2;
	frameCount = 2;
	if(a_frame3 == nullptr) return;
	frames[2] = a_frame3;
	frameCount = 3;
	if(a_frame4 == nullptr) return;
	frames[3] = a_frame4;
	frameCount = 4;
}

