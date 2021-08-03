#include "StonePlatMedium.h"
#include "StoneMaterial.h"

PhysicsFixture StonePlatMedium::fixture(Shape::Rectangle, *StoneMaterial::Instance());
float StonePlatMedium::width = 168.0f;
float StonePlatMedium::height = 21.0f;
ImageName::Name StonePlatMedium::imgNames[] = { ImageName::Name::Stone_Plat_Medium_0, ImageName::Name::Stone_Plat_Medium_1, ImageName::Name::Stone_Plat_Medium_2, ImageName::Name::Stone_Plat_Medium_3 };


StonePlatMedium::StonePlatMedium(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Stone_Plat_Medium, x, y, width, height, &fixture, imgNames, StoneMaterial::Instance(), pWorld)
{

}