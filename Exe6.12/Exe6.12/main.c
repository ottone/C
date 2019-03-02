//
//  main.c
//  Exe6.12
//
//  Created by Francesco Parrucci on 09/02/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
SCRIVETE DELLE ISTRUZIONI SINGOLE CHE ESEGUANO OGNUNA DELLE SEGUENTI OPERAZIONI SU VETTORI UNIDIMENSIONALI: 
 
A) AZZERATE I 10 ELEMENTI DEL VETTORE DI INTERI COUNTS
B) AGGIUNGETE 1  A OGNUNO DEI 15 ELEMENTI CONTENUTI NEL VETTORE DI INTERI BONUS.
C) LEGGETE DALLA TASTIERA I 12 VALORI IN VIRGOLA MOBILE DEL VETTORE monthlyTemperatures
D) VISUALIZZATE IN COLONNA I 5 VALORI CONTENUTI NEL VETTORE DI INTERI BESTSCORES.
 
*/

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int counts[10] = {0}, bonus[15] = {0}, bestScores[] = {34, 43, 8, 12, 9}, count;
    float monthlyTemperatures[12] = {0};
    
    printf("\nValori del vettore counts[]:\n");
    
    for(count = 0; count <= 9; count++)
        printf("%2d",counts[count]);
    
    printf("\n");
    
    for(count = 0; count <= 14; count++)
        bonus[count]++;
    
    printf("\nValori del vettore bonus[]:\n");
    
    for(count = 0; count <= 14; count++)
        printf("%2d",bonus[count]);

    printf("\n");

    for(count = 0; count <= 11; count++){
        printf("\nInserisci una temperatura: ");
        scanf("%f",&monthlyTemperatures[count]);
    }
    
    for(count = 0; count <= 11; count++)
        printf("\nValori inseriti: %.2f", monthlyTemperatures[count]);
    
    printf("\nValori del vettore bestScores:\n");

    for(count = 0; count <= 4; count++)
        printf("\n%4d",bestScores[count]);
    
    printf("\n");

    
    printf("\nHello, World!\n");
    return 0;
}
