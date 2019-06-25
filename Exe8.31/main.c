//
//  main.c
//  Exe8.31
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
 * Scrivete le vostre versioni delle funzioni di ricerca nelle stringhe presentate nella Figura 8.22
 *
 * char *strchr(const char *s, int c) Individua la prima occorrenza del carattere c nella stringa s. Qualora c sia stato trovato, sarà restituito
 * 				      un puntatore alla locazione di c in s. Altrimenti sarà restituito un puntatore NULL
 *
 * size_t strcspn(const char *s1, const char *s2)	Determina e restituisce la lunghezza del segmento iniziale della stringa s1 che non contenga
 * 							nessuno dei caratteri incluse in s2.
 *
 * size_t strspn(const char *s1, const char *s2)	Determina e restituisce la lunghezza del segmento iniziale della stringa s1 che contenga soltanto
 * 							i caratteri inlcusi in s2
 *
 * char *strpbrk(const char *s1, const char *s2)	Individua nella stringa s1 la prima occorrenza di uno qualsiasi dei caratteri inclusi in s2.Qualora
 * 							un carattere della stringa s2 sia stato ritrovato in s1, sarà restutuito un puntatore alla locazione
 * 							di quel carattere nella stringa s1. Altrimenti sarà resutuito un puntatore NULL.
 *
 * char *strrchr(const char *s, int c)			Individua l'ultima occorrenza di c nella stringa s. Qualora c sia stato ritrovato, sarà restituito un
 * 							puntatore alla locazione di c nella stringa s. In caso contrario sarà restutuito un puntatore a NULL.
 *
 * char *strstr(const char *s1, const char *s2)		Individua la prima occorrenza della stringa s2 in s1. Qualora la stringa sia stata ritrovata, sarà
 * 							restituito un puntatore alla locazione de s2 nella stringa s1. In caso contrario sarà restituito un
 * 							puntatore NULL.
 *
 * char *strtok(char *s1, const char *s2) 		Una sequenza di invocazioni di strtok suddividerà la stringa s1 in "token" (componenti logici come,
 * 							per esempio, le parole in una riga di testo) separati dai caratteri contenuti nella stringa s2. 
 *							La prima invocazione dovrà contenere s1 come primo argomento, mentre quelle susseguenti dovranno 
 *							contenere NULL, qualora si desideri continuare a suddividere la stessa stringa. Ogni invocazione 
 *							restituirà un puntatore al token corrente. Nel caso non ci fossero piu token la funzione restituirà
 *							un NULL. 
*/
#include <stdlib.h>
#include <stdio.h>

char getChar(void);
char * geTs(char *);
void putChar(char);
void puTs(char *);

int strCmp(char  *s1, const char *s2);
int strNcmp(char *s1, const char *s2, size_t n);

char * strChr(const char *s, int c);
int strCspn(const char *s1, const char *s2);
int strSpn(const char *s1, const char *s2);
char *strPbrk(const char *s1, const char *s2);
char *strRchr(const char *s, int c);
char *strStr(const char *s1, const char *s2);
void strTok(char *s1, const char s2);
#define size 50

int main(){

	char s1[size], s2[size],c;
	int i;

	//printf("\nInserire un carattere ");
	//c = getChar();
	//putChar(c);

 	printf("\nInserire una stringa: ");
	geTs(s1);

	strTok(s1,' ');

	strTok(NULL,' ');
 	//printf("\nInserire una Stringa: ");
	//geTs(s2);

	//printf("\nInserire il numro di caratteri da confrontare : ");
	//scanf("%d",&i);

	//printf("\nConfronto s1 vs s2: %d\n",strNcmp(s1,s2,i));

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

char * strChr(const char *s, int c){
	int i;

	while((s[i] != c) && s[i]) i++;

	if(s[i] == c)
		return &s[i];
	else
		return NULL;
}

int strCspn(const char *s1, const char *s2){
	int c, n;
	
	for(c = 0; s2[c] != '\0'; c++)
	   for(n = 0;s1[n] != '\0'; n++)
		   if(s2[c] == s1[n])
			   return c;

}

int strSpn(const char *s1, const char *s2){
	int c, n, count;

	for(c = 0,count = 0 ;(s2[c] != '\0') && count != 0; c++){
	   for(n = 0, count = 0;s1[n] != '\0'; n++)
		   if(s2[c] == s1[n])
			   count++;
	}

	return c;
}

char *strPbrk(const char *s1, const char *s2){
	int c, n, flag = 0;
	
	for(c = 0; s2[c] != '\0'; c++)
	   for(n = 0;s1[n] != '\0'; n++)
		   if(s2[c] == s1[n])
			   return &s1[c];
		  
	return NULL;
}

char *strRchr(const char *s, int c){
	int i = 0; 

	while(s[i] != '\0') i++;

	while(i > 0){ 
		if(s[i] == c) return &s[i];
		i--;}

	return NULL;
}

char *strStr(const char *s1, const char *s2){

	int i = 0, c = 0, d;

	for(i = 0, c = 0; s1[i] != '\0'; i++, c = 0){
		if(s1[i] == s2[c]) d = i;
		while((s1[d++] == s2[c++]) && s2[c] != '\0') ;
		if(s2[c] == '\0')
			break;
	}
		
		if(s2[c] == '\0')
			return &s1[i];
		else 
			return NULL;
}

void strTok(char *s1, const char s2){
    
	int c;
	char l[size];
	static char *t;

	if(s1 == NULL){
		if(t != NULL){
			
		for(c = 0; *t != s2 && *t != '\0';  c++,t++) l[c] = *t;

		l[c] = '\0';
		t = &t[c+1];
		puTs(l);
		}
	}else{
		for(t=s1, c = 0; *t != s2; c++,t++) l[c] = *t;

		l[c] = '\0';
		t = &s1[c+1];
		puTs(l);
	}

}
