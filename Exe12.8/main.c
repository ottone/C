//
//  main.c
//  Exe12.8
//
//  Created by Francesco Parrucci on 22/07/19.
//  Copyright © 219 Francesco Parrucci. All rights reserved.
//
//  Scrivete un programma che inserisca ordinatamente in una lista concatenata 25 interi casuali compresi tra zero e 100 il programma dovrà calcolare la somma degli interi
//  e la loro media con un valore in virgola mobile.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct listNode{  // self referential structure
	int data;
	struct listNode *nextPtr;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

void insert(LISTNODEPTR *,int c);
void stampa(LISTNODEPTR);
int somma(LISTNODEPTR);

int main(){

	LISTNODEPTR first = NULL;

	srand(time(NULL));

	int i = 0, total = 0;
	float average = 0;

	printf("\nInserimento valori casuali nella lista:");
	while(i < 25){
		insert(&first,(rand() % 100) + 1);
		i++;
	}

	stampa(first);
	
	total = somma(first);

	printf("\nTotale : %d Average = %.2f\n",total,(float) total / 25);

	return 0;
}

void insert(LISTNODEPTR *sPtr, int c)
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


void stampa(LISTNODEPTR list){
	
	char c;
	if(list == NULL)
		printf("\nThe list is Empty\n");
	else{
	putchar('\n');
		while(list != NULL){
			printf("%d ",list->data);
			list = list->nextPtr;
		}
	}

	putchar('\n');
}

int somma(LISTNODEPTR list){
	
	if(list == NULL)
		return 0;
	else	
		return list->data + somma(list->nextPtr);
	
}

