#include "Seesaw.h"

#include "PhysicsWorld.h"
#include "PhysicsJoint.h"

#include "BlocksHeader.h"
#include "BirdsPigsHeader.h"

#include "GameObjectMan.h"


Seesaw::Seesaw(float x, float y, PhysicsWorld* pWorld)
{
	// Objects

	PhysicsFixture fix(Shape::Rectangle, 0.3f, 0, 0);
	PhysicsObject2D* pLever = new PhysicsObject2D(GameObjectName::Wood_Plat_Short, new GraphicsObject_Sprite(ImageName::Wood_Plat_Short_0, Rect(x, y+40, 60, 10)), pWorld, BodyType::Static, &fix);
	pLever->SetAngle(MATH_PI2);
	GameObjectMan::Add(pLever, GameObjectName::MainGroup);

	PhysicsObject2D* pBase = new PhysicsObject2D(GameObjectName::Wood_Plat_Long, new GraphicsObject_Sprite(ImageName::Wood_Plat_Long_0, Rect(x, y, 450, 20)), pWorld, BodyType::Static, &fix);
	GameObjectMan::Add(pBase, GameObjectName::MainGroup);

	/*PhysicsObject2D* pPlank = new WoodPlatLong(x, y + 80, pWorld);
	GameObjectMan::Add(pPlank, GameObjectName::MainGroup);*/

	PhysicsObject2D* pPlank = new PhysicsObject2D(GameObjectName::Wood_Plat_Long, new GraphicsObject_Sprite(ImageName::Wood_Plat_Long_0, Rect(x, y + 80, 200, 20)), pWorld, BodyType::Dynamic, &fix);
	GameObjectMan::Add(pPlank, GameObjectName::MainGroup);

	PhysicsObject2D* pLeftSeat;
	pLeftSeat = new WoodPlatShort(x - 180, y + 80, pWorld);
	GameObjectMan::Add(pLeftSeat, GameObjectName::MainGroup);

	PhysicsObject2D* pRightSeat;
	pRightSeat = new WoodPlatShort(x + 180, y + 80, pWorld);
	GameObjectMan::Add(pRightSeat, GameObjectName::MainGroup);

	PhysicsObject2D* pPigL = new SmallPig(x - 180, y + 320, pWorld);
	GameObjectMan::Add(pPigL, GameObjectName::MainGroup);

	PhysicsObject2D* pPigR = new SmallPig(x + 180, y + 120, pWorld);
	GameObjectMan::Add(pPigR, GameObjectName::MainGroup);

	// Joints

	Vect2D v(PixelToMeter(60 / 2.0f), 0);
	PhysicsJoint::Revolute(pLever, pPlank, v);

	Vect2D v_zero = Vect2D(0, 0);
	PhysicsJoint::Revolute(pLeftSeat, pPlank, v_zero);
	PhysicsJoint::Revolute(pRightSeat, pPlank, v_zero);

	Vect2D axis(0, 1);

	v = Vect2D(PixelToMeter(-180), 0);
	PhysicsJoint::Prismatic(pBase, pLeftSeat, v, v_zero, axis);

	v = Vect2D(PixelToMeter(180), 0);
	PhysicsJoint::Prismatic(pBase, pRightSeat, v, v_zero, axis);
}

void Seesaw::Demolish()
{
}
