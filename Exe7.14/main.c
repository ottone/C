//
//  main.c
//  Exe7.14
//
//  Created by Francesco Parrucci on 08/04/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
MODIFICATE IL PROGRAMMA DELLA FIGURA 7.13 IN MODO DA SIMULARE UN MAZZIERE. LE CINQUE CARTE DELLA MANO
DEL MAZZIERE SARANNO DISTRIBUITE "A FACCIA IN GIU" COSI CHE IL GIOCATORE NON LE POSSA VEDERE. IL PROGRAMMA
DOVRA' QUINDI VALUTARE LA MANO DEL MAZZIERE E, BASANDOSI SULLA QUALITA' DI QUELLA, DOVRA' ESTRARRE ALTRE
CARTE PER SOSTITUIRE QUELLE SCARTATE DALLA MANO ORIGINARIA. IL PROGRAMMA DOVRA' QUINDI RIVALUTARE LA MANO
DEL MAZZIERE (ATTENZIONE QUESTO È UN PROBLEMA DIFFICILE)
*/



	/* Card dealing program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//void shuffle(int [][13]);
//void deal(const int [][13], const char *[], const char *[]);

void player(int [][13]);
void see(int [][13]);
void results(int [][13]);
void order(int []);
void change(int [][13]);


int main()
{
   void (*f[]) (int [][13]) = {player,see,change};

   //char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
   //char *face[13] = {"Ace", "Deuce", "Three", "Four",
   //                  "Five", "Six", "Seven", "Eight",
   //                  "Nine", "Ten", "Jack", "Queen", "King"};
   //int deck[4][13] = {0};

   int play[4][13] = {0}, choice;

   srand(time(NULL));

   //shuffle(deck);
   //deal( deck, face, suit);
   /*
   player(play);
   see(play,face,suit);
   results(play);
   change(play);
   see(play,face,suit);
   results(play);
   */

   do{
	   printf("\n0 per le carte:");
	   printf("\n1 per vedere:");
	   printf("\n2 per cambiare (max 4 carte):");
	   printf("\n3 per terminare.");
	   scanf("%d",&choice);
	  
	   if(choice >= 0 && choice <= 2)
	   	(*f[choice])(play);

   }while(choice != 3);


   return 0;
}

/*
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

*/

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

void see(int player[][13]){
	
	const char  *wSuit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	const char *wFace[13] = {"Ace", "Deuce", "Three", "Four",
                                 "Five", "Six", "Seven", "Eight",
                                 "Nine", "Ten", "Jack", "Queen", "King"};


	int card , row, column;
	
	printf("\n\n");

	for(card = 1; card <= 5; card++)

		for(row = 0 ; row <= 3; row++)

			for(column = 0; column <= 12 ; column++)
				if(player[row][column] == card)
					printf("%5s of %-8s\n",wFace[column], wSuit[row]);

	results(player);
}

void results(int player[][13]){
	
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

void change (int mazzo[4][13]){
	
	int n, card, row, column;
	
	do{
		printf("\nQuante carte vuoi sostituire? ");
		scanf("%d",&n);
	}while(n < 1 || n > 4);


	while(n > 0){

		printf("\n\nDigita il numero della carta da sostituire: ");
		scanf("%d",&card);
		n--;
		for(row = 0; row <= 3 ; row++)
			for(column = 0; column <= 12; column++)
				if(mazzo[row][column] == card){
					mazzo[row][column] = 0;
					row = rand() % 4;
					column = rand() % 13;
					mazzo[row][column] = card;
				}

	}

}
