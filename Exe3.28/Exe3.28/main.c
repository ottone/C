//
//  main.c
//  Exe3.28
//
//  Created by Francesco Parrucci on 30/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//

/* Analysis of examination results : Modificare il programma in modo da convalidare l'input . Reiterate su ogni input qualora il valore immesso fosse deverso da 1 o da 2 finchè l'utente non immetta un valore corretto.
*/



#include <stdio.h>

main()
{
    
 /* initializing variables in declarations */
    char carattere;
    int passes = 0, failures = 0, student = 1, result;

    /* process 10 students; counter-controlled loop */
    while (student <= 10) {
        do{
            
           printf("Enter result (1=pass,2=fail): ");
           carattere = getchar();
           getchar();
           if(carattere == '1')
               result = 1;
           else if (carattere == '2')
               result = 2;
           else
               result = 3;
            
        } while(result != 1 && result != 2);
            
        if (result == 1)        /* if/else nested in while */
            passes = passes + 1;
       else
            failures = failures + 1;
        
        student = student + 1;
    }
    
    printf("Passed %d\n", passes);
    printf("Failed %d\n", failures);
    
    if (passes > 8)
        printf("Raise tuition\n");

    return 0;   /* successful termination */
}


