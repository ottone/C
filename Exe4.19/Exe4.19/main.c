//
//  main.c
//  Exe4.19
//
//  Created by Francesco Parrucci on 14/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 UN AZIENDA DI VENDITA PER CORRISPONDENZA VENDE CIQUE DIFFERENTI PRODOTTI I CUI PREZZI AL DETTAGLIO SONO MOSTRATI NELLA
 SEGHENTE TABELLA:
----------------------------------------------------
| NUMERO PRODOTTO  |            PREZZO AL DETTAGLIO|
| --------------------------------------------------                                                |
| 1                |              2.98             |
| 2                |              4.50             |
| 3                |              9.98             |
| 4                |              4.49             |
| 5                |              6.87             |
----------------------------------------------------
 
SCRIVETE UN PROGRAMMA CHE LEGGA UNA SERIE DI COPPIE DI NUMERI COME SEGUE:
 
1) NUMERO DI PRODOTTO;
2) QUANTITA' VENDUTA IN UN GIORNO.

IL VOSTRO PROGRAMMA DOVRA' UTILIZZARE SWITCH PER AIUTARE A DETERMINARE IL PREZZO AL DETTAGLIO DI OGNI PRODOTTO. IL VOSTRO
PROGRAMMA DOVRA CALCOLARE E VISUALIZZARE IL VALORE TOTALE AL DETTAGLIO DI TUTTI I PRODOTTI VENDUTI NELL'ULTIMA SETTIMANA
*/
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : CALCOLO PRODOTTI VENDUTI NELL'ULTIMA SETTIMANA
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI:
// RIPETERE LE SEGUENTI ISTRUZIONI FINCHE' NON SI SIANO INSERITE TUTTE LE VENDITE
// INSERIRE UN NUMERO DI PRODOTTO
// INSERIRE UNA QUANTITA'
// STAMPA DEI DETTAGLI E DEL TOTALE
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI:
// -- VARIABILE CHAR CARATTERE;
// -- VARIABILI FLOAT UNO , DUE , TRE , QUATTRO , CINQUE E TOTAL;
// -- VARIABILE INT NUMERO PRODOTTO E QUANTITA' PRODOTTO.
//###########################################################################################################################
//###########################################################################################################################
// ESEGUIRE LE SEGUENTI ISTRUZIONI FINCHE' CARATTERE E' UGUALE A Y O y
//###########################################################################################################################
//###########################################################################################################################
// ACQUISIZIONE DATI:
// -- RACCOGLIERE IN INPUT NUMERO PRODOTTO E QUANTITA' VENDUTA
//###########################################################################################################################
//###########################################################################################################################
// CALCOLO:
// -- CONFRONTARE IL NUMERO DEL PRODOTTO CON STRUTTURA DI SELEZIONE SWITCH
// -- SE LA SELEZIONE NON E' RISCONTRATA INSERIRE AVVERTIMENTO IN CLAUSOLA DEFAULT
// -- MOLTIPLICARE QUANTITA' PER PREZZO INDICATO NEL CASE DELLA SELEZIONE SWITCH E ASSEGNARE IL VALORE ALLA VARIABILE DEL
//    PRODOTTO
//###########################################################################################################################
//###########################################################################################################################
// STAMPA
// -- VISUALIZZA I RISULTATI PER DETTAGLIO DEL NUMERO DI PRODOTTI E IL TOTALE.
//###########################################################################################################################
//###########################################################################################################################


 #include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    char carattere;
    float uno = 0, due = 0, tre = 0, quattro = 0, cinque = 0;
    int num_prodotto, quantita;
    
    printf("Hai venduto prodotti? EOF (CTRL + D) per terminare: ");
    while((carattere = getchar()) != EOF){
        
        printf("Inserire il numero di prodotto (1 - 5): ");
        scanf("%d",&num_prodotto);
        
        printf("Inserire la quantità venduta: ");
        scanf("%d",&quantita);
        
        switch (num_prodotto){
            
            case 1:
                uno += 2.98 * quantita;
                break;
                
            case 2:
                due += 4.50 * quantita;
                break;
            
            case 3:
                tre += 9.98 * quantita;
                break;
            
            case 4:
                quattro += 4.49 * quantita;
                break;
                
            case 5:
                cinque += 6.87 * quantita;
                break;
                
            default:
                printf("Selezione sbagliata!");
                break;
        }
        
    }
        printf("\nSTAMPA DELLE VENDITE SETTIMANALI:\n");
        printf("#################################\n");
        printf("PRODOTTO NUMERO UNO     : %.2f.\n",uno);
        printf("PRODOTTO NUMERO DUE     : %.2f.\n",due);
        printf("PRODOTTO NUMERO TRE     : %.2f.\n",tre);
        printf("PRODOTTO NUMERO QUATTRO : %.2f.\n",quattro);
        printf("PRODOTTO NUMERO CINQUE  : %.2f.\n",cinque);
        printf("#################################\n");
        printf("TOTALE : %.2f.", uno + due + tre + quattro + cinque);
    
    
    return 0;
}
