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
#define PLAYER_FUNCTION_FILE		"src/player_function.c"
#define	NUMBER_OF_ELEMENTS			5
#define EXEC_DELAY					400
#define TIMEOUT_PLAYER_FUNCTION		100 //in ms
#define FAST_FORWARD_DELAY			100
#define DEVELOPER_MODE				0


void 			show_instructions();
void 			show_error();

int 			load_level(char *level_name, char*** level_array);
int				load_resources(t_game_element ***element_array);
int				load_sprite(t_game_element *element);
int				play(char **map_array, t_game_element **game_elements);
void			player_function();
int				is_victorious(t_vector2d exit_pos);
int				save_level_list();

void 			print_victory();
void 			print_cell(t_vector2d position, char** sprite, int pair);
void 			print_player();
void 			print_map(char **map_array, t_game_element **game_elements);
void 			print_action_bar();
void			update_action_text();

void			append_action(t_action_type action, char *text);

void 			*play_thread(void *thread_done);
void			free_map(char **map_array);
void			clear_actions();

#endif
