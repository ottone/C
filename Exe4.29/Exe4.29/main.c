//
//  main.c
//  Exe4.29
//
//  Created by Francesco Parrucci on 18/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 (LEGGI DI DE MORGAN) IN QUESTO CAPITOLO ABBIAMO DISCUSSO DEGLI OPERATORI LOICI && || E !. LE LEGGI DI DI MORGAN POTRANNO A 
 VOLTE RENDERCI PIU PRATICA LA FORMULAZIONE DI UNA ESPRESSIONE LOGICA. QUESTE LEGGI STABILISCONO CHE L'ESPRESSIONE !
 (CONDIZIONE1 && CONDIZIONE2) E' LOGICAMENTE EQUIVALENTE ALLA ESPRESSIONE (!CONDIZIONE1 || !CONDIZIONE2). UTILIZZATE LE LEGGI DI DE MORGAN PER SCRIVERE DELLE ESPRESSIONI EQUIVALENTI PER OGNUNA DI QUELLE SEGUENTI E QUINDI SCRIVETE UN PROGRAMMA CHE DIMOSTRI CHE L'ESPRESSIONE ORIGINALE E QUELLA NUOVA SONO, IN OGNI CASOM EQUIVALENTI:
 
 A) !(X < 5) && !(Y >= 7)  = !((X < 5) || (Y >= 7))
 B) !(A == B) || !(G != 5) = !((A == B) && (G != 5))
 C) !((X <= 8) && (Y > 4)) = !(X <= 8) || !(Y > 4)
 D) !((I > 4) || (J <= 6)) = !(I > 4) && !(J <= 4)
 
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int A = 3, B = 3, G = 4 , H = 5, I = 6, X = 4, Y = 8, J = 2;
    
    printf("\nA) !(X < 5) && !(Y >= 7) == !((X < 5) || (Y >= 7))");
    printf(" Soluzione: %d == %d\n", !(X < 5) && !(Y >= 7) , !((X < 5) || (Y >= 7)));
    
    printf("\nB) (!(A == B) || !(G != 5)) = !((A == B) && (G != 5))");
    printf(" Soluzione: %d == %d\n",(!(A == B) || !(G != 5)) , !((A == B) && (G != 5)));
    
    
    printf("\nC) !((X <= 8) && (Y > 4)) = !(X <= 8) || !(Y > 4)");
    printf(" Soluzione: %d == %d\n", !((X <= 8) && (Y > 4)) , !(X <= 8) || !(Y > 4));
   
    printf("\nD) !((I > 4) || (J <= 6)) = !(I > 4) && !(J <= 4)");
    printf(" Soluzione: %d == %d\n",!((I > 4) || (J <= 6)) , !(I > 4) && !(J <= 4));
    
    return 0;
}
