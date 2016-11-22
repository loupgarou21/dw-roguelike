#ifndef CHARACTER_H
#define CHARACTER_H

const int cnInventorySlots = 6;

// Setup the player

class cPlayer
{
	public:
		cPlayer(void);
		~cPlayer(void);

		// Getting smarted I hope, creating a struct to hold character data within the player class.
		struct PLAYER_CHARACTER
		{
			char p_szName[9];				// Character's name
			int nLevel;						// Character's level
			int nExperience;				// Character's amount of experience
			int nHealthMax;					// Character's maximum amount of health
			int nHealthCurrent;				// Character's current amount of health
			int nMagicMax;					// Character's maximum amount of magic
			int nMagicCurrent;				// Character's current amount of magic
			int nStrength;					// Character's current strength
			int nAgility;					// Character's current agility
			int nAttack;					// Character's attack power
			int nDefense;					// Character's defensive power
			int nWeapon;					// Character's current weapon
			int nArmor;						// Character's current armor
			int nShield;					// Character's current shield
			int nPositionX;					// Character's current horizontal position
			int nPositionY;					// Character's current vertical position
		};

		PLAYER_CHARACTER sHero;

		int nGold;
		int nInventory[cnInventorySlots][2]; // Second field is used if the item type stored in the first field is stackable, tells us how many of the item there are.
		int nProgress;			// Stored the current progress stage of the player
		int *nTargetMap;		// When moving between maps, this stores the map we're heading too (and still in, really)
		int nTargetMapHeight;
		int nTargetMapWidth;
		int nTargetX;			// When moving between maps, this stores the X coordinate we're heading to (well, the X coordinate for the camera anyway)
		int nTargetY;			// When moving between maps, this stores the Y coordinate we're heading to (well, the Y coordinate for the camera anyway)
		int nTargetActors;
		int *nTargetActorList;
		int nTargetChests;
		int *nTargetChestList;
		int nTargetStairs;
		STAIRS *nTargetStairList;
		int nLightRadius;
		bool bInCave;
		bool bTransition;		// Keep track of whether or not we just transitioned to a new map.
		// Interestingly, this is no longer actually being used for what I originally intended to use it.
		bool bRainbowDrop;		// Keep track of whether or not we've used the rainbow drop.
		bool bPrincessSaved;	// Keep track of whether or not we've saved the princess
		bool bLetsPlay;
};



#endif	// CHARACTER_H