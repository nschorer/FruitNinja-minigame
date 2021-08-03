#include "WoodSquare.h"
#include "ContactAction.h"

#include "WoodMaterial.h"

PhysicsFixture WoodSquare::fixture(Shape::Rectangle, *WoodMaterial::Instance());
float WoodSquare::width = 44.0f;
float WoodSquare::height = 44.0f;
ImageName::Name WoodSquare::imgNames[] = { ImageName::Name::Wood_Square_0, ImageName::Name::Wood_Square_1, ImageName::Name::Wood_Square_2, ImageName::Name::Wood_Square_3 };

WoodSquare::WoodSquare(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Wood_Square, x, y, width, height, &fixture, imgNames, WoodMaterial::Instance(), pWorld)
{

}