//
//  main.c
//  Exe6.31
//
//  Created by Francesco Parrucci on 09/03/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*(BUCKET SORT) UN BUCKET SORT INCOMINCIA DICHIARANDO UN VETTORE UNIDIMENSIONALE DI INTERI POSITIVI, QUELLO CHE DOVRAÌ ESSERE ORDINATO , E UNA MATRICE DI INTERI CON LE RIGHE INDICIZZATE DA 0A 9 E LE COLONNE DA 0 A N-1, DOVE N EÌ IL NUMERO DEI VALORI PRESENTI NEL VETTORE CHE DOVRA' ESSERE ORDINATO . OGNI RIGA DELLA MATRICE E' DETTA BUCKET (SECCHIO). SCRIVETE UNA FUNZIONE bucketSort CHE RICERVA COME ARGOMENTI UN VETTORE DI INTERI E LA SUA DIMENSIONE. 
L'ALGORITMO E' IL SEGUENTE :

1) SCORRETE IL VETTORE UNIDIMENSIONALE E SISTEMATE OGNUNO DEI SUOI VALORI IN UNA RIGA DELLA MATRICE, BASSANDOVI SULLA CIFRA DELLE UNITA'. PER ESEMPIO, IL 97 SARA' SISTEMATO NELLA RIVA 7 , IL 3 SARA' INSERITO NELLA RIGA 3 E IL 100 SARA' POSTO NELLA RIGA 0.

2) SCORRETE LA MATRICE E RIPORTATE I VALORI NEL VETTORE ORIGINARIO. NEL VETTORE UNIDIMENSIONALE IL NUOVO ORDINE DEI SUDDETTI VALORI SARA' 100, 3 E 97.

3) RIPETETE QUESTO PROCESSO PER OGNI SUCCESSIVA POSIZIONE DELLE CIFRE (DECINE , CENTINAIA,  MIGLIAIA ECC.) E FERMATEVI QUANDO SARA' STATA ELABORATA LA CIFRA PIU' SIGNIFICATIVA DEL NUMERO PIU' GRANDE.

AL TERMINE DEL SECONDO PASSAGGIO SUL VETTORE, IL 100 SARA' SISTEMATO NELLA RIGA 0, IL 3 SARA' INSERITO NELLA RIGA 0 O (POICHE HA SOLO UNA CIFRA) E IL 97 SARA' POSTO NELLA RIGA 9. L'ORDINE DEI VALORI NEL VETTORE UNIDIMENSIONALE SARA' A QUESTO PUNTO :100 , 3, E 97.AL TERMINE DEL TERZO PASSAGGIO,  IL 100 SARA' SISTEMATO NELLA RIGA 1, IL 3 E IL 97 SARANNO INSERITI NELLA RIGA 0 (IL 97 DOPO IL 3).IL BUCKET SORT GARANTISCE CHE TUTTI I VALORI SARANNO ORDINATI APPROPRIATAMENTE, DOPO CHE SARA' STATA ELABORATA LA CIFRA PIU' SIGNIFICATIVA DEL NUMERO PIU' GRANDE. IL BUCKET SORT SAPRA' DI AVERE TERMINATO IL PROPRIO COMPITO, QUANDO TUTTI I VALORI SARANNO STATI RICOPIATI NELLA RIGA 0 DELLA MATRICE.
OSSERVATE CHE LA MATRICE AVRA' UNA DIMENSIONE PARI A 10 VOLTE QUELLA DEL VETTORE DI INTERI DA ORDINARE. QUESTA TECNICA E' PIU' EFFICIENTE DI QUELLA DELL' ORDINAMENTO A BOLLE, MA RICHIEDE UNA CAPACITÀ DI MEMORIA NOTEVOLMENTE SUPERIORE . L'ORDINAMENTO A BOLLE RICHIEDE SOLO UNA POSIZIONE DI MEMORIA IN PIU' PER IL TIPO DI DATO DA ORDINARE. IL BUCKET SORT È UN ESEMPIO DI COMPROMESSO TRA CONSUMO DI MEMORIA ED EFFICIENZA: E' VERO CHE UTILIZZA PIU' MEMORIA, MA È ANCHE VERO CHE È PIU' EFFICIENTE. QUESTA VERSIONE DEL BUCKET SORT RICHIEDE CHE PER OGNI PASSAGGIO I DATI SIANO RIPORTATI NEL VETTORE ORIGINALE. SI POTREBBE ANCHE CREARE UNA SECONDA MATRICE E SPOSTARE RIPETUTAMENTE I DATI TRA LE DUE MATRICI, FINCHE' NON SIANO STATI RICOPIATI TUTTI NELLA RIGA 0 DI UNA DELLE DUE. A QUEL PUNTO LA RIGA 0 CONTERREBBE IL VETTORE ORDINATO.
*/
