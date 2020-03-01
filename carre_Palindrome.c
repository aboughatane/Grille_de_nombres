#include "projet.h"

int numberOfDigits(int nb)
{
	int res = 0;

	for (; nb > 0; ++res)
		nb /= 10;

	return res;
} 

int doUpsideDown(int nb)
{
	int upsideDown = 0, chiffreNb;
	for (int i = numberOfDigits(nb) - 1, j = nb; i >= 0; --i)
	{
		chiffreNb = j % 10;
		j = (j-chiffreNb)/10;
		upsideDown = upsideDown + chiffreNb * pow(10, i);
	}
	return upsideDown;
}

int isPalindrome(int nb, int nbUpsideDown)
{
	if(nb == nbUpsideDown)
		return 1;
	else
		return 0;
}

int isPalindromicSquare(int nb)
{
	int nbUpsideDown = doUpsideDown(nb), nbInt; // Le nbInt va nous permettre de garder notre nombre
	float nbTest;

	if(isPalindrome(nb, nbUpsideDown))
	{
		nbInt = (int) sqrt(nb);
		nbTest = sqrt(nb);
		if(nbTest == nbInt)
			return 1;
	}
	return 0;
}

void palindromicSquare(tab * palindromicSquares,champ_t * here, int input,champ_t *grid, int w, int h)
{
	int * ptrPalindromicSquare, firstDigit, * endPalindromicSquares = palindromicSquares->t + palindromicSquares->nb - 1;

	for (int i = 1 * pow(10,w - 1); i < 1 * pow(10,w); ++i)
	{
		doUpsideDown(i);
		if (isPalindromicSquare(i))
		{
			// Ajout dans les palindromes carrés testés
			palindromicSquares->nb += 1;
			palindromicSquares->t = (int *) realloc(palindromicSquares->t, palindromicSquares->nb * sizeof *palindromicSquares->t);
			endPalindromicSquares = palindromicSquares->t + palindromicSquares->nb - 1;
			*endPalindromicSquares = i;
		}
	}

	ptrPalindromicSquare = palindromicSquares->t;

	// On va comparer la case du tableau avec les premiers chiffres des palindromes carrés
	for (Uint nb = palindromicSquares->nb; nb; nb--, *ptrPalindromicSquare++)
	{
		firstDigit = (*ptrPalindromicSquare) / pow(10, (int) log10((*ptrPalindromicSquare)));
		digitAllowed(here, firstDigit);
	}
}

void forPalindromicSquare(tab * palindromicSquares,champ_t * here, int input,champ_t *grid, int w, int h)
{
	champ_t *ptrGrid = (champ_t *) grid;
	int firstDigit, digit, nbr, *ptrPalindromicSquare = palindromicSquares->t;

	if(isAllowed(here,here->a))
	{
		for (Uint nb = palindromicSquares->nb; nb; nb--, *ptrPalindromicSquare++)
		{
			firstDigit = (*ptrPalindromicSquare) / pow(10, (int) log10((*ptrPalindromicSquare)));

			if(firstDigit == here->a)
			{
				ptrGrid +=  w * (h-1) + (input - 'a');
				nbr = (*ptrPalindromicSquare) - firstDigit * pow(10,w - 1);

				while (nbr > 0)
				{
					digit = nbr % 10;
					nbr = (nbr-digit)/10;
					digitAllowed(ptrGrid, digit);
					ptrGrid -= w;
				}
			}
		}
	}
}

void searchPalindromicSquare
(
	void (*fct1)(int *, champ_t *, champ_t *,int, champ_t *,int, int), int * lastFct1, champ_t * hereFct1, int inputFct1,
	void (*fct2)(int *, champ_t *, champ_t *,int, champ_t *,int, int), int * lastFct2, champ_t * hereFct2, int inputFct2,
	void (*fct3)(int *, champ_t *, champ_t *,int, champ_t *,int, int), int * lastFct3, champ_t * hereFct3, int inputFct3,
	tab * palindromicSquares, champ_t * here, champ_t * ptrCaseNoire, int input, champ_t * grid,int w, int h) 
	{
		while(!isAllowed(here, here->a))
		{
			(*fct1)(lastFct1, hereFct1, ptrCaseNoire, inputFct1, grid, w, h);
		}
		forPalindromicSquare(palindromicSquares,here, input,grid, w, h);
		here += w;


		while(!isAllowed(here, here->a))
		{
			(*fct2)(lastFct1, hereFct2, ptrCaseNoire, inputFct2, grid, w, h);
		}		
		here += w;

		while(!isAllowed(here, here->a))
		{
			(*fct3)(lastFct3, hereFct3, ptrCaseNoire, inputFct3, grid, w, h);
		}

		here += w;
}