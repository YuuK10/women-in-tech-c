#include "game_functions.h"
void player_function()
{
	int direction;

	direction = DOWN;
	walk(direction);
	walk(direction);
	walk(direction);
	walk(direction);

	direction = UP;
	walk(direction);
	walk(direction);

	direction = RIGHT;
	walk(direction);
	walk(direction);

	direction = DOWN;
	walk(direction);
	walk(direction);

	direction = LEFT;
	walk(direction);
	walk(direction);
}
