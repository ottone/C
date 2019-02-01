//
//  main.c
//  Exe5.42
//
//  Created by Francesco Parrucci on 01/02/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
IL MASSIMO COMUN DIVISORE DEGLI INTERI X E Y E' L'INTERO PIU' GRANDE CHE DIVIDA ESATTAMENTE SIA X CHE Y. SCRIVETE UNA FUNZIONE 
RICORSIVA gcd CHE RESTITUISCA IL MASSIMO COMUN DIVISORE DI X E Y. IL gcd DI X E Y SARA' DIFINITO IN MODO RICORSIVO COME SEGUE: 
SE Y è UGUALE A 0, ALLORA gcd(X, Y) SARA' X; ALTRIMENTI gcd(X, Y) SARA' gcd(Y, X % Y)DOVE % SARA' L'OPERATORE MODULO
 */


#include <stdio.h>

int gcd(int, int);

int main(int argc, const char * argv[]) {
    // insert code here...
    int n1, n2;
    
    printf("\nInserisci due numeri: ");
    scanf("%d %d",&n1,&n2);
    printf("\nMCD gcd(%d , %d) : %d",n1,n2,gcd(n1,n2));
    
    printf("\nHello, World!\n");
    return 0;
}

int gcd(int x, int y){
    if(y == 0){
        printf(" %d \n");
        return x;
    }else{
        printf("gcd(%d, %d)\n",y,x%y);
        return gcd(y, x % y);
}
}
