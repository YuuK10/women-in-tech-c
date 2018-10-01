#include "game.h"

void	print_menu(int game_status)
{
	if (game_status == PAUSED)
	{
		mvprintw(1, 1, "p : play\ts : step by step\tq : quit game");
		move(1, 174);
	}
	else
	{
		mvprintw(1, 1, "p : pause\ts : step by step\tq : quit game");
		move(1, 174);
	}
}
