//
//  main.c
//  Exe5.35
//
//  Created by Francesco Parrucci on 31/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
SCRIVETE UN PROGRAMMA C CHE PROPONGA IL GIOCO "INDOVINA IL NUMERO" NEL MODO SEGUENTE: IL VOSTRO PROGRAMMA SCEGLIERA' IL NUMERO
DA INDOVINARE, SELEZIONANDO UN INTERO A CASO COMPRESO NELL'INTERVALLO DA 1 A 1000. IL PROGRAMMA QUINDI VISUALIZZERA' :
 
 I have a number between 1 and 1000?
 Can you guess my number?
 Please type your first guess.

 IL GIOCATORE ALLORA DIGITERA' UNA PRIMA IPOSTESI. IL PROGRAMMA RISPONDERA' CON UNA DELLE SEGUENTI FRASI:
 
 1. Excellent!. You guessed the number!
    Would you like to play again (y or n)?
 2. Too low. Try again.
 2. Too high. Try again.
 
 QUALORA L'IPOTESI DEL GIOCATORE SIA SBAGLIATA, IL VOSTRO PROGRAMMA DOVRA' REITERARE FINCHE' IL GIOCATORE NON AVRA' FINALMENTE 
 INDOVINATO IL NUMERO CORRETTO. IL VOSTRO PROGRAMMA DOVRAì CONTINUARE A INDICARE Too high o Too low, PER AIUTARE IL GIOCATORE A 
 "PRENDERE LA MIRA" SULLA RISPOSTA CORRETTA.
 */
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : INDOVINA IL NUMERO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI E FUNZIONI void question(int, int):
// GENERA UN NUMERO CASUALE TRA 1 E 1000 CHIEDI ALL'UTENTE DI INDOVINARLO
//  -- SE CORRETTO STAMPA UN MESSAGGIO OK. E CHIEDI SE VUOLE CONTINUARE O MENO
//  -- ALTRIMENTI STAMPA UN MESSAGGIO TOO LOW O TOO HIGH
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI E FUNZIONE void question(int, int):
// -- PROTOTIPO DI FUNZIONE void question(int)
// -- VARIABILE INT num1, num2
// -- VARIABILE CHAR lettera
//###########################################################################################################################
//###########################################################################################################################
// GENERA UN NUMERO TRA 1 E 1000 E ASSEGNALO A number
// CHIEDI ALL'UTENTE DI INDOVINARE LA GRANDEZZA
// -- SE INDOVINA STAMPA Excellent!. You guessed the number! Would you like to play again (y or n)?
// -- ALTRIMENTI CHIAMA LA FUNZIONE question e passale il numero da indovinare e quello immesso dall'utente
// CONTINUA FINCHE' IL VALORE DEL CARATTERE IMMESSO E' DIVERSO DA Y O EOF
//###########################################################################################################################
//###########################################################################################################################
// DEFINIZIONE DELLA FUNZIONE void question(int num1, int num2)
//###########################################################################################################################
//###########################################################################################################################
// SE num1 > num2 STAMPA Too low. Try again.
// ALTRIMENTI STAMPA Too High. Try again.
//###########################################################################################################################
//###########################################################################################################################
// INTEGRAZIONE DEL ESERCIZIO 5.36 MODIFICATE L'ESERCIZIO 5.35 IN MODO DA CONTARE IL NUMERO DI TENTATIVI DEL GIOCATORE. QUALO
// RA IL NUMERO SIA INFERIORE O UGUALE A 10, VISUALIZZATE "Either you know the secret or you got lucky!". QUALORA IL
// GIOCATORE INDOVINI IL NUMERO IN 10 TENTATIVI, VISUALIZZATE "Ahah! You know the secret!". QUALORA IL GIOCATORE FACCIA PIU' DI
// 10 TENTATIVI, VISUALIZZATE "You should be able to do better!".
//###########################################################################################################################
//###########################################################################################################################

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void question(int, int);

int main(int argc, const char * argv[]) {
    // insert code here...
    srand((int)time(NULL));
    int num1 , num2 , count = 0;
    char lettera = 'y';
    
    
    
    do{
        count++;
        num1 = 1 + rand() % 1000;
        printf("\nI have a number between 1 and 1000? %d\nCan you guess my number?\nPlease type your first guess. ",num1);
        scanf("%d",&num2);
        
        if (num2 == num1){
            
            if(count < 10)
                printf("\nEither you know the secret or you got lucky!");
            else if(count == 10)
                printf("\nAhah! You know the secret!");
            else
                printf("\nYou should be able to do better!");
            
            printf("\nExcellent!. You guessed the number! Would you like to play again (y or n)?");
            count = 0;
            getchar();
            lettera = getchar();
            
        }else{
            while(num1 != num2){
                question(num2,num1);
                scanf("%d",&num2);
                count++;
            }
            if(count < 10)
                printf("\nEither you know the secret or you got lucky!");
            else if(count == 10)
                printf("\nAhah! You know the secret!");
                else
                printf("\nYou should be able to do better!");
            
            printf("\nExcellent!. You guessed the number! Would you like to play again (y or n)?");
            count = 0;
            getchar();
            lettera = getchar();
        }
        
    }while(lettera != 'n' && lettera != 'N');
    
    printf("\nHello, World!\n");
    return 0;
}

void question(int num1, int num2){
    if(num1 > num2)
        printf("\nToo High. Try again.");
    else
        printf("\nToo Low. Try again.");
}
