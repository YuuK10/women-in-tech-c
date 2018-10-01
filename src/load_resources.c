#include "game.h"

int					load_resources(t_game_element ***elements)
{
	t_game_element **element_array;
	char			*file_line;
	int				line_count;
	size_t			len;
	FILE			*fd;

	fd = fopen(RESOURCE_PATH, "r");
	if(fd == NULL)
	{
		show_error(3);
		return (0);
	}

	line_count = count_file_lines(fd);
	fseek(fd, 0, SEEK_SET);

	element_array = malloc((line_count + 1) * sizeof(t_game_element*));

	file_line = NULL;
	for (int i = 0 ; getline(&file_line, &len, fd) != -1 ; i++)
	{
		element_array[i] = split_data(file_line);
		if (load_sprite(element_array[i]) == 0)
		{
			//fclose(fd);
			return (0);
		}
	}

	element_array[line_count] = NULL;

	//fclose(fd);
	free(file_line);
	*elements = element_array;
	return (1);
}

t_game_element		*split_data(char *data_string)
{
	t_game_element	*game_element;
	char		*data_element[5];
	char		i;

	i = 1;
	data_element[0] = data_string;
	while (*data_string != '\n' && *data_string != '\0')
	{
		if (*data_string == '\t')
		{
			data_element[i] = data_string + 1;
			*data_string = '\0';
			i = i + 1;
		}
		data_string++;
	}
	*data_string = '\0';

	game_element = malloc(sizeof(t_game_element));
	if (game_element == NULL)
		return (NULL);

	game_element->blockable = *data_element[4];
	game_element->id = *data_element[0];
	game_element->name = strdup(data_element[1]);
	game_element->sprite_filename = strdup(data_element[2]);
	game_element->behavior = strdup(data_element[3]);


	return(game_element);
}

void			print_game_element(t_game_element *game_element)
{
	erase();
	printw("addr_name : %p\n", game_element->name);
	printw("id : %c\n", game_element->id);
	printw("name : %s\n", game_element->name);
	printw("sprite_filename : %s\n", game_element->sprite_filename);
	printw("behavior : %s\n", game_element->behavior);
	printw("blockable : %c\n\n", game_element->blockable);
	for (int y = 0 ; y < cell_dimensions.y ; y++)
	{
		printw("%s\n", game_element->sprite[y]);
	}
	refresh();
	getch();
}
