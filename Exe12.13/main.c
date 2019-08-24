//
//  main.c
//  Exe12.13
//
//  Created by Francesco Parrucci on 27/07/19.
//  Copyright © 219 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che valuti un'espressione in notaizone polacca inversa (supponete che sia valida) come 6 2 + 5 * 8 4 / -.
//  Il programma dovrà leggere e immagazzinare in un vettore un'espressione in notaizone polaca inversa formata da numeri e operatori. Usando la versione modificata delle
//  funzioni per la gestione di una pila implementate in precedenza in questo capitolo, il programma dovrà analizzare l'espressione e valutarla. L'algoritmo è il seguente:
//
//  1) Accodate il carattere NULL ('\0') alla fine dell'espressione in notazione polacca inversa. Nel momento in cui il carattere NULL sarà stato incontrato, non saranno 
//     necessarie ulteriori operazioni.
//
//  2) Fintanto che '\0' non sia stato incontrato, leggete l'espressione da sinistra a destra. 
//     Nel caso in cui il carattere corrente sia un numero, inserite il suo valoreintero in testa alla pila. Ricordate che il valore intero di una carattere numerico è 
//     quello assunto nell'insieme dei caratteri del computer meno il valore di '0'.
//
//     Altrimenti, qualora il carattere corrente sia un operatore, estraete dalla cima della pila i primi due elementi e immagazzinateli nelle variabili x e y 
//     Calcolate y operatore x.
//
//     Inserite il risultato del calcolo in testa alla pila.
//
//  3) Estraete il valore contenuto in cima alla pila, qualora nell'espressione abbiate incontrato il carattere NULL. Quel valore sarà proprio il risultato dell'espressione
//     in notaizone polacca inversa.
//
//
//  Nota: nel precendente punto 2), quando l'operatore sarà '/', la testa della pila conterrà 2 e il suo elemento successivo sarà 8, allora dovrete estrarre il 2 in x, 
//  il valore 8 in y, calcolare 8 / 2 e reinserire nella pila il risultato, 4. Questa nota si applicherà anche  all'operatore '-'. Ecco un elenco delle operazioni 
//  aritmetiche che saranno consentite in un'espressione :
//
//  +		addizione
//  - 		sottrazione 
//  *		moltiplicazione
//  /		divisione
//  ^		elevamento a potenza
//  %		modulo
//
//  La pila dovrà essere gestita con le seguenti dichiarazioni :
//
//  struct stackNode{
//  	int data;
//  	struct stackNode *nextPtr;
//  	};
//
//  typedef struct stackNode STACKNODE;
//  typedef STACKNODE *STACKNODEPTR;
//
//  Il programma dovrà essere formato dal main e da altre sei funzioni con le seguenti intestazioni: 
//
//  int evaluatePostfixExpression(char *expr)
//
//  Valuterà l'espressione in notaizone polacca inversa.
//
//  int calculate(int op1, int op2, char operator)
//
//  Calcolerà il valore dell'espressione op1 operatore op2
//
//  void push(STACKNODEPTR *topPtr, int value)
//
//  Inserirà un valore in cima alla pila.
//
//  int pop(STACKNODEPTR *topPtr)
//
//  Estrarrà un valore dalla cima della pila,
//
//  int isEmpty(STACKNODEPTR topPtr)
//
//  Determinerà se la pila è vuota.
//
//  void printStack(STACKNODEPTR topPtr)
//
//  Visualizzerà la pila.
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
#include <math.h>

struct stackNode {
	char data;
	struct stackNode *nextPtr;
};

struct stackNodeInt{
	int value;
	struct stackNodeInt *nextPtr;
};

typedef struct stackNodeInt STACKNODEI;
typedef STACKNODEI *STACKNODEIPTR;
typedef struct stackNode STACKNODE;
typedef STACKNODE *STACKNODEPTR;

void convertToPostfix(char infix[], char postfix[]); // converte la notaizone infissa in quella polacca
int isOperator(char c); // Determina se c è un operatore 
int precedence(char operator1, char operator2); // Determina se la priorità di operator1 è minore, uguale o maggiore di quella di operator2 restituendo -1, 0 o 1
void push(STACKNODEPTR *topPtr, char value); // Inserirà un valore in cima alla pila
char pop(STACKNODEPTR *topPtr); // Restituirà il valore contenuto in cima alla pila, senza estrarlo dalla stessa
void pushi(STACKNODEIPTR *topPtr, int value); // Inserirà un valore intero in cima alla pila
int popi(STACKNODEIPTR *topPtr); // Restituirà il valore intero in cima alla pila
int isEmpty(STACKNODEPTR topPtr); // Determinerà se la pila è vuota
void printStack(STACKNODEPTR topPtr); // Visualizzerà la pila.
int evaluatePostfixExpression(char *expr);      	 //  Valuterà l'espressione in notaizone polacca inversa.
int calculate(int op1, int op2, char operator); 	 //  Calcolerà il valore dell'espressione op1 operatore op2
void printStackInt(STACKNODEIPTR topPtr);		 // Visualizzerà la pila di interi

