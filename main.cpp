// Basic inclusions
#include <ncurses.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
// Needed for ubuntu:
#include <string.h>
#include <unistd.h>

// These includes hold variables required for the map inclusions
#include "items.h"
#include "chests.h"
#include "actor.h"
#include "stairs.h"
#include "map_class.h"
#include "maps.h"
#include "window_layouts.h"
#include "character.h"
#include "equipment.h"
#include "map_tiles.h"

// Map Inclusions
#include "map_brecconary.h"
#include "map_cantlin.h"
#include "map_charlock_castle.h"
#include "map_erdricks_cave.h"
#include "map_garinham.h"
#include "map_hauksness.h"
#include "map_kol.h"
#include "map_northern_shrine.h"
#include "map_rimuldar.h"
#include "map_rock_mountain_cave.h"
#include "map_southern_shrine.h"
#include "map_swamp_cave.h"
#include "map_tantegel.h"
#include "map_world.h"

// Global Map Dimensions
// As a note, don't confuse the "Global Map" with the "Overworld Map"
// Global map is loaded with the map of the current location
const int cnGlobalMapWidth	= 148;
const int cnGlobalMapHeight	= 166;

// Camera map dimensions
const int cnCameraMapWidth = 29;
const int cnCameraMapHeight = 15;

const int cnCameraMapOffsetX = 12;
const int cnCameraMapOffsetY = 1;

// Initializer for the cPlayer class.  This provides the starting stats for the player
// and any player characters.  I might be fudging this a bit to load stats I don't 
// ultimately intend to start the player/player character with for testing purposes
cPlayer::cPlayer(void)
{
	this->nGold = 1000;
	for(int i = 1; i < cnInventorySlots; i++)
	{
		this->nInventory[i][cnItemSlot] = cnItemNone;
		this->nInventory[i][cnItemCount] = 0;
	}
	this->nProgress = 0;
	this->nTargetMap = cnMapTantegel;
	this->nTargetMapHeight = 0;
	this->nTargetMapWidth = 0;
	this->nTargetX = 2;
	this->nTargetY = 47;
	this->nTargetActors = 0;
	this->nTargetActorList = NULL;
	this->nTargetChests = 0;
	this->nTargetChestList = NULL;
	this->bTransition = false;
	this->nLightRadius = 0;
	this->bInCave = false;
	this->bPrincessSaved = false;
	this->bRainbowDrop = false;
	this->bLetsPlay = true;
	this->nOutsideY = 43;
	this->nOutsideX = 43;

	// Use this to load an inventory slot if we need to for testing
	this->nInventory[0][cnItemSlot] = cnItemKey;
	this->nInventory[0][cnItemCount] = 2;

	this->sHero.p_szName[0] = 'H';
	this->sHero.p_szName[1] = 'e';
	this->sHero.p_szName[2] = 'r';
	this->sHero.p_szName[3] = 'o';
	this->sHero.nLevel = 1;
	this->sHero.nExperience = 0;
	this->sHero.nHealthMax = 14;
	this->sHero.nHealthCurrent = 14;
	this->sHero.nMagicMax = 0;
	this->sHero.nMagicCurrent = 0;
	this->sHero.nStrength = 4;
	this->sHero.nAgility = 4;
	this->sHero.nAttack = 4;
	this->sHero.nDefense = 2;
	this->sHero.nWeapon = 0;
	this->sHero.nArmor = 0;
	this->sHero.nShield = 0;
	this->sHero.nPositionX = 14;
	this->sHero.nPositionY = 7;
}

cPlayer::~cPlayer(void)
{
	// Destruct!
	// Honestly, I don't really know what I should be putting here.  Apparently we leak memory
	// if we don't properly clean up after ourselves, but I don't really know how to do that
	// right now.  Hopefully I figure that out at some point.
}

cChest::cChest(void)
{
	this->nItemType = 0;
	this->nGoldMin = 0;
	this->nGoldMax = 0;
}

cChest * p_cChestList[cnMaxChests];

cChest::~cChest(void)
{
	// destruct
	// who knows if I'm even doing this correctly...
	for( int i = 0; i < cnMaxChests; i++ )
	{
		delete p_cChestList[i];
	}
}

cActor::cActor(void)
{
	this->bExists = false;			
	this->nInitialPositionX = 0;	
	this->nInitialPositionY = 0; 	
	this->nPositionX = 0;			
	this->nPositionY = 0;			
	this->nMovementPattern = 0;						
	this->bIsMerchant = false;		
	this->nConversation = 0;
	this->nCostume = 0;
}

cActor * p_cActorList[cnMaxActors];

cActor::~cActor(void)
{
	// destruct
	// who knows if I'm even doing this correctly...
	for( int i = 0; i < cnMaxActors; i++ )
	{
		delete p_cActorList[i];
	}
}

cMap::cMap()
{

}

cMap::~cMap()
{

}

int *nTargetMap;
int nTargetMapHeight;
int nTargetMapWidth;
int nTargetActors;
int *nTargetActorList;
int nTargetChests;
int *nTargetChestList;
int nTargetStairs;
int *nTargetStairList;

//////////////////////
// Global variables //
//////////////////////
std::vector<std::vector<int> > nGlobalMapArray(cnGlobalMapHeight, std::vector<int> (cnGlobalMapWidth, 0));		// 2d vector for the global map
std::vector<std::vector<int> > nGlobalItemArray(cnGlobalMapHeight, std::vector<int> (cnGlobalMapWidth, 0));		// 2d vector for the global item map
std::vector<std::vector<int> > nCameraMapArray(cnCameraMapHeight, std::vector<int> (cnCameraMapWidth, 0));		// 2d vector for the camera map

cMap * p_cMapList[cnMaps];

// int nGlobalMapArray[cnGlobalMapHeight][cnGlobalMapWidth]; 	// Array for the global map
// int nGlobalItemArray[cnGlobalMapHeight][cnGlobalMapWidth];	// Array for the global item map
// int nCameraMapArray[cnCameraMapHeight][cnCameraMapWidth]; 	// Array for the camera map
// I thought about keeping the camera X and Y coordinates
// local and just passing them from function to function,
// but I started passing these variables a lot, so I just
// made them global to make it easier.
int nCameraX;
int nCameraY;

////////////////////////
// Function Prototypes//
////////////////////////

bool IsPassible( WINDOW *wCamera, int x, int y, TILE_TYPE sTileIndex[], cPlayer *Player);
void ChangeMap( WINDOW *wCamera, TILE_TYPE sTileIndex[], cPlayer *Player, int nTileValue);
void TeleportPlayer( cPlayer *Player, int nTileValue );
bool ActorObstruction( int y, int x, cPlayer *Player );
void UpdateActor( cActor *CurrentActor, TILE_TYPE sTileIndex[], cPlayer *Player, WINDOW *wCamera);
void LoadMap(WINDOW *wCamera, TILE_TYPE sTileIndex[], cPlayer *Player);
void LoadActors(cPlayer *Player);
void LoadChests(cPlayer *Player);
void DrawMap(WINDOW *wCamera, TILE_TYPE sTileIndex[], cPlayer *Player);
void DrawTile(WINDOW *wCamera, int x, int y, TILE_TYPE sTileIndex[], cPlayer *Player);
void Transition(WINDOW *wCamera, TILE_TYPE sTileIndex[], cPlayer *Player);
void DrawWindow(WINDOW *wCurrentWindow, int nWindowHeight, int nWindowWidth);
void ClearWindow(WINDOW *wCurrentWindow, int nWindowHeight, int nWindowWidth);
bool DrawYesNo(WINDOW *wYesNo);
void DrawExitWindow(WINDOW *wConfirmExit);
bool ConfirmExit(WINDOW *wCommand);
void DrawStats(WINDOW *wStats, cPlayer *Player);
void DrawCommandWindow(WINDOW *wCommand);
void EnterCommand(WINDOW *wCommand, WINDOW *wInventory, WINDOW *wAlert, WINDOW *wStatus, WINDOW *wYesNo, WINDOW *wCamera, WINDOW *wStats, TILE_TYPE sTileIndex[], cPlayer *Player, cChest *cCurrentChest);
void Talk(WINDOW *wAlert, WINDOW *wYesNo, WINDOW *wStats, cPlayer *Player);
void PlayerStatus(WINDOW *wStatus, cPlayer *Player);
void UseStairs(WINDOW *wCamera, WINDOW *wAlert, TILE_TYPE sTileIndex[], cPlayer *Player);
void SearchGround(WINDOW *wAlert, cPlayer *Player);
void DrawItemMenu(WINDOW *wCamera, WINDOW *wInventory, WINDOW *wAlert, TILE_TYPE sTileIndex[], cPlayer *Player);
void OpenDoor(WINDOW *wAlert, cPlayer *Player);
void TakeChest(WINDOW *wAlert, cPlayer *Player, cChest *cCurrentChest);
bool AvailableInventorySlot(WINDOW *wAlert, int nItemToAdd, cPlayer *Player);
void AddItem(cPlayer *Player, int nItemToAdd);
void RemoveItem(int nInventorySlot, cPlayer *Player);
void UseHerb(WINDOW *wAlert, int nInventorySlot, cPlayer *Player);
void UseKey(WINDOW *wAlert, int nInventorySlot, cPlayer *Player);
void UseRainbowDrop(WINDOW *wCamera, WINDOW *wAlert, TILE_TYPE sTileIndex[], int nInventorySlot, cPlayer *Player);
void InitializeMaps();
void LoadBrecconaryMap();
void LoadCantlin();
void LoadCharlockCastle();
void LoadErdricksCave();
void LoadGarinham();
void LoadHauksness();
void LoadKol();
void LoadNorthernShrine();
void LoadRimuldar();
void LoadRockMountainCave();
void LoadSouthernShrine();
void LoadSwampCave();
void LoadTantegelMap();
void LoadWorldMap();


