//
//  main.c
//  Exe7.28
//
//  Created by Francesco Parrucci on 18/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*


/*
(Vettori di puntatori a funzioni) Riscrivete il programma della Figura 6.22 in modo da utilizzare un'interfaccia guidata da menu.
Il programma dovrà offrire all'utente le seguenti 4 opzioni:

Enter a choice:

0 Print the array of grades
1 Find the minimum grade
2 Find the maximum grade
3 Print the average on all tests for each student
4 End program

Una restrizione all'utilizzo di vettori di puntatori a funzioni è che tutti i puntatori devono essere dello stesso tipo. Di conseguenza
, devono essere dei puntatori a funzioni che restituiscano tutte lo stesso tipo di dato e che ricevano argomenti dello stesso tipo. Per
questa ragione, le funzioni nella Figura 6.22 dovranno essere modificate in modo che restituiscano lo steso tipo di dato e ricevano i 
medesimi parametri. Modificate le funzioni minimum e maximum in modo che visualizzino il valore minimo e quello massimo e non restituiscano
niente. Per l'opzione 3, modificate la funzione average della Figura 6.22 in modo che invii in output la media di ogni studente (invece che
quella di uno specifico). La funzione average non dovrà restituire nessun dato e riceverà gli stessi parametri di printArray, minimum e 
maximum. Immagazzinate i puntatori alle quattro funzioni nel vettore processGrades e utilizzate la scelta effettuata dall'utente come indice
di vettore per richiamare le funzioni.

*/

/* Double-subscripted array example */
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

void minimum(int [][EXAMS]);
void maximum(int [][EXAMS]);
void average(int [][EXAMS]);
void printArray(int [][EXAMS]);

int main()
{
   int student, choice, studentGrades[STUDENTS][EXAMS] = {{77, 68, 86, 73}, {96, 87, 89, 78}, {70, 90, 86, 81}};
	
   void (*processGrades[4]) (int [][EXAMS]) = {printArray,minimum,maximum,average}; // dichiarazione di un vettore di puntatori a funzioni 

   while(1){
	do{
		printf("\n0 Print the array of grades");
		printf("\n1 Find the minimum grade");
		printf("\n2 Find the maximum grade");
		printf("\n3 Print the average on all tests for each student");
		printf("\n4 End program: ");
		scanf("%d",&choice);
	}while(!(choice >= 0 && choice <= 4));

		if(choice == 4)
			break;
		else
			(*processGrades[choice])(studentGrades);
   }

   return 0;
}

/* Find the minimum grade */
 void minimum(int grades[][EXAMS])
{
   int i, j, lowGrade = 100;

   for (i = 0; i <= STUDENTS - 1; i++)
      for (j = 0; j <= EXAMS - 1; j++)
         if (grades[i][j] < lowGrade)
            lowGrade = grades[i][j];

   printf("\nLowest grade: %d\n",lowGrade);
}

/* Find the maximum grade */
void maximum(int grades[][EXAMS])
{
   int i, j, highGrade = 0;

   for (i = 0; i <= STUDENTS - 1; i++)
      for (j = 0; j <= EXAMS - 1; j++)
         if (grades[i][j] > highGrade)
            highGrade = grades[i][j];

   printf("\nHighest grade: %d\n", highGrade);
}

/* Determine the average grade for a particular exam */
void average(int grades[][EXAMS])
{
   int student, i, total = 0;

   for (student = 0, total = 0; student <= STUDENTS - 1; student++){
   	for (i = 0, total = 0; i <= EXAMS - 1; i++)
      		total += grades[student][i];
   
      printf("\nThe average grade for student %d is %.2f\n", student, (float) total / EXAMS );
      
   }

}

/* Print the array */
void printArray(int grades[][EXAMS])
{
   int i, j;


   printf("\n\nThe array is:\n");

   printf("                 [0]  [1]  [2]  [3]");

   for (i = 0; i <= STUDENTS - 1; i++) {
      printf("\nstudentGrades[%d] ", i);

      for (j = 0; j <= EXAMS - 1; j++)
         printf("%-5d", grades[i][j]);
   }

   printf("\n\n");
}
