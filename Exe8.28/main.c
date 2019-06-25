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
 * Scrivete due versioni di ognuna delle funzioni per la copia e la concatenazione delle stringhe presentate nella Figura 8.17
 * La prima versione dovrà utilizzare gli indici di vettore, mentre la seconda dovrà utilizzare i puntatori e la relativa aritmetica
 *
 * char *strcpy(char *s1, const char *s2) copia la stringa s2 nel vettore s1. Restituisce il valore di s1
 *
 * char *strncpy(char *s1, const char *s2, size_t n) Copia un massimo di n caratteri dalla stringa s2 nel vettore s1.
 *
 * char *strcat(char *s1, const char *s2) Accoda la stringa s2 al vettore s1. Il primo carattere di s2 si sostituisce al NULL di s1. Restituisce il valore di s1
 *
 * char *strncat(char *s1, const char *s2, size_t n) Accoda un massimo di n caratteri dalla stringa s2  al vettore s1. Il primo carattere di s2 si sostituisce
 * 						     al NULL di terminazione di s1. Restituisce il valore di s1.
 *
*/

#include <stdlib.h>
#include <stdio.h>

#define size 50

char *copystr(char *, const char *);
char *copynstr(char *, const char *, int );

int main(){

	char s1[size] , s2[size];
	int i;

 	printf("\nInserire una stringa: ");
	gets(s1);

 	printf("\nInserire una stringa: ");
	gets(s2);
	
	printf("\nNumero di caratteri da concatenare: ");
	scanf("%d",&i);

	copynstr(s1,s2,i);
	puts(s1);
			
	return 0;
}

char *copystr(char *s1, const char *s2){
	/*
	// copia della stringa utilizzando gli indici
	
	int i = 0;
	while( s1[i++] = s2[i++]) ;
	*/
	
	// copia della stringa utilizzando l'aritmetica dei puntatori
	char *s = s1;

	for (;*s1=*s2;s1++,s2++) ;
	
	s1 = s;
	return s1;
}

char *copynstr(char *s1, const char *s2, int n)
{
	int m = sizeof(char) * n;
	
	// copia della stringa utilizzando gli indici
	
	int i = 0, a = 0;

	while(s1[i]) i++; 
	

	while(m-- > 0)
		s1[i++] = s2[a++];  
	
	s1[++i] = '\0';
	/*	
	// copia della stringa utilizzando l'aritmetica dei puntatori

	char *s = s1;

	for (;*s1;s1++) ;
	
	for (; m > 0 ; m--, s1++, s2++)
		*s1 = *s2;
	s1++;
	*s1 = '\0';
	s1 = s;
	*/
	return s1;
}
