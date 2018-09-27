#include <stdio.h>
#include "game.h"

int main(int argc, char **argv)
{
	initscr();
	noecho();
	if (argc == 2)
	{
		load_level(argv[1]);
	}
	else if (argc > 2)
		printf("Too many arguments...");
	else
		show_instructions();
	endwin();
	return (0);
}
