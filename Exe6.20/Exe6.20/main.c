//
//  main.c
//  Exe6.20
//
//  Created by Francesco Parrucci on 10/02/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
SCRIVETE UN PROGRAMMA CHE ESEGUA 1000 VOLTE I GIOCO DEI DADI CRAPS E RISPONDETE AD OGNIUNA DELLE SEGUENTI DOMANDE

A) QUANTI GIOCHI SONO STATI VINTI AL PRIMO LANCIO, SECONDO , AL TERZO , AL QUARTO .... AL VENTESIMO?
B) QUANTI GIOCHI SONO STATI PERSI AL PRIMO LANCIO, SECONDO , AL TERZO , AL QUARTO .... AL VENTESIMO?
C) QUALI SONO LE POSSIBILITA' DI VITTORIA DEL GIOCO DEI DADI ? (NOTA: SAPPIATE CHE IL GIOCO DEI DADI E' UNO DEI PIU' EQUI TRA 
   QUELLI DA CASINO' A QUALE CONCLUSIONE VI PORTA QUESTA CONSIDERAZIONE?)
D) QUALE' LA LUNGHEZZA MEDIA DI UN GIOCO DI DADI?
E) LE PROPABILITA' DI VITTORIA AUMENTANO CON LA LUNGHEZZA DEL GIOCO?

*/

/* Craps */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(void);
int craps(void);

int main()
{
    int count ,win = 0, loss = 0;
    
    srand((int)time(NULL));
    
    for(count = 0; count < 1000 ; count++){
        if(craps())
            win++;
        else
            loss++;
    }
    
    printf("Su %d giocate numero vinte : %d e numero perse %d\n",count , win, loss);
    
    
    return 0;
}
int craps(void){
    
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
            //printf("Point is %d\n", myPoint);
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
        return 1; //printf("Player wins\n");
    else
        return 0; //printf("Player loses\n");
}

int rollDice(void)
{
    int die1, die2, workSum;
    
    die1 = 1 + (rand() % 6);
    die2 = 1 + (rand() % 6);
    workSum = die1 + die2;
    //printf("Player rolled %d + %d = %d\n", die1, die2, workSum);
    return workSum;
}
