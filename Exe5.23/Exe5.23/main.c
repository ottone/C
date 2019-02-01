//
//  main.c
//  Exe5.23
//
//  Created by Francesco Parrucci on 27/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 

 SCRIVETE UNA FUNZIONE CHE ACCETTI IN INPUT L'ORA. SUDDIVISA IN TRE ARGOMENTI INTERI (PER LE ORE . I MINUTI E I SECONDI), E
 RESTITUISCA IL NUMERO DEI SECONDI TRASCORSI DALL'ULTIMA COLTA CHE L'OROLOGIO "HA RINTOCCATO LE 12". UTILIZZATE QUESTA FUNZIONE
 PER CALCOLARE LA QUANTITA DI TEMPO IN SECONDI CHE INTERCORRE TRA DUE ORARI, ENTRAMBI I QUALI SIANO COMPRESI ALL'INTERNO DI UN
 CICLO DI 12 ORE DELL'OROLOGIO
 
*/
#include <stdio.h>

long howSeconds(int, int, int);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int ore, minuti , secondi;
    
    do{
        printf("\nInserisci l'ora minuti e secondi correnti: ");
        scanf("%d%d%d",&ore,&minuti,&secondi);
    }while(!(ore >= 12 && ore <= 24) && !(minuti >= 0 && minuti <= 60) && !(secondi >=  0 && secondi <= 60));
    
    printf("\nSecondi trascorsi dalle 12: %ld", howSeconds(ore, minuti, secondi));
    
    printf("\nHello, World!\n");
    return 0;
}

long howSeconds(int hours, int minute, int seconds){
    return (hours - 12) * 3600 + minute * 60 + seconds;
}