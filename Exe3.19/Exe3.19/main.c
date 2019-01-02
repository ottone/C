//
//  main.c
//  Exe3.19
//
//  Created by Francesco Parrucci on 29/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//
/*
    UNA GRANDE INDUSTRIA CHIMICA RETRIBUISCE I PROPRI VENDITORI BASANDOSI SULLE PROVVIGIONI. IL VENDITORE RICEVE $200 LA
    SETTIMANA PIU IL 9 PER CENTO DELLE PROPRIE VENDITE LORDE PORTATE A TERMINE DURANTE LA SETTIMANA. PER ESEMPIO, UN VENDITORE
    CHE IN UNA SETTIMANA VENDA PRODOTTI CHIMICI PER UN VALORE DI $5000, RICEVERA' $200 PIU IL 9 PER CENTO DI $ 5000 OVVEROSIA
    UN TOTLAE DI $650. SCRIVETE UN PROGRAMMA C CHE PRENDA IN INPUT LE VENDITE LORDE DI OGNI VENDITORE PER L'ULTIMA SETTIMANA E
    QUINDI CALCOLI E VISUALIZZI IL SALARIO PER OGNUNO DI LORO. ELABORATE I CONTI PER UN VENDITORE PER VOLTA
 */

//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : CALCOLO DEL SALARIO SETTIMANALE SU BASE COMPONENTE FISSA E PROVVIGIONI DEL 9%
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE E INIZIALIZZAZIONE DELLE VARIABILI
// ACQUISIZIONE DELLE VENDITE EFFETTUATE NELLA SETTIMANA E SOMMA AL TOTALE
// CALCOLA E VISUALIZZA SALARIO SETTIMANALE
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE E INIZIALIZZAZIONE DELLE VARIABILI TOTALE VENDITE, VENDITA, SALARIO SETTIMANALE
//###########################################################################################################################
//###########################################################################################################################
// FINCHE' IL VALORE DELLA VENDITA E' DIVERSO DA -1 CONTINUA
// INSERISCI VALORE DI UNA VENDITA
// SOMMA VENDITA A TOTALE VENDITE
//###########################################################################################################################
//###########################################################################################################################
// CALCOLA IL 9% DEL TOTALE VENDITE E SOMMA 200 PER OTTENERE IL SALARIO SETTIMANALE
// STAMPA IL SALARIO
//###########################################################################################################################
//###########################################################################################################################

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    float tot_vendite = 0, vendita = 0, salario_settimanale = 200;
    
    while (vendita > -1){
        printf("Inserire valore della vendita (-1 per terminalre): ");
        scanf("%f", &vendita);
        tot_vendite += vendita;
    }
    
    printf("Salario settimanale: %.2f\n", tot_vendite = (tot_vendite * 9) / 100 + 200);
    return 0;
}
