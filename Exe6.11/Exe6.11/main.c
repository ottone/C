//
//  main.c
//  Exe6.11
//
//  Created by Francesco Parrucci on 09/02/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*

L'ORDINAMENTO A BOLLE PRESENTATO NELLA FIGURA 6.15 E' INEFFICIENTE PER VETTORI DI GRANDI DIMENSION. APPORTATE LE SEGUENTI
SEMPLICI MODIFICHE IN MODO DA MIGLIORARE L'EFFICIENZA DELL'ORDINAMENTO A BOLLE.
 
 A) DOPO IL PRIMO PASSAGGIO, IL NUMERO PIU' GRANDE SARA' STATO SICURAMENTE SISTEMATO NELL'ELEMENTO CON L'INDICE PIU' ALTO DEL 
 VETTORE; DOPO IL SECONDO PASSAGGIO, I DUE NUMERI PIU GRANDI SARANNO "A POSTO" E COSI VIA. INVECE DI ESEGUIRE NOVE CONFRONTI AD 
 OGNI PASSAGGIO, MODIFICATE L'ORDINAMENTO A BOLLE COSI' CHE ESEGUA OTTO CONFRONTI NEL SECONDO PASSAGGIO, SETTE NEL TERZO  E 
 COSI VIA.
 
 B) I DATI NEL VOTTORE POTREBBERO GIA' ESSERE NELL'ORDINE APPROPRIATO O IN UNO VICINO A QUESTO, PERCIO' PERCHE' ESEGUITE NOVE
 PASSAGGI QUANDO NE POTREBBERO BASTARE MENO? MODIFICATE L'ORDINAMENTO A BOLLE, IN MODO DA VERIFICATE SE ALLA FINE DI OGNI 
 PASSAGGIO SIANO STATI ESEGUITI DEGLI SCAMBI. NEL CASO CHE NON NE SIANO STATI ESEGUITI, ALLORA I DATI SARANNO GIA' NELL'ORDINE 
 APPROPRIATO, PERCIO' IL PROGRAMMA DOVRA' TERMINARE LA PROPRIA ESECUZIONE. NEL CASO INVECE CHE SIANO STATI ESEGUITI DEGLI 
 SCAMBI, SARA' NECESSARIO ALMENO UN ALTRO PASSAGGIO.

*/

/* This program sorts an array's values into ascending order */

#include <stdio.h>
#define SIZE 10

int main()
{
    int a[SIZE] = {89, 2, 4, 8, 10, 12, 37, 45, 70, 1};
    int i, pass, hold, test = 0;
    
    printf("Data items in original order\n");
    
    for (i = 0; i <= SIZE - 1; i++)
        printf("%4d", a[i]);
    
    for (pass = 1; pass <= SIZE - 1; pass++){               /* passes */
            for (i = 0; i <= SIZE - (pass +  1); i++)       /* one pass */
                if (a[i] > a[i + 1]) {                      /* one comparison */
                    test++;
                    hold = a[i];                            /* one swap */
                    a[i] = a[i + 1];
                    a[i + 1] = hold;
                }
        
    if(test == 0){
        printf("\nVettore ordinato al %d ciclo! Esco.\n",pass);
            break;}
        else
            test = 0;
    }
    printf("\nData items in ascending order\n");
    
    for (i = 0; i <= SIZE - 1; i++)
        printf("%4d", a[i]);
    
    printf("\n");
    
    return 0;
}
