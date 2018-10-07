#include "game.h"

void clear_actions()
{
	t_game_action *current;
	t_game_action *next;
	if (action_list != NULL)
	{
		current = action_list;
		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
		}

		action_list = NULL;
	}
}
