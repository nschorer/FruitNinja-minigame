#include "GlassPlatTiny.h"
#include "GlassMaterial.h"

PhysicsFixture GlassPlatTiny::fixture(Shape::Rectangle, *GlassMaterial::Instance());
float GlassPlatTiny::width = 41.0f;
float GlassPlatTiny::height = 21.0f;
ImageName::Name GlassPlatTiny::imgNames[] = { ImageName::Name::Glass_Plat_Tiny_0, ImageName::Name::Glass_Plat_Tiny_1, ImageName::Name::Glass_Plat_Tiny_2, ImageName::Name::Glass_Plat_Tiny_3 };

GlassPlatTiny::GlassPlatTiny(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Glass_Plat_Medium, x, y, width, height, &fixture, imgNames, GlassMaterial::Instance(), pWorld)
{

}
