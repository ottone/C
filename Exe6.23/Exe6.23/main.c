//
//  main.c
//  Exe6.23
//
//  Created by Francesco Parrucci on 22/02/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
(TURTLE GRAPHICS) IL LINGUAGGIO LOGO, PARTICOLARMENTE POPOLARE TRA GLI UTENTI DI PERSONAL COMPUTER,  HA RESO FAMOSO IL CONCETTO
 DI TURTLE GRAPHICS (GRAFICI DELLA TARTARUGA). IMMAGINATE UNA TRARTARUGA MECCANICA CHE GIROVAGA IN UNA STANZA SOTTO IL
 CONTROLLO DI UN PROGRAMMA C. LA TARTARUGA HA UNA PENNA IN UNA DELLE DUE POSIZIONI, ALZATA O ABBASSATA. LA TARTARUGA TRACCIA 
 DELLE LINEE MAN MANO CHE SI MUOVE CON LA PENNA ABBASSATA; QUANDO QUESTA E' ALZATA SI MUOVE LIBERAMENTE SENZA SCRIVERE NIENTE.
 IN QUESTO PROBLEMA, SIMULERETE LE OPERAIZONI DELLA TARTARUGA E CREERETE, ALLO STESSO TEMPO, UN BLOCCHETTO PER GLI SCHIZZI.
 UTILIZZATE UNA MATRICE FLOOR 50 PER 50 E AZZERATELA. LEGGETE I  COMANDI DA UN VETTORE CHE LI CONTENGA. IN OGNI MOMENTO,
 MANTENETE TRACCIA DELLA POSIZIONE CORRENTE DELLA TARTARUGA E DELLO STATO (ALZATA O ABBASSATA) DELLA PENNA. SUPPONETE CHE LA 
 TARTARUGA COMINCI SEMPRE  DALLA POSIZIONE 0,0 DEL PAVIMENTO CON LA PENNA ALZATA. L'INSIEME DEI COMANDI PER LA TARTARUGA CHE IL 
 VOSTRO PROGRAMMA DOVRA' ELABORARE SARA':
 
 1 ALZA LA PENNA
 2 ABBASSA LA PENNA
 3 GIRA A DESTRA
 4 GIRA A SINISTRA 
 5,10 VAI IN AVANTI DI 10 SPAZI (O UN NUMERO DIVERSO DA 10)
 6 VISUALIZZA LA MATRICE 50 PER 50 
 9 FINE DEI DATI (VALORE SENTINELLA)
 
 SUPPONETE CHE LA TARTARUGA SIA IN UNA QUALCHE POSIZIONE VICINA AL CENTRO DEL PAVIMENTO. IL SEGUENTE PROGRAMMA DISEGNEREBBE E 
 VISUALIZZEREBBE UN QUADRATO 12 PER 12:
 
 2
 5,12
 3
 5,12
 3
 5,12
 3
 5,12
 1
 6
 9
 
 MAN MANO CHE LA TARTARUGA SI MUOVERA' CON LA PENNA ABBASSATA , IMPOSTERETE GLI ELEMENTI CORRISPONDENTI DELLA MATRICE FLOOR A
 1. NEL MOMENTO IN CUI IL PROGRAMMA AVRA' IMPARTITO IL COMANDO 6 (VISUALIZZA), STAMPERETE UN ASTERISCO , O QUALSIAI ALTRO 
 CARATTERE ABBBIATE SCELTO, IN CORRISPONDENZA DI OGNI 1 INCLUSO NELLA MATRICE. STAMPERETE INVECE UNO SPAZIO IN CORRISPONDENZA 
 DI OGNI ZERO, SCRIVETE UN PROGRAMMA C CHE IMPRLEMENTI LE CAPACITA' GRAFICHE DELLA TARTARUGA DISCUSSE IN QUESTO ESERCIZIO. 
 SCRIVETE DIVERSI PROGRAMMI DI TURTLE GRAPHICS, IN MODO CHE SIANO DISEGNATE DELLE FORME INTERESSANTI. AGGIUNGETE ALTRI COMANDI 
 PER INVCREMENTARE LA POTENZA DEL VOSTO LINGUAGGIO DI TURTLE GRAPHICS.
