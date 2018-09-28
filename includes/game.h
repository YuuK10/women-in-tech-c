#ifndef GAME_H
# define GAME_H

#include <ncurses.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "data.h"

#define	RESOURCE_PATH		"data/data_elements"
#define	NUMBER_OF_ELEMENTS	5
#define ASSETS_PATH			"data/assets/"


void 			show_instructions();
void 			show_error();

int 			load_level(char *level_name, char** level_array);
t_game_element	*load_resources(t_game_element **element_array);

#endif
