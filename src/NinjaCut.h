#ifndef NINJA_CUT_H
#define NINJA_CUT_H

#include "GameObject2D.h"

class NinjaSwordCallback;

class NinjaCut : public GameObject2D
{
public:
	NinjaCut(NinjaSwordCallback* pRCCB, Vect& start, Vect& end, float len, float time);
	virtual ~NinjaCut() = default;

	virtual void Update(float t) override;

private:
	float len;
	float startTime;
};

#endif