int main(){
	
	char infix[30], postfix[30];

	convertToPostfix(infix,postfix);
	printf("\nEspressione convertita in notazione polacca inversa : ");
	printf("\nValore dell'espressione %s : %d\n\n",postfix,evaluatePostfixExpression(postfix));

return 0;
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
			*(ptr++) = ' ';	
		}else if(infix[i] == '('){ 		// Nel caso in cui il carattere corrente di infix sia una parentesi aperta inseritela nella pila
			push(&stack,infix[i++]);
		}else if(isOperator(infix[i])){ 	// Nel caso in cui il carattere corrente di infix sia un operatore 
			if(isOperator(stack->data)  && (precedence(stack->data,infix[i]) >= 0)){	// se nella testa della pila ci sono operatori di precedenza
				*(ptr++) = pop(&stack);	// maggiore o uguale a quella dell'operatore corrente inseriteli
				*(ptr++) = ' ';
			}
			push(&stack,infix[i++]);	// in postfix. inserite nella pila il carattere corrente in infix
		}else if(infix[i] == ')'){		// Nel caso in cui il carattere corrente di infix sia una parentesi chiusa
			while(stack->data != '('){	// Estraete gli operatori dalla testa della pila e inseriteli in postfix, finchè non ci sarà una
				*(ptr++) = pop(&stack);	// parentesi aperta sulla cima della pila.
				*(ptr++) = ' ';
			}
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

void pushi(STACKNODEIPTR *topPtr, int value){ // Inserirà un valore intero in cima alla pila
	
	STACKNODEIPTR newPtr = NULL;

	newPtr = malloc(sizeof(STACKNODEI));

	if(newPtr != NULL){
		newPtr->value = value;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}else
		printf("\nMemory not available!!!\n");

}

int popi(STACKNODEIPTR *topPtr){ // Restituirà il valore intero in cima alla pila
	
	int value;
	STACKNODEIPTR temp = NULL;
	
	temp = *topPtr;
	value = (*topPtr)->value;
	*topPtr = (*topPtr)->nextPtr;
	free(temp);

	return value;

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
	
	putchar('\n');

	while(isEmpty(topPtr)){
		printf("%c ",topPtr->data);
		topPtr = topPtr->nextPtr;
	}
	putchar('\n');
}

	
int evaluatePostfixExpression(char *expr){      //  Valuterà l'espressione in notaizone polacca inversa.
	
int i = 0, x , y , temp;

STACKNODEIPTR stack = NULL;

while(expr[i] != '\0'){

	if(isdigit(expr[i])){
		pushi(&stack,expr[i]-'0');
		printf("\nInserisco %d",expr[i]-'0');
		printStackInt(stack);
		i++;
	}else if(isOperator(expr[i])){
		printf("\nOperatore : %c",expr[i]);
		x = popi(&stack);
		printf(" Estraggo %d ",x);
		y = popi(&stack);
		printf(" Estraggo %d ",y);
		if(expr[i] == '/' || expr[i] == '-') if(x < y) {temp = y, y = x, x = temp;}
		temp = calculate(x,y,expr[i]);
		printf(" risultato operazione %d da inserire nella pila",temp);
		pushi(&stack,calculate(x,y,expr[i]));
		i++;
		printStackInt(stack);
	}else
		i++;
}
return popi(&stack);
}

int calculate(int op1, int op2, char operator){ //  Calcolerà il valore dell'espressione op1 operatore op2
	
	int value ;

	switch (operator){
		case '+':
		value = op1 + op2;
		break;

		case '-':
		value = op1 - op2;
		break;

		case '*':
		value = op1 * op2;
		break;

		case '/':
		value = op1 / op2;
		break;

		case '^':
		//value = 1;
		//while(op1-- > 0) value *= op2;
		value = pow(op1,op2);
		break;
	}
	return value;	
}
		
void printStackInt(STACKNODEIPTR topPtr){		 // Visualizzerà la pila di interi
	
	putchar('\n');
	while(topPtr != NULL){
		printf(" %d ",topPtr->value);
		topPtr = topPtr->nextPtr;
	}
	putchar('\n');
}
