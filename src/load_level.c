#include "game.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

t_level_element	**level_list = NULL;
char			*level_name = NULL;

int				check_file_line_count()
{
	FILE *fd;
	t_level_element *level;
	int line_count;
	int max;

	fd = fopen(PLAYER_FUNCTION_FILE, "r");
	if (fd == NULL)
	{
		show_error(10);
		return (0);
	}

	line_count = count_file_lines(fd);
	if ((level = get_level_by_name(level_name)) == NULL)
	{
		show_error(0);
		return (0);
	}

	max = atoi(level->max_line_count);

	if (line_count > max && max > 0)
	{
		show_error(11);
		return (0);
	}

	return (1);
}

int				check_level_availability()
{
	int i;
	int available;
	int found;

	i = 0;
	available = 1;
	found = 0;

	while (level_list[i] != NULL)
	{
		if (strcmp(level_list[i]->name, level_name) == 0)
			return (1);
		if (level_list[i]->status == '0')
		{
			show_error(9);
			return (0);
		}
		i++;
	}

	show_error(9);
	return (0);
}

t_level_element	*split_level_data(char *data_string)
{
	t_level_element	*level_element;
	char		*data_element[3];
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

	level_element = malloc(sizeof(t_level_element));
	if (level_element == NULL)
		return (NULL);

	level_element->name = strdup(data_element[0]);
	level_element->status = *data_element[1];
	level_element->max_line_count = strdup(data_element[2]);

	return (level_element);
}

int			load_level_list()
{
	FILE	*fp;
	int		line_count;
	char	*line;
	size_t	len;

	if (level_list != NULL)
		return (1);

	fp = fopen(LEVEL_LIST_PATH, "r");
	if (fp == NULL)
	{
		show_error(7);
		return (0);
	}

	line_count = count_file_lines(fp);
	fseek(fp, 0, SEEK_SET);

	level_list = malloc((line_count + 1) * sizeof(t_level_element*));
	for (int i = 0 ; getline(&line, &len, fp) != -1 ; i++)
		level_list[i] = split_level_data(line);

	level_list[line_count] = NULL;

	fclose(fp);
	return (1);
}

t_vector2d		get_map_dimensions(FILE *fp)
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

int			load_level(char *level, char ***map_array)
{
	char **level_array;
	FILE *fp;
	char *filename;
	char *line = NULL;
	size_t len = 0;
	int read;
	int current_line;
	t_vector2d dimensions;

	level_name = level;

	if (!load_level_list())
		return (0);

	if (!check_file_line_count())
		return (0);

	if (!DEVELOPER_MODE && !check_level_availability())
		return (0);

	filename = strjoin("data/levels/", level_name);
	fp = fopen(filename, "r");
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
	*map_array = level_array;
	return (1);
}
