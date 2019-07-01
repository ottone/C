//
//  main.c
//  Exe9.8
//
//  Created by Francesco Parrucci on 30/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un progamma che verifichi la differenza tra gli indicatori di converione %d e %i quando sono utilizzati nelle istruzioni
//  scanf. Utilizzate le istruzioni:
//
//  scanf("%i%d", &x, &y);
//  printf("%d %d\n", x, y);
//
//  per prendere in input e visualizzare i valori. Verificate il funzionamento del programma con i seguenti gruppi di dati:
//
//  10		10
//  -10		-10
//  010		010
//  0x10	0x10
//
//

#include <stdio.h>

#define size 10

int main(){

	int count, x, y;

	printf("\nFornire in input il seguente input:\n10\t10\n-10\t-10\n010\t010\n0x10\t0x10\n");
	for(count = 0; count < 4 ; count++){
		printf("\n%d° input: ",count +1);
		scanf("%i%d", &x, &y);
		printf("Valore acquisito con indicatore di conversione %%i: %d\n",x);
		printf("Valore acquisito con indicatore di conversione %%d: %d\n",y);

	}

	return 0;

}

