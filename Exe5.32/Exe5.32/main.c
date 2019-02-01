//
//  main.c
//  Exe5.32
//
//  Created by Francesco Parrucci on 31/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
I COMPUTER GIOCANO UN RUOLO SEMPRE PIUè IMPORTANTE NELL'EDUCAZIONE. SCRIVETE UN PROGRAMMA CHE AIUTI UNO STUDENTE DI SCUOLA 
ELEMENTARE AD APPRENDERE LA MOLTIPLICAZIONE. UTILIZZATE rand PER PRODURRE DEU INTERI POSITIVI DI UNA CIFRA. DOVRETE QUNDI
VISUALIZZARE UNA DOMANDA COME :

 HOW MUCH IS 8 TIMES 7 ? 
 
IN SEGUITO LO STUDENTE DIGITERA' LA RISPOSTA . IL VOSTRO PROGRAMMA CONTROLLERA' LA RISPOSTA DELLO STUDENTE. QUALORA SIA
CORRETTA, VUSUALIZZATE "VERY GOOD!" E SOTTOPONETE QUINDI UN'ALTRA DOMANDA SULLA MOLTIPLICAZIONE. NEL CASO CHE LA RISPOSTA SIA
SBAGLIATA, VISUALIZZATE "NO. PLEASE TRY AGAIN." E LSASCIATE QUINDI CHE LO STUDENTE PROVI ANCORA RIPETUTAMENE LA STESSA
DOMANDA, FINCHE' ALLA FINE NON AVRAè RISPOSTO CORRENTTAMENTE.
*/
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : ESERCIZI SULLE MOLTIPLICAZIONI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI E FUNZIONI product:
// GENERA DUE NUMERI CASUALI E CHIEDI ALL'UTENTE IL RISULTATO DEL LORO PRODOTTO
//  -- SE CORRETTO STAMPA UN MESSAGGIO OK.
//  -- ALTRIMENTI RITENTA.
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI E FUNZIONE int product(int , int):
// -- PROTOTIPO DI FUNZIONE int product(int, int)
// -- VARIABILE INT numbe1 number2 prodotto
//###########################################################################################################################
//###########################################################################################################################
// GENERA DUE NUMERI E PONILI IN number1 e number2
// CHIEDI ALL'UTENTE DI INSERIRE IL RISULTATO DELLA LORO MOLTIPLICAZIONE EOF PER TERMINARE
// RICHIAMA LA FUNZIONE product PASSANDO number1 e number2
// SE IL RISULTATO E' UGUALE A QUELLO IMMESSO DAL UTENTE STAMPA "OK" ALTRIMENTI STAMPA "RITENTA" E NON USCIRE FINCHE' IL
// RISULTATO NON SIA GIUSTO.
//###########################################################################################################################
//###########################################################################################################################
// DEFINIZIONE DELLA FUNZIONE int product (int, int)
//###########################################################################################################################
//###########################################################################################################################
// RETURN number1 * number2;
//###########################################################################################################################
//###########################################################################################################################
/* 
INTEGRAZIONE CON ESERCIZIO 5.33 IN MODO CHE SIANO VISUALIZZATI VARI COMMENTI A FRONTE DI OGNI RISPOSTA CORRETTA E
SBAGLIATA COME SEGUE: 
 
 VERY GOOD!
 EXCELLENT!
 NICE WORK!
 KEEP UP THE GOOD WORK!
 
COMMENTI PER UNA RISPOSTA SBAGLIATA
 
 NO. PLEASE TRY AGAIN.
 WRONG. TRY ONCE MORE.
 DON'T GIVE UP!
 NO. KEEP TRYING
 
UTILIZZATE IL GENERATORE DI NUMERI CUASUALI PER SCEGLIERNE UNO COMPRESO TRA 1 E 4 E SELEZIONARE UN COMMENTO APPROPRIATO A OGNI 
RISPOSTA. UTILIZZATE LA STRUTTURA SWITCH CON DELLE ISTRUZIONI PRINTF PER EMETTERE I COMMENTI.
*/
//###########################################################################################################################
//###########################################################################################################################
//############################################### INTEGRAZIONE ESERCIZIO 5.33 ###############################################
//###########################################################################################################################
//###########################################################################################################################
// SE L'UTENTE SBAGLA INVOCARE LA FUNZIONE WRONG PASSANDOLE UN NUMERO CASUALE DA 1 A 4  CON RAND()
// ALTRIMENTI INVOCARE LA FUNZIONE RIGHT PASSANDOLE UN NUMERO CASUALE DA 1 A 4 CON RAND()
//###########################################################################################################################
//###########################################################################################################################
//###################################################### FUNZIONE WRONG #####################################################
//###########################################################################################################################
//###########################################################################################################################
// STRUTTURA SWITCH NUBMER
// -- CASE 1
//  STAMPA "NO. PLEASE TRY AGAIN"
// -- CASE 2
//  STAMPA "WRONG. TRY ONCE MORE."
// -- CASE 3
//  STAMPA "DON'T GIVE UP!"
// -- CASE 4
//  STAMPA "NO. KEEP TRYING."
//###########################################################################################################################
//###########################################################################################################################
//###################################################### FUNZIONE RIGHT #####################################################
//###########################################################################################################################
//###########################################################################################################################
// STRUTTURA SWITCH NUBMER
// -- CASE 1
//  STAMPA "VERY GOOD!"
// -- CASE 2
//  STAMPA "EXCELLENT!"
// -- CASE 3
//  STAMPA "NICE WORK!"
// -- CASE 4
//  STAMPA "KEEP UP THE GOOD WORK!"
//###########################################################################################################################
//###########################################################################################################################
/*
INTEGRAZIONE ESERCIZIO 5.34 MODIFICARE L'ESERCIZIO IN MODO DA CONTARE IL NUMERO DI RISPOSTE CORRETTE E SBAGLIATE IMMESSE DALLO
STUDENTE. DOPO CHE LO STUDENTE ABRA' DIGITATO 10 RISPOSTE , IL VOSTRO PROGRAMMA DOVRA' CALCOLARE LA PERCENTUALE DI QULLE
CORRETTE. QUALORA LA PERCENTUALE SIA INFERIORE A 75%, IL VOSTRO PRIGRAMMA DOVRA' VISUALIZZARE "Pliase ask your
instructor for extra help" E QUINDI TERMINARE LA PROPRIA ESECUZIONE.
 */
