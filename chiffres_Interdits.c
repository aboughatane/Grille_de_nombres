#include "projet.h"


void digitAllowed(champ_t * t, int chffr)
{
	switch(chffr)
	{
		case 0:
			t->b = 1;
			break;
		case 1:
			t->c = 1;
			break;
		case 2:
			t->d = 1;
			break;
		case 3:
			t->e = 1;
			break;
		case 4:
			t->f = 1;
			break;
		case 5:
			t->g = 1;
			break;
		case 6:
			t->h = 1;
			break;
		case 7:
			t->i = 1;
			break;
		case 8:
			t->j = 1;
			break;
		case 9:
			t->k = 1;
			break;
	}
}

int isAllowed(champ_t * t, int chffr)
{
	switch(chffr)
	{
		case 0:
			return t->b;
		case 1:
			return t->c;
		case 2:
			return t->d;
		case 3:
			return t->e;
		case 4:
			return t->f;
		case 5:
			return t->g;
		case 6:
			return t->h;
		case 7:
			return t->i;
		case 8:
			return t->j;
		case 9:
			return t->k;
	}
	return 0;
}