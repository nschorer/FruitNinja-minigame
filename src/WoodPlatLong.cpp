#include "WoodPlatLong.h"
#include "ContactAction.h"
#include "WoodMaterial.h"


PhysicsFixture WoodPlatLong::fixture(Shape::Rectangle, *WoodMaterial::Instance());
float WoodPlatLong::width = 205;
float WoodPlatLong::height = 21.0f;
ImageName::Name WoodPlatLong::imgNames[] = { ImageName::Name::Wood_Plat_Long_0, ImageName::Name::Wood_Plat_Long_1, ImageName::Name::Wood_Plat_Long_2, ImageName::Name::Wood_Plat_Long_3 };

WoodPlatLong::WoodPlatLong(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Wood_Plat_Long, x, y, WoodPlatLong::width, WoodPlatLong::height, &fixture, imgNames, WoodMaterial::Instance(), pWorld)
{

}
