//
//  main.c
//  Exe11.12
//
//  Created by Francesco Parrucci on 12/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
// 
//  Siete il proprietario di una ferramenta e avete bisogno di mantenere un inventario che possa dirvi quali e quanti attrezzi avete, i il costo di ogniuno di esse.
//  Scrivete un programma che inizializzi il file "hardware.dat" con 100 record vuoti, vi consenta di immettere i dati relativi a ogni attrezzo, vi dia la possibilità 
//  di elencarli tutti, vi lasci eliminare il record di un attrezzo che non avete più e vi permetta di aggiornare qualsiasi informazione all'interno del file.
//  Il numero di identificazione dell'attrezzo dovrà essere anche quello del record. Usate le seguenti informazioni come dati iniziali per il vostro file.
//
//  Record n° 	Nome dell'attrezzo		Quantità	Costo
//  3		Smerigliatrice elettrica	7		57.98
//  17		Martello			76		11.99
//  24		Sega da traforo			21		11.00
//  39 		Falciatrice 			3		79.50	
//  56		Sega Elettrica			18		99.99
//  68		Giravite			106		6.99
//  77		Martello da fabbro		11		21.50
//  83		Chiave inglese			34		7.50
//
//  Scrivete delle istruzioni che eseguano ognuno dei seguenti compiti. Supponete che la struttura 
//
//  typedef struct{
//  	int num;
//  	char name[30];
//  	int qta;
//  	float cost;
//  } record;
//
//


#include <stdio.h>
#include <string.h>

int menu(void);
void inizialize(void);
void addRecord(void);
void updateRecord(void);
void stampa(void);
void deleteRecord(void);

  typedef struct{
  	char name[30];
  	int qta;
  	float costo;
  } record;

int main()
{
	int i;
	while((i = menu()) != 6){
		switch (i){

			case 1:
				inizialize();
				break;
			case 2:
				addRecord();
				break;
			case 3:
				updateRecord();
				break;
			case 4:
				stampa();
				break;
			case 5:
				deleteRecord();
				break;
		}
	

	}
	
return 0;

}

void addRecord(void)
{
	FILE *Ptr;
	record data;
	int i = 0;
	char c;

	if((Ptr = fopen("hardware.dat","r+")) == NULL)
			printf("\nImpossibile aprire il file");
	else{
			printf("\nInserimento/aggiornamento record in hardware.dat\n");
			
			printf("Inserire il numero di record (1 - 100 0 per terminare): ");
			scanf("%d",&i);
			while(i != 0){
			while((c = getchar()) != '\n');
			fseek(Ptr,(i -1) * sizeof(record),SEEK_SET);
			fread(&data,sizeof(record),1,Ptr);
			if(strcmp(data.name,"") != 0)
				printf("Record occupato --> \"%s %d %+.2f\" <--",data.name,data.qta,data.costo);
			else{
				printf("\nEnter product name: ");
				gets(&data.name);
				printf("\nEnter quantity and cost: ");
				scanf("%d%f",&data.qta,&data.costo);
				fseek(Ptr,(i - 1) * sizeof(record),SEEK_SET);
				fwrite(&data,sizeof(record),1,Ptr);
			}
			printf("\nInserire il numero di record (1 - 100 0 per terminare): ");
			scanf("%d",&i);
			}
			fclose(Ptr);

	}
}

void inizialize(void){
	
	FILE *Ptr;
	record data = {"", 0, 0};
	int i = 0;

	if((Ptr = fopen("hardware.dat","w")) == NULL)
			printf("\nImpossibile aprire il file hardware.dat");
	else
	{
		printf("\nInizializzazione del file hardware.dat\n");
		for(i = 1; i <= 100; i++)
			fwrite(&data,sizeof(record),1,Ptr);

		fclose(Ptr);
	}

}


void updateRecord(void){

	FILE *Ptr;
	record data;
	int i = 0;
	char c;

	if((Ptr = fopen("hardware.dat","r+")) == NULL)
			printf("\nImpossibile aprire il file");
	else{
			printf("\nAggiornamento record in hardware.dat\n");
			
			printf("Inserire il numero di record (1 - 100 0 per terminare): ");
			scanf("%d",&i);
			while(i != 0){
			while((c = getchar()) != '\n');
			printf("\nEnter product name: ");
			gets(&data.name);
			printf("\nEnter quantity and cost: ");
			scanf("%d%f",&data.qta,&data.costo);
			fseek(Ptr,(i - 1) * sizeof(record),SEEK_SET);
			fwrite(&data,sizeof(record),1,Ptr);
			printf("\nInserire il numero di record (1 - 100 0 per terminare): ");
			scanf("%d",&i);
			}
			fclose(Ptr);

	}
}

void stampa(void){

	FILE *Ptr;
	record  read;

	if((Ptr = fopen("hardware.dat","r")) == NULL)
			printf("\nImpossibile aprire il file");
	else{
			printf("\nStampa record in hardware.dat\n");
			while(!feof(Ptr)){
			fread(&read,sizeof(record),1,Ptr);
			if(strcmp(read.name,"") != 0) printf("%-20s %-15d %-15.2f\n",read.name, read.qta, read.costo);
			}
			fclose(Ptr);

	}
}

void deleteRecord(void){

	FILE *Ptr;
	record data = {"", 0, 0}, read;
	int i = 0;

	if((Ptr = fopen("hardware.dat", "r+")) == NULL)
			printf("\nImpossibile aprire il file");
	else{
			printf("\nCancellazione di nel file hardware.dat\n");
			printf("Inserire il numero di record (1 -100 0 per terminare): ");
			scanf("%d",&i);
			while(i != 0){
			fseek(Ptr,(i - 1) * sizeof(record),SEEK_SET);
			fread(&read,sizeof(record),1,Ptr);
			if(strcmp(read.name,"") == 0) 
				printf("\nRecord vouto!!!\n");
			else{
				fseek(Ptr,(i - 1) * sizeof(record),SEEK_SET);
				fwrite(&data,sizeof(record),1,Ptr);
				printf("\nRecord %d eliminato.\n",i);
			}
			printf("Inserire il numero di record (1 - 100 0 per terminare): ");
			scanf("%d",&i);
			}
			fclose(Ptr);
	}
}

int menu(void){
	
	int choice;

	printf("\n1 - per inizializzare il file"
	       "\n2 - per inserire record"
	       "\n3 - per aggiornare record"
	       "\n4 - per stampare il file"
	       "\n5 - per eliminare record"
	       "\n6 . per terminare"
	       "\n-----------------------> ?: ");
	scanf("%d",&choice);

	return choice;
}
