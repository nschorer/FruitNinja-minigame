#include "FerrisWheel.h"

#include "PhysicsWorld.h"
#include "PhysicsJoint.h"

#include "BlocksHeader.h"
#include "BirdsPigsHeader.h"

#include "GameObjectMan.h"

FerrisWheel::FerrisWheel(float x, float y, PhysicsWorld* pWorld)
{
	// base/center
	PhysicsFixture fix(Shape::Rectangle, 5.5f, 10.1f, 0.1f);
	PhysicsObject2D* pBase = new PhysicsObject2D(GameObjectName::Wood_Plat_Long, new GraphicsObject_Sprite(ImageName::Wood_Plat_Long_0, Rect(x, y - 250, 450, 20)), pWorld, BodyType::Static, &fix);
	GameObjectMan::Add(pBase, GameObjectName::MainGroup);

	PhysicsObject2D* pCenter = new WoodCircle(x, y, pWorld);
	pCenter->SetCollisionFlags(0, 0);
	GameObjectMan::Add(pCenter, GameObjectName::MainGroup);

	// spokes

	PhysicsObject2D* pSpoke0 = new PhysicsObject2D(GameObjectName::Wood_Plat_Long, new GraphicsObject_Sprite(ImageName::Wood_Plat_Long_0, Rect(x - 80, y, 130, 20)), pWorld, BodyType::Dynamic, &fix);
	pSpoke0->SetCollisionFlags(0, 0);
	GameObjectMan::Add(pSpoke0, GameObjectName::Background);

	PhysicsObject2D* pSpoke1 = new PhysicsObject2D(GameObjectName::Wood_Plat_Long, new GraphicsObject_Sprite(ImageName::Wood_Plat_Long_0, Rect(x + 80, y, 130, 20)), pWorld, BodyType::Dynamic, &fix);
	pSpoke1->SetCollisionFlags(0, 0);
	GameObjectMan::Add(pSpoke1, GameObjectName::Background);

	PhysicsObject2D* pSpoke2 = new PhysicsObject2D(GameObjectName::Wood_Plat_Long, new GraphicsObject_Sprite(ImageName::Wood_Plat_Long_0, Rect(x, y + 80, 130, 20)), pWorld, BodyType::Dynamic, &fix);
	pSpoke2->SetAngle(MATH_PI2);
	pSpoke2->SetCollisionFlags(0, 0);
	GameObjectMan::Add(pSpoke2, GameObjectName::Background);

	PhysicsObject2D* pSpoke3 = new PhysicsObject2D(GameObjectName::Wood_Plat_Long, new GraphicsObject_Sprite(ImageName::Wood_Plat_Long_0, Rect(x, y - 80, 130, 20)), pWorld, BodyType::Dynamic, &fix);
	pSpoke3->SetAngle(MATH_PI2);
	pSpoke3->SetCollisionFlags(0, 0);
	GameObjectMan::Add(pSpoke3, GameObjectName::Background);

	// plats

	PhysicsObject2D* pPlat0 = new WoodPlatShort(x - 150, y, pWorld);
	GameObjectMan::Add(pPlat0, GameObjectName::MainGroup);

	PhysicsObject2D* pPlat1 = new WoodPlatShort(x + 150, y, pWorld);
	GameObjectMan::Add(pPlat1, GameObjectName::MainGroup);

	PhysicsObject2D* pPlat2 = new WoodPlatShort(x, y + 150, pWorld);
	GameObjectMan::Add(pPlat2, GameObjectName::MainGroup);

	PhysicsObject2D* pPlat3 = new WoodPlatShort(x, y - 150, pWorld);
	GameObjectMan::Add(pPlat3, GameObjectName::MainGroup);

	// pigs


	SmallPig* pPig0 = new SmallPig(x - 150, y + 30, pWorld);
	GameObjectMan::Add(pPig0, GameObjectName::Name::MainGroup);

	SmallPig* pPig1 = new SmallPig(x + 150, y + 30, pWorld);
	GameObjectMan::Add(pPig1, GameObjectName::Name::MainGroup);

	SmallPig* pPig2 = new SmallPig(x, y + 180, pWorld);
	GameObjectMan::Add(pPig2, GameObjectName::Name::MainGroup);

	SmallPig* pPig3 = new SmallPig(x, y - 120, pWorld);
	GameObjectMan::Add(pPig3, GameObjectName::Name::MainGroup);

	// joints
	Vect2D v_zero(0, 0);

	b2RevoluteJoint* rvJoint_centerBase =  PhysicsJoint::Revolute(pCenter, pBase, v_zero, 0.25f, 200000);
	rvJoint_centerBase;

	b2RevoluteJoint* rvJoint_plat0Center = PhysicsJoint::Revolute(pPlat0, pSpoke0, v_zero);
	b2RevoluteJoint* rvJoint_plat1Center = PhysicsJoint::Revolute(pPlat1, pSpoke1, v_zero);
	b2RevoluteJoint* rvJoint_plat2Center = PhysicsJoint::Revolute(pPlat2, pSpoke2, v_zero);
	b2RevoluteJoint* rvJoint_plat3Center = PhysicsJoint::Revolute(pPlat3, pSpoke3, v_zero);

	PhysicsJoint::Gear(pCenter, pPlat0, rvJoint_centerBase, rvJoint_plat0Center);
	PhysicsJoint::Gear(pCenter, pPlat1, rvJoint_centerBase, rvJoint_plat1Center);
	PhysicsJoint::Gear(pCenter, pPlat2, rvJoint_centerBase, rvJoint_plat2Center);
	PhysicsJoint::Gear(pCenter, pPlat3, rvJoint_centerBase, rvJoint_plat3Center);

	Vect2D v = v_zero;

	/*v.x = PixelToMeter(-50);
	PhysicsJoint::Weld(pCenter, pSpoke0, v);
	v.x = PixelToMeter(50);
	PhysicsJoint::Weld(pCenter, pSpoke1, v);

	v.x = 0;
	v.y = PixelToMeter(50);
	PhysicsJoint::Weld(pCenter, pSpoke2, v);
	v.y = PixelToMeter(-50);
	PhysicsJoint::Weld(pCenter, pSpoke3, v);*/


	PhysicsJoint::Weld(pCenter, pSpoke0, v_zero);
	PhysicsJoint::Weld(pCenter, pSpoke1, v_zero);
	PhysicsJoint::Weld(pCenter, pSpoke2, v_zero);
	PhysicsJoint::Weld(pCenter, pSpoke3, v_zero);

	pPig0->pJoint = PhysicsJoint::Weld(pPlat0, pPig0, v_zero);
	pPig1->pJoint = PhysicsJoint::Weld(pPlat1, pPig1, v_zero);
	pPig2->pJoint = PhysicsJoint::Weld(pPlat2, pPig2, v_zero);
	pPig3->pJoint = PhysicsJoint::Weld(pPlat3, pPig3, v_zero);
}
