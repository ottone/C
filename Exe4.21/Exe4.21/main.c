//
//  main.c
//  Exe4.21
//
//  Created by Francesco Parrucci on 17/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 RISCRIVETE IL PROGRAMMA DELLA FIGURA 4.2 IN MODO CHE L'INIZIALIZZAZIONE DELLA VARIABILE COUNTER SIA ESEGUITA NELLA DICHIARAZIONE , INVECE CHE NELLA STRUTTURA FOR.
*/

/* Counter-controlled repetition with the for structure */
#include <stdio.h>

main()
{
    int counter = 1;
    
    /* initialization, repetition condition, and increment */
    /* are all included in the for structure header        */
    for (/*counter = 1*/; counter <= 10; counter++)
        printf("%d\n", counter);
    
    return 0;
}
