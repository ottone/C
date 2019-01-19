//
//  main.c
//  Exe4.15
//
//  Created by Francesco Parrucci on 12/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 MODIFICATE IL PROGRAMMA DELL'INTERESSE SCOMPOSTO DELLA SEZIONE 4.6 IN MODO CHE RIPETA I SUOI PASSI PER TASSI D'INTERESSE DEL 5, 6, 7, 8, 9, E 10 PERCENTO. UTILIZZATE UN CICLO FOR PER VARIARE IL TASSO DI INTERESSE
*/

#include <stdio.h>
#include <math.h>

main()
{
    int year, tasso;
    double amount, principal = 1000.0, rate = .05;
    
    printf("%4s%21s\n", "Year", "Amount on deposit");
    for (tasso = 0 ; tasso <= 5; tasso++){
        printf("\nTasso : %.2f\n",rate);
        for (year = 1; year <= 10; year++) {
            amount = principal * pow(1.0 + rate, year);
            printf("Anno %4d°%21.2f\n", year, amount);
        }
        rate += .01;
    }
    return 0;
}
