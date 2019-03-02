//
//  main.c
//  Exe6.22
//
//  Created by Francesco Parrucci on 21/02/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
UTILIZZATE UNA MATRICE PER RISOLVERE IL SEGUENTE PROBLEMA. UN'AZIENDA HA QUATTRO VENDITORI (NUMERATI DA 1 A 4) CHE VENDONO 
CINQUE DIFFERENTI PRODOTTI (NUMERATI DA 1 A 5). UNA VOLTA AL GIORNO, OGNUNO DEI VENDITORI FORNISCE UN TAGLIANDO PER OGNI TIPO
DI PRODOTTO VENDUTO. OGNI TAGLIANDO CONTIENE:
 
 1. IL NUMERO DEL VENDITORE
 2. IL NUMERO DEL PRODOTTO 
 3. IL VALORE TOTALE ESPRESSO IN DOLLARI DEL VENDUTO GIORNALIERO DI QUEL PRODOTTO.
 
 DI CONSEGUENZA OGNI VENDITORE FORNISCE TRA 0 E 5 TAGLIANDI AL GIORNO. SUPPONETE CHE SIANO DISPONIBILI I DATI DEI TAGLIANDI 
 DELL'ULTIMO MESE. SCRIVETE UN PROGRAMMA CHE LEGGA LE SUDDETTE INFORMAZIONI, RIGUARDANTI IL VENDUTO DELL'ULTIMO MESE, E SOMMI
 LE VENDITE TOTALI PER VENDITORE E PER PRODOTTO, TUTTI I TOTALI DEVRANNO ESSERE IMMAGAZZINATI NELLA MATRICE SALES. DOPO AVERE 
 ELABORATO TUTTE LE INFORMAIZONI DELL'ULTIMO MESE, VUSUALIZZATE I RISULTATI IN FORMATO TABULARE IN MODO CHE LE COLONNE
 RAPPRENENTINO I VARI VENDITORE E LE RIGHE RAPPRESENTINO I SINGOLI PRODOTTI, SOMMATE OGNI RIGA, IN MODO DA OTTENERE LE VENDITE
 TOTALI DELL0ULTIMO MESE PER OGNUNO DEI PRODOTTIM SOMMATE OGNI COLONNA , IN MODO DA OTTENERE IL TOTALE DELLE VENDITE 
 DELL'ULTIMO MESE PER OGNUNO DEI VENDITORI, LA VOLSTRA SATAMPA TABULARE DOVRA INCLUDERE IL SUDDETTI TOTALI A DESTRA DELLE
 RIGHE I IN FONDO ALLE COLONNE.
 */
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : MEMORIZZAZIONE SOMMA E STAMPA VENDITE PRODOTTI PER DIVERSI VENDITORI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE STRUTTURE DATI E FUNZIONI
// ACQUISIRE DATI PER UN PERIODO DI TEMPO
// STAMPA LA SOMMA DEI VALORI ACQUISITI PER VENDITORE (COLONNE) PRODOTTO (RIGHE) TOTALE (COLONNA A DESTRA)
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE STRUTTURE E FUNZIONI:
// -- PROTOTIPO DI FUNZIONE MENU (1 INSERIRE 2 STAMPA 0 ESCI)
// -- PROTOTIPO DI FUNZIONE INSERT (INT SALES [] [6],INT VENDITORE, INT PRODOTTO , INT TOTALE)
// -- PROTOTIPO DI FUNZIONE STAMPA PER STAMPA TOTALE
//
//###########################################################################################################################
//###########################################################################################################################
//#################################################### MAIN #################################################################
//###########################################################################################################################
//###########################################################################################################################
//
// DIHIARAZIONE MATRICE SALES [5] [6]
//
// SCELTA = MENU
//
// CHIEDERE AD UTENTE SE VUOLE INSERIRE UNA VENDITA O SE VUOLE STAMPARE LA MATRICE
//
//  SE SCELTA == 1
//      CHIAMARE FUNZIONE INSERT (SALES [] [])
//  ALTRIMENTI
//      RICHIAMA LA FUNIZONE STAMPA (SALES [] [])
//
// FINCHE' SCELTA E' DIVERSO DA 0 CONTINUA
//
//###########################################################################################################################
//###########################################################################################################################
//################################################# FUNZIONE INSERT #########################################################
//###########################################################################################################################
//###########################################################################################################################
//
// VOID INSERT (INT SALES [] [6])
//
// INT VENDITORE , PRODOTTO , TOTALE;
//
// CHIEDI NUMERO VENDITORE E MEMORIZZA IN VENDITORE
// CONTINUA FINCHE' VENDITORE < 1 E VENDITORE > 4
//
// CHIEDI NUMERO PRODOTTO E MEMORIZZA IN PRODOTTO
// CONTINUA FINCHE' PRODOTTO < 1 E PRODOTTO > 5
//
// CHIEDI IL TOTALE DA INSERIRE E MEMORIZZA IN TOTALE
// CONTINUA FINCHE' TOTALE < 0
//
// SALES[VENDITORE] [PRODOTTO] += TOTALE;
//
//###########################################################################################################################
//###########################################################################################################################
//################################################# FUNZIONE STAMPA #########################################################
//###########################################################################################################################
//###########################################################################################################################
//
// VOID STAMPA (INT SALES [] [6])
//
// INT VENDITORE , PRODOTTO, TOT;
//
// STAMPA (%10S PRODOTTO 1 PRODOTTO 2 PRODOTTO 3 PRODOTTO 4 PRODOTTO 5 TOTALI, "          ")
//
// FOR (VENDITORE = 1 ; VENDITORE <= 4 ; VENDITORE++)
//   STAMPA (VENDITORE %D,VENDITORE)
//     FOR(TOT = 0, PRODOTTO = 1; PRODOTTO <= 5; PRODOTTO++)
//         STAMPA (%10D, SALES[VENDITORE] [PRODOTTO])
//         TOT += SALES[VENDITORE] [PRODOTTO]
//     STAMPA(%10D, TOT)
//
// STAMPA (%10S , "TOTALI")
//
// FOR (PRODOTTO = 1 PRODOTTO <= 5 PRODOTTO++)
//    FOR (TOT = 0, VENDITORE = 1 VENDITORE <= 4 VENDITORE++)
//      TOT += SALES[VENDITORE] [PRODOTTO]
//    STAMPA (%10D, TOT)
//
//###########################################################################################################################
//###########################################################################################################################
//################################################# FUNZIONE MENU ###########################################################
//###########################################################################################################################
//###########################################################################################################################
//
// INT MENU (VOID)
//
// INT SCELTA;
//
// STAMPA "1 PER INSERIRE"
// STAMPA "2 PER STAMPARE"
// STAMPA "0 PER USCIRE"
// FATE LA VS SCELTA:
// MEMORIZZA IN SCELTA
// CONTINUA FINCHE' SCELTA < 0 E SCELTA > 2
//
// RETURN SCELTA
//
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>

