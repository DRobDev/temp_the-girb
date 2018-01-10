#include "tools\collider.h"

//TEMP:
#include "AIE.h"

std::vector<Collider*> Collider::allColliders = std::vector<Collider*>();

Collider::Collider(Collider::ColliderTypes a_colType)
{
	//add collider to all colliders vector and set type
	allColliders.push_back(this);
	colType = a_colType;
}

void Collider::UpdateAllColliders()
{
	//check if colliders have hit, if so call 'hit' function
	float m_combinedExtents;
	float m_distanceBetweenColliders;

	for( auto i = allColliders.begin(); i != allColliders.end(); i++)
	{
		for(auto r = i; r < allColliders.end(); r++)
		{
			//skip check on self
			if(i == r) continue;

			m_combinedExtents = (*r)->GetExtent(*i) + (*i)->GetExtent(*r);
			m_distanceBetweenColliders = Vec2::Distance((*i)->colliderWorldPos, (*r)->colliderWorldPos);

			if(m_combinedExtents > m_distanceBetweenColliders)
			{
				(*i)->Hit((*r));
				(*r)->Hit((*i));
			}
		}
	}
}






BallCollider::BallCollider(ColliderTypes a_colType)
	: Collider(a_colType)
{
	colliderWorldPos = Vec2();
	colRad = 0;
}

//void BallCollider::m_UpdateCollider()
//{
//}

float BallCollider::GetExtent(Collider* BallCollider)
{
	return colRad;
}

void BallCollider::SetColliderPosition(Vec2 a_pos)
{
	colliderWorldPos = a_pos;
}

void BallCollider::SetCollisionRadius(float a_rad)
{
	colRad = a_rad;
}




