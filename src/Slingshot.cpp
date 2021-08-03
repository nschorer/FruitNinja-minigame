#include "Slingshot.h"

#include "GameObjectMan.h"
#include "BirdQueue.h"
#include "Mouse.h"

Slingshot::Slingshot(float x, float y, BirdQueue* _pQueue)
	: GameObject2D(GameObjectName::Name::Slingshot, new GraphicsObject_Sprite(ImageName::Name::Null, Rect(x, y, 0.0f, 0.0f))), pQueue(_pQueue), pBird(nullptr), shouldLaunch(false)
{
	assert(pQueue);

	pSling_Branch = new GameObject2D(GameObjectName::Name::Sling_Branch, new GraphicsObject_Sprite(ImageName::Name::Sling_Branch, Rect(x - 25, y + 40, 47, 127)));
	pSling_Tree = new GameObject2D(GameObjectName::Name::Sling_Tree, new GraphicsObject_Sprite(ImageName::Name::Sling_Tree, Rect(x, y, 40, 200)));
	
	pSling_R = new Sling(x-25, y+68, x - 25, y + 68, 100.0f);
	pSling_L = new Sling(x+3, y + 68, x - 25, y + 68, 100.0f);

	GameObjectMan::Add(pSling_Tree, GameObjectName::Sling_Handle_Back);
	GameObjectMan::Add(pSling_Branch, GameObjectName::Slong_Handle_Front);
	GameObjectMan::Add(pSling_L, GameObjectName::Sling_Back);
	GameObjectMan::Add(pSling_R, GameObjectName::Sling_Front);
}

Slingshot::~Slingshot()
{
	/*GameObjectMan::Delete(pSling_Branch);
	GameObjectMan::Delete(pSling_Tree);
	GameObjectMan::Delete(pSling_L);
	GameObjectMan::Delete(pSling_R);*/
}

void Slingshot::Update(float t)
{
	Vect2D slingPoint, birdPoint;
	GetDragPoint(slingPoint, birdPoint);
	pSling_L->StretchToPoint(slingPoint);
	pSling_R->StretchToPoint(slingPoint);

	if (pBird)
	{
		Vect Anchor(this->posX - 20, this->posY + 68, 0.0f);
		pBird->SetPosition(birdPoint.x, birdPoint.y + 8);
	}

	GameObject2D::Update(t);
}

void Slingshot::LoadBirdFromQueue()
{
	if (pBird == nullptr) {
		LoadBird(pQueue->Pop());
	}
}

void Slingshot::LoadBird(RedBird* _pBird)
{
	assert(pBird == nullptr);
	assert(_pBird != nullptr);
	pBird = _pBird;
	pBird->SetPhysicsActive(false);
}

void Slingshot::LaunchBird(Vect2D& impulse)
{
	pBird->SetPhysicsActive(true);
	pBird->ApplyImpulse(impulse);
	pBird = nullptr;
}

void Slingshot::GetDragPoint(Vect2D& slingPoint, Vect2D& birdPoint)
{
	static bool SlingHeld = false;
	float xPos;
	float yPos;
	Mouse::GetWorldMousePos(xPos, yPos);

	// Only grab sling if in nearby radius
	if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT))
	{
		if (!SlingHeld) {
			Vect slingPos(this->posX, this->posY, 0.0f);
			Vect mousePos(xPos, yPos, 0.0f);

			if ((slingPos - mousePos).magSqr() < 100 * 100) // radius of 100
			{
				SlingHeld = true;
			}
		}
	}
	else
	{
		SlingHeld = false;
	}

	if (SlingHeld) {
		

		float MaxDrawLength = 75.0f;

		

		Vect Anchor(this->posX - 20, this->posY + 68, 0.0f);
		Vect DrawPoint(xPos, yPos, 0.0f);
		Vect DrawVector = (Anchor - DrawPoint);  // The 'sling direction' goes from the drawpoint towards the anchor
		float len = DrawVector.mag();
		Vect impulseVect = DrawVector;

		if (len > MaxDrawLength)
		{
			impulseVect.norm();
			impulseVect *= MaxDrawLength;
		}

		DrawVector.norm();

		// Cap the sling's extension
		if (len > MaxDrawLength)
		{
			len = MaxDrawLength;
		}

		shouldLaunch = len > 30.0f;
		if (shouldLaunch)
		{
			float scalar = 0.3f;
			launchDirection.x = impulseVect[X] * scalar;
			launchDirection.y = impulseVect[Y] * scalar;
		}

		Vect result = Anchor - DrawVector * len;
		slingPoint = Vect2D(result.X(), result.Y());
		
		result = Anchor - DrawVector * len  + DrawVector * 20.0f;
		birdPoint = Vect2D(result.X(), result.Y());
	}
	else
	{
		slingPoint = Vect2D(this->posX-20, this->posY+68);
		birdPoint = Vect2D(this->posX - 10, this->posY + 68);

		if (pBird && shouldLaunch)
		{
			LaunchBird(launchDirection);
		}
		shouldLaunch = false;
	}
}
