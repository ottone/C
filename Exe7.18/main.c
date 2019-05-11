//
//  main.c
//  Exe7.18
//
//  Created by Francesco Parrucci on 14/04/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
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

*/


#include <stdio.h>
#define SIZE 100


int istruzione (int);
int posizione (int);

void codici(void);
void editor(int []);
void inserimento_modifica(int []);
void simpletron(int []);
int check(int []);
void visualizza_sorgenti(int []);

int main(){
 
  //int memory[SIZE] = {0}, count;
  
  int memory[SIZE] = {10,1,1,1003,4005,2000,3102,4219,2003,1004,3104,4116,2002,3001,2102,4005,2004,2103,4005,2003,1103,4300};

  visualizza_sorgenti(memory);

  getchar();
  
  

  // Editor simpletron
  
  // editor(memory);
  
  // Esecuzione 

  if(check(memory))  
  simpletron(memory);  

  return 0;

}

void codici(void){

          printf("\t10 LEGGE UNA PAROLA DAL TERMINALE E LA IMMAGAZZINA IN UNA SPECIFICA LOCAIONE DI MEMORIA.\n");
          printf("\t11 SCRIVE SUL TERMINALE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAIZONE DI MEMORIA.\n");
          printf("\t20 CARICA NELL'ACCUMULATORE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA.\n");
          printf("\t21 ARCHIVIA IL CONTENUTO DELL'ACCUMULATORE IN UNA SPECIFICA LOCAZIONE DI MEMORIA.\n");
          printf("\t30 AGGIUNGE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAIZONE DI MEMORIA A QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)\n");
          printf("\t31 SOTTRAE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA DA QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)\n");
          printf("\t32 DIVIDE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA PER QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)\n");
          printf("\t33 MOLTIPLICA LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAIZONE DI MEMORIA PER QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO).\n");
          printf("\t40 SALTA A UNA SPECIFICA LOCAZIONE DI MEMORIA\n");
          printf("\t41 SALTA A UNA SPECIFICA LOCAIZONE DI MEMORIA, SE L'ACCUMULATORE UN VALORE NEGATIVO.\n");
          printf("\t42 SALTA A UNA SPECIFICA LOCAIZONE DI MEMORIA, SE L'ACCUMULATORE CONTIENE UN VALORE UGUALE A ZERO.\n");
          printf("\t43 FERMA L'ESECUZIONE DEL PROGRAMMA\n\n\n");


}

void visualizza_sorgenti(int instruction[]){

        int position;

	printf("\n\n");

        for(position = 0; position < SIZE; position++){
               printf("MEMORY[%3d] -> %4d", position , instruction[position]);
	       (position + 1) % 4 == 0 ? printf("\n") : printf("\t");
	}
	printf("\n\n");
}

void editor(int instruction[SIZE]){

        int  choice = 0;
	
        	do{
                	printf("\n1) STAMPA CODICI DELLE OPERAIZONI:\n");
                	printf("\n2) VISUALIZZA IL CONTENUTO DEL SORGENTE.\n");
               		printf("\n3) INSERIMENTO O MODIFICA DI UNA O PIU VOCI\n");
                	printf("\n4) ESCI ED ESEGUI: ");
                	scanf("%d", &choice);
			
		   switch (choice){
			case 1:
			codici();
			break;

			case 2:
			visualizza_sorgenti(instruction);
			break;

			case 3:
			inserimento_modifica(instruction);
			break;

			case 4:
			break;

			default:
			printf("Scelta sbagliata\n");
			choice = 0;
			break;
		    }

		}while(choice != 4);
		
}

void inserimento_modifica(int instruction[SIZE]){

        int position;

	printf("\nInserire il valore dell'indice (-1 per terminare): ");
	scanf("%d",&position);

	while(position >= -1 && position <= 100){
        
	   if(position == -1)
		   break;

	   printf("\nParola :");
	   scanf("%d",&instruction[position]);

	   printf("\nInserire il valore dell'indice (-1 per terminare): ");
           scanf("%d",&position);
	}	
}

