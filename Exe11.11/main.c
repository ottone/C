//
//  main.c
//  Exe11.11
//
//  Created by Francesco Parrucci on 11/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
// 
//
//  Scrivete delle istruzioni che eseguano ognuno dei seguenti compiti. Supponete che la struttura 
//
//  struct person {
//  	char lastName[15];
//  	char firstName[15];
//  	char age[2];
//  };
//
//  sia già stata definita e che il file sia già stato aperto in scrittura.
//  a) Inizializzate il file "nameage.dat" in modo che ci siano 100 record con lastName = "unassigned", firstName="" e age="0".
//  b) Immettete 10 cognomi, nomi ed età e scriveteli nel file.
//  c) Aggiornate un record e; qualora non vi troviate delle informazioni, informate l'utente con il messaggio "No info".
//  d) Eliminate un record che contenga delle informazioni, inizializzando nuovamente quel particolare record.
//


#include <stdio.h>
#include <string.h>

struct person {
	char lastName[20];
	char firstName[20];
	char age[3];
};

int main()
{
	FILE *Ptr;
	typedef struct person persona;
	int i = 0;
	char c;

	persona per = {"unassigned", "", "0\n"}, data, read;
	
	if((Ptr = fopen("nameage.dat","w")) == NULL)
			printf("\nImpossibile aprire il file");
	else
	{
		printf("\nInizializzazione file di nameage.dat\n");
		for(i = 1; i <= 100; i++)
			fwrite(&per,sizeof(persona),1,Ptr);

		fclose(Ptr);
	}

	if((Ptr = fopen("nameage.dat","r+")) == NULL)
			printf("\nImpossibile aprire il file");
	else{
			printf("\nInserimento/aggiornamento record in nameage.dat\n");
			printf("Inserire il numero di record (1 - 100 0 per terminare): ");
			scanf("%d",&i);
			while(i != 0){
			printf("Enter account lastname firstname age: ");
			scanf("%s%s%s",&data.lastName,&data.firstName,&data.age);
			strcat(data.age,"\n");
			fseek(Ptr,(i - 1) * sizeof(per),SEEK_SET);
			fwrite(&data,sizeof(persona),1,Ptr);
			printf("\nInserire il numero di record (1 - 100 0 per terminare): ");
			scanf("%d",&i);
			}
			fclose(Ptr);

	}

	if((Ptr = fopen("nameage.dat","r")) == NULL)
			printf("\nImpossibile aprire il file");
	else{
			printf("\nStampa record in nameage.dat\n");
			printf("Inserire il numero di record (1 - 100 0 per terminare): ");
			scanf("%d",&i);
			while(i != 0){
			fseek(Ptr,(i - 1) * sizeof(per),SEEK_SET);
			fread(&read,sizeof(persona),1,Ptr);
			printf("%s %s %s",read.lastName, read.firstName, read.age);
			printf("Inserire il numero di record (1 - 100 0 per terminare): ");
			scanf("%d",&i);
			}
			fclose(Ptr);

	}

	if((Ptr = fopen("nameage.dat", "r+")) == NULL)
			printf("\nImpossibile aprire il file");
	else{
			printf("\nCancellazione di nel file nameage.dat\n");
			printf("Inserire il numero di record (1 -100 0 per terminare): ");
			scanf("%d",&i);
			while(i != 0){
			fseek(Ptr,(i - 1) * sizeof(persona),SEEK_SET);
			fread(&read,sizeof(persona),1,Ptr);
			if((strcmp(read.firstName,per.firstName) == 0) && (strcmp(read.firstName,per.firstName) == 0) && (strcmp(read.firstName,per.firstName) == 0))
				printf("\nRecord vouto!!!\n");
			else{
				fseek(Ptr,(i - 1) * sizeof(persona),SEEK_SET);
				fwrite(&per,sizeof(persona),1,Ptr);
				printf("\nRecord %d eliminato.\n",i);
			}
			printf("Inserire il numero di record (1 - 100 0 per terminare): ");
			scanf("%d",&i);
			}
			fclose(Ptr);
	}
				
	return 0;
}
