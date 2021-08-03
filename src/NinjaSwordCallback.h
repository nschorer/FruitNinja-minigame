#ifndef NINJA_SWORD_CALLBACK_H
#define NINJA_SWORD_CALLBACK_H

#include "Box2DWrapper.h"
#include <list>

class NinjaSwordCallback : public b2RayCastCallback
{
public:
	virtual float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction) override;

	void ClearList();
	void ProcessList();

private:
	using ListFixtures = std::list<b2Fixture*>;
	ListFixtures lstFixtures;

};

#endif _SimpleRayCastCallBack