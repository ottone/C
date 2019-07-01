//
//  main.c
//  Exe9.13
//
//  Created by Francesco Parrucci on 30/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che converta degli interi, corrispondenti a temperature Fahrenheit comprese tra 0 e 212, nelle equivalenti
//  Celsius espresse in numeri a virgola mobile con 3 cifre di precisione. Utilizzate la formula 
//
//  celsius  = 5.0 / 9.0 * (fahrenheit - 32);
//
//  per eseguire il calcolo. L'output dovrà essere visualizzato giustificato a destra all'interno di due colonne, ognuna di 10 
//  caratteri, e le temperature Celsius dovranno essere precedute da un segno sia per i valori positivi, sia per quelli negativi.
//
//


#include <stdio.h>

int main(){

float celsius;
int count, fahrenheit = 0;

printf("\n%10s\t%10s\n","Fahrenheit","Celsius");
for(count = 0; count < 213; count++,fahrenheit++)
	printf("%+10d\t%+10.1f\n",fahrenheit,5.0 / 9.0 * (fahrenheit - 32));

return 0;

}

