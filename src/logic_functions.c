#include "game.h"

int	is_victorious(t_vector2d exit_pos)
{
	if (exit_pos.x == player.position.x && exit_pos.y == player.position.y)
		return (1);
	else
		return (0);
}

void exec_walk_up(char **map_array, t_game_element **game_elements)
{
	if (player.position.y != 0 &&
		find_element_by_id(map_array[player.position.y - 1][player.position.x], \
			game_elements)->blockable == '0')
		player.position.y--;
}

void exec_walk_down(char **map_array, t_game_element **game_elements)
{
	if (player.position.y != map_dimensions.y - 1 &&
		find_element_by_id(map_array[player.position.y + 1][player.position.x], \
			game_elements)->blockable == '0')
		player.position.y++;
}

void exec_walk_left(char **map_array, t_game_element **game_elements)
{
	if (player.position.x != 0 &&
		find_element_by_id(map_array[player.position.y][player.position.x - 1], \
			game_elements)->blockable == '0')
		player.position.x--;
}

void exec_walk_right(char **map_array, t_game_element **game_elements)
{
	if (player.position.x != map_dimensions.x - 1 &&
		find_element_by_id(map_array[player.position.y][player.position.x + 1], \
			game_elements)->blockable == '0')
	{
		player.position.x++;
	}
}

void	exec_open_door_right(char **map_array, t_game_element **game_elements)
{
	if (player.position.x != map_dimensions.x - 1 &&
		strcmp(find_element_by_id(map_array[player.position.y][player.position.x + 1],
		game_elements)->behavior, "door") == 0)
		{
			map_array[player.position.y][player.position.x + 1] =
				find_element_by_name("door_open", game_elements)->id;
		}
}

void	exec_open_door_left(char **map_array, t_game_element **game_elements)
{
	if (player.position.x != 0 &&
		strcmp(find_element_by_id(map_array[player.position.y][player.position.x - 1],
		game_elements)->behavior, "door") == 0)
		{
			map_array[player.position.y][player.position.x - 1] =
				find_element_by_name("door_open", game_elements)->id;
		}
}

void	exec_open_door_up(char **map_array, t_game_element **game_elements)
{
	if (player.position.y != 0 &&
		strcmp(find_element_by_id(map_array[player.position.y - 1][player.position.x],
		game_elements)->behavior, "door") == 0)
		{
			map_array[player.position.y - 1][player.position.x] =
				find_element_by_name("door_open", game_elements)->id;
		}
}

void	exec_open_door_down(char **map_array, t_game_element **game_elements)
{
	if (player.position.y != map_dimensions.x - 1 &&
		strcmp(find_element_by_id(map_array[player.position.y + 1][player.position.x],
		game_elements)->behavior, "door") == 0)
		{
			map_array[player.position.y + 1][player.position.x] =
				find_element_by_name("door_open", game_elements)->id;
		}
}
