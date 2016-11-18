#ifndef ITEMS_H
#define ITEMS_H

struct ITEM_TYPE
{
	char	p_szName[18];
	int		nCost;
	bool	bStackable;
	int		nStackSize;
};

ITEM_TYPE sItems[] = {
	{ "", 0, false, 0 },					// (0) cnItemNone
	{ "Herb", 24, true, 6 },				// (1) cnItemHerb
	{ "Wings", 70, false, 0 }, 				// (2) cnItemWings
	{ "Torch", 8, false, 0 },				// (3) cnItemTorch
	{ "Dragon's Scale", 20, false, 0 },		// (4) Dragon's Scale
	{ "Fairy Water", 38, false, 0 },		// (5) Fairy Water
	{ "Key", 53, true, 6 },					// (6) cnItemKey - Key from Town 1
	{ "Key", 85, false, 0 },				// (7) Key from Town 2
	{ "Key", 98, false, 0 },				// (8) Key from Town 3
	{ "Ball of Light", 0, false, 0 },		// (9) Ball of Light
	{ "Erdrick's Tablet", 0, false, 0 },	// (10) Erdrick's Tablet
	{ "Fairy Flute", 0, false, 0 },			// (11) cnItemFairyFlute
	{ "Silver Harp", 0, false, 0 },			// (12) Silver Harp
	{ "Staff of Rain", 0, false, 0 },		// (13) cnStaffOfRain
	{ "Stone of Sunlight", 0, false, 0 },	// (14) cnItemStoneOfSunlight
	{ "Gwaelin's Love", 0, false, 0 },		// (15) Gwaelin's Love
	{ "Erdrick's Token", 0, false, 0 },		// (16) Erdrick's Token
	{ "Rainbow Drop", 0, false, 0 },		// (17) cnItemRainbowDrop
	{ "Cursed Belt", 180, false, 0 },		// (18) cnItemCursedBelt
	{ "Death Necklace", 1200, false, 0 },	// (19) Death Necklace
	{ "Fighter's Ring", 15, false, 0 },		// (20) cnFightersRing
	{ "Gold", 0, false, 0 }					// (21) cnItemGold - Used for chests, not an actual inventory item
};

const int cnItemNone				= 0;
const int cnItemHerb				= 1;
const int cnItemWings				= 2;
const int cnItemTorch				= 3;
const int cnItemKey					= 6;
const int cnItemErdricksTablet		= 10;
const int cnItemFairyFlute			= 11;
const int cnStaffOfRain				= 13;
const int cnItemStoneOfSunlight		= 14;
const int cnItemRainbowDrop			= 17;
const int cnItemCursedBelt			= 18;
const int cnItemDeathNecklace		= 19;
const int cnItemFightersRing		= 20;
const int cnItemGold				= 21;

const int cnItemSlot 	= 0;
const int cnItemCount	= 1;

#endif	// ITEMS_H