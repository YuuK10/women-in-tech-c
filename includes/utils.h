#ifndef UTILS_H
# define UTILS_H

#include "data.h"

char 			*strjoin(char *str1, char *str2);
int				count_file_lines(FILE *file);

t_game_element	*find_element_by_id(char id, t_game_element **game_elements);
t_game_element	*find_element_by_name(char *name, t_game_element **game_elements);

t_game_element	*get_element_at_position(t_vector2d position);

t_game_element	*split_data(char *data_string);

void			print_game_element(t_game_element *game_element);

#endif
