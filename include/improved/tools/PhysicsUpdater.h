//////////////////////
// Physics updater
// used for collecting physic elements and calling updates
// 
/////////////////////

#pragma once
#include "Tools.h"

class PhysicsUpdater
{
	//all physics
	static std::list<PhysicsUpdater*>allPhysics;

protected:
	//constructor
	PhysicsUpdater();

	//pure virtual, called each frame
	virtual void m_PhysicsUpdate() = 0;

	//distructor
	virtual ~PhysicsUpdater();

public:
	//calls update function on all physic objects
	static void UpdateAllPhysics();
};