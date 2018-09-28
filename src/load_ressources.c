#include "game.h"
#include <stdio.h>

t_game_element		*load_ressource(FILE *fd)
{
	t_game_element		*ressources = NULL;
	off_t			file_size;
	char			*file_to_string;
	char			tmp;
	int			i;

	i = 0;
	fseek(fd, 0, SEEK_END);
	file_size = ftell(fd);
	fseek(fd, 0, SEEK_SET);
	printf("file_size : %lld\n", file_size);
	file_to_string = (char *)malloc(file_size + 1);
	if (file_to_string == NULL)
		return (NULL);
	while (fread(&tmp, 1, 1, fd) != 0)
	{
		file_to_string[i] = tmp;
		i = i + 1;
	}
	printf("%s\n", file_to_string);
	return (ressources);
}
