//
//  main.c
//  Exe12.21
//
//  Created by Francesco Parrucci on 30/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  (Ricerca ricorsiva in una lista) Scrivete una funzione searchList che cerchi in modo ricorsivo un dato valore all'interno di una lista concatenata. La funzione
//  dovrà restituire un puntatore al valore, qualora l'abbia ritrovato, o NULL in caso contrario. Usate la vostra funzione in un programma di prova che crei una lista
//  di interi. Il programma dovrà richiedere all'utente il valore da individuare nella lista.
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
LISTNODEPTR searchList(LISTNODEPTR, int);

int main()
{
   srand(time(NULL));
   int i;   
   LISTNODEPTR Ptr = NULL, number = NULL;

    /* inserimento valori casuali per l'albero di ricerca binaria */
   printf("\nInizializzazione lista...");
   for(i = 0; i < SIZE; i++){
	   insertNode(&Ptr, i);
   }
   printList(Ptr);

   
   printf("\n\nQuale numero cerchi? ");
   scanf("%d",&i);
   if((number = searchList(Ptr,i)) != NULL) 
	   printf("\nTrovato!!!\n");
   else
	   printf("\nNo match\n");
   

    
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

LISTNODEPTR searchList(LISTNODEPTR list, int value){

		if(list == NULL)
			return NULL;
		else if(list->data == value)
			return list;
		else
			searchList(list->nextPtr, value);

}
