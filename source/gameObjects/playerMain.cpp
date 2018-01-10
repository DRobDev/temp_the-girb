#include "gameObjects\playerMain.h"
#include "AIE.h"
#include "tools\spriteKit.h"
#include "tools\camera.h"
#include "tools\gameTime.h"
#include "tools\animation.h"
#include "debugging\debugWindow.h"
#include "tools\bullet.h"

bool PlayerMain::isCreated = false;
Vec2 PlayerMain::centerOffset = (*worldSize / 2);

PlayerMain::PlayerMain()
{
	//TEMP: do this better
	if(isCreated == true) while(true);

	//access camera
	camera = Camera::GetInstance();
	isCreated = true; //there can be only one
	DebugWindow::AddAWatcher(&velocity.x, "vel x");
	DebugWindow::AddAWatcher(&velocity.y, "vel y");
	SetColliderPosition(worldPosition + centerOffset);
}

void PlayerMain::UpdatePlayer()
{
	//set camera position
	camera->SetWorldPosition(worldPosition);
	//move player on key press
	m_MovePlayer();
	//rotate to look at moust
	m_LookAtMouse();
	//update collider position
	SetColliderPosition(worldPosition + centerOffset);
	m_LoopWorld(colliderWorldPos);
	//adjust radius base on scale
	SetCollisionRadius((animator->GetCurrentFrame()->baseSize->x * .5f) / ScaleMultiplyer);
	//fire on press
	m_fire();
}

void PlayerMain::Draw()
{
	//select animation to draw
	if(velocity == Vec2::ZERO)
		animator->Play(currentLevel->idleAnim); //idle when not moving
	else
		animator->Play(currentLevel->moveAnim);

	//set scale
	SetSpriteScale(animator->GetCurrentFrame()->id, animator->GetCurrentFrame()->baseSize->x, animator->GetCurrentFrame()->baseSize->y);
	//set position
	spriteMatrix[12] = centerOffset.x; spriteMatrix[13] = centerOffset.y;
	//rotate sprite
	SetSpriteMatrix(animator->GetCurrentFrame()->id, spriteMatrix);
	//draw 
	DrawSprite(animator->GetCurrentFrame()->id);
}

void PlayerMain::m_LookAtMouse()
{
	//get mouse position relative to center
	double m_x, m_y;
	GetMouseLocation(m_x, m_y);
	if(m_x == 0 || m_y == 0) return;

	m_x = worldCenter.x - m_x;
	m_y = worldCenter.y - m_y;

	//calculate angle(rad)
	float m_angle = atan2f(m_x, m_y);

	//update rotation matrix
	spriteMatrix[0] = cosf(m_angle);	spriteMatrix[1] = sinf(m_angle);
	spriteMatrix[4] = -sinf(m_angle);	spriteMatrix[5] = cosf(m_angle);
}

void PlayerMain::m_MovePlayer()
{
	//TODO: make keys non constant

	//move player on key press
	//get desried position
	Vec2 m_desMov = Vec2();
	if(GetMouseButtonDown(MOUSE_BUTTON_2))
	{
		m_desMov.y = currentLevel->moveSpeed;
	}
	//set position
	MoveLocal(m_desMov);
}

void PlayerMain::m_fire()
{
	static bool m_pressedOnce = false;
	if(GetMouseButtonDown(MOUSE_BUTTON_1))
	{
		if(!m_pressedOnce)
		{
			Bullet* b = new Bullet(currentLevel->bulletType);
			Vec2 pos = worldPosition + centerOffset;
			b->SetWorldPosition(pos);
			m_pressedOnce = true;
		}
	}
	if(GetMouseButtonReleased(MOUSE_BUTTON_1))
		m_pressedOnce = false;

}


