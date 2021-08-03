#include "PhysicsMan.h"

void PhysicsMan::Create()
{
    // nothing?
}

void PhysicsMan::Update()
{
    PhysicsMan* pMan = privGetInstance();
    assert(pMan->pWorld);

    pMan->pWorld->Update();
}

void PhysicsMan::Terminate()
{
    PhysicsMan* pMan = privGetInstance();
    assert(pMan->pWorld);
    delete pMan->pWorld;

}

void PhysicsMan::AddWorld(PhysicsWorld* _pWorld)
{
    PhysicsMan* pMan = privGetInstance();
    pMan->pWorld = _pWorld;
}

PhysicsWorld* PhysicsMan::GetWorld()
{
    PhysicsMan* pMan = privGetInstance();
    return pMan->pWorld;
}

PhysicsMan::PhysicsMan()
    :pWorld(nullptr)
{
}

PhysicsMan* PhysicsMan::privGetInstance()
{
    static PhysicsMan pMan;
    return &pMan;
}
