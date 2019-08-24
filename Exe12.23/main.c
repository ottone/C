//
//  main.c
//  Exe12.23
//
//  Created by Francesco Parrucci on 04/08/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  (Ricerca in un albero binario). Scrivete la funzione binaryTreeSearch che tenti di individuare un dato valore all'interno di un albero di ricerca binaria. La funzione dovrà accettare come argomenti un puntatore 
//  al nodo radice dell'albero di ricerca e una chiave di ricerca da individuare. Qualora il nodo contenente la chiave di ricerca 
//  stato individuato, la funzione dovrà restituire un puntatore a quel nodo. in caso contrario,  la funzione dovrà restituire NULL.
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

void inOrder(TREENODEPTR);
void insertNode(TREENODEPTR *, int);
TREENODEPTR searchNode(TREENODEPTR ,int);
void deleteNode(TREENODEPTR *, int);
int main()
{
   srand(time(NULL));
   int i, c;   
   TREENODEPTR Ptr = NULL, search;

    /* inserimento valori casuali per l'albero di ricerca binaria */
   printf("\nInizializzazione albero...");
   for(i = 0; i < 15; i++){
	   c = 1 + rand() % 30;
	   insertNode(&Ptr, c);
   }
   inOrder(Ptr);
   printf("\nChe valore cerchi ? ");
   scanf("%d",&i);
   printf("\n\n");
   search = searchNode(Ptr,i);
   if(search != NULL)
	   printf("\nValore %d trovato\n",search->data);
   printf("\n\n");
   return 0;
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

TREENODEPTR searchNode(TREENODEPTR rootPtr,int value){
	
	if(rootPtr->data == value)
		return rootPtr;
	else if(value > rootPtr->data && rootPtr->rightPtr != NULL)
		searchNode(rootPtr->rightPtr,value);
	else if(value < rootPtr->data && rootPtr->leftPtr != NULL)
		searchNode(rootPtr->leftPtr,value);
	else	
		return NULL;

}

void deleteNode(TREENODEPTR *rootPtr,int value){

	TREENODEPTR father = NULL , son = *rootPtr, temp = NULL, ptr1 = NULL, ptr2 = NULL;
	int direction; // 0 left 1 right	

		

		while(son != NULL && son->data != value){
			father = son;
			if(value > son->data){
		        son = son->rightPtr;
			direction = 1;	
			}else{
			son = son->leftPtr;
			direction = 0;
			}
		}
	
		
	if(son == NULL)
		printf("\nPuntatore non trovato\n");
	else	
		printf("\nValore del puntatore %p --> %d\n",son,son->data);


	if(son->leftPtr == NULL && son->rightPtr == NULL){ // Nodo foglia
		printf("\nElimino un nodo foglia del nodo %d\n",father->data);
		if(father->data < son->data)
			father->rightPtr = NULL;
		else
			father->leftPtr = NULL;
		free(son);
	}else if(son->leftPtr == NULL && son->rightPtr != NULL){ // Nodo con figlio
		printf("\nElimino un nodo con figlio destro\n");
		temp = son;
		if(father->data < son->data)
			father->rightPtr = son->rightPtr;
		else
			father->leftPtr = son->rightPtr;
		free(son);
	}else if(son->leftPtr != NULL && son->rightPtr == NULL){ // Nodo con figlio
		printf("\nElimino un nodo con figlio sinistro\n");
		temp = son;
		if(father->data < son->data)
			father->rightPtr = son->leftPtr;
		else
			father->leftPtr = son->leftPtr;
		free(son);
	}else{ // Nodo con figli
		printf("\nElimino un nodo con due figli %d ",son->data);		
		
		ptr1 = son->leftPtr;
		while(ptr1->rightPtr != NULL){
		       	ptr2 = ptr1;
			ptr1 = ptr1->rightPtr;
		}	
		
		printf("Il sostituto è %d ",ptr1->data);

		if(ptr1->leftPtr == NULL && ptr1->rightPtr == NULL){  	// Nodo foglia
			printf(" nodo foglia\n");
			if(ptr2 == NULL){
				printf("\nIl padre del sostituto è son\n");
				
				if(father != NULL){
					printf("Valore di father : %d",father->data);
					if(direction == 1)
						father->rightPtr = son->leftPtr;
					else
						father->leftPtr = son->leftPtr;
				}else
					//(*rootPtr) = ptr1;
				
				ptr1->leftPtr = son->leftPtr;
				ptr1->rightPtr = (son->leftPtr)->rightPtr;
									
			}else{
				printf("\nIl padre del sostituto è %d\n",ptr2->data);

				if(father != NULL){
					printf("Valore di father : %d",father->data);
				if(direction == 1)
					father->rightPtr = ptr2->rightPtr;
				else
					father->leftPtr = ptr2->rightPtr;
				}
					ptr1->leftPtr = son->leftPtr;
					ptr1->rightPtr = son->rightPtr;
					ptr2->rightPtr = NULL;
			}

				if(father == NULL) (*rootPtr) = ptr1;
				son->leftPtr = NULL;
				son->rightPtr = NULL;
				free(son);
		}else{ 							// Nodo con figlio
			printf(" nodo con figlio\n");
			if(ptr2 == NULL){
				printf("\nIl padre del sostituto è son\n");
				if(father != NULL){
						printf("Valore di father : %d",father->data);
					if(direction == 1)
						father->rightPtr = son->leftPtr;
					else
						father->leftPtr = son->leftPtr;
				}else
					//(*rootPtr) = ptr1;
				
				(ptr1->leftPtr)->rightPtr = son->rightPtr;
				(ptr1->leftPtr)->rightPtr = (son->rightPtr)->rightPtr;
				//(ptr1->rightPtr)->leftPtr = (son->rightPtr)->rightPtr;
				ptr1->rightPtr = (son->rightPtr)->leftPtr;
				
				
			}else{
				if(father != NULL){
					printf("Valore di father : %d",father->data);
				if(direction == 1)
					father->rightPtr = ptr2->rightPtr;
				else
					father->leftPtr = ptr2->rightPtr;
			
					ptr1->rightPtr = son->rightPtr;
					ptr1->leftPtr = son->leftPtr;
					ptr2->rightPtr = ptr1->leftPtr;
				}else{
					ptr1->rightPtr = son->rightPtr;
					ptr1->leftPtr = ptr1->leftPtr;
					ptr2->rightPtr = ptr1->leftPtr;
				}
			}
			son->leftPtr = NULL;
			son->rightPtr = NULL;
			free(son);
			
		}
	}
	
}
