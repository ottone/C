//
//  main.c
//  Exe7.24
//
//  Created by Francesco Parrucci on 10/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
7.24

/*
(Quicksort) Negli esempi e negli esercizi del Capitolo 6 abbiamo discusso le tecniche di orinamento a bolle (bubble 
sort), di bucket sort e per selezione (selection sort). Presenteremo ora una tecnica ricorsiva di ordinamento chiamata
Quicksort (ordinamento veloce). L'algoritmo fornamentale per un vettore di valori unidimensionale è il seguente:

		1) Passo di ripartizione: prendete il primo elemento di un vettore disordinato e determinate la sua po
		   sizione finale in quello ordinato. Ciò avverrà quando tutti i valori del sottovettore sinistro, 
		   rispetto all'elemento, gli saranno inferiori e tutti quelli del sottovettore destro gli saranno 
		   superiori. A questo punto avremo un elemento sistemato nella sua giusta posizione e due sottovettori 
		   disordinati.

		2) Passo ricorsivo: eseguite il passo 1 su ogni sottovettore disordinato.

Ogni volta che il passo 1 sarà eseguito su un sottovettore, un altro elemento sarà sistemato nella sua posizione finale
all'interno del vettore ordinato e saranno creati due sottovettori disordinati. Considereremo sicuramente oridnato un 
sottovettore che sia formato da un solo elemento e, di conseguenza , queso sarà già nella sua posizione finale. 
L'algoritmo di base sembra abbastanza semplice, ma in che modo determineremo la posizione finale del primo elemento di
ogni sottovettore? Come esempio, consideriamo il seguente gruppo di valori (l'elemento in grassetto è quello utilizzato
per la ripartizione, ovvero sia, quello che sarà sistemato nella sua posizione finale all'interno del vettore ordinato):

			(37) 2 6 4 89 8 10 12 68 45

		1) Partendo da quello più a destra nel vettore , confrontate ogni elemento con il 37 finchè non 
		   ne troviate uno minore che scambierete di posto con il 37. il primo elemento minore di 37
		   è 12, perciò 37 e 12 saranno scambiati di posto. Il nuovo vettore sarà:

			(12) 2 6 4 89 8 10 (37) 68 45

		   L'elemento 12 è in corsivo per ricordare che è stato appena scambiato di posto con il 37.
		   
		2) Partendo dalla sinistra del vettore, ma cominciando da quello successivo al 12, confrontate ogni
		   elemento con il 37 finchè non ne troviate uno maggiore che scambierete di posto con il 37. Il 
		   primo elemento maggiore di 37 è 89, perciò 37 e 89 saranno scambiati di posto. il nuovo vettore sara'

		   	12 2 6 4 (37) 8 10 (89) 68 45

		3) Partendo dalla destra, ma cominciando da quello precedente a 89, confrontate ogni elemento con il 37
		   Il primo elemento minore di 37 è 10, perciò 37 e 10 saranno scambiati di posto. Il nuovo vettore sarà
	   	   	
			12 2 6 4 (10) 8 (37) 89 68 45

		4) Partendo dalla sinistra, ma cominciando da quello successivo al 10, confrontate ogni elemento con il
		   37 finchè non ne troviate uno maggiore che scambierete di posto con il 37. In questo caso non ci sono
		   altri elementi maggiori di 37 perciò, confrontando il 37 con se stesso, sapremo che sarà già stato
   		   sistemato nella sua posizione finale all'interno del vettore ordinato.

Una volta che al suddetto vettore sarà stata applicata la ripartizione, ci saranno due sottovettori disordinati. Il sot
tovettore dei valori minori di 37 conterrà 12, 2, 6, 4, 10 e 8, mentre quello dei valori maggiori di 37 conterrà 89, 68
e 45. L'algoritmo di ordinamento dovrà dunque procedere con la ripartizione di entrambi i sottovettori nello stesso mo
do utilizzato per ripartire quello originale. Basandovi sulla discussione precedente scrivete una funzione ricorsiva
quicksort che ordini un vettore unidimensionale di valori interi. La funzione dovrà ricevere come argomenti un vettore
di valori interi, un indice di partenza e uno di fine. La funzione partition dovrà essere richiamata da quicksort per 
eseguire il passo di ripartizione.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10


void partition(int [],int, int);
void swap(int *,int *);
void stampa(int[]);
int quicksort(int [],int, int);

int main(){

	int count, v[SIZE];

srand(time(NULL));

	for(count = 0; count < SIZE; count++)
		v[count] = 1 + rand() % 100;

	printf("\nPrima di quicksort():\n");
	for(count = 0; count < SIZE; count++)
		printf("v[%d] : %d\n",count,v[count]);

	//quicksort(v , 0, SIZE -1);
	partition(v,0,SIZE-1);

	printf("\nDopo di quicksort():\n");
	for(count = 0; count < SIZE; count++)
		printf("v[%d] : %d\n",count,v[count]);

return 0; 
}

// Funzione quicksort e partition 

int quicksort(int v[],int l, int r){
   
	int  s = l, d = r;

	if(l == r)
		return l;
	else if(s < d){
		if(v[s] > v[d]){ 
			swap(&v[s],&v[d]);
			s++;
			quicksort(v,d,s);
		}else{
			d--;
			quicksort(v,s,d);
		}	
	}else{//(s > d)
		if(v[s] < v[d]){
		       	swap(&v[s],&v[d]);
			s--;
			quicksort(v,d,s);
		}else{
			d++;
			quicksort(v,d,s);
		}
	}
		

}

void partition(int v[], int l, int r){
   
	int i;// = quicksort(v,l,r);
	
	if(l == r)
		return;
	else{
		i = quicksort(v,l,r);
		if (i > l) partition(v,l,i-1);	
		if (i < r) partition(v,i+1,r);
	}
	
	

}	


/*

// Funzione quicksort e partition di Algoritmi in C

void quicksort(int v[], int l, int r){

	int i;

	if(r <= l) return;

	i = partition(v, l, r);
	quicksort(v, l, i-1);
	quicksort(v, i+1, r);
}

int partition(int a[], int l, int r){
	
	int i = l-1, j = r, v = a[r];
	
	for(;;){
		while (a[++i] < v) ;
		while (v < a[--j]) if(j == l) break;
		if(i >= j) break;
		swap(&a[i],&a[j]);
		}

	swap(&a[i],&a[r]);
	return i;
	}
}

// Funzione quicksort Kerningham & Ritchie

void quicksort(int v[], int sin, int des){

	int i , last;

	if(sin >= des)	// se il vettore contiene meno di due elementi non fa niente
		return;

	// sposta l'elemento discriminante in v[sin] 

	swap(&v[sin],&v[(sin + des)/2]);

	last = sin;

	for(i = sin + 1; i <= des; i++)
		if(v[i] < v[sin])
			swap(&v[++last],&v[i]);

	// ripristina l'elemento discriminante
		
	swap(&v[sin],&v[last]);

	quicksort(v, sin, last -1);
	quicksort(v, last + 1, des);


}
*/
/*
// Funzione quicksort bellini

void quicksort(int v[],int sin, int des){ 

	int  media , i, j;
	
	media = (v[sin]+v[des]) / 2;
	i = sin;
	j = des;

	
	do{
		while(v[i] < media) i++;
	       	while(v[j] > media) j--;

		if(i <= j){	
			swap(&v[i], &v[j]);
			i++;
			j--;
		}
	}while(j >= i);

	if(sin < j) quicksort(v,sin ,j);
	if(des > i) quicksort(v,i,des);
}


*/

void stampa(int v[]){

	int count ;
	printf("\n");
	for(count  = 0; count < SIZE; count++)
		printf("v[%d] : %d\n",count,v[count]);
	

}


void swap(int *a,int *b){
	
	int temp = *a;

	*a = *b;
	*b = temp;
}

