//
//  main.c
//  Exe2.26
//
//  Created by Francesco Parrucci on 28/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//

/* SCRIVETE UN PROGRAMMA CHE LEGGA DUE INTERI E DETERMINI E VISUALIZZI SE IL PRIMO SIA UN MULTIPLO DEL SECONDO. (SUGGERIMENTO: USATE L'OPERATORE MODULO.)
*/


#include <stdio.h>

int main(int argc, const char * argv[]) {

    int primo, secondo;

    printf("Inserisci un intero:");
    scanf("%d", &primo);

    printf("Inserisci un intero:");
    scanf("%d", &secondo);

    printf("Il primo numero %s multiplo del secondo.\n", (primo % secondo) ? "non è" : "è");

    printf("Il secondo numero %s multiplo del primo.\n", (secondo % primo) ? "non è" : "è");

    return 0;
}
