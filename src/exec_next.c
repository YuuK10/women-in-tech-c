#include "game.h"

void exec_next(char **map_array, t_game_element **game_elements)
{
	t_game_action *action;
	if (action_list != NULL)
	{
		action = action_list;

		switch (action->type)
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
			case OPEN_DOOR_LEFT:
				exec_open_door_left(map_array, game_elements);
				break;
			case OPEN_DOOR_RIGHT:
				exec_open_door_right(map_array, game_elements);
				break;
			case OPEN_DOOR_UP:
				exec_open_door_up(map_array, game_elements);
				break;
			case OPEN_DOOR_DOWN:
				exec_open_door_down(map_array, game_elements);
				break;
		}

		action_list = action->next;
		free(action);
	}
}
