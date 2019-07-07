//
//  main.c
//  Exe10.13
//
//  Created by Francesco Parrucci on 05/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  L'operatore di scorrimento a sinistra può essere usato per comprimere i valori di due caratteri, in una variabile intera
//  senza segno di due byte. Scrivete un programma che accetti in input dalla tastiera due caratteri e li passi alla funzione 
//  packCharacters. Per comprimere due caratteri in una variabile intera unsigned, assegnatele il primo carattere, fatela scorrere
//  a sinistra per 8 posizioni e combinatela con il secondo carattere, usando l'operatore bitwise OR inclusivo. Il programma 
//  dovrà visualizzare i caratteri nel loro formato a bit, prima e dopo essere stati compressi nell'intero unsigned, per 
//  dimostrare che saranno stati compressi correttamente nella variabile unsigned
//
//

#include <stdio.h>

void visualBit(unsigned);
unsigned packCharacters(char, char);

int main()
{
   char  x ,y;
   unsigned u;

   printf("\nInserisci un carattere: ");
   scanf("%c",&x);
   //x = getchar();
   getchar();
   printf("\nInserisci un carattere: ");
   scanf("%c",&y);
   //y = getchar();
   //getchar();
   u = packCharacters(x,y);
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
