#include "StonePlatShort.h"
#include "StoneMaterial.h"

PhysicsFixture StonePlatShort::fixture(Shape::Rectangle, *StoneMaterial::Instance());
float StonePlatShort::width = 82.0f;
float StonePlatShort::height = 21.0f;
ImageName::Name StonePlatShort::imgNames[] = { ImageName::Name::Stone_Plat_Short_0, ImageName::Name::Stone_Plat_Short_1, ImageName::Name::Stone_Plat_Short_2, ImageName::Name::Stone_Plat_Short_3 };

StonePlatShort::StonePlatShort(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Stone_Plat_Short, x, y, width, height, &fixture, imgNames, StoneMaterial::Instance(), pWorld)
{

}