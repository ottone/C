//
//  main.c
//  Exe10.9
//
//  Created by Francesco Parrucci on 05/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Create l'unione floatingPoint con in membri float f, double d e long doble l. Scrivete un programma che accetti in input valori di
//  tipo float, double e long double e li immagazzini nelle variabili di un'unione di tipo union floatingPoint. Ogni variabile dell'
//  unione dovrà essere visualizzata come un float, un double e un long double. I valori saranno sempre stampati correttamente?
//
//

/* Example using a bit field  Figura 10.16*/

#include <stdio.h>
#include <stdlib.h>

union floatingPoint {
	float f;
	double d;
	long double l;
};

int main(){
 	
	union floatingPoint flo;

	printf("\nInserisci un float (%d Byte): ",sizeof(float));
	scanf("%f",&flo.f);
	printf("\nValori dell'unione flo f : %f d : %lf l : %Lf \n",flo.f,flo.d,flo.l);

	printf("\nInserisci un double (%d Byte): ",sizeof(double));
	scanf("%lf",&flo.d);
	printf("\nValori dell'unione flo f : %f d : %lf l : %Lf \n",flo.f,flo.d,flo.l);

	printf("\nInserisci un long double(%d Byte): ",sizeof(long double));
	scanf("%Lf",&flo.l);
	printf("\nValori dell'unione flo f : %f d : %lf l : %Lf \n",flo.f,flo.d,flo.l);

	return 0;	
}

