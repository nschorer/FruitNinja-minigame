#include "BlackBird.h"

#include "GameObjectMan.h"
#include "Blast.h"

PhysicsFixture BlackBird::fixture(Shape::Rectangle, 10.0f, 0.3f, 0.5f);
ImageName::Name BlackBird::image = ImageName::Bird_Black_0;
float BlackBird::width = 61.0f;
float BlackBird::height = 81.0f;

BlackBird::BlackBird(float x, float y, PhysicsWorld* pWorld)
	:PhysicsObject2D(GameObjectName::Bird_Black, new GraphicsObject_Sprite(image, Rect(x, y, BlackBird::width, BlackBird::height)), pWorld, BodyType::Dynamic, &BlackBird::fixture)
{

}

void BlackBird::Explode()
{
	GameObject* pObj = new Blast(this->posX, this->posY, this->pPhysicsBody->GetWorld());
	GameObjectMan::Add(pObj, GameObjectName::Name::Effects);
}
