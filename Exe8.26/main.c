//
//  main.c
//  Exe8.26
//
//  Created by Francesco Parrucci on 07/06/19.
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
 *
 *
 * Usando come guida la tabella dei caratteri ASCII dell'Appendice D, scrivete le vostre versioni delle funzioni per la gestione dei caratteri presentate nella Fig 8.1
 *
 * int isdigit(int c)	Restituisce un valore vero se c è una cifra e 0 (falso) in caso contrario
 * int isAlpha(int c)   Restituisce un valore vero se c è una lettera e 0 in caso contrario 
 * int isAlnum(int c)   Restituisce un valore vero se c è una cifra o una lettera e 0 in caso contrario
 * int isXdigit(int c)  Restituisce un valore vero se c è una cifra esadecimale o 0 in caso contrario
 * int isLower(int c)   Restituisce un valore vero se c è una lettera minuscola e 0 in caso contrario
 * int isUpper(int c)	Restituisce un valore vero se c è una lettera maiuscola o 0 in caso contrario
 * int toLower(int c)	Restitiusce la lettera minuscola sorrispondente, se c è una lettera maiuscola, e l'argomento inalterato in caso contrario
 * int toUpper(int c) 	Restituisce la lettera maiuscola corrispondente, se c è una lettera maiuscola, e l'argomento inalterato in caso contrario
 * int ispace(int c)	Restituisce un valore vero, se c è un carattere di spazio bianco (newline('\n'), spazio (' '), salto pagina('\f'), ritorno
 * 			carrello ('\r'), tabulazione orizzontale ('\t') o tabulazione verticale ('\v')) e 0 in caso contrario
 * int isCntrl(int c)	Restituisce un valore vero se c è un carattere di controllo e 0 in caso contrario
 * int isPunct(int c)	Restituisce un valore vero se c è un carattere stampabile, diverso da uno spazio, una cifra o una lettera e 0 in caso contrario
 * int isPrint(int c)	Restituisce un valore vero se c è un carattere stampabile, incluso lo spazio (' '), e 0 in caso contrario
 * int isGraph(int c)	Restituisce un valore vero se c è un carattere stampabile, diverso dallo spazio ('') e 0 in caso contrario
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define size 1000
#define word 15

void getStr(char *s);
void recharge(char [][word]);
void BubbleSort(char [][word], int , int );
void ShellSort(char [][word], int, int );


int isDigit(int c);	// Restituisce un valore vero se c è una cifra e 0 (falso) in caso contrario
int isAlpha(int c);  	// Restituisce un valore vero se c è una lettera e 0 in caso contrario 
int isAlnum(int c); 	// Restituisce un valore vero se c è una cifra o una lettera e 0 in caso contrario
int isXdigit(int c);  	// Restituisce un valore vero se c è una cifra esadecimale o 0 in caso contrario
int isLower(int c);  	// Restituisce un valore vero se c è una lettera minuscola e 0 in caso contrario
int isUpper(int c);	// Restituisce un valore vero se c è una lettera maiuscola o 0 in caso contrario
int toLower(int c);	// Restitiusce la lettera minuscola sorrispondente, se c è una lettera maiuscola, e l'argomento inalterato in caso contrario
int toUpper(int c); 	// Restituisce la lettera maiuscola corrispondente, se c è una lettera maiuscola, e l'argomento inalterato in caso contrario
int isPace(int c);	// Restituisce un valore vero, se c è un carattere di spazio bianco (newline('\n'), spazio (' '), salto pagina('\f'), ritorno carrello ('\r'), tabulazione orizzontale ('\t') o tabulaz
			// ione verticale ('\v')) e 0 in caso contrario
int isCntrl(int c);	// Restituisce un valore vero se c è un carattere di controllo e 0 in caso contrario
int isPunct(int c);	// Restituisce un valore vero se c è un carattere stampabile, diverso da uno spazio, una cifra o una lettera e 0 in caso contrario
int isPrint(int c);	// Restituisce un valore vero se c è un carattere stampabile, incluso lo spazio (' '), e 0 in caso contrario
int isGraph(int c);	// Restituisce un valore vero se c è un carattere stampabile, diverso dallo spazio ('') e 0 in caso contrario


