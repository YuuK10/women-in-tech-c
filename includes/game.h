#ifndef GAME_H
# define GAME_H

#include <ncurses.h>
#include "utils.h"
#include "data.h"



void show_instructions();
void show_error();

int load_level(char *level_name, char** level_array);

#endif
