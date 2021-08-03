#include "GlassRect.h"

#include "GlassMaterial.h"

PhysicsFixture GlassRect::fixture(Shape::Rectangle, *GlassMaterial::Instance());
float GlassRect::width = 84.0f;
float GlassRect::height = 44.0f;
ImageName::Name GlassRect::imgNames[] = { ImageName::Name::Glass_Rect_0, ImageName::Name::Glass_Rect_1, ImageName::Name::Glass_Rect_2, ImageName::Name::Glass_Rect_3 };

GlassRect::GlassRect(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Glass_Rect, x, y, width, height, &fixture, imgNames, GlassMaterial::Instance(), pWorld)
{

}

