#include "GlassPlatShort.h"
#include "ContactAction.h"

#include "GlassMaterial.h"

PhysicsFixture GlassPlatShort::fixture(Shape::Rectangle, *GlassMaterial::Instance());
float GlassPlatShort::width = 82.0f;
float GlassPlatShort::height = 21.0f;
ImageName::Name GlassPlatShort::imgNames[] = { ImageName::Name::Glass_Plat_Short_0, ImageName::Name::Glass_Plat_Short_1, ImageName::Name::Glass_Plat_Short_2, ImageName::Name::Glass_Plat_Short_3 };

GlassPlatShort::GlassPlatShort(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Glass_Plat_Short, x, y, width, height, &fixture, imgNames, GlassMaterial::Instance(), pWorld)
{

}
