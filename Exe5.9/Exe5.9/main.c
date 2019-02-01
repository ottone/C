//
//  main.c
//  Exe5.9
//
//  Created by Francesco Parrucci on 25/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 UN GARAGE ADDEBITA UN IMPORTO MINIMO DI $2.00 PER UN PARCHEGGIO FINO A TRE ORE. IL GARAGE ADDEBITA UN'ADDIZIONALE DI $0.50 PER 
 OGNI ORA O FRAZIONE DI ESSA CHE ECCEDA LE TRE DI BASE. L'ADDEBITO MASSIMO PER OGNI DATO PERIODO DI 24 ORE E' $10,00 . ASSUMETE 
 CHE NESSUNA AUTO PARCHEGGI PER PIU' DI 24 ORE PER VOLTA. SCRIVETE UN PROGRAMMA CHE CALCOLI E VISUALIZZI GLI ADDEBITI PER
 OGNUNO DEI TRE CLIENTI CHE HANNO PARCHEGGIATO LE PROPRIE AUTO IN QUESTO GARAGE IERI. DOVRETE IMMETTERE LE ORE DI PARCHEGGIO 
 PER OGNI CLIENTE. IL VOSTRO PROGRAMMA DOVRA' VISUALIZZARE I RISULTATI IN UN FORMATO TABULARE ORDINATO E DOVRA' CALCOLARE
 E VISUALIZZARE IL TOTALE DELLE RICEVUTE DI IERI.
 IL PROGRAMMA DOVRA' UTILIZZARE LA FUNZIONE calculateCharges PER DETERMINARE L'ADDEBITO DI OGNI CLIENTE. I VOSTRI RISULTATI 
 DOVRANNO APPARIRE NEL SEGUENTE FORMATO:
 
  CAR       HOURS       CHARGE
 
  1         1.5         2.00
  2         4.0         2.50
  3         24.0        10.00
 TOTAL      29.5        14.50
 
*/
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : CALCOLO E STAMPA DETTAGLIO E TOTALE NUMERO ORE E IMPORTO DOVUTO PER IL PARCHEGGIO DI TRE VETTURE
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI E FUNZIONI:
// ACQUISISCI IL NUMER DELLE ORE PARCHEGGIATE PER OGNI VETTURA
// STAMPA DEL RISUTATI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI E FUNZIONI:
// -- PROTOTIPO DI FUNZIONE float calcutateCharges (float)
// -- VARIABILE INT COUNT = 1
// -- VARIABILE FLOAT CAR1, CAR2, CAR3,  TOTALHOURS E TOTALDOLLARS;
//###########################################################################################################################
//###########################################################################################################################
// ACQUISISCI IL NUMERO DELLE ORE PARCHEGGIATE  PER OGNI VETTURA
// -- INSERISCI IL NUMERO DI ORE PER LA VETTURA MAX 24
// -- ASSEGNA IL VALORE AD HOURS
// -- SE IL VALORE INSERITO E' MAGGIORE DI 24 O MINORE DI 0 RIPETI
// -- TOTALHOURS = TOTALHOURS + HOURS
// -- TOTALDOLLARS = TOTALDOLLARS + calculateCharges(HOURS)
// -- STAMPA L'INTESTAZIONE CAR  HOURS TOTAL
// -- STAMPA IL VALORE DI COUNT++ , CAR1 E IL VALORE RESTITUITO DA calculateCharges(CAR1)
// -- STAMPA IL VALORE DI COUNT++ , CAR1 E IL VALORE RESTITUITO DA calculateCharges(CAR2)
// -- STAMPA IL VALORE DI COUNT , CAR1 E IL VALORE RESTITUITO DA calculateCharges(CAR3)
// -- STAMPA LA STRINGA "TOTAL %.2F %.2F", TOTALHOURS , TOTALDOLLARS
//###########################################################################################################################
//###########################################################################################################################
// DEFINIZIONE DELLA FUNZIONE float dollari calculateCharges(float hours)
//###########################################################################################################################
//###########################################################################################################################
// SE HOURS E' MINORE UGUALE A 3
//  -- RESTITUISCI 2
// ALTRIMENTI SE HOURS E' MAGGIORE DI 3
//  -- RESTITUISCI 2 + (HOURS - 3) * 0.50
//###########################################################################################################################
//###########################################################################################################################

#include <stdio.h>

float calculateCharges(float);

int main(int argc, const char * argv[]) {
    // insert code here...
    int count;
    float car1, car2, car3;
    

        do{
            printf("\nInserisci le ore di parcheggio vettura 1: ");
            scanf("%f",&car1);
        }while(!(car1 > 0 && car1 <= 24));
    
        do{
            printf("\nInserisci le ore di parcheggio vettura 2: ");
            scanf("%f",&car2);
        }while(!(car2 > 0 && car2 <= 24));
        
        do{
            printf("\nInserisci le ore di parcheggio vettura 3: ");
            scanf("%f",&car3);
        }while(!(car3 > 0 && car3 <= 24));
        
    printf("\n\t%-10s%-10s%-10s\n","CAR","HOURS","CHARGE");
    printf("\n\t%-10d%-10.2f%-10.2f",count++,car1,calculateCharges(car1));
    printf("\n\t%-10d%-10.2f%-10.2f",count++,car2,calculateCharges(car2));
    printf("\n\t%-10d%-10.2f%-10.2f",count,car3,calculateCharges(car3));
    printf("\n\t%-10s%-10.2f%-10.2f\n","TOTAL",car1 + car2 + car3 ,calculateCharges(car1) + calculateCharges(car2) + calculateCharges(car3));
    
    return 0;
}
    

    
float calculateCharges(float hours)
{
    if(hours <= 3)
        return 2;
    else
        return 2 + (hours - 3) * 0.5;
}
