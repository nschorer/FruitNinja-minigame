#ifndef NINJA_FRUIT_PIG_H
#define NINJA_FRUIT_PIG_H

#include "NinjaFruit.h"

class PhysicsWorld;

class NinjaFruit_Pig : public NinjaFruit
{
public:
	NinjaFruit_Pig(float x, float y, PhysicsWorld* pWorld);
	virtual ~NinjaFruit_Pig() = default;

private:
	static ImageName::Name imgNames[3];
	static float radius;
};

#endif