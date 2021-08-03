#ifndef WOOD_PLAT_SHORT_H
#define WOOD_PLAT_SHORT_H

#include "Block_Base.h"

class WoodPlatShort : public Block_Base
{
public:

	WoodPlatShort(float x, float y, PhysicsWorld* pWorld);
	virtual ~WoodPlatShort() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif