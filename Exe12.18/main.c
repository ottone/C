//
//  main.c
//  Exe12.18
//
//  Created by Francesco Parrucci on 30/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
//  In questo capitolo, abbiamo visto che l'eliminazione dei duplicati è semplice, qualora si stia creando un albero di ricerca binaria. Descrivete in che modo eseguireste l'eliminazione dei duplicati
//  usando sotanto un vettore a una dimensione. Confrontate le prestazioni dell'operazione di eliminazione
//
//  Create a binary tree and traverse it preorder, inorder, and postorder 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 10

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

int main()
{
   int i, c, flag, data, v1[SIZE], v2[SIZE] = {0};
   TREENODEPTR rootPtr = NULL;
   unsigned int t;

    /* inserimento valori casuali per l'albero di ricerca binaria */
   printf("\nValori da inserire :");
   for(i = 0; i < SIZE; i++)
	   v1[i] = 1 + (rand() % SIZE);

   printf("\nInserimento valori nell'albero di ricerca binaria...");
   t = time(0);
   for(i = 0; i < SIZE; i++)
      insertNode(&rootPtr,v1[i]);
   t -= time(0);
      
   inOrder(rootPtr);
   printf("\nTempo necessario per inserire valori non duplicati nell'albero di ricerca binaria...%u\n",t);

   printf("\nInserimento valori nel vettore...");
   t = time(0);
   
   for(i = 0 , c = 0; i < SIZE; i++)
		if(dup(v2,v1[i]) == 0) v2[i] = v1[i];

   		ShellSort(v2,0,SIZE -1);
   t -= time(0);

   printf("\nTempo necessario per inserire valori non duplicati nell'albero di ricerca binaria...%u\n",t);
   
   for(i = 0; i < SIZE; i++)
	   if(v2[i] != 0) printf("%3d",v2[i]);
   /* traverse the tree preOrder */
   //printf("\n\nThe preOrder traversal is:\n");
   //preOrder(rootPtr);

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
