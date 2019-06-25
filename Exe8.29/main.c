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
 *  Scrivete le vostre versioni delle funzioni getchar , gets , putchar e puts descritte nella Figura 8.12
 * 
 *
*/

#include <stdlib.h>
#include <stdio.h>

char getChar(void);
char * geTs(char *);
void putChar(char);
void puTs(char *);

#define size 50

int main(){

	char s1[size], c;
	int i;

	//printf("\nInserire un carattere ");
	//c = getChar();
	//putChar(c);

 	printf("\nInserire una stringa: ");
	geTs(s1);

 	printf("\nStringa inserita: ");
	puTs(s1);
	
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
