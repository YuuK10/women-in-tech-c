#include "game_functions.h"

/*
**	Une boucle est un bout de code qui repete une instruction
**	ou des instruction tant que la condition est correcte ou
**	que la condition deviennent fausse.
**
**	On ecrit une boucle de la maniere suivante :
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
