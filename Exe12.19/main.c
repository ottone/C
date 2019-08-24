//
//  main.c
//  Exe12.19
//
//  Created by Francesco Parrucci on 30/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
//  Scrivete una funzione depth che riceva un albero binario e determini di quanti livelli sia composto.
//
//  Create a binary tree and traverse it preorder, inorder, and postorder 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 30

struct treeNode {
   struct treeNode *leftPtr;
   int data;
   struct treeNode *rightPtr;
};

typedef struct treeNode TREENODE;
typedef TREENODE *TREENODEPTR;

void insertNode(TREENODEPTR *, int);
void inOrder(TREENODEPTR);
void preOrder(TREENODEPTR);
void postOrder(TREENODEPTR);
int dup(int [],int);
void ShellSort(int a[], int l, int r);
int depth(TREENODEPTR);
int power(int, int);

int main()
{
   srand(time(NULL));

   int i, c, flag, data, v1[SIZE], v2[SIZE] = {0};
   TREENODEPTR rootPtr = NULL;
   unsigned int t;

    /* inserimento valori casuali per l'albero di ricerca binaria */
   printf("\nValori da inserire :");
   for(i = 0; i < SIZE; i++)
	   insertNode(&rootPtr, 1 + (rand() % SIZE));

    
   i = 1;
   c = depth(rootPtr);   
   data = power(i,c);
   printf("\nNumero elementi dell'albero: %d\n",c);
   printf("\nNumero livelli albero: %d\n",data);

   printf("\nStampa dell'albero:\n");
   
   inOrder(rootPtr);


   /* traverse the tree inOrder */
   // printf("\n\nThe inOrder traversal is:\n");
   // inOrder(rootPtr);

   /* traverse the tree postOrder */
   //printf("\n\nThe postOrder traversal is:\n");
   //postOrder(rootPtr);
   
   printf("\n\n");
   return 0;
}

void insertNode(TREENODEPTR *treePtr, int value)
{
   if (*treePtr == NULL) {   /* *treePtr is NULL */
      *treePtr = malloc(sizeof(TREENODE));

      if (*treePtr != NULL) {
         (*treePtr)->data = value;
         (*treePtr)->leftPtr = NULL;
         (*treePtr)->rightPtr = NULL;
      }
      else
         printf("%d not inserted. No memory available.\n", 
                value);

   }
   else
      if (value < (*treePtr)->data)
         insertNode(&((*treePtr)->leftPtr), value);
      else if(value > (*treePtr)->data)
         insertNode(&((*treePtr)->rightPtr), value);
      else 
         printf("\n...dup...\n");
}

void inOrder(TREENODEPTR treePtr)
{
   if (treePtr != NULL) {
      inOrder(treePtr->leftPtr);
      printf("%3d", treePtr->data);
      inOrder(treePtr->rightPtr);
   }
}

void preOrder(TREENODEPTR treePtr)
{
   if (treePtr != NULL) {
      printf("%3d", treePtr->data);
      preOrder(treePtr->leftPtr);
      preOrder(treePtr->rightPtr);
   }
}

void postOrder(TREENODEPTR treePtr)
{
   if (treePtr != NULL) {
      postOrder(treePtr->leftPtr);
      postOrder(treePtr->rightPtr);
      printf("%3d", treePtr->data);
   }
}

int dup(int v[],int value){
	int i;

	for (i = 0; i < SIZE; i++)
		if(v[i] == value) return  1;

}

void ShellSort(int a[], int l, int r){
	
	int i, j, h, temp;

	for(h = (r-l)/2; h > 0; h /= 2)
		for(i = l+h; i <= r; i++)
			for(j = i-h; j < i; j++){
				if(a[j] > a[i]){
					temp = a[j];
					a[j] = a[i];
					a[i] = temp;
				}else
					continue;
			}
}

int  depth(TREENODEPTR treePtr){
	
	if(treePtr != NULL){
		return  1 + depth(treePtr->leftPtr) + depth(treePtr->rightPtr);
	}else 
		return 0;
	
	
	
}

int power(int i , int c){

	int d = 0;

	while(i < c){
		i <<= 1;
		d++;
	}

	return d;
}
