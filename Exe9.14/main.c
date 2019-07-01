//
//  main.c
//  Exe9.14
//
//  Created by Francesco Parrucci on 30/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//  
//  Scrivete un programma che verifichi tutte le sequnze di escape della Figura 9.16. Visualizzate un carattere prima e dopo le 
//  sequenze di escape che spostano il cursore, per rendere evidente lo spostamento del cursore.
//


#include <stdio.h>

int main(){

printf("\nApice singolo con sequenza di escape \\\' \n");
getchar();
printf("\nApice doppio con sequenza di escape \\\" \n");
getchar();
printf("\nPunto interrogativo con sequenza di escape \\\? \n");
getchar();
printf("\nCarattere di backslash con sequenza di escape \\\\ \n");
getchar();
printf("\nProvoca un allarme acustico o visivo con sequenza di escape \\\aa\n");
getchar();
printf("\nMuove il cursore indieto di una posizione sulla riga corrente con sequenza di escape \\b");
getchar();
printf("      %c\b\b\b%c",'A','C');
getchar();
printf("\nMuove il cursore all'inizio della successiva pagina logica con sequenza di escape \\f\n");
printf("%c",'A');
printf("\f%c",'A');
getchar();
printf("\nMuove il cursore all'inizio della riga successiva con sequenza di escape \\n\n");
printf("%c",'A');
printf("\n%c",'A');
getchar();
printf("\nMuove il cursore all'inizio della riga corrente con sequenza di escape \\r");
getchar();
printf("%10c",'A');
printf("\r%c",'A');
getchar();
printf("\nMuove il cursore sulla successiva posizione di tabulazione orizzontale con sequenza di escape \\t\n");
printf("%c",'A');
printf("\t%c",'A');
getchar();
printf("\nMuove il cursore sulla successiva posizione di tabulazione verticale con sequenza di escape \\v\n");
printf("%c",'A');
printf("\v");
printf("%c",'A');
getchar();

return 0;

}

