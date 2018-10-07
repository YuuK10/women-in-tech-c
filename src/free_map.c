#include "game.h"

void free_map(char **map_array)
{
	for (int y = 0 ; y < map_dimensions.y ; y++)
	{
		free(map_array[y]);
	}
	free(map_array);
}
