//
//  main.c
//  Exe6.26
//
//  Created by Francesco Parrucci on 09/03/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*(LE OTTO REGINE) UN'ALRO PROBLEMA DEGLI APPASSIONATI DEL GIOCO DEGLI SCACCHI È' QUELLO DELLE OTTO REGINE. DETTO SEMPILICEMENTE :
E' POSSIBILE SISTEMARE OTTO REGINE SU UNA SCACCHIERA VUOTA IN MODO CHE NESSUNA DI LORO "ATTACCHI" LE ALTRE, OVVEROSIA IN MODO CHE 
NON CI SIANO DUE REGINE SULLE STESSA RIGA, SULLA MEDESIMA COLONNA O LUNGO LA STESSA DIAGONALE? UTILIZZATE IL TIPO DI RAGGIONAMENTO
SVILUPPATO NELL'ESERCIZIO 6.24 PER FORMULARE UN METODO EURISTICO CHE RISOLVA IL PROBLEMA DELLE OTTO REGINE. ESEGUITE IL VOSTRO 
PROGRAMMA. (SUGGERIMENTO: SARA' POSSIBILE ASSEGNARE UN VALORE NUMERICO A OGNI CASELLA DELLA SCACCHIERA, IN MODO DA INDICARE IL 
NUMERO DI QUELLE CHE SARANNO "ESCLUSE", IN UNA SCACCHIERA VUOTA, UNA VOLTA CHE UNA REGINA SARA' STATA SISTEMATA IN QUELLA CASELLA.
PER ESEMPIO , A OGNUNO DEI QUATRO ANGOLI SAREBBE ASSEGATO IL VALORE 22, COME MOSTRATO :

* * * * * * * *
* *
*   *
*     *
*       *
*         *
*           *
*             *

UNA VOLTA CHE QUESTI "NUMERI DI ESCLUSIONE" SARANNO STATI SISTEMATI IN TUTTE LE CASELLE 64 CASELLE, UN METODO EURISTICO APPROPRIATO POTRA' ESSERE:SISTEMATE LA PROSSIMA REGINA NELLA CASELLA CON IL NUMERO DI ELIMINAZIONE PIU' BASSO. PER QUALE MOTIVO QUESTA STRATEGIA E' INTUITIVAMENTE ATTRAENTE? 
*/


#include <stdio.h>
#define n 8

void stampa(char matrix[n][n]){

        int count, count1;

        printf("\n\n");

        for(count = 0; count <= n - 1; count++){
                for(count1 = 0; count1 <= n - 1; count1++ ){
                        printf("%2c", matrix[count][count1]);
                }
                printf("\n");
        }

        printf("\n\n");
}

void copy_board(char myboard[n][n], char board[n][n]){
	
	int j ,i;

	for(j = 0; j <= n - 1; j++)
		for(i = 0; i <= n - 1; i++ )
				myboard[j][i] = board[j][i];

}

void sign(char board[n][n], int row){      /* main algorithm */
    int i, j;
 
    if (row == n) // condizione di terminazione
        return;
       
    for (j=0; j<n; j++) {		
        if (board[row][j] != 'x') {     
            for(i=0; i<n; i++) {
                if (i == row) continue;
                board[i][j] = 'x';   	// same column
                 
                if ((j-row+i >= 0) && (j-row+i < n)) 
                    board[i][j-row+i] = 'x';
                 
                if ((j+row-i >= 0) && (j+row-i < n)) 
                    board[i][j+row-i] = 'x';
            }
            board[row][j] = 'R';
            sign(board, row+1);
        }
    }
}

void set(char b[n][n]){
	
int j , i;

for(j = 0; j <= n; j++)
	for(i = 0; i <= n ; i++)
		b[j][i] = '.';
}	
	

int main(){
char board [n][n];
sign(board,0);
stampa(board);
return 0;
}