int main(){

	char s[size], *p, *c;
	int count;
 
	printf("%s\t\t%s\n%s%s\t\t\t%s%s\n%s%s\t\t%s%s\n\n", "According to isDigit: ","According to isdigit: ",
	isDigit('8') ? "8 is a " : "8 is not a ", "digit",isdigit('8') ? "8 is a ": "8 is not a ","digit", 
	isDigit('#') ? "# is a " : "# is not a ", "digit",isdigit('#') ? "# is a ": "8 is not a ","digit");

        printf("%s\t\t%s\n%s%s\t\t\t%s%s\n%s%s\t\t\t%s%s\n%s%s\t\t%s%s\n%s%s\t\t%s%s\n\n", "According to isAlpha: ","According to isalpha: ",
        isAlpha('A') ? "A is a " : "A is not a ", "letter", isalpha('A') ? "A is a " : "A is not a ", "letter",
        isAlpha('b') ? "b is a " : "b is not a ", "letter", isalpha('b') ? "b is a " : "b is not a ", "letter",
        isAlpha('&') ? "& is a " : "& is not a ", "letter", isalpha('&') ? "& is a " : "& is not a ", "letter",
        isAlpha('4') ? "4 is a " : "4 is not a ", "letter", isalpha('4') ? "4 is a " : "4 is not a ", "letter");
        
	printf("%s\t\t\t\t%s\n%s%s\t\t\t%s%s\n%s%s\t\t\t%s%s\n%s%s\t\t\t%s%s\n\n", "According to isAlnum: ","According to isalnum: ", 
        isAlnum('A') ? "A is a " : "A is not a ", "digit or a letter",isalnum('A') ? "A is a " : "A is not a ", "digit or a letter",
        isAlnum('8') ? "8 is a " : "8 is not a ", "digit or a letter",isalnum('8') ? "8 is a " : "8 is not a ", "digit or a letter",
        isAlnum('#') ? "# is a " : "# is not a ", "digit or a letter",isalnum('#') ? "# is a " : "# is not a ", "digit or a letter");
        
	printf("%s\t\t\t%s\n%s%s\t\t%s%s\n%s%s\t\t%s%s\n%s%s\t\t%s%s\n%s%s\t\t%s%s\n%s%s\t\t%s%s\n\n","According to isXdigit: ","According to isXdigit: ",
        isXdigit('F') ? "F is a " : "F is not a ", "hexadecimal digit",isxdigit('F') ? "F is a " : "F is not a ", "hexadecimal digit",
        isXdigit('J') ? "J is a " : "J is not a ", "hexadecimal digit",isxdigit('J') ? "J is a " : "J is not a ", "hexadecimal digit",
        isXdigit('7') ? "7 is a " : "7 is not a ", "hexadecimal digit",isxdigit('7') ? "7 is a " : "7 is not a ", "hexadecimal digit",
        isXdigit('$') ? "$ is a " : "$ is not a ", "hexadecimal digit",isxdigit('$') ? "$ is a " : "$ is not a ", "hexadecimal digit",
        isXdigit('f') ? "f is a " : "f is not a ", "hexadecimal digit",isxdigit('f') ? "f is a " : "f is not a ", "hexadecimal digit");	

	printf("%s\t\t\t%s\n%s%s\t\t\t%s%s\n%s%s\t\t%s%s\n%s%s\t\t%s%s\n%s%s\t\t%s%s\n\n","According to isLower: ", "According to islower: ",
        isLower('p') ? "p is a " : "p is not a ","lowercase letter",islower('p') ? "p is a " : "p is not a ","lowercase letter",
        isLower('P') ? "P is a " : "P is not a ","lowercase letter",islower('P') ? "P is a " : "P is not a ","lowercase letter",
        isLower('5') ? "5 is a " : "5 is not a ","lowercase letter",islower('5') ? "5 is a " : "5 is not a ","lowercase letter",
        isLower('!') ? "! is a " : "! is not a ","lowercase letter",islower('!') ? "! is a " : "! is not a ","lowercase letter");
	
	printf("%s\t\t\t%s\n%s%s\t\t%s%s\n%s%s\t\t%s%s\n%s%s\t\t%s%s\n%s%s\t\t%s%s\n\n","According to isUpper: ","According to isupper: ",
        isUpper('D') ? "D is an " : "D is not an ","uppercase letter",isupper('D') ? "D is an " : "D is not an ","uppercase letter",
        isUpper('d') ? "d is an " : "d is not an ","uppercase letter",isupper('d') ? "d is an " : "d is not an ","uppercase letter",
        isUpper('8') ? "8 is an " : "8 is not an ","uppercase letter",isupper('8') ? "8 is an " : "8 is not an ","uppercase letter",
        isUpper('$') ? "$ is an " : "$ is not an ","uppercase letter",isupper('$') ? "$ is an " : "$ is not an ","uppercase letter");

    	printf("%s%c\n%s%c\n%s%c\n%s%c\n\n","u converted to uppercase is ", toUpper('u'),"7 converted to uppercase is ", toUpper('7'),
	"$ converted to uppercase is ", toUpper('$'),"L converted to lowercase is ", toLower('L'));
	
 	printf("%s\t\t\t\t%s\n%s%s%s\t\t%s%s%s\n%s%s%s\t%s%s%s\n%s%s\t\t\t%s%s\n\n", "According to isPace: ","According to isspace", 
	"Newline", isPace('\n') ? " is a " : " is not a ","whitespace character", "Newline", isspace('\n') ? " is a " : " is not a ","whitespace character", 
	"Horizontal tab",isPace('\t') ? " is a " : " is not a ","whitespace character", "Horizontal tab",isspace('\t') ? " is a " : " is not a ","whitespace character", 
	isPace('%') ? "% is a " : "% is not a ", "whitespace character",isspace('%') ? "% is a " : "% is not a ", "whitespace character");

    	printf("%s\t\t\t%s\n%s%s%s\t%s%s%s\n%s%s\t\t%s%s\n\n", "According to isCntrl:","According to iscntrl: ",
	"Newline", isCntrl('\n') ? " is a " : " is not a ", "control character","Newline", iscntrl('\n') ? " is a " : " is not a ", "control character", 
	isCntrl('$') ? "$ is a " : "$ is not a ","control character",iscntrl('$') ? "$ is a " : "$ is not a ","control character");

	printf("%s\t\t\t%s\n%s%s\t\t%s%s\n%s%s\t%s%s\n%s%s\t\t%s%s\n\n", "According to isPunct:","According to ispunct: ",
	isPunct(';') ? "; is a " : "; is not a ","punctuation character", ispunct(';') ? "; is a " : "; is not a ","punctuation character", 
	isPunct('Y') ? "Y is a " : "Y is not a ","punctuation character", ispunct('Y') ? "Y is a " : "Y is not a ","punctuation character",
        isPunct('#') ? "# is a " : "# is not a ","punctuation character", ispunct('#') ? "# is a " : "# is not a ","punctuation character");
    
	printf("%s\t\t\t\t\t%s\n%s%s\t\t\t\t%s%s\n%s%s%s\t\t\t%s%s%s\n\n", "According to isPrint: ","According to isprint: ", 
	isPrint('$') ? "$ is a " : "$ is not a ", "printing character",isprint('$') ? "$ is a " : "$ is not a ", "printing character",
	"Alert", isPrint('\a') ? " is a " : " is not a ","printing character","Alert", isPrint('\a') ? " is a " : " is not a ","printing character");
    	
	printf("%s\t\t\t\t\t\t\t%s\n%s%s\t\t\t\t%s%s\n%s%s%s\t\t\t%s%s%s\n\n",  "According to isGraph:","According to isgraph: ",
	isGraph('Q') ? "Q is a " : "Q is not a ", "printing character other than a space", isgraph('Q') ? "Q is a " : "Q is not a ", "printing character other than a space",
        "Space", isGraph(' ') ? " is a " : " is not a ","printing character other than a space","Space", isgraph(' ') ? " is a " : " is not a ","printing character other than a space");

	
	return 0;
}


