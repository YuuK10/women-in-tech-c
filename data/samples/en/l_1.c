#include "game_functions.h"

/*	Welcome in your first C code file !
**
**	What you see just right down there is called a function. A function
**	is basically a piece of code that will be executed by a program.
**
**	You'll need to write the instructions for Archimede between those {
**	and } brackets, and of course, you should not delete them, or the
**	program wont even read your code, and will throw what we call a
**	"compilation error".
**
**	As you can see, there is already an instruction written.
**	The function :

**			walk(direction)

**	is the first function you will have to use in this adventure, and will tell
**	Archimede to walk one step in the direction you choose. You should write the
**	direction between the ( and ) brackets in uppercase (LEFT, RIGHT, UP, DOWN).
**
**	-----------------------------------------------------------------------
**	You are currently using the VIM text editor.
**	In order to edit the file, you need to press I on your keyboard. You
**	will then enter the "INSERT" mode (see on the bottom on the screen).
**
**	To leave the "INSERT" mode, you need to press the ESC button.
**
**	To save and quit this file, you have to leave the "INSERT" mode (see
**	if "-- INSERT --" is written on the bottom of your screen or not), and
**	type ":x" (without the double quotes, and yes, WITH the double dots)
**	and press enter.
**	-----------------------------------------------------------------------
**
**	One last thing : every C instruction must be followed by a semi-collon
**	(;) in order to be valid.
**
**	Maybe you should leave this file and type "playgame" into the terminal,
**	just to see what the first level looks like, and what this walk(RIGHT)
**	function does. Then, come back to this file by typing "editcode", and
**	add the instructions needed to finish the level.
**
**	Good luck !
**/

void player_function()
{
	walk(RIGHT);
}
