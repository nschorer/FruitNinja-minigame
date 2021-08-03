#ifndef PIG_BASE_H
#define PIG_BASE_H

#include "PhysicsObject2D.h"

class Pig_Base : public PhysicsObject2D
{
public:

	virtual ~Pig_Base() = default;

	virtual void CollideAccept(PhysicsObject2D & other, b2Contact * contact, const b2ContactImpulse * pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };

	virtual void CollideVisit(Pig_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;
	virtual void CollideVisit(RedBird & other, b2Contact * pcontact, const b2ContactImpulse * pimpulse) override;
	virtual void CollideVisit(Block_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;

	void DoDamage(float damage);

protected:
	Pig_Base(GameObjectName::Name name, float x, float y, float width, float height, PhysicsFixture * Fixture, float maxHealth, ImageName::Name imgNames[2], PhysicsWorld * pWorld);
	Pig_Base() = delete;

private:

	void Die();

protected:

	ImageName::Name* imgNames;
	float maxHealth;
	float health;

	static const int numImgs = 2;

};

#endif