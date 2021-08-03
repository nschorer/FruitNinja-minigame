#include "WoodPlatTiny.h"
#include "ContactAction.h"

#include "WoodMaterial.h"

PhysicsFixture WoodPlatTiny::fixture(Shape::Rectangle, *WoodMaterial::Instance());
float WoodPlatTiny::width = 41.0f;
float WoodPlatTiny::height = 21.0f;
ImageName::Name WoodPlatTiny::imgNames[] = { ImageName::Name::Wood_Plat_Tiny_0, ImageName::Name::Wood_Plat_Tiny_1, ImageName::Name::Wood_Plat_Tiny_2, ImageName::Name::Wood_Plat_Tiny_3 };

WoodPlatTiny::WoodPlatTiny(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Wood_Plat_Tiny, x, y, width, height, &fixture, imgNames, WoodMaterial::Instance(), pWorld)
{

}


