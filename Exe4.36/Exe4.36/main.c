//
//  main.c
//  Exe4.36
//
//  Created by Francesco Parrucci on 19/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 SCRIVETE UN PROGRAMMA CHE PRENDA IN INPUT UN ANNO COMPRESO NELL'INTERVALLO DAL 1994 AL 1999 E UTILIZZI UNA ITERAZIONE CON UN 
 CICLO FOR PER PRODURRE UN CALENDARIO COMPRENDIATO, VISUALIZZATO IN MODO ORDINATO. ATTENTI AGLI ANNI BISESTILI.
 */

//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : VISUALIZZA UN CALENDARIO DAL DEGLI ANNI DAL 1994 AL 1999
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI:
// RICEVERE IN INPUT L'ANNO DI RIFERIMENTO
// STAMPARE IL CALENDARIO
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI:
// -- VARIABILE INT  ANNO, MESE ,START ;
// -- VARIABILI INT COUNT
//###########################################################################################################################
//###########################################################################################################################
// RICEVRE IN INPUT UN ANNO DI RIFERIMENTO
// -- DIGITARE L'ANNO TRA 1994 E 1999
// -- CONTROLLO INPUT
//
// CONSIDERARE IL GIORNO CON IL QUALE INIZIA L'ANNO DI RIFERIMENTO
// -- SETTARE UN CONTATORE A 365 ED AGGIUNGERE 365 PER LA DIFFERENZA TRA ANNO INSERITO E 1994
// -- AGGIUNGERE I GIORNI I PIU AL CONTATORE PER GLI ANNI BISESTILI INCLUSI NEL PERIODO
// -- SETTARE LA VARIABILE START A 6 ( SABATO 1 GENNAIO 1994)
// -- FINCHE' COUNT E' > DI UNO
//      -- DECREMENTA COUNT DI UNO
//      -- SE START == 7 START = 1 ALTRIMENTI INCREMENTALO DI UNO
//
// STAMPARE IL CALENDARIO
// -- STAMPARE INTESTAZIONE DELL'ANNO
// -- PER MESI DA 1 A 12
// -- CONTROLLARE IL MESE SE (1,3,5,7,8 ,10 e 12) IMPOSTARE UN CONTATORE A 31
// -- CONTROLLARE IL MESE SE (2 E ANNO BISESTILE 1996) IMPOSTARE UN CONTATORE A 29 ALTRIMENTI 28
// -- CONTROLLARE IL MESE SE (4,6,9 E 11) IMPOSTARE A 30 IL CONTATORE
//
//    -- STAMPA IL NOME DEL MESE E VAI A CAPO
//       -- FINCHE' IL CONTATORE GIORNI E' MAGGIORE DI 0
//       -- PER START DA 1 A 7 (LUN - DOM) STAMPA IL GIORNO (LUN - DOM) INCREMENTA START SE MINORE DI 7 ALTRIMENTI = 1 E DECREMENTA
//          IL CONTATORE GIORNI
// -- STAMPA UN RITORNO A CAPO INCREMENTA IL CONTATORE MESI E RIPETI IL CICLO DI STAMPA PER I GIORNI DEL MESE.
//
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int count = 0, start = 6, anno, mese, giorni;
    
    do{
        printf("Immettere l'anno");
        scanf("%d",&anno);
    }while(anno < 1994 || anno > 1999);
    
    count += 365 + ((anno - 1994) * 365);
    
    if(anno == 1996)
        count += 1;
    else if((anno - 1996) % 4 == 0)
        count += (anno - 1996) / 4;

    while(count-- > 1)
        if(start == 7)
            start = 1;
        else
            start++;

    
printf("\n\t\tCalendario %d\n\n",anno);

    
    for(mese = 1 ; mese <= 12; mese++){
        switch (mese){
        case 1:
            printf("\nGennaio\n");
            giorni = 31;
            break;
        case 2:
            printf("\nFebbraio\n");
            giorni = anno % 4 == 0 ? 29 : 28;
            break;
        case 3:
            printf("\nMarzo\n");
            giorni = 30;
            break;
        case 4:
            printf("\nAprile\n");
            giorni = 30;
            break;
        case 5:
            printf("\nMaggio\n");
            giorni = 31;
            break;
        case 6:
            printf("\nGiugno\n");
            giorni = 30;
            break;
        case 7:
            printf("\nLuglio\n");
            giorni = 31;
            break;
        case 8:
            printf("\nAgosto\n");
            giorni = 31;
            break;
        case 9:
            printf("\nSettembre\n");
            giorni = 30;
            break;
        case 10:
            printf("\nOttobre\n");
            giorni = 31;
            break;
        case 11:
            printf("\nNovembre\n");
            giorni = 30;
            break;
        case 12:
            printf("\nDicembre\n");
            giorni = 31;
            break;
        default:
            break;
        }
        
        while (giorni-- > 0){
            switch (start){
            case 1:
                printf(" LUN ");
                break;
            case 2:
                printf(" MAR ");
                break;
            case 3:
                printf(" MER ");
                break;
            case 4:
                printf(" GIO ");
                break;
            case 5:
                printf(" VEN ");
                break;
            case 6:
                printf(" SAB ");
                break;
            case 7:
                printf(" DOM ");
                break;
            default:
                break;
            }
         
            if(start == 7)
                start = 1;
            else
                start++;
        }
        
        printf("\n");
    }
    
    
        
    return 0;
}
