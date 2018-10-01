#include "game.h"
#include "game_functions.h"

void	walk(int direction)
{
	switch (direction)
	{
		case LEFT:
			append_action(WALK_LEFT, NULL);
			break;
		case RIGHT:
			append_action(WALK_RIGHT, NULL);
			break;
		case UP:
			append_action(WALK_UP, NULL);
			break;
		case DOWN:
			append_action(WALK_DOWN, NULL);
			break;
	}
}

void 	*play_thread(void *arg)
{
	player_function();
	(void) arg;
	pthread_exit(NULL);
}
