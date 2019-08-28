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
void stampa(void);
int menu(void);

struct instruct{
	int line;
	char ist[30];
};

typedef struct instruct inStruction;

/*int main(){

	char string[300];
	void (*f[5]) (void) = {createFile,addRecord,updateRecord,eliminateRecord,stampa};
	int c;
	
	do{
	c = menu();
	if(c >= 0 && c <= 4) (*f[c])();
	}while(c >= 0 && c <= 4);

return 0;
}*/

int menu(void){
int i;

do{
	printf("\t<--- MENU --->\n");
	printf("\t1) Per creare/sovrascrivere un file\n");
	printf("\t2) Per aggiungere un record alla fine del file\n");
	printf("\t3) Per aggiornare un record\n");
	printf("\t4) Per eliminare un record\n");
	printf("\t5) Stampa un file\n");
	printf("\t6) Esci\n");
	printf("\t<--- Inserisci : ");
	scanf("%d",&i);
	i -= 1;
}while(i < 0 || i > 5);

return i;
}


void createFile(void){

char name[20], *p;
int i = 1;
FILE *ptFILE;
inStruction new;

printf("\nNome file? : ");
scanf("%s",name);
getchar();
if((ptFILE = fopen(name,"w")) == NULL){
	printf("\nImpossibile aprire il file in scrittura...\n");
}else{
	printf("\nEOF per terminare : ");
	new.line = i++;
	fgets(new.ist,30,stdin);
	if((p = strchr(new.ist,'\n')) != NULL) *p = '\0';
	while(!feof(stdin)){
	fwrite(&new,sizeof(inStruction),1,ptFILE);
	new.line = i++;
	printf("\nEOF per terminare : ");
	fgets(new.ist,30,stdin);
	if((p = strchr(new.ist,'\n')) != NULL) *p = '\0';
	}
	fclose(ptFILE);
}
clearerr(stdin);
}

void updateRecord(void){

char name[20], *p;
int i = 1;
FILE *ptFILE;
inStruction old, new;

printf("\nNome file? : ");
scanf("%s",name);
getchar();
if((ptFILE = fopen(name,"r+")) == NULL){
	printf("\nImpossibile aprire il file in scrittura...\n");
}else{
	printf("\nInserisci il numero di linea : ");
	scanf("%d",&i);
	getchar();
	fseek(ptFILE,(i - 1) * sizeof(inStruction),SEEK_SET);
	fread(&old,sizeof(inStruction),1,ptFILE);
	if(old.line == 0){
		printf("\nLinea %d è vuota...\n",i);
	}else{
		printf("\nPrecedente valore : %s \n",old.ist);
		printf("\nImmettere il nuovo: ");
		new.line = old.line;
		fgets(new.ist,30,stdin);
		if((p = strchr(new.ist,'\n')) != NULL) *p = '\0';
		fseek(ptFILE,(i - 1) * sizeof(inStruction),SEEK_SET);
		fwrite(&new,sizeof(inStruction),1,ptFILE);
	}
	fclose(ptFILE);
}
clearerr(stdin);
}

void eliminateRecord(){


char name[20];
int i = 1;
FILE *ptFILE;
inStruction temp, blank = {0 , "\n\0"};

printf("\nNome file? : ");
scanf("%s",name);
getchar();
if((ptFILE = fopen(name,"r+")) == NULL){
	printf("\nImpossibile aprire il file in scrittura...\n");
}else{
	
	printf("\nInserisci il numero di linea : ");
	scanf("%d",&i);
	getchar();
	fseek(ptFILE,(i - 1) * sizeof(inStruction),SEEK_SET);
	fread(&temp,sizeof(inStruction),1,ptFILE);
	if(temp.line == 0)
		printf("\nIstruzione inesistente\n");
	else{
		blank.line = temp.line;
		fseek(ptFILE,(i - 1) * sizeof(inStruction),SEEK_SET);
		fwrite(&blank,sizeof(inStruction),1,ptFILE);
	}
	fclose(ptFILE);
}
clearerr(stdin);
}

void stampa(void){
	char name[20];
	int i;
	FILE *ptFILE;
	inStruction temp;

	printf("\nNome file? : ");
	scanf("%s",name);

	if((ptFILE = fopen(name,"r")) == NULL){
		printf("\nImpossibile aprire il file in lettura...\n");
	}else{
		fread(&temp,sizeof(inStruction),1,ptFILE);
		while(!feof(ptFILE)){
			printf("%2d %s\n",temp.line, temp.ist);
			fread(&temp,sizeof(inStruction),1,ptFILE);
		}
	}
	clearerr(stdin);
}

void addRecord(void){

	char name[20], *p;
	int i, last;
	FILE *ptFILE;
	inStruction temp;

	printf("\nNome file? : ");
	scanf("%s",name);
	getchar();
	if((ptFILE = fopen(name,"r")) == NULL){
		printf("\nImpossibile aprire il file in lettura...\n");
	}else{
		fread(&temp,sizeof(inStruction),1,ptFILE);
		while(!feof(ptFILE)){
			fread(&temp,sizeof(inStruction),1,ptFILE);
		}
		fclose(ptFILE);
		if((ptFILE = fopen(name,"ab")) == NULL)
			printf("\nImpossibile aprire il file in accodamento...\n");
		else{
			printf("\nUltima linea : %d",temp.line++);
			printf("\nInserire l'istruzione: ");
			fgets(temp.ist,30,stdin);
			if((p = strchr(temp.ist,'\n')) != NULL) *p = '\0';
			//fseek(ptFILE,(temp.line - 1) * sizeof(inStruction),SEEK_SET);
			fwrite(&temp,sizeof(inStruction),1,ptFILE);
			fclose(ptFILE);
		}
	}
	clearerr(stdin);
}
