#include "NinjaSword.h"
#include <string>
#include "GameObject2D.h"
#include "CameraMan.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "DebugOut.h"
#include "PixelToMeter.h"
//#include "AudioManager.h"
#include "SimpleRayCastCallBack.h"
#include "NinjaSwordCallback.h"
#include "Visualizer.h"
#include "Game.h"
#include "PhysicsMan.h"
#include "NinjaCut.h"
#include "GameObjectMan.h"

int comboCounter = 0;
float comboTimer = 0.0f;
Vect cutNorm;

void NinjaAction(NinjaSwordCallback* rccb, float elapsedTime, float totalTime)
{
	if (comboTimer > 0) {
		comboTimer -= elapsedTime;
		if (comboTimer < 0.0f)
		{
			comboCounter = 0;
			comboTimer = 0.0;
		}
	}

	static bool LeftButtonDown = false;
	static b2Vec2 prevPos;
	float xPos, yPos;

	if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT) && !LeftButtonDown)
	{
		// begin capture
		Mouse::GetWorldMousePos(xPos, yPos);
		prevPos = b2Vec2(xPos, yPos);		// Start of the line
		//prevPos = b2Vec2(PixelToMeter(xPos), PixelToMeter(yPos));		// Start of the line
		//DebugMsg::out("Line: Begin\n");
		LeftButtonDown = true;
	}
	else if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT) && LeftButtonDown)
	{
		// continue capture
		Mouse::GetWorldMousePos(xPos, yPos);
		b2Vec2 WorldMousePos(xPos, yPos);
		//b2Vec2 WorldMousePos(+PixelToMeter(xPos), +PixelToMeter(yPos)); // End of the line

												// If mouse has actually moved
		if ((WorldMousePos - prevPos).LengthSquared() > .01f)
		{
			// Debug view
			//Visualizer::AddLineWorld(prevPos, WorldMousePos);

			Vect start(prevPos.x, prevPos.y, 0.0f);
			Vect end(WorldMousePos.x, WorldMousePos.y, 0.0f);

			float len = (end - start).mag();

			if (len > 10) {
				NinjaCut* pCut = new NinjaCut(rccb, start, end, len, totalTime);
				GameObjectMan::Add(pCut, GameObjectName::Name::Slong_Handle_Front);
				cutNorm = (end - start).getNorm();
			}

			//DebugMsg::out("Line: (%.2f, %.2f) - (%.2f, %.2f)\n", prevPos.x, prevPos.y, WorldMousePos.x, WorldMousePos.y);
			LeftButtonDown = true;
			prevPos = WorldMousePos; // next line's start point
		}

	}
	else if (!Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT) && LeftButtonDown)
	{
		// end capture
		//rccb->ClearList();

		//DebugMsg::out("Line: End\n");
		LeftButtonDown = false;

		// Debug view
		Visualizer::ClearLines();
	}
}