////////////////////////////////////////////
// Nothing but functions from here on out //
////////////////////////////////////////////
int main(void)
{
	initscr();                              // Initialize ncurses functions
	start_color();							// Enable color
	curs_set(0);                            // turn off the cursor (make it invisible)
	noecho();                               // Don't print user input to the screen
	cbreak();                               // Turn off keyboard buffering so we can get whole key input for keys
                                            // with escape sequences such as arrow keys
	//raw();								// Ooh, same as cbreak, but super raw!  Will likely use this once I'm no longer
											// worried about getting stuck in my own game.

	// initialize our RNG
	srand(time(NULL));

	// Setup our windows
	WINDOW *wCameraFrame = newwin(cnCameraFrameHeight, cnCameraFrameWidth, cnCameraFrameOffsetY, cnCameraFrameOffsetX);
	WINDOW *wCamera = newwin(cnCameraMapHeight, cnCameraMapWidth, cnCameraMapOffsetY, cnCameraMapOffsetX);
	WINDOW *wStats = newwin(cnStatsWindowHeight, cnStatsWindowWidth, cnStatsOffsetY, cnStatsOffsetX);
	WINDOW *wCommand = newwin(cnCommandWindowHeight, cnCommandWindowWidth, cnCommandOffsetY, cnCommandOffsetX);
	WINDOW *wConfirmExit = newwin(cnExitWindowHeight, cnExitWindowWidth, cnExitOffsetY, cnExitOffsetX);
	WINDOW *wInventory = newwin(cnInventoryWindowHeight, cnInventoryWindowWidth, cnInventoryOffsetY, cnInventoryOffsetX);
	WINDOW *wAlert = newwin(cnAlertWindowHeight, cnAlertWindowWidth, cnAlertOffsetY, cnAlertOffsetX);
	WINDOW *wStatus = newwin(cnStatusWindowHeight, cnStatusWindowWidth, cnStatusOffsetY, cnStatusOffsetX);
	WINDOW *wYesNo = newwin(cnYesNoWindowHeight, cnYesNoWindowWidth, cnYesNoOffsetY, cnYesNoOffsetX);

	// Use better keyboard input for arrow keys, etc.
	keypad(stdscr, TRUE);                   
	keypad(wCamera, TRUE);
	keypad(wCommand, TRUE);
	keypad(wConfirmExit, TRUE);
	keypad(wInventory, TRUE);
	keypad(wAlert, TRUE);
	keypad(wYesNo, TRUE);

	// Create color pairs for the map
	init_pair(1, COLOR_WHITE, COLOR_BLACK);		// rock color
	init_pair(2, COLOR_GREEN, COLOR_BLACK);		// grass color
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);	// Player color
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);	// Available
	init_pair(5, COLOR_WHITE, COLOR_BLUE);		// Water
	init_pair(6, COLOR_RED, COLOR_BLACK);		// Brick
	init_pair(7, COLOR_YELLOW, COLOR_BLACK);	// Sand
	init_pair(8, COLOR_GREEN, COLOR_YELLOW);	// Desk
	init_pair(9, COLOR_BLACK, COLOR_YELLOW);	// Shop Sign
	init_pair(10, COLOR_BLUE, COLOR_WHITE);		// Bridge colors
	init_pair(11, COLOR_RED, COLOR_YELLOW);		// Chest Color
	init_pair(12, COLOR_RED, COLOR_WHITE);		// King color
	init_pair(13, COLOR_BLUE, COLOR_GREEN);		// Barrier color
	init_pair(14, COLOR_GREEN, COLOR_BLUE);		// Swamp color
	init_pair(15, COLOR_BLUE, COLOR_BLACK);		// Blue villager color
	init_pair(16, COLOR_WHITE, COLOR_RED);
	init_pair(17, COLOR_MAGENTA, COLOR_WHITE);	// Dragonlord color

	// Load the tiles to be used when drawing the camera map
	// Additional info can be found in map_tiles.h
	// Fields are: 
	// 0 - Tile character (nCharacter)
	// 1 - Tile color (nColorPair)
	// 2 - Is this tile Passible (bPassible)
	// 3 - Does this tile cause you to teleport on the current map (bTeleport)
	// 4 - Does this tile cause a new map to load (bChangeMap)
	TILE_TYPE sTileIndex[] = {
<<<<<<< HEAD
		{ ' ' , 1, false, false, false, nullptr, 0, 0 },					// (0) cnTileBlank
		{ ACS_CKBOARD, 6, true, false, false, nullptr, 0, 0 },				// (1) cnTileBrickFloor
		{ '#', 1, false, false, false, nullptr, 0, 0 },						// (2) cnTileRockWall
		{ '.', 2, true, false, false, nullptr, 0, 0 },						// (3) cnTileGrass	
		{ '#', 2, true, false, false, nullptr, 0, 0 }, 						// (4) cnTileTree
		{ '~', 5, false, false, false, nullptr, 0, 0 },						// (5) cnTileWater
		{ ACS_CKBOARD, 7, true, false, false, nullptr, 0, 0 },				// (6) cnTileSand
		{ ACS_CKBOARD, 14, true, false, false, nullptr, 0, 0 },				// (7) cnTileSwamp
		{ '/', 13, true, false, false, nullptr, 0, 0 },						// (8) cnTileBarrier
		{ ACS_CKBOARD, 1, false, false, false, nullptr, 0, 0 },				// (9) cnTileRoof		
		{ '+', 1, false, false, false, nullptr, 0, 0 }, 					// (10) cnTileDoor
		{ 'O', 8, false, false, false, nullptr, 0, 0 },						// (11) cnTileWoodDesk
		{ '$', 9, false, false, false, nullptr, 0, 0 },						// (12) cnTileSignShop
		{ 'N', 9, false, false, false, nullptr, 0, 0 },						// (13) cnTileSignInn
		{ '=', 10, true, false, false, nullptr, 0, 0 },						// (14) cnTileBridge
		{ '<', 1, true, false, false, nullptr, 0, 0 }, 						// (15) cnTileStairUp
		{ '>', 1, true, false, false, nullptr, 0, 0 },						// (16) cnTileStairDown
		{ '.', 2, false, false, true, *nWorldMapArray, 0, 0 },			// (17) cnTileGrassExit
		{ ACS_CKBOARD, 7, false, false, true, *nWorldMapArray, 0, 0 },	// (18) cnTileSandExit
		{ ACS_CKBOARD, 14, false, false, true, *nWorldMapArray, 0, 0 },	// (19) cnTileSwampExit
		{ 'X', 6, false, false, false, nullptr, 0, 0 },						// (20) ** AVAILABLE TILE SLOT **
		{ 'X', 6, false, false, false, nullptr, 0, 0 },						// (21) ** AVAILABLE TILE SLOT **
		{ 'n', 7, true, false, false, nullptr, 0, 0 },						// (22) cnTileHill
		{ 'M', 1, false, false, false, nullptr, 0, 0 },						// (23) cnTileMountain
		{ ACS_PI, 1, true, false, true, *nGarinhamMapArray, 14, 0 },		// (24) cnTileGarinham
		{ ACS_PI, 1, true, false, true, *nKolMapArray, 23, 19 },			// (25) cnTileKol
		{ 'C', 1, true, false, true, *nErdricksCaveMapArray, 0, 0 },		// (26) cnTileErdricksCave
		{ ACS_PI, 1, true, false, true, *nBrecconaryMapArray, 15, 0 },		// (27) cnTileBrecconary
		{ 'A', 1, true, false, true, *nTantegelMapArray, 29, 10 }, 			// (28) cnTileTantegel
		{ 'C', 1, true, false, true, *nSwampCaveMapArray, 0, 0 }, 			// (29) cnTileSwampCave1
		{ 'A', 1, true, false, true, *nCharlockCastleMapArray, 19, 9 }, 	// (30) cnTileCharlock
		{ 'C', 1, true, false, true, *nSwampCaveMapArray, 29, 0 }, 			// (31) cnTileSwampCave2
		{ 'C', 1, true, false, true, *nRockMountainCaveMapArray, 7, 0 },	// (32) cnTileRockMountainCave
		{ ACS_PI, 1, true, false, true, *nRimuldarMapArray, 14, 29 },		// (33) cnTileRimuldar
		{ ACS_PI, 1, true, false, true, *nHauksnessMapArray, 10, 0 },		// (34) cnTileHauksness
		{ ACS_PI, 1, true, false, true, *nCantlinMapArray, 0, 15 },			// (35) cnTileCantlin
		{ '#', 2, false, false, true, *nWorldMapArray, 0, 0 },			// (36) cnTileTreeExit
		{ 'X', 6, false, false, false, nullptr, 0, 0 },						// (37) ** AVAILABLE TILE SLOT **
		{ 'X', 6, false, false, false, nullptr, 0, 0 },						// (38) ** AVAILABLE TILE SLOT **
		{ 'X', 6, false, false, false, nullptr, 0, 0 },						// (39) ** AVAILABLE TILE SLOT **
		{ 'X', 6, false, false, false, nullptr, 0, 0 },						// (40) ** AVAILABLE TILE SLOT **
		{ 'X', 6, false, false, false, nullptr, 0, 0 },						// (41) ** AVAILABLE TILE SLOT **
		{ 'X', 6, false, false, false, nullptr, 0, 0 },						// (42) ** AVAILABLE TILE SLOT **
		{ ACS_CKBOARD, 6, false, false, true, *nWorldMapArray, 0, 0 },	// (43) cnTileBrickExit
		{ ACS_CKBOARD, 1, true, true, false, nullptr, 0, 0 },				// (44) cnTileHouseIn
		{ ' ', 1, true, true, false, nullptr, 0, 0 }						// (45) cnTileHouseOut
=======
		{ ' ' , 1, false, false, false, cnMapNone, 0, 0 },					// (0) cnTileBlank
		{ ACS_CKBOARD, 6, true, false, false, cnMapNone, 0, 0 },				// (1) cnTileBrickFloor
		{ '#', 1, false, false, false, cnMapNone, 0, 0 },						// (2) cnTileRockWall
		{ '.', 2, true, false, false, cnMapNone, 0, 0 },						// (3) cnTileGrass	
		{ '#', 2, true, false, false, cnMapNone, 0, 0 }, 						// (4) cnTileTree
		{ '~', 5, false, false, false, cnMapNone, 0, 0 },						// (5) cnTileWater
		{ ACS_CKBOARD, 7, true, false, false, cnMapNone, 0, 0 },				// (6) cnTileSand
		{ ACS_CKBOARD, 14, true, false, false, cnMapNone, 0, 0 },				// (7) cnTileSwamp
		{ '/', 13, true, false, false, cnMapNone, 0, 0 },						// (8) cnTileBarrier
		{ ACS_CKBOARD, 1, false, false, false, cnMapNone, 0, 0 },				// (9) cnTileRoof		
		{ '+', 1, false, false, false, cnMapNone, 0, 0 }, 					// (10) cnTileDoor
		{ 'O', 8, false, false, false, cnMapNone, 0, 0 },						// (11) cnTileWoodDesk
		{ '$', 9, false, false, false, cnMapNone, 0, 0 },						// (12) cnTileSignShop
		{ 'N', 9, false, false, false, cnMapNone, 0, 0 },						// (13) cnTileSignInn
		{ '=', 10, true, false, false, cnMapNone, 0, 0 },						// (14) cnTileBridge
		{ '<', 1, true, false, false, cnMapNone, 0, 0 }, 						// (15) cnTileStairUp
		{ '>', 1, true, false, false, cnMapNone, 0, 0 },						// (16) cnTileStairDown
		{ '.', 2, false, false, true, cnMapWorld, 0, 0 },					// (17) cnTileGrassExit
		{ ACS_CKBOARD, 7, false, false, true, cnMapWorld, 0, 0 },			// (18) cnTileSandExit
		{ ACS_CKBOARD, 14, false, false, true, cnMapWorld, 0, 0 },			// (19) cnTileSwampExit
		{ 'X', 6, false, false, false, cnMapNone, 0, 0 },						// (20) ** AVAILABLE TILE SLOT **
		{ 'X', 6, false, false, false, cnMapNone, 0, 0 },						// (21) ** AVAILABLE TILE SLOT **
		{ 'n', 7, true, false, false, cnMapNone, 0, 0 },						// (22) cnTileHill
		{ 'M', 1, false, false, false, cnMapNone, 0, 0 },						// (23) cnTileMountain
		{ ACS_PI, 1, true, false, true, cnMapGarinham, 14, 0 },				// (24) cnTileGarinham
		{ ACS_PI, 1, true, false, true, cnMapKol, 23, 19 },					// (25) cnTileKol
		{ 'C', 1, true, false, true, cnMapErdricksCave, 0, 0 },				// (26) cnTileErdricksCave
		{ ACS_PI, 1, true, false, true, cnMapBrecconary, 15, 0 },			// (27) cnTileBrecconary
		{ 'A', 1, true, false, true, cnMapTantegel, 29, 10 }, 				// (28) cnTileTantegel
		{ 'C', 1, true, false, true, cnMapSwampCave, 0, 0 }, 				// (29) cnTileSwampCave1
		{ 'A', 1, true, false, true, cnMapCharlockCastle, 19, 9 }, 			// (30) cnTileCharlock
		{ 'C', 1, true, false, true, cnMapSwampCave, 29, 0 }, 				// (31) cnTileSwampCave2
		{ 'C', 1, true, false, true, cnMapRockMountainCave, 7, 0 },			// (32) cnTileRockMountainCave
		{ ACS_PI, 1, true, false, true, cnMapRimuldar, 14, 29 },			// (33) cnTileRimuldar
		{ ACS_PI, 1, true, false, true, cnMapHauksness, 10, 0 },			// (34) cnTileHauksness
		{ ACS_PI, 1, true, false, true, cnMapCantlin, 0, 15 },				// (35) cnTileCantlin
		{ '#', 2, false, false, true, cnMapWorld, 0, 0 },					// (36) cnTileTreeExit
		{ 'X', 6, false, false, false, cnMapNone, 0, 0 },						// (37) ** AVAILABLE TILE SLOT **
		{ 'X', 6, false, false, false, cnMapNone, 0, 0 },						// (38) ** AVAILABLE TILE SLOT **
		{ 'X', 6, false, false, false, cnMapNone, 0, 0 },						// (39) ** AVAILABLE TILE SLOT **
		{ 'X', 6, false, false, false, cnMapNone, 0, 0 },						// (40) ** AVAILABLE TILE SLOT **
		{ 'X', 6, false, false, false, cnMapNone, 0, 0 },						// (41) ** AVAILABLE TILE SLOT **
		{ 'X', 6, false, false, false, cnMapNone, 0, 0 },						// (42) ** AVAILABLE TILE SLOT **
		{ ACS_CKBOARD, 6, false, false, true, cnMapWorld, 0, 0 },			// (43) cnTileBrickExit
		{ ACS_CKBOARD, 1, true, true, false, cnMapNone, 0, 0 },				// (44) cnTileHouseIn
		{ ' ', 1, true, true, false, cnMapNone, 0, 0 }						// (45) cnTileHouseOut
>>>>>>> Create-map-class
	};

	int nDeltaX, nDeltaY;			// This is used for storing player movement

	// Create our player object
	cPlayer Player;

	InitializeMaps();

	// Create our chest objects
	for(int i = 0; i < cnMaxChests; i++)
	{
		cChest *p_cNewChest = new cChest();
		p_cChestList[i] = p_cNewChest;
	}

	for(int i = 0; i < cnMaxActors; i++)
	{
		cActor *p_cNewActor = new cActor();
		p_cActorList[i] = p_cNewActor;
	}

	int sKeyPress;

	int nTileItem;

	Player.nTargetMap = cnMapTantegel;

	// I added the Transition() function in order to make loading a new location prettier,
	// (well, less jarring anyway,) but loading the map before the rest of the screen made 
	// the game seem slow, so let's load the other windows first.
	DrawWindow(wCameraFrame, cnCameraFrameHeight, cnCameraFrameWidth);
	DrawStats(wStats, &Player);
	DrawCommandWindow(wCommand);

	// Load initial map
	// ...TODO... Use a title screen, currently loading directly to the throne room.
	// ...TODO... Implement save/load system.  Currently we're starting over from scratch every time.
	LoadMap(wCamera, sTileIndex, &Player);

	// Main game loop
	while(Player.bLetsPlay)
	{
		// copy portion of global map to camera map
		for(int y=0; y<cnCameraMapHeight; y++)
		{
			for(int x=0; x<cnCameraMapWidth; x++)
			{
				nCameraMapArray[y][x] = nGlobalMapArray[y+nCameraY][x+nCameraX];
			}
		}

		// TODO: Remove DrawStats when we start to add events that actually affect the stats window
		DrawMap(wCamera, sTileIndex, &Player);	// Jump to the DrawMap routine to draw the camera window
		DrawStats(wStats, &Player);			// Jump to the DrawStats routine to draw the stats window

		mvwaddch(wCamera, Player.sHero.nPositionY,Player.sHero.nPositionX,'@' | A_BOLD | COLOR_PAIR(3));

		sKeyPress = wgetch(wCamera);

		nDeltaX = 0;
		nDeltaY = 0;

		nTileItem = nGlobalItemArray[Player.sHero.nPositionY+nCameraY][Player.sHero.nPositionX+nCameraX];

		// Process the input
		switch(sKeyPress)
		{
			case KEY_UP:
				nDeltaY = -1;
				break;
			case KEY_DOWN:
				nDeltaY = 1;
				break;
			case KEY_LEFT:
				nDeltaX = -1;
				break;
			case KEY_RIGHT:
				nDeltaX = 1;
				break;
			case 'x':
				EnterCommand(wCommand, wInventory, wAlert, wStatus, wYesNo, wCamera, wStats, sTileIndex, &Player, p_cChestList[nTileItem]);
				break;
			case 'q':
				if(ConfirmExit(wConfirmExit))
					Player.bLetsPlay = false;
				break;	
			default:
				break;

		}

		// Check and see if we're allowed to move in the direction specified
		if( nDeltaY + nDeltaX !=0 && IsPassible( wCamera, Player.sHero.nPositionX+nDeltaX, Player.sHero.nPositionY+nDeltaY, sTileIndex, &Player))
		{
			// If allowed, move in the direction specified
			nCameraX += nDeltaX;
			nCameraY += nDeltaY;
		}

		// Let's update the actors at this point
		for( int i = 0; i < Player.nTargetActors; i++ )
		{
			if( nDeltaY + nDeltaX !=0 && p_cActorList[i]->bExists && p_cActorList[i]->nMovementPattern > 0)
			{
				UpdateActor(p_cActorList[i], sTileIndex, &Player, wCamera);
			}
		}
	}

	// Shutdown program
	delwin(wCameraFrame);
	delwin(wCamera);
	delwin(wStats);
	delwin(wCommand);
	delwin(wConfirmExit);
	delwin(wInventory);
	delwin(wAlert);
	delwin(wStatus);
	delwin(wYesNo);
	endwin();
	return 0;
}

