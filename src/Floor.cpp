#include "Floor.h"

PhysicsFixture Floor::fixture(Shape::Rectangle, 0.0f, 0.5f, 0.0f);

Floor::Floor(float x, float y, float width, float height, PhysicsWorld* pWorld)
	:PhysicsObject2D(GameObjectName::Floor, new GraphicsObject_Sprite(ImageName::Null, Rect(x, y, width, height)), pWorld, BodyType::Static, &Floor::fixture)
{
}
