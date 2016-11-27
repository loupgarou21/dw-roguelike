#ifndef MAP_CLASS_H
#define MAP_CLASS_H

#include "stairs.h"

class cMap
{
public:
	cMap();
	~cMap();

	void InitializeMap();

	struct STAIRS
	{
		int nOriginY;			// Origin staircase Y coordinate.  Calculate based on where the player character is standing
		int nOriginX;			// Origin staircase X coordinate.  Calculate based on where the player character is standing
		int nDestinationY;		// Destination staircase Y coordinate.  Calulate based on camera position, not player character position
		int nDestinationX;		// Destination staircase X coordinate.  Calulate based on camera position, not player character position
		int nDestinationMap;	// Pointer to destination map, in case the stairs take us to a completely different map.
		bool bInCave;			// Does the destination put us in a cave?
	};

	struct CHEST
	{
		int nItemType;
		int nGoldMin;
		int nGoldMax;
		int nPositionY;
		int nPositionX;
	};

	struct ACTOR
	{
		bool bExists;			// Does this actor actually exist in this map?
		int nInitialPositionX;	// Starting X position for the Actor
		int nInitialPositionY; 	// Starting Y position for the Actor
		int nPositionX;			// Current X position
		int nPositionY;			// Current Y position
		int nMovementPattern;	// Determines how far an actor is allowed to move from their initial position
								// 0 can't move at all, 1 can move up to one square from the initial position in any direction
								// 2 can move two squares and so on.
		bool bIsMerchant;		// Is the current user some sort of merchant?
		int nConversation;		// Determines what script our actor is going to follow
		int nCostume;			// Determines the coloring of our actor
	};

	int nMapHeight;
	int nMapWidth;
	std::vector<std::vector<int> > nMapLayout;
	int nChests;
	CHEST sChestList[cnMaxChests];
	int nActors;
	ACTOR sActorList[cnMaxActors];
	int nStairs;
	STAIRS sStairList[cnMaxStairs];

};

#endif // MAP_CLASS_H