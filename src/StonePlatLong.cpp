#include "StonePlatLong.h"
#include "StoneMaterial.h"

PhysicsFixture StonePlatLong::fixture(Shape::Rectangle, *StoneMaterial::Instance());
float StonePlatLong::width = 205.0f;
float StonePlatLong::height = 21.0f;
ImageName::Name StonePlatLong::imgNames[] = { ImageName::Name::Stone_Plat_Long_0, ImageName::Name::Stone_Plat_Long_1, ImageName::Name::Stone_Plat_Long_2, ImageName::Name::Stone_Plat_Long_3 };


StonePlatLong::StonePlatLong(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Stone_Plat_Long, x, y, width, height, &fixture, imgNames, StoneMaterial::Instance(), pWorld)
{

}
