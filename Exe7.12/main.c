//
//  main.c
//  Exe7.12
//
//  Created by Francesco Parrucci on 01/04/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
MODIFICATE IL PROGRAMMA DELLA FIGURA 7.24 IN MODO CHE LA FUNZIONE DI DISTRIBUZIONE DISPENSI LE CINQUE 
CARTE DI UNA MANO DI POKER. IN SEGUITO SCRIVETE LE SEGUENTI FUNZIONI AGGIUNTIVE:

A) DETERMINARE SE LA MANO CONTENGA UNA COPPIA.
B) DETEMINARE SE LA MANO CONTENGA UNA DOPPIA COPPIA.
C) DETERMINARE SE LA MANO CONTENGA UN TRIS (PER ESEMPIO TRE FANTI).
D) DETERMINARE SE LA MANO CONTENGA UN POKER (PER ESEMPIO, QUATTRO ASSI).
E) DETERMINARE SE LA MANO CONTENGA UN COLORE  (OVVEROSIA, CINQUE CARTE DELLO STESSO SEME).
F) DETERMINARE SE LA MANO CONTENGA UNA SCALA (OVVEROSIA, CINQUE CARTE CON VALORI CONSECUTIVI).

*/


	/* Card dealing program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int [][13]);
void deal(const int [][13], const char *[], const char *[]);
void player(int [][13]);
void see(const int [][13], const char *[], const char *[]);
void resutls(const int [][13]);
void order(int []);

int main()
{
   char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
   char *face[13] = {"Ace", "Deuce", "Three", "Four",
                     "Five", "Six", "Seven", "Eight",
                     "Nine", "Ten", "Jack", "Queen", "King"};
   
   int deck[4][13] = {0};

   int play[4][13] = {0};

   srand(time(NULL));

   shuffle(deck);
   //deal( deck, face, suit);
   
   player(play);
   see(play,face,suit);
   results(play);

   return 0;
}

void shuffle(int wDeck[][13])
{
   int card, row, column;

   for(card = 1; card <= 52; card++) {
      row = rand() % 4;
      column = rand() % 13;

      while(wDeck[row][column] != 0) {
         row = rand() % 4;
         column = rand() % 13;
      }

      wDeck[row][column] = card;
   }
}

void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[])
{
   int card, row, column;

   for (card = 1; card <= 52; card++)

      for (row = 0; row <= 3; row++)

         for (column = 0; column <= 12; column++)

            if (wDeck[row][column] == card)
               printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
}

void player(int play[][13])
{
   int card, row, column;

   printf("\nDistribuisco 5 Carte...\n\n\n");

   for(card = 1; card <= 5; card++) {
      row = rand() % 4;
      column = rand() % 13;

      while(play[row][column] != 0) {
         row = rand() % 4;
         column = rand() % 13;
      }

      play[row][column] = card;

   }
}

void see(const int player[][13], const char *wFace[], const char *wSuit[]){
	
	int card , row, column;

	for(card = 1; card <= 5; card++)

		for(row = 0 ; row <= 3; row++)

			for(column = 0; column <= 12 ; column++)
				if(player[row][column] == card)
					printf("%5s of %-8s\n",wFace[column], wSuit[row]);

	
}

void results(const int player[][13]){
	
	int card , row, column, hand_poker[13] = {0}, seed[4] = {0};
	int couple = 0, tris = 0, poker = 0, color = 0, scale[5] = {0}, scala = 1;

        for(card = 1; card <= 5; card++)

                for( row = 0 ; row <= 3; row++)

                        for(column = 0; column <= 12 ; column++)
                                if(player[row][column] == card){
                                        hand_poker[column] += 1;
					seed[row] += 1;
					scale[card - 1] = column;
				}
				
	for(row = 0; row <= 3 ; row++)
		if(seed[row] == 5)
			color += 1;
					
	for(column = 0; column <= 12 ; column++){
		if(hand_poker[column] == 2)
			couple += 1;

		if(hand_poker[column] == 3)
			tris += 1;
		
		if(hand_poker[column] == 4)
			poker += 1;

        }

	order(scale);

	for(card = 1; card <= 4; card++)
		if(scale[card-1] + 1 != scale[card])
			scala = 0;

	printf("\n\n\n");


	if(color == 1 && scala == 1)
		printf("\nHai una Scala a Colore\n");
	else if(scala == 1 && color == 0)
		printf("Hai una scala !!!\n");
	else if(scala == 0 && color == 1)
		printf("Hai Colore !!!\n");
	else if(poker == 1)
		printf("Hai un poker !!!\n");
	else if(tris == 1 && couple == 1)
		printf("Hai un Full !!!\n");
	else if(tris == 1)
		printf("Hai un Tris !!!\n");
	else if(couple == 2)
		printf("Hai una Doppia Coppia !!!\n");
	else if(couple == 1)
		printf("Hai una Coppia !!!\n");
	else 
		printf("Nulla ,riprova la prossima\n");


	printf("\n\n\n");
}

void order(int scale[]){
	int x,y,temp;

	for(x = 1 ; x <= 4 ; x++)
		for(y = 0; y <= 3; y++)
			if(scale[y] > scale[x]){
				temp = scale[y];
				scale[y] = scale[x];
				scale[x] = temp;
			}

}
