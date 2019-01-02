//
//  main.c
//  Exe3.36
//
//  Created by Francesco Parrucci on 31/12/18.
//  Copyright © 2018 Francesco Parrucci. All rights reserved.
//
/* 
 PRENDETE IN INPUT UN INTERO CONTENENTE SOLTATNO DELI 0 E 1, OVVEROSIA UN INTERO BINARIO E VISUALIZZATE IL SUO EQUIVALENTE
 DECIMALE. PER PRELEVARE LE CIFRE DEL NUMERO BINARIO UNA PER VOLTA DA DESTRA A SINISTRA UTILIZZATE GLI OPEATORI DI DIVISIONE E
 MODULO. NEL SISTEMA NUMERICO DECIMALE LA CIFRA PIU A DESTRA HA UN VALORE POSIZIONALE DI 1 E QUELLE CHE SI SUSSEGUONO A
 SENISTRA HANNO UN VALORE POSIZIONALE DI 10, POI 100, POI 1000 ECC. ALLO STESSO MODO NEL SISTEMA NUMERICO BINARIO LA CIFRA PIU
 A DESTRA HA UN VALORE POSIZIONALE DI 1 E QUELLE CHE SI SUSSEGUONO A SINISTRA HANNO UN VALORE POSIZIONALE DI 2, POI 4, POI 8,
 ECC. DI CONSEGUENZA IL NUMERO 234 POTRA' ESSERE INTERPRETATO COME 4 * 1 + 3 * 10 + 2 * 100. L'EQUIVALENTE DECIMALE DEL BINARIO
 11101 SARA 1 * 1 + 0 * 2 + 1 * 4 + 1 * 8  O 1 + 0 + 4 + 8 O 13.
*/
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : CONVERTIRE UN NUMERO BINARIO IN NUMERO DECIMALE
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// INIZIALIZZARE LE VARIABILI
//###########################################################################################################################
//###########################################################################################################################
// PRENDERE IN INPUT UN NUMERO BINARIO
// CONVERTI IL BINARIO IN NUMERO DECIMALE E MEMORIZZALO NELLA VARIABILE DECIMAL
// STAMPA IL VALORE
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE E INIZIALIZZAZIONE DELLE VARIABILI BINARY, DECIMAL = 0, COUNT = 1, DIVISORE = 10, SENTINEL = 1, BIN = 2.
//###########################################################################################################################
//###########################################################################################################################
// INSERIRE UN NUMERO BINARIO IN BINARY
// DIVIDERE IL BINARY PER 10 MOLTIPLICARE IL RESTO PER BIN E ASSEGNARE IL RISULTATO A DECIMAL
// ASSEGNARE A BINARY BINARY DIVISO 10 MOLTIPRICA BIN PER 2
// SE BINARY E' UGUALE A ZERO ESCI
//###########################################################################################################################
//###########################################################################################################################
// STAMPLA IL RISULTATO
//###########################################################################################################################
//###########################################################################################################################

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int binary , decimal = 0, count = 1, divisore = 10, sentinel = 1 , bin = 2;
    
    printf("Inserisci un numero binario tipo 101010 : ");
    scanf("%d",&binary);
    
    while(binary > 0){
        decimal += (binary % 10) * bin;
        bin *= 2;
        binary /= 10;
    }
    
    printf("Numero decimale: %d\n", decimal);
    return 0;
}
