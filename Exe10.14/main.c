//
//  main.c
//  Exe10.14
//
//  Created by Francesco Parrucci on 05/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
// Usando gli operatori di scorrimento a destra, AND bitwise e una maschera, scrivete la funzione unpackCharacters, che prenda l'intero 
// unsigned dell'Esercizio 10.13 e lo decomprima in due caratteri. Per decomprimere una coppia di caratteri da un intero unsigned di due
// byte, combinatelo con la maschera 65280 (11111111 00000000) e fate scorrere a destra per otto bit il risultato. Assegnate il valore 
// risultante a una variabile char. In seguito combinate l'intero unsigned con la maschera 255 (00000000 11111111). Assegnate il valore 
// risultante a un'altra variabile char. Il programma dovrà visualizzare in bit l'intero unsigned, prima della decompressione, e quindi
// dovrà visualizzare in bit anche i caratteri, per confermare che la loro decompressione sia stata eseguita correntemente. 
//
//

#include <stdio.h>

void visualBit(unsigned);
unsigned packCharacters(char, char);
void unpackCharacters(char *, char *, unsigned );

int main()
{
   char  x ,y;
   unsigned u;

   printf("\nInserisci un carattere: ");
   scanf("%c",&x);
   getchar();
   printf("\nInserisci un carattere: ");
   scanf("%c",&y);
   u = packCharacters(x,y);
   unpackCharacters(&x,&y,u);
   printf("\nOra il primo carattere varrà %c e il secondo %c\n",x,y);
  
   return 0;
}



void visualBit(unsigned n){
int j, mask = 1 << 15;

for(j = 1; j <= 16; j++, n<<=1){
	n & mask ? putchar('1') : putchar('0');
if((j % 8) == 0 ) putchar(' ');
}
putchar('\n');
}

unsigned packCharacters(char c, char d){
 
	unsigned u = 0;
	puts("Primo carattere ");
	visualBit(c);
	puts("Secondo carattere ");
	visualBit(d);
	
	u |= c;
	u<<=8;
	u |= d;
	visualBit(u);
	
	return u;

}

void unpackCharacters(char *x, char *y, unsigned u){
	unsigned mask  = 65280;

	visualBit(u);
	
	mask &= u;
	*y = mask>>8;
	visualBit(*y);
	
	mask = 255;
	*x = u & mask;
	visualBit(*x);
}
