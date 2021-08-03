#include <assert.h>
#include "Mouse.h"

#include "CameraMan.h"

// Use this to read mouse buttons
bool Mouse::GetKeyState(AZUL_MOUSE button)
{
	bool value;

	if (glfwGetMouseButton(button) == GLFW_PRESS)
	{
		value = true;
	}
	else
	{
		value = false;
	}
	return value;
}

void Mouse::GetCursor(float &xPos, float &yPos)
{
	int xDouble;
	int yDouble;

	// get mouse position
	glfwGetMousePos(&xDouble, &yDouble);

	// why the hell would you use a double for a mouse cursor?
	// We went to the moon on 16 bits, why we need 64 for a mouse amazes me

	xPos = (float)xDouble;
	yPos = (float)yDouble;

}

void Mouse::GetWorldMousePos(float& xPos, float& yPos)
{
	float x;
	float y;
	Mouse::GetCursor(x, y);
	Camera* pCam = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
	pCam->CorrectForOrigin(x, y);

	Vect campos;
	pCam->getPos(campos);

	float currheight = pCam->getMaxY() - pCam->getMinY();
	float currwidth = pCam->getMaxX() - pCam->getMinX();
	float ScaleFactor = currwidth / pCam->getScreenWidth();

	// correct for left-right cam position and zoom
	x = ScaleFactor * x									// converts window pixels to view pixels
		- 0.5f * (currwidth - pCam->getScreenWidth())	// offsets the location of origin based on zoom view
		+ campos[X];									// corrects for camera left-right movement

	// correct for up-down cam position and zoom
	y = ScaleFactor * y									// converts window pixels to view pixels
		- 0.5f * (currheight - pCam->getScreenHeight())	// offsets the location of origin based on zoom view
		+ campos[Y];									// corrects for camera left-right movement

	xPos = x;
	yPos = y;
}
