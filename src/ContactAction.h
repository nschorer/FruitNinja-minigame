// ContactAction

#ifndef _ContactAction
#define _ContactAction

struct b2ContactImpulse;
class b2Contact;

class RedBird;

class Block_Base;
class Pig_Base;

class BigPig;
class MediumPig;
class SmallPig;

class Blast;

class ContactAction
{
public:

	static void ContactPair(RedBird& redBird, Block_Base& block, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(RedBird& redBird, Pig_Base& pig, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	static void ContactPair(Pig_Base& pig, Block_Base& block1, b2Contact* pContact, const b2ContactImpulse* pImpulse);

	// Stop hitting yourself
	static void ContactPair(Pig_Base& pig1, Pig_Base& pig2, b2Contact* pContact, const b2ContactImpulse* pImpulse);
	static void ContactPair(Block_Base& block1, Block_Base& block2, b2Contact* pContact, const b2ContactImpulse* pImpulse);

};

#endif _ContactAction
