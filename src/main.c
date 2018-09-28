#include <stdio.h>
#include "game.h"

int main(int argc, char **argv)
{
	initscr();
	noecho();

	char **map_array;
	t_game_element **elements;

	if (argc == 2)
	{
		load_level(argv[1], map_array);
		load_resources(elements);
	}
	else if (argc > 2)
		printf("Too many arguments...");
	else
		show_instructions();
	endwin();
	return (0);
}
