//
//  main.c
//  Exe14.2
//
//  Created by Francesco Parrucci on 28/08/19.
//  Copyright © 219 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che calcoli il prodotto di una serie di interi passati alla funzione product, usando un elenco variabile di argomenti. Verificate la vostra funzione con diverse chiamate, ognuna con un numero differente 
//  di argomenti.
//

#include <stdio.h>
#include <stdarg.h>


int product(int , ...); // Calcola il prodotto di una serie di interi usando un elenco variabile di argomenti.

int main(){

int a = 3, b = 5, c = 6, d = 8;
 
printf("%s%d\n%s%d\n%s%d\n%s%d\n\n","a = ", a, "b = ", b, "c = ", c, "d = ", d);
printf("%s%d\n%s%d\n%s%d\n",
          "The product of a and b is ",
          product(2, a, b),
          "The product of a, b and c is ",
          product(3, a, b, c),
          "The product of a, b, c and d is ",
          product(4, a, b, c, d));

 return 0;
}


int product(int l, ...){	// Calcola il prodotto di una serie di interi usando un elenco variabile di argomenti.

	int i, value;
	

	va_list pa;

	va_start(pa, l);

	for(i = 1,value = 1; i <= l; i++)
		value *= va_arg(pa, int);

	va_end(pa);

	return value;

}
