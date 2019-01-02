//
//  main.c
//  Exe3.45
//
//  Created by Francesco Parrucci on 01/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 SCRIVERE UN PROGRAMMA CHE LEGGA IN INPUT TRE INTERI DIVERSI DA ZERO E DETERMINI SE POSSONO ESSERE I LATI DI UN TRIANGOLO 
 RETTANGOLO
 */
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : DETERMINARE SE TRE INTERI POSSONO RAPPRESENTARE I TRE LATI DI UN TRIANGOLO RETTANGOLO
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
// SE LA SOMMA DEI QUADRATI DEI LATI CORTI E' UGUALE AL QUADRATO DEL LATO LUNGO
//    SE LA DIFFERENZA DEI QUADRATI DEL LATO LUNGO PER UNO DEL LATO CORTO E' UGUALE AL QUADRATO DEL LATO CORTO
//      E  SE LA DIFFERENZA DEI QUADRATI DEL LATO LUNGO PER IL SECONDO LATO CORTO E' UGUALE AL QUADRATO DEL LATO CORTO
//         ALLORA  E' UN TRIANGOLO RETTANGOLO
// ALTRIMENTI NON LO E'
//###########################################################################################################################
//###########################################################################################################################
// STAMPA IL RISULTATO
//###########################################################################################################################
//###########################################################################################################################

#include <stdio.h>Un

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a, b, c, temp, count1 , count2;
    
    printf("Iserisci un valore in virgola mobile:");
    scanf("%d",&c);
    
    printf("Iserisci un valore in virgola mobile:");
    scanf("%d",&temp);
    
    if(temp < c){
        b = c;
        c = temp;
    }else
        b = temp;
    
    printf("Iserisci un valore in virgola mobile:");
    scanf("%d",&temp);
    
    if(temp < c){
        a = b;
        b = c;
        c = temp;
    }else if(temp > c && temp < b){
        a = b;
        b = temp;
    }else
        a = temp;
    
    
    
    printf("\nValori in ordine: %d %d %d\n", a , b, c);
    
    if( a * a ==  b * b + c * c){
        if(b * b == a * a - c * c)
            if(c * c == a * a - b * b)
                printf("\nE' un triangolo rettangolo\n");
    }else
        printf("\nNon è un triangolo rettangolo.\n");
    
    return 0;
}
