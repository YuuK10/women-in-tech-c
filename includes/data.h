#ifndef DATA_H
# define DATA_H

typedef enum	e_action_type
{
	WALK_LEFT,
	WALK_RIGHT,
	WALK_UP,
	WALK_DOWN,
	OPEN_DOOR_LEFT,
	OPEN_DOOR_RIGHT,
	OPEN_DOOR_UP,
	OPEN_DOOR_DOWN
}				t_action_type;

typedef struct	s_vector2d
{
	int x;
	int y;
}				t_vector2d;

typedef struct	s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}				t_color;

typedef struct	s_game_element
{
	char	id;
	char	blockable;
	t_color	foreground_color;
	t_color	background_color;
	int		color_pair;
	char	*behavior;
	char	*name;
	char	*sprite_filename;
	char	**sprite;
}				t_game_element;

typedef struct	s_player
{
	t_vector2d	position;
	int			color_pair;
	char		**sprite;
}				t_player;

typedef struct	s_game_action
{
	t_action_type			type;
	char					*text;
	struct s_game_action	*next;
}				t_game_action;

typedef struct	s_level_element
{
	char				*name;
	char				status;
	char				*max_line_count;
}				t_level_element;

static const t_vector2d map_dimensions = {25, 19};
static const t_vector2d cell_dimensions = {7, 4};
static const int left_margin = 0; // Margin between the map and the screen's edges
static const int top_margin = 3;

#endif
