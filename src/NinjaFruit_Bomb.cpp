#include "NinjaFruit_Bomb.h"
#include "GameObjectMan.h"
#include "Scoreboard.h"
#include "TimerEvent_DeleteGameObject.h"
#include "TimerMan.h"

ImageName::Name NinjaFruit_Bomb::imgNames[2] = { ImageName::Name::Bird_Black_0, ImageName::Name::Bang};
float NinjaFruit_Bomb::radius = 40.0f;

extern int comboCounter;
extern float comboTimer;

NinjaFruit_Bomb::NinjaFruit_Bomb(float x, float y, PhysicsWorld* pWorld)
	:NinjaFruit(GameObjectName::Name::Alien, x, y, NinjaFruit_Bomb::radius, -500, NinjaFruit_Bomb::imgNames, pWorld)
{
}

void NinjaFruit_Bomb::OnCut()
{
	this->MarkForDelete();

	GameObject2D* pGObj = new GameObject2D(GameObjectName::Bang, new GraphicsObject_Sprite(ImageName::Name::Bang, Rect(this->posX, this->posY, this->radius * 3.0f, this->radius * 3.0f)));
	GameObjectMan::Add(pGObj, GameObjectName::Slong_Handle_Front);

	TimerMan::AddEvent(0.5f, new TimerEvent_DeleteGameObject(pGObj));

	comboCounter = 0;
	comboTimer = 0.0f;

	//Trace::out("\n%i", this->score);
	Scoreboard::ChangeScore(this->score);
}
