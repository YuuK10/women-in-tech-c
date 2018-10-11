/*
**	Since you started, you could see these lines with stars at the beggining.
**	These are called COMMENTS.
**
**	Comments are really usefull to explain your code, but they have absolutely
**	no effect on it. It also means that you can delete them if you have too
**	may lines in your code file...
**
**	There are two types of comments in C. You can see an example of each of
**	them below.
**/

#include "game_functions.h"
void player_function()
{
	/*
	** This is a multi line comment.
	** This one is used for big comments.
	*/

	// This one is a single line comment.

	walk(LEFT); // Single line comments can also be placed after instructions.
	walk(LEFT);
	walk(LEFT);
	walk(LEFT);
	walk(LEFT);
	walk(LEFT);
}
