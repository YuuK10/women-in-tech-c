#include "game.h"

void exec_next()
{
	if (last_action != NULL)
	{
		switch (last_action->type)
		{
			case WALK_LEFT:
				exec_walk_left();
				break;
			case WALK_RIGHT:
				exec_walk_right();
				break;
			case WALK_UP:
				exec_walk_up();
				break;
			case WALK_DOWN:
				exec_walk_down();
				break;
		}
	}
}
