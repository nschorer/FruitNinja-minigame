#include "GlassSquare.h"

#include "GlassMaterial.h"

PhysicsFixture GlassSquare::fixture(Shape::Rectangle, *GlassMaterial::Instance());
float GlassSquare::width = 44.0f;
float GlassSquare::height = 44.0f;
ImageName::Name GlassSquare::imgNames[] = { ImageName::Name::Glass_Square_0, ImageName::Name::Glass_Square_1, ImageName::Name::Glass_Square_2, ImageName::Name::Glass_Square_3 };

GlassSquare::GlassSquare(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Glass_Square, x, y, width, height, &fixture, imgNames, GlassMaterial::Instance(), pWorld)
{

}