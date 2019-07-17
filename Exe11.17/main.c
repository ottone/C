//
//  main.c
//  Exe11.17
//
//  Created by Francesco Parrucci on 16/07/19.
//  Copyright © 219 Francesco Parrucci. All rights reserved.
//
//  Nell'Esercizio 7.19, avete scritto una simulaizone software di un computer che usa uno speciale linguaggio macchina, chiamato Linguaggio Macchina Simpletron (LMS). 
//  Ogni volta che volete eseguire un programma LMS, dovete digitare da tastiera il codice per immetterlo nel simulatore. Se vi capitasse di commettere un errore durante
//  la digitazione del programma LMS, dovreste far ripartire il simulatore e digitare nuovamente il codice LMS. Non sarebbe bello poter leggere il programma LMS da un
//  file, piuttosto che digitarlo ogni volta? Ciò ridurrebbe il tempo e gli errori durante la fase di preparazione per l'esecuzione di un programma LMS.
//
//  a) Modificate il sumulatore che avete scritto nell'Esercizio 7.19, in modo che legga i programmi LMS da un file specificato tramite tastiera dall'utente.
//  
//  b) Al termine della sua esecuzione, il Simpletron avrà visualizzato sullo schermo il contenuto dei propri registri e della memoria. Sarebbe sicuramente bello poter
//  catturare l'output in un file, perciò lmodificate il sumulaore in modo che scriva il suo output in un file, oltre che sullo schermo.
//
/*
(PROGRAMMAIZONE IN LINGUAGGIO MACCHINA) CREEREMO ORA UN COMPUTER CHE CHIAMEREMO SIMPLETRON. COME IL SUO NOME LASCIA INTENDERE 
SI TRATTA DI UNA MACCHINA SEMPLICE, MA COME VEDREMO PRESTO ANCHE POTENTE. IL SIMPLETRON ESEGUIRÀ DEI PROGRAMMI SCRITTI NELL'
UNICO LINGUAGGIO CHE SIA IN GRADO DI COMPRENDERE DIRETTAMENTE, VALE A DIRE IL LINGUAGGIO MACCHINA SIMPLETRON, CHE ABBREVIAMO
IN LMS. IL SIMPLETRON CONTIENE UN ACCUMULATORE UN "REGISTRO SPECIALE" IN CUI SARANNO INSERITE TUTTE LE INFORMAZIONI. PRIMA
CHE IL SIMPLETRON POSSA UTILIZZARLE PER I CALCOLI O PER ESAMINARLE IN VARI MODI. TUTTE LE INFORMAIZONI SARANNO MANIPOLATE 
ALL'INTERNO DEL SIMPLETRON COME PAROLE. UNA PAROLA È UN NUMERO DECIMALE DI QUATTRO CIFRE CON SEGNO, COME +3364, -1293, +0007,
-0001, ECC. IL SIMPLETRON È EQUIPAGGIATO CON UNA MEMORIA DI 100 PAROLE ALLE QUALI FAREMO RIRERIMENTO ATTRAVERSO I LORO NUMERI
DI LOCAIZONE 00, 01, ....90.
PRIMA DI POTER ESEGUIRE UN PROGRAMMA LMS DOVREMO CARICARLO O IMMETTENDO NELLA MEMORIA. LA PRIMA ISTRUZIONE (O COMANDO) DI OGNI
PROGRAMMA LMS SARÀ SEMPRE CARICATA NELLA POSIZIONE 00.
OGNI ISTRUZIONE SCRITTA IN LMS OCCUPERÀ UNA PAROLA NELLA MEMORIA DEL SIMPLETRON E DI CONSEGUENZA , CORRISPONDERÀ, A UN NUMERO
DECIMALE DI QUATTRO CIFRE CON SEGNO. OVVIAMENTE IL SEGNO DI OGNI ISTRUZIONE LMS SARÀ SEMPRE QUELLO POSITIVO, MENTRE QUELLI DELLE
PAROLE CHE CONTENGONO DEI DATI POTRANNO ESSERE POSITIVI O NEGATIVI. OGNI LOCAZIONE DELLA MEMORIA DEL SIMPLETRON POTRÀ CONTENERE 
UN'ISTRUZIONE, IL VALORE DI UN DATO UTILIZZATO DAL PROGRAMMA, OPPURE UN'AREA DI MEMORIA INUTILIZZATA (E QUINDI INDEFINITA). LE 
PRIME DUE CIFRE DI OGNI ISTRUIZONE LMS CORRISPONDERANNO AL CODICE DELL'OPERAZIONE CHE DOVRÀ ESSERE ESEGUITA. I CODICI DELLE 
OPERAZIONI LMS SONO RIASSUNTI NELLA FIGURA 7.31
------------------------------------------------------------------------------------------------------------------------------
CODICE DELL'OPERAIZONE				SIGNIFICATO
------------------------------------------------------------------------------------------------------------------------------
OPERAZIONE DI INPUT / OUTPUT :

#DEFINE READ 10					LEGGE UNA PAROLA DAL TERMINALE E LA IMMAGAZZINA IN UNA SPECIFICA LOCAIONE DI
						MEMORIA.

#DEFINE WRITE 11				SCRIVE SUL TERMINALE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAIZONE DI MEMORIA.

OPERAZIONI DI CARICAMENTO / IMMAGAZZINAMENTO :

#DEFINE LOAD 20 				CARICA NELL'ACCUMULATORE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA.

#DEFINE STORE 21				ARCHIVIA IL CONTENUTO DELL'ACCUMULATORE IN UNA SPECIFICA LOCAZIONE DI MEMORIA.

OPERAZIONI ARITMETICHE:

#DEFINE ADD 30					AGGIUNGE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAIZONE DI MEMORIA A QUELLA CONTENUTA
						NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)

#DEFINE SUBTRACT 31				SOTTRAE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA DA QUELLA CONTENUTA
						NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)

#DEFINE DIVIDE 32				DIVIDE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA PER QUELLA CONTENUTA 
						NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)

#DEFINE MULTIPLY 33				MOLTIPLICA LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAIZONE DI MEMORIA PER QUELLA CONTENUTA
						NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO).

OPERAZIONI DI TRASFERIMENTO DEL CONTROLLO:

#DEFINE BRANCH 40 				SALTA A UNA SPECIFICA LOCAZIONE DI MEMORIA

#DEFINE BRANCHNEG 41				SALTA A UNA SPECIFICA LOCAIZONE DI MEMORIA, SE L'ACCUMULATORE UN VALORE NEGATIVO.

#DEFINE BRANCHZERO 42				SALTA A UNA SPECIFICA LOCAIZONE DI MEMORIA, SE L'ACCUMULATORE CONTIENE UN VALORE UGUALE A ZERO.

#DEFINE HALT 43					FERMA L'ESECUZIONE DEL PROGRAMMA
--------------------------------------------------------------------------------------------------------------------------------------------

C) LEGGETE UNA SERIE DI NUMERI E DETERMINATE E VISUALIZZATE QUELLO MAGGIORE. IL PRIMO NUMERO LETTO INDICHERÀ QUANTI VALORI DOVRANNO ESSERE 
   ELABORATI.


7.19

(SIMULATORE DI COMPUTER) POTRÀ SEMBRARE ESAGERATO, MA CON QUESTO ESERCIZIO COSTRUIRETE IL VOSTRO COMPUTER. NO, NON DOVRETE SALDARE DEI COMPONENTI.
UTILIZZERETE PIUTTOSTO LA POTENTE TECNICA DELLA SIMULAZIONE SOFTWARE PER CREARE UN MODELLO SOTWARE DEL SIMPLETRON. NON RIMARRETE DELUSI. IL VOSTRO
SIMULATORE SIMPLETRON TRASFORMERÀ IL COMPUTER CHE STATE UTILIZZANDO IN UN SIMPLETRON E SARETE EFFETTIVAMENTE IN GRADO DI ESEGUIRE, PROVARE E METTERE
A PUNTO I PROGRAMMI LMS CHE AVETE SCRITTO NELL'ESERCIZIO 7.18.

NEL MOMENTO IN CUI ESEGUIRETE IL VOSTRO SIMULATORE SIMPLETRON QUESTO DOVRÀ INCOMINCIARE VISUALIZZANDO:

	*** Welcome to Simpletron! ***

*** Please enter your program one instruction ***
*** (or data word) at a time. I will type the ***
*** location number and a question mark (?).  ***
*** You then type the word for that location. ***
*** Type the sentinel -99999 to stop entering ***
	     
             *** your program. ***

SIMULATE LA MEMORIA DEL SIMPLETRON CON IL VETTORE UNIDIMENSIONALE MEMORY DI 100 ELEMENTI. SUPPONETE CHE IL SIMULATORE SIA GIÀ IN ESECUZIONE ED 
ESAMINIAMO IL DIALOGO CHE SI SVILUPPERÀ CON ESSO, MAN MANO CHE IMMETTIAMO IL PROGRAMMA MOSTRATO NELL'ESEMPIO 2  DELL'ESERCIZIO 7.18:

00 ? +1009
01 ? +1010
02 ? +2009
03 ? +3110
04 ? +4107
05 ? +1109
06 ? +4300
07 ? +1110
08 ? +4300
09 ? +0000
10 ? +0000
11 ? -99999

*** Program loading completed ***
*** Program execution begins  ***

ORA CHE IL PROGRAMMA LMS È STATO IMMESSO (O CARICATO) NEL VETTORE MEMORY, IL SIMPLETRON PROVVEDERÀ A ESEGUIRLO. L'ESECUZIONE COMINCIERÀ CON 
L'ISTRUZIONE NELLA LOCAIZONE 00 E, COME IN C, CONTINUERÀ IN MODO SEQUENZIALE, SEMPRE CHE NON SI DIRAMI IN QUALCHE ALTRA PARTE DEL PROGRAMMA 
A CAUSA DI UN TRASFERIMENTO DI CONTROLLO.

UTILIZZATE LA VARIABILE ACCUMULATOR PER RAPPRESENTARE IL REGISTRO ACCUMULATORE. USATE LA VARIABILE INSTRUCTIONCOUNTER PER CONSERVARE L'INDIRIZZO
DI MEMORIA IN CUI SARÀ CONTENUTA L'ISTRUIZONE DA ESEGUIRE. UTILIZZATE LA VARIABILE OPERATIONCODE PER INDICARE L'OPERAZIONE DA ESEGUIRE, OVVEROSIA
LE DUE CIFRE A SINISTRA NELLA PAROLA DELL'ISTRUZIONE. USATE LA VARIABILE OPERAND PER INDICARE LA LOCAZIONE DI MEMORIA SU CUI OPERERÀ L'ISTRUIZONE
DA ESEGUIRE. IN ALTRI TERMINI OPERAND CORRISPONDERÀ ALLE DUE CIFRE PIÙ A DESTRA DELL'ISTRUZIONE DA ESEGUIRE. NON ESEGUITE DIRETTAMENTE LE ISTRUZIONI
CONTENUTE NELLA MEMORIA. TRASFERITE PIUTTOSTO QUELLA DA ESEGUIRE DALLA MEMORIA IN UNA VARIABILE CHIAMATA INSTRUCIONREGISTER. 
IN SEGUITO "STACCHERETE" LE DUE CIFRE DI SINISTRA PER SISTEMARE IN OPERATIONCODE E "SEPARETE" LE DUE CIFRE DI DESTRA PER SISTEMARLE IN OPERAND.
NEL MOMENTO IN CUI IL SIMPLETRON COMINCIERÀ L'ESECUZIONE I REGISTRI SPECIALI SARANNO DUNQUE INIZIALIZZATI NEL MODO SEGUENTE: 

ACCUMULATOR 			+0000
INSTRUCTIONCOUNTER		   00
INSTRUCTIONREGISTER		+0000
OPERATIONCODE			   00
OPERAND				   00


ORA "SEGUIAMO" L'ESECUZIONE DELLA PRIMA ISTRUZIONE LMS: IL +1009 SISTEMATO NELLA LOCAZIONE DI MEMORIA 00. QUELLO CHE SEGUIREMO È DETTO CICLO DI ESECUZIONE
DELL'ISTRUZIONE.
LA VARIABILE INSTRUCTIONCOUNTER CI INDICA LA LOCAZIONE DELLA PROSSIMA ISTRUZIONE DA ESEGUIRE.
"PRELEVEREMO" DUNQUE IL CONTENUTO DI QUELLA POSIZIONE DAL VETTORE MEMORY USANDO L'ISTRUZIONE C: 

		instructionRegister = memory[instructionCounter];

IL CODICE DELL'OPERAZIONE E L'OPERANDO SARANNO ESTRATTI DAL REGISTRO DELLE ISTRUZIONI CON: 

		operationCode = instructionRegister / 100;
		operand = instructionRegister % 100;
	
ORA IL SIMPLETRON È IN GRADO DI DETERMINARE CHE IL CODICE DELL'OPERAIOZNE CORRISPONDE IN REALTÀ È UNA READ (E NON UNA WRITE, O UNA LOAD, ECC.). UNA STRUTTURA 
SWITCH DISTINGUERÀ LE DODICI OPERAIZONI DEL LINGUAGGIO LMS.

ALL'INTERNO DELLA STRUTTURA SWITCH IL COMPORTAMENTO DELLE VARIE ISTRUIZIONI SARÀ SIMULATO NEL MODO SEGUENTE (LASCIAMO A VOI LE ALTRE ISTRUZIONI):

		read: scanf("%d", &memory[operand]);
		load: accumulator = memory[operand];
		add:  accumulator += memory[operand];

		VARIE ISTRUZIONI DI SALTO NE DISCUTEREMO A BREVE.

		halt: QUESTA ISTRUZIONE VISUALIZZA IL MESSAGGIO 
		*** Simpletron execution terminated ***

E IN SEGUITO VISUALIZZERÀ IL NOME E IL CONTENUTO DI TUTTI I REGISTRI, COSÌ COME QUELLO DI TUTTA LA MEMORIA. UN OUTPUT DI QUESTO GENERE È SPESSO CHIAMATO 
DUMP DEL COMPUTER (OVVEROSIA DEPOSITO DEL COMPUTER, CHE NON È PERÒ IL POSTO DOVE VANNO A FINIRE I VECCHI COMPUTER). PER AIUTARVI A IMPLEMENTARE LA VOSTRA
FUNZIONE DI DUMP NELLA FIGURA 7.32 ABBIAMO RIPORTATO UN ESEMPIO PER IL FORMATO DEL DUMP. OSSERVATE CHE UN DUMP ESEGUITO ALLA FINE DELL'ESECUZIONE DI UN 
PROGRAMMA SIMPLETRON DOVREBBE MOSTRARE I VALORI CORRENTI DELLE ISTRUZIONI E DEI DATI, COSÌ COME SONO IN QUEL MOMENTO.
PROCEDIAMO CON L'ESECUZIONE DELLA PRIMA ISTRUIZONE DEL NOSTRO PROGRAMMA, VALE A DIRE LA +1009 DELLA POSIZIONE 00. COME ABBIAMO AFFERMATO PRIMA, LA STRUTTURA
SWITCH LA SIMULERÀ ESEGUENDO L'ISTRUZIONE C

		scanf("%d", &memory[operand]);

PRIMA CHE LA FUNZIONE SCANF SIA ESEGUITA, DOVRÀ ESSERE VISUALIZZATO UN PUNTO INTERROGATIVO (?) PER RICHIEDERE L'INPUT DELL'UTENTE. IL SIMPLETRON ATTENDERÀ CHE
L'UTENTE IMMETTA UN VALORE E PREMA IL TASTO INVIO. A QUEL PUNTO IL VALORE SARÀ SISTEMATO NELLA LOCAZIONE 09.
LA SIMULAZIONE DELLA PRIMA ISTRUZIONE È STATA FINALMENTE COMPLETATA. CI RIMANE SOLO LA PREPARAZIONE DEL SIMPLETRON ALL'ESECUZIONE DELLA PROSSIMA ISTRUZIONE. DATO 
CHE L'ISTRUZIONE APPENA ESEGUITA NON ERA TRASFERIMENTO DI CONTROLLO, AVREMO SEMPLICEMENTE BISOGNO DI INCREMENTARE IL REGISTRO CONTATORE DELLE ISTRUZIONI, NEL MODO 
SEGUENTE:
		
		++instructionCounter;

QUESTO PASSO COMPLETA DAVVERO L'ESECUZIONE SIMULATA DELLA PRIMA ISTRUZIONE. L'INTERO PROCESSO (OVVEROSIA IL CICLO DI ESECUZIONE DELL'ISTRUZIONE) RICOMINCIERÀ
NUOVAMENTE CON IL RECUPERO DELLA PROSSIMA ISTRUZIONE DA ESEGUIRE. 
ORA ESAMINIAMO IN CHE MODO SARANNO SIMULATE LE ISTRUZIONI DI SALTO, OVVEROSIA I TRASFERIMENTI DI CONTROLLO. IN EFFETTI, SARÀ NECESSARIO SOLO AGGIORNARE IN MODO
APPROPRIATO IL VALORE CONTENUTO NEL CONTATORE DI ISTRUZIONI. DI CONSEGUENZA, L'ISTRUZIONE DI SALTO INCONDIZIONATO (40) SARÀ SIMULATA ALL'INTERNO DELLA STRUTTURA 
SWITCH CON :

		instructionCounter = operand;

MEMORY  DUMP:

	REGISTERS: 
	
	accumulator +0000
	instructionCounter 			00
	instructionRegister	+0000
	operationCode 00
	operand 00

	MEMORY:

		0	1	2	3	4	5	6	7	8	9
	0   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000
       10   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000
       20   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000
       30   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000
       40   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000
       50   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000
       60   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000
       70   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000
       80   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000
       90   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000   +0000

L'ISTRUZIONE CONDIZIONALE "SALTO SE L'ACCUMULATORE È UGUALE A ZERO" SARÀ SIMULATA CON:

		if(accumulator == 0)
			instructionCounter = operand;

A QUESTO PUNTO, DOVRESTE ESSERE IN GRADO DI IMPLEMENTARE IL VOSTRO SIMULATORE DI SIMPLETRON E DI ESEGUIRE OGNUNO DEI PROGRAMMI LMS CHE 
AVETE SCRITTO NELL'ESERCIZIO 7.18. POTRETE ABBELLIRE IL LINGUAGGIO LMS CON DELLE CARATTERISTICHE AGGIUNTIVE E IMPLEMENTARLE NEL VOSTRO 
SIMULATORE.
IL VOSTRO SIMULATORE DOVRÀ EFFETTUARE DEI CONTROLLI PER VARI TIPI DI ERRORE. PER ESEMPIO, DURANTE LA FASE DI CARICAMENTO DEL PROGRAMMA,
OGNI NUMERO CHE L'UTENTE TENTERÀ DI IMMETTERE NEL VOTTORE MEMROY DEL SIMPLETRON DOBTÀ ESSERE COMPRESO NELL'INTERVALLO DA -9999 A +9999.
IL VOSTRO SIMULATORE DOVRÀ QUINDI UTILIZZARE UN CICLO WHILE PER CONTROLLARE CHE OGNI NUMERO IMMESSO SIA COMPRESO IN QUELL'INTERVALLO E, 
IN CASO CONTRARIO, CONTINUARE A RICHIEDERLO ALL'UTENTE FINCHÈ NON NE ABRAÀ IMMESSO UNO CORRETTO. 
DURANTE LA FASE DI ESECUZIONE, IL VOSTRO SIMULATORE DOBRÀ EFFETTUARE DEI COTROLLI PER VARI ERRORI GRAVI, COME I TENTATIVI DI ESEGUIRE 
DELLE DIVISIONI PER ZERO O DI ESEGUIRE DEI CODICI DI OPERAIZONE NON VALIDI, IL SUPERMANTO DELLA CAPACITÀ DELL'ACCUMULATORE (OVVEROSIA
LE OPERAZIONI ARITMITICHE CHE PRODUCONO VALORI MAGGIORI DI +9999 E MINORI DI -9999) E ALTRE COSE SIMILI. INSOMMA, OCCORRERÀ GESTIRE GLI
ERRORI FATALI. NEL MOMENTO IN CUI AVRÀ INTERCETTATO UN ERRORE FATALE, IL VOSTRO SIMULATORE DOBRÀ VISUALIZZARE UN MESSAGGIO DI ERRORE COME:

		*** Attempt to divide bt zero ***
		*** Simpletron execution abnormally terminated ***

E VISUALIZZARE UN DUMP DOMPLETO DEL COMPUTER NEL FORMATO DI CUI ABBIAMO DISCUSSO IN PRECEDENZA.
CIÒ AIUTERÀ L'UTENTE A INDIVIDUARE L'ERRORE DEL PROGRAMMA.

*/