bool IsPassible( WINDOW *wCamera, int x, int y, TILE_TYPE sTileIndex[], cPlayer *Player)
{
	// This function is designed to determine if the player character
	// can move to where the player told us to move

	// Store the value of the tile specified
	int nTileValue = nCameraMapArray[y][x];

	if(sTileIndex[nTileValue].bChangeMap)
	{
		// If we're trying to step on a tile that brings us to a new map, change maps
		if(Player->nTargetMap == cnMapWorld)
		{
			// Set some coordinate to return to when we leave the city
			Player->nOutsideY = nCameraY + (y - Player->sHero.nPositionY);
			Player->nOutsideX = nCameraX + (x - Player->sHero.nPositionX);
		}
		Player->nTargetMap = sTileIndex[nTileValue].nTargetMap;
		Player->nTargetY = sTileIndex[nTileValue].nTargetY;
		Player->nTargetX = sTileIndex[nTileValue].nTargetX;
		ChangeMap(wCamera, sTileIndex, Player, nTileValue);
		return false;

	} else if(sTileIndex[nTileValue].bTeleport)
	{
		// If we're trying to step on a tile that teleports us elsewhere on the map, teleport
		TeleportPlayer(Player, nTileValue);
	}

	// Lets check to see if there's someone standing in our way
	if(ActorObstruction(y + nCameraY, x + nCameraX, Player))
		return false;

	// Otherwise, Return true if it's passible
	return sTileIndex[nTileValue].bPassible;

	// If execution gets here, it's not passible
	// We shouldn't be getting here though
	return false;
}

void ChangeMap( WINDOW *wCamera, TILE_TYPE sTileIndex[], cPlayer *Player, int nTileValue )
{
	if( Player->nTargetMap == cnMapWorld )
	{
		Player->nTargetY = Player->nOutsideY;
		Player->nTargetX = Player->nOutsideX;
	}

	// Actually load the map data
	LoadMap(wCamera, sTileIndex, Player);
	return;
}

void TeleportPlayer(cPlayer *Player, int nTileValue)
{
	// This function teleports the player on the current map if they've either hit one of the house tiles, or used the stairs

	int nPlayerX = nCameraX + Player->sHero.nPositionX;
	int nPlayerY = nCameraY + Player->sHero.nPositionY;

	if(nTileValue == cnTileHouseIn)
	{
		nCameraY += 44;
	} else if(nTileValue == cnTileHouseOut)
	{
		nCameraY -= 44;
	}

	return;
}

bool ActorObstruction( int y, int x, cPlayer *Player )
{
	for( int i = 0; i < Player->nTargetActors; i++)
	{
		if( p_cActorList[i]->bExists && p_cActorList[i]->nPositionY == y && p_cActorList[i]->nPositionX == x )
			return true;
	}
	return false;
}

void UpdateActor( cActor *CurrentActor, TILE_TYPE sTileIndex[], cPlayer *Player, WINDOW *wCamera)
{
	// I was originally going to use the IsPassible() function for moving the actor, but because of
	// the way I'd built some of the other functions, this was no longer easily possible, so this
	// function basically just tries to move the actor and checks to see if the actor is allowed to move
	// there in a stripped down way.

	// Generate a new set of deltas for this actor
	int nDeltaX = 0;
	int nDeltaY = 0;

	switch(rand() % 5)
	{
		case 0:
			// Actor wants to move left
			nDeltaX = -1;
			break;
		case 1:
			// Actor wants to move right
			nDeltaX = 1;
			break;
		case 2:
			// Actor wants to move up
			nDeltaY = -1;
			break;
		case 3:
			// Actor wants to move down
			nDeltaY = 1;
			break;
		default:
			// Actor doesn't want to move
			break;
	}

	int x = CurrentActor->nPositionX + nDeltaX;
	int y = CurrentActor->nPositionY + nDeltaY;

	int nTileValue = nGlobalMapArray[y][x];

	// If the target tile isn't passible, we won't move
	if( !sTileIndex[nTileValue].bPassible || nTileValue == cnTileSwamp || nTileValue == cnTileBarrier )
	{
		return;
	}

	int nMovementX = std::abs(x - CurrentActor->nInitialPositionX);
	int nMovementY = std::abs(y - CurrentActor->nInitialPositionY);

	// If the target tile is outside the actor's allowable movement area, we won't move
	if( nMovementX > CurrentActor->nMovementPattern || nMovementY > CurrentActor->nMovementPattern)
	{
		return;
	}

	// If the actor is trying to step on another actor, we won't move
	if(ActorObstruction(y, x, Player))
		return;

	// If the actor is trying to step on the player, we won't move
	if( x == nCameraX+Player->sHero.nPositionX && y == nCameraY+Player->sHero.nPositionY )
	{
		return;
	}

	// If we made it this far, it's OK for the actor to move.
	CurrentActor->nPositionX += nDeltaX;
	CurrentActor->nPositionY += nDeltaY;

	return;

}

void LoadMap(WINDOW *wCamera, TILE_TYPE sTileIndex[], cPlayer *Player)
{
	// First, let's load the appropriate map data to the global map array
	int nTargetMap = Player->nTargetMap;
	for(int y=0; y < p_cMapList[nTargetMap]->nMapHeight; y++)
	{
		for(int x=0; x < p_cMapList[nTargetMap]->nMapWidth; x++)
		{
			nGlobalMapArray[y][x] = p_cMapList[nTargetMap]->nMapLayout[y][x];
		}
	}

	// Next, let's reposition the camera to the correct location
	nCameraX = Player->nTargetX;
	nCameraY = Player->nTargetY;

	// OK, we'll do one more thing, let's make sure any light source is extinguished
	Player->nLightRadius = 0;

	LoadActors(Player);
	LoadChests(Player);
	Transition(wCamera, sTileIndex, Player);

	return;
}

void LoadActors(cPlayer *Player){
	// Actor handling for when we change maps
	int nTargetMap = Player->nTargetMap;

	for(int i = 0; i < cnMaxActors; i++)
	{
		// If we're trying to load info about an actor that doesn't exist on the map, set it to not exist
		if(p_cMapList[nTargetMap]->nActors < i-1)
		{
			p_cActorList[i]->bExists = false;
		// Otherwise, load the info about the actor into the appropriate actor
		} else {
			p_cActorList[i]->bExists = p_cMapList[nTargetMap]->sActorList[i].bExists;
			p_cActorList[i]->nCostume = p_cMapList[nTargetMap]->sActorList[i].nCostume;
			p_cActorList[i]->nInitialPositionY = p_cMapList[nTargetMap]->sActorList[i].nInitialPositionY;
			p_cActorList[i]->nPositionY = p_cMapList[nTargetMap]->sActorList[i].nPositionY;
			p_cActorList[i]->nInitialPositionX = p_cMapList[nTargetMap]->sActorList[i].nInitialPositionX;
			p_cActorList[i]->nPositionX = p_cMapList[nTargetMap]->sActorList[i].nPositionX;
			p_cActorList[i]->nMovementPattern = p_cMapList[nTargetMap]->sActorList[i].nMovementPattern;
			p_cActorList[i]->bIsMerchant = p_cMapList[nTargetMap]->sActorList[i].bIsMerchant;
			p_cActorList[i]->nConversation = p_cMapList[nTargetMap]->sActorList[i].nConversation;
		}
	}
	return;
}

void LoadChests(cPlayer *Player)
{
	// Last but not least, let's load chest/item data
	// First, we should probably wipe existing chests/items from the map
	nGlobalItemArray.resize(cnGlobalMapHeight, std::vector<int>(cnGlobalMapWidth, 0));
	
	// Now let's load the chest data to the appropriate chest object

	int nTargetMap = Player->nTargetMap;

	for(int i = 0; i < cnMaxChests; i++)
	{
		// If we're trying to load info about an Chest that doesn't exist on the map, set it to not exist
		if(i >= Player->nTargetChests)
		{
			p_cChestList[i]->nItemType = 0;
			p_cChestList[i]->nGoldMin = 0;
			p_cChestList[i]->nGoldMax = 0;
			p_cChestList[i]->nPositionY = 0;
			p_cChestList[i]->nPositionX = 0;
		// Otherwise, load the info about the Chest into the appropriate Chest
		} else {
			p_cChestList[i]->nItemType = p_cMapList[nTargetMap]->sChestList[i].nItemType;
			p_cChestList[i]->nGoldMin = p_cMapList[nTargetMap]->sChestList[i].nGoldMin;
			p_cChestList[i]->nGoldMax = p_cMapList[nTargetMap]->sChestList[i].nGoldMax;
			p_cChestList[i]->nPositionY = p_cMapList[nTargetMap]->sChestList[i].nPositionY;
			p_cChestList[i]->nPositionX = p_cMapList[nTargetMap]->sChestList[i].nPositionX;
			// While we're at it, let's actually place the chest on the item map
			nGlobalItemArray[p_cChestList[i]->nPositionY][p_cChestList[i]->nPositionX] = i;
		}
	}
}

void DrawMap(WINDOW *wCamera, TILE_TYPE sTileIndex[], cPlayer *Player)
{
	for( int y = 0; y < cnCameraMapHeight; y++ )
	{
		for( int x = 0; x < cnCameraMapWidth; x++ )
		{
			DrawTile( wCamera, x, y, sTileIndex, Player);
		}
	}
}

void DrawTile( WINDOW *wCamera, int x, int y, TILE_TYPE sTileIndex[], cPlayer *Player)
{
	// Draw the specified tile in our camera window
	int nType = nCameraMapArray[y][x];
	if(Player->bInCave == true && (std::abs(Player->sHero.nPositionY - y) > Player->nLightRadius ||(std::abs(Player->sHero.nPositionX - x)) > Player->nLightRadius))
	{
		// If we're in a cave, only draw the tiles within the light radius
		mvwaddch(wCamera, y, x, sTileIndex[cnTileBlank].nCharacter);
	} else {
		mvwaddch(wCamera, y,x, sTileIndex[nType].nCharacter | COLOR_PAIR(sTileIndex[nType].nColorPair | A_BOLD));
		// If there's a chest here, draw the chest (hide certain items, such as the Fairy Flute.)
		int nChestContents = p_cChestList[nGlobalItemArray[y+nCameraY][x+nCameraX]]->nItemType;
		if(nChestContents > 0 && nChestContents != cnItemFairyFlute)
			mvwaddch(wCamera, y,x, '(' | COLOR_PAIR(11 | A_BOLD));

		// Draw any actors on the screen if they exist
		for(int i = 0; i < Player->nTargetActors; i++)
		{
			int nActorY = p_cActorList[i]->nPositionY - nCameraY;
			int nActorX = p_cActorList[i]->nPositionX - nCameraX;
			if( y == nActorY && x == nActorX && p_cActorList[i]->bExists && !Player->bTransition)
			{
				mvwaddch(wCamera, nActorY, nActorX, '@' | A_BOLD | COLOR_PAIR(p_cActorList[i]->nCostume));
			}
		}
	}	
}

void Transition(WINDOW *wCamera, TILE_TYPE sTileIndex[], cPlayer *Player)
{
	Player->bTransition = true;
	// Set camera map to blank
	for(int y=0; y<cnCameraMapHeight; y++)
	{
		for(int x=0; x<cnCameraMapWidth; x++)
		{
			nCameraMapArray[y][x] = cnTileBlank;
		}
	}

	// Slowly redraw the camera map
	for( int y = 0; y < cnCameraMapHeight; y++ )
	{
		for( int x = 0; x < cnCameraMapWidth; x++ )
		{
			DrawTile( wCamera, x, y, sTileIndex, Player);
			wrefresh(wCamera);
			usleep(500);
		}
	}
	Player->bTransition = false;

	// Fill the camera map with correct global map info
	for(int y=0; y<cnCameraMapHeight; y++)
	{
		for(int x=0; x<cnCameraMapWidth; x++)
		{
			nCameraMapArray[y][x] = nGlobalMapArray[y+nCameraY][x+nCameraX];
		}
	}
	
	// Slowly redraw the camera map again
	for( int y = 0; y < cnCameraMapHeight; y++ )
	{
		for( int x = 0; x < cnCameraMapWidth; x++ )
		{
			DrawTile( wCamera, x, y, sTileIndex, Player );
			wrefresh(wCamera);
			usleep(500);
		}
	}
}

