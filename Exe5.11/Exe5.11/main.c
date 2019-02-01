//
//  main.c
//  Exe5.11
//
//  Created by Francesco Parrucci on 25/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 LA FUNZIONE floor PUO' ESSERE UTILIZZATA PER ARROTONDARE UN NUMERO A UNA SPECIFICA POSIZIONE DECIMALE. L'ISTRUZIONE :
 
 y = floor ( x * 10 + 0.5) / 10;
 
 ARROTONDA X ALLA POSIZIONE DEI DECIMI (LA PRIMA A DESTRA DELLA VIRGOLA DEI DECIMALI). L'ISTRUZIONE:
 
 y = floor(x * 100 + 0.5) / 100;
 
 ARROTONDA X ALLA POSIZIONE DEI CENTESIMI (LA SECONDA A DESTRA DELLA VIRGOLA DEI DECIMALI). SCRIVETE UN PROGRAMMA CHE DEFINISCA
 QUATTRO FUNZIONII PER ARROTONDARE UN NUMERO X IN VARI MDDI:
 
 a) roundToInteger(number)
 b) roundToTenths(number)
 c) roundToHundreths(number)
 d) roundToThousandths(number)
 
 PER OGNI VALORE , LETTO, IL VOSTRO PROGRAMMA DOVRA' VISUALIZZARE IL NUMERO ORIGINALE E QUELLI ARROTONDATI ALL'INTERO , AL
 DECIMO , AL CENTESIMO E AL MILLESIMO PIU' VICINI.
 */

#include <stdio.h>
#include <math.h>

float roundToInteger(float);
float roundToTenths(float);
float roundToHundreths(float);
float roundToThousandths(float);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    float x = 0;
    
    do{
        printf("\nImmettere un numero EOF per terminare: ");
        scanf("%f",&x);
        if (x != 0){
            printf("\ny = roundToInteger(%.3f) = %.3f",x, roundToInteger(x));
            printf("\ny = roundToTenths(%.3f) = %.3f",x, roundToTenths(x));
            printf("\ny = roundToHundreths(%.3f) = %.3f",x, roundToHundreths(x));
            printf("\ny = roundToThousandths(%.3f) = %.3f",x, roundToThousandths(x));}
        x = 0;
    }while(getchar() != EOF);
    
    
    printf("\n");
    
    return 0;
}

float roundToInteger(float x){
    return floor(x + 0.5);
}

float roundToTenths(float x){
    return floor(x * 10 + 0.5) / 10;
}

float roundToHundreths(float x){
    return floor(x * 100 + 0.5) / 100;
}

float roundToThousandths(float x){
    return floor(x * 1000 + 0.5) / 1000;
}
