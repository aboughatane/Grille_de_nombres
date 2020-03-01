CC=gcc
CFLAGS=-Wall
SRC=main.c affichage.c chiffres_Interdits.c initialisations.c nombres_Premiers.c chiffres_Consecutifs.c carre_Palindrome.c carre.c produit.c case_Noire.c
OBJ=$(SRC:.c=.o)

projet : $(OBJ) projet.h
	$(CC) -o $@ $(OBJ) -lm

%.o : %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm *.o *~core