//
//  main.c
//  Exe6.34
//
//  Created by Francesco Parrucci on 09/03/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
(RICERCA LINEARE) MODIFICATE IL PROGRAMMA DELLA FIGURA 6.18, IN MODO DA UTILIZZARE UNA FUNZIONE RICORSIVA
linearSearch CHE ESEGUA UNA RICERCA LINEARE ALL'INTERNO DEL VETTORE. LA FUNZIONE DOVRA' RICEVERE COME ARGOMENTI
UN VETTORE DI INTERI E LA SUA DIMENSIONE. NEL CASO CHE LA CHIAVE DI RICERCA SIA STATA RITROVATA, RESTITUIRETE 
L'INDICE DEL VETTORE, ALTRIMENTI -1.
*/


/* Linear search of an array */

#include <stdio.h>
#define SIZE 100

int linearSearch(int [], int , int );

int main()
{
   int a[SIZE], x, keySearch, element;

   for (x = 0; x <= SIZE - 1; x++)  /* create some data */
      a[x] = 2 * x;

   printf("Enter integer search key: ");
   scanf("%d", &keySearch);
   element = linearSearch(a, keySearch, 0);

   if (element != -1)
      printf("Found value in element %d\n", element);
   else
      printf("Value not found\n");

   return 0;
}

int linearSearch(int array[], int key, int n)
{
   /*int n;

   for (n = 0; n <= size - 1; ++n)
      if (array[n] == key)
         return n;

   return -1;
*/

   if(key == array[n])
	   return n;
   else if(n <= SIZE -1)
	   linearSearch(array , key, n + 1);
   else
	   return -1;
}	

