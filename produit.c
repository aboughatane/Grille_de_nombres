#include "projet.h"


void produit(champ_t *here, int input,champ_t *grid, int w, int h)
{
	champ_t *ptrGrid = here;
	int ch1 = 1,ch2 = 1,ch3 = 1;

	// Si input est horizontal càd une chiffre
	if(input >= 0 && input <= 9)
	{
		ch1 = ptrGrid++->a;
		ch2 = ptrGrid++->a;
	}

	// Si input est vertical càd une lettre
	else if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
	{
		ch1 = ptrGrid->a;
		ptrGrid += h;
		ch2 = ptrGrid->a;
		ptrGrid += h;	
	}

	// Si l'une des cases est egal à 0 faut chercher d'autre valeurs
	if(ch1 * ch2 == 0)
	{
		printf(" Erreur une des cases est egale à 0\n");
	}
	
	else
	{
		ch3 = 12 / (ch1 * ch2);
		ptrGrid->a = ch3;
	}
}