*/
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : TURTLE GRAPHICS
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE STRUTTURE DATI E PROTOTIPI DI FUNZIONI
// ACQUISIRE DATI FINO ALL'IMMISSIONE DEL NUMERO 9
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
//
// DEFINE SIZE = 50
// PROTOTIPO DI FUNZIONE WRITEON
// PROTOTIPO DI FUNZIONE WRITEOFF
// PROTOTIPO DI FUNZIONE RIGHT
// PROTOTIPO DI FUNZIONE LEFT
// PROTOTIPO DI FUNZIONE GO
// PROTOTIPO DI FUNZIONE PRINT
// PROTOTIPO DI FUNZIONE MENU ( RITORNA 1 PER ALZA PENNA, 2 PER ABBASSA PENNA, 3 GIRA A DESTRA, 4 GIRA A SINISTRA
//                                      5 PER VAI IN AVANTI, 6 PER VISUALIZZA E 9 PER ESCI)
//
//###########################################################################################################################
//###########################################################################################################################
//#################################################### MAIN #################################################################
//###########################################################################################################################
//###########################################################################################################################
//
// DICHIARAZIONE MATRICE INTERA FLOOR [50] [50]
// DICHIARAZIONE VETTORE INTERO COMMAND[12]
// DICHIARAZIONE VARIABILE INT COUNT = 0;
// DICHIARAZIONE VARIABILI EXTERN INT X = 0 , Y = 0, FM = 0, TO = 49, ASC = 0, ORD = 0, PENNA = 0;
//
// MENU(COMMAND[])
//
// DO
// STRUTTURA SWITCH (COMMAND[COUNT])
//      CASE 1:
//          PENNA = WRITEON();
//          BREAK;
//      CASE 2:
//          PENNA = WRITEOFF();
//          BREAK;
//      CASE 3:
//          DESTRA = RIGHT();
//          BREAK;
//      CASE 4:
//          SINISTRA = LEFT();
//          BREAK;
//      CASE 5:
//          COUNT++
//          GO(COMMAND[COUNT]);
//          BREAK;
//      CASE 6:
//          STAMPA(FLOOR[] [50]);
//          BREAK;
//      CASE 9:
//          SCELTA = 9;
//          BREAK;
//      DEFAULT:
//          SCELTA = 10;
//          PRINTR(SCELTA SBAGLIATA!);
//          BREAK:
// COUNT++;
// WHILE COMMAND[SCELTA] != 9
//
//###########################################################################################################################
//###########################################################################################################################
//################################################# FUNZIONE MENU(COMMAND[]) ################################################
//###########################################################################################################################
//###########################################################################################################################
//
// VOID MENU(COMMAND[]){
//
//      INT COUNT = 0;
//
//      DO
//          PRINTF  1 ALZA LA PENNA
//          PRINTF  2 ABBASSA LA PENNA
//          PRINTF  3 GIRA A DESTRA
//          PRINTF  4 GIRA A SINISTRA
//          PRINTF  5,10 VAI IN AVANTI DI 10 SPAZI (O UN NUMERO DIVERSO DA 10)
//          PRINTF  6 VISUALIZZA LA MATRICE 50 PER 50
//          PRINTF  9 FINE DEI DATI (VALORE SENTINELLA):
//
//          SCANF %D &COMMAND[COUNT]
//          IF COUMMAND[COUNT] == 5
//                  COUNT++
//          PRINTF(1 X 10 AVANZAMENTI 2 X PERSONALIZZARE)
//          SCANF(%D %COMMAND[COUNT])
//             IF(COMMAND[COUNT] == 1)
//                  COMMAND[COUNT] == 10
//              ELSE{
//                  DO
//                     IMMETTERE IL NUMERO DI AVANZAMENTI [0 - 49]
//                     SCANF (%D, &COMMAND[COUNT])
//                  WHILE (COMMAND[COUNT] < 0 || COMMAND[COUNT] > 49)}
//          COUNT++
//
//      WHILE COMMAND[COUNT] == 9 || COUNT == 12
//
//
// }
//
//###########################################################################################################################
//###########################################################################################################################
//################################################# FUNZIONE PENNA_GIU #######################################################
//###########################################################################################################################
//###########################################################################################################################
//
// INT WRITEON(VOID){
//      RETURN 1;
// }
//
//###########################################################################################################################
//###########################################################################################################################
//################################################# FUNZIONE PENNA_SU #######################################################
//###########################################################################################################################
//###########################################################################################################################
//
// INT WRITEOFF(VOID){
//      RETURN 0;
// }
//
//###########################################################################################################################
//###########################################################################################################################
//################################################# FUNZIONE T_RIGHT ########################################################
//###########################################################################################################################
//###########################################################################################################################
//
// VOID RIGHT(VOID){
//
//
//      SE ORD == 1
//
//              ORD = 0;
//              ASC = 1;
//
//              SE FM = 0
//                  FM = SIZE - 1
//                  TO = 0
//
//              SE FM = SIZE - 1
//                  FM = 0
//                  TO = SIZE - 1
//
//      ALTRIMENTI
//
//              ASC = 0
//              ORD = 1
//
//              SE FM = SIZE - 1
//                  FM = SIZE - 1
//                  TO = 0
//
//              SE FM = 0
//                  FM = 0
//                  TO = SIZE - 1
//
// }
//
//###########################################################################################################################
//###########################################################################################################################
//################################################# FUNZIONE T_LEFT #########################################################
//###########################################################################################################################
//###########################################################################################################################
//
// VOID LEFT(VOID){
//
//
//      SE ORD == 1
//
//              ORD = 0;
//              ASC = 1;
//
//              SE FM = 0
//                  FM = 0
//                  TO = SIZE - 1
//
//              SE FM = SIZE - 1
//                  FM = 0
//                  TO = SIZE - 1
//
//      ALTRIMENTI
//
//              ASC = 0
//              ORD = 1
//
//              SE FM = SIZE - 1
//                  FM = 0
//                  TO = SIZE - 1
//
//              SE FM = 0
//                  FM = SIZE - 1
//                  TO = 0
//
// }
//
//###########################################################################################################################
//###########################################################################################################################
//################################################# FUNZIONE DISTANCE #########################################################
//###########################################################################################################################
//###########################################################################################################################
//
// VOID DISTANCE(INT DISTANCE, INT PENNA){
//
//      SE ASC = 1
//
//          SE FM = 0
//              DISTANCE = DISTANCE + X > 50 ? 50 : DISTANCE + X
//              WHILE X <= DISTANCE{
//                  IF (PENNA == 1)
//                      FLOOR [Y] [X++] = 1
//                  ELSE
//                      X++
//              }
//          ALTRIMENTI
//              DISTANCE = X - DISTANCE  < 0 ? 0 : X - DISTANCE
//              WHILE X >= DISTANCE){
//                  IF (PENNA == 1)
//                      FLOOR [Y] [X--] = 1
//                  ELSE
//                      X--
//              }
//
//      SE ORD = 1
//
//          SE FM = 0
//              DISTANCE = DISTANCE + Y > 50 ? 50 : DISTANCE + Y
//              WHILE Y <= DISTANCE{
//                  IF (PENNA == 1)
//                      FLOOR [Y++] [X] = 1
//                  ELSE
//                      Y++
//              }
//          ALTRIMENTI
//              DISTANCE = Y - DISTANCE  < 0 ? 0 : Y - DISTANCE
//              WHILE Y >= DISTANCE){
//                  IF (PENNA == 1)
//                      FLOOR [Y--] [X] = 1
//                  ELSE
//                      Y--
//              }
//
//      DISTANCE = 0
//
// }
//
//###########################################################################################################################
//###########################################################################################################################
//################################################# FUNZIONE STAMPA #########################################################
//###########################################################################################################################
//###########################################################################################################################
//
// VOID STAMPA(VOID){
//
//      INT COUNT1, COUNT2;
//
//      FOR(COUNT1 = 0; COUNT1 <= SIZE - 1; COUNT1++)
//          FOR(COUNT2 = 0; COUNT2 <= SIZE - 1; COUNT2++){
//              IF (FLOOR[COUNT1] [COUNT2] == 1)
//                      PRINTF(@)
//              ALTRIMENTI
//                      PRINTF( )}
//          PRINTF(\N)
// }
//
//###########################################################################################################################
//###########################################################################################################################

#include <stdio.h>
#define SIZE 50
void menu(int command[]);
int writeon(void);
int writeoff(void);
void right(void);
void left(void);
void go();
void stampa(void);
int x = 25 , y = 25, fm = 0, to = SIZE - 1 , asc = 1 , ord = 0 , penna = 0 , command[15] = {0};
int flor [SIZE] [SIZE] = {0};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int count = 0;
    
    menu(command);
    
    do{
        switch (command[count]){
            case 1:
                printf("\nChiamo writeoff()\n");
                penna = writeoff();
                count++;
                break;
            case 2:
                printf("\nChiamo writeon()\n");
                penna = writeon();
                count++;
                break;
            case 3:
                printf("\nChiamo right()\n");
                right();
                count++;
                break;
            case 4:
                printf("\nChiamo left()\n");
                left();
                count++;
                break;
            case 5:
                count++;
                printf("\nChiamo go()\n");
                go(command[count]);
                count++;
                break;
            case 6:
                printf("\nChiamo stampa()\n");
                stampa();
                count++;
                break;
            case 9:
                printf("\nEsco\n");
                break;
        }
        
    }while(command[count] != 9);
    
    
    printf("\nHello, World!\n");
    return 0;
}

void menu(int command[]){
    
    int count = 0;
    
    do{
        printf("\n1 Alza la penna");
        printf("\n2 Abbassa la penna");
        printf("\n3 Gira a destra");
        printf("\n4 Gira a sinistra");
        printf("\n5 Vai avanti di 10 spazi (o di un numero diverso da 10)");
        printf("\n6 Visualizza la Matrice");
        printf("\n9 Esci : ");
        scanf("%d",&command[count]);
        
        if (command[count] == 5){
            count++;
            printf("\n1 x 10 avanzamenti 2 x castomizzare: ");
            scanf("%d",&command[count]);
            
            if(command[count] == 1)
                command[count] = 10;
            else{
                do{
                    printf("Imettere il numero di avanzamenti [0 - 49]: ");
                    scanf("%d",&command[count]);
                }while(command[count] < 0 || command[count] > 49);
            }
        }
        
        
    }while(command[count++] != 9);
 
    printf("\nStampa dell'array command[] \n");
    for(count = 0; count <= 14; count++)
        printf("\ncommand[%d] = %d",count,command[count]);
}

