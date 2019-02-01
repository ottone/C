//
//  main.c
//  Exe5.10
//
//  Created by Francesco Parrucci on 25/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 UN APPLICAZIONE DELLA FUNZIONE FLOOR E' L'ARROTONDAMENTO DI UN VALORE ALL'INTERO PIU' VICINO L'ISTRUZIONE Y = floor(X + 0.5)
 ARROTONDERA' IL NUMERO X ALL'INTERO PIU' VICINO E ASSEGNERA IL RISULTATO A Y. SCRIVETE UN PROGRAMMA CHE LEGGA DIVERSI NUMERI
 E UTILIZZI L'ISTRUZIONE PROECEDENTE PER ARROTONDARE OGNUNO DI QUESTI NUMERI ALL'INTERO PIU' VICINO. PER OGNI NUMERO ELABORATO 
 VISUALIZZATE QUELLO ORIGINALE E QUELLO ARROTONDATO.
*/

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...

    float x = 0 ,y;
    
    do{
        printf("\nImmettere un numero EOF per terminare: ");
        scanf("%f",&x);
        y = floor(x + 0.5);
        if (x != 0)
            printf("\ny = floor(%.2f + 0.5) = %.2f",x, floor(x + 0.5));
        x = 0;
    }while(getchar() != EOF);
    
    
    printf("\n");
    
    return 0;
}