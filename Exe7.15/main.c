//
//  main.c
//  Exe7.15
//
//  Created by Francesco Parrucci on 09/04/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
MODIFICATE IL PROGRAMMA SVILUPPATO NELL'ESERCIZIO 7.14 COSÌ CHE POSSA GESTIRE AUTOMATICAMENTE LA MANO DEL 
MAZZIERE, MENTRE CONSENTA AL GIOCATORE DI DECIDERE QUALI CARTE DELLA SUA MANO SOSTITUIRE. IL PROGRAMMA DOVRA'
QUINDI VALUTARE ENTRAMBE LE MANI E DETERMINARE CHI AVRA' VINTO. UTLIZZATE ORA QUESTO NUOVO PROGRAMMA PER GIOCARE
20 PARTITE CONTRO IL COMPUTER. CHI NE VINCE DI PIÙ? BASANDOVI SUI RISULTATI DI QUESTE PARTITE, APPORTATE LE 
OPPORTUNE MODIFICHE PER RAFFINARE IL VOSTRO PROGRAMMA DI GIOCO (ANCHE QUESTO È UN PROBLEMA DIFFICILE). GIOCATE 
ALTRE 20 PARTITE. GIOCA MEGLIO IL VOSTRO NUOVO PROGRAMMA?  
*/



	/* Card dealing program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player(int [][13]);
int see(int [][13]);
int results(int [][13]);
int change(int [][13]);
int grades(int row, int column);

void ordina_mazzo(int [][13]);
void order(int []);
void reset(int [][13]);
void think(int [][13]);
void carte_uguali(int [][13]);

int main()
{
   int (*f[]) (int [][13]) = {player,see,change,results}, play[4][13] = {0}, player_one, player_two;
   char choice;
   srand(time(NULL));
   // ----------------- UTENTE ----------------------
   (*f[0])(play);					// 1) DO LE CARTE ALL'UTENTE
   ordina_mazzo(play);					// 2) ORDINA IL MAZZO
   (*f[1])(play);					// 3) VEDO COSA HO
   player_one = (*f[3])(play);				// 4) VALUTO E ASSEGNO IL VALORE A PLAYER_ONE
   do{													
     printf("y cambia (max 4 carte) altimenti n: ");	// 5) CHIEDO SE L'UTENTE INTENDE A CAMBIARE CARTE
     choice = getchar();
   }while(choice != 'y' && choice != 'n');		
   if(choice == 'y'){					// 6) SE L'UTENTE VUOLE CAMBIARE CARTE CHIEDO QUALI
     (*f[2])(play);
     (*f[1])(play);					// 7) VEDO COSA HO
     ordina_mazzo(play);				// 8) ORDINA IL MAZZO
     player_one = (*f[3])(play);			// 9) VALUTO E ASSEGNO IL NUOVO VALORE A PLAYER_ONE
   }
   // ----------------- MACCHINA --------------------
   (*f[0])(play);			// 1) DO LE CARTE
   ordina_mazzo(play);                  // 2) ORDINA IL MAZZO
   (*f[1])(play);	 		// 3) VEDO COSA HO
   think(play);		  		// 4) PENSO A QUALI CARTE CAMBIARE IN BASE A QUELLO CHE HO
   ordina_mazzo(play); 			// 5) ORDINO IL MAZZO
   player_two = (*f[3])(play);		// 6) VALUTO E ASSEGNO IL VALORE A PLAYER_TWO
   (*f[1])(play);			// 7) VEDO IL RISULTATO
   // --------------- COMPUTER --------------------
        if(player_one > player_two)
                printf("\nVince player One!!!\n\n");
        else if(player_one < player_two)
                printf("\nVince player Two!!!!\n\n");
        else
                printf("\nIncredibile Pari!!!\n\n");
   // ---------------------------------------------
   return 0;
}


int player(int play[][13])
{
   int card, row, column;
   reset(play);
   for(card = 1; card <= 5; card++) {
      row = rand() % 4;
      column = rand() % 13;

      while(play[row][column] != 0) {
         row = rand() % 4;
         column = rand() % 13;
      }
      play[row][column] = card;
   }
   return 0;
}

int see(int player[][13]){
	
	const char  *wSuit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	const char *wFace[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	int card , row, column;
	
	printf("\n");

	for(card = 1; card <= 5; card++)

		for(row = 0 ; row <= 3; row++)

			for(column = 0; column <= 12 ; column++)
				if(player[row][column] == card)
					printf("%5s of %-8s punteggio carta :%d\n",wFace[column], wSuit[row],grades(row,column));

	return 0;
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

int  change (int mazzo[4][13]){
	
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
		  mazzo[row][column] = card;}
	}
	return 0;
}

void reset(int play[4][13]){
	
	int row, column;

	for(row = 0; row <= 3; row++)
		for(column = 0; column <= 12; column++)
			play[row][column] = 0;

}


int results(int player[][13]){

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


        if(color == 1 && scala == 1){
                printf("\nHai una Scala a Colore\n");
                result = 9;
        }else if(scala == 1 && color == 0){
                printf("\nHai una scala !!!\n");
                result = 8;
        }else if(scala == 0 && color == 1){
                printf("\nHai Colore !!!\n");
                result = 7;
        }else if(poker == 1){
                printf("\nHai un poker !!!\n");
                result = 6;
        }else if(tris == 1 && couple == 1){
                printf("\nHai un Full !!!\n");
                result = 5;
        }else if(tris == 1){
                printf("\nHai un Tris !!!\n");
                result = 4;
        }else if(couple == 2){
                printf("\nHai una Doppia Coppia !!!\n");
                result = 3;
        }else if(couple == 1){
                printf("\nHai una Coppia !!!\n");
                result = 2;
        }else{
                printf("\nNulla ,riprova la prossima\n");
                result = 1;
        }

        return result;
}


void think(int play[][13]){
	
	int n, card, row, column , score, v[4] = {0}, val;

	score = results(play);
	
	switch(score){
		case 9: // scala a colore
		break;
		
		case 8: // scala
		break;

		case 7: // colore
		break;

		case 6: // poker
		break;

		case 5: // full
		break;

		case 4: // Tris  1)  Individua le due carte da cambiare  2) Cambiale:
		carte_uguali(play);	
		break;

		case 3: // Coppia Coppia 1) Individua la carta  2) Cambiale:
	        carte_uguali(play);
		break;

		case 2: // Coppia 1) Individua le due carte 2) Cambiale:
		carte_uguali(play);
		break;

		case 1: // Nulla, Ne cambio 4 sperando che entri qulcosa... 1) Individua la carta piu alta 2) Cambiale:
		carte_uguali(play);
		break;	
	}

	ordina_mazzo(play);
	see(play);
}


int grades(int row, int column){

	 char  *wSuit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
         char *wFace[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	 char *vett = NULL;
 	 int result = 0;
/*
	vett = wSuit[row];

	if(vett == "Heart")
		result += 4;
	else if (vett == "Diamonds")
		result += 3;
	else if (vett == "Clubs")
		result += 2;
	else // Spades
		result += 1;
*/	
	vett = wFace[column];
		
	if (vett == "Ace")
		result += 13;
	else if (vett == "King")
		result += 12;
	else if (vett == "Queen")
		result += 11;
	else if (vett == "Jack")
		result += 10;
	else if (vett == "Ten")
		result += 9;
	else if (vett == "Nine")
		result += 8;
	else if (vett == "Eight")
		result += 7;
	else if (vett == "Seven")
		result += 6;
	else if (vett == "Six")
		result += 5;
	else if (vett == "Five")
		result += 4;
	else if (vett == "Four")
		result += 3;
	else if (vett == "Three")
		result += 2;
	else // Deuce
		result += 1;
	
	vett = NULL;
	return result;
}

