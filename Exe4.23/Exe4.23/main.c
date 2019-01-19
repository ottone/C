//
//  main.c
//  Exe4.23
//
//  Created by Francesco Parrucci on 17/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 MODIFICA IL PROGRAMMA DELLA FIGURA 4.6 IN MODO CHE UTILIZZI SOLTANTO DEGLI INTERI PER CALCORARE L'INTERESSE COMPOSTO.
 (SUGGERIMENTO: TRATTATE TUTTE LE CIFRE MONETARIE COME QUANTITA' INTERE DI CENTESIMI. IN SEGUITO "SEPARATE" IL RISULTATO DALLE
 SUE PORZIONI DI DOLLARI E CENTESIMI, UTILIZZANDO RISPETTIVAMENTE LE OPERAZIONI DI DIVISIONE E MODULO. INSERITE UN PUNTO)
*/

/* Calculating compound interest */
#include <stdio.h>
#include <math.h>

main()
{
    int year, ammount, principal = 1000, rate = 5;
    
    printf("%4s%21s\n", "Year", "Amount on deposit");
    
    for (year = 1; year <= 10; year++) {
        ammount = (int) (100 * principal * pow(1 + ((float)rate / 100), year));
        printf("%4d%21d.%2d corrispettivo intero\n", year, ammount/100 , ammount%100);
    }
    
    return 0;
}