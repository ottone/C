//
//  main.c
//  Exe3.37
//
//  Created by Francesco Parrucci on 31/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//
/* SCRIVETE UN PROGRAMMA CON UN CICLO WHILE CHE CONTI UNO PER VOLTA DA 1 A 3000000. OGNI VOLTA CHE IL CONTO RAGGIUNGERA' UN MULTIPLO DI 1000000 VUSUALIZZERETE IL NUMERO SULLO SCHERMO. UTILIZZATE IL VOSTRO OROLOGIO PER MISURARE IL TEMPO IMPIEGATO DA OGNI MILIONE DI ETERAZIONI ALL'INTERNO DEL CICLO
*/


#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int x = 0;
    
    while(++x <= 3000000){
       if(x % 1000000 == 0)
          printf("\n**** %d ****\n", x);
    }
    
    printf("Hello, World!\n");
    return 0;
}
