//
//  main.c
//  Exe6.21
//
//  Created by Francesco Parrucci on 17/02/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
(SISTEMA DI PRENOTAZIONE PER LINEE AEREE) UNA PICCOLA COMPAGNIA AEREA HA APPENA COMPRATO UN COMPUTER PER IL SUO NUOVO SISTEMA 
 DI PRENOTAZIONE AUTOMATICA. IL PRESIDENTE VI HA CHIESTO DI PROGRAMMARE IL NUOVO SISTEMA IN C. VOI DOVETE SCRIVERE UN PROGRAMMA 
 CHE ASSEGNI I POSTI SU OGNI VOLO DELL'UNICO AEREO DELL'AEROLINEA (CAPACITA' 10 POSTI).
 IL VOSTRO PROGRAMMA DOVRA' VISUALIZZARE IL SEGUENTE MENU DI SCELTE:
 
 Please type 1 for "smoking"
 Please type 2 for "nonsmoking"
 
 NEL CASO CHE IL CLIENTE DIGITI 1, ALLORA IL VOSTRO PROGRAMMA DOVRA' ASSEGNARE UN POSTO NELLA SEZIONE FUMATORI (QUELLI DA 1 A 
 5). NEL CASO CHE IL CLIENTE DIGITI 2, ALLORA IL VOSTRO PROGRAMMA DOVRA' ASSEGNARE UN POSTO NELLA SEZIONE NON FUMATORI (QUELLI 
 DA 6 A 10). IL VOSTRO PROGRAMMA DOVRA' QUINDI STAMPARE UNA CARTA D'IMBARCO CHE DOVRA' INDICARE IL NUMERO DI POSTO ASSEGNATO AL 
 PASSEGGERO E SE QUELLO SI TROVA NELLA SEZIONE FUMATORI O NON FUMATORI DELL'AEROPLANO.
 UTILIZZATE UN VETTORE INIDIMENSIONALE PER RAPPRESENTARE LA MAPPA DEI POSTI SULL'AEREO. AZZERATE TUTTI GLI ELEMENTI DEL VETTORE 
 IN MODO DA INDICARE CHE TUTTI I POSTI SONO VUOTI. MAN MANO CHE I POSTI SARANNO STATI ASSEGNATI, IMPOSTERETE A 1 L'ELEMENTO 
 CORRISPONDENTE DEL VETTORE IN MODO DA INDICARE CHE IL POSTO NON è PIU DISPONIBILE.
 NATURALMENTE, IL VOSTRO PROGRAMMA NON DOVRA' MAI ASSEGNARE UN POSTO CHE SIA GIA' STATO ASSEGNATO. QUANDO LA SEZIONE FUMATORI 
 SARA' PIENA, IL VOSTRO PROGRAMMA DOVRA' CHIEDERE AL CLIENTE SE SIA DISPOSTO AD ACCETTARE UNA SISTEMAIZONE NELLA SEZIONE DEI 
 NON FUMATORI (E VICEVERSA). ESEGUITE L'APPROPRIATA ASSEGNAZIONE DI POSTO, QUALORA LA SUA RISPOSTA SIA AFFERMATIVA. 
 VISUALIZZATE IL MESSAGGIO "NEXT FLIGHT LEAVES IN 3 HOURS" ("IL PROSSIMO VOLO DECOLLERA' FRA 3 ORE"), QUALORA LA SUA RISPOSTA 
 SIA NEGATIVA.
