//
//  main.c
//  Exe12.11
//
//  Created by Francesco Parrucci on 23/07/19.
//  Copyright © 219 Francesco Parrucci. All rights reserved.
//
//  Scrivete un programma che usi una pila per determinare se una stringa è palindroma (ovverosia, se possa essere letta allo stesso modo in entrambi i sensi). Il programma
//  dovrà ignorare gli spazie la punteggiatura.
//


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{  // self referential structure
	char data;
	struct Node *nextPtr;
};

typedef struct Node NODE;
typedef NODE *NODEPTR;

void push(NODEPTR *,char c);
char pop(NODEPTR *);
void enqueue(NODEPTR *, NODEPTR *, char);
char dequeue(NODEPTR *, NODEPTR *);

int main(){

	NODEPTR stack = NULL, head = NULL, tail = NULL;

	int i = 0, bool = 1;
	char v[80];

	printf("\nInserimento di una stringa:");
  	fgets(v,80,stdin);

	while(v[i] != '\0'){
		if(isalpha(v[i])){ 
			push(&stack,v[i]);
			enqueue(&head,&tail,v[i]);
		}
		i++;
	}

	while(stack != NULL && &head != &tail){
		if(pop(&stack) != dequeue(&head,&tail)) bool = 0;
	}

	if(bool == 1)
		printf("\nStringa palindroma\n");
	else
		printf("\nStringa non palindroma\n");

	return 0;
}

void enqueue(NODEPTR *head, NODEPTR *tail, char c){
	
	NODEPTR newPtr;

	newPtr = malloc(sizeof(NODE));

	if(newPtr == NULL)
		printf("\nMemory not available!!!\n");
	else{
		newPtr->data = c;
		newPtr->nextPtr = NULL;

		if((*head) == NULL)
		  *head = newPtr;
		else
		  (*tail)->nextPtr = newPtr;

		*tail = newPtr;
	
	}
}


char dequeue(NODEPTR *head, NODEPTR *tail){
	
	char c;
	NODEPTR temp;

	c = (*head)->data;
	temp = *head;
	*head = (*head)->nextPtr;

	if(*head == NULL) 
	  *tail = NULL;

	free(temp);
	return c;

}


char pop(NODEPTR *sPtr){
	
	NODEPTR temp;
	char c;

	temp = *sPtr;
	c = temp->data;
	*sPtr = temp->nextPtr;
	free(temp);

	return c;
}

void push(NODEPTR *sPtr, char c)
{
    NODEPTR newPtr;

    newPtr = malloc(sizeof(NODE));

    if(newPtr == NULL)
	    printf("\nImpossibile allocare memoria per il nuovo dato %c\n",c);
    else{
		newPtr->data = c;
		newPtr->nextPtr = *sPtr;
		*sPtr = newPtr;
    }
}
