#ifndef GAME_H
# define GAME_H

#include <ncurses.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include "utils.h"
#include "data.h"
#include "static.h"
#include "game_functions.h"
#include "logic_functions.h"


#define	RESOURCE_PATH		"data/data_elements"
#define	NUMBER_OF_ELEMENTS	5
#define EXEC_DELAY			500
#define ASSETS_PATH			"data/assets/"


#define	PAUSED			0


void 			show_instructions();
void 			show_error();

int 			load_level(char *level_name, char*** level_array);
int				load_resources(t_game_element ***element_array);
int				load_sprite(t_game_element *element);
void			play(char **map_array, t_game_element **game_elements);
void			player_function();

void			append_action(t_action_type action, char *arg);

t_vector2d		get_spawn_position(char **map_array, char spawn_id);

void 			*play_thread(void *arg);

#endif
