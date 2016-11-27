#ifndef ACTOR_H
#define ACTOR_H

// Maximum number of actors in current map
// We'll just reuse actor slots in every map
extern const int cnMaxActors = 27;
extern const int cnBasicActorAttributes = 7;

class cActor
{
	public:
		cActor(void);
		~cActor(void);

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

#endif // ACTOR_H