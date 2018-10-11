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
	int iterator; //On déclare une variable "iterator"

	iterator = 1; //On assigne la valeur de 1 a iterator
	while (iterator <= 20) //Tant que iterator <= 20, executer le code suivant...
	{
		//Peut être que quelque chose manque ici...
		//A la fin de chaque boucle, la variable iterator s'incremente
		//jusqu'a ce qu'elle atteigne 21, et que la boucle s'arrete.
		iterator = iterator + 1;
	}
}
