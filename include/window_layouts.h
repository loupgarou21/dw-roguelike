#ifndef WINDOW_LAYOUTS_H
#define WINDOW_LAYOUTS_H

// A new struct for handling the cursor in any window that needs a cursor
struct CURSOR_POSITION
{
	int		nCursorY;				// Cursor position Y coordinate
	int 	nCursorX;				// Cursor position X coordinate
	bool	bHasCursor;				// Set to true if the cursor is here
};

///////////////////
// Camera Window //
///////////////////
// Camera map dimensions
const int cnCameraFrameWidth = 31;
const int cnCameraFrameHeight = 17;

// Camera window offset
const int cnCameraFrameOffsetX = 11;
const int cnCameraFrameOffsetY = 0;

////////////////////
// Command Window //
////////////////////

// Command window dimensions
const int cnCommandWindowWidth = 21;
const int cnCommandWindowHeight = 6;

// Command window offset
const int cnCommandOffsetX = 16;
const int cnCommandOffsetY = 17;

// Array for holding the cursor position in the command window
CURSOR_POSITION sCommandCursor[] = {
	{ 1, 2, false },	// (0) Talk
	{ 2, 2, false },	// (1) Status
	{ 3, 2, false },	// (2) Stairs
	{ 4, 2, false },	// (3) Search
	{ 1, 12, false },	// (4) Spell
	{ 2, 12, false },	// (5) Item
	{ 3, 12, false },	// (6) Door
	{ 4, 12, false },	// (7) Take
};

// Definitions for commands
const int cnCommandTalk		= 0;
const int cnCommandStatus	= 1;
const int cnCommandStairs	= 2;
const int cnCommandSearch	= 3;
const int cnCommandSpell		= 4;
const int cnCommandItem		= 5;
const int cnCommandDoor		= 6;
const int cnCommandTake		= 7;

///////////////
// Exit menu //
///////////////

// Exit window dimensions
const int cnExitWindowWidth		= 25;
const int cnExitWindowHeight	= 7;

// Exit window offset
const int cnExitOffsetX 		= 14;
const int cnExitOffsetY 		= 5;

// Array for holding the cursor position in the exit window
CURSOR_POSITION sExitCursor[] = {
	{ 5, 5, false },	// (0) cnAnswerYes
	{ 5, 16, false },	// (1) cnAnswerNo
};

const int cnAnswerYes	= 0;
const int cnAnswerNo 	= 1;

//////////////////
// Stats window //
//////////////////

// Stats window dimensions
const int cnStatsWindowWidth	= 9;
const int cnStatsWindowHeight	= 7;

// Stats window offset
const int cnStatsOffsetX		= 1;
const int cnStatsOffsetY		= 1;

//////////////////////
// Inventory Window //
//////////////////////

// Inventory Window Dimensions
const int cnInventoryWindowWidth	= 23;
const int cnInventoryWindowHeight	= 8;

// Inventory window offset
const int cnInventoryOffsetX		= 43;
const int cnInventoryOffsetY		= 1;

CURSOR_POSITION sInventoryCursor[] = {
	{ 1, 2, false },
	{ 2, 2, false },
	{ 3, 2, false },
	{ 4, 2, false },
	{ 5, 2, false },
	{ 6, 2, false },
};

//////////////////
// Alert Window //
//////////////////

// Alert Window Dimensions
const int cnAlertWindowWidth 	= 25;
const int cnAlertWindowHeight 	= 9;

// Alert Window Offset
const int cnAlertOffsetX 		= 43;	// was 14
const int cnAlertOffsetY 		= 1;	// was 4

///////////////////
// Status Window //
///////////////////
const int cnStatusWindowWidth	= 20;
const int cnStatusWindowHeight	= 15;

const int cnStatusOffsetX		= 43;
const int cnStatusOffsetY		= 1;

///////////////////
// Yes/No Window //
///////////////////

const int cnYesNoWindowWidth	= 8;
const int cnYesNoWindowHeight	= 4;

const int cnYesNoOffsetX		= 43;
const int cnYesNoOffsetY		= 10;

// Array for holding the cursor position in the YesNo window
CURSOR_POSITION sYesNoCursor[] = {
	{ 1, 1, false },	// (0) cnAnswerYes
	{ 2, 1, false },	// (1) cnAnswerNo
};

#endif // WINDOW_LAYOUTS_H