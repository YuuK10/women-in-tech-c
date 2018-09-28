#include "game.h"
#include <stdio.h>

t_game_element		*load_ressource(t_game_element **element_array)
{
	t_game_element		*ressource;
	char			*file_line;
	size_t			size;
	size_t			len;
	FILE			*fd;

	fd = fopen(RESSOURCE_PATH, "r");
	file_line = NULL;
	while ((size = getline(&file_line, &len, fd)) != -1)
	{
		ressource = split_data(file_line);
		//if (ressource != NULL)
		//	print_game_element(ressource);
		free(ressource);
		ressource = NULL;
		printf("\n");
	}
	free(file_line);
	file_line = NULL;
	fclose(fd);
	return (ressource);
}

t_game_element		*split_data(char *data_string)
{
	t_game_element	*game_element;
	char		*data_element[5];
	char		i;

	i = 1;
	data_element[0] = data_string;
	while (*data_string != '\n')
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

	game_element = (t_game_element *)malloc(sizeof(game_element));
	if (game_element == NULL)
		return (NULL);
	game_element->id = *data_element[0];
	game_element->name = strdup(data_element[1]);
	printf("name_1 : %s\n", game_element->name);
	game_element->sprite_filename = strdup(data_element[2]);
	printf("name_2 : %s\n", game_element->name);
	game_element->interractable = *data_element[3];
	printf("name_3 : %s\n", game_element->name);
	game_element->blockable = *data_element[4];
	printf("name_4: %s\n", game_element->name);
	printf("addr_name : %p\n", game_element->name);
	print_game_element(game_element);
	return(game_element);
}

void			print_game_element(t_game_element *game_element)
{
	printf("addr_2 : %p\n", game_element->name);
	printf("id : %c\n", game_element->id);
	printf("name : %s\n", game_element->name);
	printf("sprite_filename : %s\n", game_element->sprite_filename);
	printf("interractable : %c\n", game_element->interractable);
	printf("blockable : %c\n", game_element->blockable);
}
