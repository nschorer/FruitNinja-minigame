#ifndef WOOD_PLAT_MEDIUM_H
#define WOOD_PLAT_MEDIUM_H


#include "Block_Base.h"

class WoodPlatMedium : public Block_Base
{
public:

	WoodPlatMedium(float x, float y, PhysicsWorld* pWorld);
	virtual ~WoodPlatMedium() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif