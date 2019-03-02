//
//  main.c
//  Exe6.15
//
//  Created by Francesco Parrucci on 10/02/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
UTILIZZATE UN VETTORE UNIDIMENSIONALE PER RISOLVERE IL SEGUENTE PROBLEMA. LEGGETE IN INPUT 20 NUMERI, OGNUNO DEI QUALI SARA' 
COMPRESO TRA 10 E 100, ESTREMI INCLUSI. OGNI VOLTA CHE LEGGETE UN NUMERO, VISUALIZZATELO QUALORA NON SIA UN DUPLICATO DI UNO 
GIA' LETTO. PREPARATEVI AL CASO PEGGIORE IN CUI TUTTI I 20 NUMERI SIANO DIFFERENTI. UTILIZZATE IL VETTORE PIU' PICCOLO 
POSSIBILE PER RISOLVERE QUESTO PROBLEMA.
*/



#include <stdio.h>
#define SIZE 10

int main(int argc, const char * argv[]) {
    // insert code here...
    int x = 0, y = 0, temp, vett[SIZE] = {0};
    
    while(y < SIZE){
        
    do{
        printf("\nImmetti un numero compreso tra 10 e 100: ");
        scanf("%d",&temp);
    }while(temp < 10 || temp > 100);
        
    for(x=0; x <= y;x++)
        if(vett[x] == temp)
            temp =0;
    if(temp)
        vett[y++] = temp;
        
    }
    
    
    for(x = 1 ; x <= SIZE ; x++){
        printf("%3d",vett[x - 1]);
        if(x % 5 == 0)
            printf("\n");
    }
    printf("\nHello, World!\n");
    return 0;
}