void DrawWindow(WINDOW *wCurrentWindow, int nWindowHeight, int nWindowWidth)
{
	// This function draws a blank window with a frame in the window with height and width specified
	// Other functions draw the relevant information inside the window.
	for(int y = 0; y < nWindowHeight; y++)
	{
		for(int x = 0; x < nWindowWidth; x++)
		{
			if(y == 0 && x == 0)
			{
				mvwaddch(wCurrentWindow, y, x, ACS_ULCORNER);
			} else if(y==0 && x==nWindowWidth-1)
			{
				mvwaddch(wCurrentWindow, y, x, ACS_URCORNER);
			} else if(y==nWindowHeight-1 && x==0)
			{
				mvwaddch(wCurrentWindow, y, x, ACS_LLCORNER);
			} else if(y==nWindowHeight-1 && x==nWindowWidth-1)
			{
				mvwaddch(wCurrentWindow, y, x, ACS_LRCORNER);
			} else if(y==0 || y==nWindowHeight-1)
			{
				mvwaddch(wCurrentWindow, y, x, ACS_HLINE);
			} else if(x==0 || x==nWindowWidth-1)
			{
				mvwaddch(wCurrentWindow, y, x, ACS_VLINE);
			} else
			{
				mvwaddch(wCurrentWindow, y, x, ' ');
			}
		}
	}
	wrefresh(wCurrentWindow);
	return;
}

void ClearWindow(WINDOW *wCurrentWindow, int nWindowHeight, int nWindowWidth)
{
	// Fill the window with blank spaces
	for(int y = 0; y < nWindowHeight; y++)
	{
		for(int x = 0; x < nWindowWidth; x++)
		{
			mvwaddch(wCurrentWindow, y, x, ' ');
		}
	}
	wrefresh(wCurrentWindow);
}

bool DrawYesNo(WINDOW *wYesNo)
{
	int nCursorPosition = 0;
	int sKeyPress;
	bool exit_command = false;
	bool bAnswer;
	while(!exit_command)
	{
		sYesNoCursor[nCursorPosition].bHasCursor = true;
		DrawWindow(wYesNo, cnYesNoWindowHeight, cnYesNoWindowWidth);
		mvwprintw(wYesNo, 1, 2, "YES");
		mvwprintw(wYesNo, 2, 2, "NO");
		for(int i = 0; i < 2; i++)
		{
			if(sYesNoCursor[i].bHasCursor)
			{
				mvwaddch(wYesNo, sYesNoCursor[i].nCursorY, sYesNoCursor[i].nCursorX, ACS_RARROW | A_BLINK);
			}
		}
		sKeyPress = wgetch(wYesNo);
		switch(sKeyPress)
		{
			case KEY_DOWN:
				if(nCursorPosition == 0)
				{
					sYesNoCursor[nCursorPosition].bHasCursor = false;
					nCursorPosition = 1;
				}
				break;
			case KEY_UP:
				if(nCursorPosition == 1)
				{
					sYesNoCursor[nCursorPosition].bHasCursor = false;
					nCursorPosition = 0;
				}
				break;
			case 'x':
				if(nCursorPosition == cnAnswerYes)
					bAnswer = true;
				if(nCursorPosition == cnAnswerNo)
					bAnswer = false;
				exit_command = true;
				break;
			case 'z':
				exit_command = true;
				bAnswer =  false;
				break;
			default:
				// Someone is mucking about with the keyboard again
				break;
		}
	}
	ClearWindow(wYesNo, cnYesNoWindowHeight, cnYesNoWindowWidth);
	sYesNoCursor[nCursorPosition].bHasCursor = false;
	return bAnswer;
}

void DrawExitWindow(WINDOW *wConfirmExit)
{
	DrawWindow(wConfirmExit, cnExitWindowHeight, cnExitWindowWidth);
	mvwprintw(wConfirmExit, 1, 2, "Are you sure you want");
	mvwprintw(wConfirmExit, 2, 8, "to quit?");
	mvwprintw(wConfirmExit, 3, 2, "All unsaved progress");
	mvwprintw(wConfirmExit, 4, 6, "will be lost.");
	mvwprintw(wConfirmExit, 5, 6, "YES");
	mvwprintw(wConfirmExit, 5, 17, "NO");

	// Draw the cursor if it exists
	for(int i = 0; i < 2; i++)
	{
		if(sExitCursor[i].bHasCursor)
		{
			mvwaddch(wConfirmExit, sExitCursor[i].nCursorY, sExitCursor[i].nCursorX, ACS_RARROW | A_BLINK);
		}
	}

	wrefresh(wConfirmExit);

	return;
}

bool ConfirmExit(WINDOW *wConfirmExit)
{
	// Set the default cursor position
	int nCursorPosition = 0;

	int sKeyPress;
	
	bool exit_command = false;

	// Until we're ready to leave the exit menu, interact with the exit menu
	while( !exit_command )
	{
		sExitCursor[nCursorPosition].bHasCursor = true;
		DrawExitWindow(wConfirmExit);
		sKeyPress = wgetch(wConfirmExit);
		switch(sKeyPress)
		{
			case KEY_RIGHT:
				if(nCursorPosition == 0)
				{
					sExitCursor[nCursorPosition].bHasCursor = false;
					nCursorPosition = 1;
				}
				break;
			case KEY_LEFT:
				if(nCursorPosition == 1)
				{
					sExitCursor[nCursorPosition].bHasCursor = false;
					nCursorPosition = 0;
				}
				break;
			case 'x':
				if(nCursorPosition == cnAnswerYes)
					return true;
				if(nCursorPosition == cnAnswerNo)
				{
					sExitCursor[nCursorPosition].bHasCursor = false;
					return false;
				}
				break;
			case 'z':
				sExitCursor[nCursorPosition].bHasCursor = false;
				return false;
			default:
				// Someone is mucking about with the keyboard again
				break;
		}
	}

	return false;
}

void DrawStats(WINDOW *wStats, cPlayer *Player)
{
	DrawWindow(wStats, cnStatsWindowHeight, cnStatsWindowWidth);

	mvwprintw(wStats, 0, 2, "Stats");
	// Level line
	mvwprintw(wStats, 1, 1, "LV");
	mvwprintw(wStats, 1, 3, "%5d", Player->sHero.nLevel);
	// Current Health line
	mvwprintw(wStats, 2, 1, "HP");
	mvwprintw(wStats, 2, 3, "%5d", Player->sHero.nHealthCurrent);
	// Current Magic Line
	mvwprintw(wStats, 3, 1, "MP");
	mvwprintw(wStats, 3, 3, "%5d", Player->sHero.nMagicCurrent);
	// Gold line
	mvwprintw(wStats, 4, 1, "G");
	mvwprintw(wStats, 4, 2, "%6d", Player->nGold);
	// Experience line
	mvwprintw(wStats, 5, 1, "E");
	mvwprintw(wStats, 5, 2, "%6d", Player->sHero.nExperience);
	wrefresh(wStats);

	return;
}

void DrawCommandWindow(WINDOW *wCommand)
{
	DrawWindow(wCommand, cnCommandWindowHeight, cnCommandWindowWidth);
	mvwprintw(wCommand, 0, 7, "Command");
	mvwprintw(wCommand, 1, 3, "TALK");
	mvwprintw(wCommand, 2, 3, "STATUS");
	mvwprintw(wCommand, 3, 3, "STAIRS");
	mvwprintw(wCommand, 4, 3, "SEARCH");
	mvwprintw(wCommand, 1, 13, "SPELL");
	mvwprintw(wCommand, 2, 13, "ITEM");
	mvwprintw(wCommand, 3, 13, "DOOR");
	mvwprintw(wCommand, 4, 13, "TAKE");

	// Draw the cursor if it exists
	for(int i = 0; i < 8; i++)
	{
		if(sCommandCursor[i].bHasCursor)
		{
			mvwaddch(wCommand, sCommandCursor[i].nCursorY, sCommandCursor[i].nCursorX, ACS_RARROW | A_BLINK);
		}
	}

	wrefresh(wCommand);

	return;
}

void EnterCommand(WINDOW *wCommand, WINDOW *wInventory, WINDOW *wAlert, WINDOW *wStatus, WINDOW *wYesNo, WINDOW *wCamera, WINDOW *wStats, TILE_TYPE sTileIndex[], cPlayer *Player, cChest *cCurrentChest)
{
	// Set the default cursor position
	int nCursorPosition = 0;

	int sKeyPress;
	
	bool exit_command = false;

	// Until we're ready to exit the command menu, interact with the command menu
	while( !exit_command )
	{
		sCommandCursor[nCursorPosition].bHasCursor = true;
		DrawCommandWindow(wCommand);
		sKeyPress = wgetch(wCommand);
		switch(sKeyPress)
		{
			case KEY_UP:
				if((nCursorPosition > 0 && nCursorPosition <= 3) || (nCursorPosition > 4 && nCursorPosition <= 7))
				{
					sCommandCursor[nCursorPosition].bHasCursor = false;
					nCursorPosition--;
				}
				break;
			case KEY_DOWN:
				if((nCursorPosition < 3 && nCursorPosition >= 0) || (nCursorPosition < 7 && nCursorPosition >= 4))
				{
					sCommandCursor[nCursorPosition].bHasCursor = false;
					nCursorPosition++;
				}
				break;
			case KEY_RIGHT:
				if(nCursorPosition < 4)
				{
					sCommandCursor[nCursorPosition].bHasCursor = false;
					nCursorPosition += 4;
				}
				break;
			case KEY_LEFT:
				if(nCursorPosition > 3)
				{
					sCommandCursor[nCursorPosition].bHasCursor = false;
					nCursorPosition -=4;
				}
				break;
			case 'x':
				// Something was selected, take next action
				mvwaddch(wCommand, sCommandCursor[nCursorPosition].nCursorY, sCommandCursor[nCursorPosition].nCursorX, ACS_RARROW);
				wrefresh(wCommand);
				switch(nCursorPosition)
				{
					case cnCommandTalk:
						Talk(wAlert, wYesNo, wStats, Player);
						break;
					case cnCommandStatus:
						PlayerStatus(wStatus, Player);
						break;
					case cnCommandStairs:
						UseStairs(wCamera, wAlert, sTileIndex, Player);
						break;
					case cnCommandSearch:
						SearchGround(wAlert, Player);
						break;
					case cnCommandSpell:
						break;
					case cnCommandItem:
						DrawItemMenu(wCamera, wInventory, wAlert, sTileIndex, Player);
						break;
					case cnCommandDoor:
						OpenDoor(wAlert, Player);
						break;
					case cnCommandTake:
						TakeChest(wAlert, Player, cCurrentChest);
						break;
					default:
						// We should never get this far
						break;
				}
				sCommandCursor[nCursorPosition].bHasCursor = false;
				exit_command = true;
				break;
			case 'z':
				sCommandCursor[nCursorPosition].bHasCursor = false;
				exit_command = true;
				break;
			default:
				// Someone is mucking about with the keyboard again
				break;
		}
	}
	DrawCommandWindow(wCommand);

	ClearWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);

	return;
}

