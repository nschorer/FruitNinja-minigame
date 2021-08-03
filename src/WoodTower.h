#ifndef WOOD_TOWER_H
#define WOOD_TOWER_H

#include "PhysicsObject2D.h"
#include <vector>

class WoodTower
{
public:
	WoodTower(float x, float y, int numLevels);
	virtual ~WoodTower();

	void Demolish();

private:
	PhysicsObject2D** pObjects;
	int numObjects;
};

#endif