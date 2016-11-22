#ifndef STAIRS_H
#define STAIRS_H

const int cnStairAttributes = 6;
const int cnMaxStairs = 4;

struct STAIRS
{
	int nOriginY;			// Origin staircase Y coordinate.  Calculate based on where the player character is standing
	int nOriginX;			// Origin staircase X coordinate.  Calculate based on where the player character is standing
	int nDestinationY;		// Destination staircase Y coordinate.  Calulate based on camera position, not player character position
	int nDestinationX;		// Destination staircase X coordinate.  Calulate based on camera position, not player character position
	int *nDestinationMap;	// Pointer to destination map, in case the stairs take us to a completely different map.
	bool bInCave;			// Does the destination put us in a cave?
};

const int cnBrecconaryStairs = 0;

// Values corespond to:
// nStairOriginY
// nStairOriginX
// nStairDestinationY
// nStairDestinationX
// *nStairDestinationMap

STAIRS nBrecconaryStairArray[cnBrecconaryStairs] = {};

const int cnCantlinStairs = 0;

// Values corespond to:
// nStairOriginY
// nStairOriginX
// nStairDestinationY
// nStairDestinationX
// *nStairDestinationMap

STAIRS nCantlinStairArray[cnCantlinStairs] = {};

const int cnCharlockCastleStairs = 43;

// Values corespond to:
// nStairOriginY
// nStairOriginX
// nStairDestinationY
// nStairDestinationX
// *nStairDestinationMap

STAIRS nCharlockCastleStairArray[cnCharlockCastleStairs] = {
	{ 8, 23, 0, 55, *nCharlockCastleMapArray, true },		// F1 to B1 Stair A
	{ 7, 69, 1, 9, *nCharlockCastleMapArray, false },		// B1 to F1 Stair A
	{ 21, 17, 13, 54, *nCharlockCastleMapArray, true },		// F1 to B1 Stair B
	{ 20, 68, 14, 3, *nCharlockCastleMapArray, false },		// B1 to F1 Stair B
	{ 21, 28, 15, 63, *nCharlockCastleMapArray, true },		// F1 to B1 Stair C
	{ 22, 77, 14, 14, *nCharlockCastleMapArray, false },	// B1 to F1 Stair C
	{ 8, 75, 34, 8, *nCharlockCastleMapArray, true },		// B1 to B2 Stair D
	{ 41, 22, 1, 61, *nCharlockCastleMapArray, true },		// B2 to B1 Stair D
	{ 11, 62, 34, 0, *nCharlockCastleMapArray, true },		// B1 to B2 Stair E
	{ 41, 14, 4, 48, *nCharlockCastleMapArray, true },		// B2 to B1 Stair E
	{ 14, 73, 38, 4, *nCharlockCastleMapArray, true },		// B1 to B2 Stair F
	{ 45, 18, 7, 59, *nCharlockCastleMapArray, true },		// B2 to B1 Stair F
	{ 14, 79, 42, 9, *nCharlockCastleMapArray, true },		// B1 to B2 Stair G
	{ 49, 23, 7, 65, *nCharlockCastleMapArray, true },		// B2 to B1 Stair G
	{ 16, 74, 43, 8, *nCharlockCastleMapArray, true },		// B1 to B2 Stair H
	{ 50, 22, 9, 60, *nCharlockCastleMapArray, true },		// B2 to B1 Stair H
	{ 21, 62, 35, 0, *nCharlockCastleMapArray, true },		// B1 to B2 Stair I
	{ 42, 14, 14, 48, *nCharlockCastleMapArray, true },		// B2 to B1 Stair I
	{ 26, 68, 34, 5, *nCharlockCastleMapArray, true },		// B1 to B2 Stair J
	{ 41, 19, 19, 54, *nCharlockCastleMapArray, true },		// B2 to B1 Stair J
	{ 41, 17, 34, 31, *nCharlockCastleMapArray, true },		// B2 to B3 Stair K
	{ 41, 45, 34, 3, *nCharlockCastleMapArray, true },		// B3 to B2 Stair K
	{ 42, 23, 36, 26, *nCharlockCastleMapArray, true },		// B2 to B3 Stair L
	{ 43, 40, 35, 9, *nCharlockCastleMapArray, true },		// B3 to B2 Stair L
	{ 49, 14, 38, 29, *nCharlockCastleMapArray, true },		// B2 to B3 Stair M
	{ 45, 43, 42, 0, *nCharlockCastleMapArray, true },		// B3 to B2 Stair M
	{ 50, 15, 43, 24, *nCharlockCastleMapArray, true },		// B2 to B3 Stair N
	{ 50, 38, 43, 1, *nCharlockCastleMapArray, true },		// B3 to B2 Stair N
	{ 47, 39, 43, 48, *nCharlockCastleMapArray, true },		// B3 to B4 Stair O
	{ 50, 62, 40, 25, *nCharlockCastleMapArray, true },		// B4 to B3 Stair O
	{ 48, 45, 41, 55, *nCharlockCastleMapArray, true },		// B3 to B4 Stair P
	{ 48, 69, 41, 31, *nCharlockCastleMapArray, true },		// B4 to B3 Stair P
	{ 42, 70, 51, 4, *nCharlockCastleMapArray, true },		// B4 to B5 Stair Q
	{ 58, 18, 35, 56, *nCharlockCastleMapArray, true },		// B5 to B4 Stair Q
	{ 43, 64, 51, 9, *nCharlockCastleMapArray, true },		// B4 to B5 Stair R
	{ 58, 23, 36, 50, *nCharlockCastleMapArray, true },		// B5 to B4 Stair R
	{ 58, 14, 57, 24, *nCharlockCastleMapArray, true },		// B5 to B6 Stair S
	{ 64, 38, 51, 0, *nCharlockCastleMapArray, true },		// B6 to B5 Stair S
	{ 63, 19, 51, 24, *nCharlockCastleMapArray, true },		// B5 to B6 Stair T
	{ 58, 38, 56, 5, *nCharlockCastleMapArray, true },		// B6 to B5 Stair T
	{ 58, 47, 51, 24, *nCharlockCastleMapArray, true },		// B6 to B6 Stair T
	{ 64, 47, 102, 8, *nCharlockCastleMapArray, false },	// B6 to B7 Stair U
	{ 109, 22, 57, 33, *nCharlockCastleMapArray, true }		// B7 to B6 Stair U
};

