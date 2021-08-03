#include "NinjaLauncher.h"
#include "MathEngine.h"
#include "GameObjectMan.h"
#include "NinjaHeader.h"
#include "TimerMan.h"
#include "TimerEvent_LaunchFruit.h"

NinjaLauncher::NinjaLauncher(float _x, float _y, float _radius, PhysicsWorld* _pWorld)
	:x(_x), y(_y), radius(_radius), pWorld(_pWorld),active(true)
{
}

void NinjaLauncher::StartLaunching(Difficulty d)
{
	if (active) {
		diff = d;
		LaunchRandomFruit();

		float delay = 0;
		switch (d)
		{
		case Difficulty::NORMAL:
			delay = (rand() % 100) / 20.0f; // up to 5 second delay
			break;
		case Difficulty::HARD:
			delay = (rand() % 100) / 100.0f; // up to 1 second delay
			break;
		}
		TimerMan::AddEvent(delay, new TimerEvent_LaunchFruit(this, diff));
	}
}

void NinjaLauncher::StopLaunching()
{
	active = false;
}

void NinjaLauncher::LaunchRandomFruit()
{
	float offset = ( 270 + (rand() % 40) - 20) * MATH_PI_180;
	float launchX = this->x + cosf(offset) * radius;
	float launchY = this->y + sinf(offset) * radius;

	int roulette = rand() % 20;
	NinjaFruit* pFruit;
	if (roulette <= 3)
	{
		pFruit = new NinjaFruit_Bomb(launchX, launchY, pWorld);
	}
	else
	{
		pFruit = new NinjaFruit_Pig(launchX, launchY, pWorld);
	}
	GameObjectMan::Add(pFruit, GameObjectName::Name::MainGroup);

	Vect direction(this->x - launchX, this->y - launchY, 0.0f);
	float angleOffset = ((rand() % 10) - 5) * MATH_PI_180;
	float cs = cosf(angleOffset);
	float sn = sinf(angleOffset);
	float px = cs * direction.X() - sn * direction.Y();
	float py = sn * direction.X() + direction.Y() * cs;
	direction.X() = px;
	direction.Y() = py;

	direction *= 0.06f;

	Vect2D impulse(direction.X(), direction.Y());

	pFruit->ApplyImpulse(impulse);
}
