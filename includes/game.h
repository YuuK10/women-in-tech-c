#ifndef GAME_H
# define GAME_H

#include <ncurses.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "data.h"

#define	RESSOURCE_PATH	"data/data_elements"


void show_instructions();
void show_error();

int load_level(char *level_name, char** level_array);
t_game_element		*load_ressource(FILE *fd);

#endif
