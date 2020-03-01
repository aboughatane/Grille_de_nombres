#include "projet.h"

void initGrid(champ_t * grid, int w, int h)
{
	for(int line = 0; line < h; line++)
	{
		for(int col = 0; col < w; col++)
		{
			grid[line * w + col].a = 10;
		}
	}
}


void initBits(champ_t * grid, int w, int h)
{
	for (int line = 0; line < h; ++line)
	{
		for (int col = 0; col < w; ++col)
		{
			grid[line * w + col].b = 0;
			grid[line * w + col].c = 0;
			grid[line * w + col].d = 0;
			grid[line * w + col].e = 0;
			grid[line * w + col].f = 0;
			grid[line * w + col].g = 0;
			grid[line * w + col].h = 0;
			grid[line * w + col].i = 0;
			grid[line * w + col].j = 0;
			grid[line * w + col].k = 0;
		}
	}
}

champ_t * inputGrid(int input,champ_t * grid, int w, int h)
{
	champ_t * addHere = NULL, *ptrGrid = grid;

	// Dans le cas où l'utilisateur entre un chiffre
	if(input > 0 && input <= 9)
	{
		if(input == 1)
			addHere = ptrGrid;
		else
			addHere = ptrGrid + w * (input - 1);
	}

	// Dans le cas où l'utilisateur entre une lettre
	else if(input >= 97)
	{
		addHere = ptrGrid + (input - 97);
	}

	else
		printf("Entrée incorrecte !\n");

	return addHere;
}