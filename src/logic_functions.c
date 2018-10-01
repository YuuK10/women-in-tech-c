#include "game.h"

void exec_walk_up(char **map_array, t_game_element **game_elements)
{
	if (player.position.y != 0 &&
		!find_element_by_id(map_array[player.position.y - 1][player.position.x], \
			game_elements)->blockable)
		player.position.y--;
}

void exec_walk_down(char **map_array, t_game_element **game_elements)
{
	if (player.position.y != map_dimensions.y - 1 &&
		!find_element_by_id(map_array[player.position.y + 1][player.position.x], \
			game_elements)->blockable)
		player.position.y++;
}

void exec_walk_left(char **map_array, t_game_element **game_elements)
{
	if (player.position.x != 0 &&
		!find_element_by_id(map_array[player.position.y][player.position.x - 1], \
			game_elements)->blockable)
		player.position.x--;
}

void exec_walk_right(char **map_array, t_game_element **game_elements)
{
	if (player.position.x != map_dimensions.x - 1 &&
		!find_element_by_id(map_array[player.position.y][player.position.x + 1], \
			game_elements)->blockable)
		player.position.x++;
}
