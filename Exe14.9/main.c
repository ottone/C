//
//  main.c
//  Exe14.9
//
//  Created by Francesco Parrucci on 29/08/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
//  Scrivete un programma che usi l'istruzione goto per  simularee una struttura di iterazione nidificata che visualizzi un quadrato di asterischi come il seguente:
//
//  * * * * *
//  *       *
//  *       *
//  *       *
//  * * * * *
//
//  Il programma dovrà usare soltanto le seguenti tre istruzioni printf:
//
//  printf("*");
//  printf(" ");
//  printf("\n");	
 

#include <stdio.h>
#include <stdlib.h>

int main()
{
int a = 0, b = 0, c = 0;

	intestazione:
	     printf("*");
	     printf(" ");
	     a++;
	if(a < 6) goto intestazione;

	printf("\n");
	a = 0;

	colonne: 
	     printf("*"); 
	     printf(" ");
	     printf(" ");
	     printf(" ");
	     printf(" ");
	     printf(" ");
	     printf(" ");
	     printf(" ");
	     printf(" ");
	     printf(" ");
	     printf("*"); 
	     printf("\n");
	     a++;
	if(a < 4) goto colonne;

	a = 0;

	fine:
	     printf("*");
	     printf(" ");
	     a++;
	if(a < 6) goto fine;
	
	printf("\n");

return 0;
}
