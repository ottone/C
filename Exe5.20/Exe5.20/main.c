//
//  main.c
//  Exe5.20
//
//  Created by Francesco Parrucci on 26/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
SCRIVETE UNA FUNZIONE CHE VISUALIZZI AL MARGINE SINISTRO DELLO SCHERMO UN QUADRATO PIENO DI ASTERISCHI IL CUI LATO SIA STATO
SPECIFICATO NEL PARAMETRO INTERO side. IL QUADRATO DEVE ESSERE FORMATO DA QUALSIASI CARATTERE SIA CONTENUTO NEL PARAMETRO DI
TIPO CARATTERE fillCharacter. INCREMENTARE CON FUNZIONI CHE DISEGNINO UN AMPIA GAMMA DI FORME
 */
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : DISEGNO CON CARATTERI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI E FUNZIONI paint
// RICHIEDERE UN NUMERO INTERO E IL TIPO DI CARATTERE
// CHIAMA paint(X,Y) E STAMPA RISULTATO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI E FUNZIONI paint:
// -- FUNZIONE  (void) paint (int, char)
// -- VARIABILE INT X ;
// -- VARIABILE CHAR Y;
//###########################################################################################################################
//###########################################################################################################################
// RICHIEDERE UN INTERO POSITIVO E MEMORIZZARLI IN X
// RICHIEDERE UN CARATTERE E MEMORIZZARLO IN Y
// RICHIAMA paint(x,y)
//###########################################################################################################################
//###########################################################################################################################
//######################################## FUNZIONE void paint1(int x, char y)###########################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARA DUE VARIABILI COUNT1 E COUNT2
// PER COUNT1 = 1 ; COUNT1 <= X ; COUNT1++
//      PER COUNT2 = 1; COUNT2 <= X ; COUNT2++
//          STAMPA UN CARATTERE CONTENUTO IN Y
//      STAMPA UN RITORNO A CAPO E NUOVA RIGA
//###########################################################################################################################
//###########################################################################################################################
//######################################## FUNZIONE void paint2(int x, char y)###############################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARA DUE VARIABILI COUNT1  COUNT2 COUNT3 E COUNT4
// PER COUNT1 = 1, COUNT3 = X / 2 + 1 , COUNT4 = X / 2 + 1 ; COUNT1 <= X / 2 + 1 ; COUNT1++, COUNT3++
//      PER COUNT2 = 1; COUNT2 <= X; COUNT2++
//          SE COUNT2 >= COUNT3 && COUNT2 <= COUNT4
//            STAMPA UN CARATTERE Y COUNT3-- E COUNT4++
//          ALTRIMENTI
//            STAMPA UNO SPAZIO
//      STAMPA UN RITORNO A CAPO E NUOVA LINEA
// PER COUNT1 = 1, COUNT3 = 1 , COUNT4 = X  ; COUNT1 <= X / 2 + 1 ; COUNT1++,
//      PER COUNT2 = 1; COUNT2 <= X; COUNT2++
//          SE COUNT2 >= COUNT3 && COUNT2 <= COUNT4
//            STAMPA UN CARATTERE Y COUNT3++ E COUNT4--
//          ALTRIMENTI
//            STAMPA UNO SPAZIO
//      STAMPA UN RITORNO A CAPO E NUOVA LINEA
//###########################################################################################################################
//###########################################################################################################################
//######################################## FUNZIONE void paint2(int x, char y)###############################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARA DUE VARIABILI COUNT1 E COUNT2
// INSEMINAZIONE RAND CON SRAND FATTORE DI SCALA X
// PER COUNT1 = 1 ; COUNT1 <= X  ; COUNT1++
//      PER COUNT2 = 1, COUNT3 = X - RAND() % X,  COUNT2 <= X ; COUNT2++
//      SE COUNT2 >= X / 2 - COUNT3 E COUNT2 <= X / 2 + COUNT3
//      STAMPA UN CARATTERE CONTENUTO IN Y
//      ALTRIMENTI STAMPA UNO SPAZIO
// STAMPA UN RITORNO A CAPO E NUOVA RIGA
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void paint(int, char);
void paint1(int, char);
void paint2(int, char);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int x;
    char y;
    
    do{
        printf("\nInserisci un intero positivo ed un carattere: ");
        scanf("%d",&x);
        scanf("%c",&y);
    }while(y ==  ' ' || y == '\n' || x <= 0);
    
    paint(x, y);
    printf("Hello, World!\n");
    paint1(x, y);
    printf("Hello, World!\n");
    paint2(x, y);
    printf("Hello, World!\n");
    return 0;
}

void paint(int x, char y){
    int count1 , count2;
    printf("\n");
    for(count1 = 0; count1 < x; count1++){
        for(count2 = 0; count2 < x; count2++)
            putchar(y);
        printf("\n");
    }
}

void paint1(int x, char y){
    int count1 , count2, count3 , count4;
    
    for(count1 = 1, count3 = count4 = x / 2; count1 <= x / 2 ; count1++, count3-- , count4++){
        for(count2 = 1; count2 <= x; count2++)
            if(count2 >= count3 && count2 <= count4 )
                putchar(y);
            else
                putchar(' ');
    printf("\n");
    }
    
    for(; count1 > 0 ; count1--, count3++, count4--){
        for(count2 = 1; count2 < x; count2++)
            if(count2 >= count3 && count2 <= count4)
                putchar(y);
            else
                putchar(' ');
        
        printf("\n");
    }
}

void paint2(int x, char y){
    srand(x);
    int count1 , count2, count3;
    
    for(count1 = 0; count1 <= x; count1++){
        if ((count3 = x - (rand() % x)) == x )
            continue;
        else
        for(count2 = 0; count2 <= x; count2++){
            //if(count3 == x)
            //    continue;
            if (count2 > (x/2 - count3) && count2 < (x/2 + count3))
                putchar(y);
            else
                putchar(' ');}
        printf("\n");
    }
}
