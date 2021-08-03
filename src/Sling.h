#ifndef SLING_H
#define SLING_H


#include "GameObject2D.h"

class Sling : public GameObject2D
{
public:

	Sling(float x, float y, float restX, float restY, float maxLength);

	virtual void Update(float t) override;

	void StretchToPoint(Vect2D& point);

private:

	void privUpdate();

private:
	static ImageName::Name image;
	static float width;
	static float height;

	float anchorX;
	float anchorY;
	float restX;
	float restY;
	float maxLength;
	Sling* pSibling;
};

#endif