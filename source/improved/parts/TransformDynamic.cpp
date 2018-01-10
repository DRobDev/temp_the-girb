#include "parts\TransformDynamic.h"

const float TransformDynamic::sleep = 16;

TransformDynamic::TransformDynamic(float a_mass, float a_drag)
{
	//assign physical values
	mass = a_mass; drag = a_drag;
	velocity = Vec2::ZERO;
	velocityDirection = Vec2::ZERO;
	velocityMagnitude = 0;
}

void TransformDynamic::Move(Vec2 a_movVec)
{
	velocity = a_movVec;
}

void TransformDynamic::AddForceLocal(Vec2 a_force)
{
	//adds force tranflorm along the local axis a specified ammount//

	//make movement amount frame and mass consistent
	a_force = (a_force / mass) * Time::GetDelta();
	Vec2 m_desired;

	//tralslate move around local axis
	m_desired.x = (-((-a_force.x) * transformMatrix[0]) + (a_force.y * transformMatrix[4]));
	m_desired.y = -(((-a_force.x) * transformMatrix[1]) - (a_force.y *transformMatrix[5]));

	//wake (if velocity is currently zero, making sure the initial move is more than the sleep tollerance)
	if(velocity == Vec2::ZERO)
	{
		if( sqrtf(powf(m_desired.x, 2) + powf(m_desired.y, 2)) <= (sleep * Time::GetDelta()))
			m_desired = m_desired * ((sleep * Time::GetDelta()) / sqrtf(powf(m_desired.x, 2) + powf(m_desired.y, 2))); 
		m_desired = m_desired * 3.141592;
	}

	////translate move into velocity
	//if(fabsf(velocityDirection.x + m_desired.x) > fabsf(velocityDirection.x))
	//	m_addDrag(true,false,true); //cancel drag
	//if(fabsf(velocityDirection.y + m_desired.y) > fabsf(velocityDirection.y))
	//	m_addDrag(false,true,true); //cancel drag

	if(fabsf(velocityDirection.x + m_desired.x) > fabsf(velocityDirection.x)
	|| fabsf(velocityDirection.y + m_desired.y) > fabsf(velocityDirection.y))
		m_addDrag(true, true, true); //cancel drag

	velocity += m_desired;
}

void TransformDynamic::Update()
{
	//dont update velocity if none
	if(velocity == Vec2::ZERO)
		return;

	//update velocity direction
	m_getVelocityDirection();

	//add drag slowing down velocity
	m_addDrag();

	//add velocity based momentum
	TransformBase::Move(velocity);
}

TransformDynamic::~TransformDynamic()
{
}

void TransformDynamic::m_getVelocityDirection()
{
	//get magnitude of vector
	velocityMagnitude = sqrtf(powf(velocity.x,2) + powf(velocity.y,2));

	//get normalized direction
	velocityDirection.x = velocity.x * velocityMagnitude;
	velocityDirection.y = velocity.y * velocityMagnitude;
}

void TransformDynamic::m_addDrag(bool a_addToX, bool a_addToY, bool a_removeInstead)
{
	//dont apply dray if stationary
	if(velocity == Vec2::ZERO || !a_addToX && !a_addToY) return;

	//sleep if slow enough 
	if(velocityMagnitude < sleep * Time::GetDelta()) { velocity = Vec2::ZERO; return; }

	//add drag to both axis
	if(a_addToX && a_addToY)
	{
		//apply drag reducing velocity
		if(!a_removeInstead)
			velocity = velocity - ((velocityDirection * (drag / mass)) * Time::GetDelta());

		//apply negative drag increasing velocity (used to cancel effects of drag)
		else
			velocity = velocity + ((velocityDirection * (drag / mass)) * Time::GetDelta());
	}
	else if(a_addToX)
	{
		//apply drag reducing velocity
		if(!a_removeInstead)
			velocity.x = velocity.x - ((velocityDirection.x * (drag / mass)) * Time::GetDelta());

		//apply negative drag increasing velocity (used to cancel effects of drag)
		else
			velocity.x = velocity.x + ((velocityDirection.x * (drag / mass)) * Time::GetDelta());
	}
	else //add to y
	{
		//apply drag reducing velocity
		if(!a_removeInstead)
			velocity.y = velocity.y - ((velocityDirection.y * (drag / mass)) * Time::GetDelta());

		//apply negative drag increasing velocity (used to cancel effects of drag)
		else
			velocity.y = velocity.y + ((velocityDirection.y * (drag / mass)) * Time::GetDelta());
	}

}

/*
void TransformDynamic::m_getVelocityDirection()
{
//get velocity direction
if(fabsf(velocity.x) < fabsf(velocity.y))
{
velocityDirection.x = velocity.x / velocity.y;
velocityDirection.y = 1 - velocityDirection.x;
}
else
{
velocityDirection.y = velocity.y / velocity.x;
velocityDirection.x = 1 - velocityDirection.y;
}
}

void TransformDynamic::m_addDrag(bool a_removeInstead)
{
//dont apply dray if stationary
if(velocity == Vec2::ZERO)
return;

//sleep if slow enough 
if(fabsf(velocity.x) < (sleep * velocityDirection.x) * Time::GetDelta()
&& fabsf(velocity.y) < (sleep * velocityDirection.y) * Time::GetDelta()) 
{
velocity = Vec2::ZERO;
return;
}

//apply drag reducing velocity
if(!a_removeInstead)
{
//reduce velocity x by adjusted drag
if(velocity.x != 0)
{
if(velocity.x > 0)	velocity.x -= ((drag / mass) * velocityDirection.x) * Time::GetDelta();
else				velocity.x += ((drag / mass) * velocityDirection.x) * Time::GetDelta();
}
//reduce velocity y by adjusted 
if(velocity.y != 0)
{
if(velocity.y > 0)	velocity.y -= ((drag / mass) * velocityDirection.y) * Time::GetDelta();
else				velocity.y += ((drag / mass) * velocityDirection.y) * Time::GetDelta();
}
}
//apply negative drag increasing velocity (used to cancel effects of drag)
else
{
//increase velocity x by adjusted drag
if(velocity.x != 0)
{
if(velocity.x > 0)	velocity.x += ((drag / mass) * velocityDirection.x) * Time::GetDelta();
else				velocity.x -= ((drag / mass) * velocityDirection.x) * Time::GetDelta();
}
//increase velocity y by adjusted 
if(velocity.y != 0)
{
if(velocity.y > 0)	velocity.y += ((drag / mass) * velocityDirection.y) * Time::GetDelta();
else				velocity.y -= ((drag / mass) * velocityDirection.y) * Time::GetDelta();
}
}
}*/