#include "game.h"

void show_error(int error_code)
{
	erase();
	switch (error_code)
	{
		case 0: // Bad level name
			printw("Error while loading the level - level not found\n\n");
			break;
		case 1: // File problems
			printw("Error while loading the level - cannot open the level\n\n");
			break;
		case 2: // Bad map format
			printw("Error while loading the level - bad format\n\n");
			break;
		case 3: // Resource file not found
			printw("Error while loading resources - ressource not found");
			break;
		case 4: // Sprite problem
			printw("Error while loading resources - cannot read sprite\n\n");
			break;
		case 5: // Sprite size not fitting the map cells
			printw("Error while loading resources - bad sprite size\n\n");
			break;
		case 6: // Thread error
			printw("Error while creating thread\n\n");
			break;
		case 7: // Cannot open data_level
			printw("Error while loading level - cannot open data levels file\n\n");
			break;
		case 8: // Cannot write data_level
			printw("Error while saving level - cannot write to levels file\n\n");
			break;
		case 9: // Cannot write data_level
			printw("This level is still locked (or is inexistant).\nAre you trying to cheat, you little asshole ? x)\n\n");
			break;
		case 10:
			printw("Error while checking player function - cannot open file\n\n");
			break;
		case 11:
			printw("Too many lines in the player function file.\nYou may try to find a way to reduce it a bit :)\n\n");
			break;
		default:
			printw("An unknown error has occured.\n\n");
	}

	printw("Error code : %d\n", error_code);

	printw("Press any key to exit");
	refresh();
	timeout(-1);
	getch();
	timeout(0);
}
