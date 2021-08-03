#include "ContactAction.h"
//#include "Box2D.h"
#include "Box2DWrapper.h"
#include "BlocksHeader.h"
#include "BirdsPigsHeader.h"
#include "Blast.h"
#include "Game.h"
#include "PixelToMeter.h"
#include "GameObjectMan.h"

void ContactAction::ContactPair(RedBird& redBird, Block_Base& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	pContact;
	redBird;
	for (int i = 0; i < pImpulse->count; i++)
	{
		// Record Damage
		block.DoDamage(pImpulse->normalImpulses[i]);
	}
}

void ContactAction::ContactPair(RedBird& redBird, Pig_Base& pig, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	pContact;
	redBird;
	for (int i = 0; i < pImpulse->count; i++)
	{
		// Record Damage
		pig.DoDamage(pImpulse->normalImpulses[i]);
	}
}

void ContactAction::ContactPair(Pig_Base& pig, Block_Base& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	pContact;
	for (int i = 0; i < pImpulse->count; i++)
	{
		// Record Damage
		pig.DoDamage(pImpulse->normalImpulses[i]);
		block.DoDamage(pImpulse->normalImpulses[i]);
	}
}

void ContactAction::ContactPair(Pig_Base& pig1, Pig_Base& pig2, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	pContact;
	for (int i = 0; i < pImpulse->count; i++)
	{
		// Record Damage
		pig1.DoDamage(pImpulse->normalImpulses[i]);
		pig2.DoDamage(pImpulse->normalImpulses[i]);
	}
}

void ContactAction::ContactPair(Block_Base& block1, Block_Base& block2, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	pContact;
	for (int i = 0; i < pImpulse->count; i++)
	{
		// Record Damage
		block1.DoDamage(pImpulse->normalImpulses[i]);
		block2.DoDamage(pImpulse->normalImpulses[i]);
	}
}


//void ContactAction::ApplyRadialImpulse(Blast& blast, WoodPlatShort& woodPlatShort, b2Contact* pContact)
//{
//	pContact;
//
//	Vect v(woodPlatShort.posX - blast.posX, woodPlatShort.posY - blast.posY, 0.0f);
//	float fStrength = 1000.0f;
//	v = v.getNorm() * fStrength;
//
//	Vect2D force(v.X(), v.Y());
//	woodPlatShort.ApplyForce(force);
//}
//*/