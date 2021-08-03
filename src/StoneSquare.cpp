#include "StoneSquare.h"
#include "StoneMaterial.h"

PhysicsFixture StoneSquare::fixture(Shape::Rectangle, *StoneMaterial::Instance());
float StoneSquare::width = 44.0f;
float StoneSquare::height = 44.0f;
ImageName::Name StoneSquare::imgNames[] = { ImageName::Name::Stone_Square_0, ImageName::Name::Stone_Square_1, ImageName::Name::Stone_Square_2, ImageName::Name::Stone_Square_3 };

StoneSquare::StoneSquare(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Stone_Square, x, y, width, height, &fixture, imgNames, StoneMaterial::Instance(), pWorld)
{

}
