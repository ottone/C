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
//  (Scrivere in lettere l'importo di una assegno) Continuando la discussione dell'esempio precedente, ribadiamo quanto sia importante progettare dei sistemi per la 
//  compilaizone degli assegni che prevengano l'alterazione del loro importo. Un metodo di sicurezza comune richiede che l'importo dill'assegno sia scritto in cifre
//  e "dichiarato" anche in lettere. Qualcuno è in grado di alterare l'importo numerico di un assegno, ma è estremamente difficele cambiare l'importo espresso in 
//  lettere. Molti sistemi computerizzati per la compilazione degli assegni non stampano l'inmporto in lettere. Probabilmente, la causa principale di questa omissione
//  è che molti dei linguaggi di alto livello utilizzati nelle applicaizoni commerciali non contengono delle caratteristiche adeguate per la manipolaizone delle strighe.
//  Un'altra ragione è che la logica per scrivere in lettere gli importi degli assegni è alquanto complicata.
//  Scrivete un programma C che prenda in input l'ammontare numerico di un assegno e scriva il suo equivalente in lettere. Per esempio, l'importo 112.43 dobrebbe essere
//  scritto come 
//
//  ONE HUNDRED TWELVE and 43/100
//
//
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define size 9

int checkString(char *);
void formatStrig(char *);
void letterale(char *);

int main(){

	char string[size];	
	
	printf("Inserire l'importo in dollari es: 1.250,99 ");
	gets(string);
	while(!(checkString(string))) 
	gets(string);
	//formatString(string);
	letterale(string);
	
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
	
	//printf("\nValore di ritorno dopo primo ciclo while: %d\n",ret);
	//getchar();

	if(s[strlen(s)-3] != ',') ret = 0;
	//printf("\nValore di ritorno dopo seconda istruzione if : %d\n",ret);
	//getchar();

	p = strcspn(s,",\0") - 4;
	putchar(s[p]);
	while(p > 0) {
		if(s[p] != '.') 
			ret = 0; 
	p -= 4;}
	
	//printf("\nValore di ritorno dopo terzo ciclo while: %d\n",ret);
	//getchar();

	if(ret == 0){
		printf("\nValore immesso errato: %s\n",s);
		return 0;
	}else{
		printf("\nValore immesso corretto: %s\n",s);
		return 1;
	}
}


void formatString(char *s){

	int count  = 0, c = 0, i = 0;
	
	count = strlen(s);
	printf("\nValore di count : %d\n",count);
	if(count == size)   // 12.345,99
		;
	else{
		c = size - count;
		memmove(&s[c],s,count);
		while(i < c) s[i] = '*', i++;	
		s[size]  = '\0';
	}
	
		puts(s);

}


void letterale(char *s){
	
	char p[size] , *c = NULL;

	char *v[99] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE",
		       "SIX","SEVEN","EIGHT","NINE","TEN","ELEVEN",
		       "TWELVE","THIRTEEN","FOURTEEN","FIFTEEN",
		       "SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"};

	v[20] = "TWENTY";
	v[30] = "THERTY";
	v[40] = "FOURTY";
	v[50] = "FIFTY";
	v[60] = "SIXTY";
	v[70] = "SEVENTY";
	v[80] = "EIGHTY";
	v[90] = "NINETY";
	v[91] = "HUNDRED";
	v[92] = "THOUSAND";

	int  i, t = 0, h = 0;
	strcpy(p,s);
	puts(p);	
	
	
	if((c = strchr(p,'.')) != NULL){
		memmove(&p[c - p],&c[1],strlen(c));
		p[strlen(s)-1]='\0';
	}

	i = atoi(p);
	
	printf("\nValore da convertire: %d\n",i);
	getchar();

	if(i <= 19) 
		puts(v[i]);	
	else if(i >= 20 && i <= 99){
		printf("\n%s%s",v[(i/10) * 10],v[i%10]);
	}else if(i >= 100 && i < 1000){
		t = i % 100;
		printf("\n%s%s%s%s",v[i/100],v[91],v[(t/10)*10],v[t%10]);
	}else if(i >= 1000 && i < 9999){
		t = i % 1000;
		h = t % 100;
		printf("\n%s%s%s%s%s%s",v[i/1000],v[92],v[t/100],v[91],v[(h/10)*10],v[h%10]);
	}else if(i >= 10000 && i < 100000){
		t = i / 1000;
		h = i % 1000;
		if(t <= 19) printf("\n%s%s",v[t],v[92]);
		else printf("\n%s%s%s",v[(t/10)*10],v[t%10],v[92]);
		printf("%s%s",v[h/100],v[91]);
		t = h % 100;
		printf("%s%s",v[(t/10)*10],v[t%10]);
	}else
		puts("Too mach money!!!");

	c = strchr(p,',');
	printf(" and %s/100\n",c+1);
}
