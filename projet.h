#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	/* STRUCTURES */
struct champ
{
	unsigned int a : 4;
	unsigned int b : 1;
	unsigned int c : 1;
	unsigned int d : 1;
	unsigned int e : 1;
	unsigned int f : 1;
	unsigned int g : 1;
	unsigned int h : 1;
	unsigned int i : 1;
	unsigned int j : 1;
	unsigned int k : 1;

};
typedef struct champ champ_t;

typedef unsigned int Uint;
struct tab
{
	Uint nb;
	int * t;
};
typedef struct tab tab;

	/* LA CASE NOIRE */
void initBlackCell(champ_t * here, champ_t ** ptrCaseNoire, int noireColonne, int noireLigne, champ_t * grid, int w, int h);
void toAvoidBlackCell(champ_t * here, champ_t * ptrCaseNoire, int input,champ_t ** ptrGrid, int * w, int * h);

	/*FONCTIONS D'AFFICHAGE*/
void printGrid(champ_t * grid, int w, int h);
void affichamp(champ_t);
void affTab(tab t);


	/* CHAMP DE BITS */
void digitAllowed(champ_t * t, int chffr);
int isAllowed(champ_t * t, int chffr);


	/* FONCTIONS D'INITIALISATIONS */
void initGrid(champ_t * grid, int w, int h);
void initBits(champ_t * grid, int w, int h);
champ_t * inputGrid(int input,champ_t * grid, int w, int h);

	/* NOMBRES PREMIERS */
int findPrimeNumber(int nb);
void searchPrimeNumber(int * lastPrime,champ_t *here, champ_t * ptrCaseNoire, int input, champ_t * grid, int w, int h);


	/* CHIFFRE CONSECUTIF */
void consecutiveDigit(int * consecutiveDigits, champ_t * here, champ_t * ptrCaseNoire,int input, champ_t * grid,int w, int h);

	/* CARRES PALINDROMES */
int numberOfDigits(int nb);
int doUpsideDown(int nb);
int isPalindrome(int nb, int nbUpsideDown);
int isPalindromicSquare(int nb);
void palindromicSquare(tab * palindromicSquares,champ_t * here, int input,champ_t *grid, int w, int h);
void searchPalindromicSquare
(
	void (*fct1)(int *, champ_t *, champ_t *,int, champ_t *,int, int), int * lastFct1, champ_t * hereFct1, int inputFct1,
	void (*fct2)(int *, champ_t *, champ_t *,int, champ_t *,int, int), int * lastFct2, champ_t * hereFct2, int inputFct2,
	void (*fct3)(int *, champ_t *, champ_t *,int, champ_t *,int, int), int * lastFct3, champ_t * hereFct3, int inputFct3,
	tab * palindromicSquares, champ_t * here, champ_t * ptrCaseNoire, int input, champ_t * grid,int w, int h);

	/* FONCTION CARRE */
int isSquare(int nb);
void searchSquare(int * lastSquare, champ_t * here, champ_t * ptrCaseNoire,int input,champ_t * grid, int w, int h);


	/* PRODUIT */
void produit(champ_t *here, int input,champ_t *grid, int w, int h);