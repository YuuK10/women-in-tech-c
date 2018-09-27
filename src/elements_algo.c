#include "game.h"

t_game_element *find_element_by_id(char id, t_game_element **elements)
{
	int i = 0;

	if (elements == NULL || elements[0] == NULL)
		return (NULL);

	while (elements[i] != NULL)
	{
		if (elements[i]->id == id)
			return (elements[i]);
		i++;
	}
}