#include <stdio.h>
#include <string.h>
#define SIZE 100
 

int istruzione (int);
int posizione (int);

void print_start(void);
void editor(void);
void simpletron(int *,int *,int *,int *,int *);
void dump(int *,int *,int *,int *,int *);
int menu(void);
void reader(void);
void update(void);

int main(){
  
	
  //                     0 1 2   3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20   21
  //int memory[SIZE] = {10,1,1,1003,4005,2000,3102,4219,2003,1004,3104,4116,2002,3001,2102,4005,2004,2103,4005,2003,1103,4300};
  //                    10,1,0,0   ,1003,2000,4217,3101,2100,2003,1004,3104,4114,4005,2004,2103,4005,1103,4300
  int memory[SIZE] = {0}, choice;
  int accumulator = 0;                 //   +0000 RAPPRESENTA IL REGISTRO ACCUMULATORE
  int instructionCounter = 0;          //      00 PER CONSERVARE L'INDIRIZZO DI MEMORIA IN CUI SARA' CONTENUTA L'ISTRUZIONE DA ESEGUIRE
  int instructionRegister = 0;         //   +0000 NON ESEGUITE DIRETTAMENTE LE ISTRUZIONI CONTENUTE NELLA MEMORIA. TRASFERITE PIUTTOSTO QUELLA DA ESEGUIRE DALLA MEMORIA 
 		     		       //         IN UNA VARIABILE
  int operationCode = 0;               //      00 PER INDICARE L'OPERAZIONE DA ESEGUIRE OVVEROSIA LE DUE CIFRE A SINISTRA NELLA PAROLA DELL'ISTRUZIONE
  int operand = 0;                     //      00 INDICA LA LOCAZIONE DI MEMORIA SU CUI OPERERÀ L'ISTRUZIONE DA ESEGUIRE
 

  while((choice = menu()) != 6){
  	switch (choice){

		case 1:
		editor();
		break;

		case 2:
		reader();
		break;

		case 3:
		update();
		break;

		case 4:
		simpletron(&accumulator,&instructionCounter,&instructionRegister,&operationCode,&operand);
		break;

		case 5: 
		dump(&accumulator,&instructionCounter,&instructionRegister,&operationCode,&operand);
		break;

	}
  }
  return 0;

}


