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

void	open_door(int direction)
{
	switch (direction)
	{
		case LEFT:
			append_action(OPEN_DOOR_LEFT, NULL);
			break;
		case RIGHT:
			append_action(OPEN_DOOR_RIGHT, NULL);
			break;
		case UP:
			append_action(OPEN_DOOR_UP, NULL);
			break;
		case DOWN:
			append_action(OPEN_DOOR_DOWN, NULL);
			break;
	}
}

void 	*play_thread(void *thread_done)
{
	player_function();
	*((int*)thread_done) = 1;
	pthread_exit(NULL);
}
