//
//  main.c
//  Exe6.33
//
//  Created by Francesco Parrucci on 09/03/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
(PALINDROMI) UN PALINDROMO E' UNA STRINGA CHE SI LEGGE ALLO STESSO MODO DA SINISTRA 
A DESTRA E DA DESTRA A SINISTRA. ALCUNI ESEMPI DI PALINDROMI SONO: "RADAR", "ABLE WAS 
I ERE I SAW ELBA" E "A MAN A PLAN A CANAL PANAMA". SCRIVETE UNA FUNZINE RICORSIVA 
testPalindrome CHE RESTITUISCA 1, QUALORA LA STRINGA IMMAGAZZINATA NEL VETTORE SIA UN
PALINDROMO, E 0 IN CASO CONTRARIO. LA FUNZIONE DOVRÀ IGNORARE GLI SPAZI E LA PUNTEGGIATURA
EVENTUALMENTE PRESENTI NELLA STRINGA.
*/


#include <stdio.h>
#define size 100

int testPalindrome(char a[size], int n, int m){
	
if(n == m || a[n] == a[m])
	return 1;
else if(!(a[n] >= 97 && a[n] <= 122))
	n + 1;
else if(!(a[m >= 65 && a[m] <= 90]))
	m - 1;
else if(a[n] != a[m])
	return 0;
else
	testPalindrome(a,n+1,m-1);
 
	
}

int length(char v[size]){
  
	int m = 0;

	while(v[m] != '\0')
		m++;	
	
	return m;
}

int main(){

int m = 0;
char v[size];

printf("\nImmetti una frase o parola:");
while(m < size - 1 && (v[m] = getchar()) != '\n' )
     m++;

v[m] = '\0';

printf("\nHai immesso la seguente: %s, ed è lunga %d\n",v,length(v));

printf("\nRisultato funzione testPalindrome: %d.\n",testPalindrome(v,0,length(v) - 1));

//printf("\nValore di a = %d, z = %d\n",'a','z');

//printf("\nValore di A = %d, Z = %d\n",'A','Z');

return 0;
}