void ordina_mazzo(int play[][13]){
	
	int card_temp, row_temp, column_temp, value, row, column, card, row1, column1 , card1, x , y;
	int val1 , val2,  temp[4][13] = {0};

	for(card = 2; card <= 5; card++){
	   for(card1 = 1; card1 <= 4; card1++){
	        
		for(x = 0;  x <= 3; x++)
                for(y = 0;  y <= 12; y++)
	   	if(play[x][y] == card ){
           		row = x;
			column = y;}
	   		
	        for(x = 0; x <= 3; x++)
	        for(y = 0; y <= 12; y++)
	      	if(play[x][y] == card1){
			row1 = x;
			column1 = y;}
	      
	        if (grades(row1,column1) > grades(row,column)){	
			play[row][column] = card1;
			play[row1][column1] = card;}
	    }		
	}
}

// DETERMINA LE CARTE UGUALI E CAMBIA QUELLE DIVERSE FUNZIONE DA UTILIZZARE CON UN COPPIA, DOPPIA TRIS O NULLA.

void carte_uguali(int play[][13]){

    int card, card1, x, y, val1, val2, row, row1, column, column1 , v[6] = {0};

	for(card = 1; card <= 4; card++){
		
               for(x = 0;  x <= 3; x++)
                  for(y = 0;  y <= 12; y++)
                     if(play[x][y] == card ){
                        row = x;
                        column = y;}
		
               for(x = 0; x <= 3; x++)
                  for(y = 0; y <= 12; y++)
                     if(play[x][y] == card + 1){
                        row1 = x;
                        column1 = y;}

                        val1 = grades(row,column);
                        val2 = grades(row1,column1);

                        if(val1 == val2){
				if(v[card]  == 0)
			  	v[card] += 1;
				
				if(v[card +1] == 0)
				v[card+1] += 1;		
			}
	}
	
	for(x = 1, y = 0 ; x <= 5; x++)
		if(v[x] == 0)
		y++;

	if(y == 5)
	    x = 1 + rand() % 5;	

	for(card = 1; card <= 5; card++){
                if(v[card] == 0 && card != x){

			for(row = 0; row <= 3 ; row++)
                        for(column = 0; column <= 12; column++)
                           	if(play[row][column] == card){
                                	play[row][column] = 0;
                                        do{
					         row = rand() % 4;
         					 column = rand() % 13;
  					}while(play[row][column] != 0);

     					play[row][column] = card;
				}
		
        	}
	}

}