*/
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : SISTEMA DI PRENOTAZIONE POSTI AEREI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI E FUNZIONI:
// ACQUISIRE LA SCELTA DEL VIAGGIATORE E ASSEGNARE UN POSTO
// STAMPA DELLA CARTA D'IMBARCO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI E FUNZIONI:
// -- COSTANTE SIMBOLICA SIZE = 11
// -- PROTOTIPO DI FUNZIONE STAMPA CARTA D'IMBARCO void stampa(int [] , int count)
// -- PROTOTIPO DI FUNZIONE int prenotazione (int [])
// -- VARIABILE INT COUNT = 0, POSTI[SIZE], X;
//###########################################################################################################################
//###########################################################################################################################
// FINCHE' COUNT E' MINORE O UGUALE A 10
// -- COUNT = COUNT + prenotazione(posti, segnaposto);
// -- stampa(posti);
//###########################################################################################################################
//###########################################################################################################################
// DEFINIZIONE DELLA FUNZIONE int prenotazione(int posti[], int segnaposto)
// DICHIARA LE SEGUENTI VARIABILI:
// -- INT SCELTA = 0, SMOKE = 0, NOSMOKE = 0, COUNT, RET = 0
// -- CAHAR QUESTION = 'A'
//
// CICLO FOR COUNT DA 1 A 10 PER DETERMINARE AD OGNI CHIAMATA IL NUMERO DEI POSTI INSERITI FUMATORI E NON
//
// -- IF COUNT >  5 E DIVERSO DA 0
//    INCREMENTA DI UNO NOSMOKE
//
// -- ALTRIMENTI SE COUNT < 5 E DIVERSO DA 0
//    INCREMENTA DI
//
// SE IL NUMERO DI POSTI SULL'AEROPLANO E' UGUALE A 10 STAMPA LA SEGUENTE FRASE:
//
// -- Posti disponibili terminati. Il prossimo aereo decollera fra 3 ore. precedere y o n per terminare: ";
// -- PONI LA VARIABILE RET  = 0 ; PER USCITA
//
// ALTRIMENTI:
//
// RICHIEDI 1  PER POSTI FUMATORI E 2  PER NON FUMATORI E MEMORIZZA IL VALORE IN VARIABILE SCELTA
//
//     -- SE SCELTA E' UGUALE A 1
//
//         -- SE SMOKE <= 4
//
//              ASSEGNA A POSTI[1 + SMOKE] = SEGNAPOSTO
//              PONI RET UGUALE A 1
//
//         -- ALTRIMENTI
//
//             -- SE NOSMOKE <= 4
//
//                  INFORMA CHE I POSTI FUMATORI SONO TERMINATI E CHE SONO DISPONIBILI SOLO POSTI NON FUMATORI.
//                  INOLTRE COMUNICA CHE IL PROSSIMO AEREO DECOLLERA' FRA 3  ORE. RICHIEDI Y O N PER TERMINARE
//                  MEMORIZZA L'INPUT NELLA VARIABILE QUESTION
//
//                 -- SE QUESTION == A 'Y' O 'Y'
//
//                      POSTI[6 + NOSMOKE] = SEGNAPOSTO
//                      RET = 1
//
//                 -- ALTRIMENTI
//
//                      RET = 0;
//
//             -- ALTRIMENTI
//
//                  RET = 0;
//
//     -- SE SCELTA E' UGUALE A 2
//
//         -- SE NOSMOKE <= 4
//
//              ASSEGNA A POSTI[6 + NOSMOKE] = SEGNAPOSTO
//              PONI RET UGUALE A 1
//
//         -- ALTRIMENTI
//
//             -- SE SMOKE <= 4
//
//                  INFORMA CHE I POSTI NON FUMATORI SONO TERMINATI E CHE SONO DISPONIBILI SOLO POSTI FUMATORI.
//                  INOLTRE COMUNICA CHE IL PROSSIMO AEREO DECOLLERA' FRA 3  ORE. RICHIEDI Y O N PER TERMINARE
//                  MEMORIZZA L'INPUT NELLA VARIABILE QUESTION
//
//                 -- SE QUESTION == A 'Y' O 'Y'
//
//                      POSTI[1 + SMOKE] = SEGNAPOSTO
//                      RET = 1
//
//                 -- ALTRIMENTI
//
//                      RET = 0;
//
//             -- ALTRIMENTI
//
//                  RET = 0;
//
//
//  RITORNA IL VALORE DI RET
//
//###########################################################################################################################
//###########################################################################################################################
// DEFINIZIONE DELLA FUNZIONE STAMPA POSTI
// STAMPA --------------------------------------
// STAMPA | POSTO     | PRENOTAZIONE           |
// -- PER COUNT = 1 COUNT <= 10 COUNT++
//  -- STAMPA | POSTO  %4D | PRENOTAZIONE N. %4D |
//  -- STAMPA ------------------------------------
//###########################################################################################################################
//###########################################################################################################################

#include <stdio.h>
#define SIZE 11
void stampa(int []);
int prenotazione(int [], int );

int main(int argc, const char * argv[]) {
    // insert code here...
    int count = 1, posti[SIZE] = {0}, x;
    
    //for(x = 1 ; x <= 10 ; x++)
    //    printf("\nreturn of prenotazione : %d",prenotazione(posti, x));
    while(count <= 10)
        count += prenotazione(posti, count);
    stampa(posti);
    printf("\nHello, World!\n");
    return 0;
}

int prenotazione(int posti[], int segnaposto){
    char question = 'a';
    int scelta = 0, smoke = 0, nosmoke = 0, count, ret = 0;
    
    for(count = 1; count <= 10 ; count++)
        if(posti[count] != 0){
            if(count > 5)
                nosmoke++;
            else
                smoke++;
        }
    printf("\nValore di no smoke : %d valore di nosmoke : %d",smoke,nosmoke);
    
    if((smoke + nosmoke) >=  10){
        printf("\nPosti diponibili terminati.\n");
        printf("Il prossimo aereo decollera fra 3 ore. procedere y o n per terminare: ");
        ret = 0;
    }else{
        do{
            printf("\n1 per posto Fumatori. 2 per posto non fumatori: ");
            scanf("%d",&scelta);
        }while(scelta < 1 ||  scelta > 2);
        
        if (scelta == 1){

            if(smoke <= 4){
                posti[1 + smoke] = segnaposto;
                ret = 1;
            }else{
                if(nosmoke <= 4){
                        do{
                        getchar();
                        printf("\nPosti fumatori terminati, disponibili solo posti non fumatori\n");
                        printf("Il prossimo aereo decollera fra 3 ore. procedere y o n per terminare: ");
                        question = getchar();
                        }while(!(question != 'y' || question != 'Y' || question != 'n' || question != 'N'));
        
                    if(question == 'y' || question == 'Y'){
                        posti[6 + nosmoke] = segnaposto;
                        ret = 1;}
                    else
                        ret = 0;
                }else
                    ret = 0;
            }
        }
        
        if(scelta == 2){
        
            if(nosmoke <= 4){
                posti[6 + nosmoke] = segnaposto;
                ret = 1;
            }else{
                if(smoke <= 4){
                    do{
                    getchar();
                    printf("\nPosti non fumatori terminati, disponibili solo posti non fumatori\n");
                    printf("Il prossimo aereo decollera fra 3 ore. procedere y o n per terminare: ");
                    question = getchar();
                    }while(!(question != 'y' || question != 'Y' || question != 'n' || question != 'N'));
            
                    if(question == 'y' || question == 'Y'){
                        posti[1 + smoke] = segnaposto;
                        ret = 1;}
                    else
                        ret = 0;
            }else
                ret = 0;
            }
        }
    }
return ret;
}


    

void stampa(int posti[]){
    int count;
    
    printf("\n________________________________\n");
    printf("|Posti      | Prenotazione      |\n");
    printf("--------------------------------\n");
    for(count = 1; count <= 10 ; count++)
        printf("|Posto %4d | Prenotazione %4d |\n", count, posti[count]);
    printf("_________________________________\n");
        
    
}