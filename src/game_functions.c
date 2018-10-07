#include "game.h"
#include "game_functions.h"

void	walk(int direction)
{
	switch (direction)
	{
		case LEFT:
			append_action(WALK_LEFT, "walk(LEFT)");
			break;
		case RIGHT:
			append_action(WALK_RIGHT, "walk(RIGHT)");
			break;
		case UP:
			append_action(WALK_UP, "walk(UP)");
			break;
		case DOWN:
			append_action(WALK_DOWN, "walk(DOWN)");
			break;
	}
}

void	open_door(int direction)
{
	switch (direction)
	{
		case LEFT:
			append_action(OPEN_DOOR_LEFT, "open_door(LEFT)");
			break;
		case RIGHT:
			append_action(OPEN_DOOR_RIGHT, "open_door(RIGHT)");
			break;
		case UP:
			append_action(OPEN_DOOR_UP, "open_door(UP)");
			break;
		case DOWN:
			append_action(OPEN_DOOR_DOWN, "open_door(DOWN)");
			break;
	}
}

void 	*play_thread(void *thread_done)
{
	player_function();
	*((int*)thread_done) = 1;
	pthread_exit(NULL);
}
