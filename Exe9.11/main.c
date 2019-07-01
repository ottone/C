//
//  main.c
//  Exe9.11
//
//  Created by Francesco Parrucci on 30/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che visualizzi il valore 100,453627 arrotondato all'intero piu vicino e al numero piu vicino a meno di un 
//  decimo, di un centesimo, di un millesimo e di un decimo di millesimo. 
//
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

int c = 0;
float f = 100.453627;

//printf("\ncell(%f) = %f\n",f,ceil(f));

for(c = 0; c < 7; c++){
	printf("Numero : %f precisione : %d %.*g\n",f,c,c,f);
}
printf("\n\n");
return 0;

}