void Talk(WINDOW *wAlert, WINDOW *wYesNo, WINDOW *wStats, cPlayer *Player)
{
	// Not super happy about having to do it this way, but we'll ask the user what direction they want
	// to talk in...  Just not a much better way to fix this issue unless I really want to move actors
	// around and keep them from coming within 2 tiles of each other.

	DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
	mvwprintw(wAlert, 1, 1, "What direction do you");
	mvwprintw(wAlert, 2, 1, "want to talk?");
	int sKeyPress;
	int nDeltaX = 0;
	int nDeltaY = 0;
	bool exit_command = false;
	while(!exit_command)
	{
		sKeyPress = wgetch(wAlert);
		switch(sKeyPress)
		{
			case KEY_UP:
				nDeltaY = -1;
				exit_command = true;
				break;
			case KEY_DOWN:
				nDeltaY = 1;
				exit_command = true;
				break;
			case KEY_LEFT:
				nDeltaX = -1;
				exit_command = true;
				break;
			case KEY_RIGHT:
				nDeltaX = 1;
				exit_command = true;
				break;
			case 'z':
				ClearWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
				return;
				break;
			default:
				break;
		}
	}

	int nTalkX = nCameraX + Player->sHero.nPositionX + nDeltaX;
	int nTalkY = nCameraY + Player->sHero.nPositionY + nDeltaY;

	// If we're trying to talk at a desk tile, talk to whoever is one past the desk tile
	// Note: Currently this causes a minor bug in that you can talk with the king and princess
	// across their "throne".
	if( nGlobalMapArray[nTalkY][nTalkX] == cnTileWoodDesk)
	{
		nTalkX += nDeltaX;
		nTalkY += nDeltaY;
	}

	int nConversation = 0;

	for(int i = 0; i < cnMaxActors; i++)
	{
		if(p_cActorList[i]->nPositionX == nTalkX && p_cActorList[i]->nPositionY == nTalkY)
			nConversation = p_cActorList[i]->nConversation;
	}

	bool bConfirm;
	DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
	switch(nConversation)
	{
		case 0:
			// No one to talk to
			mvwprintw(wAlert, 1, 1, "'There is no one");
			mvwprintw(wAlert, 2, 2, "there.'");
			break;
		case 1:
			// Talk to the king
			if(Player->nProgress == 0)
			{
				// We haven't left the throne room yet
				mvwprintw(wAlert, 1, 1, "'When thou art");
				mvwprintw(wAlert, 2, 2, "finished preparing");
				mvwprintw(wAlert, 3, 2, "for thy departure,");
				mvwprintw(wAlert, 4, 2, "please see me.");
				mvwprintw(wAlert, 5, 2, "I shall wait.'");
			} else if(Player->nProgress >= 1)
			{
				// We've left the throne room at least once
				mvwprintw(wAlert, 1, 1, "'I am greatly pleased");
				mvwprintw(wAlert, 2, 2, "that thou hast");
				mvwprintw(wAlert, 3, 2, "returned, %s", Player->sHero.p_szName);
				mvwaddch(wAlert, 4, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
				wgetch(wAlert);
				// ...TODO... Experience points are a placeholder here, still need to implement leveling.
				DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
				mvwprintw(wAlert, 1, 1, "'Before reaching thy");
				mvwprintw(wAlert, 2, 2, "next level of");
				mvwprintw(wAlert, 3, 2, "experience thou must");
				mvwprintw(wAlert, 4, 2, "gain %d Points.'", 1);
				mvwaddch(wAlert, 5, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
				wgetch(wAlert);
				DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
				// ...TODO... Saving does nothing yet as the save system isn't yet implemented
				mvwprintw(wAlert, 1, 1, "'Will thou tell me now");
				mvwprintw(wAlert, 2, 2, "of thy deeds so they");
				mvwprintw(wAlert, 3, 2, "won't be forgotten?'");
				wrefresh(wAlert);
				bConfirm = DrawYesNo(wYesNo);
				DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
				wrefresh(wAlert);
				if(bConfirm)
				{
					mvwprintw(wAlert, 1, 1, "'Thy deeds have been");
					mvwprintw(wAlert, 2, 2, "recorded on the");
					mvwprintw(wAlert, 3, 2, "Imperial Scrolls of");
					mvwprintw(wAlert, 4, 2, "Honor.'");
					mvwaddch(wAlert, 5, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
					wgetch(wAlert);
					DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
					wrefresh(wAlert);
				}
				mvwprintw(wAlert, 1, 1, "'Dost thou wish to");
				mvwprintw(wAlert, 2, 2, "continue thy quest?'");
				wrefresh(wAlert);
				bConfirm = DrawYesNo(wYesNo);
				DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
				if(!bConfirm)
				{
					mvwprintw(wAlert, 1, 1, "'Rest then for awhile.'");
					mvwaddch(wAlert, 2, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
					Player->bLetsPlay = false;
				} else {
					mvwprintw(wAlert, 1, 1, "'Goodbye now, %s.", Player->sHero.p_szName);
					mvwprintw(wAlert, 2, 2, "Take care and tempt");
					mvwprintw(wAlert, 3, 2, "not the Fates.'");
				}
			}
			break;
		case 2:
			// Talk to the stationary TR Guard on the left
			if(Player->nProgress == 0)
			{
				// We haven't left the throne room yet
				mvwprintw(wAlert, 1, 1, "'East of this castle");
				mvwprintw(wAlert, 2, 2, "is a town where");
				mvwprintw(wAlert, 3, 2, "armor, weapons, and");
				mvwprintw(wAlert, 4, 2, "many other items may");
				mvwprintw(wAlert, 5, 2, "be purchased.'");
				mvwaddch(wAlert, 6, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
				wgetch(wAlert);
				DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
				mvwprintw(wAlert, 1, 1, "'Return to the Inn for");
				mvwprintw(wAlert, 2, 2, "a rest if thou art");
				mvwprintw(wAlert, 3, 2, "wounded in battle,");
				mvwprintw(wAlert, 4, 2, "%s.'", Player->sHero.p_szName);
				mvwaddch(wAlert, 5, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
				wgetch(wAlert);
				DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
				mvwprintw(wAlert, 1, 1, "'Sleep heals all.'");
			} else if(Player->nProgress >= 1)
			{
				// We've left the throne room, but haven't saved the princess yet
				mvwprintw(wAlert, 1, 1, "'A word of advice.'");
				mvwaddch(wAlert, 2, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
				wgetch(wAlert);
				DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
				mvwprintw(wAlert, 1, 1, "'Save thy money for");
				mvwprintw(wAlert, 2, 2, "more expensive armor.'");
			}
			break;
		case 3:
			// Talk to the stationary TR Guard on the right
			if(Player->nProgress == 0)
			{
				// We haven't left the throne room yet
				mvwprintw(wAlert, 1, 1, "'If thou hast");
				mvwprintw(wAlert, 2, 2, "collected all the");
				mvwprintw(wAlert, 3, 2, "Treasure Chests,");
				mvwprintw(wAlert, 4, 2, "a key will be found'");
				mvwaddch(wAlert, 5, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
				wgetch(wAlert);
				DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
				mvwprintw(wAlert, 1, 1, "'Once used, the key");
				mvwprintw(wAlert, 2, 2, "will disappear, but");
				mvwprintw(wAlert, 3, 2, "the door will be open");
				mvwprintw(wAlert, 4, 2, "and thou may pass");
				mvwprintw(wAlert, 5, 2, "through.'");
			} else if(Player->nProgress >= 1)
			{
				// We've left the throne room, but haven't saved the princess yet
				mvwprintw(wAlert, 1, 1, "'Listen to what people");
				mvwprintw(wAlert, 2, 2, "say.");
				mvwprintw(wAlert, 3, 2, "It can be of great");
				mvwprintw(wAlert, 4, 2, "help.'");
			}
			break;
		case 4:
			// Talk to the walking TR Guard
			// Pretty sure he has a different conversation after the princess is saved
			// so I'll have to get to that later
			mvwprintw(wAlert, 1, 1, "'Dost thou know about");
			mvwprintw(wAlert, 2, 2, "Princess Gwaelin?'");
			wrefresh(wAlert);
			bConfirm = DrawYesNo(wYesNo);
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			if(!bConfirm)
			{
				mvwprintw(wAlert, 1, 1, "'Half a year now hath");
				mvwprintw(wAlert, 2, 2, "passed since the");
				mvwprintw(wAlert, 3, 2, "Princess was");
				mvwprintw(wAlert, 4, 2, "kidnapped by the");
				mvwprintw(wAlert, 5, 2, "enemy.'");
				mvwaddch(wAlert, 6, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
				wgetch(wAlert);
				DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
				mvwprintw(wAlert, 1, 1, "'Never does the King");
				mvwprintw(wAlert, 2, 2, "speak of it, but he");
				mvwprintw(wAlert, 3, 2, "must be suffering");
				mvwprintw(wAlert, 4, 2, "much.'");
				mvwaddch(wAlert, 5, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
				wgetch(wAlert);
				DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			}
			mvwprintw(wAlert, 1, 1, "'%s, please save the", Player->sHero.p_szName);
			mvwprintw(wAlert, 2, 2, "Princess.'");
			break;
		case 5:
			// Talk to the stationary guard just north of the stairs to the throne room
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'King Lorik will");
			mvwprintw(wAlert, 2, 2, "record thy deeds in");
			mvwprintw(wAlert, 3, 2, "his Imperial Scroll");
			mvwprintw(wAlert, 4, 2, "so thou may return to");
			mvwprintw(wAlert, 5, 2, "thy quest later.'");
			break;
		case 6:
			// Talk to the stationary guard just south of the stairs to the throne room
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'If thou art planning");
			mvwprintw(wAlert, 2, 2, "to take a rest, first");
			mvwprintw(wAlert, 3, 2, "see King Lorik.'");
			break;
		case 7:
			// Talk to either of the guards at the southern enterance to Tantegel
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'Welcome to Tantegel");
			mvwprintw(wAlert, 2, 2, "Castle.'");
			break;
		case 8:
			// A variety of actors
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'Where oh where can I");
			mvwprintw(wAlert, 2, 2, "find Princess");
			mvwprintw(wAlert, 3, 2, "Gwaelin?'");
			break;
		case 9:
			// Walking blue guy in Tantegel
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'There was a time when");
			mvwprintw(wAlert, 2, 2, "Brecconary was a");
			mvwprintw(wAlert, 3, 2, "Paradise.");
			mvwprintw(wAlert, 4, 2, "Then the Dragonlord's");
			mvwprintw(wAlert, 5, 2, "minions came.'");
			break;
		case 10:
			// One of the walking guards in Tantegel
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'When entering the");
			mvwprintw(wAlert, 2, 2, "cave, take with thee");
			mvwprintw(wAlert, 3, 2, "a torch.'");
			break;
		case 11:
			// Walking guard near north enterance to Tantegel
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'Thou must have a key");
			mvwprintw(wAlert, 2, 2, "to open a door.'");
			break;
		case 12:
			// Gray wizard behind counter in Tantegel
			// ...TODO... Add white screen flashing
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'%s's coming was", Player->sHero.p_szName);
			mvwprintw(wAlert, 2, 2, "foretold by legend.");
			mvwprintw(wAlert, 3, 2, "May the light shine");
			mvwprintw(wAlert, 4, 2, "upon this brave");
			mvwprintw(wAlert, 5, 2, "warrior.'");
			Player->sHero.nMagicCurrent = Player->sHero.nMagicMax;
			DrawStats(wStats, Player);
			break;
		case 13:
			// Northern most walking green guy in Tantegel
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'We are merchants who");
			mvwprintw(wAlert, 2, 2, "have traveled much in");
			mvwprintw(wAlert, 3, 2, "this land.");
			mvwprintw(wAlert, 4, 2, "Many of our");
			mvwprintw(wAlert, 5, 2, "colleagues have been");
			mvwprintw(wAlert, 6, 2, "killed by servants of");
			mvwprintw(wAlert, 7, 2, "the Dragonlord.'");
			break;
		case 14:
			// Southern most walking green guy in Tantegel
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'Rumor has it that");
			mvwprintw(wAlert, 2, 2, "entire towns have");
			mvwprintw(wAlert, 3, 2, "been destroyed by the");
			mvwprintw(wAlert, 4, 2, "Dragonlord's");
			mvwprintw(wAlert, 5, 2, "servants.'");
			break;
		case 15:
			// Stationary blue guy in Tantegel
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'To become strong");
			mvwprintw(wAlert, 2, 2, "enough to face future");
			mvwprintw(wAlert, 3, 2, "trials thou must");
			mvwprintw(wAlert, 4, 2, "first battle many");
			mvwprintw(wAlert, 5, 2, "foes.'");
			break;
		case 16:
			// Mobile soldier in Tantegel treasure room
			// Note: The king seems a bit short on cash these days.
			// 		 The treasure room doesn't have much gold in it, between 4 chests,
			//       you're probably going to average about 30-ish gold, not even the
			//		 cost of the key to get in.
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'Never does a brave");
			mvwprintw(wAlert, 2, 2, "person steal.'");
			// and he gives you a guilt trip for taking the gold...
			break;
		case 17:
			// Mobile red soldier 1 in Tantegel
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'I am looking for the");
			mvwprintw(wAlert, 2, 2, "castle cellar.");
			mvwprintw(wAlert, 3, 2, "I heard it is not");
			mvwprintw(wAlert, 4, 2, "easily found.'");
			break;
		case 18:
			// Stationary grey soldier 6 in Tantegel
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'If thy Hit Points are");
			mvwprintw(wAlert, 2, 2, "high enough, by all");
			mvwprintw(wAlert, 3, 2, "means, enter.'");
			break;
		case 19:
			// Stationary grey soldier 6 in Tantegel
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'Let us wish the");
			mvwprintw(wAlert, 2, 2, "warrior well!'");
			mvwaddch(wAlert, 3, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
			wgetch(wAlert);
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'May the light be thy");
			mvwprintw(wAlert, 2, 2, "strength!'");
			break;
		case 20:
			// Mobile red solder 2 in Tantegel
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'In Garinham, look for");
			mvwprintw(wAlert, 2, 2, "the grave of Garin.");
			mvwprintw(wAlert, 3, 2, "Thou must push on a");
			mvwprintw(wAlert, 4, 2, "wall of darkness");
			mvwprintw(wAlert, 5, 2, "there.'");
			break;
		case 21:
			// Stationary blue woman in Tantegel
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'When the sun and rain");
			mvwprintw(wAlert, 2, 2, "meet, a Rainbow");
			mvwprintw(wAlert, 3, 2, "Bridge shall appear.'");
			mvwaddch(wAlert, 4, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
			wgetch(wAlert);
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'It's a legend.'");
			break;
		case 22:
			// Stationary gray wizard in Tantegel cellar
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'I have been waiting");
			mvwprintw(wAlert, 2, 2, "long for one such as");
			mvwprintw(wAlert, 3, 2, "thee.'");
			mvwaddch(wAlert, 4, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
			wgetch(wAlert);
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'Take the Treasure");
			mvwprintw(wAlert, 2, 2, "Chest.'");
			break;
		case 23:
			// Talk to the key seller in Tantegel
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'Magic keys!");
			mvwprintw(wAlert, 2, 2, "They will unlock any");
			mvwprintw(wAlert, 3, 2, "door.");
			mvwprintw(wAlert, 4, 2, "Dost thou wish to");
			mvwprintw(wAlert, 5, 2, "purchase one for 85");
			mvwprintw(wAlert, 6, 2, "GOLD?'");
			wrefresh(wAlert);
			bConfirm = DrawYesNo(wYesNo);
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			while(bConfirm)
			{
				if(Player->nGold < 85)
				{
					mvwprintw(wAlert, 1, 1, "'Thou hast not enough");
					mvwprintw(wAlert, 2, 2, "money.'");
					mvwaddch(wAlert, 3, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
					wgetch(wAlert);
					DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
					bConfirm = false;
				} else if(AvailableInventorySlot(wAlert, cnItemKey, Player))
				{
					AddItem(Player, cnItemKey);
					Player->nGold -= 85;
					DrawStats(wStats, Player);
					mvwprintw(wAlert, 1, 1, "'Here, take this key.");
					mvwprintw(wAlert, 2, 2, "Dost thou wish to");
					mvwprintw(wAlert, 3, 2, "purchase more?'");
					wrefresh(wAlert);
					bConfirm = DrawYesNo(wYesNo);
					DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
				} else {
					// Something went wrong, get out of the loop
					bConfirm = false;
				}
			}
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'I will see thee");
			mvwprintw(wAlert, 2, 2, "later.'");
		default:
			break;
	}
	wgetch(wAlert);
	ClearWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
	return;
} 

void PlayerStatus(WINDOW *wStatus, cPlayer *Player)
{
	int nAttack = Player->sHero.nAttack + sWeapon[Player->sHero.nWeapon].nStat;
	int nDefense = Player->sHero.nDefense + sArmor[Player->sHero.nArmor].nStat + sShield[Player->sHero.nShield].nStat;

	// Man, what was the guy that designed this window in the original game thinking, it's ugly as hell
	DrawWindow(wStatus, cnStatusWindowHeight, cnStatusWindowWidth);
	// First line, Character's name
	mvwprintw(wStatus, 1, 6, "NAME:%s", Player->sHero.p_szName);
	// Second line, character's strength
	mvwprintw(wStatus, 2, 7, "STRENGTH:%3d", Player->sHero.nStrength);
	// Third line, character's agility
	mvwprintw(wStatus, 3, 8, "AGILITY:%3d", Player->sHero.nAgility);
	// Fourth line, character's max HP
	mvwprintw(wStatus, 4, 5, "MAXIMUM HP:%3d", Player->sHero.nHealthMax);
	// Fifth line, character's max MP
	mvwprintw(wStatus, 5, 5, "MAXIMUM MP:%3d", Player->sHero.nMagicMax);
	// Sixth line, character's Attack Power
	mvwprintw(wStatus, 6, 3, "ATTACK POWER:%3d", nAttack);
	// Seventh line, character's Defense Power
	mvwprintw(wStatus, 7, 2, "DEFENSE POWER:%3d", nDefense);
	// Eigth line, character's weapon
	mvwprintw(wStatus, 8, 3, "WEAPON:");
	// Oh god, this is about to get ugly.  I'm sure there's a better way...
	// The reason for this ugliness is that we're restricted to how large of a weapon/armor/shield name we can
	// write to the window.  The restriction is artificial, as I've essentially imposed it on myself, and I do
	// have plenty of room to write wider, but I'm trying to stay true-ish to the original game, which was itself
	// restricted in name length, and would break the line.
	//
	// To this end, this code take the name of the weapon/armor/shield, and checks the name, character by character
	// to see if there is a space in the name.  If there is, it starts writing to the next line.
	bool nl = false;
	int n = 10;
	for(int i = 1; i < cnItemNameMaxLength && sWeapon[Player->sHero.nWeapon].p_szName[i-1] !='\0'; i++)
	{
		if(sWeapon[Player->sHero.nWeapon].p_szName[i-1] == ' ')
		{
			nl = true;
		}
		if(!nl)
		{
			mvwaddch(wStatus, 8, i+9, sWeapon[Player->sHero.nWeapon].p_szName[i-1]);
		} else {
			mvwaddch(wStatus, 9, n, sWeapon[Player->sHero.nWeapon].p_szName[i-1]);
			n++;
		}
	}
	// Ninth line, character's armor
	mvwprintw(wStatus, 10, 4, "ARMOR:");
	nl = false;
	n = 10;
	for(int i = 1; i < cnItemNameMaxLength && sArmor[Player->sHero.nArmor].p_szName[i-1] !='\0'; i++)
	{
		if(sArmor[Player->sHero.nArmor].p_szName[i-1] == ' ')
		{
			nl = true;
		}
		if(!nl)
		{
			mvwaddch(wStatus, 10, i+9, sArmor[Player->sHero.nArmor].p_szName[i-1]);
		} else {
			mvwaddch(wStatus, 11, n, sArmor[Player->sHero.nArmor].p_szName[i-1]);
			n++;
		}
	}
	// Tenth line, character's shield
	mvwprintw(wStatus, 12, 3, "SHIELD:");
	nl = false;
	n = 10;
	for(int i = 1; i < cnItemNameMaxLength && sShield[Player->sHero.nShield].p_szName[i-1] !='\0'; i++)
	{
		if(sShield[Player->sHero.nShield].p_szName[i-1] == ' ')
		{
			nl = true;
		}
		if(!nl)
		{
			mvwaddch(wStatus, 12, i+9, sShield[Player->sHero.nShield].p_szName[i-1]);
		} else {
			mvwaddch(wStatus, 13, n, sShield[Player->sHero.nShield].p_szName[i-1]);
			n++;
		}
	}

	wgetch(wStatus);
	ClearWindow(wStatus, cnStatusWindowHeight, cnStatusWindowWidth);
	return;
}

void UseStairs(WINDOW *wCamera, WINDOW *wAlert, TILE_TYPE sTileIndex[], cPlayer *Player)
{
	int nPlayerX = nCameraX + Player->sHero.nPositionX;
	int nPlayerY = nCameraY + Player->sHero.nPositionY;
	int nTileValue = nGlobalMapArray[nPlayerY][nPlayerX];

	int nTargetMap = Player->nTargetMap;
	//mvwprintw(wAlert, 0, 0, "Player Position: %d, %d",nPlayerY, nPlayerX);
	//wgetch(wAlert);
	if( nTileValue != cnTileStairDown && nTileValue != cnTileStairUp )
	{
		// If we're not standing on a set of stairs, alert the Player->
		DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
		mvwprintw(wAlert, 1, 1, "'There are no stairs");
		mvwprintw(wAlert, 2, 2, "here.'");
		wgetch(wAlert);
		ClearWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);

	} else {
		for( int i = 0; i < p_cMapList[nTargetMap]->nStairs; i++ )
		{
			if( nPlayerY == p_cMapList[nTargetMap]->sStairList[i].nOriginY && nPlayerX == p_cMapList[nTargetMap]->sStairList[i].nOriginX )
			{
				nCameraY = p_cMapList[nTargetMap]->sStairList[i].nDestinationY;
				nCameraX = p_cMapList[nTargetMap]->sStairList[i].nDestinationX;
				Player->nTargetY = p_cMapList[nTargetMap]->sStairList[i].nDestinationY;
				Player->nTargetX = p_cMapList[nTargetMap]->sStairList[i].nDestinationX;
				
				Player->bInCave = p_cMapList[nTargetMap]->sStairList[i].bInCave;
				if( Player->nTargetMap != p_cMapList[nTargetMap]->sStairList[i].nDestinationMap )
				{
					Player->nTargetMap = p_cMapList[nTargetMap]->sStairList[i].nDestinationMap;
					ChangeMap( wCamera, sTileIndex, Player, nTileValue );
					return;
				}
				if( Player->nProgress == 0 )
				{
					Player->nProgress++;
					ChangeMap( wCamera, sTileIndex, Player, nTileValue );
					return;
				}
			}
		}
		Transition(wCamera, sTileIndex, Player);
	}

	return;
}

void SearchGround(WINDOW *wAlert, cPlayer *Player)
{
	int i = 0;
	int nChestNumber = nGlobalItemArray[Player->sHero.nPositionY+nCameraY][Player->sHero.nPositionX+nCameraX];
	DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
	mvwprintw(wAlert, 1, 1, "%s searches the", Player->sHero.p_szName);
	mvwprintw(wAlert, 2, 1, "ground all about.");
	mvwaddch(wAlert, 3, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
	wgetch(wAlert);
	mvwaddch(wAlert, 3, cnAlertWindowWidth/2, ' ');
	int nChestContents = p_cChestList[nChestNumber]->nItemType;
	if(nChestContents == cnItemFairyFlute)
	{
		mvwprintw(wAlert, 4, 1, "%s discovers the", Player->sHero.p_szName);
		mvwprintw(wAlert, 5, 1, "%s.", sItems[nChestContents].p_szName);
		if(AvailableInventorySlot(wAlert, nChestContents, Player))
		{
			AddItem(Player, nChestContents);
			nGlobalItemArray[Player->sHero.nPositionY+nCameraY][Player->sHero.nPositionX+nCameraX] = 0;
		} else {
			mvwaddch(wAlert, 6, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
			wgetch(wAlert);
			mvwaddch(wAlert, 6, cnAlertWindowWidth/2, ' ');
			mvwprintw(wAlert, 7, 1, "But your inventory is");
			mvwprintw(wAlert, 8, 1, "full.");
		}
	} else if(nChestNumber > 0)
	{
		mvwprintw(wAlert, 4, 1, "There is a treasure");
		mvwprintw(wAlert, 5, 1, "box.");
	//	TODO - Figure out a way to not have this manually entered "secret". 
	} else if(Player->nTargetMap == cnMapCharlockCastle && nCameraY == 1 && nCameraX == 9)
	{
		mvwprintw(wAlert, 4, 1, "%s discovers the", Player->sHero.p_szName);
		mvwprintw(wAlert, 5, 1, "Secret Passage.");
		nGlobalMapArray[8][23] = cnTileStairDown;
	} else {
		mvwprintw(wAlert, 4, 1, "But there found");
		mvwprintw(wAlert, 5, 1, "nothing.");
	}
	wgetch(wAlert);
	return;
}

void DrawItemMenu(WINDOW *wCamera, WINDOW *wInventory, WINDOW *wAlert, TILE_TYPE sTileIndex[], cPlayer *Player)
{
	bool exit_command = false;
	int nCursorPosition = 0;

	DrawWindow(wInventory, cnInventoryWindowHeight, cnInventoryWindowWidth);
	mvwprintw(wInventory, 0, 7, "Inventory");
	if(Player->nInventory[0][cnItemSlot] == 0)
	{
		// We don't have anything in our inventory, let the player know
		mvwprintw(wInventory, 1, 2, "Nothing of use");
		mvwprintw(wInventory, 2, 2, "has yet been");
		mvwprintw(wInventory, 3, 2, "given to thee.");
		wgetch(wInventory);
	} else {
		for(int i = 0; i < cnInventorySlots; i++)
		{
			mvwprintw(wInventory, i+1, 3, "%s", sItems[Player->nInventory[i][cnItemSlot]].p_szName);
			if(sItems[Player->nInventory[i][cnItemSlot]].bStackable)
			{
				mvwprintw(wInventory, i+1, 8, "x%d", Player->nInventory[i][cnItemCount]);
			}
		}

		while(!exit_command)
		{
			sInventoryCursor[nCursorPosition].bHasCursor = true;
			for(int i = 0; i < cnInventorySlots; i++)
			{
				if(sInventoryCursor[i].bHasCursor)
				{
					mvwaddch(wInventory, sInventoryCursor[i].nCursorY, sInventoryCursor[i].nCursorX, ACS_RARROW | A_BLINK);
				} else {
					mvwaddch(wInventory, sInventoryCursor[i].nCursorY, sInventoryCursor[i].nCursorX, ' ');
				}
			}
			int sKeyPress = wgetch(wInventory);
			switch(sKeyPress)
			{
				case KEY_UP:
					if(nCursorPosition > 0)
					{
						sInventoryCursor[nCursorPosition].bHasCursor = false;
						nCursorPosition--;
					}
					break;
				case KEY_DOWN:
					// If the player presses the down key, and we aren't already at the bottom 
					// of the list, and there are more items, move the cursor down
					if(nCursorPosition < 7 && Player->nInventory[nCursorPosition+1][cnItemSlot] != 0)
					{
						sInventoryCursor[nCursorPosition].bHasCursor = false;
						nCursorPosition++;
					}
					break;
				case 'x':
					mvwaddch(wInventory, sInventoryCursor[nCursorPosition].nCursorY, sInventoryCursor[nCursorPosition].nCursorX, ACS_RARROW);
					switch(Player->nInventory[nCursorPosition][cnItemSlot])
					{
						case cnItemHerb:
							UseHerb(wAlert, nCursorPosition, Player);
							break;
						case cnItemKey:
							UseKey(wAlert, nCursorPosition, Player);
							break;
						case cnItemTorch:
							Player->nLightRadius = 1;
							RemoveItem(nCursorPosition, Player);
							break;
						case cnItemRainbowDrop:
							UseRainbowDrop(wCamera, wAlert, sTileIndex, nCursorPosition, Player);
							break;
						default:
							break;
					}
					exit_command = true;
					break;
				case 'z':
					exit_command = true;
					break;
			}
		}
	}

	// Clean up after ourselves
	ClearWindow(wInventory, cnInventoryWindowHeight, cnInventoryWindowWidth);
	sInventoryCursor[nCursorPosition].bHasCursor = false;

	return;
}

void OpenDoor(WINDOW *wAlert, cPlayer *Player)
{
	int nInventorySlot = cnInventorySlots;

	// Check to see if we have a key
	for( int i = 0; i < cnInventorySlots; i++ )
	{
		if(Player->nInventory[i][cnItemSlot] == cnItemKey)
			nInventorySlot = i;
	}

	// If we have a key, use it
	if(nInventorySlot < cnInventorySlots)
	{
		UseKey(wAlert, nInventorySlot, Player);
	} else {
		// Otherwise, alert the player that they don't have a key
		DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
		mvwprintw(wAlert, 1, 1, "Thou hast not a key to");
		mvwprintw(wAlert, 2, 1, "use.");
		wgetch(wAlert);
	}
	return;
}

void TakeChest(WINDOW *wAlert, cPlayer *Player, cChest *cCurrentChest)
{
	int nGold;
	int nChestContents = nGlobalItemArray[Player->sHero.nPositionY+nCameraY][Player->sHero.nPositionX+nCameraX];
	if(nChestContents > cnItemNone && cCurrentChest->nItemType != cnItemFairyFlute)
	{
		if(cCurrentChest->nItemType == cnItemErdricksTablet)
		{
			nGlobalItemArray[Player->sHero.nPositionY+nCameraY][Player->sHero.nPositionX+nCameraX] = 0;
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "Fortune smiles upon");
			mvwprintw(wAlert, 2, 1, "thee, %s.", Player->sHero.p_szName);
			mvwprintw(wAlert, 3, 1, "Thou hast found the");
			mvwprintw(wAlert, 4, 1, "Tablet.");
			mvwaddch(wAlert, 5, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
			wgetch(wAlert);
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "The tablet reads as");
			mvwprintw(wAlert, 2, 1, "follows:");
			mvwaddch(wAlert, 3, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
			wgetch(wAlert);
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'I am Erdrick and thou");
			mvwprintw(wAlert, 2, 2, "art my descendant.'");
			mvwaddch(wAlert, 3, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
			wgetch(wAlert);
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'Three items were");
			mvwprintw(wAlert, 2, 2, "needed to reach the");
			mvwprintw(wAlert, 3, 2, "Isle of Dragons");
			mvwprintw(wAlert, 4, 2, "which is south of");
			mvwprintw(wAlert, 5, 2, "Brecconary.'");
			mvwaddch(wAlert, 6, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
			wgetch(wAlert);
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'I gathered these");
			mvwprintw(wAlert, 2, 2, "items, reached the");
			mvwprintw(wAlert, 3, 2, "island, and there");
			mvwprintw(wAlert, 4, 2, "defeated a creature");
			mvwprintw(wAlert, 5, 2, "of great evil.'");
			mvwaddch(wAlert, 6, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
			wgetch(wAlert);
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'Now I have entrusted");
			mvwprintw(wAlert, 2, 2, "the three items to");
			mvwprintw(wAlert, 3, 2, "three worthy keepers.'");
			mvwaddch(wAlert, 4, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
			wgetch(wAlert);
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'Their descendants");
			mvwprintw(wAlert, 2, 2, "will protect the");
			mvwprintw(wAlert, 3, 2, "items until thy quest");
			mvwprintw(wAlert, 4, 2, "leads thee to seek");
			mvwprintw(wAlert, 5, 2, "them out.'");
			mvwaddch(wAlert, 6, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
			wgetch(wAlert);
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'When a new evil");
			mvwprintw(wAlert, 2, 2, "arises, find the");
			mvwprintw(wAlert, 3, 2, "three items, then");
			mvwprintw(wAlert, 4, 2, "fight!'");
			wgetch(wAlert);
		} else if((cCurrentChest->nItemType) == cnItemGold)
		{
			int nGoldRand = cCurrentChest->nGoldMax - cCurrentChest->nGoldMin + 1;
			if( cCurrentChest->nGoldMax - cCurrentChest->nGoldMin !=0 )
			{
				nGold = rand() % nGoldRand + cCurrentChest->nGoldMin;
			} else{
				nGold = cCurrentChest->nGoldMax;
			}
			if( nGold == 130 && AvailableInventorySlot(wAlert, cCurrentChest->nItemType, Player))
			{
				// Special condition, in the unlikely event the player gets exactly 130 gold from a chest,
				// the player gets the death necklace (honestly, as long as the user doesn't die, this is really a benefit).
				cCurrentChest->nItemType = cnItemDeathNecklace;
				AddItem(Player, cCurrentChest->nItemType);
				nGlobalItemArray[Player->sHero.nPositionY+nCameraY][Player->sHero.nPositionX+nCameraX] = 0;
				DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
				mvwprintw(wAlert, 1, 1, "Fortune smiles upon");
				mvwprintw(wAlert, 2, 1, "thee, %s.", Player->sHero.p_szName);
				mvwprintw(wAlert, 3, 1, "Thou hast found the");
				mvwprintw(wAlert, 4, 1, "%s.", sItems[cCurrentChest->nItemType].p_szName);
				wgetch(wAlert);
			} else {
				DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
				mvwprintw(wAlert, 1, 1, "Of GOLD thou hast");
				mvwprintw(wAlert, 2, 1, "gained %d", nGold);
				Player->nGold += nGold;
				nGlobalItemArray[Player->sHero.nPositionY+nCameraY][Player->sHero.nPositionX+nCameraX] = 0;
				wgetch(wAlert);
			}
		} else if(AvailableInventorySlot(wAlert, cCurrentChest->nItemType, Player))
		{
				AddItem(Player, cCurrentChest->nItemType);
				nGlobalItemArray[Player->sHero.nPositionY+nCameraY][Player->sHero.nPositionX+nCameraX] = 0;
				DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
				mvwprintw(wAlert, 1, 1, "Fortune smiles upon");
				mvwprintw(wAlert, 2, 1, "thee, %s.", Player->sHero.p_szName);
				mvwprintw(wAlert, 3, 1, "Thou hast found the");
				mvwprintw(wAlert, 4, 1, "%s.", sItems[cCurrentChest->nItemType].p_szName);
				wgetch(wAlert);
		}
	} else {
		DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
		mvwprintw(wAlert, 1, 1, "There is nothing to");
		mvwprintw(wAlert, 2, 1, "take here, %s.", Player->sHero.p_szName);
		wgetch(wAlert);
	}
	
	return;
}

bool AvailableInventorySlot(WINDOW *wAlert, int nItemToAdd, cPlayer *Player)
{
	for( int i = 0; i < cnInventorySlots; i++ )
	{
		if(Player->nInventory[i][cnItemSlot] == cnItemHerb && Player->nInventory[i][cnItemCount] >= 6 && nItemToAdd == cnItemHerb)
		{
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'Thou cannot hold more"); 
			mvwprintw(wAlert, 2, 2, "Herbs.'");
			wgetch(wAlert);
			ClearWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			return false;
		} else if(Player->nInventory[i][cnItemSlot] == cnItemKey && Player->nInventory[i][cnItemCount] >= 6 && nItemToAdd == cnItemKey)
		{
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'Thou cannot hold more"); 
			mvwprintw(wAlert, 2, 2, "Keys.'");
			wgetch(wAlert);
			ClearWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			return false;
		} else if( i == cnInventorySlots-1 && Player->nInventory[i][cnItemSlot] != cnItemNone )
		{
			DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			mvwprintw(wAlert, 1, 1, "'Thou cannot carry");
			mvwprintw(wAlert, 2, 1, "anymore.'");
			wgetch(wAlert);
			ClearWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
			return false;
		}
	}
	return true;
}

void AddItem(cPlayer *Player, int nItemToAdd)
{
	for( int i = 0; i < cnInventorySlots; i++ )
	{
		if(Player->nInventory[i][cnItemSlot] == cnItemHerb && Player->nInventory[i][cnItemCount] < 6 && nItemToAdd == cnItemHerb)
		{
			Player->nInventory[i][cnItemCount]++;
			break;
		} else if(Player->nInventory[i][cnItemSlot] == cnItemKey && Player->nInventory[i][cnItemCount] < 6 && nItemToAdd == cnItemKey)
		{
			Player->nInventory[i][cnItemCount]++;
			break;
		} else if( Player->nInventory[i][cnItemSlot] == cnItemNone )
		{
			Player->nInventory[i][cnItemSlot] = nItemToAdd;
			if(nItemToAdd == cnItemHerb || nItemToAdd == cnItemKey)
				Player->nInventory[i][cnItemCount] = 1;
			break;
		}
	}
	return;
}

void RemoveItem(int nInventorySlot, cPlayer *Player)
{
	// This function removes an item from the inventory.

	// If the player is stackable, and there are more than one, remove one of the appropriate item
	if(sItems[Player->nInventory[nInventorySlot][cnItemSlot]].bStackable == true && Player->nInventory[nInventorySlot][cnItemCount] > 1)
	{
		Player->nInventory[nInventorySlot][cnItemCount]--;
	} else if(nInventorySlot < cnInventorySlots-1 && Player->nInventory[nInventorySlot+1][cnItemSlot] != cnItemNone)
	{
		// If the item isn't stackable, or there is only one of the stackable item, and there are more items in the inventory
		// remove the item being used, and condense the inventory list
		for(int i = nInventorySlot; i < cnInventorySlots; i++)
		{
			Player->nInventory[i][cnItemSlot] = 0;
			Player->nInventory[i][cnItemCount] = 0;
			if(i<cnInventorySlots-1)
			{
				Player->nInventory[i][cnItemSlot] = Player->nInventory[i+1][cnItemSlot];
				Player->nInventory[i][cnItemCount] = Player->nInventory[i+1][cnItemCount];
			}
		}
	} else {
		// Otherwise, just remove the current item.  We only get here if we're using the last item in the inventory
		Player->nInventory[nInventorySlot][cnItemSlot] = 0;
		Player->nInventory[nInventorySlot][cnItemCount] = 0;
	}
	return;	
}

void UseHerb(WINDOW *wAlert, int nInventorySlot, cPlayer *Player)
{
	// Remove one herb from the inventory
	RemoveItem(nInventorySlot, Player);
	// Generate random number between 20 and 35
	int nHeal = rand() % 15 + 21;
	// Check to see if we're healing to more than our max health
	if(Player->sHero.nHealthCurrent+nHeal > Player->sHero.nHealthMax)
	{
		// if so, heal only to our max health
		Player->sHero.nHealthCurrent = Player->sHero.nHealthMax;
	} else {
		// otherwise, add nHeal to our current health
		Player->sHero.nHealthCurrent += nHeal;
	}

	int i;

	DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
	mvwprintw(wAlert, 1, 1, "%s used the Herb.", Player->sHero.p_szName);
	wgetch(wAlert);

	return;
}

void UseKey(WINDOW *wAlert, int nInventorySlot, cPlayer *Player)
{
	if(nCameraMapArray[Player->sHero.nPositionY+1][Player->sHero.nPositionX] == cnTileDoor)
	{
		nGlobalMapArray[nCameraY+Player->sHero.nPositionY+1][nCameraX+Player->sHero.nPositionX] = cnTileBrickFloor;
	} else if(nCameraMapArray[Player->sHero.nPositionY-1][Player->sHero.nPositionX] == cnTileDoor)
	{
		nGlobalMapArray[nCameraY+Player->sHero.nPositionY-1][nCameraX+Player->sHero.nPositionX] = cnTileBrickFloor;
	} else if(nCameraMapArray[Player->sHero.nPositionY][Player->sHero.nPositionX+1] == cnTileDoor)
	{
		nGlobalMapArray[nCameraY+Player->sHero.nPositionY][nCameraX+Player->sHero.nPositionX+1] = cnTileBrickFloor;
	} else if(nCameraMapArray[Player->sHero.nPositionY][Player->sHero.nPositionX-1] == cnTileDoor)
	{
		nGlobalMapArray[nCameraY+Player->sHero.nPositionY][nCameraX+Player->sHero.nPositionX-1] = cnTileBrickFloor;
	} else {
		DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
		mvwprintw(wAlert, 1, 1, "There is no door here.");
		wgetch(wAlert);
		return;
	}
	RemoveItem(nInventorySlot, Player);
	return ;
}

void UseRainbowDrop(WINDOW *wCamera, WINDOW *wAlert, TILE_TYPE sTileIndex[], int nInventorySlot, cPlayer *Player)
{
	int nPlayerX = nCameraX + Player->sHero.nPositionX;
	int nPlayerY = nCameraY + Player->sHero.nPositionY;
	DrawWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
	mvwprintw(wAlert, 1, 1, "%s held the", Player->sHero.p_szName);
	mvwprintw(wAlert, 2, 1, "Rainbow Drop toward");
	mvwprintw(wAlert, 3, 1, "the sky.");
	mvwaddch(wAlert, 4, cnAlertWindowWidth/2, ACS_DARROW | A_BLINK);
	wgetch(wAlert);
	if( Player->nTargetMap == cnMapWorld && nPlayerY == 56 && nPlayerX == 79)
	{
		Player->bRainbowDrop = true;
		Player->nTargetX = nPlayerX - 14;
		Player->nTargetY = nPlayerY - 7;
		nGlobalMapArray[56][78] = cnTileBridge;
		Transition(wCamera, sTileIndex, Player);
		RemoveItem(nInventorySlot, Player);
	} else {
		mvwaddch(wAlert, 4, cnAlertWindowWidth/2, ' ');
		mvwprintw(wAlert, 5, 1, "But nothing happened.");
		wgetch(wAlert);
	}
	ClearWindow(wAlert, cnAlertWindowHeight, cnAlertWindowWidth);
	return;
}

void InitializeMaps()
{
	for(int i = 0; i < cnMaps; i++)
	{
		cMap *p_cNewMap = new cMap();
		p_cMapList[i] = p_cNewMap;
	}

	LoadBrecconaryMap();
	p_cMapList[cnMapBrecconary]->InitializeMap();
	LoadCantlin();
	p_cMapList[cnMapCantlin]->InitializeMap();
	LoadCharlockCastle();
	p_cMapList[cnMapCharlockCastle]->InitializeMap();
	LoadErdricksCave();
	p_cMapList[cnMapErdricksCave]->InitializeMap();
	LoadGarinham();
	p_cMapList[cnMapGarinham]->InitializeMap();
	LoadHauksness();
	p_cMapList[cnMapHauksness]->InitializeMap();
	LoadKol();
	p_cMapList[cnMapKol]->InitializeMap();
	LoadNorthernShrine();
	p_cMapList[cnMapNorthernShrine]->InitializeMap();
	LoadRimuldar();
	p_cMapList[cnMapRimuldar]->InitializeMap();
	LoadRockMountainCave();
	p_cMapList[cnMapRockMountainCave]->InitializeMap();
	LoadSouthernShrine();
	p_cMapList[cnMapSouthernShrine]->InitializeMap();
	LoadSwampCave();
	p_cMapList[cnMapSwampCave]->InitializeMap();
	LoadTantegelMap();
	p_cMapList[cnMapTantegel]->InitializeMap();
	LoadWorldMap();
	p_cMapList[cnMapWorld]->InitializeMap();

	return;
}

void LoadBrecconaryMap()
{
	nTargetMap = *nBrecconaryMapArray;
	nTargetMapHeight = cnBrecconaryMapHeight;
	nTargetMapWidth = cnBrecconaryMapWidth;
	nTargetActors = cnBrecconaryActors;
	nTargetActorList = *nBrecconaryActorList;
	nTargetChests = cnBrecconaryChests;
	nTargetChestList = *nBrecconaryChestList;
	nTargetStairs = cnBrecconaryStairs;
	nTargetStairList = *nBrecconaryStairArray;
}

void LoadCantlin()
{
	nTargetMap = *nCantlinMapArray;
	nTargetMapHeight = cnCantlinMapHeight;
	nTargetMapWidth = cnCantlinMapWidth;
	nTargetActors = cnCantlinActors;
	nTargetActorList = *nCantlinActorList;
	nTargetChests = cnCantlinChests;
	nTargetChestList = *nCantlinChestList;
	nTargetStairs = cnCantlinStairs;
	nTargetStairList = *nCantlinStairArray;
}

void LoadCharlockCastle()
{
	nTargetMap = *nCharlockCastleMapArray;
	nTargetMapHeight = cnCharlockCastleMapHeight;
	nTargetMapWidth = cnCharlockCastleMapWidth;
	nTargetActors = cnCharlockCastleActors;
	nTargetActorList = *nCharlockCastleActorList;
	nTargetChests = cnCharlockCastleChests;
	nTargetChestList = *nCharlockCastleChestList;
	nTargetStairs = cnCharlockCastleStairs;
	nTargetStairList = *nCharlockCastleStairArray;
}

void LoadErdricksCave()
{
	nTargetMap = *nErdricksCaveMapArray;
	nTargetMapHeight = cnErdricksCaveMapHeight;
	nTargetMapWidth = cnErdricksCaveMapWidth;
	nTargetActors = cnErdricksCaveActors;
	nTargetActorList = *nErdricksCaveActorList;
	nTargetChests = cnErdricksCaveChests;
	nTargetChestList = *nErdricksCaveChestList;
	nTargetStairs = cnErdricksCaveStairs;
	nTargetStairList = *nErdricksCaveStairArray;
}

void LoadGarinham()
{
	nTargetMap = *nGarinhamMapArray;
	nTargetMapHeight = cnGarinhamMapHeight;
	nTargetMapWidth = cnGarinhamMapWidth;
	nTargetActors = cnGarinhamActors;
	nTargetActorList = *nGarinhamActorList;
	nTargetChests = cnGarinhamChests;
	nTargetChestList = *nGarinhamChestList;
}

void LoadHauksness()
{
	nTargetMap = *nHauksnessMapArray;
	nTargetMapHeight = cnHauksnessMapHeight;
	nTargetMapWidth = cnHauksnessMapWidth;
	nTargetActors = cnHauksnessActors;
	nTargetActorList = *nHauksnessActorList;
	nTargetChests = cnHauksnessChests;
	nTargetChestList = *nHauksnessChestList;
	nTargetStairs = cnHauksnessStairs;
	nTargetStairList = *nHauksnessStairArray;
}

void LoadKol()
{
	nTargetMap = *nKolMapArray;
	nTargetMapHeight = cnKolMapHeight;
	nTargetMapWidth = cnKolMapWidth;
	nTargetActors = cnKolActors;
	nTargetActorList = *nKolActorList;
	nTargetChests = cnKolChests;
	nTargetChestList = *nKolChestList;
	nTargetStairs = cnKolStairs;
	nTargetStairList = *nKolStairArray;
}

void LoadNorthernShrine()
{
	nTargetMap = *nNorthernShrineMapArray;
	nTargetMapHeight = cnNorthernShrineMapHeight;
	nTargetMapWidth = cnNorthernShrineMapWidth;
	nTargetActors = cnNorthernShrineActors;
	nTargetActorList = *nNorthernShrineActorList;
	nTargetChests = cnNorthernShrineChests;
	nTargetChestList = *nNorthernShrineChestList;
	nTargetStairs = cnNorthernShrineStairs;
	nTargetStairList = *nNorthernShrineStairArray;
}

void LoadRimuldar()
{
	nTargetMap = *nRimuldarMapArray;
	nTargetMapHeight = cnRimuldarMapHeight;
	nTargetMapWidth = cnRimuldarMapWidth;
	nTargetActors = cnRimuldarActors;
	nTargetActorList = *nRimuldarActorList;
	nTargetChests = cnRimuldarChests;
	nTargetChestList = *nRimuldarChestList;
	nTargetStairs = cnRimuldarStairs;
	nTargetStairList = *nRimuldarStairArray;
}

void LoadRockMountainCave()
{
	nTargetMap = *nRockMountainCaveMapArray;
	nTargetMapHeight = cnRockMountainCaveMapHeight;
	nTargetMapWidth = cnRockMountainCaveMapWidth;
	nTargetActors = cnRockMountainCaveActors;
	nTargetActorList = *nRockMountainCaveActorList;
	nTargetChests = cnRockMountainCaveChests;
	nTargetChestList = *nRockMountainCaveChestList;
	nTargetStairs = cnRockMountainCaveStairs;
	nTargetStairList = *nRockMountainCaveStairArray;
}

void LoadSouthernShrine()
{
	nTargetMap = *nSouthernShrineMapArray;
	nTargetMapHeight = cnSouthernShrineMapHeight;
	nTargetMapWidth = cnSouthernShrineMapWidth;
	nTargetActors = cnSouthernShrineActors;
	nTargetActorList = *nSouthernShrineActorList;
	nTargetChests = cnSouthernShrineChests;
	nTargetChestList = *nSouthernShrineChestList;
	nTargetStairs = cnSouthernShrineStairs;
	nTargetStairList = *nSouthernShrineStairArray;
}

void LoadSwampCave()
{
	nTargetMap = *nSwampCaveMapArray;
	nTargetMapHeight = cnSwampCaveMapHeight;
	nTargetMapWidth = cnSwampCaveMapWidth;
	nTargetActors = cnSwampCaveActors;
	nTargetActorList = *nSwampCaveActorList;
	nTargetChests = cnSwampCaveChests;
	nTargetChestList = *nSwampCaveChestList;
	nTargetStairs = cnSwampCaveStairs;
	nTargetStairList = *nSwampCaveStairArray;
}

void LoadTantegelMap()
{
	nTargetMap = *nTantegelMapArray;
	nTargetMapHeight = cnTantegelMapHeight;
	nTargetMapWidth = cnTantegelMapWidth;
	nTargetActors = cnTantegelActors;
	nTargetActorList = *nTantegelActorList;
	nTargetChests = cnTantegelChests;
	nTargetChestList = *nTantegelChestList;
	nTargetStairs = cnTantegelStairs;
	nTargetStairList = *nTantegelStairArray;
}

void LoadWorldMap()
{
	nTargetMap = *nWorldMapArray;
	nTargetMapHeight = cnWorldMapHeight;
	nTargetMapWidth = cnWorldMapWidth;
	nTargetActors = cnWorldActors;
	nTargetActorList = *nWorldActorList;
	nTargetChests = cnWorldChests;
	nTargetChestList = *nWorldChestList;
	nTargetStairs = cnWorldStairs;
	nTargetStairList = *nWorldStairArray;
}

void cMap::InitializeMap()
{
	this->nMapHeight = nTargetMapHeight;
	this->nMapWidth = nTargetMapWidth;
	this->nActors = nTargetActors;
	this->nChests = nTargetChests;
	this->nStairs = nTargetStairs;

	this->nMapLayout.resize(this->nMapHeight, std::vector<int>(this->nMapWidth, 0));

	int nCounter = 0;

	// Load the map array into the object's map vector
	for(int y = 0; y < this->nMapHeight; y++)
	{
		for(int x = 0; x < this->nMapWidth; x++)
		{
			this->nMapLayout[y][x] = *(nTargetMap+nCounter);
			nCounter++;
		}
	}

	// Load the actor array into the object's actor struct

	// There may be a better way to do this, but this is what works for me
	// I have a pointer to an array holding info about the actors on the current map
	// To make it easier for me to load that info into the appropriate actor, I'm
	// loading the info from the pointed to array into a temporary array before I load that
	// info into an actor.

	int nTempCharacterArray[nTargetActors][cnBasicActorAttributes];
	int nCount = 0;

	for(int y = 0; y < (nTargetActors); y++)
	{
		for(int x = 0; x < cnBasicActorAttributes; x++)
		{
			nTempCharacterArray[y][x] = *(nTargetActorList+nCount);
			nCount++;
		}
	}
	// OK, let's load the info into the appropriate actor now.
	for(int i = 0; i < cnMaxActors; i++)
	{
		// If we're trying to load info about an actor that doesn't exist on the map, set it to not exist
		if(nTargetActors < i-1)
		{
			this->sActorList[i].bExists = false;
		// Otherwise, load the info about the actor into the appropriate actor
		} else {
			this->sActorList[i].bExists = nTempCharacterArray[i][0];
			this->sActorList[i].nCostume = nTempCharacterArray[i][1];
			this->sActorList[i].nInitialPositionY = nTempCharacterArray[i][2];
			this->sActorList[i].nPositionY = nTempCharacterArray[i][2];
			this->sActorList[i].nInitialPositionX = nTempCharacterArray[i][3];
			this->sActorList[i].nPositionX = nTempCharacterArray[i][3];
			this->sActorList[i].nMovementPattern = nTempCharacterArray[i][4];
			this->sActorList[i].bIsMerchant = nTempCharacterArray[i][5];
			this->sActorList[i].nConversation = nTempCharacterArray[i][6];
		}
	}

	// Load the chest array into the object's chest struct
	int nTempChestArray[nTargetChests][cnChestAttributes];
	nCount = 0;
	// Load our temporary array
	for(int y = 0; y < (nTargetChests); y++)
	{
		for(int x = 0; x < cnChestAttributes; x++)
		{
			nTempChestArray[y][x] = *(nTargetChestList+nCount);
			nCount++;
		}
	}
	// Now let's load the chest data to the appropriate chest object

	for(int i = 0; i < cnMaxChests; i++)
	{
		// If we're trying to load info about an Chest that doesn't exist on the map, set it to not exist
		if(i >= nTargetChests)
		{
			this->sChestList[i].nItemType = 0;
			this->sChestList[i].nGoldMin = 0;
			this->sChestList[i].nGoldMax = 0;
			this->sChestList[i].nPositionY = 0;
			this->sChestList[i].nPositionX = 0;
		// Otherwise, load the info about the Chest into the appropriate Chest
		} else {
			this->sChestList[i].nItemType = nTempChestArray[i][0];
			this->sChestList[i].nGoldMin = nTempChestArray[i][1];
			this->sChestList[i].nGoldMax = nTempChestArray[i][2];
			this->sChestList[i].nPositionY = nTempChestArray[i][3];
			this->sChestList[i].nPositionX = nTempChestArray[i][4];
		}
	}

	int nTempStairArray[nTargetStairs][cnStairAttributes];
	nCount = 0;
	// Load our temporary array
	for(int y = 0; y < (nTargetStairs); y++)
	{
		for(int x = 0; x < cnStairAttributes; x++)
		{
			nTempStairArray[y][x] = *(nTargetStairList+nCount);
			nCount++;
		}
	}

	// Last but not least, let's load the stair data into the object's stair struct
	for( int i = 0; i < nTargetStairs; i++ )
	{
		this->sStairList[i].nOriginY = nTempStairArray[i][0];
		this->sStairList[i].nOriginX = nTempStairArray[i][1];
		this->sStairList[i].nDestinationY = nTempStairArray[i][2];
		this->sStairList[i].nDestinationX = nTempStairArray[i][3];
		this->sStairList[i].nDestinationMap = nTempStairArray[i][4];
		this->sStairList[i].bInCave = nTempStairArray[i][5];
	}

}

