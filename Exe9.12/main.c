//
//  main.c
//  Exe9.12
//
//  Created by Francesco Parrucci on 30/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che prenda in input dalla tastiera una stringa e ne determini la lunghezza. Viaualizzate la stringa utilizzando
//  come dimensione di campo il doppio della sua lunghezza
//
//

#include <stdio.h>

int main(){

char string[100];
int c;

printf("\nImmetti una stringa: ");
scanf("%s%n",string,&c);
printf("\n%*s\n",c*2,string);

return 0;

}

