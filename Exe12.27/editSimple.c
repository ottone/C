//
//  simple.c
//
//  Created by Francesco Parrucci on 19/08/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che realizza un file contentenente delle istruzioni in linguaggio semplice. Il programma deve presentare un menu di scelta in cui l'utente puo scegliere tra le seguenti opzioni:
//
//  1 - Creare un file in linguaggio semplice 
//  2 - Modificare un Record del file
//  3 - Eliminare un Record del file
//  4 - Stampare il file.
//
//  Per soddisfare i requisiti il programma si avvale delle seguenti funzioni: 
//  	
//  void createFile(void) :  É una funzione che permette di creare il file ad accesso casuale con un nome richiesto in seguito all'utente. Il file verrà aperto in scrittura quindi se l'utente fornisce un file già esistente questo 
//  verrà sovrascritto. La scrittura del file avverrà per mezzo della seguente struttura 
//
//  struct instruct {
//  	int line;
//  	char ist[20];
//   }; 
//
//  Una volta aperto il file in scrittura, si entra in un ciclo while nel quale l'utente potrà scegliere di terminare l'inserimento premendo la combinazione CTRL - D su sistemi unix EOF, o per mezzo di valore sentinella. La variabile
//  line sarà impostata automaticamente da un contatore progressivo, mentre il vettore di caratteri ist riporterà l'istruzione come da standard del linguaggio semplice.
//
//  void updateRecord(void) : Per consuetudine la funzione chiederà all'utente di immettere il nome del file e lo aprirà in scrittura aggiornamento. La funzione chiederà all'utente di immettere la linea dove apportare la modifica e 
//  dopo aver effettuato la ricerca , chiede che vanga inserta la nuova istruzione cosi da sostituire la precedente e chiudere il file.
//
//  void eliminateRecord(void) : Dopo aver chiesto nome file la funzione aprirà il file in scritturra aggiornamento. Verrà richiesta anche qua il numero di linea da modificare e una volta trovata la linea verrà posta uguale alla 
//  variabile di tipo intStruction di nome blank opportunamente settata a zero in modo da cancellare la stringa.
//
//  void stampa(char []) : La funzione stampa del file, è l'unica tra quattro che riceve come argomento un vettore di caratteri nel quale sarà memorizzato il listato in simpletron. Una che l'utente fornisca il nome del file e aperto
//  in lettura, la funzione lo scorrerà per mezzo di un ciclo while fine a termine del file e copierà ogni stringa nella vettore oltreche stamparla a video. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void createFile(void);
void addRecord(void);
void updateRecord(void);
void eliminateRecord();
void stampa(char []);

struct instruct{
	int line;
	char ist[30];
};

typedef struct instruct inStruction;

int main(){

	char string[300];

	createFile();
	//stampa(string);
	//updateRecord();
	stampa(string);
	//eliminateRecord();
	//stampa(string);
	addRecord();
	stampa(string);


return 0;
}
void createFile(void){

char name[20];
int i = 1;
FILE *ptr;
inStruction new;

printf("\nNome file? : ");
scanf("%s",name);
getchar();
if((ptr = fopen(name,"w")) == NULL){
	printf("\nImpossibile aprire il file in scrittura...\n");
}else{
	printf("\nEOF per terminare : ");
	new.line = i++;
	fgets(new.ist,30,stdin);
	while(!feof(stdin)){
	fwrite(&new,sizeof(inStruction),1,ptr);
	new.line = i++;
	printf("\nEOF per terminare : ");
	fgets(new.ist,30,stdin);
	}
	fclose(ptr);
}
clearerr(stdin);
}

void updateRecord(void){

char name[20];
int i = 1;
FILE *ptr;
inStruction old, new;

printf("\nNome file? : ");
scanf("%s",name);
getchar();
if((ptr = fopen(name,"r+")) == NULL){
	printf("\nImpossibile aprire il file in scrittura...\n");
}else{
	printf("\nInserisci il numero di linea : ");
	scanf("%d",&i);
	getchar();
	fseek(ptr,(i - 1) * sizeof(inStruction),SEEK_SET);
	fread(&old,sizeof(inStruction),1,ptr);
	if(old.line == 0){
		printf("\nLinea %d è vuota...\n",old.line);
	}else{
		printf("\nPrecedente valore : %s \n",old.ist);
		printf("\nImmettere il nuovo: ");
		new.line = old.line;
		fgets(new.ist,30,stdin);
		fseek(ptr,(i - 1) * sizeof(inStruction),SEEK_SET);
		fwrite(&new,sizeof(inStruction),1,ptr);
	}
	fclose(ptr);
}
clearerr(stdin);
}

void eliminateRecord(){


char name[20];
int i = 1;
FILE *ptr;
inStruction temp, blank = {0 , "\n\0"};

printf("\nNome file? : ");
scanf("%s",name);
getchar();
if((ptr = fopen(name,"r+")) == NULL){
	printf("\nImpossibile aprire il file in scrittura...\n");
}else{
	
	printf("\nInserisci il numero di linea : ");
	scanf("%d",&i);
	getchar();
	fseek(ptr,(i - 1) * sizeof(inStruction),SEEK_SET);
	fread(&temp,sizeof(inStruction),1,ptr);
	if(temp.line == 0)
		printf("\nIstruzione inesistente\n");
	else{
		blank.line = temp.line;
		fseek(ptr,(i - 1) * sizeof(inStruction),SEEK_SET);
		fwrite(&blank,sizeof(inStruction),1,ptr);
	}
	fclose(ptr);
}
clearerr(stdin);
}

void stampa(char string[]){

	char name[20];
	int i;
	FILE *ptr;
	inStruction temp;

	printf("\nNome file? : ");
	scanf("%s",name);

	if((ptr = fopen(name,"r")) == NULL){
		printf("\nImpossibile aprire il file in lettura...\n");
	}else{
		fread(&temp,sizeof(inStruction),1,ptr);
		while(!feof(ptr)){
			printf("%2d %s",temp.line, temp.ist);
			fread(&temp,sizeof(inStruction),1,ptr);
		}
	}
	clearerr(stdin);
}

void addRecord(void){

	char name[20];
	int i, last;
	FILE *ptr;
	inStruction temp;

	printf("\nNome file? : ");
	scanf("%s",name);
	getchar();
	if((ptr = fopen(name,"r")) == NULL){
		printf("\nImpossibile aprire il file in lettura...\n");
	}else{
		fread(&temp,sizeof(inStruction),1,ptr);
		while(!feof(ptr)){
			fread(&temp,sizeof(inStruction),1,ptr);
		}
		fclose(ptr);
		if((ptr = fopen(name,"ab")) == NULL)
			printf("\nImpossibile aprire il file in accodamento...\n");
		else{
			printf("\nUltima linea : %d",temp.line++);
			printf("\nInserire l'istruzione: ");
			fgets(temp.ist,30,stdin);
			//fseek(ptr,(temp.line - 1) * sizeof(inStruction),SEEK_SET);
			fwrite(&temp,sizeof(inStruction),1,ptr);
			fclose(ptr);
		}
	}
	clearerr(stdin);
}
