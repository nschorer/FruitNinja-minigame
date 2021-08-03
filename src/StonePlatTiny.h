#ifndef STONE_PLAT_TINY_H
#define STONE_PLAT_TINY_H


#include "Block_Base.h"

class StonePlatTiny : public Block_Base
{
public:

	StonePlatTiny(float x, float y, PhysicsWorld* pWorld);
	virtual ~StonePlatTiny() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif