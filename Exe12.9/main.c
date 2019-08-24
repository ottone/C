//
//  main.c
//  Exe12.9
//
//  Created by Francesco Parrucci on 23/07/19.
//  Copyright © 219 Francesco Parrucci. All rights reserved.
//
//  Scrivete un programma che crei una lista concatenata di 10 caratteri ,in seguito, create una copia della lista con gli elementi in ordine inverso
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct listNode{  // self referential structure
	char data;
	struct listNode *nextPtr;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

void insert(LISTNODEPTR *,char c);
void stampa(LISTNODEPTR);
void reverse(LISTNODEPTR ,LISTNODEPTR *);
void inv(LISTNODEPTR *,char c);

int main(){

	LISTNODEPTR first = NULL, second = NULL;

	int i = 0;
	srand(time(NULL));

	printf("\nInserimento caratteri casuali nella lista:");
	while(i < 10){
		insert(&first,(rand() % 25) + 97);
		i++;
	}

	stampa(first);
	
	reverse(first, &second);
	
	stampa(second);

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


void stampa(LISTNODEPTR list){
	
	char c;
	if(list == NULL)
		printf("\nThe list is Empty\n");
	else{
	putchar('\n');
		while(list != NULL){
			printf("%c ",list->data);
			list = list->nextPtr;
		}
	}

	putchar('\n');
}

void inv(LISTNODEPTR *sPtr, char c){

	LISTNODEPTR newPtr , previousPtr , currentPtr ;
	
	newPtr = malloc(sizeof(LISTNODE));

	if(newPtr != NULL){

		newPtr->data = c;
		newPtr->nextPtr = NULL;

		currentPtr = *sPtr;
		previousPtr = NULL;

		while(currentPtr != NULL && currentPtr->data > c){
		previousPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;		
		}
	
		if(previousPtr == NULL){
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}else{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;}
	}else
		printf("\nMemory not available!!!\n");
}

void reverse(LISTNODEPTR first ,LISTNODEPTR *second){


	if(first == NULL)
		printf("\nDevi riempire la prima lista!!!\n");
	else{
		while(first != NULL){
			inv(second, first->data);
			first = first->nextPtr;
	
		}
	}
}
