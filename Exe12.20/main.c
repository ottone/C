//
//  main.c
//  Exe12.20
//
//  Created by Francesco Parrucci on 30/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  (Visualizzazione ricorsiva di una lista in ordine inverso) Scrivete una funzione printListBackwards che visualizzi in modo ricorsivo e in ordine inverso gli elementi 
//  di una lista Usate la vostra funzione in un programma di prova che crei una lista ordinata di interi e la visualizzi in ordine inverso.
//
//  Create a binary tree and traverse it preorder, inorder, and postorder 
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30

struct listNode {
   int data;
   struct listNode *nextPtr;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

void printList(LISTNODEPTR);
void insertNode(LISTNODEPTR *, int);
void printListBackwards(LISTNODEPTR);

int main()
{
   srand(time(NULL));
   int i;   
   LISTNODEPTR Ptr = NULL;

    /* inserimento valori casuali per l'albero di ricerca binaria */
   printf("\nInizializzazione lista...");
   for(i = 0; i < SIZE; i++){
	   insertNode(&Ptr, i);
   }
   printList(Ptr);

   printf("\n\n");
   
   printListBackwards(Ptr);
    
   printf("\n\n");
   return 0;
}

void insertNode(LISTNODEPTR *Ptr, int value)
{
   LISTNODEPTR previousPtr , currentPtr , newPtr;

   newPtr = malloc(sizeof(LISTNODE));

   if(newPtr != NULL){
	
	newPtr->nextPtr = NULL;
	newPtr->data = value;

	currentPtr = *Ptr;
	previousPtr = NULL;

	while(currentPtr != NULL && value > currentPtr->data){
		previousPtr = currentPtr;		// walk to...
		currentPtr = currentPtr->nextPtr;	// ...next node
	}

	if(previousPtr == NULL){
		newPtr->nextPtr = *Ptr;
		*Ptr = newPtr;
	}else{
		previousPtr->nextPtr = newPtr;
		newPtr->nextPtr = currentPtr;
	}
   }else
         printf("%d not inserted. No memory available.\n",value);
}


void printList(LISTNODEPTR Ptr){
	
	if(Ptr == NULL)
		printf("\nThe list is Empty!!!\n");
	else{
		printf("\nThe list is ...\n");
		while(Ptr != NULL){
			printf("%3d",Ptr->data);
			Ptr = Ptr->nextPtr;
		}
	}	
}

void printListBackwards(LISTNODEPTR Ptr){

	if(Ptr == NULL)
		;
	else{
		printListBackwards(Ptr->nextPtr);
		printf("%3d",Ptr->data);
	}

}
