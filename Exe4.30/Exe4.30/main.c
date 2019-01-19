//
//  main.c
//  Exe4.30
//
//  Created by Francesco Parrucci on 18/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 RISCRIVETE  IL PROGRAMMA DELLA FIGERA 4.7 SOSTITUENDO L'ISTRUZIONE SWITCH  CON DELLE STRUTTURE  IF / ELSE NIDIFICATE; STATE
 ATTENTI A TRATTARE APPROPRIATAMENTE IL CASO DI DEFAULT. RISCRIVETE QUINDI QUESTA NUOVA VERSIONE. SOSTITUINDO LE STRUTTURE IF /
 ELSE NIFIFICATE CON UNA SERIE DI ISTRUZIONI IF;  ANCHE QUESTA VOLTA, STATE ATTENTI A TRATTARE APPROPRIATAMENTE IL CASO DI 
 DEFAULT (CIO' SARA' PIU' DIFFICILE CHE CON LA VERSIONE DELLE STRUTTURE IF/ELSE NIDIFICATE). QUESTO ESERCIZIO DIMOSTRERA' CHE
 LA STRUTTURA SWITCH E UNA COMODITA' E CHE OGNI SWITCH POTRA' ESSERE SOSTITUITO CON ISTRUZIONI DI SELEZIONE SINGOLA.
 */

/* Counting letter grades */
#include <stdio.h>

main()
{
    int grade;
    int aCount = 0, bCount = 0, cCount = 0, dCount = 0, fCount = 0;
    
    printf("Enter the letter grades.\n");
    printf("Enter the EOF character to end input.\n");
    
    while ( ( grade = getchar() ) != EOF) {
    
        if  (grade == 'A' || grade == 'a')
            ++aCount;
        
        else if (grade == 'B' || grade == 'b')
            ++bCount;
        
        else if (grade == 'C' || grade == 'c')
            ++cCount;
        
        else if (grade == 'D' || grade == 'd')
            ++dCount;
        
        else if (grade == 'F' || grade == 'f')
                ++fCount;   
        
        else if (grade == '\n' || grade == ' ')  /* grade was uppercase B */
                ;
        
        else
                /* catch all other characters */
            printf("Incorrect letter grade entered. Enter a new grade.\n");
        
        }
    
    
    printf("\nTotals for each letter grade are:\n");
    printf("A: %d\n", aCount);
    printf("B: %d\n", bCount);
    printf("C: %d\n", cCount);
    printf("D: %d\n", dCount);
    printf("F: %d\n", fCount);
    
    return 0;
}

