#include "TheGirb.h"

#include "gameObjects\PlayerMain.h"

#include "elements\Simple.h"
#include "elements\SimplePhysics.h"
#include "elements\CollisionSimple.h"
#include "elements\CollisionSimplePhysics.h"

#include "tools\PhysicsUpdater.h"
#include "tools\GameObjectsUpdater.h"



//TEMP:
#include "debugging\DebugWindow.h"

TheGirb* TheGirb::instance = nullptr;
Vec2 TheGirb::screenSize = Vec2(1000,900);

TheGirb* TheGirb::GetInstance()
{
	if(instance == nullptr)
		instance = new TheGirb();
	return instance;
}

TheGirb::TheGirb()
{
	//initialize framework settings
	frameworkSettings.title				= "THE GIRB";
	frameworkSettings.isFullscreen		= false;
	frameworkSettings.backgroundColour	= SColour(0,0,0,255);//black
	frameworkSettings.screenSize		= &screenSize;

	//initialze frameworkd
	Initialise(
		frameworkSettings.screenSize->x,		//window width
		frameworkSettings.screenSize->y,		//window height
		frameworkSettings.isFullscreen,		//fullscreen
		frameworkSettings.title);			//title

	//set background colour
	SetBackgroundColour(frameworkSettings.backgroundColour);

}

///////////////////////////////////////////////////////////
// MAIN GAME LOOP
void TheGirb::RunGame()
{
	//CollisionSimple simp( 
	//	PreDefSprites::DEFAULT,
	//	Collider::ColliderType::OBJECT,
	//	Vec2(200,800));

	//CollisionSimplePhysics simpB( 
	//	PreDefSprites::DEFAULT,
	//	Collider::ColliderType::OBJECT,
	//	Vec2(999,600));

	PlayerMain player;


	float FPS;
	DebugWindow::AddAWatcher(&FPS, "delta");

	DebugWindow::AddAWatcher(&player.tranformDynam->velocity.x, "velX");
	DebugWindow::AddAWatcher(&player.tranformDynam->velocity.y, "velY");

	do 
	{
		FPS = Time::fps;

		DebugWindow::GetInstance()->DrawWindow();

	/*	if(IsKeyDown(KEY_SPACE))
			simp.Move(Vec2(0,20));*/
		//simp.SetRotation(mouseXf);
		//simp.LookAt(mousePos);


		//update game objects
		GameObjectsUpdater::UpdateAllGameObjects();
		//update physics
		PhysicsUpdater::UpdateAllPhysics();
		//update colliders
		Collider::UpdateAllColliders();
		//update game time
		Time::UpdateGameTime();
		//draw game
		Drawer::DrawGame();

	} while ( FrameworkUpdate() == false );

	Shutdown();
}
/////////////////////////////////////////////////////////////

TheGirb::~TheGirb()
{
}

Vec2& TheGirb::GetScreenSize()
{
	return screenSize;
}

