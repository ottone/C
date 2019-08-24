//
//  main.c
//  Exe12.24
//
//  Created by Francesco Parrucci on 04/08/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
// 
//  (Visita per livelli di un albero binario) Il programma delal Figura 12.19 ha mostrato tre metodi ricorsivi per visitare  un albero binario: la visita simmetrica, quella anticipata e quella differita. Questo esercizio presenterà la visita per livelli di un 
//  albero binario, nella quale i valori dei nodi saranno visualizzati livello dopo livello, incomincianndo da quello del nodo radice. I nodi di ogni livello saranno visualizzati da sinistra a destra. LA visita per livelli non è un algoritmo ricorsivo. 
//  Essa usa la struttura di dati coda per controllare l'output dei nodi. L'algorirmo sarà il seguente:
//
//  1) Inserite il nodo radice nella coda.
//  2) Fintanto che siano rimasti dei nodi nella coda,
//
//  	Prendete il nodo successivo della coda 
//  	Visualizzate il valore del nodo
//  	Qualora il puntatore  al figlio sinistro del nodo non sia NULL
//  		Inserite il figlio sinistro nella coda
//  	Qualora il puntatore al figlio destro del nodo non sia NULL
//  		Inserite il figlio destro nella ccoda  
//
//  Scrivete la funzione levelOrder che esegua una vista per livelli di una albero binario. La funzione dovrà accettare come argomento un puntatore al nodo radice dell'albero. Modificate il programma della Figura 12.19, in modo che utilizzi questa funzione.
//  Confrontate l'output di questa funzione con quelli degli altri algoritmi di visita per verificare che  funzioni correnttamente. (Nota : in questo programma, avrete anche bisogno di modificare e incorporare le funzioni per l'elaborazione  delle code mostrate 
//  nella Figura 12.13)
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30


struct treeNode {
   struct treeNode *leftPtr;
   int data;
   struct treeNode *rightPtr;
};

typedef struct treeNode TREENODE;
typedef TREENODE *TREENODEPTR;

struct codeNode{
   TREENODEPTR h;
   struct codeNode *nextPtr;
};

typedef struct codeNode CODENODE;
typedef CODENODE *CODENODEPTR;

TREENODEPTR dequeue(CODENODEPTR *,CODENODEPTR *);
void enqueue(CODENODEPTR *, CODENODEPTR *, TREENODEPTR);

/*
 Funzione di attraversamento in preordine non ricorsivo: Questa funzione non ricorsiva basata su stack è funzionamente equivalente alla sua versione ricorsiva 

void traverse(link h, void  (*visit) (link))
{
	STACKini(max); STACKpush(h);

	while(!STACKempty())
	{
		(*visit) (h = STACKpop());
		if(h->r != NULL) STACKpush(h->r);
		if(h->l != NULL) STACKpush(h->l);
	}

}


 Cambiando la struttura dati utilizzata per l'attraversamento in preorder (vedi sopra ) da stack a coda , si ottiente un attramento level-order. 

void traverse(link h, void (*visit) (link))
{
	QUEUEinit(max); QUEUEput(h);

	while(!QUEUEempty()){
	(*visit) (h = QUEUEget());
	if(h->l != NULL) QUEUEput(h->l);
	if(h->r != NULL) QUEUEput(h->r);

	}
}

*/

void levelOrder(TREENODEPTR *t){

	CODENODEPTR head = NULL, tail = NULL;
	TREENODEPTR h = NULL;

	enqueue(&head,&tail,*t);    	
	
	while( head != NULL){
		h = dequeue(&head,&tail);
		printf("%3d",h->data);

		if(h->leftPtr != NULL) 
			enqueue(&head,&tail,h->leftPtr);
		if(h->rightPtr != NULL)
		      	enqueue(&head,&tail,h->rightPtr);
		
	}
}


void inOrder(TREENODEPTR);
void preOrder(TREENODEPTR);
void postOrder(TREENODEPTR);

void insertNode(TREENODEPTR *, int);


int main()
{
   srand(time(NULL));

   int i;   
   TREENODEPTR Ptr = NULL;

    /* inserimento valori casuali per l'albero di ricerca binaria */
   printf("\nInizializzazione ...\n");

   for(i = 0; i < 15; i++){
	   insertNode(&Ptr, 1 + rand() % 30);
   }

   printf("\n\n");
   printf("\nVista in Ampiezza\n");   
   levelOrder(&Ptr);
   printf("\n\n");
   printf("\nVista inOrder\n");
   inOrder(Ptr);
   printf("\n\n");
   printf("\nVista postOrder\n");
   postOrder(Ptr);
   printf("\n\n");
   printf("\nVista preOrder\n");
   preOrder(Ptr);
   printf("\n\n");
   
   return 0;
}

void printQueue(CODENODEPTR *head,CODENODEPTR *tail){

	TREENODEPTR t;

	while(head != NULL){
		t = dequeue(head,tail);
		printf("%3d",t->data);
	}
}

void enqueue(CODENODEPTR *head, CODENODEPTR *tail, TREENODEPTR n){
	
	CODENODEPTR new = NULL;

	new = malloc(sizeof(CODENODE));

	if(new != NULL){
		new->h = n;
		new->nextPtr = NULL;

		if(*head == NULL){
			*head = new;
		}else
			(*tail)->nextPtr = new;
			
		*tail = new;
	}else
		printf("\nMemory lack!!!\n");

}

TREENODEPTR  dequeue(CODENODEPTR *head, CODENODEPTR *tail){
   
	CODENODEPTR temp = NULL;
	TREENODEPTR i;	

	i = (*head)->h;
	temp = *head;
	*head = (*head)->nextPtr;

	if(*head == NULL) *tail == NULL;

	free(temp);
	return i;
}

void insertNode(TREENODEPTR *rootPtr, int value)
{

   TREENODEPTR new;

   if(*rootPtr == NULL){
	   
   	new = malloc(sizeof(TREENODE));
	
	if(new != NULL){
		new->data = value;
		new->leftPtr = NULL;
		new->rightPtr = NULL;
		*rootPtr = new;
	}else
		printf("\nMemory lack!!!\n");
   }else{
	   if(value < (*rootPtr)->data)
		   insertNode(&((*rootPtr)->leftPtr),value);
   	   else if(value > (*rootPtr)->data)
		   insertNode(&((*rootPtr)->rightPtr),value);
	   else 
		   printf("\n..dup...\n");
   }	
}
	

void inOrder(TREENODEPTR Ptr){

	if(Ptr != NULL){
		inOrder(Ptr->leftPtr);
		printf("%3d",Ptr->data);
		inOrder(Ptr->rightPtr);
	}
}



void preOrder(TREENODEPTR Ptr){

	if(Ptr != NULL){
		printf("%3d",Ptr->data);
		preOrder(Ptr->leftPtr);
		preOrder(Ptr->rightPtr);
	}
}
void postOrder(TREENODEPTR Ptr){

	if(Ptr != NULL){
		postOrder(Ptr->leftPtr);
		postOrder(Ptr->rightPtr);
		printf("%3d",Ptr->data);
	}
}
