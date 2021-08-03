#ifndef WOOD_PLAT_TINY_H
#define WOOD_PLAT_TINY_H


#include "Block_Base.h"

class WoodPlatTiny : public Block_Base
{
public:

	WoodPlatTiny(float x, float y, PhysicsWorld* pWorld);
	virtual ~WoodPlatTiny() = default;


private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif