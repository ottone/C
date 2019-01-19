//
//  main.c
//  Exe4.22
//
//  Created by Francesco Parrucci on 17/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 MODIFICATE IL PROGRAMMA DELLA FIGURA 4.7 IN MODO CHE CALCOLI LA VOTAZIONE MEDIA DELLA CLASSE.
*/

/* Counting letter grades */
#include <stdio.h>

main()
{
    int grade;
    int acount = 0, bcount = 0, ccount = 0, dcount = 0, fcount = 0;
    
    printf("Enter the letter grades.\n");
    printf("Enter the EOF character to end input.\n");
    
    while ( ( grade = getchar() ) != EOF) {
        
        switch (grade) {    /* switch nested in while */
                
            case 'A': case 'a':  /* grade was uppercase A */
                acount += 10;         /* or lowercase a */
                break;
                
            case 'B': case 'b':  /* grade was uppercase B */
                bcount += 9;         /* or lowercase b */
                break;
                
            case 'C': case 'c':  /* grade was uppercase C */
                ccount += 8;         /* or lowercase c */
                break;
                
            case 'D': case 'd':  /* grade was uppercase D */
                dcount += 7;         /* or lowercase d */
                break;
                
            case 'F': case 'f':  /* grade was uppercase F */
                fcount += 6;         /* or lowercase f */
                break;
                
            case '\n': case' ':  /* ignore these in input */
                break;
                
            default:        /* catch all other characters */
                printf("Incorrect letter grade entered.");
                printf(" Enter a new grade.\n");
                break;
        }
    }
    
    printf("\nTotals for each letter grade are:\n");
    printf("A: %d\n", acount / 10 ? acount/10 : 0);
    printf("B: %d\n", bcount / 9 ? bcount/9 : 0);
    printf("C: %d\n", ccount / 8 ? ccount/8 : 0);
    printf("D: %d\n", dcount / 7 ? dcount/7 : 0);
    printf("F: %d\n", fcount / 6 ? fcount/6 : 0);
    printf("Media della Classe : %d.\n", (acount + bcount + ccount + dcount + fcount) / 5);
    
    return 0;
}
