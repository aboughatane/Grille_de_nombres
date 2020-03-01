#include "projet.h"

void consecutiveDigit(int * lastConsecutiveDigit,champ_t * here, champ_t * ptrCaseNoire,int input,champ_t *grid, int w, int h)
{
	int digit, endDigit, h2 = h;
	champ_t *ptrGrid = (champ_t *) grid;

	//Pointeur sur la derniere case
	champ_t * endHere = (champ_t *) here;

	// Si input est horizontal càd un chiffre
	if(input >= 0 && input <= 9) 
		ptrGrid = here + (w-1);

	// Si input est vertical càd une lettre
	else if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
	{
		ptrGrid += w * (h-1) + (input - 'a');
	}

	// On s'occupe de la case noire :
	if(ptrCaseNoire)
		toAvoidBlackCell(here, ptrCaseNoire, input, &ptrGrid, &w, &h2);


	// Si on a testé aucun nombre
	if (!*lastConsecutiveDigit)
	{
		// On prend le premier élément si il y a déjà un chiffre sinon 1
		if(here->a != 10 && here->a != 11)
		{
			digit = here->a;
			endDigit = digit + (w - 1);
		}
		
		else
		{
			digit = 1;
			endDigit = digit + (w - 1);
		}
	}

	// Sinon on cherche à partir du dernier nombre premier testé
	else
	{
		digit = *lastConsecutiveDigit + 1;

		// On prend le premier élément si il y a déjà un chiffre sinon 1
		if(here->a != 10 && here->a != 11)
			endDigit = digit + (w - 1);

		else
			endDigit = digit + (w - 1);
	}

	// Ajout du nombre comme dernier testé
	*lastConsecutiveDigit = digit;

	//pour remplir horizontalement
	if(input >= 0 && input <= 9)
	{
		endHere = here + (w-1);
		for (int i = 0; i < w; ++i)
		{
			endHere->a = endDigit--;
			endHere--;
		}
	}

	//pour remplir verticalement
	else if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
	{
		endHere = here + (2 * h);
		for (int i = 0; i < h2; ++i)
		{
			endHere->a = endDigit--;
			endHere -= w;
		}
	}
}