//
//  main.c
//  Exe12.15
//
//  Created by Francesco Parrucci on 28/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
//  (Simulazione di un supermercato) Scrivete un programma che simuli una fila alla cassa di un supermercato. La fila è una coda. I clienti arriveranno casualmente in 
//  intervalli interi compresi tra 1 e 4 minuti. Anche i clienti saranno serviti in modo casuale ad intervalli interi compresi tra 1 e 4 minuti. Ovviamente, i ritmi 
//  dovranno essere bilaciati. la coda crescerà all'infinito qualora il ritmo degli arrivi sia superiore a quello del servizio. Nonostante i ritmi bilanciati, il caso 
//  potrebbe causare delle lunghe code. Eseguite la simulaizone del supermercato per una giornata lavorativa di 12 ore (720 minuti),usando il seguente algoritmo:
//
//  1) Scegliete un intero casuale compreso tra 1 e 4, per determinare il minuto in cui arriverà il primo cliente.
//
//  2) Nel momento in cui arriva il primo cliente:
//     Deteminate il tempo di servizio del cliente(un intero casuale compreso tra 1 e 4);
//     Cominciate a servire il cliente;
//     Stabilite il tempo di arrivo del prossimo cliente ( un intero casuale compreso tra 1 e 4 aggiunto al tempo corrente).
//
//  3) Per ogni minuto del giorno:
//     Qualora arrivi il cliente successivo:
//     	Mettete il cliente nella coda;
//     	Stabilite il tempo di arrivo del prossimo cliente;
//     	Nel caso in cui sia stato completato il servizio per l'ultimo cliente:
//     		Comunicatelo 
//     		Togliete dalla coda il prossimo cliente da servire
//     		Determinate il temopo di completamento del servizio per il cliente (ovverosia, un intero casuale da 1 a 4 aggiunto al tempo corrente).
//
//  Eseguite ora la vostra simulazione e ponetevi le seguenti questioni:
//
//  	a) Qual è stato il numero massimo di clienti in coda durante tutta la simulazione ?
//  	b) Qual è stata l'attesa piu lunga tra quelle sperimentate dai clienti?
//  	c) Che cosa succederebbe se l'intervallo di arrivo, compreso tra 1 e 4 minuti, fosse cambiato in uno compreso tra 1 e 3 minuti?
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct queueNode{
	unsigned int data;
	struct queueNode *nextPtr;
};

typedef struct queueNode QUEUENODE;
typedef QUEUENODE *QUEUENODEPTR;

void enqueue(QUEUENODEPTR *, QUEUENODEPTR *,unsigned int data);
unsigned int dequeue(QUEUENODEPTR *, QUEUENODEPTR *);
void printQueue(QUEUENODEPTR);
void waitFor(unsigned int);

int main(){
unsigned int tArrive, tService;
int i = 1;
srand(time(NULL));

QUEUENODEPTR head = NULL, tail = NULL;

tArrive = time(0) + (1 + (rand() % 5));//  1) Scegliete un intero casuale compreso tra 1 e 4, per determinare il minuto in cui arriverà il primo cliente.

while(1){

	if(time(0) == tArrive){				//  2) Nel momento in cui arriva il primo cliente:
		tService = time(0) + (1 + (rand() % 5));
		enqueue(&head,&tail,i++);
		tArrive = time(0) + (1 + (rand() % 5));
	}

	if(head != NULL && time(0) == tService)
        	dequeue(&head,&tail);
	
	printQueue(head);
	//getchar();
}

//     Deteminate il tempo di servizio del cliente(un intero casuale compreso tra 1 e 4);
//     Cominciate a servire il cliente;
//     Stabilite il tempo di arrivo del prossimo cliente ( un intero casuale compreso tra 1 e 4 aggiunto al tempo corrente).
//
//  3) Per ogni minuto del giorno:
//     Qualora arrivi il cliente successivo:
//     	Mettete il cliente nella coda;
//     	Stabilite il tempo di arrivo del prossimo cliente;
//     	Nel caso in cui sia stato completato il servizio per l'ultimo cliente:
//     		Comunicatelo 
//     		Togliete dalla coda il prossimo cliente da servire
//     		Determinate il temopo di completamento del servizio per il cliente (ovverosia, un intero casuale da 1 a 4 aggiunto al tempo corrente).

return 0;
}

void enqueue(QUEUENODEPTR *head,QUEUENODEPTR *tail,unsigned int data){
	QUEUENODEPTR newPtr = NULL;
	newPtr = malloc(sizeof(QUEUENODE));
	if(newPtr != NULL){
		newPtr->data = data;
		newPtr->nextPtr = NULL;
		if(*head == NULL)
			*head = newPtr;
		else
			(*tail)->nextPtr = newPtr;
		*tail = newPtr;
	}else
		printf("\nMemory not available!!!\n");
}

unsigned int dequeue(QUEUENODEPTR *head,QUEUENODEPTR *tail){
	QUEUENODEPTR temp = NULL;
	unsigned int data;

	data = (*head)->data;
	temp = *head;
	*head = (*head)->nextPtr;

	if(*head == NULL)
		*tail = NULL;

	free(temp);
	return data;
}

void printQueue(QUEUENODEPTR currentPtr){
	
	if(currentPtr == NULL)
		printf("\nLa coda è vuota!");
	else{
		while(currentPtr != NULL){
		printf(" %d ",currentPtr->data);
		currentPtr = currentPtr->nextPtr;
	}
	printf("\n");
	}
}

void waitFor(unsigned int secs){

	unsigned int retTime = time(0) + secs;
	while (time(0) < retTime) ;
}
