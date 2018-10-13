#include "game_functions.h"

/*
**	Bienvenue dans ton premier fichier C
**
**  Ce que tu vois en dessous s'appelle une fonction. Une fonction
**  est un bout de code qui sera execute par le programme.
**
**  Tu vas devoir ecrire les instructions pour Archimede entre les accolades
**	{ et } et bien entendu, tu ne dois pas les supprimer, ou le
**	programme ne pourra meme pas lire ton code, et tu auras ce
**	ce que l'on appelle un "erreur de compilation".
**
**	Comme tu peux le voir, il y a deja une instruction ecrite.
**	Cette instruction
**
**		walk(direction)
**
**	est la premiere que tu auras a utiliser dans cette avanture.
**  Elle indiquera a Archimede d'avancer d'une case dans la direction donnee.
**	Pour ce faire tu devras ecrire la direction entre les parentheses ( et )
**	en majuscule (LEFT, RIGHT, UP, DOWN).
**
**	-----------------------------------------------------------------------
**
**	En ce moment, tu te trouves dans un editeur de texte appele VIM.
**	Afin de modifier ton texte, tu dois appuyer sur la touche i de ton clavier.
**	VIM entrera alors en mode "INSERT" (tu pourras le voir s'afficher en bas a
**	gauche de l'ecran).
**
**	Pour quitter le mode "INSERT" il suffit d'appuyer sur la touche ESC du clavier.
**
**	Pour sauvegarder et quitter le fichier, il va falloir quitter le mode "INSERT" (ESC)
**	(si tu vois s'afficher -- INSERT -- en bas a gauche, alors tu es toujours en
**	mode INSERT).  Une fois que tu as quitte le mode INSERT, tape ":x" (sans les 
**	guillemets mais avec les deux points) et appuye sur Enter.
**
**	-----------------------------------------------------------------------
**
**	Une derniere chose : chacune des instructions ecrite en C DOIT etre suivie
**	par un point virgule (;) pour etre valide.
**
**	Tu devrais peut etre maintenant quitter ce fichier et d'ecrire "playgame" dans
**	le terminal, afin de voir le premier niveau et voir ce que la
**	fonction walk(RIGHT) a dans le ventre. Ensuite, reviens ici en tapant "editcode"
**	afin d'ajouter les instructions necessaires au succes du niveau.
**
**	Bonne chance !
**/

void player_function()
{
	walk(RIGHT);
}
