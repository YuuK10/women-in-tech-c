/*
**	Depuis que tu as commence, tu as pu voir des lignes qui commencent par des
**	etoiles. Ca s'appelle des COMMENTAIRES.
**
**	Les commentaires sont tres utiles pour expliquer ton code, mais ils n'ont
**	aucun effet sur celui-ci. Ca signifie aussi que tu peux les supprimer si tu
**	as trop de lignes dans ton fichier...
**
**	Il y a deux types de commentaires en C. Tu peux en voir un exemple de chaque
**	ci-dessous.
**/

#include "game_functions.h"
void player_function()
{
	/*
	** Ceci est un commentaire multi-lignes ou "de bloc".
	** Ils sont utilises pour les longs commentaires
	*/

	// Ceci est un simple commentaire de ligne

	walk(LEFT); // Ils peuvent aussi etre places apres les instructions
	walk(LEFT);
	walk(LEFT);
	walk(LEFT);
	walk(LEFT);
	walk(LEFT);
}
