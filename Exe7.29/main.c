//
//  main.c
//  Exe7.29
//
//  Created by Francesco Parrucci on 18/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
(Modifiche al simulatore Simpletron) Nell'esercizio 7.19 avete scritto una simulazione software di un computer
che esegue i programmi scritti nel Linguaggio Macchina Simpletron (LMS). In questo esercizio, proporremo diverse
modifiche e miglioramenti al Simulatore Simpletron. Negli Esercizi 12.26 e 12.27, proporremo la costruzione di 
un compilatore che convertirà i programmi scritti in un linguaggio ad alto livello (una variante del BASIC) nel 
Linguaggio Macchina del Simpletron. Alcune delle seguenti modifiche e migliorie potranno essere necessarie per 
eseguire i programmi prodotti dal compilatore.

a) Estendete la memoria del Simulatore Simpletron, in modo che possa contenere 1000 locazioni e consentire al 
   Simpletron di gestire programmi più corposi.
	
b) Fate in modo che il simulatore possa eseguire il calcolo del modulo. Sarà necessario aggiungere un'istruzione 
   un'istruzione al Linguaggio Macchina Simpletron (34)

c) Fate in modo che il simulatore possa calcolare l'elevamento a potenza. Sarà necessario aggiungere un'istruzione 
   al Linguaggio Macchina Simpletron. (35)

d) Modificate il simulatore in modo che utilizzi dei valori esadecimali, invece di quelli interi, per rappresentare le
   istruzioni del Linguaggio Macchina Simpletron.

e) Modificate il simulatore per consentire la visualizzazione di un carattere newline. Sarà necessario aggiungere 
   un'istruzione al Linguaggio Macchina Simpletron.

f) Modificate il simulatore in modo che possa elaborare anche dei valori in virgola mobile oltre a quelli interi.

g) Modificate il simulatore in modo che possa gestire l'input di stringhe. Suggerimento: ogni parola del Simpletron 
   potrà essere suddivisa in due gruppi contenenti ognuno un intero di due cifre.
   Ogni intero di due cifre rappresenterà il valore decimale ASCII equivalente a un carattere. Aggiungete un'istruzione
   in linguaggio macchina che prenda in input una stringa e la immagazzini in una spefifica locazione della memoria del
   Simpletron. In quella locazione, la prima metà della parola conterrà il numero di caratteri inclusi nella stringa 
   (ovverosia, la sua lunghezza). Ogni mezza parola successiva conterrà un carattere ASCII espresso con un valore decimale
   di due cifre. L'istruzione in linguaggio macchina convertirà ogni carattere nel suo equivalente ASCII e lo assegnerà 
   alla mezza parola. 
b) Modificate il simulatore in modo che gestisca l'output delle stringhe immagazzinate nel formato descritto nella parte
   (g). Suggerimento : aggiungete al linguaggio macchina un'istruzione che visualizzi una stringa cominciando da una certa
   locazione della memoria del Simpletron. In quella locazione, la prima metà della parola conterrà il nuemro dei caratteri
   inclusi nella stringa (ovverosia, la sua lunghezza). Ogni mezza parola successiva conterrà un carattere ASCII espresso
   con un valore decimale di due cifre. L'istruzione in linguaggio macchina controllerà la lunghezza e visualizzerà la stringa
   , traducendo ogni numero di due cifre nel carattere equivalente.

*/



//
//  main.c
//  Exe7.19
//
//  Created by Francesco Parrucci on 18/04/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
7.18
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

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#define SIZE 1000
 

int istruzione (int);
int posizione (int);

void print_start(void);
void editor(float []);
void simpletron(float []);
void visualizza_sorgenti(float [],int ,int, int, int, int);
int pw(int , int );
/*
void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}
*/
int main(){
  //                     0 1 2   3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20   21
  //int memory[SIZE] = {10,1,1,1003,4005,2000,3102,4219,2003,1004,3104,4116,2002,3001,2102,4005,2004,2103,4005,2003,1103,4300};
  //                    10,1,0,0   ,1003,2000,4217,3101,2100,2003,1004,3104,4114,4005,2004,2103,4005,1103,4300
  float memory[SIZE] = {0}, n;
  unsigned int a;


//  	printf("\nStringa immessa : %s\n",buf);

// while(1){
//	printf("\n%d --> %X ",b,b++);
//	a = time(0) + 2; 
//	while(time(0) < a);	  
//  }

  print_start();
  editor(memory);  
  simpletron(memory); 
  
  return 0;
}

int pw(int base, int exponent){
	
	if(exponent == 0)
		return 1;
	else
		return base * pw(base,exponent-1);	

}

