#ifndef	MAP_TantegelStart_H
#define MAP_TantegelStart_H

#include <vector>
#include "map_class.h"

void LoadTantegelStart();

// This header file contains the map info for TantegelStart
cMap cMapTantegelStart;

void LoadTantegelStart()
{
    // Map Dimensions
    cMapTantegelStart.nMapWidth   = 36;
    cMapTantegelStart.nMapHeight  = 24;


    cMapTantegelStart.nMapLayout.resize(cMapTantegelStart.nMapHeight, std::vector<int>(cMapTantegelStart.nMapWidth, 0));

    // Map Declarations
    cMapTantegelStart.nMapLayout = {
        // 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  2,  1,  1,  1,  1,  1,  1,  1,  1,  2,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  2,  1, 11, 11, 11, 11, 11, 11,  1,  2,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  2,  1, 11,  1, 11, 11,  1, 11,  1,  2,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  2,  1,  1,  1,  1,  1,  1,  1,  1,  2,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  2,  1,  1,  1,  1,  1,  1,  1,  1,  2,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  2,  1,  1,  1,  1,  1,  1,  1,  1,  2,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  2,  2,  2,  2, 10,  2,  2,  2,  2,  2,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  2,  1,  1,  1,  1,  1,  1,  1, 16,  2,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 },
        {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9 }
    };

    cMapTantegelStart.nChests = 3;
    // fields corespond to:
    // 0 = nItemType
    // 1 = nGoldMin
    // 2 = nGoldMax
    // 3 = nPositionY
    // 4 = nPositionX
    cMap::CHEST sTempChestList[] = {
        { true, cnItemGold,               120,120, 10, 17 },     // These last three are reserved for when the player first starts the game.
        { true, cnItemTorch,                0,  0, 10, 18 },
        { true, cnItemKey,                  0,  0,  7, 19 }      
    };
    memcpy( cMapTantegelStart.sChestList, sTempChestList, sizeof(sTempChestList));

    cMapTantegelStart.nActors = 4;
    // values corespond to:
    // 0 = Does the actor actually exist
    // 1 = nCostume
    // 2 = nInitialPositionY
    // 3 = nInitialPositionX
    // 4 = nPositionY
    // 5 = nPositionX
    // 6 = nMovementPattern
    // 7 = bIsMerchant - not really using this.  May just keep here for later use.
    // 8 = nConversation

    cMap::ACTOR sTempActorList[] = {
        {  1, 12,  9, 16,  9, 16,  0,  0,  1 },      // King
        {  1,  1, 12, 16, 12, 16,  0,  0,  2 },      // Stationary Soldier 1
        {  1,  1, 12, 18, 12, 18,  0,  0,  3 },      // Stationary Soldier 2
        {  1,  1, 11, 20, 11, 20,  5,  0,  4 },      // Mobile Soldier
    };
    memcpy( cMapTantegelStart.sActorList, sTempActorList, sizeof(sTempActorList));

    // Ignore this comment

    cMapTantegelStart.nStairs = 1;

    // Values corespond to:
    // nStairOriginY
    // nStairOriginX
    // nStairDestinationY
    // nStairDestinationX
    // *nStairDestinationMap

    cMap::STAIRS sTempStairList[] = {
        { 14, 21, 7, 7, cnMapTantegel, false },     // Throne room to F1
    };
    memcpy( cMapTantegelStart.sStairList, sTempStairList, sizeof(sTempStairList));

    cMapTantegelStart.bInCave = false;
}

#endif // MAP_TantegelStart_H