int menu(void);
void insert (int sales [] [6]);
void stampa (int sales [] [6]);

int main(int argc, const char * argv[]) {
    // insert code here...
    int sales [5] [6] = {0}, scelta = 3;
    
    do{
        scelta = menu();
        switch (scelta){
            case 1:
                insert(sales);
                break;
            case 2:
                stampa(sales);
                break;
            default:
                break;
        }
    }while(scelta != 0);
        
    printf("Hello, World!\n");
    return 0;
}

int menu(void){
    int scelta;
    
    do {
        printf("\n1 PER INSERIRE");
        printf("\n2 PER STAMPARE");
        printf("\n0 PER USCIRE.");
        printf("\nFai la tua scelta: ");
        scanf("%d",&scelta);
    }while(scelta < 0 || scelta > 2);
    
    return scelta;
}

void insert (int sales [] [6]){
    int venditore, prodotto, totale;
    
    do {
        printf("\nInserire il numero del venditore: ");
        scanf("%d",&venditore);
    }while(venditore < 1 || venditore > 4);
    
    do {
        printf("\nInserire il numero del prodotto: ");
        scanf("%d",&prodotto);
    }while(prodotto < 1 || prodotto > 5);
    
    
    do {
        printf("\nInserire il totale: ");
        scanf("%d",&totale);
    }while(totale < 0);
    
    sales [venditore] [prodotto] += totale;
    
}

void stampa (int sales [] [6]){
    int venditore, prodotto, tot;
    
    printf("\n%12s PRODOTTO 1 PRODOTTO 2 PRODOTTO 3 PRODOTTO 4 PRODOTTO 5 TOTALE"," ");
    
    for (venditore = 1; venditore <= 4; venditore++){
        printf("\nVENDITORE %d ",venditore);
        for(tot = 0, prodotto = 1; prodotto <= 5 ; prodotto++){
            printf("%11d",sales[venditore] [prodotto]);
            tot += sales [venditore] [prodotto];}
        printf("%10d",tot);
    }

    printf("\n%-12s","Totali:");
    
    for(prodotto = 1 ; prodotto <= 5; prodotto++){
        for(tot = 0, venditore = 1; venditore <= 4 ; venditore++)
            tot += sales[venditore] [prodotto];
        printf("%11d",tot);}
}
