//
//  main.c
//  Exe10.20
//
//  Created by Francesco Parrucci on 07/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//

/* Che cosa fara il seguente programma ? */

#include <stdio.h>

int mistery(unsigned);
void visualBit(unsigned);

int main(){
	
	unsigned x;

	printf("Enter an integer: ");
	scanf("%d",&x);
	visualBit(x);
	printf("The result is %d\n", mistery(x));
	
	return 0;
}

void visualBit(unsigned i){
	unsigned n, mask = 1<<15;
        
	for (n = 1; n <= 16; n++ , i<<=1)
	{
		i & mask ? putchar('1') : putchar('0');

		if(n % 8 == 0) putchar(' ');

	}
	putchar('\n');
}

int mistery(unsigned bits){
	unsigned i, mask = 1 << 15, total = 0;


	for(i = 1; i <= 16; i++, bits <<= 1)
		if((bits & mask) == mask) 
			++total;
		
	return total % 2 == 0 ? 1 : 0;
	
}


