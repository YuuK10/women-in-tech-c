#ifndef DATA_H
# define DATA_H

typedef struct	s_vector2d
{
	int x;
	int y;
}				t_vector2d;

typedef	struct	s_game_element
{
	char	id;
	char	*name;
	char	**sprite;
}				t_game_element;

typedef struct	s_player
{
	t_vector2d position;
	char	**sprite;
}				t_player;

static const t_vector2d map_dimensions = {25, 20};
static const t_vector2d cell_dimensions = {7, 4};
static const int left_margin = 0; // Margin between the map and the screen's edges
static const int top_margin = 0;

#endif
