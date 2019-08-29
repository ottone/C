//
//  main.c
//  Exe14.4
//
//  Created by Francesco Parrucci on 29/08/19.
//  Copyright © 219 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che ordini un vettore di interi in modo ascendente o discendente. Il programma dovrà usare gli argomenti della riga di comando per passare -a, per un ordinamento ascendente, o -s per uno discendente. 
//  (Nota: in UNIX questo è il formato standard per il passaggio delle opzioni a un programma). 
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

int main(int argc, char *argv[]){

srand(time(NULL));
int a, c, temp, v[SIZE] = {0};

for(a = 0; a < SIZE; a++)
	v[a] = 1 + (rand() % SIZE);

if(argc != 2) 
	printf("\nUsage order -a (ascendent) -d (descendent)\n");
else{
	if(strcmp(argv[1],"-a") == 0){
		for (a = 0; a < SIZE ; a++)
		       for(c = SIZE - 1; c > a; c--)
				if(v[c] < v[c - 1]){
					temp = v[c];
					v[c] = v[c-1];
					v[c-1] = temp;
				}
		for(a = 0; a < SIZE; a++)
			printf("v[%2d] = %2d\n" , a,v[a]);

	}else if(strcmp(argv[1],"-d") == 0){
		for (a = 0; a < SIZE ; a++)
		       for(c = SIZE - 1; c > a; c--)
				if(v[c] > v[c - 1]){
					temp = v[c];
					v[c] = v[c-1];
					v[c-1] = temp;
				}
		for(a = 0; a < SIZE; a++)
			printf("v[%2d] = %2d\n" , a,v[a]);

	}else
		printf("\nOption admitted are -a (ascending) or -d (descending)\n");
}
 return 0;
}
