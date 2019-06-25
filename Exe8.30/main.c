//
//  main.c
//  Exe8.30
//
//  Created by Francesco Parrucci on 11/06/19.
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
 *  Scrivete due versioni per ogniuna delle funzioni per la comparazione delle stringhe presentate nella Figura 8.20. La prima versione dovrà
 *  utilizzare gli indici di vettore, mentre la seconda versione dovrà utilizzare i puntatori e la relativa aritmetica.
 * 
 * int strcmp(char *s1, const char *s2) Confrontate le stringhe s1 e s2. La funzione restituirà 0, un valore minore di 0 o maggiore di 
 * 					      0 qualora s1 sia rispettivamente uguale , minore o maggiore di s2.
 *
 * int strncmp(char *s1, const char *s2, size_t n) Confronta un massimo di n caratteri di s1 con la stringa s2. La funzione restituirà 0
 * 							 , un valore minore di 0 o maggiore di 0 qualora s1 sia rispettivamente uguale, minore
 * 							 o maggiore di s2.
 *
*/

#include <stdlib.h>
#include <stdio.h>

char getChar(void);
char * geTs(char *);
void putChar(char);
void puTs(char *);

int strCmp(char  *s1, const char *s2);
int strNcmp(char *s1, const char *s2, size_t n);

#define size 50

int main(){

	char s1[size], s2[size],c;
	int i;

	//printf("\nInserire un carattere ");
	//c = getChar();
	//putChar(c);

 	printf("\nInserire una stringa: ");
	geTs(s1);

 	printf("\nInserire una Stringa: ");
	geTs(s2);

	printf("\nInserire il numro di caratteri da confrontare : ");
	scanf("%d",&i);

	printf("\nConfronto s1 vs s2: %d\n",strNcmp(s1,s2,i));

	return 0;
}


char getChar(void){
    
    char c;	
    scanf("%c",&c);

    return c;
}

char * geTs(char *s){
	char *p = s;

	while((*s = getChar() ) != '\n') s++;
	
	*s = '\0';
	s = p;
		
	return s;
}

void putChar(char c){
	printf("%c\n",c);
}

void puTs(char *s){
	printf("%s\n",s);
}

int strCmp(char  *s1, const char *s2){
	int i = 0;

	while((s1[i] == s2[i]) && s1[i] && s2[i]) i++;
		
	if(s1[i] == s2[i])
		return 0;
	else if(s1[i] > s2[i])
		return 1;
	else
		return -1;
}

int strNcmp(char *s1, const char *s2, size_t n){

	int l = sizeof(char) * n, i = 0;
	
	while((s1[i] == s2[i]) && s1[i] && s2[i] && l) {i++, l--;}
	
	
	if(s1[i] == s2[i])
		return 0;
	else if(s1[i] > s2[i])
		return 1;
	else
		return -1;
}
