//
//  main.c
//  Exe11.16
//
//  Created by Francesco Parrucci on 16/07/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//   
//  Scrivete un programma che usi l'operatore sizeof per determinare le dimensioni in byte dei vari tipi di dato sul vostro sistema. Scrivete i risultati nel 
//  file "datasize.dat", così che possiate visualizzarli in un secondo momento. il formato dei risultati nel file dovrà eseree: 
//
//  Data type 			Size
//  char 			1
//  unsigned char		1
//  short int			2
//  unsignded short int		2
//  int 			4
//  unsigned int		4
//  long int			4
//  unsigned long int		4
//  float			4
//  double			8
//  long double			16
//
//  Nota: sul vostro computer, le dimensioni dei tipi di dato potrebbero non corrispondere a quelle elencate sopra.
//
#include <stdio.h>

int main()
{
   FILE *ptr;

   if((ptr = fopen("datasize.dat","w")) == NULL)
		printf("\nImpossibile aprire il file \"datasize.dat\"\n");
   else{
		fprintf(ptr,"\n%-30s%-4s\n","Data type","Size");
				
		fprintf(ptr,"%-30s%-4d\n","char",sizeof(char));
		fprintf(ptr,"%-30s%-4d\n","unsigned char",sizeof(unsigned char));
		fprintf(ptr,"%-30s%-4d\n","short int",sizeof(short int));
		fprintf(ptr,"%-30s%-4d\n","unsigned short int",sizeof(unsigned short int));
		fprintf(ptr,"%-30s%-4d\n","int",sizeof(int));
		fprintf(ptr,"%-30s%-4d\n","unsigned int",sizeof(unsigned int));
		fprintf(ptr,"%-30s%-4d\n","long int",sizeof(long int));
		fprintf(ptr,"%-30s%-4d\n","unsigned long int",sizeof(unsigned long int));
		fprintf(ptr,"%-30s%-4d\n","float",sizeof(float));
		fprintf(ptr,"%-30s%-4d\n","double",sizeof(double));
		fprintf(ptr,"%-30s%-4d\n","long double",sizeof(long double));
	
		fclose(ptr);
   }

return 0;
}
