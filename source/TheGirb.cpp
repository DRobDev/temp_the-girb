//////////////////////////////////////////////////////////////////////////
// The Girb
//\
/////////////////////////////////////////////////////////////////////////

#pragma once

#include "TheGirb.h"
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include <vector>

#include "tools\map.h"
#include "tools\spriteKit.h"
#include "tools\vec3.h"

#include "tools\transform.h"
#include "tools\enemyBase.h"
#include "debugging\debugWindow.h"
#include "tools\camera.h"
#include "tools\gameTime.h"
#include "gameObjects\playerMain.h"
#include "gameObjects\enemyCharlie.h"
#include "tools\collider.h"
#include "tools\animation.h"
#include "tools\fx.h"
#include "tools\bullet.h"

Vec2 TheGirb::ScreenSize = Vec2(1000,800);

TheGirb::TheGirb()
{
	//setup game window
	Initialise(ScreenSize.x, ScreenSize.y, false, "The Girb" );
	SetBackgroundColour( SColour( 0x00, 0x00, 0x00, 0xFF ) );
	backgroundImage = SpriteKit::GetInstance()->backgroundPaper;

	//get game time
	gametime = GameTime::GetInstance();
	//create player
	playerMain = new PlayerMain();
}

void TheGirb::RunGame()
{
	//TESTING
	DebugWindow* debug = DebugWindow::GetInstance();
	//add fps
	DebugWindow::AddAWatcher(&gametime->fps, "FPS");


	std::vector<EnemyCharlie*> allCharlie;

	for(int i = 0; i < 20; i++)
		new EnemyCharlie;


	do 
	{
		//clear all previous draws
		ClearScreen();

		//TESTING



		//update game time variables
		gametime->UpdateTime();
		playerMain->UpdatePlayer();


		//update all transforms in game
		Transform::UpdateAllTransforms();
		//updat all animations
		Animation::UpdateAllAnimations();
		//update all fxs
		Fx::UpdateFX();
		//update all colliders
		Collider::UpdateAllColliders();
		//update all enemies
		EnemyBase::UpdateAllEnemies();
		//update bullets
		Bullet::UpdateAllBullets();


		//TEMP:
		//m_DrawBackground();



		EnemyBase::DrawAllEnemies();
		Bullet::DrawAllBullets();
		Fx::DrawFx();

		playerMain->Draw();


		//beak on escape press
		if(IsKeyDown(KEY_ESCAPE))
			bool lka = true;
		//draw foreground as box
		DebugWindow::GetInstance()->DrawBox(Transform::ForegroundStart, Transform::ForegroundEnd);
		//draw debug info
		debug->DrawWindow();

	} while ( FrameworkUpdate() == false );

	//DestroySprite(testSprId);

	Shutdown();


}


void TheGirb::m_DrawBackground()
{
	static bool posSet = false;
	static Transform backgroundTran;
	for(int x = 0; backgroundImage->baseSize->x * (x-1) < ScreenSize.x; x++)
	{
		for(int y = 0; backgroundImage->baseSize->y * (y-1) < ScreenSize.y; y++)
		{
			if(!posSet)
			{
				backgroundTran.SetWorldPosition(-(ScreenSize / 2));
				posSet = true;
			}

			MoveSprite(backgroundImage->id, backgroundTran.reletivePosition.x + (backgroundImage->baseSize->x * x), backgroundTran.reletivePosition.y + (backgroundImage->baseSize->y * y));

			DrawSprite(backgroundImage->id);
		}
	}
}