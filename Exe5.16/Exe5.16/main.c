//
//  main.c
//  Exe5.16
//
//  Created by Francesco Parrucci on 26/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 SCRIVETE UNA FUNZIONE integerPower(base, exponent) CHE RESTITUISCA IL VALORE DELLA BASE ELEVATO ALL'ESPONENTE PER EESEMPIO,
 INTEGER integerPower(3,4) = 3*3*3*3. SUPPONETE CHE exponent SIA UN INTERO POSITIVO DIVERSO DA ZERO E CHE LA BASE SIA UN
 INTERO. LA FUNZIONE integerPower DOVRA' UTILIZZARE FOR PER CONTROLLARE IL CALCOLO. NON UTILIZZATE NESSUNA FUNZIONE DELLA
 LIBRERIA MATEMATICA
 */
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : CALCOLO DELLA POTENZA DI UN INTERO CON ESPONENTE E BASE INTERI POSITIVI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI E FUNZIONE integerPower
// RICHIEDERE DUE NUMERI INTERI POSITIVI EOF PER TERMINARE
// CHIAMA integerPower(X,Y) E STAMPA RISULTATO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI E FUNZIONE integerPower:
// -- FUNZIONE  (int) integerPower (int, int)
// -- VARIABILE INT X , Y;
//###########################################################################################################################
//###########################################################################################################################
// RICHIEDERE DUE INTERI POSITIVI E MEMORIZZARLI IN X E Y EOF PER TERMINARE
// FINCHE' X E Y <= 0 CONTINUA A RICHIEDERE
// RICHIAMA integerPower(x,y) E STAMPA IL RISULTATO
// PONI X E Y = 0
//###########################################################################################################################
//###########################################################################################################################
//######################################## FUNZIONE int integerPower(int x, int y)###########################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARA UNA VARIABILE M = X
// PER Y >= 0
// X = X * M
// DECREMENTA Y
// RITORNA IL VALORE DI X
//###########################################################################################################################
//###########################################################################################################################



#include <stdio.h>
int integerPower(int, int);

int main(int argc, const char * argv[]) {
    // insert code here...
    int x =0, y = 0;
    do{
        do{
            printf("\nInserisci due numeri positivi:");
            scanf("%d%d",&x,&y);
        }while(x <= 0 && y <= 0);
        
        if (x && y)
            printf("\nCalcolo potenza con di %d elevato alla %d: %d",x,y,integerPower(x,y));
        
    }while(getchar() != EOF);
    printf("\nHello, World!\n");
    return 0;
}

int integerPower(int x, int y){
    int m = x;
    for(;y > 1 ; y--)
        x *=m;
    
    return x;
}
