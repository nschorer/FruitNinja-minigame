#include "WoodPlatShort.h"
#include "ContactAction.h"

#include "Blast.h"
#include "WoodMaterial.h"

PhysicsFixture WoodPlatShort::fixture(Shape::Rectangle, *WoodMaterial::Instance());
float WoodPlatShort::width = 82.0f;
float WoodPlatShort::height = 21.0f;
ImageName::Name WoodPlatShort::imgNames[] = { ImageName::Name::Wood_Plat_Short_0, ImageName::Name::Wood_Plat_Short_1, ImageName::Name::Wood_Plat_Short_2, ImageName::Name::Wood_Plat_Short_3 };

WoodPlatShort::WoodPlatShort(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Wood_Plat_Short, x, y, WoodPlatShort::width, WoodPlatShort::height, &fixture, imgNames, WoodMaterial::Instance(), pWorld)
{

}