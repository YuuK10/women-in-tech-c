#include "game.h"

t_game_element *find_element_by_id(char id, t_game_element **elements)
{
	if (elements == NULL || elements[0] == NULL)
		return (NULL);

	for (int i = 0 ; elements[i] != NULL ; i++)
	{
		if (elements[i]->id == id)
			return (elements[i]);
	}

	return (NULL);
}

t_game_element *find_element_by_name(char *name, t_game_element **elements)
{
	if (elements == NULL || elements[0] == NULL)
		return (NULL);

	for (int i = 0 ; elements[i] != NULL ; i++)
	{
		if (strcmp(elements[i]->name, name) == 0)
			return (elements[i]);
	}
	return (NULL);
}

t_level_element	*get_level_by_name(char *name)
{
	if (level_list == NULL || level_list[0] == NULL)
		return (NULL);

	for (int i = 0 ; level_list[i] != NULL ; i++)
	{
		if (strcmp(level_list[i]->name, name) == 0)
			return (level_list[i]);
	}
	return (NULL);
}

int		get_level_index_by_name(char *name, t_level_element **level)
{
	if (level == NULL || level[0] == NULL)
		return (-1);

	for (int i = 0 ; level[i] != NULL ; i++)
	{
		if (strcmp(level[i]->name, name) == 0)
			return (i);
	}
	return (-1);
}

t_vector2d		get_pos_by_id(char **map_array, char spawn_id)
{
	t_vector2d position = {-1, -1};
	for (int y = 0 ; y < map_dimensions.y ; y++)
	{
		for (int x = 0 ; x < map_dimensions.x ; x++)
		{
			if (map_array[y][x] == spawn_id)
			{
				position.x = x;
				position.y = y;
				return (position);
			}
		}
	}

	return (position);
}

t_color			hexa_to_color(char *hexa)
{
	t_color color = {0, 0, 0};
	char *code;

	if (strlen(hexa) >= 6)
	{
		code = strndup(hexa, 2);
		color.r = strtol(code, NULL, 16);
		free(code);
		hexa += 2;

		code = strndup(hexa, 2);
		color.g = strtol(code, NULL, 16);
		free(code);
		hexa += 2;

		code = strndup(hexa, 2);
		color.b = strtol(code, NULL, 16);
		free(code);
	}

	else
	{
		erase();
		printw("%d", strlen(hexa));
		refresh();
		timeout(-1);
		getch();
		timeout(0);
		//show_error(-1);
	}

	return (color);
}
