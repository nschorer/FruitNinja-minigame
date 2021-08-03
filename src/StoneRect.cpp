#include "StoneRect.h"
#include "StoneMaterial.h"

PhysicsFixture StoneRect::fixture(Shape::Rectangle, *StoneMaterial::Instance());
float StoneRect::width = 84.0f;
float StoneRect::height = 44.0f;
ImageName::Name StoneRect::imgNames[] = { ImageName::Name::Stone_Rect_0, ImageName::Name::Stone_Rect_1, ImageName::Name::Stone_Rect_2, ImageName::Name::Stone_Rect_3 };

StoneRect::StoneRect(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Stone_Rect, x, y, width, height, &fixture, imgNames, StoneMaterial::Instance(), pWorld)
{

}