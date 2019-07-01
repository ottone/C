//
//  main.c
//  Exe9.20
//
//  Created by Francesco Parrucci on 01/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che utilizzi l'indicatore di conversione g per inviare in output il valore 9876,12345.
//  Visualizzate il valore con delle precisioni comprese tra 1 e 9  
//


#include <stdio.h>

int main(){

int i;

for(i = 0; i <= 9; i++){
	printf("\nNumero : 9876.12345 precisione :%d indicatore di conversione %%g : %.*g\n",i,i,9876.12345);
	getchar();
}

return 0;

}

