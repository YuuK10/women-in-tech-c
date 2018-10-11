#include "game_functions.h"
void player_function()
{
	int i;
	int j;

	i = 1;
	while (i < 4)
	{
		j = 0;
		while (j < 8)
		{
			walk(RIGHT);
			j++;
		}

		j = 0;
		while (j < 8)
		{
			walk(DOWN);
			j++;
		}

		j = 0;
		while (j < 8)
		{
			walk(UP);
			j++;
		}

		//Essaie de compléter le niveau à partir d'ici...

		i++;
	}
}
