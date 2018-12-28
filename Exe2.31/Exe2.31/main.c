//
//  main.c
//  Exe2.31
//
//  Created by Francesco Parrucci on 28/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//

/* SCRIVETE UN PROGRAMMA CHE CALCOLI I QUADRATI E I CUBI DEI NUMERI DA 0 A 10 E UTILIZZI LE TABULAZIONI PER VISUALIZZARNE UNA TABELLA 
*/

#include <stdio.h>

int main(int argc, const char * argv[]) {

    
    printf("Numero  \tQuadrato\tCubo    \n");
    printf("%-10d\t%-10d\t%-10d\t\n",1,1*1,1*1*1);
    printf("%-10d\t%-10d\t%-10d\t\n",2,2*2,2*2*2);
    printf("%-10d\t%-10d\t%-10d\t\n",3,3*3,3*3*3);
    printf("%-10d\t%-10d\t%-10d\t\n",4,4*4,4*4*4);
    printf("%-10d\t%-10d\t%-10d\t\n",5,5*5,5*5*5);
    printf("%-10d\t%-10d\t%-10d\t\n",6,6*6,6*6*6);
    printf("%-10d\t%-10d\t%-10d\t\n",7,7*7,7*7*7);
    printf("%-10d\t%-10d\t%-10d\t\n",8,8*8,8*8*8);
    printf("%-10d\t%-10d\t%-10d\t\n",9,9*9,9*9*9);
    printf("%-10d\t%-10d\t%-10d\t\n",10,10*10,10*10*10);
    return 0;
}
