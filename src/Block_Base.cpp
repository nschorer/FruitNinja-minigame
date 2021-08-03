#include "Block_Base.h"
#include "ContactAction.h"

Block_Base::Block_Base(GameObjectName::Name name, float x, float y, float width, float height, PhysicsFixture* pFixture, ImageName::Name _imgNames[4], PhysicsMaterial* _pMaterial, PhysicsWorld* pWorld)
	:PhysicsObject2D(name, new GraphicsObject_Sprite(_imgNames[0], Rect(x, y, width, height)), pWorld, BodyType::Dynamic, pFixture), pMaterial(_pMaterial), imgNames(_imgNames), health(_pMaterial->Health())
{
}

void Block_Base::CollideVisit(Block_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
		ContactAction::ContactPair(other, *this, pcontact, pimpulse);
}

void Block_Base::CollideVisit(Pig_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
		ContactAction::ContactPair(other, *this, pcontact, pimpulse);
}

void Block_Base::CollideVisit(RedBird& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
		ContactAction::ContactPair(other, *this, pcontact, pimpulse);
}

void Block_Base::DoDamage(float damage)
{
	float maxHealth = pMaterial->Health();
	health -= damage;

	GraphicsObject_Sprite* pSprite = (GraphicsObject_Sprite*)this->GetGameSprite();

	if (health > maxHealth * 0.75f)
	{
		pSprite->SetImage(this->imgNames[0]);
	}
	else if (health > maxHealth * 0.5f)
	{
		pSprite->SetImage(this->imgNames[1]);
	}
	else if (health > maxHealth * 0.25f)
	{
		pSprite->SetImage(this->imgNames[2]);
	}
	else if (health > 0)
	{
		pSprite->SetImage(this->imgNames[3]);
	}
	else {
		//Die();
	}
}



void Block_Base::Die()
{
	this->MarkForDelete();
}
