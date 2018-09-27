#ifndef DATA_H
# define DATA_H

typedef struct	s_vector2d
{
	int x;
	int y;
}				t_vector2d;

static const t_vector2d map_dimensions = {25, 20};

typedef	struct	s_sprites {
	int	id;
	char	*name;
	char	sprites;
}		t_sprites;


#endif
