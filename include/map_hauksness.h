#ifndef	MAP_HAUKSNESS_H
#define MAP_HAUKSNESS_H

// This header file contains the map info for Hauksness

// Map Dimensions
const int cnHauksnessMapWidth   = 48;
const int cnHauksnessMapHeight  = 34;


// Map Declarations
int nHauksnessMapArray[cnHauksnessMapHeight][cnHauksnessMapWidth] = {
    // 1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47  48
	{ 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  2,  2,  6,  6,  3,  2,  2,  6,  2,  2,  2,  2,  2,  2,  2,  1,  1,  2,  7,  2, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  2,  6,  6,  3,  4,  2,  6,  1,  1, 11,  1,  2,  4,  3,  3,  6,  2,  7,  7,  2, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  6,  6,  6,  4,  3,  2,  2,  1,  1,  2,  1,  2,  3,  3,  3,  1,  7,  7,  6,  2, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  6,  3,  3,  3,  7,  7,  2,  2,  1,  2,  2,  2,  3,  7,  3,  1,  1,  7,  6,  6, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  6,  6,  3,  3,  3,  7,  7,  3,  1,  3,  3,  3,  4,  3,  3,  1,  1,  3,  6,  2, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  2,  3,  1,  1,  1,  6,  7,  6,  1,  1,  1,  6,  6,  1,  1,  6,  1,  3,  3,  2, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  2,  3,  1,  1,  1,  1,  6,  1,  1,  6,  6,  6,  1,  1,  1,  1,  1,  3,  4,  3, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  3,  3,  1,  1,  3,  6,  6,  6,  3,  4,  3,  3,  3,  3,  3,  3,  1,  3,  3,  4, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  2,  3,  1,  1,  3,  6,  2,  2,  2,  2,  6,  2,  1,  1,  1,  2,  1,  2,  2,  3, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  1,  1,  6,  1,  3,  2,  1,  1,  1,  6,  6,  2,  7,  3,  2,  1, 11,  7,  2,  6, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  1,  6,  1,  1,  3,  2,  2,  2, 11,  2,  2,  2,  3,  7,  2,  1,  7,  7,  2,  7, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  4,  4,  1,  1,  4,  2,  6,  6,  1,  1,  1,  2,  4,  3,  2,  2,  7,  2,  2,  7, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  4,  3,  6,  1,  4,  2,  6,  2,  1,  2,  6,  2,  4,  4,  6,  6,  7,  7,  4,  2, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  2,  3,  1,  6,  4,  2,  1,  1,  1,  6,  6,  6,  4,  6,  3,  2,  2,  2,  2,  6, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  2,  3,  1,  1,  3,  2,  2,  1,  1,  2,  2,  2,  6,  3,  3,  2,  6,  6,  6,  2, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  2,  7,  6,  1,  3,  6,  6,  4,  1,  6,  1,  1,  1,  1,  6,  1,  1, 11,  6,  2, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  7,  7,  1,  1,  3,  3,  6,  3,  1,  4,  3,  3,  3,  3,  3,  2,  1,  2,  6,  6, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  6,  7,  1,  6,  1,  1,  1,  1,  6,  3,  3,  3,  7,  3,  3,  2,  2,  2,  2,  2, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  2,  7,  7,  7,  3,  3,  3,  3,  3,  3,  3,  7,  7,  7,  3,  6,  6,  6,  6,  6, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  6,  6,  7,  2,  2,  2,  2,  3,  2,  7,  7,  7,  7,  2,  2,  2,  6,  2,  2,  2, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
    { 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18 },
};

////////////////
// Chest data //
////////////////

const int cnHauksnessChests =  2;

// fields corespond to:
// 0 = nItemType
// 1 = nGoldMin
// 2 = nGoldMax
// 3 = nPositionY
// 4 = nPositionX
int nHauksnessChestList[cnHauksnessChests][cnChestAttributes] = {
    { cnItemNone, 0, 0, 0, 0 },
    { cnItemNone, 0, 0, 0, 0 }
};

////////////////
// Actor data //
////////////////

const int cnHauksnessActors =  0;

// fields corespond to:
// 0 = Does the actor actually exist
// 1 = nCostume
// 2 = nInitialPositionY
// 3 = nInitialPositionX
// 4 = nMovementPattern
// 5 = bIsMerchant
// 6 = nConversation
int nHauksnessActorList[cnHauksnessActors][cnBasicActorAttributes] = {};

const int cnHauksnessStairs = 0;

// Values corespond to:
// nStairOriginY
// nStairOriginX
// nStairDestinationY
// nStairDestinationX
// *nStairDestinationMap

int nHauksnessStairArray[cnHauksnessStairs][cnStairAttributes] = {};

#endif // MAP_HAUKSNESS_H