#ifndef CHESTS_H
#define CHESTS_H

// The actual maximum number of usable chests is one less than cnMaxChests.
// chest[0] is reserved for when there is no chest.
extern const int cnMaxChests = 9;
extern const int cnChestAttributes = 5;

class cChest
{
	public:
		cChest(void);
		~cChest(void);
		int nItemType;
		int nGoldMin;
		int nGoldMax;
		int nPositionY;
		int nPositionX;
};

#endif // CHESTS_H