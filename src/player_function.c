#include "game_functions.h"

/* walk(int dir)
 * open_door(int dir)
 *
 * UP, DOWN, LEFT, RIGHT
 */

void player_function()
{
	while (1)
	{
		walk(DOWN);
		walk(DOWN);
		open_door(RIGHT);
		walk(RIGHT);
		walk(RIGHT);
	}
}
