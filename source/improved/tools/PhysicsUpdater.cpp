

#include "tools\PhysicsUpdater.h"

std::list<PhysicsUpdater*> PhysicsUpdater::allPhysics = std::list<PhysicsUpdater*>();

PhysicsUpdater::PhysicsUpdater()
{
	allPhysics.push_back(this);
}

void PhysicsUpdater::UpdateAllPhysics()
{
	for(auto i = allPhysics.begin(); i != allPhysics.end(); i++)
		(*i)->m_PhysicsUpdate();
}

PhysicsUpdater::~PhysicsUpdater()
{
	allPhysics.remove(this);
}