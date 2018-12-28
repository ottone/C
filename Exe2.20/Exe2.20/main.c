//
//  main.c
//  Exe2.20
//
//  Created by Francesco Parrucci on 28/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//

/* Scrivete un programma che legga il raggio di un cerchio e visualizzi il diametro, la circonferenza e l'area dello stesso. Usate il valore costante 3,14159 per pi. Esegute ognuno di questi calcoli all'interno della/e istruzioni/e printf e usate la specifica di conversione %f. (Nota: in questo capitolo avviamo trattato soltanto costanti e variabilit intere. Nel capitolo 3  tratteremo i numeri in virgola mobile, ovverosia quei valori che possono contenere i decimali)
 
*/


#include <stdio.h>

int main(int argc, const char * argv[])
{
    
    const float pi = 3.14159;
    float raggio;
    
    
    printf("Iserire il raggio del cerchio: ");
    scanf("%f", &raggio);
    
    printf("L'area del cerchio è: %f\n", raggio * raggio * pi);
    printf("La circonferenza del cerchio è: %f\n", 2 * pi * raggio);
    printf("Il diametro del cerchio è: %f\n", 2 * raggio );
    
    return 0;
}
