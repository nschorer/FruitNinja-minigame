#ifndef PHYSICS_FIXTURE_H
#define PHYSICS_FIXTURE_H

//#include "Box2D.h"
#include "Box2DWrapper.h"
#include "PhysicsMaterial.h"

enum class Shape
{
	Rectangle,
	Circle,
	Triangle
};

enum class FilterCategory {
	BIRD = 0x0001, // values in Hexadecimal
	PIG = 0x0002,
	BLOCKTYPE1 = 0x0004,
	BLOCKTYPE2 = 0x0008,
	SLINGSHOT = 0x0010, // Decimal 16!

	ALL = 0xFFFF
};

class PhysicsFixture
{

public:

	PhysicsFixture(Shape shape, float density, float friction, float restitution);
	PhysicsFixture(Shape shape, float density, float friction, float restitution, FilterCategory collisionCategory, uint16 collisionMask = (uint16)FilterCategory::ALL);
	PhysicsFixture(Shape shape);
	PhysicsFixture(Shape shape, PhysicsMaterial& material);

public:
	b2FixtureDef fixDef;
	Shape shape;
};

#endif