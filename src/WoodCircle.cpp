#include "WoodCircle.h"
#include "ContactAction.h"

#include "WoodMaterial.h"

PhysicsFixture WoodCircle::fixture(Shape::Circle, *WoodMaterial::Instance());
float WoodCircle::width = 77.0f;
float WoodCircle::height = 77.0f;
ImageName::Name WoodCircle::imgNames[] = { ImageName::Name::Wood_Circle_Big_0, ImageName::Name::Wood_Circle_Big_0, ImageName::Name::Wood_Circle_Big_0, ImageName::Name::Wood_Circle_Big_0 };

WoodCircle::WoodCircle(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Wood_Circle, x, y, WoodCircle::width, WoodCircle::height, &fixture, imgNames, WoodMaterial::Instance(), pWorld)
{
}
