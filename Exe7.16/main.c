//
//  main.c
//  Exe7.16
//
//  Created by Francesco Parrucci on 13/04/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
NEL PROGRAMMA PER IL MESCOLAMENTO E LA DISTRIBUZIONE DELLE CARTE DELLA FIGURA 7.24, ABBIAMO INTENZIONALMENTE
UTILIZZATO UN ALGORITMO DI MESCOLAMENTO INEFFICIENTE CHE HA INTRODOTTO LA POSSIBILITÀ DI DIFFERIMENTI 
INDEFINITI. IN QUESTO ESERCIZIO CREERETE UN ALGORITMO DI MESCOLAMENTO AD ALTA EFFICIENZA CHE EVITERÀ IL 
DIFFERIMENTO INDEFINITO.

MODIFICATE IL PROGRAMMA DELLA FIGURA 7.24 NEL MODO SEGUENTE. INIZIALIZZATE LA MATRICE DECK COME MOSTRATO 
NELLA FIGURA 7.29. MODIFICATE LA FUNZIONE SHUFFLE IN MODO CHE ITERI SU OGNI RIGA E COLONNA DELLA MATRICE,
TOCCANDO OGNUNO DEGLI ELEMENTI UNA VOLTA SOLA. OGNI ELEMENTO DOVRÀ ESSERE SCAMBIATO CON UN ALTRO SELEZIO
NATO A CASO DALLA MATRICE. VISUALIZZATE LA MATRICE RISULTANTE COSÌ CHE POSSIATE DETERMINARE SE IL MAZZO 
DI CARTE SIA STATO MESCOLATO IN MODO SODDISFACENTE (COME NELLA FIGURA 7.30, PER ESEMPIO). PER ASSICURARVI 
UN MESCOLAMENTO SODDISFACENTE POTRESTE ANCHE FARE IN MODO CHE IL PROGRAMMA RICHIAMI PIÙ VOLTE LA FUNZIONE 
SHUFFLE.

-------------------------------------- MATRICE DECK NON MESCOLATA-----------------------------------------
	0	1	2	3	4	5	6	7	8	9	10	11	12

0	1	2	3	4	5	6	7	8	9	10	11	12	13	      

1	14	15	16	17	18	19	20	21	22	23	24	25	26

2	27	28	29	30	31	32	33	34	35	36	37	38	39

3	40	41	42	43	44	45	46	47	48	49	50	51	52
----------------------------------------------------------------------------------------------------------

SEBBENE L'APPROCCIO UTILIZZATO IN QUESTO PROBLEMA MIGLIORI L'ALGORITM0 DI MESCOLAMENTO, QUELLO DI DISTRIBU
ZIONE RICHIEDERÀ ANCORA DELLE RICERCHE NELLA MATRICE DECK PER LA CARTA 1, POI PER LA 1, POI PER LA 3 E COSI
VIA. COME SE NON BASTASSE, L'ALGORITMO DI DISTRIBUZIONE CONTINUERÀ A CERCARE UNA CARTA NEL MAZZO ANCHE DOPO
AVERLA GIÀ RITROVATA E DISTRIBUITA. MODIFICATE IL PROGRAMMA DELLA FIGURA 7.24 IN MODO CHE UNA VOLTA CHE AB
VIA DISTRIBUITO UNA CARTA, NON FACCIA ULTERIORI TENTATIVI PER RITROVARLA E CHE PROCEDA IMMEDIATAMENTE CON LA
DISTRIBUZIONE DI QUELLA SUCCESSIVA.
*/



	/* Card dealing program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int [][13]);
void deal(const int [][13], const char *[], const char *[]);
void init(int [][13]);

int main()
{
   srand(time(NULL));

   char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
   char *face[13] = {"Ace", "Deuce", "Three", "Four","Five", "Six", "Seven", "Eight","Nine", "Ten", "Jack", "Queen", "King"};
   int card , row, column,  deck[4][13] = {0};

   // INIZIALIZZAZIONE DELLA MATRICE DECK

   init(deck);

   shuffle(deck);

   for(row = 0; row <= 3; row++){
      for(column = 0; column <= 12; column++)
         printf("%4d",deck[row][column]);
      printf("\n");
   }

   
   deal( deck, face, suit);
   return 0;
}


void shuffle(int wDeck[][13])
{
   int count, row, column, card, rand_row, rand_col;
   
   for(count = 1; count <= 52; count++){
     for(row = 0; row <= 3; row++)
       for (column = 0; column <= 12; column++){
		rand_row = rand() % 4;
		rand_col = rand() % 13;	
	        card = wDeck[row][column]; 
		wDeck[row][column] = wDeck[rand_row][rand_col];
		wDeck[rand_row][rand_col] = card;
       }
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

void init(int deck [][13]){

    int card, row, column;

    for(card = 1, row = 0; row <= 3; row++)
      for(column = 0; column <= 12; column++){
         deck[row][column] = card;
         card % 13 == 0 ? printf("%4d\n",deck[row][column]) : printf("%4d",deck[row][column]);
        card++;
    }
     
    printf("\n\n");


}
