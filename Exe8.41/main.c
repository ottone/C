//
//  main.c
//  Exe8.41
//
//  Created by Francesco Parrucci on 26/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  (Lettere di sollecito) Molte aziende commerciali spendono una gran quantità di tempo e di denaro per il recupero del credito. Il sollecito è appunto l'invio a un devitore di ripetute
//  e insistenti richieste, nel tentativo di incasare un credito.
//  Spesso i computer sono utlizzati per generare automaticamente le lettere di sollecito, con un grado crescente di severità man mano che il credito invecchia. La teoria alla vase di ciò
//  è che un credito diventa piu difficele da incassare man mano che invecchia e, di conseguenza, le lettere di sollecito devono diventare piu minacciose. 
//  Scrivete un programma C che contenga i testi di cinque lettere di sollecito con severità crescente. 
//  Il vostro programma dovrà accettare come input:
//
//  1 Il nome del debitore 
//  2 L'indirizzo del debitore 
//  3 Il conto del debitore 
//  4 La cifra dovuta 
//  5 L'età della cifra dovuta (ovverosia, un ritardo di un mese, di due mesi, ecc).
//
//  Utitlizzate l'età della cifra dovuta per selezionare uno dei cinque testi del messaggio e stampate la lettera di sollecito, inserendo in modo appropriato le altre informazioni fornite
//  dall'utente.
//
//  
//
//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20
void searchandreplace(char *,char *,char *);
void seandrep(char *,char *, char *);


int main(){
	
	char *lettere[3] =  {"Gentile NOME residente in INDIRIZZO in la invitiamo entro il termine di 10 giorni dalla ricezione della presente lettera di effettuare il pagamento della fattura dell' importo pari a CIFRA euro e già scaduta in quanto non ci risulta da lei saldata, vale a dire un importo totale di CIFRA €. La preghiamo a tal riguardo di normalizzare al più presto la sua posizione contabile, in particolare effettuando un bonifico alle coordinate IBAN CONTO oppure attraverso un assegno bancario.\n","############################################################################################################################################################","@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"};
	
	char buffer[1000];
	char nome[size] = {"Francesco PARRUCCI"};
	char indirizzo[size] = {"Via Gran Sasso, 3"};
	char conto[size] = {"12345678909999999"};
	char cifra[size] = {"1000,00"};
	char eta[5] = {"0"};
	char *p, *c, b1[1000],b2[1000];
	char e;
	int i;
	//printf("Nome del cliente: ");
	//gets(nome);

	//printf("Indirizzo del Cliente :");
	//gets(indirizzo);

	//printf("Cifra dovuta: ");
	//gets(cifra);

	//printf("Mesi di ritarto: ");
	//gets(eta);
	
	/*
	puts(buffer);
	p = strstr(buffer ,"giulio");	// trovo il puntatore a giulio nella stringa
	puts(p);			// stampo la stringa da giulio in poi
	i = strlen(buffer) - strlen(p); // calcolo l'offset da inizio a giulio
	memmove(b1,buffer,i);		// muovo su b1 l'offset della stringa
	b1[i]='\0';			// termino b1
	strcat(b1, nome);		// sposto in b1 la variabile che mi interessa
	memmove(&b1[strlen(b1)] ,p + strlen("giulio"),strlen(p));		
	puts(b1);
	*/
	strcpy(buffer,lettere[0]);
	/*
	searchandreplace(buffer,"NOME",nome);
	searchandreplace(buffer,"INDIRIZZO",indirizzo);
	searchandreplace(buffer,"CIFRA",cifra);
	searchandreplace(buffer,"CIFRA",cifra);
	searchandreplace(buffer,"CONTO",conto);
	*/
	
	seandrep(buffer,"NOME",nome);
	seandrep(buffer,"INDIRIZZO",indirizzo);
	seandrep(buffer,"CIFRA",cifra);
	seandrep(buffer,"CONTO",conto);
	puts(buffer);
	return 0;

}

void searchandreplace(char *string,char *search, char *replace){
	
	char b1[1000], *p;
	int i;

	//puts(string);
	p = strstr(string ,search);	// trovo il puntatore a giulio nella stringa
	//puts(p);			// stampo la stringa da giulio in poi
	i = strlen(string) - strlen(p); // calcolo l'offset da inizio a giulio
	memmove(b1,string,i);		// muovo su b1 l'offset della stringa
	b1[i]='\0';			// termino b1
	strcat(b1, replace);		// sposto in b1 la variabile che mi interessa
	memmove(&b1[strlen(b1)] ,p + strlen(search),strlen(p));
	strcpy(string,b1);		
	
}

void seandrep(char *string,char *search, char *replace){
	
	char b1[1000], *p;
	int i;
	b1[0] = '\0';

	p = strtok(string," ");
	strcmp(p,search) == 0 ? strcat(b1,replace) : strcat(b1,p);
	strcat(b1," ");
	while((p = strtok(NULL," ")) != NULL){
		strcmp(p,search) == 0 ? strcat(b1,replace) : strcat(b1,p);
		strcat(b1," ");}
	strcpy(string,b1);
}	
