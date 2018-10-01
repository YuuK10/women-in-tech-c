#include <stdio.h>
#include "game.h"

int main(int argc, char **argv)
{
	initscr();
	noecho();
	raw();

	char **map_array;
	t_game_element **elements;
	int		i = 0;

	if (argc == 2)
	{
		if (load_level(argv[1], &map_array) && load_resources(&elements))
		{
			play(map_array, elements);
		}
	}
	else if (argc > 2)
		printf("Too many arguments...");
	else
		show_instructions();
	endwin();
	return (0);
}
