#include "projet.h"

void initBlackCell(champ_t * here, champ_t ** ptrCaseNoire, int noireColonne, int noireLigne, champ_t * grid, int w, int h)
{
	here = inputGrid(noireLigne, grid, w, h) + (noireColonne - 'a');
	here->a = 11;
	(*ptrCaseNoire) = here;
}

void toAvoidBlackCell(champ_t * here, champ_t * ptrCaseNoire, int input,champ_t ** ptrGrid, int * w, int * h)
{
	champ_t * i = here;

	// On parcourt l'emplacement pour vérifier si il y a la case noire
	if(input >= 0 && input <= 9)
		while(i < *ptrGrid && ptrCaseNoire != i)
			i +=1;

	else if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
		while(i < *ptrGrid && ptrCaseNoire != i)
			i += *w;

	if(ptrCaseNoire == i)
	{
		if(input >= 0 && input <= 9)
		{
			if(*ptrGrid == i)
			{
				
				*w -= 1;
				(*ptrGrid) -= 1;
			}

			else if(here < i)
			{
				*w = i - here;
				(*ptrGrid) = i - 1;
			}

			else if(here == i)
				*w -= 1;
		}

		// Dans ce cas là on va prendre une deuxième variable (h) pour ne pas modifier le h garde la vrai hauteur de la grille et dont on va se resservir après
		else if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
		{
			if(*ptrGrid == i)
			{
				*h -= 1;
				(*ptrGrid) -= *w;
			}

			else if(here < i)
			{
				(*ptrGrid) = i - *w;
				*h = ((*ptrGrid) - here)/ (*w) + 1;
			}

			else if(here == i)
				*h -= 1;
		}
	}
}