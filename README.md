# dw-roguelike
A roguelike based on the original Dragon Warrior.

Sorry, no make file yet, compile with:
$ g++ -std=c++14 main.cpp -lcurses -Iinclude

If you do compile the code, the controls are:
Arrow keys
	up is up, down is down, left is left, right is right
x - select
z - cancel
q - brings up the quit dialog, I may get rid of this at some point, or at the very least intend to change the way it works

This should run fine in Mac OS, Linux will display names oddly as it handles undefined spaces in names differently.