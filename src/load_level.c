#include "game.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

t_vector2d get_map_dimensions(FILE *fp)
{
	char c;
	int column_counted;
	t_vector2d dimensions;

	dimensions.x = 0;
	dimensions.y = 0;
	column_counted = 0;

	while(c != EOF)
	{
		c = fgetc(fp);
		if (c == '\n')
		{
			dimensions.y++;
			column_counted = 1;
		}
		if (!column_counted)
			dimensions.x++;
	}
	return (dimensions);
}

int load_level(char *level_name, char*** level)
{
	char **level_array;
	FILE *fp;
	char *filename;
	char *line = NULL;
	size_t len = 0;
	int read;
	int current_line;
	t_vector2d dimensions;

	filename = strjoin("data/levels/", level_name);
	fp = fopen(filename, "r");
	//getch();
	free(filename);
	if (fp == NULL)
	{
		show_error(-1);
		return (0);
	}

	dimensions = get_map_dimensions(fp);
	if (dimensions.x != map_dimensions.x || dimensions.y != map_dimensions.y)
	{
		fclose(fp);
		show_error(2); // Bad format error
		return (0);
	}
	level_array = malloc(sizeof(char*) * map_dimensions.y);

	current_line = 0;
	fseek(fp, 0, SEEK_SET);
	while(getline(&line, &len, fp) != -1)
	{
		level_array[current_line] = line;
		line = NULL;
		current_line++;
	}

	fclose(fp);
	*level = level_array;
	return (1);
}
