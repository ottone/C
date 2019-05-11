//
//  main.c
//  Exe7.20
//
//  Created by Francesco Parrucci on 08/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
7.20

MODIFICATE IL PROGRAMMA DI MESCOLAMENTO E DISTRUVUZIONE DELLE CARTE PROPOSTO IN FIGURA 7.24, IN MODO CHE LE SUDDETTE OPERAZIONI SIANO
ESEGUITE DA UNA FUNZIONE UNICA (shuffleAndDeal). QUESTA DOVRÀ CONTENERE UNA STRUTTURA DI ITERAZIONE NIDIFICATA SIMILE A QUELLA DELLA 
FUNZIONE shuffle MOSTRATA NELLA FIGURA 7.24

*/

/* Card dealing program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int [][13],const char *[],const char *[]);

main()
{
   char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
   char *face[13] = {"Ace", "Deuce", "Three", "Four",
                     "Five", "Six", "Seven", "Eight",
                     "Nine", "Ten", "Jack", "Queen", "King"};
   int deck[4][13] = {0};

   srand(time(NULL));

   shuffle(deck, face, suit);

   return 0;
}

void shuffle(int wDeck[][13],const char *wFace[], const char *wSuit[])
{
   int card = 1 , row, column, temp, x, y;
   
  
  for( x = 0; x <= 3; x++)
     for(y = 0; y <= 12; y++)
         wDeck[x][y] = card++;
  

  for(x = 0; x <= 3; x++)
     for(y = 0; y <= 12; y++,card++){
       	 row = rand() % 4;
       	 column = rand() % 13;
       	 temp = wDeck[x][y];
       	 wDeck[x][y] = wDeck[row][column];
	 wDeck[row][column] = temp;
 	 printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
}

}
