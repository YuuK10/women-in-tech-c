#include "game.h"

int main(int argc, char **argv)
{
	char			**map_array;
	t_game_element	**elements;
	int				i = 0;
	int				playing = 1;

	initscr();
	start_color();
	noecho();
	raw();

	if (argc == 2 && load_resources(&elements))
	{
		while (playing)
		{
			if (load_level(argv[1], &map_array))
			{
				playing = play(map_array, elements);
				free_map(map_array);
			}
		}
	}
	else if (argc > 2)
		printf("Too many arguments...");
	else
		show_instructions();
	endwin();
	return (0);
}
