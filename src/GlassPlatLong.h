#ifndef GLASS_PLAT_LONG_H
#define GLASS_PLAT_LONG_H


#include "Block_Base.h"

class GlassPlatLong : public Block_Base
{
public:

	GlassPlatLong(float x, float y, PhysicsWorld* pWorld);
	virtual ~GlassPlatLong() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif