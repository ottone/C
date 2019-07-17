//
//  main.c
//  Exe11.8
//
//  Created by Francesco Parrucci on 11/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Dopo aver scritto il programma dell'Esercizio 11.7, scrivete uno che crei alcuni dati di prova per controllare il programma dell'Esercizio 11.7. Usate i seguenti dati
//  di prova per controllare il programma dell'Esercizio 11.7. Usate i seguenti dati di conto:
//
//  File principale di 
//  Numero di conto		Nome			Saldo
//  100				Alan Jones		348.17
//  300				Mary Smith		27.19
//  500				Sam Sharp		0.00
//  700				Suzy Green		-14.22
//
//  File delle transazioni
//
//  Numero di Conto 		Importo in dollari
//  100				27.14
//  300				62.11
//  400				100.56
//  900				82.17
//
//  L'esercizio 11.3 ha chiesto al lettore di scrivere una serie di istruzioni distinte. In realtà, quelle istruzioni formano il nucleo di un importante tipo di 
//  programma per l'elaborazione dei file, ovverosia, un programma di file-matching (confronto di file). Nelle elaborazioni dei dati commerciali, è uso comune
//  avere diversi file in ogni sistema. In un sistema di gestione dei crediti, per esempio, c'è generalmente un file principale che contiene informazioni dettagliate
//  su ogni cliente, come il suo nome, l'indirizzo, il numero di telefono, gli insoluti, il limite di credito, le condizioni di sconto, le disposizioni contrattuali
//  e possibilmente un succinto riepilogo dei suoi recenti acquisti e pagamenti. Man mano che le transazioni verranno concluse (ovverosia, verranno effettuate delle 
//  vendite e arriveranno dei pagamenti nella corrispondenza), queste saranno immesse in un file. Alla fine di ogni periodo commerciale (un mese per alcune aziende,
//  una settimana per altre, un giorno in certi casi) il file delle transazioni (chiamato "trans.dat" nell'Esercizio 11.3) sarà confrontato con il file principale
//  (chiamato "oldmast.dat" nell'Esercizio 11.3), aggiornando così tutti i record di conto con gli ultimi acquisti e pagamenti. Dopo che i suddetti aggiornamenti 
//  saranno stati eseguiti, il file principale sarà riscritto in un nuovo archivio ("nuwmast.dat") che alla fine del successivo periodo commerciale, sarà usato per
//  ricominciare il processo di aggiornamento.
//  I programmi di file-maching devono affrontare alcuni problemi che non hanno riscontro in quelli che gestiscono degli archivi singoli. Per esempio, non sempre sarà
//  possibile riscontrare delle corrispondenze tra i record dei due file. Un cliente presente sul file principale potrebbe non aver effettuato alcun acquisto o 
//  pagamento nel periodo commerciale corrente e, di conseguenza, per questo cliente non esisterebbe nessun record nel file delle transazioni. Allo stesso modo, 
//  un cliente che abbia effettuato qualche acquisto o pagamento potrebbe essere appena giunto nella comunità, e l'azienda potrebbe non aver avuto l'opportunità 
//  di creare per lui un record principale.
//  Usate le istruzioni scritte nell'Esercizio 11.3 come base per scrivere un programma di file-maching per la contabilità del credito. In ognuno dei file, usate il
//  numero di conto come chiave del record per riscontrare le corrispondenze. Supponete che siano tutti file sequenziali con record immagazzinati in ordine crescente
//  di numero di conto.
//  Ogni volta che avrete riscontrato una corrispondenza (ovverosia, quando avrete trovato due record con lo stesso numero di conto sul file principale e su quello 
//  delle transazioni), dovrete aggiungere al saldo corrente del file principale l'ammontare in dollari rilevato dall'archivio delle transazioni e dovrete scrivere
//  il record di "newmast.dat". Considerate che gli acquisti saranno indicati sul file delle transazioni con importi positivi, mentre i pagamenti sarann indicati
//  con un ammontare negativo. Nel caso in cui per un certo conto troviate un record principale, ma nessuna corrispondenza nelle transazioni, dovrete semplicemente
//  scrivere il record principale in "newmast.dat". Nel caso in cui troviate un record di transazione, ma nessuna corrispondenza tra quelli principali, dovrete 
//  visualizzare il messaggio "Unmatched transaction record for account number _" (completare il messaggio, rilevando il numero di conto dal record di transazione.


//  Scrivete un'istruzione che apra in lettura il file "oldmast.dat" e assegni a ofPtr il puntatore ottenuto ofPtr = fopen("oldmast.dat","r");
//  Scrivete un'istruzione che apra in lettura il file "trans.dat" e assegni a tfPtr il puntatore ottenuto tfPtr = fopen("trans.dat","r");
//  Scrivete un'istruzione che apra in scrittura (e creazione) il file "newmast.dat" e assegni a nfPtr il puntatore ottenuto. nfPtr = fopen("newmast.dat","w");
//  Scrivete un'istruzione che che legga un record dal file "oldmast.dat". Il record sarà formato dall'intero accountNum dalla stringa name e dal valore in virgola
//  mobile currentBalance fscanf(ofPtr,"%d%s%f",&accountNum,name,&currentBalance);
//  Scrivete un'istruzione che legga un record dalfile "trans.dat". Il record sarà formato dall'intero accountNum e dal valore in virgola mobile dollarAmount 
//  fscanf(ofPtr,"%d%f",&accountNum,&dollarAmount);
//  Scrivete un'istruzione che rigistri un record nel file "newmast.dat". Il record sarà formato dall'intero accountNum dallsa stringa name e dal valore in virgola
//  mobile currentBalance fprintf(nfPtr,"%d%s%.2f",accountNum,name,currentBalance);


#include <stdio.h>
int menu(void);

void initialize(void);
void newRecord(void);
void newTransaction(void); 
void fileMatching(void);
void stampa(void);

struct clientData{
	int accountNum;
	char name[20];
	float currentBalance;
};

//typedef clientData cData;


int main(){

	
	void (*f[5]) (void) = {initialize,newRecord,newTransaction,fileMatching,stampa};
	int i;
	char c;
	do{
	i = menu();
	if(i >= 1 && i <= 5) (*f[i-1])();
	while(getchar() == '\0');	
	}while(i != 6);
	return 0;
}


int menu(void){
	int c;

	do{
	printf("\n1 - per inizializzare i file master e transazione");
	printf("\n2 - per aggiungere record al file master");
	printf("\n3 - per aggiungere transazioni");
	printf("\n4 - per il fileMatching");
	printf("\n5 - per la stampa di trans.dat");
	printf("\n6 - per uscire: ");
	scanf("%d",&c);
	}while(c < 1  || c > 6);

	return c;
}

void initialize(void){
	FILE *ofPtr, *tfPtr;

	if((ofPtr = fopen("oldmast.dat","w")) == NULL)
		printf("\nInizializzazione file oldmast.dat e trans.dat fallita\n");
	else
		fclose(ofPtr);
		
		
	if((tfPtr = fopen("trans.dat","w")) == NULL)
		printf("\nInizializzazione file trans.dat e trans.dat fallita\n");
	else
		fclose(tfPtr);

}

void newRecord(void){

	FILE *ofPtr;

	struct clientData client;

	if((ofPtr = fopen("oldmast.dat","a")) == NULL)
		printf("\nIl file oldmast.dat non può essere aperto\n");
	else{
			printf("\nInserire il Codice del Cliente il Nome e il Saldo: ");
			scanf("%d%s%f",&client.accountNum,client.name,&client.currentBalance);
			fprintf(ofPtr,"%d %s %+.2f\n", client.accountNum, client.name, client.currentBalance);
	}

		fclose(ofPtr);
		
}

