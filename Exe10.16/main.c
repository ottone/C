//
//  main.c
//  Exe10.16
//
//  Created by Francesco Parrucci on 06/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Riscrivete la funzione unpackCharacters dell'Esercizio 10.14 in modo che decomprima 4 caratteri, qualora il vostro sistema usi 
//  interi di 4 byte. Create le maschere necessarie per decomprimere i 4 caratteri, facendo scorrere a sinistra per 8 bit il valore 
//  255 contenuto nella variabile maschera, per 0, 1, 2, 3 volte (secondo il byte che state decomprimendo).
//

#include <stdio.h>

void visualBit(int);
int packCharacters(char, char, char, char);
void unpackCharacters(char *, char *, char *, char *, int );

int main()
{
   char  a, b, c, d;
   int i = 0;

   printf("\nInserisci un carattere: ");
   scanf("%c",&a);
   getchar();
   printf("\nInserisci un carattere: ");
   scanf("%c",&b);
   getchar();
   printf("\nInserisci un carattere: ");
   scanf("%c",&c);
   getchar();
   printf("\nInserisci un carattere: ");
   scanf("%c",&d);
   i = packCharacters(a,b,c,d);
  
   unpackCharacters(&a,&b,&c,&d,i);
   printf("\nOra il primo carattere varrà %c il secondo %c il terzo %c ed il quarto %c\n",a,b,c,d);
   
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

int packCharacters(char a, char b, char c, char d){
 
	int i = 0;
	puts("Primo carattere ");
	visualBit(a);
	puts("Secondo carattere ");
	visualBit(b);
	puts("Terzo carattere ");
	visualBit(c);
	puts("Quarto carattere ");
	visualBit(d);
	
	i |= a, i<<=8;
	i |= b, i<<=8;
	i |= c, i<<=8;
	i |= d;

	visualBit(i);
	
	return i;

}

void unpackCharacters(char *a, char *b, char *c, char *d, int i){
	int mask  = 255;

	*a = mask & i, i >>= 8;
	*b = mask & i, i >>= 8;
	*c = mask & i, i >>= 8;
	*d = mask & i;
}
