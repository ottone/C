//
//  main.c
//  Exe14.6
//
//  Created by Francesco Parrucci on 29/08/19.
//  Copyright © 219 Francesco Parrucci. All rights reserved.
//
//
//  Consultate il manuale del vostro sistema per determinare quali segnali siano supportati dalla relativa libreria di gestione (signal.h). Scrivete un programma ceh contenga alcune gestioni dei segnali standard SIGABRT
//  e SIGINT. Il programma dovrà controllare l'intercettazione di questi segnali richiamando la funzione abort, per generarne uno di tipo SIGABRT, e premendo <ctrl> c, per generarne uno di tipo SIGINT.
//
//

/* Using signal handling */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

void signal_hand1(int);
void signal_hand2(int);

int main()
{
   int i, x;

   signal(SIGINT, signal_hand1);
   signal(SIGABRT,signal_hand2);
   srand(clock());

   for (i = 1; i <= 100; i++) {
      x = 1 + rand() % 50;

      if (x == 25)
         raise(SIGINT);

      if (x == 13)
	 raise(SIGABRT);

      printf("%4d", i);

      if (i % 10 == 0)
         printf("\n");
   }

   return 0;
}

void signal_hand1(int signalValue)
{
   int response;

   printf("%s%d%s\n%s","\nInterrupt signal (", signalValue, ") SIGINT received.","Do you wish to continue (1 = yes or 2 = no)? ");

   scanf("%d", &response);

   while (response != 1 && response != 2) {
      printf("(1 = yes or 2 = no)? ");
      scanf("%d", &response);
   }

   if (response == 1)
      signal(SIGINT, signal_hand1);
   else
      exit(EXIT_SUCCESS);
}

void signal_hand2(int signalValue)
{
   int response;

   printf("%s%d%s\n%s","\nInterrupt signal (", signalValue, ") SIGABRT received.","Do you wish to continue (1 = yes or 2 = no)? ");

   scanf("%d", &response);

   while (response != 1 && response != 2) {
      printf("(1 = yes or 2 = no)? ");
      scanf("%d", &response);
   }

   if (response == 1)
      signal(SIGABRT, signal_hand2);
   else
      exit(EXIT_SUCCESS);
}

