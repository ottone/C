//
//  main.c
//  Exe8.37
//
//  Created by Francesco Parrucci on 19/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  (Protezione degli assegni) Molto spesso i computer sono impiegati in sistemi per la compilazione delgi assegni, come le applicaizoni per la gestione delgi stipendi
//  e per la contabilità del debito. Circolano molte strane storie secondo le quali sarebbero stati stampati (erroneamente) degli assegni per la paga settimanale con
//  cifre che superino il milione di dollari. Quelle strane cifre sono stampate dai sistemi computerizzati per la compilazione degli assegni solo a causa di errori umani
//  e/o di deterioramenti della macchina. I progettisti dei sistemi, naturalmente, fanno tutto il possibile per implementare nei propri sistemi dei controlli che 
//  prevengono l'emissione di assegni sbagliati.
//  Un altro grave problema è l'alterazione intenzionale dell'importo di un assegno da parte di qualcuno che intenda incassarlo in modo fraudolento. La maggior parte 
//  dei sistemi computerizzati per la compilaizone degli assegni impiegano una tecnica chiamata proteizone degli assegni, proprio per prevenire l'alterazione dei loro 
//  importi.
//  Gli assegni progettati per la compilazione da parte dei computer contengono un numero fisso di spazi in cui il computer può stampare l'importo. Supponete che l'assegno
//  di uno stipendio contenga otto spazi bianchi nei quali si suppone che il computer debba stampare l'ammontare di una paga settimanale. Nel caso che l'importo sia 
//  sostanizoso, allora saranno riempiti tutti gli otto spazi. Per esempio: 
//
//  1,230.60 (ammontare dell'assegno in dollari)
//  _ _ _ _ _  
//
//  12345678 (numeri di posizione)
//
//  Invece nel caso che la cifra sia inferiore ai $1000 allora molti degli spazi sarebbero lasciati in bianco. Per esempio
//
//     99.87
//  _ _ _ _ _
//
//  12345678
//
//  contiene tre spazi bianchi. Sarebbe sicuramente piu facile altereare l'importo dell'assegno, qualora questo fosse stato stampatp  con degli spazi bianchi. 
//  Per prevenire l'alteraizone di un assegno, molti sistemi per la loro compilaizone insericono degli asterischi iniziali in modo da proteggere l'importo 
//  come nell'esempio che segue:
//
//  ***99.87
//
//  - - - - -
//
//  12345678
//
//  Scrivete un programma che prenda in input l'importo in dollari che dovrà essere stampato su un assegno e lo visualizzi nel formato protetto dagli asterischi iniziali
//  , qualora siano necessari. Supponete che per stampare l'importo siano disponibili nove spazi.
//
//
//
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define size 9
int checkString(char *);

int main(){

	char string[size];	
	int count  = 0, c = 0, i = 0;
	
	printf("Inserire l'importo in dollari es: 1.250,99 ");
	
	gets(string);
	while(!(checkString(string))) 
	gets(string);

	count = strlen(string);
	printf("\nValore di count : %d\n",count);
	if(count == size)   // 12.345,99
		;
	else{
		c = size - count;
		memmove(&string[c],string,count);
		while(i < c) string[i] = '*', i++;	
		string[size]  = '\0';
	}
	
		puts(string);
	
	
	return 0;
}

int checkString(char *s){
	int count = 0 , ret = 1, p= 0;
	
	while(s[count] != '\0'){
			if(isdigit(s[count]) || s[count] == '.' ||  s[count] == ',') 
				;
			else
				ret = 0;
	count++;
	}
	
	printf("\nValore di ritorno dopo primo ciclo while: %d\n",ret);
	getchar();

	if(s[strlen(s)-3] != ',') ret = 0;
	printf("\nValore di ritorno dopo seconda istruzione if : %d\n",ret);
	getchar();

	p = strcspn(s,",\0") - 4;
	putchar(s[p]);
	while(p > 0) {
		if(s[p] != '.') 
			ret = 0; 
	p -= 4;}
	
	printf("\nValore di ritorno dopo terzo ciclo while: %d\n",ret);
	getchar();

	if(ret == 0){
		printf("\nValore immesso errato: %s\n",s);
		return 0;
	}else{
		printf("\nValore immesso corretto: %s\n",s);
		return 1;
	}
}