//###########################################################################################################################
//###########################################################################################################################
/*
ESERCIZIO 5.44 MODIFICATE IL PROGRAMMA IN MODO DA CONSENTIRE ALL'UTENTE DI SCEGLIERE IL TIPO DI PROBLEMI ARITMETICI CHE LUI O 
DESIDERA STUDIARE. UN OPZIONE 1 SIGNIFICHERA' SOLO PROBLEMI SULL'ADDIZIONE, 2 SOLO SULLA SOTTRAZIONE, 3 SOLO SULLA MOLTIPLICA
ZIONE, 4 SULLA DIVISIONE MENTRE 5 SIGNIFICHERA' MISCHIARE A CASO PROBLEMI DI TUTTI QUESTI TIPI.
*/
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int product(int number1, int number2);
int somma(int number1, int number2);
int divisione(int number1, int number2);
int sottrazione(int number1, int number2);
void wrong(int);
void right(int);
void menu(void);

nt main(int argc, const char * argv[]) {
    // insert code here...
    srand((int)time(NULL));
    
    menu();
    
    printf("\nHello, World!\n");
    return 0;
}

int product(int number1 ,int number2){
    return number1 * number2;
}

int somma(int number1 ,int number2){
    return number1 + number2;
}

int sottrazione(int number1 ,int number2){
    return number1 - number2;
}

