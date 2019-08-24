//
//  main.c
//  Exe12.22
//
//  Created by Francesco Parrucci on 31/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  (Rimozione da un albero binario) In questo esercizio, affronteremo la rimozione degli elementi dagli alberi di ricerca binaria. L'algoritmo di rimozione non è cosi
//  semplice come quello di inserimento . Durante l'eliminazione di un elemento, ci si potrebbe imbattere in tre casi: l'elemento è contenuto in un nodo foglia 
//  (ovverosia, non ha figli ) , oppure in un nodo che a un figlio , o in un nodo che ha due figli.
//
//  Qualora l'elemento da eliminare sia contenuto in una foglia, questo sarà rimosso e il puntatore del nodo padre sarà impostato a NULL.
//
//  Qualora l'elemento da eliminare sia contenuto in un nodo che abbia un figlio, il puntatore del padre sarà impostato in modo da fare riferimento al nodo figlio, 
//  mentre quello che contiene i dati sarà eliminato.Ciò significa che, all'interno dell'albero, il nodo figlio assumerà il posto di quello rimosso.
//
//  L'ultimo caso è il piu difficile. Qualora si elimini uno che abbia due figli, un altro nodo dell'albero dovrà assumere il suo posto. Tuttavia, il puntatore del 
//  nodo padre non potrà semplicemente essere impostato in modo da fare riferimento a uno dei figli di quello da eliminare. Ciò perchè, nella maggior parte dei casi
//  , l'albero di ricerca binaria risultante non si manterrebbe fedele alla sua caratteristica principale: I valori di ogni sottoalbero sinistro dell'albero sono
//  inferiori a quello del nodo padre, mentre quelli di ogni sottoalbero destro dell'albero sono maggiori di quello del nodo padre.
//  Quale nodo dovrà essere usato come nodo sostitutivo per mantenere questa caratteristica? 
//  Potrà essere il nodo contenente il valore più grande dell'albero che sia maggiore di quello del nodo eliminato. Consideriamo il nodo con il valore inferiore. In 
//  un albero di ricerca binaria, il valore più grande inferiore a quello di un padre sarà sistemato nel sottoalbero sinistro del nodo padre, e sarà sicuramente 
//  contenuto nel nodo all'estremità destra del sottoalbero. Troveremo il suddetto nodo scendendo nel sottoalbero sinistro del padre e andando sempre a destra, 
//  fintanto che il puntatore al figlio destro del nodo corrente non sarà NULL.
//  A questo punto, staremo puntando al nodo di sostituzione che potrà essere una foglia, o un nodo con un solo figlio alla sua sinistra.
//
//  Qualora il nodo di sostituzione sia una foglia, i passi per eseguire l'eliminzaione saranno i seguenti:
//
//  1) Salvate il puntatore al nodo da eliminare in una variabile temporanea di tipo puntatore: questo puntatore sarà usato per liberare la memoria allocata dinamica
//     mente
//  2) Impostate il puntatore del padre del nodo da eliminare in modo che faccia riferimento al nodo di sostituzione.
//
//  3) Impostate a NULL il puntatore al sottoalbero destro nel padre del nodo di sostituzione.
//  4) Impostate il puntatore al sottoalbero destro (sinistro) del nodo di sostituzione in modo che faccia riferimento al sottoalbero destro (sinistro) del nodo da
//     eliminare
//
//  5) Eliminare il nodo puntato dalla variabile temporanea di tipo puntatore.
//
//  Per eseguire l'eliminazione nel caso di un nodo di sostituzione che abbia un figlio sinistro, si effettueranno delle operaizoni simili a quelle effettuate nel
//  caso di un nodo di sostituzione senza figli, ma l'algoritmo dovrà spostare anche il figlio nella posizione attualmente occupata dal nodo di sostituzione all'
//  interno dell'albero. Qualora quello di sostituzione sia un nodo con un figlio a sinistra, i passi per eseguire l'eliminazione saranno i seguenti:
//
//  1) Salvate il puntatore al nodo da eliminare in una variabile temporanea di tipo puntatore.
//  2) Impostare il puntatore del padre del nodo da eliminare in modo che faccia riferimento a lnodo di sostituzione.
//  3) Impostare il puntatore al sottoalbero destro contenuto nel padre del nodo di sostituzione, in modo che faccia riferimento al figlio sinistro del nodo di 
//     sostituzione
//  4) Impostate il puntatore al sottoalbero destro (sinistro) del nodo di sostituzione in modo che faccia riferimento al sottoalbero destro (sinistro) del nodo
//     da eliminare
//  5) Eliminate il nodo puntato dalla variabile temporanea di tipo puntatore.
//
//  Scrivete la funzione deleteNode che accetti come suoi argomenti un puntatore al nodo radice dell'albero e il valore da eliminare. La funzione dovrà individuare
//  all'interno dell'albero il nodo contenente il valore da eliminare, e usare gli algoritmi discussi in questo esercizio per rimuovere il nodo.
//  Qualora il valore non sia stato ritrovato nell'albero, la funzione dovrà visualizzare un messaggio che indichi se il valore sia stato eiminato o no. Modificate
//  il programma della Figura 12.19, in modo che usi questa funzione. Dopo aver eliminato un elemento, richiamate le funzioni di vista inOrder, preOrder e postOrder
//  per confermare che l'operazione di rimozione sia stata eseguita correttamente.
//
//  Create a binary tree and traverse it preorder, inorder, and postorder 
 
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
TREENODEPTR searchNode(TREENODEPTR *,int);
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
	   printf("\n%d inserito premi invio per continuare",c);
   }
   inOrder(Ptr);
   printf("\nChe valore cerchi ? ");
   scanf("%d",&i);
   deleteNode(&Ptr,i);
   printf("\n\n");
   inOrder(Ptr);
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

TREENODEPTR searchNode(TREENODEPTR *rootPtr,int value){
	
	if((*rootPtr)->data == value)
		return *rootPtr;
	else if(value > (*rootPtr)->data)
		searchNode(&((*rootPtr)->rightPtr),value);
	else if(value < (*rootPtr)->data)
		searchNode(&((*rootPtr)->leftPtr),value);
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
