//
//  main.c
//  Exe4.31
//
//  Created by Francesco Parrucci on 18/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 SCRIVETE UN PROGRAMMA CHE VISUALIZZI IL DISEGNO DI UN ROMBO. PRTRETE UTILIZZARE DELE ISTRUZIONI PRINTF CHE VISUALIZZINO OGNUNA UN SINGOLO ASTERISCO (*)  O UNO SPAZIO. MASSIMIZZATE IL VOSTRO UTILIZZO DELLE RIPETIZIONI (CON STRUTTURE FOR NIDIFICATE) E MINIMIZZATE IL NUMERO DI STRUZIONI PRINTF
 */

//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : DISEGNARE UN ROMBO DI ASTERISCHI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI:
// FINCHE' IL ROMBO NON SARA' TERMINATO
// DISEGNARE PER OGNI RIGA UNA PARTE DEL ROMBO
// ANDARE A CAPO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI:
// -- VARIABILE INT COUNT1 COUNT2 COUNT3 E COUNT4;
//###########################################################################################################################
//###########################################################################################################################
// INIZIALIZZA IL VALORE DI COUNT3 E COUNT4 ALLA META DELLA LARGHEZZA O LUNGHEZZA DEL ROMBO
// PER COUNT1 DA 1 A X(LUNCHEZZA O LARGHEZZA DEL ROMBO):
// -- STAMPA NUOVA LINEA E RITORNO A CAPO \N
// -- PER COUNT2 DA 1 A X:
//    -- SE COUNT2 >=  COUNT 3 && COUNT2 <= COUNT4
//       -- STAMPA UN ASTERISCO
// -- SE COUNT1 < DELLA META' ROMBO AD OGNI CICLO ESTERNO DEL FOR DECREMENTI DI UNO COUNT3 E INCREMENTI COUNT4
// -- ALTRIMENTI INCREMENTA DI UNO COUNT3 E DECREMENTA DI UNO COUNT4
//###########################################################################################################################
//###########################################################################################################################



#include <stdio.h>

int main(int argc, const char * argv[]) {
   
    int count1 , count2 , count3 , count4;
    
    count3 = count4 = 6;
    
    for (count1 = 1; count1 <= 11; count1++){
        printf("\n");
        for(count2 = 1; count2 <= 11; count2++)
            if(count2 >= count3 && count2 <= count4)
                printf("*");
            else
                printf(" ");
        
        if(count1 < 6)
            count3--, count4++;
        else
            count3++, count4--;
        
    }
    return 0;
        
}
