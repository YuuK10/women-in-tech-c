#include "game.h"

void update_action_text()
{
	if (action_list != NULL)
	{
		last_action_text = current_action_text;
		current_action_text = action_list->text;
		if (action_list->next != NULL)
			next_action_text = action_list->next->text;
		else
			next_action_text = "END";
	}
	else
	{
		last_action_text = current_action_text;
		current_action_text = "END";
		next_action_text = NULL;
	}
}

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

		update_action_text();
		action_list = action->next;


		//free(action);
	}
	
	/*
		Ce code est absolument degueulasse !
		Je coooode avec le cuuuuul...
	*/
	else if (strcmp(current_action_text, "END") != 0)
	{
		update_action_text();
	}
}
