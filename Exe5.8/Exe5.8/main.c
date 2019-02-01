//
//  main.c
//  Exe5.8
//
//  Created by Francesco Parrucci on 25/01/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
 MOSTRARE IL VALORE DI X DOPO CHE SARA' STATA ESEGUITA OGNUNA DELLE SEGUENTI ISTRUZIONI:
 
 a) x = fabs(7.5)        VALORE ASSOLUTO DI X SE X > 0 = 7.5 SE X = 0 0.0 SE X < 0 -X
 b) x = floor(7.5)       ARROTONDA ALL'INTERO PIU' GRANDE NON MAGGIORE DI X (7)
 c) x = fabs(0.0)        X = 0.0
 d) x = ceil(0.0)        ARROTONDA ALL'INTERO PIU' PICCOLO NON MINORE DI X
 e) x = fabs(-6.4)       -6.4
 f) x = ceil(-6.4)       -6
 g) x = ceil(-fabs(-8+floor(-5.5))) (12)
 
*/
#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    printf("\nFunzione fabs() valore assoluto di 7.5 x = fabs(7.5) => x = %.2f",fabs(7.5));
    printf("\nFunzione floor() arrotonda all'intero più grande minore di 7.5 x = fabs(7.5) => x = %.2f",floor(7.5));
    printf("\nFunzione fabs() valore assoluto di 0.0 x = fabs(0.0) => x = %.2f",fabs(0.0));
    printf("\nFunzione ceil() arrotonda all'intero minore più grande di 0.0 x = ceil(0.0) x => %.2f",ceil(0.0));
    printf("\nFunzione fabs() valore assoluto di -6.4 x = fabs(-6.4) => x = %.2f", fabs(-6.4));
    printf("\nFunzione ceil() arrotonda all'intero minore più grande di -6.4 x = ceil(-6.4) => x = %.2f",ceil(-6.4));
    printf("\nEspressione x = ceil(-fabs(-8+floor(-5.5))) => x = %.2f\n\n",ceil(-fabs(-8+floor(-5.5))));
    
    
    return 0;
}
