//
//  main.c
//  Exe4.33
//
//  Created by Francesco Parrucci on 18/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 SE AVETE FAMILIARITA CON I NUMERI ROMANI SCRIVETE UN PROGRAMMA CHE VISUALIZZI UNA TABELLA CONTENENTE TUTTI I NUMERI ROMANI 
 EQUIVALENTI A QUELLI DECIMALI COMPRESI NELL'INTERVALLO DA 1 A 100.
 */
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : VISUALIZZARE UNA TABELLA 10 X 10 CONTENENTE I NUMERI ROMANI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI:
// CONTA DA UNO A CENTO
// TRADUCI IL RISPETTIVO NUMERO IN NUMERO ROMANO
// SE HAI RAGGIUNTO LINEA COMPOSTA DA 10 CARATTERI VAI A CAPO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI:
// -- VARIABILE INT COUNT E NUMBER;
//###########################################################################################################################
//###########################################################################################################################
// PER COUNT1 DA 1 A 100
// -- NUMBER == COUNT
// -- FINCHE' COUNT NON E' MINORE DI UNO
//      -- SE UGUALE A 100 STAMPA C E SOTTRAI 100 A NUMBER
//      -- SE MAGGIORE DI 50 STAMPA L SOTTRAI 50 A COUNT
//      -- SE MAGGIORE DI 10 STAMPA X SOTTRAI 10 FINCHE' MAGGIORE DI 10
//      -- SE MAGGIORE DI 5 STAMPA V E SOTTRAI 5
//      -- SE MAGGIORE DI 1 STAMPA I E SOTTRAI I
// -- SE COUNT DIVISO 10 E' RESTO 0 STAMPA NUOVA LINEA
// -- ALTRIMENTI STAMPA UN QUANTITA CARATTERI SPAZIO PER ALLINEAMENTO NUMERI
//###########################################################################################################################
//###########################################################################################################################

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int count, count1, number;
    
    for(count = 1, count1 = 10 ; count <= 100; count++, count1 = 10){
        number = count;
       
        while (number >= 1){
            
            if (number == 100){
                count1--;
                printf("C");
                number -= 100;
            }else if (number >= 50){
                count1--;
                number -= 50;
                printf("L");
            }else if(number >= 10){
                count1--;
                printf("X");
                number -= 10;
            }else if(number >= 5 && number < 10){
                count1--;
                printf("V");
                number -= 5;
            }else if(number >= 1 && number < 5){
                count1--;
                number--;
                printf("I");
            }
        
        }
        
        
        
        if(count % 10 == 0)
            printf("\n");
        else
            while(count1-- >= 1)
                printf(" ");
        
        }
        
            
    
    return 0;

}