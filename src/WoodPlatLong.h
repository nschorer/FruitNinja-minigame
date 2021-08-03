#ifndef WOOD_PLAT_LONG_H
#define WOOD_PLAT_LONG_H


#include "Block_Base.h"

class WoodPlatLong : public Block_Base
{
public:

	WoodPlatLong(float x, float y, PhysicsWorld* pWorld);
	virtual ~WoodPlatLong() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif