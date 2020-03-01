#include "projet.h"

int isSquare(int nb)
{
	int nbInt = (int) sqrt(nb);
	float nbTest = sqrt(nb);

	if(nbTest == nbInt)
		return 1;

	return 0;
}

void searchSquare(int * lastSquare, champ_t * here, champ_t * ptrCaseNoire,int input,champ_t * grid, int w, int h)
{
	champ_t *ptrGrid = (champ_t *) grid, *ptr = here;
	int nb = 0, digit, h2 = h;

	// ON PLACE LE POINTEUR A LA FIN
	// Si input est horizontal càd un chiffre
	if(input >= 0 && input <= 9) 
	{
		ptrGrid = here + (w-1);
	}

	// Si input est vertical càd une lettre
	else if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
	{
		ptrGrid += w * (h-1) + (input - 'a');
	}

	// On s'occupe de la case noire :
	if(ptrCaseNoire)
		toAvoidBlackCell(here, ptrCaseNoire, input, &ptrGrid, &w, &h2);

	// Si on a testé aucun nombre, donc que primes est vide
	if (!*lastSquare)
	{
		if(input >= 0 && input <= 9) 
		{
			// On prend le nombre sur la colonne
			for (int exposant = w-1; exposant >= 0; --exposant)
			{
				if(ptr->a != 10 && ptr->a != 11)
				{
					nb += ptr++->a * pow(10, exposant);
				}
				
				else
					nb += 1 * pow(10, exposant);
			}
		}

		else if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
		{
			// On prend le nombre sur la ligne
			for (int exposant = h2-1; exposant >= 0; --exposant)
			{
				if(ptr->a != 10 && ptr->a != 11)
					nb += ptr++->a * pow(10, exposant);
				else
					nb += 1 * pow(10, exposant);
			}
		}
	}

	// Sinon on cherche à partir du dernier nombre premier testé
	else
		nb = *lastSquare + 1;

	// On cherche un carré
	while(nb < 1 * pow(10,w) && !isSquare(nb))
		nb++;

	// Ajout dans le tableau des carrés testés
	*lastSquare = nb;

	// Ajout dans la grille
	while(nb > 0)
	{
		digit = nb % 10;
		nb = (nb-digit)/10;

		// Dans un cas de remplissage horizontal
		if(input >= 0 && input <= 9)
		{
			ptrGrid--->a = digit;

		}
		// Dans un cas de remplissage vertical
		else if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
		{
			ptrGrid->a = digit;
			ptrGrid -= w;
		}
	}
}