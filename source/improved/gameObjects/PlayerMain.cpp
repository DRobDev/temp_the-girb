#include "gameObjects\PlayerMain.h"

#ifdef _DEBUG
bool PlayerMain::alreadyCreated = false;
#endif // _DEBUG

PlayerMain::PlayerMain()
	//TEMP: update with animated later
	: CollisionSimplePhysics(
	PreDefSprites::PLAYER_LVL1_IDLE_1,		//player sprite
	Collider::ColliderType::PLAYERBODY,		//collider type
	Vec2(500, 400), //Vec2::ZERO,								//starting position
	60,										//mass
	60,										//drag
	Drawer::DrawPriority::TOP)				//draw priority
{
#ifdef _DEBUG
	assert(!alreadyCreated && "More than one main player has been created");
	alreadyCreated = true;
#endif // _DEBUG

	//TEMP:
	moveSpeed = Vec2(0,400);
}


//main update for player ////////////////////////////////////////
void PlayerMain::m_GameObjectsUpdate()
{
	//rotate to face cursor
	m_LookAtCursor();
	//move player towards cursor on press
	m_PlayerMove();


};
/////////////////////////////////////////////////////////////////

void PlayerMain::m_LookAtCursor()
{
	//rotate to face cursor//
	static Vec2 m_mousePosHolder = Vec2();
	static double m_mouseX, m_mouseY;
	GetMouseLocation(m_mouseX, m_mouseY);			//get mouse location
	m_mouseY = Map::GetWorldSize().y - m_mouseY;	//flip 'y' coords
	m_mousePosHolder.x = m_mouseX;					//place in vector
	m_mousePosHolder.y = m_mouseY;
	LookAt(m_mousePosHolder);						//pass vector to lookat
	//---------------------//
}

void PlayerMain::m_PlayerMove()
{
	if(GetMouseButtonDown(MOVE_BUTTON))
	{
		tranformDynam->AddForceLocal(moveSpeed);
	}
}