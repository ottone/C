//
//  main.c
//  Exe10.15
//
//  Created by Francesco Parrucci on 06/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Riscrivete la funzione unpackCharacters dell'esercizio 10.13 in modo che comprima 4 caratteri, qualora il vostro sistema usi interi 
//  di quattro byte
//

#include <stdio.h>

void visualBit(int);
int packCharacters(char, char, char, char);
void unpackCharacters(char *, char *, int );

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
   //unpackCharacters(&x,&y,i);
   //printf("\nOra il primo carattere varrà %c e il secondo %c\n",x,y);
   
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
	
	i |= a;
	i<<=8;
	i |= b;
	i<<=8;
	i |= c;
	i<<=8;
	i |= d;
	visualBit(i);
	
	return i;

}

void unpackCharacters(char *x, char *y, int i){
	unsigned mask  = 65280;

	visualBit(i);
	
	mask &= i;
	*y = mask>>8;
	visualBit(*y);
	
	mask = 255;
	*x = i & mask;
	visualBit(*x);
}