void reader(void){
	FILE *ptr;
	char name[20];
	int i = 1, memory[SIZE];
	

	printf("\nInserire il nome del file : ");
	scanf("%s",name);

	if((ptr = fopen(name,"r")) == NULL)
		printf("\nImpossibile aprire il file %s\n");
	else{
		fread(memory,sizeof(int),SIZE,ptr);
		for(i = 0 ; i < SIZE; i++)
			printf("%-3d -- istruzione --> %-6d\n",i,memory[i]);

		fclose(ptr);
	}
	
}

void dump(int *accumulator, int *instructionCounter, int *instructionRegister, int *operationCode, int *operand){

        int position, x , y, count, n;
	int instruction[SIZE] = {0};
	FILE *ptr;
	char name[20], dn[40] = "dump_", buf[SIZE], *c;

	printf("\nInserire il nome del file per il dump: ");
	scanf("%s",name);
	strcat(dn,name);

	if((ptr = fopen(name,"r")) == NULL)
		printf("\nImpossibile aprire il file %s\n",name);
	else{
		fread(instruction,sizeof(int),SIZE,ptr);
		fclose(ptr);
	}

	if((ptr = fopen(dn,"r+")) == NULL)
		printf("\nImpossibile creare il file dump %s\n",n);
	else{
	
		fprintf(ptr,"\n");

		fprintf(ptr,"MEMORY  DUMP:\nREGISTERS:\n"); 
        
        	fprintf(ptr,"accumulator:  %4d\n",*accumulator);
        	fprintf(ptr,"instructionCounter  %2d\n", *instructionCounter);
        	fprintf(ptr,"instructionRegister %2d\n", *instructionRegister);
        	fprintf(ptr,"operationCode %2d\n", *operationCode);
        	fprintf(ptr,"operand %2d\n", *operand);
	
        	fprintf(ptr,"\nMEMORY:\n");


		fprintf(ptr,"%s","  ");
		for(x = 0; x <= 9 ; x++)
			fprintf(ptr,"%8d",x);
	
		fprintf(ptr,"\n");

		for(y = 0 ; y <= 90; y += 10){
			fprintf(ptr,"%2d",y);
			for(x = y; x < y + 10; x++){
				if(instruction[x] == 0)
					fprintf(ptr,"    0000");
				else{
				fprintf(ptr,"    ");
				for(count = instruction[x], n = 0; count > 0; count  /= 10)
        				n++;
  				n = 4 - n;
				while(n-- > 0)
					fprintf(ptr,"0");
				fprintf(ptr,"%d",instruction[x]);
				}
			}
			fprintf(ptr,"\n");
		}

		fprintf(ptr,"\n");
		rewind(ptr);

		while(1){
			c = fgets(buf, SIZE - 1, ptr);
			if (c == NULL) break;
			puts(buf);
		}

		fclose(ptr);
	}
}

