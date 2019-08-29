//
//  main.c
//  Exe14.7
//
//  Created by Francesco Parrucci on 29/08/19.
//  Copyright © 219 Francesco Parrucci. All rights reserved.
//
//
//  Scrivete un programma che allochi dinamicamente un vettore di interi. La dimensione del vettore dovrà essere immessa dalla tastiera. Gli elementi del vettore dovranno essere impostati con valori immessi dalla tastiera. Visualizzate
//  i valori del vettore e quindi allocate nuovamente la sua memoria a metà del numero corrente di elementi. Visualizzate i valori rimasti nel vettore per confermare che corrispondano alla prima  metà dei valori contenuti nel vettore
//  originale.
//
//

/* Using signal handling */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int i, x, *v;
	
   srand(clock());

   printf("\nInizializzazione di un vettore di interi, immetti la dimensione: ");
   scanf("%d",&i);

   v = calloc(i,sizeof(int));

   for(x = 0; x < i; x++) v[x] = 1 + (rand() % 100);

   printf("\nStampa del vettore allocato dinamicamente:\n");
   for(x = 0; x < i; x++) printf("v[%2d] = %2d\n",x,v[x]);

   printf("\nInserisci una nuovaa dimensione per il vettore di interi: ");
   scanf("%d",&i);

   v = realloc(v,i);

   if(i < x){
	printf("\n...nuova dimensione...\n");
	for(x = 0; x < i; x++) printf("v[%2d] = %2d\n",x,v[x]);
   }else{
	for(; x < i; x++) v[x] = 1 + (rand() % 100);
	for(x = 0 ; x < i ; x++) printf("v[%2d] = %2d\n",x,v[x]);
   }

   return 0;
}
