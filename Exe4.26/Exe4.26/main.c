//
//  main.c
//  Exe4.26
//
//  Created by Francesco Parrucci on 17/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 CALCOLATE IL VALORE DI π A PARTIRE DALLA SERIE INFINITA:
 
 π  = 4 - 4/3 + 4/5 - 4/7 + 4/9 - 4/11 ....
 
 VISUALIZZATE UNA TABELLA CHE MOSTRI IL VALORE DI ∏ APPROSSIMATO DA UNO, DUE, TRE ... TERMINI DI QUESTA SERIE. QUANTI TERMINI
 DI QUESTA SERIE DOVRETE UTILIZZARE, PRIMA DI OTTENERE 3.14 ? 3.141 ?  3.1415 ? 3.14159 ?
 */

//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : VISUALIZZARE SERIE DI PITAGORA PER UN FINITO NUMERO DI VALORI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI:
// RIPETERE LE SEGUENTI ISTRUZIONI FINO A TERMINE SERIE
// PER NUMERI DISPARI DEL CONTATORE DIVIDI QUATTRO PER IL CONTATORE
// ADDIZIONA O SOTTRAZIONA IN BASE AL VALORE DI UNA VARIABILE SENTINELLA
// STAMPA I DETTAGLI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI:
// -- VARIABILE INT CONTATORE = 1 E SEGNO = 0;
// -- VARIABILI FLOAT ∏ = 0;
//###########################################################################################################################
//###########################################################################################################################
// ESEGUIRE LE SEGUENTI ISTRUZIONI FINCHE' CONTATORE E' MINORE DI UN VALORE NOTO (ESEMPIO 20)
//###########################################################################################################################
//###########################################################################################################################
// PER CONTATORE UGUALE A 1 CONTATORE MINORE DI 20 E CONTATORE INCREMENTATO DI DUE CALCOLA:
// -- SE SEGNO E' DIVERSO DA ZERO
//    -- ∏ E' UGUALE A ∏ + 4 / CONTATORE E PONI SEGNO UGUALE A 0
// -- ALTRIMENTI
//    -- ∏ E' UGUALE A ∏ - 4 / CONTATORE E PONI SEGNO UGUALE A 1
//###########################################################################################################################
//###########################################################################################################################
// STAMPA
// -- VISUALIZZA I RISULTATI PER DETTAGLIO OPERAZIONE PER OTTENERE ∏.
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int count, count1, count3 = 0, segno = 0, decimale;
    float π = 0;
    
    printf("\nInserisci il valore decimale della serie di π (esempio x 3,141456 inserisci solo 141456):");
    scanf("%d",&decimale);
    
    for (count = 1, count1 = 1; count <= 30000 ; count += 2, count1++){
        if(segno){
            π = π - (float)(4.0 / count);
            segno = 0;
        }else{
            π = π + (float)(4.0 / count);
            segno = 1;
        }
        
        if ( ((int)π == 3 && ( (int)((π - 3) * 1000000) == decimale) ) && count3 == 0){
            printf("Ciclo %d , π = %f %s 4/%d.\n",count1,π ,segno ? "-" : "+",count);
            count3++;
        }
        
        
       
        
    }
        
    


return 0;
}
