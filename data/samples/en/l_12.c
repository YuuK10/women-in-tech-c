#include "game_functions.h"
void player_function()
{
	int i;
	int j;

	i = 1;
	while (i < 2)
	{
		j = 0;
		while (j < 8)
		{
			walk(UP);
			j++;
		}
		j = 0;
		//Try to complete the code from here...
		i++;
	}
}
