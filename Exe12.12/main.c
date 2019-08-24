//
//  main.c
//  Exe12.12
//
//  Created by Francesco Parrucci on 24/07/19.
//  Copyright © 219 Francesco Parrucci. All rights reserved.
//  
//  Le pile sono usate dai compilatori come supporto per il processo di valutazione delle espressioni e di generazione del codice in linguaggio macchina. In questo modo e 
//  nel prossimo esercizio, esamineremo con cura il modo in cui i compilatori valutano delle espressioni aritmetiche che consistano solamente di costanti, operatori e 
//  parentesi. 
//  Gli esseri umani scrivono generalmente delle espressioni come 3 + 4 e 7 / 9, in cui l'operatore (+ o / , in questo caso) è scritto tra i suoi operandi, ovverosia in
//  notazione infissa. I computer "preferiscono" invece la notazione polacca inversa, con l'operatore scritto a destra dei suoi due operandi. con la notazione polacca 
//  inversa, le due precedenti espressioni infisse apparirebbero rispettivamente come 3 4 + e 7 9 /.
//  Per valutare un'espressione in notazione infissa complessa, il compilatore la convertirà prima nella notazione polacca inversa e quindi la valuterà in questa sua 
//  nuova versione. Ogniuno di questi algoritmi richiede soltanto un singolo passaggio da sinistra a destra sull'espressione. Ogni algoritmo utilizza una pila per 
//  supportare la sua attività, anche se in ognuno di essi la pila è usata per uno scopo diverso. In questo esercizio scriverete una versione C dell'algoritmo di
//  conversione da notazione infissa a notazione polacca inversa. Nel prossimo esercizio, scriverete una versione C dell'algoritmo di valutazione di un'espressione in 
//  notazione polacca inversa.
//  Scrivete un programma che converta un'ordinaria espressione aritmetica in notazione infissa (supponete che ne sia stata immessa una valida), formata da interi di una 
//  sola cifra come (6 + 2) * 5 - 8 / 4
//  in un'espressione in notazione polacca inversa. La versione polacca inversa della precendente espressione in notazione infissa è 6 2 + 5 * 8 4 / - 
//  Il programma dovrà leggere l'espressione e immagazzinarla nel vettore di caratteri infix e, in seguito, utilizzare la versione modificata delle funzioni per la 
//  gestione di una pila implementate in questo capitolo, per aiutare a creare l'espressione in notazione polacca inversa nel vettore postfix. L'algoritmo per creare
//  un'espressione in notazione polacca inversa è il seguente:
//
//  1) Inserire nella pila una parentesi aperta '(';
//  2) Accodare alla fine di infix una parentesi chiusa '(',
//  3) Fintanto che la pila non è vuota, leggete infix da sinistra a destra ed eseguite le seguenti operaizoni:
//
//  	Nel caso in cui il carattere corrente di infix sia un numero, copiatelo nell'elemento successivo di postfix.
//  	Nel caso in cui il carattere corrente di infix sia una parentesi aperta, inseritela nella pila
//  	Nel caso in cui il carattere corrente di infix sia un operatore,
//  			Estraete gli operatori ( se c'é ne sono ) dalla testa della pila, fintanto che abbiano una priorità maggiore o uguale a quella dell'operatore
//  			corrente , e inseriteli in postfix.
//  			Inserite nella pila il carattere corrente in infix.
//  	Nel caso in cui il carattere corrente di infix sia una perentesi chiusa, 
//  			Estrarre gli operatori dalla testa della pila e inseriteli in postfix, finchè non ci sarà una parentesi aperta sulla cima della pila.
//  			Estraete (ed eliminate) la parentesi aperta dalla pila.
//
//  In un'espressione dovranno essere consentite le sueguenti operazioni aritmetiche :
//
//  +	addizione
//  - 	sottrazione
//  *	moltiplicazione
//  /	divisione
//  ^	elevamento a potenza
//  %	modulo
//
//  La pila dovrà essere gestita con le seguenti dichiarazioni:
//
//  struct stackNode {
//  	char data;
//  	struct stackNode *nextPtr;
//  	};
//
//  typedef struct stackNode STACKNODE;
//  typedef STACKNODE *STACKNODEPTR;
//
//  Il programma dovrà consistere di una funzione main e di altre otto funzioni, con le seguenti intestazioni:
//
//  void convertToPostfix(char infix[], char postfix[])
//
//  Convertirà la notazione infissa in quella polaca inversa.
//
//  int isOperator(char c)
//
//  Determinerà se c'è un operatore.
//
//  int precedence(char operator1, char operator2)
//
//  Determinerà se la priorità di operator1 è minore, uguale o maggiore di quella di operator2.
//  La funzione restituirà rispettivamente  -1 , 0, 1.
//
//  void push(STACKNODEPTR *topPtr, char value)
//
//  Inserirà un valore in cima alla pila.
//
//  char pop(STACKNODEPTR *topPtr)
//
//  Estrarrà un valore dalla cima della pila.
//
//  char stackTop(STACKNODEPTR topPtr)
//
//  Restituirà il valore contenuto in cima ala pila, senza estrarlo dalla stessa.
//
//  int isEmpty(STACKNODEPTR topPtr)
//
//  Determinerà se la pila è vuota
//
//  void printStack(STACKNODEPTR topPtr)
//
//  Visualizzerà la pila
//
//
//


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct stackNode {
	char data;
	struct stackNode *nextPtr;
};

