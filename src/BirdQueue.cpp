#include "BirdQueue.h"

#include "PhysicsMan.h"
#include "GameObjectMan.h"

BirdQueue::BirdQueue(int _capacity, float _qFrontX, float _qFrontY, PhysicsWorld* _pWorld)
	:pHead(nullptr), pWorld(_pWorld), capacity(_capacity), size(0), qFrontX(_qFrontX), qFrontY(_qFrontY)
{
}

BirdQueue::~BirdQueue()
{
	// Delete the LINKs, the GOManager will clean up the birds themselves
	BirdLink* pLink = pHead;
	while (pLink != nullptr)
	{
		BirdLink* pDelete = pLink;
		pLink = pLink->pNext;
		delete pDelete;
	}
}

void BirdQueue::Reload()
{
	for (int i = this->size; i < this->capacity; ++i)
	{
		RedBird* pBird = new RedBird(0, 0, pWorld); 
		GameObjectMan::Add(pBird, GameObjectName::MainGroup);
		Push(pBird);
	}
}

void BirdQueue::Push(RedBird* pBird)
{
	assert(pBird);
	float spacing = 50.0f;

	if (this->size == 0)
	{
		assert(pHead == nullptr);
		pHead = new BirdLink(pBird);
	}
	else
	{
		assert(pHead != nullptr);
		BirdLink* pTmp = pHead;

		for (int i = 1; i < this->size; ++i)
		{
			pTmp = pTmp->pNext;
		}

		pTmp->pNext = new BirdLink(pBird);
		pTmp->pNext->pPrev = pTmp;
	}

	pBird->SetPosition(qFrontX - (this->size * spacing), qFrontY);
	pBird->SetPhysicsActive(false);

	this->size++;
}

RedBird* BirdQueue::Pop()
{
	assert(this->size > 0);
	RedBird* pBird = pHead->pBird;
	BirdLink* pOld = pHead;

	pHead = pHead->pNext;
	pHead->pPrev = nullptr;
	delete pOld; // delete the link, leave the bird
	this->size--;

	AdvanceQueue();

	return pBird;
}

void BirdQueue::AdvanceQueue()
{
	BirdLink* pTmp = pHead;
	float spacing = 50.0f;

	float x = this->qFrontX;

	while (pTmp != nullptr)
	{
		pTmp->pBird->SetPosition(x, qFrontY);
		pTmp = pTmp->pNext;
		x -= spacing;
	}
}
