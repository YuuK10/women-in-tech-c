#include "game_functions.h"

/*
**	Een lus is een stuk code dat wordt herhaald totdat de voorwaarde False is.
**
**	Het is geschreven als volgt:
**	while (voorwaarde)
**	{
**		code uit te voeren
**	}
**/

void player_function()
{
	int iterator; //Hier declareren we variabele genoemd "iterator"

	iterator = 1; //Hier geven we de waarde 1 aan iterator
	while (iterator <= 20) //While iterator is < or = 20, doe de volgende code
	{
		//Misschien missen we iets om de level te eindigen...
		//Bij elke uitvoering van de lus wordt de iterator 1 groter totdat het 20
		//bereikt en de lus eindigt.
		iterator = iterator + 1;
	}
}
