//
//  main.c
//  Exe11.14
//
//  Created by Francesco Parrucci on 14/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//   
//  Nel caso in cui abbiate a disposizione un dizionario computerizzato, modificate il programma che avete scritto nell'Esercizio 11.13 in modo che ricerchi le parole
//  nel dizionario. Alcune delle combinazioni di sette lettere create da questo programma consistono di due o piu parole (il numero telefonico 646-2276 corrisponde a
//  "MIOCAPO").
//
//
//
//  Generatore di parole con i numeri telefonici. Le tastiere telefoniche stardard dei cellulari contengono le cifre da zero a nove. A ognuno dei numeri da due a nove
//  sono associate tre o quattro lettere, come indicato dalla seguente tabella: 
//
//  Numero	Lettere
//  2		ABC
//  3		DEF
//  4		GHI
//  5		JKL
//  6		MNO
//  7		PQRS
//  8		TUV
//  9		WXYZ
//
//  Per molte persone la memorizzazione dei numeri telefonici è un'operazione difficile e per questo motivo, utilizzano la corrispondenza tra le cifre e le lettere per 
//  sviluppare paroli di sette carattiri che corrispondano ai propri numeri telefonici. Per esempio una persona il cui numero telefonico sia 468-6374, potrebbe usare le 
//  corrispondenze indicate nella tabella precedente per sviluppare la parola di sette lettere "INUMERI".
//  Le aziende tentano spesso di ottenere dei numeri telefonici che possano essere facilmente ricordati dai loro clienti. Se per le telefonate dei propri clienti 
//  un'azienda potesse pubblicizzare una semplice parola, invece di un numero telefonico, allora quell'azienda receverebbe indubbiamente qualche telefonata in più.
//  Ogni parola di sette lettere corrisponde esattamente a un numero telefonico di altrettante cifre. Un ristorante che desiderasse incrementare gli introiti dei propri
//  affari, potrebbe sicuramente farlo con il numero 872-4266 (ovverosia "USCIAMO").
//  A ogni numero telefonico di sette cifre corrispondono molte distinte parole di altrettante lettere. Sfortunatamente, molte di queste rappresentano giustapposizioni
//  di lettere senza significato. Tuttavia, è probabile che il proprietario di una bottega di barbiere possa essere contento di sapere che il numero telefonico del proprio 
//  salone, 227-3554, corrisponda a "CAPELLI". Il proprietario di un negozio di alcolici sarebbe senza dubbio felice di scoprire che il numero telefonico del proprio 
//  negozio, 547-8674, coincida con "LIQUORI". Un vegetariano con il numero telefonico 837-3872 sarebbe compiaciuto di sapere che quelle cifre equivalgano alla parola
//  "VERDURA".
//  Scrivere un programma C che, dato un numero di sette cifre, scriva in un file ogni possibile parola di sette lettere corrispondente a quel numero. Esistono al massimo 
//  16384 parole possibili (4 elevato alla settima potenza). Evitate i numeri di telefono con le cifre zero e uno. 
//
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *Ptr;
	int a,b,c,d,e,f,g,h,i;
	char *vet[] = {"ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"}, number[9], letter[9];
	char *vet2[8], buf[3];

	if((Ptr = fopen("combinazioni.txt","w")) == NULL)
		printf("\nImpossibile aprire il file\n");
	else{
		printf("\nDigita il numero di telefono: ");
		scanf("%s",letter);

		for(a = 0; letter[a] != '\0'; a++ ){
			buf[0] = letter[a], buf[1] = '\0';
			vet2[a] = vet[atoi(buf) - 2];
			puts(vet2[a]);
		}
	
		
		for(a = 0, i = 0; vet2[0][a] != '\0'; a++){
			for(b = 0; vet2[1][b] != '\0'; b++)
				for(c = 0; vet2[2][c] != '\0'; c++)
					for(d = 0; vet2[3][d] != '\0'; d++)
						for(e = 0; vet2[4][e] != '\0'; e++)
							for(f = 0; vet2[5][f] != '\0'; f++)
								for(g = 0; vet2[6][g] != '\0'; g++){
									number[0] = vet2[0][a];
									number[1] = vet2[1][b];
									number[2] = vet2[2][c];
									number[3] = vet2[3][d];
									number[4] = vet2[4][e];
									number[5] = vet2[5][f];
									number[6] = vet2[6][g];
			        					number[8] = '\0';
									i++;
									fprintf(Ptr,"%d Combinazione : %s\n",i,number);
								}
		}
		fclose(Ptr);
	}
	
return 0;
}
