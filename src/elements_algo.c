#include "game.h"

t_game_element *find_element_by_id(char id, t_game_element **elements)
{
	if (elements == NULL || elements[0] == NULL)
		return (NULL);

	for (int i = 0 ; elements[i] != NULL ; i++)
	{
		printw("%c", elements[i]->id);
		refresh();
		getch();
		if (elements[i]->id == id)
			return (elements[i]);
	}

	return (NULL);
}
