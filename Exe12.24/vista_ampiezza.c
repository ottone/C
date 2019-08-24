#include <stdio.h>
#include <stdlib.h>

typedef struct TNode TNode;
struct TNode {
   TNode *left, *right;
   char info;
};

/* Dimensione fissa per comodità. */
typedef struct Queue256 Queue256;
struct Queue256 {
   int appended;
   int removed;
   TNode *buffer[256];
};

int Queue256_size(Queue256 *q)
{
   return q->appended - q->removed;
}

void Queue256_append(Queue256 *q, TNode *n)
{
   if (Queue256_size(q) < 256) {
      q->buffer[q->appended % 256] = n;
      ++(q->appended);
   } else {
      /* Coda piena (non dovrebbe succedere in questo programma. */
      fputs("Coda piena!\n", stderr);
   }
}

TNode *Queue256_pop(Queue256 *q)
{
   if (Queue256_size(q) == 0) {
      return NULL;
   }

   TNode *ret = q->buffer[q->removed];
   ++q->removed;
   return ret;
}

void printBFS(TNode *tree)
{
   Queue256 queue = {0};
   TNode *current = NULL;

   Queue256_append(&queue, tree);
   
   while ((current = Queue256_pop(&queue)) != NULL) {
      putchar(current->info);
      putchar(' ');
      if (current->left != NULL) { Queue256_append(&queue, current->left); }
      if (current->right != NULL) { Queue256_append(&queue, current->right); }
   }
   putchar('\n');
}

int main(void)
{
   /* Creo albero (R (a (b (c . .) .) .) (d (e . .) (f . (g . .)))) */
   TNode g = {NULL, NULL, 'g'};
   TNode f = {NULL, &g, 'f'};
   TNode e = {NULL, NULL, 'e'};
   TNode d = {&e, &f, 'd'};
   TNode c = {NULL, NULL, 'c'};
   TNode b = {&c, NULL, 'b'};
   TNode a = {&b, NULL, 'a'};
   TNode R = {&a, &d, 'R'};

   /* Visito l'albero in ampiezza (dovrebbe stampare R a d b e f c g) */
   printBFS(&R);

   return 0;
}
