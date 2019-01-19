//
//  main.c
//  Exe4.17
//
//  Created by Francesco Parrucci on 13/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 RISCUOTERE IL DENARO DIVENTA SEMPRE PIU DIFFICILE NEI PERIODI DI RECESSIONE, PER QUESTO MOTIVO LE AZIENDE POTREBBERO
 RESTRINGERE I LORO LIMITI DI CREDITO, PER EVITARE CHE I PROPRI CONTI DI CREDITO (IL DENARO LORO DOVUTO) DIVENTINO TROPPO
 SOSTANZIOSI. COME RISPOSTA A UNA RECESSIONE PROLUNGATA , UNA AZIENDA HA DIMEZZATO IL LIMITE DI CREDITO DEI PROPRI CLIENTI. DI
 CONSEGUENZA , SE UN PARTICOLARE CLIENTE AVESSE AVUTO UN LIMITE DI CREDITO DI $2000, QUESTO SAREBBE ORA DI $1000. SE UN AVESSE
 AVUTO UN LIMITE DI CREDITO DI $5000, QUESTO SAREBBE ORA DI $2500. SCRIVETE UN PROGRAMMA CHE ANALIZZI LO STATO DI CREDITO PER
 TRE CLIENTI DI QUESTA AZIENDA. PER GNI CLIENTE VI SARANNO FORNITI:
 
 1) IL NUMERO DI CONTO DEL CLIENTE ; 
 
 2)IL LIMITE DI CREDITO DEL CLIENTE PRIMA DELLLA RECESSIONE;
 
 3)IL SALDO CORRENTE DEL CLIENTE (VALE A DERE, L'AMMONTARE CHE IL CLIENTE DEVE ALL'AZIENDA).
    
 IL VOSTRO PROGRAMMA DOVRA' CALCOLARE E VISUALIZZARE IL NUOVO LIMITE DI CREDITO PER OGNI CLIENTE E DOVRA' ANCHE DETERMINARE
 (E VISUALIZZARE QUALI DI LORO  HANNO DEI SALDI CORRENTI CHE ECCEDONO IL LORO NUOVO LIMITE DI CREDITO.
 */
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : CALCOLO DEL SALDO E DEL LIMITE DI CREDITO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI:
// RIPETERE LE SEGUENTI ISTRUZIONI PER TRE VOLTE
// ACQUISIZIONE DATI
// CALCOLO
// STAMPA
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI:
// -- VARIABILE CONTATORE;
// -- NUOVO LIMITE DI CREDITO;
// -- NUMEROD DI CONTO;
// -- LIMITE DI CREDITO DEL CLIENTE PRIMA DELLA RECESSIONE;
// -- SALDO CORRENTE(AMMONTARE CHE DEVE ALL'AZIONDA);
//###########################################################################################################################
//###########################################################################################################################
// ESEGUIRE LE SEGUENTI ISTRUZIONI PER TRE VOLTE
//###########################################################################################################################
//###########################################################################################################################
// ACQUISIZIONE DATI:
// -- RACCOGLIERE IN INPUT NUMERO CONTO DEL CLIENTE
// -- RACCOGLIERE IN INPUT IL LIMETE DI CREDITO DEL CLIENTE PRIMA DELLA RECESSIONE
// -- RACCOGLIERE IN INPUT IL SALDO (AMMONTARE CHE DEVE ALL'AZIENDA)
//###########################################################################################################################
//###########################################################################################################################
// CALCOLO:
// -- DIMEZZARE IL VALORE DI LIMITE CREDITO E ASSEGNARE A NUOVO LIMITE DI CREDITO
//###########################################################################################################################
//###########################################################################################################################
// STAMPA
// -- VISUALIZZA NUOVO LIMITE DI CREDITO;
// -- SE IL SALDO E' MAGGIORE DEL NUOVO LIMITE DI CREDITO VISUALIZZA AVVERTIMENTO
//###########################################################################################################################
//###########################################################################################################################

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int count, num_conto;
    float saldo, limite_credito, nuovo_limite;
    
    for(count = 1 ; count <= 3; count++){
        printf("\nInserire il numero di conto: ");
        scanf("%d",&num_conto);
        printf("Inserire il limete di credito: ");
        scanf("%f",&limite_credito);
        printf("Inserire il saldo del cliente: ");
        scanf("%f",&saldo);
        printf("\n\nCodice cliente: %d",num_conto);
        printf("\nLimete del credito %.2f",limite_credito / 2);
        printf("\nSaldo attuale :-%.2f",saldo);
        saldo < limite_credito / 2 ? printf("\n") : printf("\nAttenzione il saldo attuale è superiore al limite del credito!!!\n");
            
    }
    return 0;
}
