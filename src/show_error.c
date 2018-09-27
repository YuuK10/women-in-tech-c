#include "game.h"

void show_error(int error_code)
{
	switch (error_code)
	{
		case 0: // Bad level name
			printw("Error while loading the level - level not found\n \
					Did misstyped the name in the arguments ?\n\n \
					Error code : 0");
			break;
		case 1: // File permissions problem
			printw("Error while loading the level - permission denied\n\n \
					Error code : 1");
			break;
		case 2: // Bad map format
			printw("Error while loading the level - bad format\n\n \
					Error code : 2");
			break;
		case 3: // Resource file not found
			printw("Error while loading the level - ressource not found\n\n \
					Error code : 3");
			break;
		
		default:
			printw("An unknown error has occured.\n\n");
			printw("Error code : %d", error_code);
	}

	printw("\nPress any key to exit");
	refresh();
	getch();
}
