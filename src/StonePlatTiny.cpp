#include "StonePlatTiny.h"
#include "StoneMaterial.h"

PhysicsFixture StonePlatTiny::fixture(Shape::Rectangle, *StoneMaterial::Instance());
float StonePlatTiny::width = 41.0f;
float StonePlatTiny::height = 21.0f;
ImageName::Name StonePlatTiny::imgNames[] = { ImageName::Name::Stone_Plat_Tiny_0, ImageName::Name::Stone_Plat_Tiny_1, ImageName::Name::Stone_Plat_Tiny_2, ImageName::Name::Stone_Plat_Tiny_3 };

StonePlatTiny::StonePlatTiny(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Stone_Plat_Tiny, x, y, width, height, &fixture, imgNames, StoneMaterial::Instance(), pWorld)
{

}