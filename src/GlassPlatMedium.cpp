#include "GlassPlatMedium.h"
#include "GlassMaterial.h"

PhysicsFixture GlassPlatMedium::fixture(Shape::Rectangle, *GlassMaterial::Instance());
float GlassPlatMedium::width = 168.0f;
float GlassPlatMedium::height = 21.0f;
ImageName::Name GlassPlatMedium::imgNames[] = { ImageName::Name::Glass_Plat_Medium_0, ImageName::Name::Glass_Plat_Medium_1, ImageName::Name::Glass_Plat_Medium_2, ImageName::Name::Glass_Plat_Medium_3 };

GlassPlatMedium::GlassPlatMedium(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Glass_Plat_Medium, x, y, width, height, &fixture, imgNames, GlassMaterial::Instance(), pWorld)
{

}
