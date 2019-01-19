//
//  main.c
//  Exe4.34
//
//  Created by Francesco Parrucci on 19/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 SCRIVETE UN PROGRAMMA CHE VISUALIZZI UNA TABELLA CONTENENTE I NUMERI BINARI, OTTALI ED ESADECIMANLI EQUIVALENTI A QUELLI
 DECIMALI COMPRESI NELL'INTERNALLO DA 1 A 245. SE NON AVETE FAMILIARITA0 CON QUESTI SISTEMI NUMERICI, CONSULTATE PRIMA 
 L'APPENDICE E, SE VOLETE TENTARE DI ESEGUIRE QEUESTO ESERCIZIO.
 */
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : VISUALIZZARE I NUMER IN FORMATO TABULARE
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI:
// STAMPARE I NUMERI DA 0 A 256 IN DECIMALE ESADECIMALE OTTALE E BINARIO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI:
// -- VARIABILE INT COUNT, BUFFER BINARY = 2;
//###########################################################################################################################
//###########################################################################################################################
// STAMPARE I NUMERI DA 0 A 256 IN DECIMALE ESADECIMALE OTTALE  E BINARIO
// -- PER COUNT DA 0 A 256
//      -- STAMPA CON LE SPECIFICHE DI CONVERSIONE DI FORMATO IL VALORE DECIMALE ESADECIMALE E OTTALE DI COUNT
//      -- BUFFER = COUNT
//      -- FINCHE BUFFER E' DIVERSO DA ZERO CONTINUA
//      -- MOLTIPLICA BUFFER MODULO DI DUE PER LA POTENZA DI DIECI ELEVATO AL NUMERO DEL CICLO ED ASSEGNA IL RISULTATO A
//         DECIMALE
//      -- STAMPA DECIMALE
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int count, count2, buffer, decimale;
    
    for(count = 1, buffer = 1; count <= 256; count++, buffer = 1){
        printf("\n%3d - %3X - %3o - ",count,count,count);
        
        for(buffer = count, count2 = 0 ,decimale = 0 ; buffer != 0; buffer /=2, count2++ )
            decimale += (buffer % 2 ) * pow(10 , count2);
        
        
        printf("%8d ",decimale);
    }
    printf("\nHello, World!\n");
    return 0;
}
