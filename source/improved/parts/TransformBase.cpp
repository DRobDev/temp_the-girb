
#include "parts\TransformBase.h"

const float TransformBase::RADIAN = 57.2957795;
const float TransformBase::LOOKATMIN = 10;

TransformBase::TransformBase()
{
	//initialize tranform matrix to 'identity' matrix 
	for(int i = 0; i < MATRIXSIZE; i++)
		if(i % 5 == 0) transformMatrix[i] = 1; else transformMatrix[i] = 0;
}

void TransformBase::SetWorldPosition(Vec2& a_pos)
{
	//keep in game world
	LoopWorldPosition(a_pos);
	//update transform matrix
	transformMatrix[MAT_POSX] = a_pos.x;
	transformMatrix[MAT_POSY] = a_pos.y;
}

void TransformBase::Move(Vec2 a_movVec)
{
	//regulate velocity with delta
	a_movVec *= Time::GetDelta();

	//get desired updated world position
	a_movVec.x += transformMatrix[MAT_POSX];
	a_movVec.y += transformMatrix[MAT_POSY];

	//set desired position as worl position
	SetWorldPosition(a_movVec);
}

void TransformBase::SetRotation(float a_degrees)
{
	//translate into radians
	float m_angle = a_degrees / RADIAN;
	//translate into matrix
	transformMatrix[0] = cosf(m_angle);		transformMatrix[1] = sinf(m_angle);
	transformMatrix[4] = -sinf(m_angle);	transformMatrix[5] = cosf(m_angle); 
}

void TransformBase::LookAt(Vec2 a_worldPos)
{
	//look down shortest path towards target
	//taking world wrapping into account

	Vec2 m_wrappedPos = a_worldPos;
	Vec2 m_HalfWorldSize = GetWorldSize() / 2;
	Vec2 m_thisPosition = GetWorldPosition();

	//if more than half the screen away offset wrappedPos
	if(a_worldPos.x > m_thisPosition.x) //target on right
	{
		if(a_worldPos.x - m_thisPosition.x > m_HalfWorldSize.x) //target more than half world away
			m_wrappedPos.x -= GetWorldSize().x; //push back to other side
	}
	else //target on left
	{
		if(m_thisPosition.x - a_worldPos.x > m_HalfWorldSize.x) //more than half world away
			m_wrappedPos.x += GetWorldPosition().x;//push to other side
	}
	if(a_worldPos.y > m_thisPosition.y) //target above
	{
		if(a_worldPos.y - m_thisPosition.y > m_HalfWorldSize.y) //target more than half world away
			m_wrappedPos.y -= GetWorldSize().y; //push back to other side
	}
	else //target below
	{
		if(m_thisPosition.y - a_worldPos.y > m_HalfWorldSize.y) //more than half world away
			m_wrappedPos.y += GetWorldPosition().y;//push to other side
	}

	//look at wrapped position
	//calculate angle(rad)
	m_wrappedPos =   m_wrappedPos - m_thisPosition;
	
	//ignore if look at target is ontop of this
	if(m_wrappedPos.GetMagnitude() < LOOKATMIN) return;

	float m_angle = atan2f(m_wrappedPos.x, m_wrappedPos.y);

	//update rotation matrix
	transformMatrix[0] = cosf(m_angle);		transformMatrix[1] = -sinf(m_angle);
	transformMatrix[4] = sinf(m_angle);		transformMatrix[5] = cosf(m_angle);
}

float* TransformBase::GetTransformMatrix()
{
	return transformMatrix;
}

Vec2 TransformBase::GetWorldPosition()
{
	return Vec2(transformMatrix[MAT_POSX],transformMatrix[MAT_POSY]);
}