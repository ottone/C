//
//  main.c
//  Exe3.18
//
//  Created by Francesco Parrucci on 29/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//

/*  SVILUPPATE UN PROGRAMMA IN C CHE DETERMINI SE IL CLIENTE DI UN GRANDE MAGAZZINO ABBIA SUPERATO IL LIMITE DI CREDITO SUL SUO CONTO. PER OGNI CLIENTE SARANNO DISPONIBILI I SEGUENTI DATI :

    1 IL NUMERO DI CONTO
    2 IL SALDO ALL'INIZIO DEL MESE
    3 IL TOTALE DI TUTTI GLI ARTICOLI CHE IL CLIENTE HA MESSO IN CONTO, DURANTE IL MESE CORRENTE
    4 IL TOTALE DI TUTTI I CREDITI APPLICATI AL CONTO DI QUESTO CLIENTE, DIRANTE IL MESE CORRENTE.
    5 IL LIMITE DI CREDITO CONCESSO
 
   IL PROGRAMMA DOVRA' PRENDERE IN INPUT TUTTI QUESTI DATI CALCOLARE IL NUOVO SALDO (= SALDO INIZIALE + ARTICOLI MESSI IN CONTO
   -CREDITI) E DETERMINARE SE IL NUOVO SALDO  SUPERI IL LIMITE DI CREDITO DEL CLIENTE. PER QUEI CLIENTI CHE AVRANNO SUPERATO IL
   LIMITE DI CREDITO, IL PROGRAMMA DOVRA' VISUALIZZARE IL LORO NUMERO DI CONTO, IL LIMITE DI CREDITO, IL NUOVO SALDO E IL
   MESSAGGIO "CREDIT LIMIT EXCEEDED".
*/
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : PROGRAMMA DI GESTIONE DEL CONTO CLIENTE DI UN GRANDE MAGAZZINO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE E INIZIALIZZAZIONE DELLE VARIABILI
// ACQUISIZIONE DATI NUMERO CONTO E ARTICOLI ACQUISTATI
// VISUALIZZA SALDO E LIMITI DEL CREDITO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE E INIZIALIZZAZIONE DELLE VARIABILI NUMERO CONTO, SALDO INIZIO MESE, TOTALE ARTICOLI MESSI IN CONTO, TOTALE
// DEI CREDITI APPLICATI E LIMITE DI CREDITO CONCESSO
//###########################################################################################################################
//###########################################################################################################################
// INSERISCI IL NUMERO DI CONTO
// FINCHE' IL COSTO DI ARTICOLO E' DIVERSO DA -1  O MINORE DI SALDO CLIENTE + CREDITO CLIENTE CONTINUA
// INSERISCI COSTO DI UN ARTICOLO
// SOMMA COSTO ARTICOLO A TOTALE ARTICOLI MESSI IN CONTO
//###########################################################################################################################
//###########################################################################################################################
// SE TOTALE ARTICOLI MESSI IN CONTO E' MAGGIORE O UGUALE A SALDO + CREDITO STAMPA UN MESSAGGIO CREDIT LIMIT EXCEEDED
// SE SALDO E' MAGGRIORE DI TOTALE ARTICOLI IN CONTO STAMPA SALDO MENO TOTALE ARTICOLI MESSI IN CONTO
// SE SALDO E' MINORE DI TOTALE ARTICOLI IN CONTO SOMMA SALDO A CREDITO. SOTTRAI TOTALE ARTICOLI MESSI IN CONTO E STAMPA CREDITO
//###########################################################################################################################
//###########################################################################################################################

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int num_conto;
    float saldo = 1000, tot_articoli = 0, crediti = 500, articolo = 0;
    
    printf("Numero del conto: ");
    scanf("%d", &num_conto);
    
    printf("Numero conto %d\nSaldo iniziale : %.2f\n",num_conto, saldo);
    
    printf("\n...inizio shopping...\n");
    
    while (articolo > -1 && saldo + crediti > tot_articoli){
        printf("Costo di un articolo: ");
        scanf("%f", &articolo);
        tot_articoli += articolo;
    }
    
    if (saldo + crediti < tot_articoli)
        printf("\nCREDIT LIMIT EXCEEDED!\n");
    else if (tot_articoli > saldo)
        printf("Saldo mese corrente 0. Crediti residui: %.2f\n", crediti -= tot_articoli - saldo);
    else
        printf("Saldo mese corrente %.2f. Crediti : %.2f\n", saldo -= tot_articoli, crediti);
        
    return 0;
}
