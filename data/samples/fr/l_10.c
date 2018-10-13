#include "game_functions.h"

/*
**	Une boucle est un bout de code qui se repete tant qu'une condition est
**	verifiee.
**
**	On peut l'ecrire comme ceci :
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
