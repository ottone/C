//
//  main.c
//  Exe12.17
//
//  Created by Francesco Parrucci on 30/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
//  Scrivete un programma basato su quello della Figura 12.19 che prenda in input una linea di testo, separi la frase in parole, le inserisca in un albero di ricerca binaria e visualizzi la vista 
//  simmetrica anticipata e differita dell'albero.
//  Suggerimento: leggete la linea di testo e immagazzinatela in un vettore Usate strtok per dividere in parole il testo. Nel momento in cui avrete isolato una parola dovrete creare un nuovo nodo 
//  nell'albero, assegnate il puntatore restituito da strtok al membro string del nuovo nodo e inserirlo nell'albero.
//
//  Create a binary tree and traverse it preorder, inorder, and postorder 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treeNode {
   struct treeNode *leftPtr;
   char *data;
   struct treeNode *rightPtr;
};

typedef struct treeNode TREENODE;
typedef TREENODE *TREENODEPTR;

void insertNode(TREENODEPTR *, char *);
void inOrder(TREENODEPTR);
void preOrder(TREENODEPTR);
void postOrder(TREENODEPTR);

int main()
{
   char vet[80] , *p;
   TREENODEPTR rootPtr = NULL;

    /* insert a phrase */
   printf("\nInserisci una frase: ");
   fgets(vet,80,stdin);

   p = strchr(vet,'\n');
   *p = ' ';

   p = strtok(vet," ");
   insertNode(&rootPtr,p);
   while((p = strtok(NULL," ")) != NULL)
      insertNode(&rootPtr,p);
      

   /* traverse the tree preOrder */
   printf("\n\nThe preOrder traversal is:\n");
   preOrder(rootPtr);

   /* traverse the tree inOrder */
   printf("\n\nThe inOrder traversal is:\n");
   inOrder(rootPtr);

   /* traverse the tree postOrder */
   printf("\n\nThe postOrder traversal is:\n");
   postOrder(rootPtr);
   
   printf("\n\n");
   return 0;
}

void insertNode(TREENODEPTR *treePtr, char *value)
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
      if (strcmp(value,(*treePtr)->data) == -1)
         insertNode(&((*treePtr)->leftPtr), value);
      else if(strcmp(value,(*treePtr)->data) > 0)
         insertNode(&((*treePtr)->rightPtr), value);
      else 
         insertNode(&((*treePtr)->leftPtr),value);
}

void inOrder(TREENODEPTR treePtr)
{
   if (treePtr != NULL) {
      inOrder(treePtr->leftPtr);
      printf("%10s", treePtr->data);
      inOrder(treePtr->rightPtr);
   }
}

void preOrder(TREENODEPTR treePtr)
{
   if (treePtr != NULL) {
      printf("%10s", treePtr->data);
      preOrder(treePtr->leftPtr);
      preOrder(treePtr->rightPtr);
   }
}

void postOrder(TREENODEPTR treePtr)
{
   if (treePtr != NULL) {
      postOrder(treePtr->leftPtr);
      postOrder(treePtr->rightPtr);
      printf("%10s", treePtr->data);
   }
}

