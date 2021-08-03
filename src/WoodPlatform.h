#ifndef WOOD_PLATFORM_H
#define WOOD_PLATFORM_H
		

#include "PhysicsObject2D.h"

class WoodPlatform : public PhysicsObject2D
{
public:

	WoodPlatform(float x, float y, PhysicsWorld* pWorld);

private:
	static PhysicsFixture fixture;
	static ImageName::Name image;
	static float width;
	static float height;

};

#endif