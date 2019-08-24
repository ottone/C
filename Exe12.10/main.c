//
//  main.c
//  Exe12.10
//
//  Created by Francesco Parrucci on 23/07/19.
//  Copyright © 219 Francesco Parrucci. All rights reserved.
//
//  Scrivete un programma che prenda in input una linea di testo, e uilizzi una pila per visualizzare la linea in ordine inverso.
//
//

#include <stdio.h>
#include <stdlib.h>


struct stackNode{  // self referential structure
	char data;
	struct stackNode *nextPtr;
};

typedef struct stackNode STACKNODE;
typedef STACKNODE *STACKNODEPTR;

void push(STACKNODEPTR *,char c);
char pop(STACKNODEPTR *);

int main(){

	STACKNODEPTR first = NULL;
	char v[80], c;
	int i = 0;

	printf("\nInserisci una frase : ");
	scanf("%s",v);
	
	while(v[i] != '\0') push(&first,v[i++]);


	printf("\nEsfiltrazione caratteri dalla pila: \n");
	
	i = 0;
	while(first  != NULL){
		c = pop(&first);
		putchar(c);
	}
	return 0;
}

void push(STACKNODEPTR *stack,char c){
	
	STACKNODEPTR newPtr;

	newPtr = malloc(sizeof(STACKNODE));

	if(newPtr == NULL)
		printf("\nMemory not available!!!\n");
	else{
		newPtr->data = c;
		newPtr->nextPtr = *stack;
		*stack = newPtr;
		
	}
}

char pop(STACKNODEPTR *stack){
	
	STACKNODEPTR temp;
	char c;	
	
	temp = *stack;
	if(temp == NULL)
		printf("\nThe stack is Empty!!!\n");
	else{
		temp = *stack;
		c = (*stack)->data;
		*stack = (*stack)->nextPtr;
		free(temp);
	}

	return c;

}
