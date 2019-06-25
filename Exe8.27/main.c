//
//  main.c
//  Exe8.27
//
//  Created by Francesco Parrucci on 08/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 *		0	1	2	3	4	5	6	7	8	9
 *	0	nul	soh	stx	etx	eot	enq	ack	bel	bs	ht
 * 	1	nl	vt	ff	cr	so	si	dle	dc1	dc2	dc3
 * 	3	rs	us	sp	!	"	#	$	%	&	'	
 * 	4	(	)	*	+	,	-	.	/	0	1
 * 	5	2	3	4	5	6	7	8	9	:	;
 * 	6	<	=	>	?	@	A	B	C	D	E
 * 	7	F	G	H	I	J	K	L	M	N	O
 * 	8	P	Q	R	S	T	U	V	W	X	Y
 * 	9	Z	[	\	]	^	_	'	a	b	c
 * 	10	d	e	f	g	h	i	j	k	l	m
 * 	11	n	o	p	q	r	s	t	u	v	w
 * 	12	x	y	z	{	|	}	~	del
 *
 * Scrivete le vostre versioni delle funzioni per la conversione delle stringhe in numeri presentate nella Figura 8.5
 * 
 * double atof(const char *nPtr)	converte la stringa nPtr in un double
 *
 * int atoi(const char *nPtr)		converte la stringa nPtr in un int
 *
 * long atol(const char *nPtr) 		converte la stringa nPtr in un long int 
 *
 * double strtod(const char *nPtr, char **endPtr)	converte la stringa nPtr in un double
 *
 * long strtol(const char *nPtr, char **endPtr, int base)	converte la stringa nPtr in un long
 *
 * unsigned long strtoul(const char *nPtr, char **endPTr, int base)	converte la stringa nPtr in un unsigned long)
 *
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define size 50

double atoF(const char *nPtr);
int atoI(const char *nPtr);
long atoL(const char *nPtr);
double strtoD(const char *nPtr, char **endPtr);
long strtoL(const char *nPtr, char **endPtr, int base);
unsigned long strtouL(const char *nPtr, char **endPtr, int base);
int alphaTodigit(char);
void binary(int);

int main(){

	char s[size], *p = NULL;
 	double a;
	int count;
	long c; 
	
	gets(s);
	a = strtoD(s,&p);
	puts(p);
	printf("\nValore di a : %f\n",a);
	


	
	return 0;
}

double atoF(const char *nPtr){
	
	double a = 0;
	int count = 0, decimal = 0, n = 0, sign = 1;
	
	if(nPtr[count++] == '-')
		sign *= -1;

	if(!isdigit(nPtr[count]) && !(nPtr[count] ==  '.'))
		return 0;
	else{
	while(1){

		if (nPtr[count] == '.' && decimal == 0) decimal = count++;
	
		if(isdigit(nPtr[count])){
			n += alphaTodigit(nPtr[count]);
			count++;
			n *= 10;
		}else
			break;
	}
	
	a = (double)n;
	count -= decimal;
	decimal = 1;
	while(count-- > 0) decimal *= 10;
	
	return a = (a /  decimal) * sign;
	}
	
}

int atoI(const char *nPtr)
{
	
	int count = 0, a = 0, sign = 1;
	
	if(nPtr[count++] == '-')
		sign *= -1;

	if(!isdigit(nPtr[count]))
		return 0;
	else{
	while(nPtr[count] != '\0' && isdigit(nPtr[count])){

		a += alphaTodigit(nPtr[count]);
		count++;
		a *= 10;
	}
		
	return a * sign;
	}
}


long atoL(const char *nPtr)
{
	
	int count = 0, sign = 1;
        long int a = 0;
	
	if(nPtr[count++] == '-')
		sign *= -1;

	if(!isdigit(nPtr[count]))
		return 0;
	else{
	while(nPtr[count] != '\0' && isdigit(nPtr[count])){

		a += alphaTodigit(nPtr[count]);
		count++;
		a *= 10;
	}
		
	return a * sign;
	}

}

double strtoD(const char *nPtr, char **endPtr)
{

	double a = 0;
	int count = 0, decimal = 0, n = 0, sign = 1;
	
	if(nPtr[count++] == '-')
		sign *= -1;

	if(!isdigit(nPtr[count]) && !(nPtr[count] ==  '.')){
		*endPtr = &nPtr[count];
		return 0;
	}else{
	while(1){

		if (nPtr[count] == '.' && decimal == 0) decimal = count++;
			
		if(isdigit(nPtr[count])){
			n += alphaTodigit(nPtr[count]);
			count++;
			n *= 10;
		}else
			break;
			

	}
	
	*endPtr = &nPtr[count];

	a = n;

	if(decimal != 0){
		count -= decimal;
		decimal = 1;
		while(count-- > 0) decimal *= 10;
		return a = (a/decimal) * sign;
		
	}else
		return a = (a/10) * sign;
	}
}

long strtoL(const char *nPtr, char **endPtr, int base)
{

	long int n = 0; //%ld
	int count = 0, sign = 1;
	
	if(nPtr[count++] == '-')
		sign *= -1;

	if(!isdigit(nPtr[count]) ){
		*endPtr = &nPtr[count];
		return 0;
	}else{
	while(1){
			
		if(isdigit(nPtr[count])){
			n += alphaTodigit(nPtr[count]);
			count++;
			n *= 10;
		}else
			break;
			

	}
	
	if(base == 2){ 
		printf("\nValore binario:%c\n",sign ? ' ' : '-');
		binary(n);
	}else if(base == 16){
		printf("\nValore esadecimale:%c%X\n",sign ? ' ' : '-',n);
	}else
		printf("\nValore decimale :  %d\n",sign * n);
		
	
	*endPtr = &nPtr[count];
	return n *= sign;

	}
}

unsigned long strtouL(const char *nPtr, char **endPtr, int base)
{

	unsigned long int n = 0; // %ul
	int count = 0;
	
	if(nPtr[count++] == '-') count++;

	if(!isdigit(nPtr[count])){
		*endPtr = &nPtr[count];
		return 0;
	}else{
	while(1){
			
		if(isdigit(nPtr[count])){
			n += alphaTodigit(nPtr[count]);
			count++;
			n *= 10;
		}else
			break;
			

	}
	
	if(base == 2){ 
		printf("\nValore binario : ");
		binary(n);
	}else if(base == 16){
		printf("\nValore esadecimale : %X\n",n);
	}else
		printf("\nValore decimale :  %d\n", n);

	*endPtr = &nPtr[count];
	return n;
	}
}

int alphaTodigit(char c){

	int a = 0;

		switch (c){
			
			case '1':
				a = 1;
				break;
			
			case '2':
				a = 2;
				break;

			case '3':
				a = 3;
				break;
		
			case '4':
				a = 4;
				break;
	
			case '5':
				a = 5;
				break;
	
			case '6':
				a = 6;
				break;
		
			case '7':
				a = 7;
				break;

			case '8':
				a = 8;
				break;

			case '9':
				a = 9;
				break;
				
			}

	       return a;	
}


void binary (int n){

int c, r;

 for (c = 7; c >= 0; c--)
  {
    r = n >> c;

    if (r & 1)
      printf("1");
    else
      printf("0");
  }

  printf("\n");

}
