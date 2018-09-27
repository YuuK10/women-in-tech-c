#ifndef GAME_H
# define GAME_H

#include <ncurses.h>

typedef	struct	s_sprites {
	int	id;
	char	*name;
	char	sprites;
}		t_sprites;


void show_instructions();
void show_error();

int load_level(char *level_name);

#endif
