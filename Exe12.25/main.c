//
//  main.c
//  Exe12.25
//
//  Created by Francesco Parrucci on 05/08/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
// 
//  (Visualizzate gli alberi) Scrivete una funzione riscorsiva outputTree che visualizzi sullo schermo un albero binario. La funzione dovrà visualizzare l'albero una
//  riga per volta, con la cima (la radice) posta alla sinistra dello schermo e la base (le foglie) sistemata a destra dello stesso. Ogni riga sarà visualizzata
//  verticalmente. Per esempio, l'albero mostrato nella Figura 12.22 sarà visualizzato come segue:
//
//  			99
//  		97
//  			92
//  	83
//  			72
//  		71
// 			69
//  49
//  			44
//  		40
//  			32
//  	28
//  			19
//  		18
//  			11
//
//
//  Osservate che la foglia piu a destra compare in cima al'output, nella colonna piu a destra, mentre il nodo radice compare a sinistra dell'output. Ogni colonna 
//  dell'output incomincia cinque spazi piu a destra di qella precedente. La funzione outputTree dovrà ricevere come argomenti un puntatore al nodo radice dell'
//  albero e l'intero totalSpaces. Questa variabile indicherà il numero di spazi che dovranno precedere il valore da visualizzare e dovrà cominciare con zero, cosi
//  che il nodo radice sia visualizzato a sinistra dello schermo. Per visualizzare l'albero, la funzione userà una versione modificata della visita simmetrica:
//  essa incomincierà con il nodo piu a destra dell'albero e proseguirà tornando indietro a sinistra. Lalgoritmo sarà dunque il seguente:
//
//  Fintanto che il puntatore al nodo corrente non sia NULL
//  	chiamate in modo ricorsivo outputTree con il sottoalbero destro del nodo corrente e totalSpaces + 5
//  	Usate una struttura for per contare da 1 a totalSpaces e visualizzare gli spazi
//  	Visualizzate il valore del nodo corrente
//  	Impostate il puntatore al nodo corrente in modo che faccia riferimento al suo sottoalbero sinistro
//  	Incrementate totalSpaces di 5
//
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
void outputTree(TREENODEPTR, int);

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
   printf("\nVista albero\n");
   outputTree(Ptr,1);
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


void outputTree(TREENODEPTR t, int totalSpaces){

	int i;

	if(t != NULL){
		outputTree(t->rightPtr,totalSpaces + 5);
		for(i = 1 ; i < totalSpaces; i++) putchar(' ');
		printf("%d\n",t->data);
		outputTree(t->leftPtr,totalSpaces + 5);
	}
}
