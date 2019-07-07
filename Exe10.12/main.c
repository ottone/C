//
//  main.c
//  Exe10.12
//
//  Created by Francesco Parrucci on 05/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
// Far scorrere a sinistra di 1 bit un intero unsigned è equivalente a moltiplicare il valore per 2. Scrivete la funzione power2 
// , che accetti i due argomenti interi number e pow e calvoli 
//
// number * 2 ^ pow
//
// Usate l'operatore di scorrimento per calcolare il risultato. Il programmma dovrà visualizzare i valori come interi e come bit. 
//

#include <stdio.h>

int power2(int , int);

int main()
{
   int  x, y;

   printf("\nInserisci due interi: ");
   scanf("%d%d",&x,&y);
   printf("\nProdotto di %d per 2^%d: %d\n",x,y,power2(x,y));
   return 0;
}




int power2(int number, int pow){
	int i = 1<<pow;	
	return number * i;
}
