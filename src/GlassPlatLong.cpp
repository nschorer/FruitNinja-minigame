#include "GlassPlatLong.h"
#include "GlassMaterial.h"

PhysicsFixture GlassPlatLong::fixture(Shape::Rectangle, *GlassMaterial::Instance());
float GlassPlatLong::width = 205;
float GlassPlatLong::height = 21.0f;
ImageName::Name GlassPlatLong::imgNames[] = { ImageName::Name::Glass_Plat_Long_0, ImageName::Name::Glass_Plat_Long_1, ImageName::Name::Glass_Plat_Long_2, ImageName::Name::Glass_Plat_Long_3 };

GlassPlatLong::GlassPlatLong(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Glass_Plat_Long, x, y, width, height, &fixture, imgNames, GlassMaterial::Instance(), pWorld)
{

}