const int cnErdricksCaveStairs = 3;

// Values corespond to:
// nStairOriginY
// nStairOriginX
// nStairDestinationY
// nStairDestinationX
// *nStairDestinationMap

STAIRS nErdricksCaveStairArray[cnErdricksCaveStairs] = {
    { 7, 14, 12, 28, *nWorldMapArray, false },			// Exit to world map
    { 16, 23, 30, 9, *nErdricksCaveMapArray, true },	// B1 to B2
    { 37, 23, 9, 9, *nErdricksCaveMapArray, true }		// B2 to B1
};

const int cnHauksnessStairs = 0;

// Values corespond to:
// nStairOriginY
// nStairOriginX
// nStairDestinationY
// nStairDestinationX
// *nStairDestinationMap

STAIRS nHauksnessStairArray[cnHauksnessStairs] = {};

const int cnGarinhamStairs = 18;

// Values corespond to:
// nStairOriginY
// nStairOriginX
// nStairDestinationY
// nStairDestinationX
// *nStairDestinationMap

STAIRS nGarinhamStairArray[cnGarinhamStairs] = {
	{ 7, 33, 79, 6, *nGarinhamMapArray, true },		// F1 to B1
	{ 86, 20, 0, 19, *nGarinhamMapArray, false },	// B1 to F1
	{ 93, 15, 97,11, *nGarinhamMapArray, true },	// B1 to B2 Stair A
	{ 104, 25, 86, 1, *nGarinhamMapArray, true },	// B2 to B1 Stair A
	{ 103, 15, 117, 14, *nGarinhamMapArray, true },	// B2 to B3 Stair B
	{ 124, 28, 96, 1, *nGarinhamMapArray, true },	// B3 to B2 Stair B
	{ 103, 26, 117, 18, *nGarinhamMapArray, true },	// B2 to B3 Stair C
	{ 124, 32, 96, 12, *nGarinhamMapArray, true },	// B3 to B2 Stair C
	{ 108, 19, 127, 6, *nGarinhamMapArray, true },	// B2 to B3 Stair D
	{ 134, 20, 101, 5, *nGarinhamMapArray, true },	// B3 to B2 Stair D
	{ 112, 15, 133, 2, *nGarinhamMapArray, true },	// B2 to B3 Stair E
	{ 140, 16, 105, 1, *nGarinhamMapArray, true },	// B3 to B2 Stair E
	{ 112, 26, 129, 18, *nGarinhamMapArray, true },	// B2 to B3 Stair F
	{ 136, 32, 105, 12, *nGarinhamMapArray, true },	// B3 to B2 Stair F
	{ 128, 23, 147, 0, *nGarinhamMapArray, true },	// B3 to B4 Stair G
	{ 154, 14, 121, 9, *nGarinhamMapArray, true },	// B4 to B3 Stair G
	{ 132, 24, 147, 5, *nGarinhamMapArray, true },	// B3 to B4 Stair H
	{ 154, 19, 125, 10, *nGarinhamMapArray, true }	// B4 to B3 Stair H
};

