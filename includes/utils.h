#ifndef UTILS_H
# define UTILS_H

#include "data.h"

char *strjoin(char *str1, char *str2);

t_game_element *find_element_by_id(char id, t_game_element **game_elements);

#endif
