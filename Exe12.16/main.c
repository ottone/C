//
//  main.c
//  Exe12.16
//
//  Created by Francesco Parrucci on 29/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
//  Modificate il programma della Figura 12.19 in modo da consentire l'inserimento di valori duplicati nell'albero binario
//
//
/* Create a binary tree and traverse it preorder, inorder, and postorder */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main()
{
   int i, item;
   TREENODEPTR rootPtr = NULL;

   srand(time(NULL));

   /* insert random values between 1 and 15 in the tree */
   printf("The numbers being placed in the tree are:\n");

   for (i = 1; i <= 10; i++) {
      item = rand() % 15;
      printf("%3d", item);
      insertNode(&rootPtr, item);
   }

   /* traverse the tree preOrder */
   printf("\n\nThe preOrder traversal is:\n");
   preOrder(rootPtr);

   /* traverse the tree inOrder */
   printf("\n\nThe inOrder traversal is:\n");
   inOrder(rootPtr);

   /* traverse the tree postOrder */
   printf("\n\nThe postOrder traversal is:\n");
   postOrder(rootPtr);

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
      if (value <= (*treePtr)->data)
         insertNode(&((*treePtr)->leftPtr), value);
      else// (value > (*treePtr)->data)
         insertNode(&((*treePtr)->rightPtr), value);
         //if (value > (*treePtr)->data)
           // insertNode(&((*treePtr)->rightPtr), value);
        // else 
          //  printf("dup");
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

