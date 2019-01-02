//
//  main.c
//  Exe3.44
//
//  Created by Francesco Parrucci on 31/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//
/* 
 SCRIVERE UN PROGRAMMA CHE LEGGA IN INPUT TRE VALORI DI TIPO FLOAT DIVERSI DA ZERO E QUINDI DETERMINI E VISUALIZZI SE POSSONO
 REPPRESENTARE I LATI DI UN TRIANGOLO. UN TRIANGOLO E' UN POLIGONO DI 3 LATI. DATI TRE SEGMENTI DI MISURE A, B, C COME FACCIO A 
 SAPERE SE POSSO COSTRUIRCI UN TRIANGOLO? CIASCUNO DEVE ESSERE MINORE DELLA SOMMA DEGLI ALTRI DUE E MAGGIORE DELLA LORO 
 DIFFERENZA
*/
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : DETERMINARE SE TRE VALORI DI TIPO FLOAT POSSONO RAPPRESENTARE I TRE LATI DI UN TRIANGOLO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// INIZIALIZZARE LE VARIABILI
//###########################################################################################################################
//###########################################################################################################################
// PRENDERE IN INPUT I TRE LATI
// ORDINARE I VALORI A B C
// PER OGNI LATO DETERMINARE SE COMPRESO TRA SOMMA E DIFFERENZA DEGLI ALTRI DUE
//###########################################################################################################################
//###########################################################################################################################
// STAMPA IL RISULTATO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE E INIZIALIZZAZIONE DELLE VARIABILI A, B, C, COUNT
//###########################################################################################################################
//###########################################################################################################################
// ORDINA I VALORI IMMESSI
// SE A COMPRESO TRA B + C E B - C, B E' COMPRESO TRA A + C E A - C E C E' COMPRESO TRA A + B E A - B
// ALLORA I TRE VALORI POSSONO APPARTENERE AI LATI DI UN TRIANGOLO
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>Un

int main(int argc, const char * argv[]) {
    // insert code here...
    float a , b , c , temp;
    int count1 , count2;
    
    printf("Iserisci un valore in virgola mobile:");
    scanf("%f",&c);
    
    printf("Iserisci un valore in virgola mobile:");
    scanf("%f",&temp);
    
    if(temp < c){
        b = c;
        c = temp;
    }else
        b = temp;
    
    printf("Iserisci un valore in virgola mobile:");
    scanf("%f",&temp);
    
    if(temp < c){
        a = b;
        b = c;
        c = temp;
    }else if(temp > c && temp < b){
        a = b;
        b = temp;
    }else
        a = temp;
    
    
    
    printf("\nValori in ordine: %.2f %.2f %.2f\n", a , b, c);
    
    if((a < (b + c) && a > (b - c)) && (b < (a + c) && b > (a - c))  && (c < (a + b) && c > (a - b)))
        printf("\nE' un triangolo!\n");
    else
        printf("\nNon è un triangolo.\n");
    
    return 0;
}