typedef struct stackNode STACKNODE;
typedef STACKNODE *STACKNODEPTR;

void convertToPostfix(char infix[], char postfix[]); // converte la notaizone infissa in quella polacca
int isOperator(char c); // Determina se c è un operatore 
int precedence(char operator1, char operator2); // Determina se la priorità di operator1 è minore, uguale o maggiore di quella di operator2 restituendo -1, 0 o 1
void push(STACKNODEPTR *topPtr, char value); // Inserirà un valore in cima alla pila
char pop(STACKNODEPTR *topPtr); // Restituirà il valore contenuto in cima alla pila, senza estrarlo dalla stessa
int isEmpty(STACKNODEPTR topPtr); // Determinerà se la pila è vuota
void printStack(STACKNODEPTR topPtr); // Visualizzerà la pila.

int main(){
	
	char infix[30], postfix[30];

	convertToPostfix(infix,postfix);
	printf("\nEspressione convertita in notazione polacca inversa : ");
	puts(postfix);

}
void convertToPostfix(char infix[], char postfix[]){ // converte la notaizone infissa in quella polacca
	
	STACKNODEPTR stack = NULL;
	int i = 0;
	char c, *ptr = postfix;
	printf("\nInserire una espressione in notazione inversa :");
	fgets(infix,30,stdin);
	push(&stack,'(');  	// Inserire nella pila una parentesi aperta '('
	strcat(infix,")"); 	// Accodate alla fine di infix una parentesi chiusa ')'
	while(!(isEmpty(stack))){		// Fintanto che la pila non è vuota , leggete infix da sinistra a destra ed eseguite le seguenti operazioni:
		
		if(isdigit(infix[i]) && infix[i] != ' '){	//Nel caso in cui il carattere corrente di infix sia un numero copiatelo nell'elemento successivo di postfix
			*(ptr++) = infix[i++];	
		}else if(infix[i] == '('){ 		// Nel caso in cui il carattere corrente di infix sia una parentesi aperta inseritela nella pila
			push(&stack,infix[i++]);
		}else if(isOperator(infix[i])){ 	// Nel caso in cui il carattere corrente di infix sia un operatore 
			if(isOperator(stack->data)  && (precedence(stack->data,infix[i]) >= 0))	// se nella testa della pila ci sono operatori di precedenza
				*(ptr++) = pop(&stack);	// maggiore o uguale a quella dell'operatore corrente inseriteli
			push(&stack,infix[i++]);	// in postfix. inserite nella pila il carattere corrente in infix
		}else if(infix[i] == ')'){		// Nel caso in cui il carattere corrente di infix sia una parentesi chiusa
			while(stack->data != '(')	// Estraete gli operatori dalla testa della pila e inseriteli in postfix, finchè non ci sarà una
				*(ptr++) = pop(&stack);	// parentesi aperta sulla cima della pila.
			pop(&stack);		// parentesi aperta sulla cima della pila.
			i++;	
		}else
			i++;
		
		
	}
	*(ptr) = '\0';


}

int isOperator(char c){ // Determina se c è un operatore 

	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
		return 1;
	else
		return 0;

}

int precedence(char op1, char op2){ // Determina se la priorità di operator1 è minore, uguale o maggiore di quella di operator2 restituendo -1, 0 o 1
	
	if((op1 == '*' || op1 == '/' || op1 == '%' || op1 == '^') && (op2 == '/' || op2 == '*' || op2 == '%' || op2 == '^'))
		return 0;
	else if((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-'))
		return 0;
	else if((op1 == '*' || op1 == '/' || op1 == '%' || op1 == '^') && (op2 == '+' || op2 == '-'))
		return 1; 
	else if((op2 == '*' || op2 == '/' || op2 == '%' || op2 == '^') && (op1 == '+' || op1 == '-'))
		return -1;
	else if(!isOperator(op1) || !isOperator(op2))
		return -1;
}

void push(STACKNODEPTR *topPtr, char value){ // Inserirà un valore in cima alla pila

	STACKNODEPTR newPtr;
	
	newPtr = malloc(sizeof(STACKNODE));
	
	if(newPtr != NULL){
		newPtr->data = value;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}else
		printf("\nMemory not available!!!\n");

}

char pop(STACKNODEPTR *topPtr){ // Restituirà il valore contenuto in cima alla pila, senza estrarlo dalla stessa

	char c;
	STACKNODEPTR temp;
	
	temp = *topPtr;
	c = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(temp);
	
	return c;
}

int isEmpty(STACKNODEPTR topPtr){ // Determinerà se la pila è vuota
	
	return topPtr == NULL;

}

void printStack(STACKNODEPTR topPtr){ // Visualizzerà la pila.
	
	putchar('\0');

	while(isEmpty(topPtr)){
		printf("%c ",topPtr->data);
		topPtr = topPtr->nextPtr;
	}
	putchar('\0');
}
