#ifndef STONE_PLAT_MEDIUM_H
#define STONE_PLAT_MEDIUM_H


#include "Block_Base.h"

class StonePlatMedium : public Block_Base
{
public:

	StonePlatMedium(float x, float y, PhysicsWorld* pWorld);
	virtual ~StonePlatMedium() = default;


private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif