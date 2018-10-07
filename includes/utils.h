#ifndef UTILS_H
# define UTILS_H

#include "data.h"

char 			*strjoin(char *str1, char *str2);
int				count_file_lines(FILE *file);

t_game_element	*find_element_by_id(char id, t_game_element **game_elements);
t_game_element	*find_element_by_name(char *name, t_game_element **game_elements);

t_level_element	*get_level_by_name(char *name);

t_vector2d		get_pos_by_id(char **map_array, char spawn_id);

t_game_element	*split_data(char *data_string);

t_color			hexa_to_color(char *hexa);

void			print_game_element(t_game_element *game_element);
void			print_menu(int paused, int fast_forward);

#endif
