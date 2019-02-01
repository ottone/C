//
//  main.c
//  Exe5.24
//
//  Created by Francesco Parrucci on 30/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 
 IMPLEMENTATE LE SEGUENTI FUNZIONI INTERE:
 
 A) LA FUNZIONE celsius RESTITUISCE L'EQUIVALENTE CELSIUS DI UNA TEMPERATURA FAHRENHEIT (UTILIZZATE LA FORMULA °C = (5/9) * 
    (°F-32), DOVE °C RAPPRESENTA LA TEMPERATURA IN GRADI CELSIUS E °F QUELLA IN GRADI FAHRENHEIT).
 
 B) LA FUNZIONE fharenheit RESTITUISCE L'EQUIVALENTE FARHENHEIT DI UNA TEMPERATURA CELSIUS (UTILIZZATE LA FORMULA °F = (9/5)°C
    +32, DOVE °C RAPPRESENTA LA TEMPERATURA IN GRADI CELSIUS E °F QUELLA IN GRADI FAHRENHEIT).
 
 C) UTILIZZATE QUESTE FUNZIONI, PER SCRIVERE UN PROGRAMMA CHE VISUALIZZI DELLE TABELLE CHE MOSTRINO GLI EQUIVALENTI FAHRENHEIT
    DI TUTTE LE TEMPERATURE CELSIUS COMPRESE TRA 0 E 100 GRADI, NONCHE' GLI EQUIVALENTI CELSIUS DI TUTTE LE TEMPERATURE 
    FAHRENHEIT COMPRESE TRA 32 E 212 GRADI. VISUALIZZATE I RISULTATI IN UNA FORMA TABULARE ORDINATA CHE MINIMIZZI IL NUMERO DI 
    RIGHE DELL'OUTPUT, PUR RIMANENDO LEGGIBILE.
 
 */

//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : VISUALIZZARE I GRADI CELSIUS E FARHENHEIT DA 0 A 100
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI E FUNZIONI celsius E fahrenheit:
// STAMPA DEL RISUTATI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI E FUNZIONI fahrenheit :
// -- PROTOTIPO DI FUNZIONE float fahrenheit(float)
// -- VARIABILE INT COUNT
//###########################################################################################################################
//###########################################################################################################################
// STAMPA UNA INTESTAZIONE FAHRENHEIT
// PER I VALORI DI COUNT DA 0 A 100
// -- STAMPA IL VALORE IN GRADI CELSIUS E STAMPA IL CORRISPETTIVO VALORE IN GRADI FAHRENHEIT
//###########################################################################################################################
//###########################################################################################################################
// DEFINIZIONE DELLA FUNZIONE float fahr fahrenheit(float celsius)
//###########################################################################################################################
//###########################################################################################################################
// -- RESTITUISCI ( 9 / 5 ) + 32;
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>

float fahrenheit(float);

int main(int argc, const char * argv[]) {
    // insert code here...
    int count;

    printf("\nGRADI CELSIUS\tGRADI FAHRENHEIT\n");
    for(count = 0; count <= 100; count++)
        printf("\n%6.2f%6s\t%9.2f",(float)count,"   ",fahrenheit((float)count));
    printf("\nHello, World!\n");
    return 0;
}

float fahrenheit(float celsius){
    return (float)9 / (float)5 * celsius + 32;
}
