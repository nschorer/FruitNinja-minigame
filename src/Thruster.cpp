#include "Thruster.h"
#include "PixelToMeter.h"
#include "GameObjectMan.h"
#include "Lander.h"
#include "MathEngine.h"

ImageName::Name Thruster::img(ImageName::Name::Bang);
float Thruster::width = 50;
float Thruster::height = 20;

Thruster::~Thruster()
{
	delete poBang;
	
	if (this->active)
	{
		delete poNullSprite;
	}
	else
	{
		delete poSprite;
	}
}

Thruster::Thruster(PhysicsBody* _pBody, float _x, float _y, float _ang, float _scale)
	:pBody(_pBody), x(_x), y(_y), ang(_ang), scale(_scale)
{
	poSprite = new GraphicsObject_Sprite(Thruster::img, Rect(x, y, width * (scale / 100.0f), height * (scale / 100.0f)));
	poNullSprite = new GraphicsObject_Sprite(ImageName::Name::Null, Rect(x, y, width * (scale / 100.0f), height * (scale / 100.0f)));

	poBang = new GameObject2D(GameObjectName::Bang, poSprite);
	poBang->currAngle = ang;
	GameObjectMan::Add(poBang, GameObjectName::Effects);
}

void Thruster::Update(Lander* pLander)
{
	if (this->active)
	{
		poBang->SetGameSprite(poSprite);
	}
	else
	{
		poBang->SetGameSprite(poNullSprite);
		poSprite->SetWorld(poBang->getWorld());
	}

	this->active = false;

	// we could also get it from the body...
	poBang->currAngle = pLander->currAngle + ang;

	float c = cosf(pLander->currAngle);
	float s = sinf(pLander->currAngle);


	poBang->posX = pLander->posX + (x * c - y * s);
	poBang->posY = pLander->posY + (x * s + y * c);

}

void Thruster::ApplyForce(float force)
{
	float angle = pBody->GetAngle() + ang;
	Vect2D dir_normal(force * cosf(angle), force * sinf(angle));

	pBody->ApplyForce(dir_normal);

	this->active = true;
}

void Thruster::ApplyTorque(float torque)
{
	float angle = pBody->GetAngle() + ang;
	Vect2D dir(torque * cosf(angle), torque * sinf(angle));

	Vect2D thrusterPoint(this->x, this->y);

	pBody->ApplyForceToPoint(dir, thrusterPoint);

	this->active = true;
}
