#ifndef STONE_PLAT_LONG_H
#define STONE_PLAT_LONG_H


#include "Block_Base.h"

class StonePlatLong : public Block_Base
{
public:

	StonePlatLong(float x, float y, PhysicsWorld* pWorld);
	virtual ~StonePlatLong() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif