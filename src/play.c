#include "game.h"

t_game_action *action_list = NULL;
t_game_action *last_action = NULL;
t_player player;

void print_victory()
{
	/*FILE *fd;
	char *line;
	size_t len;

	fd = fopen(VICTORY_FILE, "r");
	if (fd == NULL)
	{*/
		mvprintw(0, 0, "Level complete !");
		return;
	/*}
	move(3, 0);
	while (getline(&line, &len, fd) != -1)
	{
		printw(line);
	}

	fclose(fd);*/
}

void print_cell(t_vector2d position, char** sprite)
{
	for (int i = 0 ; i < cell_dimensions.y ; i++)
	{
		mvprintw(top_margin + position.y * cell_dimensions.y + i, \
				left_margin + position.x * cell_dimensions.x, \
				"%s", sprite[i]);
	}
}

void print_player()
{
	print_cell(player.position, player.sprite);
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
	int 		playing = 1;
	int			game_status = 1;
	int 		input;
	int			thread_done = 0;
	pthread_t	init_player_action;
	clock_t time = clock();

	if(pthread_create(&init_player_action, NULL, &play_thread, &thread_done) == -1)
	{
		show_error(6);
	}
	while ((clock() - time) * 1000 / CLOCKS_PER_SEC < TIMEOUT_PLAYER_FUNCTION && thread_done == 0)
	{

	}
	if (thread_done == 0)
	{
		//kill that thread
		pthread_cancel(init_player_action);
	}

	player.sprite = find_element_by_name("player", game_elements)->sprite;
	player.position = get_pos_by_id(map_array, \
		find_element_by_name("spawn", game_elements)->id);

	t_vector2d exit_pos = get_pos_by_id(map_array,
		find_element_by_name("exit", game_elements)->id);

	time = clock();

	/* Main loop */
	while (playing)
	{
		clock_t delta_time = (clock() - time) * 1000 / CLOCKS_PER_SEC;
		erase();

		if (game_status && delta_time >= EXEC_DELAY && !is_victorious(exit_pos))
		{
			time = clock();
			exec_next(map_array, game_elements);
		}

		/* Printing */

		print_map(map_array, game_elements);
		print_player();
		print_menu(game_status);

		if (is_victorious(exit_pos))
		{
			get_level_by_name(level_name)->status = '1';
			print_victory();
		}

		refresh();

		input = getch();
		if (input == 'q')
			playing = 0;
		else if (input == 'p' && game_status == 1)
			game_status = 0;
		else if (input == 'p' && game_status == 0)
			game_status = 1;
	}

	save_level_list();
}
