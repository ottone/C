//
//  main.c
//  Exe8.36
//
//  Created by Francesco Parrucci on 18/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
//  (Visualizzare le date in vari formati) Nella corrispondenza commerciale le date sono visualizzate di solito in molti formati. Due dei formati più 
//  comuni sono : 21/07/55 e 21 Luglio 1955
//
//  Scrivete un programma che legga una data nel primo formato e la visualizzi nel secondo.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20

void convDate(void);
int main(){

	char string[size * 50] = {'\0'};	
	
	convDate();
	
	return 0;
}

void convDate(void){
	
	char data[11], day[5], month[5], year[5] ,*p = data;
	int d,m,y;

	printf("Inserire la data nel seguente formato: dd/mm/aaaa: ");

	gets(data);
	puts(data);
	
	d = atoi(strncpy(day,p,strcspn(p,"/\0")));
	//puts(day);
	p += strcspn(p,"/\0") + 1;
	m = atoi(strncpy(month,p,strcspn(p,"/\0")));
	//puts(month);
	p += strcspn(p,"/\0") + 1;
	y = atoi(p);
	//puts(p);

	printf("\nValori di giorno %d, mese %d e anno %d\n",d,m,y);
	
}
