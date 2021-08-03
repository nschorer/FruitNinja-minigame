#ifndef GLASS_PLAT_SHORT_H
#define GLASS_PLAT_SHORT_H


#include "Block_Base.h"

class GlassPlatShort : public Block_Base
{
public:

	GlassPlatShort(float x, float y, PhysicsWorld* pWorld);
	virtual ~GlassPlatShort() = default;


private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif