//
//  main.c
//  Exe5.41
//
//  Created by Francesco Parrucci on 01/02/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 (VISUALIZZARE LA RICORSIONE) E' INTERESSANTE OSSERVARE LA RISCORSIONE "IN AZIONE". MODIFICATE LA FUNZIONE DEL FATORIALE DELLA 
 FIGURA 5.14 IN MODO DA VISUALIZZARE LE SUE VARIABILI LOCALI E I PARAMETRI DELLE CHIAMATE RICORSIVE. PER OGNI CHIAMATA
 RICORSIVA, VISUALIZZATE GLI OUTPUT SU UNA RIGA SEPARATA E AGGIUNGETE UN LIVELLO DI RIENTRO. FATE DEL VOSTRO MEGLIO PER RENDERE
 L'OUTPUT CHIARO, INTERESSANTE E SIGNIFICATIVO. IL VOSTRO OBIETTIVO IN QUESTO CASO SARA' DI DISEGNARE E IMPLEMENTARE UN FORMATO
 DELL'OUTPUT CHE AIUTI UNA PERSONA A CAPIRE MEGLIO LA RICORSIONE. POTRESET VOLER AGGIUNGERE QUESTE CAPACITAP DI VISUALIZZAZIONE 
 AI MOLTI ALTRI ESEMPI DED ESERCIZI SULLA RICORSIONE PRESENTI IN QUSTO TESTO.
*/


// FUNZIONE FATTORIALE RICORSIVA

#include <stdio.h>

long factorial(long);

int main(){
    
    int i;
    for (i = 1 ; i <= 10; i++){
        printf("%2d! -> ",i);
        printf(" = %ld\n",factorial(i));
    }
        
    return 0;
    
}

long factorial(long number){
    if (number == 1){
         printf(" %ld ", number);
         return number;
    }else{
        printf(" %ld ",number);
        return number * factorial(number - 1);
    }
}