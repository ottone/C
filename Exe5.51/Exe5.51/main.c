//
//  main.c
//  Exe5.51
//
//  Created by Francesco Parrucci on 01/02/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
MODIFICATE IL PROGRAMMA PER IL GIOCO DEI DADI DELLA FIGURA 5.10 IN MODO DA CONSENTIRE DELLE SCOMMESSE. IMPACCHETTATE IN UNA 
FUNZIONE LA PORZIONE DEL PROGRAMMA CHE ESEGUIRA' UN SINGOLO GIOCO AI DADI. INIZIALIZZATE LA VARIABILE bankBalance (SALDO)
A 1000 DOLLARI. CHIEDETE AL GIOCATORE DI IMMETTERE UNA wager(puntata). UTILIZZATE UN CICLO while PER CONTROLLARE CHE wager SIA 
INFERIORE O UGUALE A bankBalance E, IN CASO CONTRARIO, PER CHIEDERE ALL'UTENTE DI IMMETTERE NUOVAMENTE wager FINCHE' NON NE SIA 
STATA IMMESSA UNA VALIDA. DOPO CHE SARAì STATA IMMESSA UNA wager CORRETTA. ESEGUITE UN GIOCO AI DADI. NEL CASO IN CUI IL
GIOCATORE VINCA, INVREMENTATERETE bankBalance DI wager E VISUALIZZATE IL NUOVO bankBalance. NEL CASO IN CUI IL GIOCATORE
PERDA, DECREMENTERETE bankBalance DI wager, VISUALIZZERETE IL NUOVO backBalance, VERIFICHERETE  CHE bankBalance NON SIA
DIVENTATO ZERO E, IN CASO CONTRARIO, VISUALIZZERETE IL MESSAGGIO "Sorry. You busted!". MAN MANO CHE IL GIOCO PROGREDIRA' ,
VISUALIZZARETE VARI MESSAGGI PER FARE UN PO' DI CHIACCHIERE COME   "Oh, you're going for broke, huh?" . O "Awcmon, take a
chnce!" . O "You're up big. Now's thetime to cash in your chips!".
"
*/

/* Craps */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(void);
int game(void);
void chiacchiere(void);

int main()
{
    srand((int)time(NULL));
    
    int wager = 0, bankBalance = 1000;
    
    do{
        printf("\nImmettere una puntata (1 - 1000 Dollari) : ");
        scanf("%d",&wager);
        if(game()){
            bankBalance += wager;
            printf("\nNuvo valore del saldo: %d",bankBalance);
            chiacchiere();
            wager = -1;
        }else{
            bankBalance -= wager;
            wager = -1;
            printf("\nNuvo valore del saldo: %d",bankBalance);
            if(bankBalance <= 0){
                printf("\nSorry. You busted!\n");
                break;
            }else
                chiacchiere();
            
        }
        
        
        
    }while(wager < 0 || wager > bankBalance);
    
    return 0;
}


int rollDice(void)
{
    int die1, die2, workSum;
    
    die1 = 1 + (rand() % 6);
    die2 = 1 + (rand() % 6);
    workSum = die1 + die2;
    printf("Player rolled %d + %d = %d\n", die1, die2, workSum);
    return workSum;
}

int game(void){
    int gameStatus, sum, myPoint;
    
    sum = rollDice();            /* first roll of the dice */
    
    switch(sum) {
        case 7: case 11:          /* win on first roll */
            gameStatus = 1;
            break;
        case 2: case 3: case 12:  /* lose on first roll */
            gameStatus = 2;
            break;
        default:                  /* remember point */
            gameStatus = 0;
            myPoint = sum;
            printf("Point is %d\n", myPoint);
            break;
    }
    
    while (gameStatus == 0) {    /* keep rolling */
        sum = rollDice();
        
        if (sum == myPoint)       /* win by making point */
            gameStatus = 1;
        else
            if (sum == 7)          /* lose by rolling 7 */
                gameStatus = 2;
    }
    
    if (gameStatus == 1)
        printf("Player wins\n");
    else{
        printf("Player loses\n");
        gameStatus = 0;
    }
    return gameStatus;
}

void chiacchiere(void){
    
    switch (1 + rand() % 4){
        case 1:
            printf("\nOh, you're going for broke, huh?");
            break;
        case 2:
            printf("\nAwcmon, take achnce!");
            break;
        case 3:
            printf("\nYou're up big. Now's thetime to cash in your chips!");
            break;
        default:
            break;
    }
}