//
//  main.c
//  Exe10.17
//
//  Created by Francesco Parrucci on 06/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che inverta l'ordine dei bit di un valore intero senza segno. Il programma dovrà prendere in input dall'utente 
//  il valore e richiamare la funzione reverseBits per visualizzare i bit in ordine inverso. Visualizzate il valore in bit, prima e dopo
//  che questi siano stati invertiti, per confermare che siano invertiti correttamente
//

#include <stdio.h>

void visualBit(int);
void reverseBit(int);

int main()
{
   int i = 0;
   printf("\nInserire un intero: ");
   scanf("%d",&i);

   visualBit(i);
   reverseBit(i);
   
   return 0;
}



void visualBit(int n){
int j, mask = 1 << 31;

for(j = 1; j <= 32; j++, n<<=1){
	n & mask ? putchar('1') : putchar('0');
if((j % 8) == 0 ) putchar(' ');
}
putchar('\n');
}

void reverseBit(int n){
int j, mask = 1;

for(j = 1; j <= 32; j++, n>>=1){
	n & mask ? putchar('1') : putchar('0');
if((j % 8) == 0 ) putchar(' ');
}
putchar('\n');
}
