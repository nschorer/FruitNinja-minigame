#ifndef TOWER_1_9_H
#define TOWER_1_9_H

#include "PhysicsObject2D.h"

class PhysicsWorld;

class Tower_1_9
{
public:
	Tower_1_9(float x, float y, PhysicsWorld* pWorld);
	virtual ~Tower_1_9() = default;

	void Demolish();

private:
	PhysicsObject2D* pObjects[34];
};

#endif