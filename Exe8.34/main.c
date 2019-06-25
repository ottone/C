//
//  main.c
//  Exe8.34
//
//  Created by Francesco Parrucci on 14/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
//
//  (Analisi del testo) La disponibilità dei computer, con le loro capacità di manipolaizone delle stringhe, ha prodotto alcuni approcci piuttosto interessanti
//  per analizzare gli scritti dei grandi autori. Molta attenzione è stata concentrata sul sospetto che William Shakespeare non sia mai esistito.
//  Alcuni studiosi ritengono che ci siano valide dimostraizoni secondo le quali Christopher Marlowe avrebbe scritto in realtà i capolavori attribuiti a Shakespeare
//  I ricercatori hanno utilizzato i computer per trovare delle somiglianze negli scritti di questi due autori. Questo esercizio esaminerà tre metodi per analizzare
//  i testi con il computer.
//
//  a) Scrivete un programma che legga diverse righe di testo e visualizzi una tabella indicante il numero di occorrenze nel testo per ogni
//     lettera dell'alfabeto. Per esempio, la frase to "To be, or not to be: that is the question:" contiene una "a", due "b", nessuna "c" ecc.
//
//  b) Scrivete un programma che legga diverse righe di testo e visualizzi una tabella indicante il numero di parole formate da una sola lettera,
//     da due da tre ecc. che appaiono nel testo. Per esempio . la frase "Whether 'tis nobler in the mind to suffer contiene 
//     Lunghezza della parola		Occorrenze
//     1				0
//     2				2
//     3				2
//     4				2(inclusa 'tis)
//     5				0
//     6				2
//     7				1
//	
//  c) Scrivete un programma che legga diverse righe di testo e visualizzi una tabella indicante il numero di occorrenze nel testo di ogni parola diversa.
//     La prima versione del vostro programma dovrà includere le parole nella tabella sistemandole nell'ordine in cui queste compaiono nel testo. In seguito
//     provate una visualizzazione più interessante (e utile) in cui le parole siano ordinate alfabeticamente. Per esempio, le righe
//
//     To be, or not to be: that is the question:
//     Whether 'tis nobler in the mind to suffer
//
//     contengono la parola "to" tre volte, "be" due volte, "or" una, ecc.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 100

void alphaCount();
void wordLenght();
void wordCount();

void BubbleSort(char *a[], int l, int r);
void getStr(char *s);
int totChar(char *s, char *);

int main(){

	char string[1000] = {'\0'};
	
	int count, matrix[26] = { 0 };

	getStr(string);

	printf("\nConteggio parole premi INVIO quando pronto.");	
	getchar();

	printf("\n\nStringa immessa:\n\n");
	puts(string);
	
	//alphaCount(string);
	//wordLenght(string);
	wordCount(string);
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


int totChar(char *s, char *c){

char  *searchPtr;
int l = 0;
	
	searchPtr = strtok(s, c);
	l++;
	while(searchPtr != NULL){
		searchPtr = strtok(NULL,c);
		l++;
	}
	return l;
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

