#include "WhiteBird.h"

PhysicsFixture WhiteBird::fixture(Shape::Rectangle, 3.0f, 0.6f, 0.5f);
ImageName::Name WhiteBird::image = ImageName::Bird_White_0;
float WhiteBird::width = 81.0f;
float WhiteBird::height = 93.0f;

WhiteBird::WhiteBird(float x, float y, PhysicsWorld* pWorld)
	:PhysicsObject2D(GameObjectName::Bird_White, new GraphicsObject_Sprite(image, Rect(x, y, WhiteBird::width, WhiteBird::height)), pWorld, BodyType::Dynamic, &WhiteBird::fixture)
{

}
