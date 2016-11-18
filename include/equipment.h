#ifndef EQUIPMENT_H
#define EQUIPMENT_H

// Maximum name length for a piece of equipment.
const int cnItemNameMaxLength = 16;

struct EQUIPMENT_TYPE
{
	char	p_szName[cnItemNameMaxLength];	// Equipment name
	int 	nCost;			// How much it costs to buy, affects sale value
	int		nStat;			// How it modifies the primary stat.  Starting simple, may expand later
};

EQUIPMENT_TYPE sWeapon[] = {
	{ "", 0, 0 },				// (0) Nothing currently equipped
	{ "Bamboo Pole", 10, 2 },		// (1) Bamboo Pole
	{ "Club", 60, 4 },				// (2) Club
	{ "Copper Sword", 180, 18 },	// (3) Copper Sword
	{ "Hand Axe", 560, 15 },		// (4) Hand Axe
	{ "Broad Sword", 1500, 20 },	// (5) Broad Sword
	{ "Flame Sword", 9800, 28 },	// (6) Flame Sword
	{ "Erdrick's Sword", 0, 40 }	// (7) Erdrick's Sword 
};

EQUIPMENT_TYPE sArmor[] = {
	{ "", 0, 0 },				// (0) Nothing currently equipped
	{ "Clothes", 20, 2 },			// (1) Clothes
	{ "Leather Armor", 70, 4 },		// (2) Leather Armor
	{ "Chain Mail", 300, 10 },		// (3) Chain Mail
	{ "Half Plate", 1000, 16 },		// (4) Half Plate
	{ "Full Plate", 3000, 24 },		// (5) Full Plate
	{ "Magic Armor", 7700, 24 },	// (6) Magic Armor
	{ "Erdrick's Armor", 0, 28 }	// (7) Erdrick's Armor
};

EQUIPMENT_TYPE sShield[] = {
	{ "", 0, 0 },				// (0) Nothing currently equipped
	{ "Samll Shield", 90, 4 },		// (1) Small Shield
	{ "Large Shield", 800, 10 },	// (2) Small Shield
	{ "Silver Shield", 14800, 20 }	// (3) Silver Shield
};

#endif	// EQUIPMENT_H