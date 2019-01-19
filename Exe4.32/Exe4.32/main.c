//
//  main.c
//  Exe4.32
//
//  Created by Francesco Parrucci on 18/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//

/*
 MODIFICATE IL PROGRAMMA CHE AVETE SCRITTO NELL'ESERCIZIO 4.31 IN MODO DA LEGGERE UN NUMERO DISPARI COMPRESO NELL'INTERVALLO DA 
 1 A 19 PER SPECIFICARE IL NUMERO DI RIGHE COMPRESE NEL ROMBO. IL VOSTRO PROGRAMMA DOVRA' QUINDI VISUALIZZARE UN ROMBO DELLA
 MSURA APPROPIATA.
 
 SCRIVETE UN PROGRAMMA CHE VISUALIZZI IL DISEGNO DI UN ROMBO. PRTRETE UTILIZZARE DELE ISTRUZIONI PRINTF CHE VISUALIZZINO OGNUNA
 UN SINGOLO ASTERISCO (*)  O UNO SPAZIO. MASSIMIZZATE IL VOSTRO UTILIZZO DELLE RIPETIZIONI (CON STRUTTURE FOR NIDIFICATE) E 
 MINIMIZZATE IL NUMERO DI STRUZIONI PRINTF
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
// ACQUISISCI IL NUMERO DELLE RIGHE E COLONNE PER IL ROMBO INTERVALLO FISSO TRA 1 E 19
// FINCHE' IL ROMBO NON SARA' TERMINATO
// DISEGNARE PER OGNI RIGA UNA PARTE DEL ROMBO
// ANDARE A CAPO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI:
// -- VARIABILE INT DIMENSIONI, META , COUNT1 COUNT2 COUNT3 E COUNT4;
//###########################################################################################################################
//###########################################################################################################################
// ACQUISISCI UN VALORE TRA 1 E 19 E MEMORIZZALO IN DIMENSIONI
// RICAVA LA META ESATTA DEL VALORE AQUISITO E PONILO IN COUNT3 COUNT4 E META
// PER COUNT1 DA 1 A DIMENSIONI(LUNCHEZZA O LARGHEZZA DEL ROMBO):
// -- STAMPA NUOVA LINEA E RITORNO A CAPO \N
// -- PER COUNT2 DA 1 A DIMENSIONI:
//    -- SE COUNT2 >=  COUNT 3 && COUNT2 <= COUNT4
//       -- STAMPA UN ASTERISCO
// -- SE COUNT1 < DI META ROMBO AD OGNI CICLO ESTERNO DEL FOR DECREMENTI DI UNO COUNT3 E INCREMENTI COUNT4
// -- ALTRIMENTI INCREMENTA DI UNO COUNT3 E DECREMENTA DI UNO COUNT4
//###########################################################################################################################
//###########################################################################################################################



#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int dimensioni, meta, count1 , count2 , count3 , count4;
    
    do{
        printf("\nInserisci un numero nell'intervallo 1 - 19 per le dimensioni del rombo:  ");
        scanf("%d",&dimensioni);
    }while(dimensioni < 1 || dimensioni > 19);
    
    if(dimensioni % 2)
        count3 = count4 = meta = dimensioni / 2 + 1;
    else
        count3 = count4 = meta = dimensioni / 2;
    
    for (count1 = 1; count1 <= dimensioni; count1++){
        printf("\n");
        for(count2 = 1; count2 <= dimensioni; count2++)
            if(count2 >= count3 && count2 <= count4)
                printf("*");
            else
                printf(" ");
        
        if(count1 < meta)
            count3--, count4++;
        else
            count3++, count4--;
        
    }
    return 0;
    
}
