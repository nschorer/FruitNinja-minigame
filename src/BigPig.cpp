#include "BigPig.h"

PhysicsFixture BigPig::fixture(Shape::Rectangle, 10.0f, 0.3f, 0.5f);
float BigPig::width = 98.0f;
float BigPig::height = 97.0f;
ImageName::Name BigPig::imgNames[] = { ImageName::Name::Pig_Big_0, ImageName::Name::Pig_Big_1 };
float BigPig::maxHealth = 100.0f;

BigPig::BigPig(float x, float y, PhysicsWorld* pWorld)
	:Pig_Base(GameObjectName::Name::Pig_Big, x, y, width, height, &fixture, maxHealth, imgNames, pWorld)
{

}