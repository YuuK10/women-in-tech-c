#include "game.h"

int	save_level_list()
{
	FILE *fd = NULL;

	fd = fopen(LEVEL_LIST_PATH, "w");
	if (fd == NULL)
	{
		show_error(8);
		return (0);
	}

	for (int i = 0 ; level_list[i] != NULL ; i++)
	{
		fwrite(level_list[i]->name, sizeof(char),
				strlen(level_list[i]->name), fd);
		fwrite("\t", sizeof(char), 1, fd);
		fwrite(&level_list[i]->status, sizeof(char), 1, fd);
		fwrite("\t", sizeof(char), 1, fd);
		fwrite(level_list[i]->max_line_count, sizeof(char),
				strlen(level_list[i]->max_line_count), fd);
		if (level_list[i + 1] != NULL)
			fwrite("\n", sizeof(char), 1, fd);
	}

	fclose(fd);
	return (1);
}
