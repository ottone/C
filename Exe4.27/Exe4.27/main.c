//
//  main.c
//  Exe4.27
//
//  Created by Francesco Parrucci on 17/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 (TERNE PITAGORICHE) UN TRIANGOLO RETTANGOLO PUO' AVERE LATI CHE SIANO TUTTI INTERI. L'INSIEME DEI TRE VALORI INTERI PER I LATI
 DI UN TRIANGOLO RETTANGOLO E' DETTO TERNA PITAGORICA. QUESTI TRE LATI DEVONO SODDISFARE LA RELAZIONE SECONDO LA QUALE LA SOMMA
 DEI QUADRATI DEI DUE CATETI E' UGUALE AL QUADRATO DELLA IPOTENUSA. TROVATE TUTTE LE TERNE PITAGORICHE PER LATO1, LATO2 E
 IPOTENUSA CHE NON SIANO MAGGIORI DI CINQUECENTO. UTILIZZATE UN TRIPLO CICLO FOR NIDIFICATO CHE PROVI SEMPLICEMENTE TUTTE LE
 POSSIBILITA'. QUESTO E' UN ESEMPRIO DI ELABORAZIONE CON "FORZA BRUTA". NON PIACE A MOLTI DAL PUNTO DI VISTA ESTETICO. ESISTONO
 PERO' MOLTE RAGIONI PER CUI QUESTE TECNICHE SONO IMPORTANTI. IN PRIMO LUOGO, CON L'INCREMENTO DELLA POTENZA DI CALCOLO A UN
 RITMO COSO FENOMENALE, LE SOLUZIONI CHE AVREBBERO RICHIESTO ANNI O ADDIRITTURA SECOLI DI ELABORAIZON, PER ESSERE OTTENUTE CON
 LA TECNOLOGIA DI SOLO UN PO'DI ANNI FA, OGGIGIORNO POTREBBERO ESSERE OTTENUTE IN ORE , IN MINUTI O ADDIRITTURA IN SECONDI! IN 
 SECONDO LUOGO, COME APPRENDERETE NEI CORSI PIU AVANZATI DI INFORMATICA, CìE UN GRAN NUMERO DI PROBLEMI INTERESSANTI PER I
 QUALI NON ESISTE NESSUN APPROCCIO ALGORITMICO NOTO DIVERSO DA QUELLO DELLA FORZA BRUTA. IN QUESTO LIBRO INVESTIGHEREMO SU
 MOLTI TIPO DI METODOLOGIE PER LA SOLUZIONE DEI PROBLEMI. CONSIDEREREMO MOLTI APPROCCI CON FORZA BRUTA A DIVERSI PROBLEMI
 INTERESSANTI.
 */
//################################################### SVILUPPO TOP DOWN #####################################################
//###########################################################################################################################
// TOP : TROVARE LE TERNE PITAGORICHE A 1 A 500
//###########################################################################################################################
//###########################################################################################################################
//################################################### 1° RAFFINAMENTO   #####################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARARE LE VARIABILI:
// ASSUMERE UN NUMERO DA 1 A 500
//    ASSUMERE UN NUMERO 1 A 500
//      ASSUMERE UN NUMERO 1 A 500
//          SE LA SOMMA DEI QUADRATI DEI NUMERI UNO E DUE E' UGUALE AL QUADRATO DEL TERZO NUMERO SI TRATTA DI UNA TERNA
//###########################################################################################################################
//###########################################################################################################################
//################################################### 2° RAFFINAMENTO #######################################################
//###########################################################################################################################
//###########################################################################################################################
// DICHIARAZIONE DELLE VARIABILI:
// -- VARIABILE INT COUNT1 COUNT2 COUNT3
//###########################################################################################################################
//###########################################################################################################################
// PER COUNT1 DA 1 A 500:
//      PER COUNT2 DA 1 A 500:
//          PER COUNT3 DA 1 A 500:
//              SE SOMMA DEI QUADRATI DI COUNT1 E COUNT2 E' UGUALE AL QUADRATO DI COUNT3 E' UNA TERNA
//###########################################################################################################################
//###########################################################################################################################


#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int count1 ,count2, count3;
    
    for(count1 = 1; count1 <= 500 ; count1++)
        for(count2 = 1; count2 <= 500; count2++)
            for(count3 = 1; count3 <= 500; count3++)
                if(((int)pow(count1,2) + (int)pow(count2, 2) == (int)pow(count3,2)))
                   printf("\nLato %d , Lato %d e Ipotenusa %d sono una terna pitagorica.\n",count1,count2,count3);
    
    return 0;
}
