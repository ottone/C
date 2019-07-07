//
//  main.c
//  Exe10.19
//
//  Created by Francesco Parrucci on 06/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Il seguente programma usa la funzione multiple per determinare se l'intero immesso dalla tastiera è un multiplo di qualche intero X.
//  Esaminate la funzione multiple e , quindi determinate il valore di X.
//
//

/* Questo programma determina se un valore è multiplo di X */

#include <stdio.h>

int multiple(int);

int main(){
	
	int y;

	printf("Enter an integer between 1 and 32000: ");
	scanf("%d",&y);

	if(multiple(y))
		printf("%d is a multiple of X\n", y);
	else
		printf("%d is not a multiple of X\n",y);


return 0;
}

int multiple(int num){
	int i, mask = 1, mult = 1;

	for(i = 1; i <= 10; i++, mask <<= 1)
		if((num & mask) != 0) {
			mult = 0;
			break;
		}

	return mult;
}
