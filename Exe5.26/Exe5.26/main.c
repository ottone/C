//
//  main.c
//  Exe5.26
//
//  Created by Francesco Parrucci on 30/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 UN NUMERO INTERO E' DETTO NUMERO PERFETTO QUALORA LA SOMMA DEI SIUOI FATTORI, INCLUSO 1 (MA NON SE STESSO), SIA PARI A QUEL 
 NUMERO. PER ESEMPIO 6 E' UN NUMERO PERFETTO PERCHE' 6 = 1 + 2 + 3. SCRIVETE UNA FUNZIONE perfect CHE DETEMINI SE IL PARAMETRO
 number SIA UN NUMERO PERFETTO. UTILIZZATE QUESTA FUNZIONE IN UN PROGRAMMA CHE DETERMINI E VISUALIZZI TUTTI I NUMERI PERFETTI 
 RRA 1 100. VISUALIZZATE I FATTORI DI OGNI NUMERO PERFETTO, PER CONFERMARE CHE LO SIA VERAMENTE. SFIDATE LA POTENZA DEL VOSTRO 
 COMPUTER, PROVANDO CON NUMERI MAGGIORI DI 1000.
*/
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : VERIFICARE SE UN NUMERO SIA PERFETTO (LA SOMMA DEI SUOI FATTORI INCLUSO 1 SIA PARI A QUEL NUMERO)
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI E FUNZIONI perfect:
// PRENDERE IN INPUT UN NUMERO EOF PER TERMINARE E DETERMINARE SE E' UN NUMERO PERFETTO CHIAMARE perfect
// STAMPA DEI RISULTATI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI E DELLA FUNZIONE perfect:
// -- PROTOTIPO DI FUNZIONE void perfect(int)
//###########################################################################################################################
//###########################################################################################################################
// ACQUISISCI IL NUMERO number O EOF PER TERMINARE
// -- RICHIAMA LA FUNZIONE perfect
//###########################################################################################################################
//###########################################################################################################################
//################################################# FUNZIONE perfect PRIMO RAFFINAMENTO #####################################
//###########################################################################################################################
//###########################################################################################################################
// DEFINIZIONE DELLA FUNZIONE int perfect(int number)
//###########################################################################################################################
//###########################################################################################################################
// -- DETERMINARE I FATTORI DEL NUMERO
// -- SOMMARLI PER VERIFICARE SE LA LORO SOMMA RESTITUISCA IL NUMERO INIZIALE
//###########################################################################################################################
//###########################################################################################################################
//################################################# FUNZIONE perfect SECONDO RAFFINAMENTO ###################################
//###########################################################################################################################
//###########################################################################################################################
// FINCHE' store != number
// -- SE number / number - count1 E' PARI A ZERO SOMMA NUMBER - count1 A STORE INCREMENTA count1
//###########################################################################################################################
//###########################################################################################################################
//################################################ VERSIONE RICORSIVA #######################################################
// CASO DI TERMINAZIONE
// CASO BASE E CASO PIU COMPLESSO
//###########################################################################################################################
//###########################################################################################################################
// CASO TERMINAZIONE
//
// CASO BASE NUMBER / FATTORE UGUALE A ZERO
#include <stdio.h>

unsigned long int perfect(unsigned long int number,unsigned long int store);

int main(int argc, const char * argv[]) {
    // insert code here...
    unsigned long int number, store = 1;
    do{
    printf("\nImmetti un numero EOF per terminare: ");
    scanf("%lu",&number);
    printf("\nRisultato di perfect: %lu",perfect(number, store));
    }while(getchar() != EOF);
    printf("\nHello, World!\n");
    return 0;
}

unsigned long int perfect(unsigned long int number,unsigned long int store){
    if (store == number) // caso di terminazione
        return 0;
    else
        if(number % store)
          return perfect(number, store + 1);
        else
          return store + perfect(number, store + 1);
    
}

/*
int perfect(int number){
    int count = 1, store = 0;
    
    while(store < number){
        if(!(number % count))
            store += count;
        count++;
    }
    if (store == number)
        return store;
    else
        return 0;
}
*/