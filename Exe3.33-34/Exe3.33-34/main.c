//
//  main.c
//  Exe3.33-34
//
//  Created by Francesco Parrucci on 30/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//
/* 
 SCRIVETE UN PROGRAMMA CHE LEGGA IN INPUT IL LATO DI UN QUADRATO E QUINDI LO DISEGNI UTILIZZANDO DEGLI ASTERISCHI. IL VOSTRO PROGRAMMA DOVRA FUNZIONARE CON TUTTI I QUADRATI CON DIMENSIONI DEI LATI COMPRESE TRA 1 E 20. SUCCESSIVAMENTE MODIFICATE IL PROGRAMMA CHE AVETE SCRITTO IN MODO CHE VISUALIZZI UN QUADRATO VUOTO.
 */

//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : DISEGNARE UN QUADRATO DI ASTERISCHI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// INIZIALIZZARE LE VARIABILI LATO, COUNT1 E COUNT2
//###########################################################################################################################
//###########################################################################################################################
// PRENDERE IN INPUT UN NUMERO TRA 1 E 20 E MEMORIZZARLO IN LATO
// FINCHE COUNT E' MINORE DI LATO DISEGNA UNA RIGA DI ASTERISCHI E VAI A CAPO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE E INIZIALIZZAZIONE DELLE VARIABILI LATO , COUNT1 E COUNT2
//###########################################################################################################################
//###########################################################################################################################
// INSERIRE UN NUMERO
// FINCHE IL NUMERO INSERITO NON E' CONTENUTO NELL'INTERVALLO 1 - 20 CONTINUA A CHIEDERE UN NUMERO
// PER COUNT1 UGUALE A ZERO COUNT1 MINORE DI LATO ESEGUI L'ISTRUZIONE SUCCESSIVA E VAI A CAPO
// PER COUNT2 UGUALE A ZERO COUNT2 MINORE DI LATO DISEGNA UNA RIGA DI ASTERISCHI
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>

int main(int argc, const char * argv[]) {
    
 
    int lato, count1 = 0, count2 = 0;
    
    do{
       printf("\nInserisci la dimensione del lato: ");
       scanf("%d",&lato);
    } while(lato < 1 && lato > 20);
 
// QUADRATO PIENO DI ASTERISCHI
    
/*    for(;count1 < lato; count1++){
        for(;count2 < lato; count2++){
            printf("* ");
        }
        count2 = 0;
        printf("\n");
    }
*/
    
// QUADRATO VUOTO DI ASTERISCHI
    
   
    
   for(count1 = 1 ; count1 <= lato ; count1++){
       
       if (count1 == 1 || count1 == lato)
           for(count2 = 0 ; count2 < lato; count2++){
               printf("* ");
           }
       else
           for(count2 = 1; count2 <= lato; count2++)
               if(count2 == 1 || count2 == lato)
                   printf("* ");
               else
                   printf("  ");
           
       
       printf("\n");
   
   }
    
    return 0;
}
