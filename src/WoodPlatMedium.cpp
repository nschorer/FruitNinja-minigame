#include "WoodPlatMedium.h"
#include "ContactAction.h"
#include "WoodMaterial.h"

PhysicsFixture WoodPlatMedium::fixture(Shape::Rectangle, *WoodMaterial::Instance());
float WoodPlatMedium::width = 168.0f;
float WoodPlatMedium::height = 21.0f;
ImageName::Name WoodPlatMedium::imgNames[] = { ImageName::Name::Wood_Plat_Medium_0, ImageName::Name::Wood_Plat_Medium_1, ImageName::Name::Wood_Plat_Medium_2, ImageName::Name::Wood_Plat_Medium_3 };

WoodPlatMedium::WoodPlatMedium(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Wood_Plat_Medium, x, y, WoodPlatMedium::width, WoodPlatMedium::height, &fixture, imgNames, WoodMaterial::Instance(), pWorld)
{

}
