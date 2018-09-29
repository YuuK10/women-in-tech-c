#include "game.h"

/*
**	Loads the graphical representation of an element
**	Returns 1 (true) in case of success
**	Returns 0 (false) in case of error
**
**	An empty filename or a NULL reference to a game element
**	is NOT considered as an error, and will return 1;
*/

int	load_sprite(t_game_element *element)
{
	char	*filepath;
	char	*line = NULL;
	size_t	line_size;
	FILE	*file;

	if (element == NULL || element->sprite_filename == NULL || element->sprite_filename[0] == 0)
		return (1);

	filepath = strjoin(ASSETS_PATH, element->sprite_filename);
	file = fopen(filepath, "r");
	free(filepath);
	if (file == NULL)
	{
		show_error(4);
		return (0);
	}

	element->sprite = malloc(cell_dimensions.y * sizeof(char*));
	for (int y = 0 ; y < cell_dimensions.y ; y++)
	{
		getline(&line, &line_size, file);
		element->sprite[y] = malloc((cell_dimensions.x + 1) * sizeof(char));
		for (int x = 0 ; x < cell_dimensions.x ; x++)
		{
			if(line[x] == '\0' || line[x] == '\n')
			{
				fclose(file);
				if(line != NULL)
					free(line);
				show_error(5);
				return (0);
			}
			element->sprite[y][x] = line[x];
		}
	}

	fclose(file);
	return (1);
}
