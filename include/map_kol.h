#ifndef	MAP_KOL_H
#define MAP_KOL_H

#include <vector>
#include "map_class.h"

void LoadKol();

// This header file contains the map info for Kol
cMap cMapKol;

void LoadKol()
{
    // Map Dimensions
    cMapKol.nMapWidth   = 52;
    cMapKol.nMapHeight  = 38;

    cMapKol.nMapLayout.resize(cMapKol.nMapHeight, std::vector<int>(cMapKol.nMapWidth, 0));

    // Map Declarations
    cMapKol.nMapLayout = {
        // 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47  48  49  50  51
    	{ 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  2,  2,  2,  3,  4,  4,  4,  2,  2,  2,  2,  2,  4,  4,  4,  4,  4,  4,  4,  4,  2,  2,  2,  2, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  2,  1,  2,  3,  3,  4,  4,  2,  1,  1,  1,  2,  4,  4,  4,  4,  4,  4,  2, 13,  2,  1,  1,  2, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  2, 11,  2,  7,  3,  4,  4,  1,  1,  5,  1,  1,  6,  6,  6,  6,  6,  6,  1,  1,  1,  1,  1,  2, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  7,  1,  7,  7,  3,  4,  4,  2,  1,  1,  1,  2,  4,  6,  4,  4,  4,  4,  2, 11,  2,  2,  2,  2, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  7,  7,  7,  3,  3,  2,  2,  2,  2,  1,  2,  2,  4,  6,  4,  4,  4,  4,  2,  1,  2,  4,  4,  4, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  3,  7,  3,  3,  3,  2,  4,  4,  4,  4,  4,  4,  4,  6,  4,  4,  4,  4,  2,  2,  2,  4,  4,  4, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  3,  3,  3,  3,  4,  2,  4,  4,  4,  4,  4,  4,  4,  6,  4,  4,  4,  4,  4,  4,  4,  4,  3,  4, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  4,  3,  3,  4,  4,  2,  4,  4,  4,  4,  4,  4,  4,  6,  4,  4,  4,  4,  4,  3,  3,  3,  3,  4, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  4,  4,  2,  2,  2,  2,  2,  2,  4,  4,  4,  4,  6,  6,  6,  4,  4,  4,  3,  3,  3,  4,  3,  3, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  4,  4,  4,  4,  4,  4,  4,  2,  4,  4,  4,  6,  6,  6,  6,  6,  4,  4,  4,  3,  4,  3,  3,  4, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  2,  2,  2,  2,  2,  4,  4,  2,  4,  4,  6,  6,  6,  6,  6,  6,  6,  4,  2,  2,  2,  2,  2,  2, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  2,  1,  1,  1,  2,  4,  4,  2,  4,  6,  6,  6,  6,  6,  6,  6,  6,  6,  2,  1,  1,  2,  1,  2, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  2,  1,  1,  1,  2,  4,  6, 10,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  1,  1,  1, 11,  1,  2, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  2,  1,  1,  1,  2,  4,  6,  2,  4,  6,  6,  6,  6,  6,  6,  6,  6,  6,  2,  1,  1,  2,  1,  2, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  2, 11,  2,  2,  2,  1,  6,  2,  4,  4,  6,  6,  6,  6,  6,  6,  6,  4,  2,  2,  2,  2,  2,  2, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  2,  1,  2,  1,  1,  1,  1,  2,  4,  4,  4,  6,  6,  6,  6,  6,  4,  4,  4,  4,  4,  4,  4,  4, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  2,  1,  2,  1,  2,  2,  2,  2,  2,  2,  2,  4,  6,  6,  6,  4,  4,  4,  4,  4,  4,  4,  4,  4, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  2,  1,  1,  1,  2,  1,  1,  1,  1,  1,  2,  4,  4,  6,  4,  4,  4,  4,  2,  2,  2,  2,  4,  4, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  2,  1,  2,  1,  2,  1,  3,  1,  3,  1,  2,  4,  4,  6,  6,  6,  6,  6,  6,  6,  6,  2,  4,  4, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  2,  1,  2,  1,  1,  1,  1,  1,  1,  1,  2,  4,  2,  2,  2,  2,  2,  4,  6,  6,  6,  2,  4,  4, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  2,  1,  1,  1,  3,  1,  1,  1,  1,  1,  2,  2,  2,  1,  1,  1,  2,  4,  6,  6,  6,  2,  4,  4, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  2,  2,  1,  2,  2,  1,  3,  1,  3,  1,  1,  1,  1, 11,  1,  1,  2,  4,  4,  6,  4,  4,  4,  4, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  4,  3,  3,  3,  2,  1,  1,  1,  1,  1,  2,  2,  2,  1,  1,  1,  2,  4,  4,  6,  4,  4,  4,  4, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,  4,  4,  3,  3,  2,  2,  2,  2,  2,  2,  2,  3,  2,  2,  2,  2,  2,  4,  4,  6,  4,  4,  4,  4, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 },
        { 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36 }
    };

    ////////////////
    // Chest data //
    ////////////////

    cMapKol.nChests =  1;

    // fields corespond to:
    // 0 = nItemType
    // 1 = nGoldMin
    // 2 = nGoldMax
    // 3 = nPositionY
    // 4 = nPositionX
    cMap::CHEST sTempChestList[] = {
        { true, cnItemFairyFlute, 0, 0, 13, 23 }
    };
    memcpy( cMapKol.sChestList, sTempChestList, sizeof(sTempChestList));

    ////////////////
    // Actor data //
    ////////////////

    cMapKol.nActors =  0;

    // fields corespond to:
    // 0 = Does the actor actually exist
    // 1 = nCostume
    // 2 = nInitialPositionY
    // 3 = nInitialPositionX
    // 4 = nMovementPattern
    // 5 = bIsMerchant
    // 6 = nConversation
    cMap::ACTOR sTempActorList[] = {};
    memcpy( cMapKol.sActorList, sTempActorList, sizeof(sTempActorList));

    cMapKol.nStairs = 0;

    // Values corespond to:
    // nStairOriginY
    // nStairOriginX
    // nStairDestinationY
    // nStairDestinationX
    // *nStairDestinationMap

    cMap::STAIRS sTempStairList[] = {};
    memcpy( cMapKol.sStairList, sTempStairList, sizeof(sTempStairList));

    cMapKol.bInCave = false;
}

#endif // MAP_KOL_H