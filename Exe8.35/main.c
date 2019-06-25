//
//  main.c
//  Exe8.35
//
//  Created by Francesco Parrucci on 16/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
//  (Elaborazione  dei testi) L'approfondimento dedicato alla manipolazione delle stringhe in questo libro è da attribuire in gran parte all'emozionante sviluppo
//  dell'elaborazione dei testi negli anni recenti. Una funzione importante per i sistemi di elaborazione testi è la giustificazione tipografica: l'allineamento 
//  l'allineamento delle parole al margine sinistro e a quello destro della pagina. La giustificazione tipografica genera un aspetto professionale del documento,
//  dando l'impressione che sia stato impostato in tipografia piuttosto che preparato su una macchina per scrivere. Sui computer la giustificazione tipografica 
//  può essere realizzata inserendo uno o più caratteri di spazio tra ognuna delle parole presenti in una riga, in modo che quella più a destra sia allineata con
//  il margine destro.
//  Scrivete un programma che legga diverse righe di testo e le visualizzi con una giustificazione tipografica. Supponete che il testo debba essere stampato su un 
//  foglio largo 8 pollici e mezzo (215,9 millimetri). Supponete anche che il computer stampi 10 caratteri per pollice. Di conseguenza, il vostro programma dovrà 
//  stampare 6 pollici e mezzo di testo (165,1 millimetri), ovverosia 65 caratteri per riga.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20

void alphaCount(char *);
void wordLenght(char *);
void wordCount(char *);

void giustify(char *);

void BubbleSort(char *[], int , int );
void getStr(char *);

int main(){

	char string[size * 50] = {'\0'};	

	getStr(string);

	printf("\n\nStringa immessa:\n\n");
	puts(string);
	
	giustify(string);

	//alphaCount(string);
	//wordLenght(string);
	//wordCount(string);
	return 0;
}


void getStr(char *s){

int n = 0, c;

	printf("\nInserisci un testo CTRL-D per terminare: \n");
	
	while((c = getchar()) != EOF){
		s[n++] = (char)c;
	}	
	s[n] = '\0';

	clearerr(stdin);
	
}



void alphaCount(char *string){   // conteggio delle occorrenze dei caratteri nella stringa
	int i = 0, Alpha[25] = {0};
	
	while(string[i] != '\0'){
		if((string[i] >= 97 && string[i] >= 122) || (string[i] >= 65 && string[i] >= 90))
			Alpha[(int)string[i] - 97]++;
	i++;
	}

	printf("\nOccorrenze caratteri :\n\n");
	for(i = 0; i < 26; i++) if(Alpha[i]) printf("Carattere %c/%c : Numero occorrenza : %d\n",i+65,i+97,Alpha[i]);
	printf("\n\n");
		

}

void wordLenght(char *string){ // conteggio delle parole di lunghezza diversa

	int i = 0, Length[100] = {0};
	char *p, buf[1000], space[100], *c;

	strcpy(buf,string);
	//puts(buf);
	//getchar();
	while((c = strchr(buf,'\n')) != NULL) *c = ' ';

	puts(buf);

	p = strtok(buf, " ");
	Length[strlen(p)]++;
	while((p=strtok(NULL," ")) != NULL)
		Length[strlen(p)]++;
printf("\nConteggio delle parole di diversa lunghezza :\n\n");
	for(i = 0; i < 100; i++) if(Length[i]) printf("Numero di parole di lunghezza %d : %d\n",i,Length[i]);
	printf("\n\n");
	
}

void wordCount(char *string){  // Numero di occorrenze delle parole diverse

	
	char  *p, *d[100]; 
	char buf[1000]; // buffer
	int  c = 0, i = 0, b = 0, count = 0; 

	for(i = 0 ; i < 100; i++)
		d[i] = NULL;

	strcpy(buf,string);
	puts("Pulizia dal carattere newline:");

	while((p = strchr(buf,'\n')) != NULL) *p = ' '; // pulizia del carattre newline
	
	printf("\nStringa ripulita da newline : %s",buf);
	getchar();

	
	p = strtok(buf," ");
	d[c++] = p;
	while((p=strtok(NULL," ")) != NULL) d[c++] = p;

	for(c = 0 ; c < 100; c++) if(d[c] != NULL )  if(d[c]!= NULL) {puts(d[c]) , i = c;}	

	// Ordinamento

	printf("\nvalore di i (estremo destro di bubble sort : %d\n",i);

	BubbleSort(d,0,i);
	
	
	for(c = 0, count = 0 ; c <= i;){
	   for(b = c, count = 0; b <= i; b++ )  if(strcmp(d[c],d[b]) == 0) count++; 
	
	printf("\nOccorrenze della stringa %s : %d",d[c],count);
	c += count;
	getchar();
	}
}

void BubbleSort(char *a[], int l, int r){
  
         int i, j; 
	 char *temp;
 
         for(i = l; i < r; i++)
                 for(j = r; j > i ; j--){
                         if(strcmp(a[j],a[j-1]) < 0){
                                 temp = a[j];
                                 a[j] = a[j-1];
                                 a[j-1] = temp;
                         }
                 }
}

void giustify(char *s){
 
	int i = 0 , c, len, l, r, line = 10;
	int sp, temp;
	char *p, buf[1000], *b;


	strcpy(buf, s);

	while((p = strchr(buf,'\n')) != NULL) *p = ' '; // pulizia del carattre newline

	puts(buf);
	
	len = strlen(buf);	
	i = 0;
	while(len - i >= 0){	
	
		l = i;
		getchar();

		if(len < line)
			r = l + len;
		else
			r = l + line;


		if(buf[r] == ' ') {
			buf[r] = '\n';
			sp = r + 1;
			while(buf[sp] == ' ') sp++;
			if(sp > r + 1){ 
				memmove(&buf[r+1],&buf[sp],strlen(buf));
				temp = len;
				len = temp - strlen(buf);
			}
		}else{
			while(buf[r] != ' ') 
				for(c = l; c < r; c++) 
					if(buf[c] == ' '){
				       	memmove(&buf[c+1],&buf[c],strlen(buf));
					while(buf[c] == ' ') c++;
				}
			buf[r] = '\n';
			sp = r + 1;
			while(buf[sp] == ' ') sp++;
			if(sp > r + 1){
				memmove(&buf[r+1],&buf[sp],strlen(buf));
				temp = len;
				len = temp - strlen(buf);
			}
		}
		
			i  = r + 1;
			
		
	}
	

	//memmove(&buf[5],&buf[4],strlen(buf));
	puts(buf);	
		
	

	
}
