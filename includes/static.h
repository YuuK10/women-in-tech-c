#ifndef STATIC_H
# define STATIC_H

extern t_game_action	*first_action;
extern t_game_action	*action_list;
extern t_game_action	*last_action;

extern t_level_element	**level_list;
extern char				*level_name;

extern char				*last_action_text;
extern char				*current_action_text;
extern char				*next_action_text;

extern t_player player;

#endif
