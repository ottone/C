//
//  main.c
//  Exe7.13
//
//  Created by Francesco Parrucci on 07/04/19.
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

UTILIZZARE LE FUNZIONI SVILUPPATE NELL'ESERCIZIO 7.12 PER SCRIVERE UN PROGRAMMA CHE DISTRIBUISCA 
LE CINQUE CARTE DI DUE MANI DI POKER, LE VALUTI E DETERMINI QUAL'E LA MANO MIGLIORE.


	/* Card dealing program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void player(int [][13], int);
void see(const int [][13], const char *[], const char *[]);
int resutls(const int [][13]);
void reset(int [][13]);
void order(int []);

int main()
{

   char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
   char *face[13] = {"Ace", "Deuce", "Three", "Four",
                     "Five", "Six", "Seven", "Eight",
                     "Nine", "Ten", "Jack", "Queen", "King"};
   
   int deck[4][13] = {0};
   int play[4][13] = {0};
   int player_one = 1, player_two = 2;

   srand(time(NULL));

	player(play,player_one);
   	see(play,face,suit);
   	player_one = results(play);

	reset(play);
  
        player(play,player_two);
        see(play,face,suit);
        player_two = results(play);

	if(player_one > player_two)
		printf("Vince player One!!!\n\n\n");
	else if(player_one < player_two)
		printf("Vince player Two!!!!\n\n\n");
	else
		printf("Incredibile Pari!!!\n\n\n");

   return 0;
}



void  player(int play[][13], int who)
{
   int card, row, column;

   printf("\nDistribuisco 5 Carte al %d* Giocatore\n\n\n");

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

int results(const int player[][13]){
	
	int card , row, column, hand_poker[13] = {0}, seed[4] = {0};
	int couple = 0, tris = 0, poker = 0, color = 0, scale[5] = {0}, scala = 1;
	int result = 0;
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


	if(color == 1 && scala == 1){
		printf("\nHai una Scala a Colore\n");
		result = 9;
	}else if(scala == 1 && color == 0){
		printf("Hai una scala !!!\n");
		result = 8;
	}else if(scala == 0 && color == 1){
		printf("Hai Colore !!!\n");
		result = 7;
	}else if(poker == 1){
		printf("Hai un poker !!!\n");
		result = 6;
	}else if(tris == 1 && couple == 1){
		printf("Hai un Full !!!\n");
		result = 5;
	}else if(tris == 1){
		printf("Hai un Tris !!!\n");
		result = 4;
	}else if(couple == 2){
		printf("Hai una Doppia Coppia !!!\n");
		result = 3;
	}else if(couple == 1){
		printf("Hai una Coppia !!!\n");
		result = 2;
	}else{
		printf("Nulla ,riprova la prossima\n");
		result = 1;
	}

	printf("\n\n\n");

	return result;
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

void reset(int play[4][13]){

	int x, y;

	for(x = 0; x <= 3; x++)
		for(y = 0; y <= 12; y++)
			play[x][y] = 0;
}
