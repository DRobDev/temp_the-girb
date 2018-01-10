#include "tools/transform.h"
#include "TheGirb.h"
#include <cmath>
#include "tools\gameTime.h"

//temp
#include "AIE.h"

GameTime* Transform::gameTime = GameTime::GetInstance();

Transform* Transform::CameraTran = nullptr;
std::vector<Transform*> Transform::allTransforms = std::vector<Transform*>();

Vec2* Transform::worldSize = &TheGirb::ScreenSize;
Vec2 Transform::worldCenter = *Transform::worldSize/2;

float Transform::ScaleMultiplyer = 2;
Vec2 Transform::ForegroundSize = *Transform::worldSize /  Transform::ScaleMultiplyer;

Vec2 Transform::ForegroundStart = Vec2();
Vec2 Transform::ForegroundEnd = Vec2();

const float Transform::dragBase = 4;
float Transform::drag = 0;
const float Transform::sleepBase = 5;
float Transform::sleep = 0;

const float Transform::IDENTITY[MATRIXSIZE] = {
	1,	0,	0,	0,
	0,	1,	0,	0,
	0,	0,	1,	0,
	0,	0,	0,	1
};
const float Transform::RADIAN = 57.2957795;


Transform::Transform()
{
	if(CameraTran == nullptr) CameraTran = this;
	SetWorldPosition(Vec2());
	isForeground = false;
	allTransforms.push_back(this);
	velocity = Vec2();
	for(int i = 0; i < MATRIXSIZE; i++) spriteMatrix[i] = IDENTITY[i];
}

void Transform::UpdateAllTransforms()
{
	for(auto i = allTransforms.begin(); i != allTransforms.end(); i++)
	{
		(*i)->m_update();
	}
}

void Transform::SetWorldPosition(Vec2& a_position)
{
	worldPosition = a_position;
	m_LoopWorld(worldPosition);
}

void Transform::SetVelocity(Vec2 a_velocity)
{
	velocity = a_velocity;
}

void Transform::Move(Vec2 a_moveAmmount)
{
	velocity += a_moveAmmount * gameTime->deltaTime;
}

void Transform::MoveLocal(Vec2 a_moveAmmount)
{
	//moves tranflorm along the local axis a specified ammount
	Vec2 m_desrired;
	//skip if zero submitted
	if(a_moveAmmount != Vec2::ZERO)
	{

		//make movement amount frame consistent
		a_moveAmmount = a_moveAmmount*gameTime->deltaTime;

		//wake (if velocity is currently zero, make sure the initial move is more than the sleep tollerance)
		if(velocity == Vec2::ZERO)
		{
			if( fabsf(a_moveAmmount.x) <= sleep && fabsf(a_moveAmmount.x) <= sleep)
			{
				float m_multiplyer;
				m_multiplyer = a_moveAmmount.x > a_moveAmmount.y ? sleep / a_moveAmmount.x : sleep / a_moveAmmount.y;
				m_multiplyer *= 4;

				a_moveAmmount.x *= m_multiplyer; a_moveAmmount.y *= m_multiplyer;
			}
		}

		//tralslate move around local axis

		m_desrired.x = (-((-a_moveAmmount.x) * spriteMatrix[0]) + (a_moveAmmount.y * spriteMatrix[4]));
		m_desrired.y = -(((-a_moveAmmount.x) * spriteMatrix[1]) - (a_moveAmmount.y *(spriteMatrix[5])));
	}

	//translate move into velocity
	velocity += m_desrired;// * gameTime->deltaTime;
}

void Transform::m_update()
{
	sleep = sleepBase * gameTime->deltaTime;
	drag = dragBase * gameTime->deltaTime;

	//update velocity
	if(velocity.x != 0)
		velocity.x > 0 ? velocity.x -= velocity.x * drag : velocity.x += fabsf(velocity.x) * drag;
	if(velocity.y != 0)
		velocity.y > 0 ? velocity.y -= velocity.y * drag : velocity.y += fabsf(velocity.y) * drag;

	if(fabsf(velocity.y) < sleep && fabsf(velocity.x) < sleep) {velocity.y = 0; velocity.x = 0;}//sleep

	//update world position
	worldPosition += velocity;
	m_LoopWorld(worldPosition);

	//update relative position
	reletivePosition = worldPosition - CameraTran->worldPosition;
	m_LoopWorld(reletivePosition);
	spriteMatrix[12] = reletivePosition.x; spriteMatrix[13] = reletivePosition.y;

	//check if in foreground
	isForeground = m_IsInRange(reletivePosition, ForegroundStart, ForegroundEnd);

	//update screen position if so
	if(isForeground)
		foregroundPosition = (reletivePosition - ForegroundStart) * ScaleMultiplyer;
	else
		foregroundPosition = *worldSize;
}

bool Transform::m_IsInRange(Vec2& a_point, Vec2& a_rangeStart, Vec2& a_rangeEnd)
{
	//check 'x'
	if(a_rangeStart < a_rangeEnd) //range isn't broken
		return  a_point >= a_rangeStart && a_point <= a_rangeEnd;
	else //range is broken
		return  a_point >= a_rangeStart || a_point <= a_rangeEnd;
}

void Transform::m_LoopWorld(Vec2& a_position)
{
	//loop negative
	while(a_position.x < 0) a_position.x = worldSize->x + a_position.x;
	while(a_position.y < 0) a_position.y = worldSize->y + a_position.y;
	//loop positive
	a_position.x = fmodf(a_position.x, worldSize->x);
	a_position.y = fmodf(a_position.y, worldSize->y);
}

void Transform::SetAsCamera()
{
	CameraTran = this;
}

void Transform::SetScaleMultiplyer(float a_desiredScale)
{
	ScaleMultiplyer = a_desiredScale;
	ForegroundSize = *worldSize / ScaleMultiplyer;
}

