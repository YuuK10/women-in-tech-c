#include "game_functions.h"

/*
**	A loop is a piece of code that will be repeated, until a
**	condition becomes false.
**
**	It is written like this :
**	while (condition)
**	{
**		code to execute
**	}
**/

void player_function()
{
	int iterator; //We declare a variable named iterator

	iterator = 1; //We set the value of 1 to iterator
	while (iterator <= 20) //While iterator is < or = 20, do the following code
	{
		//Maybe something is missing to complete the level...
		//At each execution of the loop, the iterator will increment,
		//until it reaches finally 20 and exit the loop
		iterator = iterator + 1;
	}
}
