#ifndef GLASS_PLAT_TINY_H
#define GLASS_PLAT_TINY_H


#include "Block_Base.h"

class GlassPlatTiny : public Block_Base
{
public:

	GlassPlatTiny(float x, float y, PhysicsWorld* pWorld);
	virtual ~GlassPlatTiny() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif