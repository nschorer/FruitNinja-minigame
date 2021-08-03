#ifndef GLASS_PLAT_MEDIUM_H
#define GLASS_PLAT_MEDIUM_H


#include "Block_Base.h"

class GlassPlatMedium : public Block_Base
{
public:

	GlassPlatMedium(float x, float y, PhysicsWorld* pWorld);
	virtual ~GlassPlatMedium() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif