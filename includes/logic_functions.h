#ifndef LOGICAL_FUNCTIONS_H
# define LOGICAL_FUNCTIONS_H

void exec_next(char **map_array, t_game_element **game_elements);

void exec_walk_up(char **map_array, t_game_element **game_elements);
void exec_walk_down(char **map_array, t_game_element **game_elements);
void exec_walk_left(char **map_array, t_game_element **game_elements);
void exec_walk_right(char **map_array, t_game_element **game_elements);
void exec_open_door_up(char **map_array, t_game_element **game_elements);
void exec_open_door_down(char **map_array, t_game_element **game_elements);
void exec_open_door_left(char **map_array, t_game_element **game_elements);
void exec_open_door_right(char **map_array, t_game_element **game_elements);

#endif