void editor(void){

	FILE *ptr;
        char name[20];	
        int  choice = 0, position = 0, instruction[SIZE] = {0};

	printf("\nInserire il nome del file sul quale salvare il programma: ");
	scanf("%s",name);
	
	if((ptr = fopen(name,"w")) == NULL)
		printf("\nImpossibile aprire %s\n");
	else{
  		
		print_start(); // Stampa l'intestazione

        	do{

			position < 10 ? printf("0%d ? ",position) : printf("%d ? ",position);
			scanf("%d",&choice);
			if(choice == -99999){
				instruction[position] = 4300;
				break;
			}else if(choice > 9999){
				continue;
			}else{
				instruction[position] = choice;
				position++;
			}
		}while(position < 100);
	fwrite(instruction,sizeof(int),SIZE,ptr);
	fclose(ptr);
	printf("\n\n\t\t*** Program loading completed ***\n\n\t\t*** Program execution begins ***\n\n");
	}

}


void simpletron(int *accumulator, int *instructionCounter, int *instructionRegister, int *operationCode, int *operand){

	FILE *ptr;

		
	*accumulator = 0;                 //   +0000 RAPPRESENTA IL REGISTRO ACCUMULATORE
  	*instructionCounter = 0;          //      00 PER CONSERVARE L'INDIRIZZO DI MEMORIA IN CUI SARA' CONTENUTA L'ISTRUZIONE DA ESEGUIRE
  	*instructionRegister = 0;         //   +0000 NON ESEGUITE DIRETTAMENTE LE ISTRUZIONI CONTENUTE NELLA MEMORIA. TRASFERITE PIUTTOSTO QUELLA DA ESEGUIRE DALLA MEMORIA 
			     		     //         IN UNA VARIABILE
  	*operationCode = 0;               //      00 PER INDICARE L'OPERAZIONE DA ESEGUIRE OVVEROSIA LE DUE CIFRE A SINISTRA NELLA PAROLA DELL'ISTRUZIONE
  	*operand = 0;                     //      00 INDICA LA LOCAZIONE DI MEMORIA SU CUI OPERERÀ L'ISTRUZIONE DA ESEGUIRE
  	int memory[SIZE] = {0};

	char name[20];

	printf("\nInserisci il nome del file: ");
	scanf("%s",&name);

	if((ptr = fopen(name,"r")) == NULL)
		printf("\nImpossibile aprire il file %s\n",name);
	else{

	fread(memory,sizeof(int),SIZE,ptr);
       	

	while(*instructionCounter <= 100){
		
		*instructionRegister = memory[*instructionCounter];
		*operationCode = *instructionRegister / 100;
                *operand = *instructionRegister % 100;

		switch(*operationCode){
			
			case 10:  // LEGGE UNA PAROLA DAL TERMINALE E LA IMMAGAZZINA IN UNA SPECIFICA LOCAZIONE DI MEMORIA.
			printf("Inserire un numero: ");
			scanf("%d",instructionRegister);
			memory[*operand] = *instructionRegister;
			++(*instructionCounter);
			break;

			case 11:  // SCRIVE SUL TERMINALE UNA PAROLA CONTENUTA IN UNA SPECIFICA LOCAIONE DI MEMORIA.
			*instructionRegister = memory[*operand];
		        printf("\nValore presente in locazione %d : %d\n",*operand ,*instructionRegister);
			++(*instructionCounter);
			break; 

			case 20:  // CARICA NELL'ACCUMULATORE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA
			*accumulator = memory[*operand];
			printf("\nValore accumulatore: %d\n",*accumulator);
			++(*instructionCounter);
			break;

			case 21:  // ARCHIVIA IL CONTENUTO DELL'ACCUMULATORE IN UNA SPECIFICA LOCAIZONE DI MEMORIA.
			memory[*operand] = *accumulator;
			++(*instructionCounter);
			break;

			case 30:  // AGGIUNGE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAIZONE DI MEMORIA A QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)
			*accumulator += memory[*operand];
			++(*instructionCounter);
			break;

			case 31:  // SOTTRAE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA DA QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)
		        *accumulator -= memory[*operand];
			//printf("\nValore accumulatore: %d\n",accumulator);
			++(*instructionCounter);
                        break;
			
			case 32:  // DIVIDE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA PER QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)
			*accumulator /= memory[*operand];
			//printf("\nValore accumulatore: %d\n",accumulator);
			++(*instructionCounter);
                        break;
			
			case 33:  // MOLTIPLICA LA PAROLA CONTENUTA IN UNA SPEFICA LOCAIZONE DI MEMORIA DA QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)
			*accumulator *= memory[*operand];
			//printf("\nValore accumulatore: %d\n",accumulator);
			++(*instructionCounter);
                        break;

			case 40:  // SALTA AD UNA SPECIFICA LOCAIZONE DI MEMORIA
			*instructionCounter  = *operand;
                        break;
			
			case 41:  // SALTA AD UNA SPECIFICA LOCAZIONE DI MEMORIA SE L'ACCUMULATORE CONTIENE UN VALORE NEGATIVO
			if(*accumulator < 0)
				*instructionCounter = *operand;
			else
				++(*instructionCounter);
			break;

			case 42:  // SALTA AD UNA SPECIFICA LOCAZIONE DI MEMORIA SE L'ACCUMULATORE CONTIENE UN VALORE UGUALE A ZERO
			if(*accumulator == 0)
                        	*instructionCounter = *operand;
			else
				++(*instructionCounter);
                        break;

			case 43:  // TERMINA L'ESECUZIONE
			+printf("\n*** Simpletron execution terminated ***\n");
			break;

			default:
			//printf("\nDato o istruzione errata: %d\n",instructionRegister);
			++(*instructionCounter);
			break;

		}

		if(*operationCode == 43)
			break;
	}

	fwrite(memory,sizeof(int),SIZE,ptr);
	fclose(ptr);

	}
}


