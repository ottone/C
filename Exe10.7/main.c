//
//  main.c
//  Exe10.7
//
//  Created by Francesco Parrucci on 04/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Modificate il programma della Figura 10.16, in modo che mescoli le carte mediante l'uso di un mescolatore ad alta efficienza (come 
//  mostrato nella Figura 10.3).
//  Visualizzate il mazzo risultante nel formato a due colonne mostrato nella Figura 10.4. Fate precedere ogni carta dal suo colore.
//

/* Example using a bit field  Figura 10.16*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct bitCard {
   unsigned face : 4;
   unsigned suit : 2;
   unsigned color : 1;
};

typedef struct bitCard Card;

void fillDeck(Card *);
void deal(Card *);
void shuffle(Card *);

int main()
{
   srand(time(NULL));

   Card deck[52];

   fillDeck(deck);
   shuffle(deck);
   deal(deck);

   return 0;
}

void fillDeck(Card *wDeck)
{
   int i;

   for (i = 0; i <= 51; i++) {
      wDeck[i].face = i % 13;
      wDeck[i].suit = i / 13;
      wDeck[i].color = i / 26;
   }
}

void shuffle(Card *wDeck)
{
   int i, j;
   Card temp;

   for(i = 0; i <= 51; i++){
	j = rand() % 52;
	temp = wDeck[i];
	wDeck[i] = wDeck[j];
	wDeck[j] = temp;
   }

}

/* Function deal prints the cards in two column format */
/* Column 1 contains cards 0-25 subscripted with k1 */
/* Column 2 contains cards 26-51 subscripted with k2 */

void deal(Card *wDeck)
{
   int k1, k2;
   char *face[] = {"Ace", "Deuce", "Three", "Four", "Five",
                   "Six", "Seven", "Eight", "Nine", "Ten",
                   "Jack", "Queen", "King"};
   char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
   char *color[] = {"Nero","Rosso"};

   for (k1 = 0, k2 = k1 + 26; k1 <= 25; k1++, k2++) {
      printf("%-6s %-5s of %10s   ", color[wDeck[k1].color], face[wDeck[k1].face], suit[wDeck[k1].suit]);
      printf("%-6s %-5s of %10s\n",  color[wDeck[k1].color], face[wDeck[k2].face], suit[wDeck[k2].suit]);
   }
}


/* The card shuffling and dealing program using structures Mescolatore ad alta efficienza Figura 10.3*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {
   char *face;
   char *suit;
};

typedef struct card Card;

void fillDeck(Card *, char *[], char *[]);
void shuffle(Card *);
void deal(Card *);

main()
{
   Card deck[52];
   char *face[] = {"Ace", "Deuce", "Three", "Four", "Five",
                   "Six", "Seven", "Eight", "Nine", "Ten",
                   "Jack", "Queen", "King"};
   char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

   srand(time(NULL));

   fillDeck(deck, face, suit);
   shuffle(deck);
   deal(deck);
   return 0;
}

void fillDeck(Card *wDeck, char *wFace[], char *wSuit[])
{
   int i;

   for (i = 0; i <= 51; i++) {
      wDeck[i].face = wFace[i % 13];
      wDeck[i].suit = wSuit[i / 13];
   }
}

void shuffle(Card *wDeck)
{
   int i, j;
   Card temp;

   for (i = 0; i <= 51; i++) {
      j = rand() % 52;
      temp = wDeck[i];
      wDeck[i] = wDeck[j];
      wDeck[j] = temp;
   }
}

void deal(Card *wdeck)
{
   int i;

   for (i = 0; i <= 51; i++)
      printf("%5s of %-8s%c", wdeck[i].face, wdeck[i].suit,
             (i + 1) % 2 ? '\t' : '\n');
}
*/