int writeon(void){
    printf("\nPenna attva\n");
    return 1;
}

int writeoff(void){
    printf("Penna non attiva");
    return 0;
}

void right(void){
    if (ord == 1){
    
        ord = 0;
        asc = 1;
    
        if (fm == 0){
            
            fm = SIZE - 1;
            to = 0;
            
        }else{
            fm = 0;
            to = SIZE - 1;
        }
    
    }else{
    
        asc = 0;
        ord = 1;
    
        if( fm == SIZE - 1){
            
            fm = SIZE - 1;
            to = 0;
    
        }else{
            
            fm = 0;
            to = SIZE - 1;
        }
    }
}

void left(void){

    if(ord == 1){
      
        ord = 0;
        asc = 1;

        if(fm == 0){
            
            fm = 0;
            to = SIZE - 1;

        }else{
            
            fm = SIZE - 1;
            to = 0;
        }
    }else{

        ord = 1;
        asc = 0;

        if (fm == 0){
            
            fm = SIZE - 1;
            to = 0;

        }else{
            
            fm = SIZE - 1;
            to = 0;
        }
    }
}

void go(int posizioni){
    int count = 0;
    
    if(asc){
    
        if(fm == 0){
            count = (posizioni + x) > 50 ? 50 : posizioni + x;
            printf("\nValore di count: %d valore di penna: %d \n",count,penna);
                  while (x <= count){
                      if(penna == 1)
                          flor [y] [x++] = 1;
                      else
                          x++;
                  }
        }else{
            count = x - posizioni  < 0 ? 0 : x - posizioni;
            printf("\nValore di count: %d valore di penna: %d \n",count,penna);
                  while (x >= count){
                      if (penna == 1)
                          flor [y] [x--] = 1;
                      else
                          x--;
                  }
        }
        
    }else{
    
        if(fm == 0){
            count = posizioni + y > 50 ? 50 : posizioni + y;
            printf("\nValore di count: %d valore di penna: %d \n",count,penna);
     while(y <= count){
                      if (penna == 1)
                          flor [y++] [x] = 1;
                      else
                          y++;
                  }
        }else{
            count = y - posizioni  < 0 ? 0 : y - posizioni;
            printf("\nValore di count: %d valore di penna: %d \n",count,penna);
                  while (y >= count){
                      if (penna == 1)
                          flor [y--] [x] = 1;
                      else
                          y--;
                  }
        }
        
    
}
}

void stampa(void){
    
    int count1, count2;
    
    for(count1 = 0; count1 <= SIZE - 1; count1++){
            for(count2 = 0; count2 <= SIZE - 1; count2++){
                if(flor[count1] [count2] == 1)
                    printf("@");
                else
                    printf("-");
            }
        printf("\n");
    }
}
