//
//  main.c
//  Exe3.21
//
//  Created by Francesco Parrucci on 30/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//
/*
 SVILUPPATE UN PROGRAMMA C CHE DETERMINI LA PAGA LORDA PER OGNUNO DEI DEVERSI IMPIEGATI. L'AZIENDA PER LE PRIME 40 ORE LAVORATE
 DA OGNI IMPIEGATO, PAGA IL "SALARIO ORARIO DI BASE", MENTRE PER TUTTE LE ORE LAVORATE IN AGGIUNTA ALLE 40, ELARGISCE "UNA VOLTA
 E MEZZA IL SALARIO DI BASE". VI SONO STATI FORNITI: UNA LISTA DEGLI IMPIEGATI DELL'AZIENDA , IL NUMERO DI ORE LAVORATE DA OGNI
 IMPIEGATO NELL'ULTIMA SETTIMANA E IL SALARIO ORARIO DI BASE DI OGNI IMPIEGATO. IL VOSTRO PROGRAMMA DOVRA' PRENDERE IN INPUT, PER
 OGNI IMPIEGATO, LE SUDDETTE INFORMAZIONI E DEVRA' QUINDI DETERMINARE E VISUALIZZARE LA PAGA LORDA DI OGNUNO DI LORO.
 */
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : CALCOLO SALARIO LORDO COMPOSTO DA UNA BASE PER LE PRIME 40 ORE, E INCREMENTO DI UNA VOLTA E MEZZA PER OGNI ORA SUCCESSIVA
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// INIZIALIZZARE LE VARIABILI NUMERO DI ORE SETTIMANALI, RETRIBUZIONE ORARIA E SALARIO
// FINCHE' IL VALORE DELLE ORE SETTIMANALI E DIVERSO DA -1 CALCOLO SALARIO
// VISUALIZZA SALARIO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE E INIZIALIZZAZIONE DEL ORE SETTIMANALI DEL WORKER , RETRIBUZIONE ORARIA E SALARIO
//###########################################################################################################################
//###########################################################################################################################
// INSERISCI ORE SETTIMANALI -1 PER TERMINARE
// FINCHE' ORE SETTIMANALI SONO DIVERSE DA -1 CONTINUA
// INSERISCI PAGA ORARIA
// CALCOLO DEL SALARIO
// VISUALIZZA IL SALARIO
// INSERISCI ORE SETTIMANALI -1 PER TERMINARE
//###########################################################################################################################
//###########################################################################################################################

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int ore;
    float paga_oraria, salario;
    
    // insert code here...
    printf("\nInserisci ore settimanali del Worker: ");
    scanf("%d",&ore);
    while(ore > -1){
        printf("Inserisci paga paga oraria del Worker: ");
        scanf("%f", &paga_oraria);
        printf("Salario settimanale : %2.f\n", salario = paga_oraria * (ore <= 40 ? ore : 40 ) +  paga_oraria * 1,5 * (ore > 40 ? ore - 40 : 0));
    }
    return 0;
}
