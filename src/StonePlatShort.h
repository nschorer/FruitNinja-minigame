#ifndef STONE_PLAT_SHORT_H
#define STONE_PLAT_SHORT_H


#include "Block_Base.h"

class StonePlatShort : public Block_Base
{
public:

	StonePlatShort(float x, float y, PhysicsWorld* pWorld);
	virtual ~StonePlatShort() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif