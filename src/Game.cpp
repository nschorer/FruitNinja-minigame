#include <sb6.h>
#include <sb6ktx.h>
#include <math.h>
#include <assert.h>

#include "DebugOut.h"
#include "GameObject.h"
#include "MathEngine.h"
#include "Game.h"
#include "GraphicsObject.h"
#include "GraphicsObject_Sprite.h"
#include "GraphicsObject_Circle.h"
#include "GraphicsObject_Box.h"
#include "GraphicsObject_Tri.h"
#include "TextureMan.h"
#include "Camera.h"
#include "GameObjectMan.h"
#include "CameraMan.h"
#include "Image.h"
#include "GameObject2D.h"
#include "Color.h"
#include "Vect2D.h"
#include "ShaderMan.h"
#include "ImageMan.h"
#include "DebugOut.h"
#include "ModelMan.h"
#include "AzulStopWatch.h"
#include "TimerMan.h"
#include "Keyboard.h"
#include "Mouse.h"

Game* Game::ptrInstance = nullptr;

//#include "Box2D.h"
#include "Box2DWrapper.h"
#include "PixelToMeter.h"
#include "PhysicsMan.h"
#include "BirdsPigsHeader.h"
#include "WoodPlatform.h"
#include "BlocksHeader.h"
#include "TowersHeader.h"
#include "Floor.h"
#include "Slingshot.h"
#include "BirdQueue.h"

#include "AngryContactListener.h"

#include "Lander1.h"
#include "Lander2.h"
#include "Seesaw.h"
#include "FerrisWheel.h"
#include "Visualizer.h"
#include "NinjaSword.h"
#include "SimpleRaycastCallback.h"
#include "NinjaSwordCallback.h"
#include "NinjaHeader.h"
#include "NinjaLauncher.h"
#include "Scoreboard.h"

AngryContactListener* pMyContactListener;
NinjaLauncher* pLauncher;

SimpleRayCastCallBack* pSimpleRCCB;
NinjaSwordCallback* pNinjaRCCB;

//-----------------------------------------------------------------------------
//  Game::Game()
//		Game Engine Constructor
//-----------------------------------------------------------------------------
Game::Game(const char* windowName, const int Width, const int Height)
	:Engine(windowName, Width, Height)
{
	ptrInstance = this;
	screenWidth = static_cast<float>(Width);
	screenHeight = static_cast<float>(Height);
}

//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void Game::Initialize()
{
	// Initialize timer
	AzulStopWatch::initStopWatch();

	// Start timer
	stopWatch.tic();
	totalWatch.tic();

	//---------------------------------------------------------------------------------------------------------
	// Box2D setup
	//---------------------------------------------------------------------------------------------------------

	PhysicsMan::Create();
	PhysicsWorld* pWorld = new PhysicsWorld(-10.0f, 50);
	PhysicsMan::AddWorld(pWorld);
}

//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void Game::LoadContent()
{
	//---------------------------------------------------------------------------------------------------------
	// Setup the current 2D orthographic Camera
	//---------------------------------------------------------------------------------------------------------
	Camera* pCam2D = new Camera(Camera::Type::ORTHOGRAPHIC_2D);

	float zoomFactor = 1.5f;
	float xShift = 1000.0f;
	float yShift = 100.0f;

	pCam2D->setViewport(0, 0, (int)this->screenWidth, (int)this->screenHeight);
	pCam2D->setOrthographic(-pCam2D->getScreenWidth() / 2.0f * zoomFactor, pCam2D->getScreenWidth() / 2.0f * zoomFactor,
		-pCam2D->getScreenHeight() / 2.0f * zoomFactor, pCam2D->getScreenHeight() / 2.0f * zoomFactor,
		1.0f, 1000.0f);
	//pCam2D->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 0.0f, -1.0f), Vect(0.0f, 0.0f, 0.0f));
	pCam2D->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0 + xShift, 0 + yShift, -1.0f), Vect(0 + xShift, 0 + yShift, 0.0f));

	// Holder for the current 2D  cameras
	CameraMan::SetCurrentCamera(pCam2D, Camera::Type::ORTHOGRAPHIC_2D);

	//---------------------------------------------------------------------------------------------------------
	// Load up the managers
	//---------------------------------------------------------------------------------------------------------
		// Create/Load Shader 
	ShaderMan::addShader(ShaderName::SPRITE, "spriteRender");
	ShaderMan::addShader(ShaderName::SPRITE_LINE, "spriteLineRender");

	// Textures
	TextureMan::addTexture("../../../../reference/reference/Asset/AngryBirds/unsorted.tga", TextName::BirdPigsEffects);
	TextureMan::addTexture("../../../../reference/reference/Asset/AngryBirds/woodBlocks.tga", TextName::WoodBlocks);
	TextureMan::addTexture("../../../../reference/reference/Asset/AngryBirds/glassBlocks.tga", TextName::GlassBlocks);
	TextureMan::addTexture("../../../../reference/reference/Asset/AngryBirds/stoneBlocks.tga", TextName::StoneBlocks);
	TextureMan::addTexture("../../../../reference/reference/Asset/AngryBirds/AngryBirdBackground.tga", TextName::AngryBackground);
	TextureMan::addTexture("../../../../reference/reference/Asset/AngryBirds/woodPlatform.tga", TextName::WoodPlatform);
	TextureMan::addTexture("../../../../reference/reference/Asset/AngryBirds/slingV2.tga", TextName::SlingV2);

	// Images
	LoadImages();

	//---------------------------------------------------------------------------------------------------------
	// Sort buckets (AKA sprite layers)
	//---------------------------------------------------------------------------------------------------------
	GameSortBucket* pSortBkt;

	pSortBkt = new GameSortBucket(GameObjectName::Slong_Handle_Front);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::Sling_Front);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::MainGroup);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::Effects);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::Sling_Handle_Back);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::Sling_Back);
	GameObjectMan::Add(pSortBkt);

	pSortBkt = new GameSortBucket(GameObjectName::Background);
	GameObjectMan::Add(pSortBkt);

	//---------------------------------------------------------------------------------------------------------
	// Create Sprites
	//---------------------------------------------------------------------------------------------------------

	CreateGameObjects();

	// create and initialize contact listener
	pMyContactListener = new AngryContactListener();
	PhysicsMan::GetWorld()->GetWorld()->SetContactListener(pMyContactListener);

	pSimpleRCCB = new SimpleRayCastCallBack();
	pNinjaRCCB = new NinjaSwordCallback();

	pLauncher = new NinjaLauncher(1400.0f, 100.0f, 300.0f, PhysicsMan::GetWorld());
	Scoreboard::Setup(pLauncher);
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void Game::Update(float currentTime)
{
	// Time update.
	//      Get the time that has passed.
	//      Feels backwards, but its not, need to see how much time has passed
	stopWatch.toc();
	stopWatch.tic();
	totalWatch.toc();

	float elapsedTime = stopWatch.timeInSeconds();
	float totalTime = totalWatch.timeInSeconds();

	Scoreboard::Update(elapsedTime);

	// Update cameras - make sure everything is consistent
	Camera* pCam2D = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
	pCam2D->updateCamera();

	TimerMan::Update();

	ProcessInputs();
	NinjaAction(pNinjaRCCB, elapsedTime, totalTime);

	// -------------  Add your update below this line: ----------------------------

	PhysicsMan::Update(); //currentTime
	GameObjectMan::Update(currentTime);

	GameObjectMan::DeletePending();
}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Game::Draw()
{
	// draw all objects
	GameObjectMan::Draw();
	
}

//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Game::UnLoadContent()
{

	//GameObjectMan::Delete(GameObjectMan::Find(GameObjectName::Name::MainGroup));
	//GameObjectMan::Delete(GameObjectMan::Find(GameObjectName::Name::Effects));
	
	//delete pSlingshot;
	delete pSimpleRCCB;
	delete pNinjaRCCB;
	delete pLauncher;

	Visualizer::Terminate();

	// Engine clean-up
	CameraMan::Terminate();
	ModelMan::Terminate();
	ShaderMan::Terminate();
	TextureMan::Terminate();
	ImageMan::Terminate();

	GameObjectMan::Terminate();
	TimerMan::Terminate();

	delete pMyContactListener;
	PhysicsMan::Terminate();
}

//------------------------------------------------------------------
// Game::ClearBufferFunc()
// Allows user to change the way the clear buffer function works
//------------------------------------------------------------------
void Game::ClearBufferFunc()
{
	const GLfloat blue[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	const GLfloat one = 1.0f;

	glViewport(0, 0, info.windowWidth, info.windowHeight);
	glClearBufferfv(GL_COLOR, 0, blue);
	glClearBufferfv(GL_DEPTH, 0, &one);
}

void Game::LoadImages()
{
	// spritecow.com

	// Images
	/*ImageMan::addImage(ImageName::Stitch, TextName::Stitch, Rect(0, 0, 300, 410));
	ImageMan::addImage(ImageName::Alien_Green, TextName::Invaders, Rect(136, 64, 85, 63));
	ImageMan::addImage(ImageName::Alien_Blue, TextName::Invaders, Rect(370, 64, 62, 63));
	ImageMan::addImage(ImageName::Alien_Red, TextName::Invaders, Rect(559, 64, 93, 63));*/

	
	ImageMan::addImage(ImageName::Bird_Black_0, TextName::BirdPigsEffects, Rect(409, 725, 61, 81));
	ImageMan::addImage(ImageName::Bird_Black_1, TextName::BirdPigsEffects, Rect(777, 446, 61, 81));
	ImageMan::addImage(ImageName::Bird_Black_2, TextName::BirdPigsEffects, Rect(668, 679, 62, 71));
	ImageMan::addImage(ImageName::Bird_Black_3, TextName::BirdPigsEffects, Rect(714, 446, 61, 81));
	ImageMan::addImage(ImageName::Bird_Black_4, TextName::BirdPigsEffects, Rect(409, 808, 61, 81));
	ImageMan::addImage(ImageName::Bird_Black_5, TextName::BirdPigsEffects, Rect(588, 446, 61, 81));
	ImageMan::addImage(ImageName::Bird_Black_6, TextName::BirdPigsEffects, Rect(651, 446, 61, 81));

	
	// Pigs

	ImageMan::addImage(ImageName::Pig_Big_0, TextName::BirdPigsEffects, Rect(298, 357, 98, 97));
	ImageMan::addImage(ImageName::Pig_Big_1, TextName::BirdPigsEffects, Rect(298, 849, 99, 93));

	ImageMan::addImage(ImageName::Pig_Medium_0, TextName::BirdPigsEffects, Rect(929, 446, 78, 77));
	ImageMan::addImage(ImageName::Pig_Medium_1, TextName::BirdPigsEffects, Rect(409, 891, 79, 74));

	ImageMan::addImage(ImageName::Pig_Small_0, TextName::BirdPigsEffects, Rect(732, 856, 48, 46));
	ImageMan::addImage(ImageName::Pig_Small_1, TextName::BirdPigsEffects, Rect(986, 744, 48, 45));

	ImageMan::addImage(ImageName::Pig_King_0, TextName::BirdPigsEffects, Rect(41, 1, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_1, TextName::BirdPigsEffects, Rect(169, 1, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_2, TextName::BirdPigsEffects, Rect(297, 1, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_3, TextName::BirdPigsEffects, Rect(425, 1, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_4, TextName::BirdPigsEffects, Rect(41, 156, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_5, TextName::BirdPigsEffects, Rect(41, 311, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_6, TextName::BirdPigsEffects, Rect(41, 466, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_7, TextName::BirdPigsEffects, Rect(41, 621, 126, 153));
	ImageMan::addImage(ImageName::Pig_King_8, TextName::BirdPigsEffects, Rect(41, 776, 126, 153));


	// Effects

	ImageMan::addImage(ImageName::Bang, TextName::BirdPigsEffects, Rect(674, 354, 87, 89));
	ImageMan::addImage(ImageName::Null, TextName::BirdPigsEffects, Rect(0, 0, 0, 0));

	ImageMan::addImage(ImageName::Sling, TextName::BirdPigsEffects, Rect(839, 25, 18, 23));
	ImageMan::addImage(ImageName::Sling_Branch, TextName::BirdPigsEffects, Rect(830, 0, 47, 127));
	ImageMan::addImage(ImageName::Sling_Tree, TextName::BirdPigsEffects, Rect(0, 0, 40, 200));

	ImageMan::addImage(ImageName::BG_0, TextName::AngryBackground, Rect(0, 0, 1280, 1336));
}

void Game::CreateGameObjects()
{
	/*PhysicsObject2D* pPhysObj;
	PhysicsWorld* pWorld = PhysicsMan::GetWorld();*/

	GameObject2D* pGameObj;

	pGameObj = new GameObject2D(GameObjectName::Background, new GraphicsObject_Sprite(ImageName::BG_0, Rect(200, 250, 1280, 1336)));
	GameObjectMan::Add(pGameObj, GameObjectName::Background);

	pGameObj = new GameObject2D(GameObjectName::Background, new GraphicsObject_Sprite(ImageName::BG_0, Rect(200 + 1280, 250, 1280, 1336)));
	GameObjectMan::Add(pGameObj, GameObjectName::Background);
}

void Game::ProcessInputs()
{
	//-----------------------------------------------------------
	// Keyboard reading
	//-----------------------------------------------------------

	static bool onePressed = false;
	static bool twoPressed = false;

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_1))
	{
		if (!onePressed && !twoPressed)
		{
			pLauncher->StartLaunching(NinjaLauncher::Difficulty::NORMAL);
			Scoreboard::Start();
		}
		onePressed = true;
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_2))
	{
		if (!twoPressed && !onePressed)
		{
			pLauncher->StartLaunching(NinjaLauncher::Difficulty::HARD);
			Scoreboard::Start();
		}
		twoPressed = true;
	}
}

float Game::GetFrameTime()
{
	return Instance().stopWatch.timeInSeconds();
}

float Game::GetTotalTime()
{
	return Instance().totalWatch.timeInSeconds();
}

Game::~Game()
{
	//delete pWorld;
}

void Game::Run(const char* windowName, const int Width, const int Height)
{
	ptrInstance = new Game(windowName, Width, Height);
	ptrInstance->run();
	delete ptrInstance;
}
