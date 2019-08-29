//
//  main.c
//  Exe14.2
//
//  Created by Francesco Parrucci on 29/08/19.
//  Copyright © 219 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che visualizzi gli argomenti immessi sulla riga di comando di un programma
//

#include <stdio.h>

int main(int argc, char *argv[]){

int a;

if(argc > 1) {
	printf("\nArgomenti inseriti sulla riga di comando....\n");
	for (a = 1; a < argc; a++ ) 
		printf("%2d %s\n",a, argv[a]);
	
}
 return 0;
}
