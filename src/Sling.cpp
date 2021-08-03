#include "Sling.h"

#include "Mouse.h"
#include "CameraMan.h"

#include "PixelToMeter.h"

ImageName::Name Sling::image = ImageName::Sling;
float Sling::width = 18.0f;
float Sling::height = 10.0f;

Sling::Sling(float x, float y, float _restX, float _restY, float _maxLength)
	:GameObject2D(GameObjectName::Sling, new GraphicsObject_Sprite(image, Rect(x, y, Sling::width, Sling::height))),
	anchorX(x), anchorY(y), restX(_restX), restY(_restY), maxLength(_maxLength), pSibling(nullptr)
{

}

void Sling::Update(float t)
{
	//privUpdate();

	GameObject2D::Update(t);
}

void Sling::StretchToPoint(Vect2D& point)
{
	Vect Anchor(anchorX, anchorY, 0.0f); // Fixed point of the sling
	float MaxDrawLength = 100.0f;

	Vect DrawPoint(point.x, point.y, 0.0f);
	Vect DrawVector = (Anchor - DrawPoint);  // The 'sling direction' goes from the drawpoint towards the anchor
	float len = DrawVector.mag();
	DrawVector.norm();

	// Get the sprite angle through Atan2 (you remember? http://facweb.cs.depaul.edu/andre/GAM325/week4.htm )
	// also: http://en.cppreference.com/w/c/numeric/math/atan2
	this->currAngle = atan2f(DrawVector[Y], DrawVector[X]);

	// rescaling the sprite based on the sling's extension
	this->scaleX = len / MaxDrawLength * 6; // I don't understand math

	// Adjust sprite position
	//*
	Vect newCenterPos = Anchor - 0.5f * len * DrawVector;
	this->posX = newCenterPos[X];
	this->posY = newCenterPos[Y];
	//*/
}

void Sling::privUpdate()
{
	if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT)) {
			Vect Anchor(anchorX, anchorY, 0.0f); // Fixed point of the sling
			float MaxDrawLength = maxLength;

			// get mouse position
			float xPos;
			float yPos;

			Mouse::GetWorldMousePos(xPos, yPos);

			Vect DrawPoint(xPos, yPos, 0.0f);
			Vect DrawVector = (Anchor - DrawPoint);  // The 'sling direction' goes from the drawpoint towards the anchor
			float len = DrawVector.mag();
			DrawVector.norm();

			// Cap the sling's extension
			if (len > MaxDrawLength)
			{
				len = MaxDrawLength;
			}


			// Get the sprite angle through Atan2 (you remember? http://facweb.cs.depaul.edu/andre/GAM325/week4.htm )
			// also: http://en.cppreference.com/w/c/numeric/math/atan2
			this->currAngle = atan2f(DrawVector[Y], DrawVector[X]);

			// rescaling the sprite based on the sling's extension
			this->scaleX = len / MaxDrawLength * 6; // I don't understand math

			// Adjust sprite position
			//*
			Vect newCenterPos = Anchor - 0.5f * len * DrawVector;
			this->posX = newCenterPos[X];
			this->posY = newCenterPos[Y];
			//*/
		
		
	}
	else
	{
		Vect Anchor(anchorX, anchorY, 0.0f); // Fixed point of the sling

		Vect DrawPoint(restX, restY, 0.0f);
		Vect DrawVector = (Anchor - DrawPoint);  // The 'sling direction' goes from the drawpoint towards the anchor
		float len = DrawVector.mag();
		DrawVector.norm();

		float MaxDrawLength = maxLength;
		// Cap the sling's extension
		if (len > MaxDrawLength)
		{
			len = MaxDrawLength;
		}

		// Get the sprite angle through Atan2 (you remember? http://facweb.cs.depaul.edu/andre/GAM325/week4.htm )
		// also: http://en.cppreference.com/w/c/numeric/math/atan2
		this->currAngle = atan2f(DrawVector[Y], DrawVector[X]);

		// rescaling the sprite based on the sling's extension
		this->scaleX = len / MaxDrawLength * 6; // I don't understand math

		// Adjust sprite position
		//*
		Vect newCenterPos = Anchor - 0.5f * len * DrawVector;
		this->posX = newCenterPos[X];
		this->posY = newCenterPos[Y];
	}
}