void print_start(void){
	

	printf("\n        *** Welcome to Simpletron! ***\n");
	printf("*** Please enter your program one instruction ***\n");
	printf("*** (or data word) at a time. I will type the ***\n");
	printf("*** location number and a question mark (?).  ***\n");
	printf("*** You then type the word for that location. ***\n");
	printf("*** Type the sentinel -99999 to stop entering ***\n");
	printf("             *** your program. ***\n");

}


int menu(void){

	int choice;
	do{
        printf("\n1 - per Editare il programma"
	       "\n2 - per Visualizzare il programma editato"
	       "\n3 - per Modificare uno o piu Record del programma"
	       "\n4 - per Eseguire Simpletron"
	       "\n5 - Dump Memory"
	       "\n6 - Esci"
	       "\nFate la vostra scelta ---> : ");
	scanf("%d",&choice);
	}while(choice < 1 || choice > 6);

	return choice;
}


void update(void){
	
	FILE *ptr;
	char name[20];
	int i = 1, memory[SIZE], n, ist;
	

	printf("\nInserire il nome del file : ");
	scanf("%s",name);

	if((ptr = fopen(name,"r+")) == NULL)
		printf("\nImpossibile aprire il file %s\n");
	else{
		fread(memory,sizeof(int),SIZE,ptr);
		for(i = 0 ; i < SIZE; i++)
			printf("%-3d -- istruzione --> %-6d\n",i,memory[i]);
		do{
		printf("\nInserire posizione -99 per terminare: ");
	        scanf("%d",&n);
		if(n == -99) break;
		printf("\nInserire l'istruzione: ");
		scanf("%d",&ist);
		memory[n] = ist;
		}while(1);
		
		fwrite(memory,sizeof(int),SIZE,ptr);
		fclose(ptr);
	}
	
}
