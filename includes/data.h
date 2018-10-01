#ifndef DATA_H
# define DATA_H

typedef enum	e_action_type
{
	WALK_LEFT,
	WALK_RIGHT,
	WALK_UP,
	WALK_DOWN
}				t_action_type;

typedef struct	s_vector2d
{
	int x;
	int y;
}				t_vector2d;

typedef struct	s_game_element
{
	char	id;
	char	blockable;
	char	*behavior;
	char	*name;
	char	*sprite_filename;
	char	**sprite;
}				t_game_element;

typedef struct	s_player
{
	t_vector2d	position;
	char		**sprite;
}				t_player;

typedef struct	s_game_action
{
	t_action_type			type;
	char					*arg;
	struct s_game_action	*next;
}				t_game_action;

static const t_vector2d map_dimensions = {25, 20};
static const t_vector2d cell_dimensions = {7, 4};
static const int left_margin = 0; // Margin between the map and the screen's edges
static const int top_margin = -1;

#endif
