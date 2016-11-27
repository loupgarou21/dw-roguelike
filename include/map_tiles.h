#ifndef MAP_TILES_H
#define MAP_TILES_H

// This header file has the definitions for tiles on the maps

struct TILE_TYPE
{
	int		nCharacter;				// Console character for this tile type
	short	nColorPair;				// Color code for this tile type
	bool	bPassible;				// Set to true if you can walk on this tile
	bool	bTeleport;				// Set to true if this tile will cause you to teleport
	bool	bChangeMap;				// Set to true if walking on this tile will cause you to change map
	int		nTargetMap;
	int		nTargetY;
	int		nTargetX;
};

// Global array used to define all tile types used in the game


// New definitions
const int cnTileBlank				= 0;
const int cnTileBrickFloor			= 1;
const int cnTileRockWall			= 2;
const int cnTileGrass				= 3;
const int cnTileTree				= 4;
const int cnTileWater				= 5;
const int cnTileSand				= 6;
const int cnTileSwamp				= 7;
const int cnTileBarrier				= 8;
const int cnTileRoof				= 9;
const int cnTileDoor				= 10;
const int cnTileWoodDesk			= 11; // Also used for thone tiles
const int cnTileSignShop			= 12;
const int cnTileSignInn				= 13;
const int cnTileBridge				= 14;
const int cnTileStairUp				= 15;
const int cnTileStairDown			= 16;
const int cnTileGrassExit			= 17;
const int cnTileSandExit			= 18;
const int cnTileSwampExit			= 19;
// 20
// 21
const int cnTileHill				= 22;
const int cnTileMountain			= 23;
const int cnTileGarinham			= 24;
const int cnTileKol					= 25;
const int cnTileErdricksCave		= 26;
const int cnTileBrecconary 			= 27;
const int cnTileTantegel			= 28;
const int cnTileSwampCave1			= 29;
const int cnTileCharlockCastle		= 30;
const int cnTileSwampCave2			= 31;
const int cnTileRockMountainCave	= 32;
const int cnTileRimuldar			= 33;
const int cnTileHauksness			= 34;
const int cnTileCantlin				= 35;
const int cnTileTreeExit			= 36;
// 37
// 38
// 39
// 40
// 41
// 42
const int cnTileBrickExit			= 43;
const int cnTileHouseIn				= 44;
const int cnTileHouseOut			= 45;


#endif