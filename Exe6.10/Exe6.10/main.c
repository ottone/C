//
//  main.c
//  Exe6.10
//
//  Created by Francesco Parrucci on 09/02/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
UTILIZZATE UN VETTORE MULTIDIMENSIONALE PER RISOLVERE IL SEGUENTE PROBLEMA. UN'AZIENDA RETRIBUISCE I SUOI VENDITORI CON DELLE 
PROVVIGIONI. UN VENITORE RICEVE $200 LA SETTIMANA PIU' IL 9 PERCENTO DELLE PROPRIE VENDITE LORDE PORTATE A TERMINE IN QUELLA 
SETTIMANA. PER ESEMPIO, UN VENDITORE CHE FACCIA INCSSARE $3000 DI VENDUTO LORDO, IN UNA SETTIMANA, RICEVERA0 $200 PIU' IL 9 
PERCENTO DI $3000 , OVVEROSIA UN TOTALE DI $470. SCRIVETE UN PROGGRAMMA  C , UTILIZZANDO UN VETTORE DI CONTATORI CHE DETERMINI 
QUANTI VENDITORI ABBIANO GUADAGNATO UNA RETRIBUZIONE COMPRESA IN OGNUNO DEI SEGUENTI INTERVALLI (SUPPONETE CHE LA RETRIBUZIONE
DI OGNI VENDITORE SIA TRONCATA A UNA SOMA INTERA):
 
 1. $200 - $299
 2. $300 - $399
 3. $400 - $499
 4. $500 - $599
 5. $600 - $699
 6. $700 - $799
 7. $800 - $899
 8. $900 - $999
 9. $1000 - OLTRE
 
*/


#include <stdio.h>
#define SIZE 10

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int x, y, import;
    int d[SIZE][3] = {{0,0},{200,299},{300,399},{400,499},{500,599},{600,699},{700,799},{800,899},{900,999},{1000,1000}};
    
    do{
    printf("\nInserire la somma: ");
    scanf("%d",&import);
    //import = ((import * 9) / 100) + 200;
    for(x = 1; x <= SIZE - 1; x++)
        if((import >= 1000 && x == SIZE - 1) || (import >= d[x][0] && import <= d[x][1]))
            d[x][2]++;
    import = 0;
    }while(getchar() != EOF);
        
        
        
    for(x = 1 ; x <= SIZE - 1; x++){
        printf("\n");
        for(y = 0; y <= 1 ; y++)
            printf("%-5d ",d[x][y]);
        for(y = 0; y <= d[x][2]; y++)
            printf("*");
    }
    
    
    printf("\nHello, World!\n");
    return 0;
}