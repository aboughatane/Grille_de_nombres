#include "projet.h"

void printGrid(champ_t * grid, int w, int h)
{
	printf("\n\t\t\t    ");
	for (int i = 0; i < w; ++i)
	{
		printf("%c ", i+97);
	}

	printf("\n\t\t\t");
	for (int i = 0; i < w + 2 + 2 * w; i++)
		printf("-");
	printf("\n");

	for (int line = 0; line < h; ++line)
	{
		printf("\t\t\t%d", line+1);
		printf(" |");

		for (int col = 0; col < w; ++col)
		{
			if (grid[line * w + col].a == 10)
				printf("  ");
			else if (grid[line * w + col].a == 11)
				printf(" *");

			else
				printf(" %d", grid[line * w + col].a);
		}
		printf(" |\n");
	}

	printf("\t\t\t");
	for (int i = 0; i < w + 2 + 2 * w; i++)
		printf("-");
	printf("\n");
}

void affichamp(champ_t cell)
{
	printf("%u %u %u %u %u %u %u %u %u %u %u\n", cell.a, cell.b, cell.c, cell.d, cell.e, cell.f, cell.g, cell.h, cell.i, cell.j, cell.k);	
}

void affTab(tab t)
{
	int *ptr = t.t;		

	printf("{");

	for (Uint nb = t.nb; nb; nb--)
		printf(" %.d ", *ptr++);

	printf("}\n");
}