int divisione(int number1 ,int number2){
    return number1 / number2;
}


void wrong(int number){
    switch (number) {
    case 1:
        printf("\nNo. Please Try again.");
        break;
    case 2:
        printf("\nWrong! Try once more.");
        break;
    case 3:
        printf("\nDon't give up!");
        break;
    case 4:
        printf("\nNo. Keep trying.");
        break;
    default:
        printf("\nSbagliato!");
        break;
        
    }

}

void right(int number){
    switch (number) {
    case 1:
        printf("\nVery Good!");
        break;
    case 2:
        printf("\nExcellent!");
        break;
    case 3:
        printf("\nNice Work!");
        break;
    case 4:
        printf("\nKeep up the good work!");
        break;
    default:
        printf("\nCorretto!");
        break;
        
    }
    
}

void menu(void){
    do{
        int num1, num2, prodotto, errori = 0, conferme = 0, fattore_di_scala = 10, select = 7, caso;
        
        do{
            num1 = 1 + rand() % fattore_di_scala;
            num2 = 1 + rand() % fattore_di_scala;

            printf("\n1) Addizione: ");
            printf("\n2) Sottrazione: ");
            printf("\n3) Moltiplicaizone: ");
            printf("\n4) Divisione: ");
            printf("\n5) Operazione a Caso: ");
            printf("\n6) Esci. ");
            scanf("%d",&select);
            
            switch select{
            case 1:
                printf("\nInserisci la somma di %d + %d: ", num1,num2);
                scanf("%d",&prodotto);
                break;
            case 2:
                printf("\nInserisci la Sottrazione di %d - %d: ", num1,num2);
                scanf("%d",&prodotto);
                break;
            case 3:
                printf("\nInserisci la Moltiplicazione di %d * %d: ", num1,num2);
                scanf("%d",&prodotto);
                break;
            case 4:
                printf("\nInserisci la divisione di %d / %d: ", num1,num2);
                scanf("%d",&prodotto);
                break;
            case 5:
                caso = 1 + rand() % 4;
                printf("\nInserisci);
                       switch caso{
                       case1:
                           printf(" la Somma di %d + %d",num1,num2);
                           scanf("%d",&prodotto);
                           break;
                       case2:
                           printf(" la Sottrazione di %d - %d",num1,num2);
                           scanf("%d",&prodotto);
                           break;
                       case1:
                           printf(" la Moltiplicazione di %d * %d",num1,num2);
                           scanf("%d",&prodotto);
                           break;
                       case1:
                           printf(" la Divisione di %d / %d",num1,num2);
                           scanf("%d",&prodotto);
                           break;
                       }
                break;
            case 6:
                printf("\nBye");
                break;
            default:
                break;
            }
        
        
        }while(!(select > 0 && select < 6));
        
                
        if( (prodotto == product(num1,num2) ) || (prodotto == somma(num1,num2) || (prodotto == sottrazione(num1,num2) || (prodotto == divisione(num1,num2))){
            right(1 + rand() % 4);
            prodotto = 0;
            conferme++;
        }
        else{
            errori++;
            while(((prodotto != product(num1,num2) ) || (prodotto != somma(num1,num2)) || (prodotto != sottrazione(num1,num2)) || (prodotto != divisione(num1,num2))) && (errori < 7) && (getchar() != EOF)){
                wrong(1 + rand() % 4);
                scanf("%d",&prodotto);
                errori++;
            }
        }
        
        if((conferme + errori == 10) && (conferme >= 10 * 0.7) ){
            errori = 0;
            conferme = 0;
            fattore_di_scala++;
            printf("\nOk. Go to Next Level");
        }
        
    }while( (errori < 7) && (getchar() != EOF) && (select > 0 && select < 6 ));
    
    if(errori >= 7)
        printf("\nPlease ask your instructor for extra help");

}