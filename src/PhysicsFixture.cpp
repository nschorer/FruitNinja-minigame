#include "PhysicsFixture.h"

PhysicsFixture::PhysicsFixture(Shape _shape, float density, float friction, float restitution)
	:shape(_shape)
{
	fixDef.density = density;
	fixDef.friction = friction;
	fixDef.restitution = restitution;
}

PhysicsFixture::PhysicsFixture(Shape shape, float density, float friction, float restitution, FilterCategory collisionCategory, uint16 collisionMask)
	:PhysicsFixture(shape, density, friction, restitution)
{
	fixDef.filter.categoryBits = (uint16)collisionCategory;
	fixDef.filter.maskBits = collisionMask;
}

PhysicsFixture::PhysicsFixture(Shape _shape)
	:shape(_shape)
{
	fixDef.isSensor = true;
}

PhysicsFixture::PhysicsFixture(Shape _shape, PhysicsMaterial& material)
	:shape(_shape)
{
	fixDef.density = material.Density();
	fixDef.friction = material.Friction();
	fixDef.restitution = material.Restitution();
}