void simpletron(int memory[]){

	int accumulatore = 0, puntatore = 0, temp = 0;

	while(puntatore <= 100){
		
		switch(istruzione(memory[puntatore])){
			
			case 10:  // LEGGE UNA PAROLA DAL TERMINALE E LA IMMAGAZZINA IN UNA SPECIFICA LOCAZIONE DI MEMORIA.
			printf("Inserire un numero: ");
			scanf("%d",&memory[posizione(memory[puntatore])]);
			puntatore++;
			break;

			case 11:  // SCRIVE SUL TERMINALE UNA PAROLA CONTENUTA IN UNA SPECIFICA LOCAIONE DI MEMORIA.
		        printf("\nValore presente in locazione %d : %d\n",posizione(memory[puntatore]) ,memory[posizione(memory[puntatore])]);
			puntatore++;
			break; 

			case 20:  // CARICA NELL'ACCUMULATORE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA
			accumulatore = memory[posizione(memory[puntatore])];
			printf("\nValore accumulatore: %d\n",accumulatore);
			puntatore++;
			break;

			case 21:  // ARCHIVIA IL CONTENUTO DELL'ACCUMULATORE IN UNA SPECIFICA LOCAIZONE DI MEMORIA.
			memory[posizione(memory[puntatore])] = accumulatore;
			puntatore++;
			break;

			case 30:  // AGGIUNGE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAIZONE DI MEMORIA A QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)
			accumulatore += memory[posizione(memory[puntatore])];
			puntatore++;
			break;

			case 31:  // SOTTRAE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA DA QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)
		        accumulatore -= memory[posizione(memory[puntatore])];
			printf("\nValore accumulatore: %d\n",accumulatore);
			puntatore++;
                        break;
			
			case 32:  // DIVIDE LA PAROLA CONTENUTA IN UNA SPECIFICA LOCAZIONE DI MEMORIA PER QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)
			accumulatore /= memory[posizione(memory[puntatore])];
			printf("\nValore accumulatore: %d\n",accumulatore);
			puntatore++;
                        break;
			
			case 33:  // MOLTIPLICA LA PAROLA CONTENUTA IN UNA SPEFICA LOCAIZONE DI MEMORIA DA QUELLA CONTENUTA NELL'ACCUMULATORE (LASCIANDO IN QUESTO IL RISULTATO)
			accumulatore *= memory[posizione(memory[puntatore])];
			printf("\nValore accumulatore: %d\n",accumulatore);
			puntatore++;
                        break;

			case 40:  // SALTA AD UNA SPECIFICA LOCAIZONE DI MEMORIA
			puntatore  = posizione(memory[puntatore]);
                        break;
			
			case 41:  // SALTA AD UNA SPECIFICA LOCAZIONE DI MEMORIA SE L'ACCUMULATORE CONTIENE UN VALORE NEGATIVO
			if(accumulatore < 0)
				puntatore  = posizione(memory[puntatore]);
			else
				puntatore++;
			break;

			case 42:  // SALTA AD UNA SPECIFICA LOCAZIONE DI MEMORIA SE L'ACCUMULATORE CONTIENE UN VALORE UGUALE A ZERO
			if(accumulatore == 0)
                        	puntatore  = posizione(memory[puntatore]);
			else
				puntatore++;
                        break;

			case 43:  // TERMINA L'ESECUZIONE
			printf("\nBye!\n");
			break;

			default:
			printf("\nDato o istruzione errata: %d\n",memory[puntatore]);
			puntatore++;
			break;

		}

		visualizza_sorgenti(memory);

		if(istruzione(memory[puntatore]) == 43)
			break;
	}

}

int istruzione(int number){
  return number / 100;
}

int posizione(int number){
  return number % 100;
}

int check(int memory[SIZE]){

	int count, ret = 0;

	for(count = 0; count <= SIZE - 1; count++)
		if(memory[count] != 0)
			ret = 1;
	
	return ret;
}