void getStr(char *s){

int n = 0, temp[word];	
int c;

	printf("\nInserisci un testo CTRL-D per terminare: \n");
	
	while((c = getchar()) != EOF){
		s[n++] = (char)c;
	}	
	s[n] = '\0';

	clearerr(stdin);
	
}


void recharge(char s[size][word]){

	int count;

	for(count = 0; count < 5 ; count++){
		printf("\nNome di città: ");
		gets(&s[count]);
	}

	//return 0;

}


void ShellSort(char  a[size][word], int l, int r){

	int i, j, h;
	char temp[15];


	for( h = 1 ; h <= (r-l)/9; h = 3*h+1) ;
	for( ; h > 0 ; h / 3)
		for(i = 1 + h; i <= r; i++){ 
		   j = i;	
		   strcpy(temp,a[i]);
	   	   while( j >=  1+h && strcmp(temp,a[j-h]))
			{ strcpy(a[j],a[j-h]) ; j -= h;}
		   strcpy(a[j],temp);
		}	   

}

	
	
int isDigit(int c)	// Restituisce un valore vero se c è una cifra e 0 (falso) in caso contrario
{
	if(c >= 48 && c <= 57)
		return 1;
	else
		return 0;

}

int isAlpha(int c)   	// Restituisce un valore vero se c è una lettera e 0 in caso contrario 
{
	if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return 1;
	else
		return 0;

}

