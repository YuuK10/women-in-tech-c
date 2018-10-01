#include "game.h"

void append_action(t_action_type action, char *arg)
{
    t_game_action *elem;
    if((elem = malloc(sizeof(t_game_action))) <= 0)
        return;

    elem->type = action;
    elem->arg = arg;
    elem->next = NULL;
    if (action_list == NULL)
    {
        last_action = elem;
        action_list = elem;
    }
    else
    {
        last_action->next = elem;
        last_action = elem;
    }
}
