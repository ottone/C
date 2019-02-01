//
//  main.c
//  Exe5.15
//
//  Created by Francesco Parrucci on 26/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/* 
 DEFINIRE UNA FUNZIONE hypotenuse CHE CALCOLI LA LUNGHEZZA DELL'IPOTENUSA DI UN TRIANGOLO RETTANGOLO QUANDO SIANO DATI GLI
 ALTRI DUE LATI. UTILIZZATE QUESTA FUNZIONE IN UN PROGRAMMA CHE DETERMINI LA LUNGHEZZA DELL'IPOTENUSA PER OGNUNO DEI SEGUENTI
 TRIANGOLI. LA FUNZIONE DOVRA' RICEVERE DUE ARGOMENTI DI TIPO double E RESTITUIRE L'IPOTENUSA COME UN double.
 */


#include <stdio.h>
#include <math.h>

double hypotenuse(double,double);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    float x = 0 ,y;
    
    do{
        printf("\nImmettere due numeri EOF per terminare: ");
        scanf("%f%f",&x,&y);
        if (x != 0)
            printf("\nLato %.2f Lato %.2f Ipotenusa %.2f",x,y,hypotenuse(x, y));
        x = y = 0;
    }while(getchar() != EOF);
    
    
    printf("\n");
    
    return 0;
}

double hypotenuse(double x, double y){
    
    return sqrt(pow(x,2) + pow(x,2));
}