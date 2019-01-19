//
//  main.c
//  Exe4.28
//
//  Created by Francesco Parrucci on 17/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 UNA AZIENDA RETRIBUISCE I PROPRI DIPENDENTI DISTINGUENDOLI TRA MANAGER ( CHE RICEVONO UN SALARIO FISSO SETTIMANALE).
 LAVORATORI A ORE ( CHE RICEVONO UNA PAGA ORARIA FISSA PER LE PRIME 40 ORE DI LAVORO E "UN'ORA E MEZZA", OVVEROSIA 1,5 VOLTE LA
 PAGA ORARIA, PER LE ORE DI STRAORDINARIO EFFETTUATE) , LAVORATORI A PROVVIGIONE (CHE RICEVONO $250 PIU IL 5,7% DELLE LORO
 VENDITE LORDE SETTIMANALI) , OPPURE LAVORATORI A COTTIMO (CHE RICEVONO UNA CIFRA FISSA DI DENARO AD ARTICOLO, PER OGNUNO DI
 QUELLI PRODOTTI; IN QUESTA AZIENDA OGNI LAVORATORE A COTTIMO LAVORA SOLTANTO SU UN TIPO DI ARTICOLO. SCRIVETE UN PROGRAMMA CHE 
 CALCOLI LA PAGA SETTIMANALE DI OGNI DIPENDENTE. NON CONOSCETE IN ANTICIPO IL NUMERO DI DIPENDENTI. OGNI TIPO DI DIPENDENTE HA
 IL PROPRIO CODICE DI PAGAMENTO: I MANAGER HANNO 1, I LAVORATORI A ORE HANNO 2, QUELLI A PROVVIGIONE HANNO 3 E QUELLI A COTTIMO 
 HANNO 4. UTILIZZATE UNA STRUTTURA SWITCH PER CALCOLARE LA PAGA DI OGNI DIPENDENTE IN BASE AL SUO CODICE DI PAGAMENTO.
 ALL'INTERNO DELLA STRUTTURA SWITCH , RICHIEDETE ALL'UTENTE )OVVEROSIA ALL'IMPIEGATO ADDETTO ALLE PAGHE  DI IMMETTERE I DATI
 APPROPRIATI DI CUI IL VOSTRO PRIGRAMMA AVRA' BISOGNO PER CALCOLARE LA PAGA DI OGNI DIPENDENTE, IN BASE ALA PROPRIO CODICE DI
 PAGAMENTO.
 */
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP :
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE VARIABILI E ACQUISIZIONE DATI
// CICLO WHILE USCITA CON EOF (CTRL D)
// VERIFICA CATEGORIA LAVORATORE
// CALCOLO STIPENDIO SETTIMANALE
// STAMPA I DETTAGLI
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI:
// -- VARIABILE INT CODICE LAVORATORE;
// -- VARIABILI FLOAT BUFFER;
//###########################################################################################################################
//###########################################################################################################################
// ACQUISIZIONE DATI
// -- RICHIEDERE CODICE LAVORATORE
//###########################################################################################################################
//###########################################################################################################################
// CICLO WHILE PREMI UN TASTO PER CONTINUARE O EOF PER TERMINARE
// -- VERIFICA CATEGORIA LAVORATORE STRUTTURA SWITCH
//      -- SE CODICE E' 1 LAVORATORE MANAGER STAMPA PAGA SETTIMANALE
//      -- SE CODICE E' 2 LAVORATORE A ORE RICHIEDERE NUMERO ORE LAVORATE NELLA SETTIMANA
//          -- SE LE ORE SONO MINORI O UGUALI A 40 STAMPA PAGA SETTIMANALE ( ORE * 5 )
//          -- SE LE ORE SONO MAGGIORI DI 40 STAMPA ( 40 * 5 ) + ( (ORE - 40) * 7.5)
//      -- SE CODICE E' 3 LAVORATORE A PROVVIGIONE IL TOTALE LORDO DELLE VENDITE SETTIMANALI
//          -- STAMPA PAGA SETTIMANALE UGUALE A $ 250 + 5.7% DELLA QUANTITA' LORDA DEGLI ARTICOLI VENDUTI
//      -- SE CODICE E' 4 LAVORATORE A COTTIMO ACQUISIRE IL TIPO DI ARTICOLO E IL NUMERICO PRODOTTO
//          -- STAMPA PAGA SETTIMANALE UGUALE A PREZZO UNITARIO * NUMERICO PRODOTTO
// -- RICHIEDI CODICE LAVORATORE
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int codice , prodotto ,number;
    float buffer = 0;
    printf("Codice Lavoratore\n1) Manager 1\n2) Lavoratore a ore 2\n3) Lavoratore a provvigioni 3\n4) Lavoratore a cottimo 4\n:");
   
    while ((codice = getchar()) != EOF){
    
        switch (codice) {
            case '1':
                printf("\nPaga settimanale del Manager: $1000.\n");
                printf("Codice Lavoratore\n1) Manager 1\n2) Lavoratore a ore 2\n3) Lavoratore a provvigioni 3\n4) Lavoratore a cottimo 4\n:");
                break;
            case '2':
                printf("\nInserire il numero delle ore lavorate:");
                scanf("%f",&buffer);
                buffer <= 40 ? printf("Paga settimanale per %.2f ore : %.2f",buffer, buffer * 5) : printf("Paga settimanale per %.2f ore : %.2f",buffer, 40 * 5 + (buffer - 40) * 7.5);
                printf("Codice Lavoratore\n1) Manager 1\n2) Lavoratore a ore 2\n3) Lavoratore a provvigioni 3\n4) Lavoratore a cottimo 4\n:");
                break;
            case '3':
                printf("\nInserire il totale lordo delle vendite settimanali : ");
                scanf("%f",&buffer);
                printf("\nPaga settimanale per lavoratore a provvigioni: %.2f", 250 + buffer * 5.7 / 100);
                printf("Codice Lavoratore\n1) Manager 1\n2) Lavoratore a ore 2\n3) Lavoratore a provvigioni 3\n4) Lavoratore a cottimo 4\n:");
                break;
            case '4':
                buffer = 0;
                do{
                printf("\nInserire il codice prodotto: \n1) prodotto 1\n2) prodotto 2\n3) prodotto 3\n:");
                scanf("%d",&prodotto);
                }while(prodotto < 1 || prodotto > 3);
                
                    switch (prodotto){
                        case 1:
                            buffer = 5;
                            break;
                        case 2:
                            buffer = 6;
                            break;
                        case 3:
                            buffer = 7;
                            break;
                        default:
                            break;
                        }

                printf("\nSeleziona il numerico prodotto : ");
                scanf("%d",&number);
                printf("\nPaga Lavaratore a cottimo : %.2f\n", buffer * number);
                printf("\nCodice Lavoratore\n1) Manager 1\n2) Lavoratore a ore 2\n3) Lavoratore a provvigioni 3\n4) Lavoratore a cottimo 4\n:");
                break;
            case '\n':
                break;
            default:
                printf("\nSelezione non corrispondente\n");
                printf("Codice Lavoratore\n1) Manager 1\n2) Lavoratore a ore 2\n3) Lavoratore a provvigioni 3\n4) Lavoratore a cottimo 4\n:");
                break;
        }
    
        
    }
   return 0;
}
