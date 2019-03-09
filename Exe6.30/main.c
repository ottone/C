//
//  main.c
//  Exe6.30
//
//  Created by Francesco Parrucci on 09/03/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*(IL CRIVELLO DI ERATOSTENE) UN NUMERO PRIMO E' QUALSIASI INTERO CHE POSSA ESSERE DIVISO SOLTANTO PER SE STESSO E PER 1. IL CRIVELLO DI ERATOSTENE E' APPUNTO UN METODO PER TROVARE I NUMERI PRIMI. ESSO FUNZIONA COME SEGHE:

1) CREATE UN VETTORE CON TUTTI GLI ELEMENTI INIZIALIZZATI A 1 (VERO). GLI ELEMENTI DEL VETTORE I CUI INDICI CORRISPONDANO A UN NUMERO PRIMO RESTERANNO A 1. AL TERMINE DELLA ELABORAZIONE, TUTTI GLI ALTRI ELEMENTI DEL VETTORE SARANNO AZZERATI.

2) PARTENDO DALL'INDICE 2 DEL VETTORE (L'INDICE 1 E' PRIMO PER DEFINIZIONE), QUALORA IL VALORE DELL'ELEMENTO PUNTATO SIA 1, SCORRETE IL RESTO DEL VETTORE E AZZERATE GLI ELEMENTI I CUI INDICI SIANO MULTIPLI DI QUELLO DELL'ELEMENTO PUNTATO. NEL CASO DELL'INDICE 2, SARANNO AZZERATI TUTTI GLI ELEMENTI SUCCESSIVI DEL VETTORE CON INDICI CHE SIANO MULTIPLI DI 2 (OVVEROSIA GLI INDICI 4,6,8,10, ECC.)  NEL CASO DELL'INDICE 3, SARANNO AZZERATI TUTTI GLI ELEMENTI SUCCESSIVI DEL VETTORE CON INDICI CHE SIANO MULTIPLI DI 3 (OVVEROSIA GLI INDICI 6, 9, 12, 15, ECC).

NEL MOMENTO IN CUI QUESTO PROCESSO SARA' STATO COMPLETATO, GLI ELEMENTI DEL VETTORE CHE CONTERRANNO ANCORA IL VALORE UNO INDICHERANNO CHE IL LORO INDICE E' UN NUMERO PRIMO E, DI CONSEGENZA, CHE POTRA' ESSERE VISUALIZZATO. SCRIVETE UN PROGRAMMA CHE UTILIZZI UN VETTORE DI 1000 ELEMENTI PER DETERMINARE E VISUALIZZARE I NUMERI PRIMI COMPRESI TRA 1 E 999. IGNORATE L'ELEMENTO 0 DEL VETTORE.
*/

 