const int cnKolStairs = 0;

// Values corespond to:
// nStairOriginY
// nStairOriginX
// nStairDestinationY
// nStairDestinationX
// *nStairDestinationMap

STAIRS nKolStairArray[cnKolStairs] = {};

const int cnNorthernShrineStairs = 1;

// Values corespond to:
// nStairOriginY
// nStairOriginX
// nStairDestinationY
// nStairDestinationX
// *nStairDestinationMap

STAIRS nNorthernShrineStairArray[cnNorthernShrineStairs] = {
    { 16, 18, 1, 81, *nWorldMapArray, false }			// Exit to world map
};

const int cnRimuldarStairs = 0;

// Values corespond to:
// nStairOriginY
// nStairOriginX
// nStairDestinationY
// nStairDestinationX
// *nStairDestinationMap

STAIRS nRimuldarStairArray[cnRimuldarStairs] = {};

const int cnRockMountainCaveStairs = 7;

// Values corespond to:
// nStairOriginY
// nStairOriginX
// nStairDestinationY
// nStairDestinationX
// *nStairDestinationMap

STAIRS nRockMountainCaveStairArray[cnRockMountainCaveStairs] = {
    { 14, 14, 57, 29, *nWorldMapArray, false },				// Exit to world map
    { 7, 14, 21, 0, *nRockMountainCaveMapArray, true },
    { 28, 14, 0, 0, *nRockMountainCaveMapArray, true },
    { 12, 20, 26, 6, *nRockMountainCaveMapArray, true },
    { 33, 20, 5, 6, *nRockMountainCaveMapArray, true },
    { 19, 26, 33, 12, *nRockMountainCaveMapArray, true },
    { 40, 26, 12, 12, *nRockMountainCaveMapArray, true },
};

const int cnSouthernShrineStairs = 1;

// Values corespond to:
// nStairOriginY
// nStairOriginX
// nStairDestinationY
// nStairDestinationX
// *nStairDestinationMap

STAIRS nSouthernShrineStairArray[cnSouthernShrineStairs] = {
    { 11, 14, 109, 108, *nWorldMapArray, false }			// Exit to world map
};

const int cnSwampCaveStairs = 2;

// Values corespond to:
// nStairOriginY
// nStairOriginX
// nStairDestinationY
// nStairDestinationX
// *nStairDestinationMap

STAIRS nSwampCaveStairArray[cnSwampCaveStairs] = {
    { 7, 14, 44, 104, *nWorldMapArray, false },			// Exit to world map, North entrance
    { 36, 14, 49, 104, *nWorldMapArray, false }			// Exit to world map, South entrance
};

const int cnTantegelStairs = 4;

// Values corespond to:
// nStairOriginY
// nStairOriginX
// nStairDestinationY
// nStairDestinationX
// *nStairDestinationMap

STAIRS nTantegelStairArray[cnTantegelStairs] = {
    { 58, 21, 7, 7, *nTantegelMapArray, false },		// Throne room to F1
    { 14, 21, 51, 7, *nTantegelMapArray, false },		// F1 to Throne Room
    { 36, 43, 48, 23, *nTantegelMapArray, false },		// F1 to B1
    { 55, 37, 29, 29, *nTantegelMapArray, false }		// B1 to F1
};

const int cnWorldStairs = 2;

// Values corespond to:
// nStairOriginY
// nStairOriginX
// nStairDestinationY
// nStairDestinationX
// *nStairDestinationMap

STAIRS nWorldStairArray[cnWorldStairs] = {
    { 8, 95, 9, 4, *nNorthernShrineMapArray, false },	// Stairs to Northern Shrine
    { 116, 122, 4, 0, *nSouthernShrineMapArray, false }	// Stairs to Southern Shrine
};



#endif // STAIRS_H