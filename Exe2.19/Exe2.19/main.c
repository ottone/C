//
//  main.c
//  Exe2.19
//
//  Created by Francesco Parrucci on 28/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.

/* SCOPO DELL'ESERCIZIO: SCRIVERE UN PROGRAMMA IN C CHE PRENDA IN INPUT DALLA TASTEIRA TRE DIVERSI INTERI E QUINDI VISUALIZZI LA SOMMA, LA MAEDIA, IL PRODOTTO, IL MINORE E IL MAGGIRORE DI QUESTI NUMERI. USATE SOLTANTO LA FORMA A SSELEZIONE SINGOLA DELA ISTRUZIONE IF CHE AVETE APPRESO IN QUESTO CAPITOLO. LO SCRERMO DI DIALOGO DOVRA APPARIRE COME IL SEGUENTE:
 
 INPUT THREE DEFFERENT INTEGERS: 13 27 14
 SUM IS 54
 AVERAGE IS 18
 PRODUCT IS 4914
 SMALLEST IS 13
 LARGEST IS 27
 */

#include <stdio.h>

int main(int argc, const char * argv[]){
    
    int a, b, c;
    int average, product, smallest, largest;
    
    printf("Inserire tre differenti interi:");
    scanf("%d %d %d", &a ,&b , &c);
    
    average = (a + b + c) / 3;
    printf("La media aritmetica dei tre numeri inseriti è: %d\n", average);
    
    product = a * b * c;
    printf("Il prodotto dei tre numeri inseriti è: %d\n3", product);
    
    smallest = a;
    
    if (b < smallest)
        smallest = b;
    
    if (c < smallest)
        smallest = c;
    
    printf("Il minore dei tre: %d\n", smallest);
    
    largest = a;
    
    if (b > largest)
        largest = b;
    
    if (c > largest)
        largest = c;
    
    printf("il maggriore dei tre: %d\n", largest);
    
    return 0;
    
}
