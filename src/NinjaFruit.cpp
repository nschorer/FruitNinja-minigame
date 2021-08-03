#include "NinjaFruit.h"
#include "GameObjectMan.h"
#include "Scoreboard.h"

PhysicsFixture NinjaFruit::fixture(Shape::Circle, 10.0f, 0.3f, 0.5f);

extern int comboCounter;
extern float comboTimer;
extern Vect cutNorm;

NinjaFruit::NinjaFruit(GameObjectName::Name name, float x, float y, float _radius, int _score, ImageName::Name _imgNames[3], PhysicsWorld* pWorld)
	:PhysicsObject2D(name, new GraphicsObject_Sprite(_imgNames[0], Rect(x, y, 2 * _radius, 2 * _radius)), pWorld, BodyType::Dynamic, &fixture), imgNames(_imgNames), radius(_radius), score(_score)
{
	this->SetCollisionFlags(0, 0);
	ignoreRaycast = false;
}

void NinjaFruit::OnCut()
{
	this->MarkForDelete();

	//Trace::out("\n\nPoint  : %f, %f", this->point.x, this->point.y);
	//Trace::out("\nNormal: %f, %f", this->normal.x, this->normal.y);
	//float x = normal.x;
	//float y = normal.y;
	float x = cutNorm.X();
	float y = cutNorm.Y();

	//Trace::out("\n\nCut  : %f, %f", x, y);

	float ang = MATH_PI2;
	float cs = cosf(ang);
	float sn = sinf(ang);

	float px = x * cs - y * sn;
	float py = x * sn + y * cs;
	float scale = 3.0f;
	px *= scale;
	py *= scale;
	//Trace::out("\nSplit : %f, %f\n", px, py);

	b2Vec2 v = this->GetPhysicsBody()->GetB2Body()->GetLinearVelocity();

	PhysicsObject2D* pObj;
	float fruitX = this->posX;
	float fruitY = this->posY;
	float cutRadius = radius * 1.4f;

	Vect2D impulse(px, py);
	pObj = new PhysicsObject2D(this->GetName(), new GraphicsObject_Sprite(imgNames[1], Rect(fruitX + px, fruitY + py, cutRadius, cutRadius)), this->pPhysicsBody->GetWorld(), BodyType::Dynamic, &fixture);
	GameObjectMan::Add(pObj, GameObjectName::Name::MainGroup);
	pObj->SetCollisionFlags(0, 0);
	pObj->GetPhysicsBody()->GetB2Body()->SetLinearVelocity(v);
	pObj->ApplyImpulse(impulse);

	impulse.x *= -1;
	impulse.y *= -1;
	pObj = new PhysicsObject2D(this->GetName(), new GraphicsObject_Sprite(imgNames[2], Rect(fruitX+px, fruitY+py, cutRadius, cutRadius)), this->pPhysicsBody->GetWorld(), BodyType::Dynamic, &fixture);
	GameObjectMan::Add(pObj, GameObjectName::Name::MainGroup);
	pObj->SetCollisionFlags(0, 0);
	pObj->GetPhysicsBody()->GetB2Body()->SetLinearVelocity(v);
	pObj->ApplyImpulse(impulse);

	//Trace::out("\n+%i", this->score * (1 + comboCounter));
	Scoreboard::ChangeScore(this->score * (1 + comboCounter));
	comboCounter++;
	comboTimer = 0.4f;
}
