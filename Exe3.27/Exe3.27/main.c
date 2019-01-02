//
//  main.c
//  Exe3.27
//
//  Created by Francesco Parrucci on 30/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//

//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : TROVATE I DUE NUMERI MAGGIORI DI 10 VALORI PRENDENDO IN INPUT OGNI VALORE SOLTANTO UNA VOLTA
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// INIZIALIZZARE LE VARIABILI COUNTER , NUMBER, FIRST E SECOND
//###########################################################################################################################
//###########################################################################################################################
// INIZIALIZZA FIRST E SECOND CON I PRIMI DUE NUMERI
// FINCHE COUNTER E' MINORE DI 8 RICEVI UN NUMERO E CONFRONTALO E SCAMBIALO SE MAGGIORE DI FIRST E SECOND
//###########################################################################################################################
//###########################################################################################################################
// VISUALIZZA FIRST E SECOND
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE E INIZIALIZZAZIONE DELLE VARIABILI COUNTER A 0 , NUMBER, FIRST E SECOND
//###########################################################################################################################
//###########################################################################################################################
// INSERISCI UN NUMERO IN FIRST
// INSERISCI UN NUMERO IN SECOND
// SE SECOND E' MAGGIORE DI FIRST INVERTI FIRST CON SECOND
// FINCHE' COUNTER E MINORE DI 8
// INSERISCI UN NUMERO IN NUMBER
// SE NUMBER > FIRST  INVERTI NUMBER CON FIRST E FIRST CON NUMBER
//###########################################################################################################################
//###########################################################################################################################
// VISUALIZZA FIRST E SECOND
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int count = 0, number , first , second;
    
    printf("Inserisci un numero: ");
    scanf("%d", &first);
    printf("Inserisci un altro numero: ");
    scanf("%d", &second);
    
    if (first < second){
        number = second;
        second = first;
        first = number;
    }
    
    while (count++ < 8 ){
        printf("Inserisci un numero: ");
        scanf("%d", &number);
        
        if (number > first){
            second = first;
            first = number;
        }
    }
    printf("First Number : %d\nSecond Number %d\n", first, second);
    return 0;
}