void newTransaction(void){

	FILE *tfPtr;
	float balance;
	int num;
	
	if((tfPtr = fopen("trans.dat","a")) == NULL)
		printf("\nIl file trans.dat non può essere aperto\n");
	else{
		
			printf("\nInserire il Codice del Cliente e l'Operazione effettuata:  ");
			scanf("%d%f",&num,&balance);
			fprintf(tfPtr,"%d %+.2f\n", num, balance);
	    }

		fclose(tfPtr);
				
}

void fileMatching(void){

FILE *tfPtr, *ofPtr, *nfPtr;
struct clientData client;
int num, flag = 0;
float balance;


if(((tfPtr = fopen("trans.dat","r")) == NULL) || ((ofPtr = fopen("oldmast.dat","r")) == NULL) || ((nfPtr = fopen("newmast.dat","w")) == NULL))
	printf("\nErrore nell'apertura dei files\n");
else{	
	fscanf(ofPtr,"%d%s%f",&client.accountNum,client.name,&client.currentBalance);  // prendi un record da oldmast
	while(!feof(ofPtr)){  // finche non raggiungi la fine di oldmast esegui le istruzioni
	fscanf(tfPtr,"%d%f",&num,&balance);  // prendi un record da trans
		while(!feof(tfPtr)){   // finche non raggiungi la fine di trans esegui le istruzioni
			if(num == client.accountNum) client.currentBalance += balance; // se i numeri coincidono somma balance
			fscanf(tfPtr,"%d%f",&num,&balance);  // prendi un record da trans
		}
	rewind(tfPtr); // riavvolgi il puntatore di trans.dat e re inizia	
	fprintf(nfPtr,"%d %s %+.2f\n",client.accountNum,client.name, client.currentBalance);
	fscanf(ofPtr,"%d%s%f",&client.accountNum,client.name,&client.currentBalance);  // prendi un record da oldmast
	}

	rewind(ofPtr);
	rewind(tfPtr);

	fscanf(tfPtr,"%d%f",&num,&balance);  // prendi un record dal file delle transazioni
	while(!feof(tfPtr)){  // finche non raggiungi la fine del file delle transazioni esegui le istruzioni
	fscanf(ofPtr,"%d%s%f",&client.accountNum,client.name,&client.currentBalance);  // prendi un record da oldmast
		
		while(!feof(ofPtr)){   // finche non raggiungi la fine del file oldmast esegui le istruzioni
			if(num == client.accountNum) flag = 1;
			fscanf(ofPtr,"%d%s%f",&client.accountNum,client.name,&client.currentBalance);  // prendi un record da oldmast
		}
	if (flag == 0) printf("\nNessuna corrispondenza trovata per il record transazione %d",num);
	rewind(ofPtr); // riavvolgi il puntatore di trans.dat e re inizia	
	flag = 0;
	fscanf(tfPtr,"%d%f",&num,&balance);  // prendi un record da transi
	}

    fclose(ofPtr);
    fclose(tfPtr);
    fclose(nfPtr);

    if(((ofPtr = fopen("oldmast.dat","w")) == NULL) || ((nfPtr = fopen("newmast.dat","r")) == NULL))
	    printf("\nErrore nell'apertura dei file\n");
    else{
	    fscanf(nfPtr,"%d%s%f",&client.accountNum,client.name,&client.currentBalance);
    	    while(!feof(nfPtr)){
		fprintf(ofPtr,"%d %s %+.2f\n",client.accountNum,client.name,client.currentBalance);
		fscanf(nfPtr,"%d%s%f",&client.accountNum,client.name,&client.currentBalance);
	    }

	    fclose(nfPtr);
	    fclose(ofPtr);
    }
}
}
void stampa(void){
FILE *Ptr;
int num;
char c;
float balance;

if((Ptr = fopen("trans.dat","r")) == NULL)
	printf("\nErrore file non aperto");
else{

	fscanf(Ptr,"%d%f%c",&num,&balance,&c);
	while(!feof(Ptr)){
		printf("%d %+.2f %c",num,balance,c);	
		fscanf(Ptr,"%d%f%c",&num,&balance,&c);
	}
	
}
}
