#include "MediumPig.h"

PhysicsFixture MediumPig::fixture(Shape::Rectangle, 10.0f, 0.3f, 0.5f);
float MediumPig::width = 78.0f;
float MediumPig::height = 77.0f;
ImageName::Name MediumPig::imgNames[] = { ImageName::Name::Pig_Medium_0, ImageName::Name::Pig_Medium_1 };
float MediumPig::maxHealth = 50.0f;

MediumPig::MediumPig(float x, float y, PhysicsWorld* pWorld)
	:Pig_Base(GameObjectName::Name::Pig_Medium, x, y, width, height, &fixture, maxHealth, imgNames, pWorld)
{
}

