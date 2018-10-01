#include "game.h"

void print_cell(t_vector2d position, char** sprite)
{
	for (int i = 0 ; i < cell_dimensions.y ; i++)
	{
		mvprintw(top_margin + position.y * cell_dimensions.y + i, \
				left_margin + position.x * cell_dimensions.x, \
				"%s", sprite[i]);
	}
}

void print_player(t_player *player)
{
	print_cell(player->position, player->sprite);
}

void print_map(char **map_array, t_game_element **game_elements)
{
	for (int y = 0 ; y < map_dimensions.y ; y++)
	{
		for (int x = 0 ; x < map_dimensions.x ; x++)
		{
			t_vector2d position = {x, y};
			if (find_element_by_id(map_array[y][x], game_elements) == NULL)
				printw("NULL");
			else
				print_cell(position, find_element_by_id(map_array[y][x], game_elements)->sprite);
		}
	}
}

void play(char **map_array, t_game_element **game_elements)
{
	int playing = 1;
	int	game_status = 1;
	int input;

	t_player player;
	player.sprite = find_element_by_name("player", game_elements)->sprite;
	player.position = get_spawn_position(map_array, \
		find_element_by_name("spawn", game_elements)->id);

	/* Main loop */
	while (playing)
	{
		erase();

		if (game_status)
		{
			/* Game logic */
			// TODO: Game logic
		}

		/* Printing */
		print_map(map_array, game_elements);
		print_player(&player);
		print_menu(game_status);

		refresh();

		input = getch();
		if (input == 'q')
			playing = 0;
		else if (input == 'p' && game_status == 1)
			game_status = 0;
		else if (input == 'p' && game_status == 0)
			game_status = 1;
	}
}
