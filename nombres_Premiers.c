#include "projet.h"

int findPrimeNumber(int nb)
{
	int isPrime = 1, prime = nb + 1;

	for (int i = 2; i < prime && isPrime; ++i)
	{
		// nb n'est pas un nombre premier s'il a un diviseur autre que 1 ou lui même 
		if (prime%i == 0)
			isPrime = 0;

		else
			isPrime = 1;
	}

	if(isPrime)
		return prime;
	return findPrimeNumber(nb+1);
}

void searchPrimeNumber(int * lastPrime,champ_t *here, champ_t * ptrCaseNoire, int input, champ_t * grid, int w, int h)
{
	champ_t *ptrGrid = (champ_t *) grid;
	int nb, digit, prime = 0, h2 = h;

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
	
	// On prend le premier élément si il y a déjà un chiffre
	if(input >= 0 && input <= 9)
	{
		if(here->a != 10 && here->a != 11)
			nb = here->a * pow(10, w-1);
		else
			nb = 1 * pow(10, w-1);
	}

	else if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
	{
		if(here->a != 10 && here->a != 11)
			nb = here->a * pow(10, h2-1);
		else
			nb = 1 * pow(10, h2-1);
	}

	// Si on a testé aucun nombre
	if (!*lastPrime)
	{
		prime = findPrimeNumber(nb);
	}

	// Sinon on cherche à partir du dernier nombre premier testé
	else
		prime = findPrimeNumber(*lastPrime);

	// Ajout du nombre comme dernier testé
	*lastPrime = prime;



	// Ajout du nombre dans la grille
	while(prime > 0)
	{
		digit = prime % 10;
		prime = (prime-digit)/10;

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