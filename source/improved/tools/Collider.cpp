#include "tools\Collider.h"
#include "tools\Map.h"

std::list<Collider*> Collider::allColliders = std::list<Collider*>();

void Collider::UpdateAllColliders()
{
	Vec2 m_worldSize = Map::GetWorldSize();

	//check for collision between all colliders
	for(auto i = allColliders.begin(); i != allColliders.end(); i++)
	{
		//check if i is overlapping world //
		Vec2 m_iPos = (*i)->GetWorldPosition();
		Vec2 m_iOffsetPos = m_iPos; //used to check overlap

		//check potential overlap
		if(m_iPos.x + (*i)->colRadius > m_worldSize.x)
			m_iOffsetPos.x -= m_worldSize.x;
		if(m_iPos.x - (*i)->colRadius < 0)
			m_iOffsetPos.x += m_worldSize.x;
		if(m_iPos.y + (*i)->colRadius > m_worldSize.y)
			m_iOffsetPos.y -= m_worldSize.y;
		if(m_iPos.y - (*i)->colRadius < 0)
			m_iOffsetPos.y += m_worldSize.y;
		//--------------------------------//


		for(auto a = i; a != allColliders.end(); a++)
		{
			if(i == a) continue; //dont check collision on self

			Vec2 m_aPos = (*a)->GetWorldPosition();

			//call hit functions if colliders hit
			if(Vec2::Distance(m_iPos, m_aPos) < (*i)->colRadius + (*a)->colRadius)
			{
				(*i)->m_Hit(*a);
				(*a)->m_Hit(*i);
				continue;
			}

			//check if a is overlapping world //
			Vec2 m_aOffsetPos = m_aPos; //used to check overlap

			//check potential overlap
			if(m_aPos.x + (*a)->colRadius > m_worldSize.x)
				m_aOffsetPos.x -= m_worldSize.x;
			if(m_aPos.x - (*a)->colRadius < 0)
				m_aOffsetPos.x += m_worldSize.x;
			if(m_aPos.y + (*a)->colRadius > m_worldSize.y)
				m_aOffsetPos.y -= m_worldSize.y;
			if(m_aPos.y - (*a)->colRadius < 0)
				m_aOffsetPos.y += m_worldSize.y;
			//--------------------------------//

			//end if no overlap
			if(m_aOffsetPos == m_aPos && m_iOffsetPos == m_iPos)
				continue;

			//check offest collision
			if(m_iOffsetPos != m_iPos)
			{
				if(Vec2::Distance(m_iOffsetPos, m_iPos) < (*i)->colRadius + (*a)->colRadius)
				{
					(*i)->m_Hit(*a);
					(*a)->m_Hit(*i);
					continue;
				}
			}
			if(m_aOffsetPos != m_aPos)
			{
				if(Vec2::Distance(m_aOffsetPos, m_iPos) < (*i)->colRadius + (*a)->colRadius)
				{
					(*i)->m_Hit(*a);
					(*a)->m_Hit(*i);
					continue;
				}
			}
		}
	}

}


Collider::Collider(ColliderType a_type, float a_colRad)
{
	colRadius = a_colRad;
	colliderType = a_type;
	allColliders.push_back(this);
}

//void Collider::SetCollisionRadius(float a_radValue)
//{
//	colRadius = a_radValue;
//}

Collider::~Collider()
{
	allColliders.remove(this);
}