int isAlnum(int c)   	// Restituisce un valore vero se c è una cifra o una lettera e 0 in caso contrario
{
	if(isAlpha(c) || isDigit(c))
		return 1;
	else
		return 0;
}

int isXdigit(int c)  	// Restituisce un valore vero se c è una cifra esadecimale o 0 in caso contrario
{

	if(isDigit(c) || (c >= 65 && c <= 70) || (c >= 97 && c <= 102))
		return 1;
	else 	
		return 0;
}

int isLower(int c)   	// Restituisce un valore vero se c è una lettera minuscola e 0 in caso contrario
{
	if(c >= 97 && c <= 122)
		return 1;
	else 
		return 0;
}

int isUpper(int c)	// Restituisce un valore vero se c è una lettera maiuscola o 0 in caso contrario
{
	if(c >= 65 && c <= 90)
		return 1;
	else
		return 0;
}

int toLower(int c)	// Restitiusce la lettera minuscola sorrispondente, se c è una lettera maiuscola, e l'argomento inalterato in caso contrario
{
	if(c >= 65 && c <= 90){
		c += 32;
		return c;
	}else
		return 0;
}

	
int toUpper(int c) 	// Restituisce la lettera maiuscola corrispondente, se c è una lettera maiuscola, e l'argomento inalterato in caso contrario
{
	if(c >= 97 && c <= 122){
		c -= 32;
		return c;
	}else
		return 0;
}

int isPace(int c)	// Restituisce un valore vero, se c è (newline('\n'), spazio (' '), salto pagina('\f'), ritorno carrello ('\r'), tabulazione orizzontale/verticale ('\t')/('\v')) e 0 in caso contrario
{
	if( c == '\n' || c == ' ' || c == '\f' || c == '\r' || c == '\t' || c == '\v')
		return 1;
	else
		return 0;
}

int isCntrl(int c)	// Restituisce un valore vero se c è un carattere di controllo e 0 in caso contrario
{
	if(isAlpha(c) == 0 && isDigit(c) == 0 && isPace(c) == 0)
		return 1;
	else 
		return 0;
}

int isPunct(int c)	// Restituisce un valore vero se c è un carattere stampabile, diverso da uno spazio, una cifra o una lettera e 0 in caso contrario
{
	if((c >= 33 && c <= 47) || (c >= 123 && c <= 126) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96))
		return 1;
	else
		return 0;
}

int isPrint(int c)	// Restituisce un valore vero se c è un carattere stampabile, incluso lo spazio (' '), e 0 in caso contrario
{
	if(isPunct(c) || isAlpha(c) || isDigit(c) || c == ' ')
		return 1;
	else	
		return 0;
}

int isGraph(int c)	// Restituisce un valore vero se c è un carattere stampabile, diverso dallo spazio ('') e 0 in caso contrario
{
	if(isPrint(c) && c != ' ')
		return 1;
	else
		return 0;
}
