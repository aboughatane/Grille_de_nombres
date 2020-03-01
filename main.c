#include "projet.h"


int main(int argc, char const *argv[])
{
	int gridSize = 'z';
	champ_t grid[gridSize][gridSize], *ptrGrid = (champ_t *)grid;
	
		/* La case noire */
	int caseNoire = 1, noireColonne = 0, noireLigne = 'a';
	champ_t *ptrCaseNoire = NULL;
	char inputCaseNoire = ' ';

		/* Les entrées */
	int inputNombrePremier = 0, inputConsecutiveDigit = 0, inputPalindromicSquare = 0, inputSquare = 0, inputProduit = 0, input = 0;

		/* Les pointeurs correspondants aux entrées */
	champ_t *addHereSquare = NULL, *addHere = NULL, *addHereConsecutiveDigit = NULL, *addHerePrimeNumber = NULL, *addHereProduit = NULL, *addHerePalindromicSquare = NULL;

		/* Pour gérer nos possibilités */
	int lastFct1, lastFct2, lastFct3;
	int lastConsecutiveDigits = 0, lastSquares = 0, lastPrimes = 0;
	tab palindromicSquares = {0,(int *) malloc(palindromicSquares.nb * sizeof * palindromicSquares.t)};

		/* Pour utiliser nos fonctions dans carre palindrome*/
	int inputFct1, inputFct2, inputFct3;
	champ_t * hereFct1, * hereFct2, *hereFct3;
	void (*fct1)(int *, champ_t *, champ_t *,int, champ_t *,int, int), (*fct2)(int *, champ_t *, champ_t *,int, champ_t *,int, int), (*fct3)(int *, champ_t *, champ_t *,int, champ_t *,int, int);

		/* Initialisation de la grille */ 
	initBits(ptrGrid, gridSize, gridSize);
	initGrid(ptrGrid, gridSize, gridSize);

		/* Menu de l'utilisateur */
	int continueGrid = 1;

	printf("\n\t\t\tBienvenue sur grille de nombre !!\n\n");
	while(continueGrid)
	{
			/* Taille de la grille */
		while(!(gridSize >= 3 && gridSize <= 9))
		{
			printf("\t\tEntrez la taille souhaitée pour votre grille (pour l'instant, nous ne pouvons travailler que sur une grille de taille 3*3) : \n");
			scanf("%d",&input);
			gridSize = input;
		}

		if (gridSize != 3)
		{
			printGrid(ptrGrid, gridSize, gridSize);
			return 0;
		}

		printGrid(ptrGrid, gridSize, gridSize);

			/* On récupère la définition de a*/
		input = 0;
		while(inputPalindromicSquare != 'a')
		{
			printf("\n\t\tPlacez les définitions : \n");
			printf("\t\tPour a :\n");
			printf("\t\t1. Carré et palindrome\n");
			input = getchar();
			scanf("%d",&input);

			switch(input)
			{
				case 1:
					inputPalindromicSquare = 'a';
					addHerePalindromicSquare = inputGrid(inputPalindromicSquare, ptrGrid, gridSize, gridSize);
					palindromicSquare(&palindromicSquares, addHerePalindromicSquare,inputPalindromicSquare,ptrGrid,gridSize,gridSize);
					break;
			}
		}

		input = getchar();
		while(inputProduit != 'b')
		{
			printf("\n\t\tPlacez les définitions : \n");
			printf("\t\tPour b :\n");
			printf("\t\t1. Le produit des chiffre est 12\n");
			
			scanf("%d",&input);

			switch(input)
			{
				case 1:
					inputProduit = 'b';
					addHereProduit = inputGrid(inputProduit, ptrGrid, gridSize, gridSize);
					produit(addHereProduit, inputProduit, ptrGrid, gridSize, gridSize);
					break;
			}
		}

		input = getchar();
		while(inputCaseNoire != 'o' && inputCaseNoire != 'n' && inputCaseNoire != 'O' && inputCaseNoire != 'N')
		{
			printf("\n\t\tVoulez vous une case noire ? O ou N\n");
			
			scanf("%c",&inputCaseNoire);

			if (inputCaseNoire == 'o' || inputCaseNoire == 'O')
			{
				caseNoire = 1;
			}

			else if(inputCaseNoire == 'n' || inputCaseNoire == 'N')
			{
				caseNoire = 0;
			}

			else
			{
				printf("\t\tErreur ! \n");
				return 0;
			}
		}

		// On gère la case noire
		if(caseNoire)
		{
			input = getchar();
			while(noireColonne - 'a' < 0 || noireColonne - 'a' >= gridSize || noireColonne == 'a' || noireColonne == 'b')
			{
				printf("\n\t\tEntrez une lettre pour placer votre case noire (repérez-vous aux lettres aux dessus si besoin) : \n");
				printf("\t\tP.-S. Vous ne pouvez pas mettre de case noire sur les 2 colonnes précédentes !\n");
				scanf("%c",&inputCaseNoire);
				noireColonne = inputCaseNoire;
			}

			while(!(noireLigne >= 0 && noireLigne <= 9) || noireLigne > gridSize)
			{
				printf("\n\t\tEntrez un chiffre pour placer votre case noire (repérez-vous aux chiffres à gauche si besoin) : \n");
				scanf("%d", &input);
				noireLigne = input;	
			}

			initBlackCell(addHere, &ptrCaseNoire, noireColonne, noireLigne, ptrGrid, gridSize, gridSize);
		}
		
		input = getchar();
		// On récupère la définition de 1
		while(!(input >= 1 && input <= 3))
		{
			printf("\n\t\tPlacez les définitions : \n");
			printf("\t\tPour 1 :\n");
			printf("\t\t1. Suite de chiffre consécutifs\n");
			printf("\t\t2. Nombre premier\n");
			printf("\t\t3. Carré\n");

			scanf("%d", &input);

			switch(input)
			{
				case 1:
					inputConsecutiveDigit = 1;
					addHereConsecutiveDigit = inputGrid(inputConsecutiveDigit, ptrGrid, gridSize, gridSize);
					fct1 = consecutiveDigit;
					lastFct1 = lastConsecutiveDigits;
					hereFct1 = addHereConsecutiveDigit;
					inputFct1 = inputConsecutiveDigit;
					break;	
				case 2:
					inputNombrePremier = 1;
					addHerePrimeNumber = inputGrid(inputNombrePremier, ptrGrid, gridSize, gridSize);
					fct1 = searchPrimeNumber;
					lastFct1 = lastPrimes;
					hereFct1 = addHerePrimeNumber;
					inputFct1 = inputNombrePremier;
					break;
				case 3:
					inputSquare = 1;
					addHereSquare = inputGrid(inputSquare, ptrGrid, gridSize, gridSize);
					searchSquare(&lastSquares, addHereSquare, ptrCaseNoire,inputSquare, ptrGrid, gridSize, gridSize);
					fct1 = searchSquare;
					lastFct1 = lastSquares;
					hereFct1 = addHereSquare;
					inputFct1 = inputSquare;
					break;
			}
		}

		input = getchar();
		// On récupère la définition de 2
		while(!(input >= 1 && input <= 2))
		{
			printf("\n\t\tPlacez les définitions : \n");
			printf("\t\tPour 2 :\n");

			if(inputConsecutiveDigit)
			{
				printf("\t\t1. Nombre premier\n");
				printf("\t\t2. Carré\n");

				scanf("%d", &input);

				switch(input)
				{
					case 1:
						inputNombrePremier = 2;
						addHerePrimeNumber = inputGrid(inputNombrePremier, ptrGrid, gridSize, gridSize);
						fct2 = searchPrimeNumber;
						lastFct2 = lastPrimes;
						hereFct2 = addHerePrimeNumber;
						inputFct2 = inputNombrePremier;
						break;
					case 2:
						inputSquare = 2;
						addHereSquare = inputGrid(inputSquare, ptrGrid, gridSize, gridSize);
						searchSquare(&lastSquares, addHereSquare, ptrCaseNoire,inputSquare, ptrGrid, gridSize, gridSize);
						fct2 = searchSquare;
						lastFct2 = lastSquares;
						hereFct2 = addHereSquare;
						inputFct2 = inputSquare;
						break;
				}
			}

			else if(inputNombrePremier)
			{
				printf("\t\t1. Suite de chiffre consécutifs\n");
				printf("\t\t2. Carré\n");


				scanf("%d", &input);

				switch(input)
				{
					case 1:
						inputConsecutiveDigit = 2;
						addHereConsecutiveDigit = inputGrid(inputConsecutiveDigit, ptrGrid, gridSize, gridSize);
						fct2 = consecutiveDigit;
						lastFct2 = lastConsecutiveDigits;
						hereFct2 = addHereConsecutiveDigit;
						inputFct2 = inputConsecutiveDigit;
						break;
					case 2:
						inputSquare = 2;
						addHereSquare = inputGrid(inputSquare, ptrGrid, gridSize, gridSize);
						searchSquare(&lastSquares, addHereSquare, ptrCaseNoire,inputSquare, ptrGrid, gridSize, gridSize);
						fct2 = searchSquare;
						lastFct2 = lastSquares;
						hereFct2 = addHereSquare;
						inputFct2 = inputSquare;
						break;
				}
			}

			else if(inputSquare)
			{
				printf("\t\t1. Suite de chiffre consécutifs\n");
				printf("\t\t2. Nombre premier\n");


				scanf("%d", &input);

				switch(input)
				{
					case 1:
						inputConsecutiveDigit = 2;
						addHereConsecutiveDigit = inputGrid(inputConsecutiveDigit, ptrGrid, gridSize, gridSize);
						fct2 = consecutiveDigit;
						lastFct2 = lastConsecutiveDigits;
						hereFct2 = addHereConsecutiveDigit;
						inputFct2 = inputConsecutiveDigit;
						break;
					case 2:
						inputNombrePremier = 2;
						addHerePrimeNumber = inputGrid(inputNombrePremier, ptrGrid, gridSize, gridSize);
						fct2 = searchPrimeNumber;
						lastFct2 = lastPrimes;
						hereFct2 = addHerePrimeNumber;
						inputFct2 = inputNombrePremier;
						break;
				}
			}

			else
			{
				printf("\t\tErreur !\n");
				return 0;
			}
		}

		input = getchar();
		// On récupère la définition de 3
		while(input != 1)
		{
			printf("\n\t\tPlacez les définitions : \n");
			printf("\t\tPour 3 :\n");

			if(!inputSquare)
			{
				printf("\t\t1. Carré\n");


				scanf("%d", &input);

				switch(input)
				{
					case 1:
						inputSquare = 3;
						addHereSquare = inputGrid(inputSquare, ptrGrid, gridSize, gridSize);
						searchSquare(&lastSquares, addHereSquare, ptrCaseNoire,inputSquare, ptrGrid, gridSize, gridSize);
						fct3 = searchSquare;
						lastFct3 = lastSquares;
						hereFct3 = addHereSquare;
						inputFct3 = inputSquare;
						break;
				}
			}

			else if(!inputNombrePremier)
			{
				printf("\t\t1. Nombre premier\n");


				scanf("%d", &input);

				switch(input)
				{	
					case 1:
						inputNombrePremier = 3;
						addHerePrimeNumber = inputGrid(inputNombrePremier, ptrGrid, gridSize, gridSize);
						fct3 = searchPrimeNumber;
						lastFct3 = lastPrimes;
						hereFct3 = addHerePrimeNumber;
						inputFct3 = inputNombrePremier;
						break;
				}
			}

			else if(!inputConsecutiveDigit)
			{
				printf("\t\t1. Suite de chiffre consécutifs\n");

				scanf("%d", &input);

				switch(input)
				{
					case 1:
						inputConsecutiveDigit = 3;
						addHereConsecutiveDigit = inputGrid(inputConsecutiveDigit, ptrGrid, gridSize, gridSize);
						fct3 = consecutiveDigit;
						lastFct3 = lastConsecutiveDigits;
						hereFct3 = addHereConsecutiveDigit;
						inputFct3 = inputConsecutiveDigit;
						break;
				}
			}

			else
			{
				printf("\t\tErreur !\n");
				return 0;
			}
		}

		continueGrid = 0;
	}

	searchPalindromicSquare(fct1, &lastFct1, hereFct1, inputFct1,fct2, &lastFct2, hereFct2, inputFct2, fct3, &lastFct3, hereFct3, inputFct3, &palindromicSquares,addHerePalindromicSquare, ptrCaseNoire, inputPalindromicSquare,ptrGrid, gridSize, gridSize);

	produit(addHereProduit, inputProduit, ptrGrid, gridSize, gridSize);
	
	printGrid(ptrGrid, gridSize, gridSize);


	return 0;
}