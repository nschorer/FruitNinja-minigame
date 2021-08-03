#ifndef FLOOR_H
#define FLOOR_H

#include "PhysicsObject2D.h"

class Floor : public PhysicsObject2D
{
public:
	Floor(float x, float y, float width, float height, PhysicsWorld* pWorld);

private:
	static PhysicsFixture fixture;
};

#endif