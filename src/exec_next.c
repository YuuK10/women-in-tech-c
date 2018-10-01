#include "game.h"

void exec_next(char **map_array, t_game_element **game_elements)
{
	if (last_action != NULL)
	{
		switch (last_action->type)
		{
			case WALK_LEFT:
				exec_walk_left(map_array, game_elements);
				break;
			case WALK_RIGHT:
				exec_walk_right(map_array, game_elements);
				break;
			case WALK_UP:
				exec_walk_up(map_array, game_elements);
				break;
			case WALK_DOWN:
				exec_walk_down(map_array, game_elements);
				break;
		}
	}
}
