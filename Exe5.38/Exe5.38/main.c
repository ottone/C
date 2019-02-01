//
//  main.c
//  Exe5.38
//
//  Created by Francesco Parrucci on 31/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 LA SERIE DI FIBONACCI 0, 1, 1, 2, 3, 5, 8, 13, 21... INCOMINCIA CON I TERMINI 0 E 1 E GODE DELLA PROPRIETA' PER LA QUALE OGNI 
 TERMINE SUCCESSIVO SARA' PARI ALLA SOMMA DEI DUE TERMINI PRECEDENTI.
 
 A) SCRIVETE UNA FUNZIONE FIBONACCI(N) NON RICORSIVA CHE CALCOLA IL NUMERO N-ESIMO DI FIBONACCI. 
 
 B) DETERMINATE IL NUMERO DI FIBONACCI PIU GRANDE CE POSSA ESSERE VISUALIZZATO SUL VOSTRO SISTEMA. MODIFICATE IL PROGRAMMA 
    DELLA PARTE A) IN MODO DA USARE DEI DOUBLE, INCECE DEGLI INT , PER CALCOLARE E RESTUTUIRE I NUMERI DI FIBONACCI. LASCIATE 
    REITERARE IL PROGRAMMA FINCHE' NON FALLISCA A CAUSA DI UN VALORE ECCESSIVAMENTE ALTO.
 */
#include <stdio.h>

//void fibonacci(unsigned long int,unsigned long int,unsigned long int);
unsigned long int fibonacci (unsigned long int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    unsigned long int n;
    printf("\nInserisci un numero : ");
    scanf("%lu",&n);
    printf("\nSerie di fibonacci(%lu): %lu",n, fibonacci(n));
    //fibonacci(0, 1, n);
    printf("\nHello, World!\n");
    return 0;
}

/*
void fibonacci(int n){
    int count , count1 = 0, count2 = 1, count3 = 0;
    printf("%d %d ",count1, count2);
    for(count = 1;count <= n; count++){
            printf("%d ",count3 = count1 + count2);
            count1 = count2;
            count2 = count3;
        }
}
*/

/*
void fibonacci(int n){
    int  count1 = 0, count2 = 1, count3 = 0;
    
    do{
        if (count1 == 0)
            printf("%d %d ",count1, count2);

        printf("%d ",count3 = count1 + count2);
        count1 = count2;
        count2 = count3;
    }while(n-- >= 1);
}
*/

/*
 void fibonacci(unsigned long int count1,unsigned long int count2 ,unsigned long int n){
    if(count1 == 0){
        printf("%lu %lu %lu ", count1 , count2, count2);
        fibonacci(count2, count2 + count1, n - 1);
    }else if(n == 0)
        printf("%lu ",count2 + count1);
    else{
        printf("%lu ",count2 + count1);
        fibonacci(count2 , count2 + count1 , n - 1);
    }
}
*/

unsigned long int fibonacci(unsigned long int n){
    if (n == 0 || n == 1)
        return n;
    else
        return fibonacci(n - 2) + fibonacci(n - 1);
}