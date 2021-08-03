#ifndef TOWER_1_1_H
#define TOWER_1_1_H

#include "PhysicsObject2D.h"

class PhysicsWorld;

class Tower_1_1
{
public:
	Tower_1_1(float x, float y, PhysicsWorld* pWorld);
	virtual ~Tower_1_1() = default;

	void Demolish();

private:
	PhysicsObject2D* pObjects[17];
};

#endif