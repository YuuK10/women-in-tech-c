#include "game.h"

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

void print_cell(t_vector2d position, char** sprite, int pair)
{
	attron(COLOR_PAIR(pair));
	for (int i = 0 ; i < cell_dimensions.y ; i++)
	{
		mvprintw(top_margin + position.y * cell_dimensions.y + i, \
				left_margin + position.x * cell_dimensions.x, \
				"%s", sprite[i]);
	}
	attroff(COLOR_PAIR(pair));
}

void print_player()
{
	print_cell(player.position, player.sprite, player.color_pair);
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
			{
				t_game_element *element = find_element_by_id(map_array[y][x], game_elements);
				print_cell(position, element->sprite, element->color_pair);
			}
		}
	}
}
