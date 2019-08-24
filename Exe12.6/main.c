//
//  main.c
//  Exe12.6
//
//  Created by Francesco Parrucci on 18/07/19.
//  Copyright © 219 Francesco Parrucci. All rights reserved.
//
//
//
//  Scrivete un programma che colleghi due liste concatenate di caratteri. Il programma dovrà includere la funzione concatenate, che prenda come argomenti i puntatori a
//  entrambe le liste e concateni la seconda alla prima

#include <stdio.h>
#include <stdlib.h>

struct listNode{  // self referential structure
	char data;
	struct listNode *nextPtr;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

void insert(LISTNODEPTR *,char c);
void stampa(LISTNODEPTR);
void unionlist(LISTNODEPTR *,LISTNODEPTR , LISTNODEPTR );

int main(){

	//char c, s;


	LISTNODEPTR first = NULL, second = NULL, third = NULL;

	char c;

	printf("\nDigita un carattere per la prima lista EOF per terminare:");
	while((c = getchar()) != EOF){
		getchar();
		insert(&first,c);
		printf("\nDigita un carattere per la prima lista EOF per terminare:");
	}

	clearerr(stdin);
	putchar('\n');	
	
	printf("\nDigita un carattere per la seconda lista EOF per terminare:");
	while((c = getchar()) != EOF){
		getchar();
		insert(&second,c);
		printf("\nDigita un carattere per la seconda lista EOF per terminare:");
	}

	unionlist(&third,first,second);

	stampa(first);

	stampa(second);
	
	stampa(third);

	return 0;
}

void insert(LISTNODEPTR *sPtr, char c)
{
    LISTNODEPTR newPtr ,currentPtr, previousPtr;

    newPtr = malloc(sizeof(LISTNODE));

    if(newPtr == NULL)
	    printf("\nImpossibile allocare memoria per il nuovo dato %c\n",c);
    else{
		newPtr->data = c;
		newPtr->nextPtr = NULL;

		previousPtr = NULL;
		currentPtr = *sPtr;

	
		while(currentPtr != NULL && currentPtr->data < c){
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
			}

		if(previousPtr == NULL){
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}else{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}

    }
}

void unionlist(LISTNODEPTR *third, LISTNODEPTR first, LISTNODEPTR second)
{
	LISTNODEPTR newPtr;

	while(first != NULL){
		insert(&newPtr,first->data);
		first = first->nextPtr;
	}


	while(second != NULL){
		insert(&newPtr,second->data);
		second = second->nextPtr;
	}

	*third = newPtr;
}


void stampa(LISTNODEPTR list){
	
	char c;
	if(list == NULL)
		printf("\nThe list is Empty\n");
	else{
	putchar('\n');
		while(list != NULL){
			putchar(list->data);
			list = list->nextPtr;
		}
	}

	putchar('\n');
}