void visualizza_sorgenti(float instruction[], int accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand){

        int position, x , y, count, n, intera;
	int mantissa;

	printf("\n");

	printf("MEMORY  DUMP:\nREGISTERS:\n"); 
        
        printf("accumulator:  %4d\n",accumulator);
        printf("instructionCounter  %2d\n", instructionCounter);
        printf("instructionRegister %2d\n", instructionRegister);
        printf("operationCode %2d\n", operationCode);
        printf("operand %2d\n", operand);
	
        printf("\nMEMORY:\n");

	
	printf("%s","  ");
	for(x = 0; x <= 9 ; x++)
		printf("%8d",x);
	
	printf("\n");

	for(y = 0 ; y <= 990; y += 10){
		printf("%3X",y);
		for(x = y; x < y + 10; x++){
			if(instruction[x] == 0)
				printf("    000000");
			else{
			printf("    ");
			if(ceil(instruction[x]) == instruction[x]){   // verifica se intero o reale
				for(count = (int)instruction[x], n = 0; count > 0; count  /= 16)
        				n++;
  				n = 6 - n;
				while(n-- > 0)
				printf("0");
				printf("%X",(int)instruction[x]);
			}else{
				intera = (int)instruction[x];
 				mantissa = (instruction[x] - (float)intera) * 100;
				
				
				for(count = intera, n = 0; count > 0; count  /= 16)
                                         n++;
                                 n = 3 - n;
                                while(n-- > 0)
                                printf("0");
                                printf("%X.",intera);

				for(count = mantissa, n = 0; count > 0; count  /= 16)
                                         n++;
                                 n = 2 - n;
				printf("%X",mantissa);
                                while(n-- > 0)
                                printf("0");
                          
			}
			}
		}
		printf("\n");
	}

	printf("\n");
}

void editor(float instruction[SIZE]){

        int  choice = 0, position = 0;
	
        	do{

			if(position < 10)

				printf("00%d ? ",position);
		        
			else if(position >= 10 && position < 100)
			
				printf("0%d ? ",position);
			
			else
			
				printf("%d ? ",position);	

			scanf("%d",&choice);
			
			if(choice == -99999){
				instruction[position] = 43000;
				break;
			}else if(choice > 99999 || choice <= 9999){
				continue;
			}else{
				instruction[position] = choice;
				position++;
			}
		}while(position < SIZE);
	
	printf("\n\n\t\t*** Program loading completed ***\n\n\t\t*** Program execution begins ***\n\n");

}


