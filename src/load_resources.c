#include "game.h"

int					load_resources(t_game_element **element_array)
{
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

	element_array = malloc(line_count * sizeof(t_game_element*));

	file_line = NULL;
	for (int i = 0 ; getline(&file_line, &len, fd) != -1 ; i++)
	{
		element_array[i] = split_data(file_line);
		//if (resource != NULL)
		//	print_game_element(resource);
		free(file_line);
	}

	free(file_line);
	fclose(fd);
	return (1);
}

t_game_element		*split_data(char *data_string)
{
	t_game_element	*game_element;
	char		*data_element[5];
	char		i;
	
	erase();
	printw("data string : %s\n\n", data_string);
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

	game_element = malloc(sizeof(game_element));
	if (game_element == NULL)
		return (NULL);
	game_element->id = *data_element[0];
	printw("data_element[1] : %s\n\n", data_element[1]);
	game_element->name = strdup(data_element[1]);
	//printf("name_1 : %s\n", game_element->name);
	game_element->sprite_filename = strdup(data_element[2]);
	//printf("name_2 : %s\n", game_element->name);
	game_element->interractable = *data_element[3];
	//printf("name_3 : %s\n", game_element->name);
	game_element->blockable = *data_element[4];
	//printf("name_4: %s\n", game_element->name);
	//printf("addr_name : %p\n", game_element->name);
	print_game_element(game_element);
	refresh();
	getch();
	
	return(game_element);
}

void			print_game_element(t_game_element *game_element)
{
	printw("addr_name : %p\n", game_element->name);
	printw("id : %c\n", game_element->id);
	printw("name : %s\n", game_element->name);
	printw("sprite_filename : %s\n", game_element->sprite_filename);
	printw("interractable : %c\n", game_element->interractable);
	printw("blockable : %c\n\n", game_element->blockable);
}
