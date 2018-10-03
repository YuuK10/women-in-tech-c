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


#define	RESOURCE_PATH				"data/data_elements"
#define ASSETS_PATH					"data/assets/"
#define LEVEL_LIST_PATH				"data/data_level"
#define VICTORY_FILE				"data/assets/victory"
#define	NUMBER_OF_ELEMENTS			5
#define EXEC_DELAY					300
#define TIMEOUT_PLAYER_FUNCTION		500 //in ms


#define	PAUSED			0


void 			show_instructions();
void 			show_error();

int 			load_level(char *level_name, char*** level_array);
int				load_resources(t_game_element ***element_array);
int				load_sprite(t_game_element *element);
void			play(char **map_array, t_game_element **game_elements);
void			player_function();
int				is_victorious(t_vector2d exit_pos);
int				save_level_list();

void			append_action(t_action_type action, char *arg);

void 			*play_thread(void *thread_done);

#endif