void simpletron(float memory[]){


	int accumulator = 0;                 //   +0000 RAPPRESENTA IL REGISTRO ACCUMULATORE
  	int instructionCounter = 0;          //      00 PER CONSERVARE L'INDIRIZZO DI MEMORIA IN CUI SARA' CONTENUTA L'ISTRUZIONE DA ESEGUIRE
  	int instructionRegister = 0;         //   +0000 NON ESEGUITE DIRETTAMENTE LE ISTRUZIONI CONTENUTE NELLA MEMORIA. TRASFERITE PIUTTOSTO QUELLA DA ESEGUIRE DALLA MEMORIA IN UNA VARIABILE
  	int operationCode = 0;               //      00 PER INDICARE L'OPERAZIONE DA ESEGUIRE OVVEROSIA LE DUE CIFRE A SINISTRA NELLA PAROLA DELL'ISTRUZIONE
  	int operand = 0;                     //      00 INDICA LA LOCAZIONE DI MEMORIA SU CUI OPERERÀ L'ISTRUZIONE DA ESEGUIRE
	
	float accumulatorFloat = 0;	     //      00 RAPPRESENTA IL REGISTRO ACCUMULATORE PER VALORI FLOAT
	float instructionRegisterFloat = 0;  //      00 RAPPRESENTA IL SECONDO REGISTRO ACCUMULATORE PER VALORI FLOAT
	int intera = 0;			     //	     00 BUFFER PER REGISTRAZIONE VALORI REALI NEL VETTORE
	int mantissa = 0;		     //      00 BUFFER PER REGISTRAZIONE VALORI IN VIRGOLA MOBILE 	
	int b = 0, count;		     //      CONTATORI PER OPERAZIOSU SULLE STRIGHE CASE 36 E 37	
	char buf[397], c;		     //      BUFFERS PER LE STRIGHE

	
	while(instructionCounter <= SIZE){
		
		instructionRegister = memory[instructionCounter];
		operationCode = instructionRegister / 1000;
                operand = instructionRegister % 1000;

		printf("\nValore di instructionRegister : %d\n", instructionRegister);
		printf("\nValore di operationCode : %d\n", operationCode);
		printf("\nValore di oparand : %d\n", operand);
		getchar();

		switch(operationCode){
			
			case 10:  // LEGGE UNA PAROLA DAL TERMINALE E LA IMMAGAZZINA IN UNA SPECIFICA LOCAZIONE DI MEMORIA.
			printf("Inserire un numero: ");
			scanf("%f",&instructionRegisterFloat);
			memory[operand]= instructionRegisterFloat;
			++instructionCounter;
			break;

			case 11:  // SCRIVE SUL TERMINALE UNA PAROLA CONTENUTA IN UNA SPECIFICA LOCAIONE DI MEMORIA.
			instructionRegisterFloat = memory[operand];
			if(ceil(instructionRegisterFloat) == instructionRegisterFloat)
				printf("\nValore presente in locazione %d : %d\n",operand ,(int)instructionRegisterFloat);
			else
				printf("\nValore presente in locaiozne %d : %.2f\n",operand, instructionRegisterFloat);
				getchar();
			++instructionCounter;
			break; 

			case 20:  // CARICA NELL'ACCUMULATORE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA
			instructionRegisterFloat = memory[operand];
			if(ceil(instructionRegisterFloat) == instructionRegisterFloat){
				accumulator = (int)instructionRegisterFloat;
				printf("\nValore accumulatore: %d\n",accumulator);
			}else{
				accumulatorFloat = instructionRegisterFloat;
				printf("\nValore accumulatore: %2.f\n",accumulatorFloat);
			}
			++instructionCounter;
			break;

			case 21:  // ARCHIVIA IL CONTENUTO DELL'ACCUMULATORE IN UNA SPECIFICA LOCAIZONE DI MEMORIA.
			if(accumulator != 0)
				memory[operand] = (float)accumulator;
			else
				memory[operand] = accumulatorFloat;
			accumulator = 0;
			accumulatorFloat = 0;
			++instructionCounter;
			break;

			case 30:  // AGGIUNGE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAIZONE DI MEMORIA A QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)
			if(accumulator != 0)
				accumulator += memory[operand];
			else
				accumulatorFloat += memory[operand];	
				
			++instructionCounter;
			break;

			case 31:  // SOTTRAE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA DA QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)
		        
			if(accumulator != 0)
				accumulator -= memory[operand];
			else
				accumulatorFloat -= memory[operand];

			++instructionCounter;
                        break;
			
			case 32:  // DIVIDE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA PER QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)
			if(accumulator != 0)
				accumulator /= memory[operand];
			else
				accumulatorFloat /= memory[operand];
			
			++instructionCounter;
                        break;
			
			case 33:  // MOLTIPLICA LA PAROLA CONTENUTA IN UNA SPEFICA LOCAIZONE DI MEMORIA DA QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)
			if(accumulator != 0)
				accumulator *= memory[operand];
			else
				accumulatorFloat /= memory[operand];

			++instructionCounter;
                        break;

			case 34: // OTTIENE IL MODULO DELLA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA DA QUELLA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)
			if(accumulator != 0)
			  accumulator %= (int)memory[operand];
			++instructionCounter;
			break;

			case 35: // L'ELEVAMENTO A POTENZA DELL'ACCUMULATORE PER LA PAROLA  IN MEMORY[OPERAND] LASCIANDO IN ACCUMULATOR IL RISULTATO.
			if(accumulator != 0)
				accumulator = pw(accumulator,memory[operand]);			
			++instructionCounter;
			break;
			
			case 36: // Input di stringhe Riservo locazione di memoria da 800 999
 			b = 0;
			printf("\nInserisci una stringa di caratteri CTRL-D per terminare: \n");
  			while((c = getchar())!=EOF) { 
  				buf[b++] = c;
 			}
			
			for(b = 0, count = 0 ;  buf[count] != '\0' ;b++,count++){
				intera = buf[count++];
			        intera += buf[count] * 1000;
				memory[800 + b] = intera;
				//printf("\n%f\n",memory[800 + b]);
				getchar();
			}

			
			++instructionCounter;        
			break;

			case 37: // Output di stringhe memorizzate nella locazione da 800 a 999
			printf("\nStampa stringhe : \n");
			for(b = 0, count = 0; count < 200; count++){
				intera = (int)memory[800 + count];
				if(intera != 0){
					printf("%c",intera % 1000);
					intera = intera / 1000;
					printf("%c",intera);}
				memory[800 + count] = 0;
			}
			++instructionCounter;
			break;

			case 40:  // SALTA AD UNA SPECIFICA LOCAIZONE DI MEMORIA
			instructionCounter  = operand;
                        break;
			
			case 41:  // SALTA AD UNA SPECIFICA LOCAZIONE DI MEMORIA SE L'ACCUMULATORE CONTIENE UN VALORE NEGATIVO
			if(accumulator < 0)
				instructionCounter = operand;
			else
				++instructionCounter;
			break;

			case 42:  // SALTA AD UNA SPECIFICA LOCAZIONE DI MEMORIA SE L'ACCUMULATORE CONTIENE UN VALORE UGUALE A ZERO
			if(accumulator == 0)
                        	instructionCounter = operand;
			else
				++instructionCounter;
                        break;

			case 43:  // TERMINA L'ESECUZIONE
			printf("\n*** Simpletron execution terminated ***\n");
			break;

			default:
			//printf("\nDato o istruzione errata: %d\n",instructionRegister);
			++instructionCounter;
			break;

		}

		if(operationCode == 43)
			break;
	}



 visualizza_sorgenti(memory, accumulator, instructionCounter, instructionRegister, operationCode, operand);

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
