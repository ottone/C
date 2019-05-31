//
//  main.c
//  Exe7.25
//
//  Created by Francesco Parrucci on 12/05/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*


/*
(Attraversamento di un Labirinto) La griglia seguente è la rappresentazione di un labirinto all'interno di una matrice.


				111111111111
				100010000001
				001010111101
				111010000101
				100001110100
				111101010101
				100101010101
				110101010101
				100000000101
				111111011101
				100000010001
				111111111111

I numeri uno e zero rappresentano rispettivamente le pareti e i corridoi del labirinto.
Esiste un semplice algoritmo di attraversamento di un labirinto che garantisce il ritrovamento dell'uscista (sempre che
c'è ne sia una). Nel caso ceh l'uscita non ci fosse vi ritrovereste di nuovo al punto di partenza. Poggiate la mano a 
destra sulla parete alla vostra destra e cominciate a camminare in avanti. 
Non rimuovete mai la vostra mano dalla parete. Se il labirinto svolta a destra, seguite il muro a destra. Alla fine ar
riverete sicuramente all'uscita del labirinto, se nel frattempo non avete rimosso la vostra mano dalla parete. E' proba
bile che esista un percorso piu' breve di quello che avete intrapreso, ma in questo modo avrete la certezza di uscire
dal labirinto.
Scrivete la funzoine ricorsiva mazeTraverse per attraversare il labirinto. La funzione dovrà ricevere come argomenti 
una matrice di caratteri 12 per 12, per rappresentare il labirinto, e la posizione di partenza all'interno dello stesso.
Man mano che mazeTraverse tenterà di individuare l'uscita dal labirinto, dovrà inserire il carattere x in ogni casella 
del percorso. La funione dovrà visualizzare il labirinto dopo ogni mossa così che l'utente possa seguire la risuluzione 
del labirinto.

(Generazione casuale di labirinti) Scrivete una funzione mazeGenerator che riceva come argomento una matrice di caratteri 
12 per 12 e produca un labirinto a caso. La funzione dovrà anche restituire i punti di ingresso e di uscita del labirinto.
Provate la vostra funzione mazeTraverse dell'Esercizio 7.25 utilizzando vari labirinti generati a caso
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 12

void mazePrint(int maze [][12]);
void mazeTraverse(int maze[][12], int x, int y);
void mazeCreation(int maze[][12]);
void mazeGenerator(int maze[][12],int *,int *,int *,int *);

int main(){

	srand(time(NULL));
	
	int maze[12][12], x, y, outX,outY;
	
	mazeGenerator(maze,&y,&x,&outY,&outX);
	//mazeCreation(maze);
	mazePrint(maze);
	getchar();
	printf("\nValori d'ingresso: (y,x) (%d,%d)\n",x,y);
	//printf("\n\t\tInserire un valore per le x :");
	//scanf("%d",&x);
	//printf("\n\t\tInserire un valore per le y :");
	//scanf("%d",&y);
	mazeTraverse(maze,y,x);
	mazePrint(maze);
	
return 0; 
}


void mazeGenerator(int maze[][12],int *Yi,int *Xi, int *Yo, int *Xo){
	
	int countY, countX, mov, i=0, lato = 1 + rand() % 4, Xin, Xout,Yin,Yout;

	for(countY = 0; countY <= SIZE - 1; countY++)
		for(countX = 0; countX <= SIZE - 1; countX++)
			maze[countY][countX] = 1;
	
	for(countY = 1; countY <= SIZE - 2; countY += 2){
		Xin = rand() % 2;
		for(countX = 1; countX <= SIZE - 2; countX++){
			if(Xin == 0)
				maze[countY][countX] = 0;
		}
	}
	

	for(countY = 1; countY <= SIZE - 2; countY +=2){
		Xin = rand() % 2;
		for(countX = 1; countX <= SIZE - 2; countX++){
			if(Xin == 0)
				maze[countX][countY] = 0;
		}
	}

	lato = 1 + rand() % 4;

	printf("\nValore del lato %d\n",lato);
	
	if(lato == 1){  // simistro
		Xin = 0;
		Yin = 1 + rand() % (SIZE - 2); // valore casuale di partenza per y
		Xout = SIZE - 1;
		Yout = 1 + rand() % (SIZE - 2); // valore casuale di partenza per y
	}else if(lato == 2){ // superiore
		Yin = 0;
		Xin = 1 + rand() % (SIZE - 2); // valore casuale di partenza per x
		Yout = SIZE - 1;
		Xout = 1 + rand() % (SIZE - 2); // valore casuale di partenza per x
	}else if(lato == 3){ // destro
		Xin = SIZE - 1;
		Yin = 1 + rand() % (SIZE - 2); // valore casuale di partenza per y
		Xout = 0;
		Yout = 1 + rand() % (SIZE - 2); // valore casuale di partenza per y
	}else if(lato == 4){	// inferiore
		Yin = SIZE - 1;
		Xin = 1 + rand() % (SIZE - 2); // valore casuale di partenza per x
		Yout = 0;
		Xout = 1 + rand() % (SIZE - 2); // valore casuale di partenza per x
	}
	
	*Xo = Xout;
	*Xi = Xin;
	*Yo = Yout;
	*Yi = Yin;

	maze[Yin][Xin] = 0;     // imposti la partenza a 0
	mov = 2 + rand() % 7;
	i = 0;
	printf("\nvalore casuale : %d\n",mov);
	printf("\nValori di partenza Yin = %d , Xin = %d",Yin, Xin);

	while(i < mov){
		if(lato == 1 && Xin  < SIZE - 1)
			maze[Yin][++Xin] = 0;

		else if(lato == 2 && Yin  < SIZE - 1)
			maze[++Yin][Xin] = 0;
		
		else if(lato == 3 && Xin  > 0)
			maze[Yin][--Xin] = 0;
		
		else if(lato  == 4 && Yin  > 0)
			maze[--Yin][Xin] = 0;
	i++;
	}
	
	if(lato == 1) 
		lato = 3;
	else if(lato == 2) 
		lato = 4;
	else if(lato == 3)
		lato = 1;
	else 
		lato = 2;


	maze[Yout][Xout] = 0;     // imposti l'uscita a 0
	mov = 2 + rand() % 4;
	i = 0;
	printf("\nvalore casuale : %d\n",mov);
	printf("\nValori di uscita Yout = %d , Xout = %d",Yout, Xout);
	printf("\nvalore di lato: %d",lato);

	while(i < mov){
                 if(lato == 1 && Xout  < SIZE - 1)
                         maze[Yout][++Xout] = 0;
 
                 else if(lato == 2 && Yout  < SIZE - 1)
                         maze[++Yout][Xout] = 0;
 
                 else if(lato == 3 && Xout  > 0)
                         maze[Yout][--Xout] = 0;
 
                 else if(lato  == 4 && Yout  > 0)
                         maze[--Yout][Xout] = 0;
         i++;
         }

}


void mazePrint(int maze [][12]){
	int x, y;

	for(x = 0; x <= 10; x++)
		printf("\n");

		printf("\t\t     ");

	for(x = 1; x <= 12; x++)
		printf(" %2d",x);

	printf("\n\t\t     ");

	for(x = 1; x <= 12; x++)
		printf("  |");

	printf("\n\t\t");

	for(x = 0; x <= SIZE - 1;x++ ){
		printf("%2d - ",x+1);
		for(y = 0; y <= SIZE - 1; y++)
			printf(" %2d",maze[x][y]);
		printf("\n\t\t");
	}

	//for(x = 0; x <= 10; x++)
	//	printf("\n");

}

void mazeTraverse(int maze[][12], int ys, int xs){

    int x = xs , y = ys;


		
    if(x == 0 && (y >= 0 &&  y <= 11)){    // 1 ° caso inizio a bordo sinistro

	printf("\nPartito da lato sinistro ");

            if(y == 0){  
		printf("angolo superiore ");

		if(maze[y][x+1] == 2){
			maze[x][y] = 2;
		}else if(maze[y+1][x] == 2){
			maze[x][y] = 2;
		}else if(maze[y+1][x] == 0 ){ // libero sotto
			maze[x][y] = 2;
			y++;
		}else if(maze[y][x+1] == 0 ){ // libero davanti
			maze[x][y] = 2;
			x++;
		}else // bloccato
		        maze[y][x] = 2;
	    }else if(y == 11){
		printf("angolo inferiore ");
		if(maze[y][x+1] == 2){
		        maze[y][x] = 2;	
		}else if(maze[y-1][x] == 2){
                        maze[x][y] = 2;
		}else if(maze[y-1][x] == 0){ // libero davanti
			maze[y][x] = 2;
			y--;
		}else if(maze[y][x+1] == 0){ // libero sopra
			maze[y][x] = 2;
			x++;
		}else // bloccato
			maze[y][x] = 2;
	    }else{ // 10 >= y >= 1
		printf("posizione di y : %d",y+1);

		if(maze[y][x+1] == 2){
			maze[y][x] = 2;
	    	}else if(maze[y+1][x] == 2){
			maze[y][x] = 2;
		}else if(maze[y-1][x] == 2){
                        maze[x][y] = 2; 
		}else if(maze[y+1][x] == 0){ // libero in basso
	       		maze[y][x] = 2;
   	    		y++;
	        }else if(maze[y-1][x] == 0){ // libero sopra
		        maze[y][x] = 2;
			y--;
	    	}else if(maze[y][x+1] == 0){ // libero avanti
	     	        maze[y][x] = 2;
	    		x++;
	        }else // bloccato
	    		maze[y][x] = 2;
	        	
	    }	    
	     

     }else if(y == 11 && (x >= 0 &&  x <= 11)){ // 2 * caso inizio bordo inferiore

		printf("\nPartito da lato inferiore  ");
	    if(x == 0){  
	
	        printf("angolo sinistro ");
	    
		if(maze[y-1][x] == 2){
		        maze[y][x] = 2;
		}else if(maze[y][x+1] == 2){
			maze[y][x] = 2;	
	    	}else if(maze[y+1][x] == 0 ){ // libero avanti
			maze[y][x] = 2;
			y++;
		}else if(maze[y][x+1] == 0 ){ // libero sopra
			maze[y][x] = 2;
			x++;
		}else // bloccato
		        maze[y][x] = 2;

	    }else if(x == 11){
		printf("angolo destro ");
		if(maze[y-1][x] == 2){
			maze[y][x] = 2;
		}else if(maze[y][x-1] == 2){
			maze[y][x] = 2;
	        }else if(maze[y-1][x] == 0){ // libero sopra
			maze[y][x] = 2;
			y--;
		}else if(maze[y][x-1] == 0){ // libero dietro
			maze[y][x] = 2;
			x--;
		}else // bloccato
			maze[y][x] = 2;
	    }else{ // 10 >= x >= 1
		printf("posizione di x : %d",x+1);
		
		if(maze[y-1][x] == 2){
			maze[y][x] = 2;
		}else if(maze[y][x+1] == 2){
			maze[y][x] = 2;
		}else if(maze[y][x-1] == 2){
			maze[y][x] = 2;
		}else if(maze[y-1][x] == 0){ // libero avanti
	       		maze[y][x] = 2;
   	    		y--;
	    	}else if(maze[y][x+1] == 0){ // libero sopra
	     	        maze[y][x] = 2;
	    		x++;
	        }else if(maze[y][x-1] == 0){ // libero dietro
		        maze[y][x] = 2;
			x--;
	        }else // bloccato
	    		maze[y][x] = 2;
	        	
	    }
	    
    
  	}else if(x == 11 && (y >= 0 && y <= 11)){ // 3 * caso inizio bordo destro

		printf("\nPartito da lato destro  ");
	    if(y == 0){  
		printf("angolo superiore ");
 		if(maze[y][x-1] == 2){
			maze[y][x] = 2;
		}else if(maze[y+1][x] == 2){
			maze[y][x] = 2;
		}else if(maze[y][x-1] == 0){ // libero dietro
			maze[y][x] = 2;
			x--;
		}else if(maze[y-1][x] == 0){ // libero sotto
			maze[y][x] = 2;
			y--;
		}else // bloccato
		        maze[y][x] = 2;

	    }else if(y == 11){
		printf("angolo inferiore ");

		if(maze[y-1][x] == 2){
			maze[y][x] = 2;
		}else if(maze[y][x-1] == 2){
			maze[y][x] = 2;
		}else if(maze[y][x-1] == 0 ){ // libero sopra
			maze[y][x] = 2;
			x--;
		}else if(maze[y-1][x] == 0 ){ // libero dietro
			maze[y][x] = 2;
			y--;
		}else // bloccato
			maze[y][x] = 2;
	    }else{ // 10 >= x >= 1
		printf("posizione di y : %d",y+1);

		if(maze[y-1][x] == 2){
			maze[y][x] = 2;
		}else if(maze[y][x-1] == 2){
			maze[y][x] = 2;
		}else if(maze[y][x] == 2){
			maze[y][x] = 2;
	        }else if(maze[y][x-1] == 0){ // libero dietro
		        maze[y][x] = 2;
			x--;
	    	}else if(maze[y-1][x] == 0){ // libero sopra
	     	        maze[y][x] = 2;
	    		y--;
	        }else if(maze[y+1][x] == 0){ // libero dietro
		        maze[y][x] = 2;
			y++;
	        }else // bloccato
	    		maze[y][x] = 2;
	        	
	    }	    
	     
    
  	}else if(y == 0 && (x >= 0 && x <= 11)){    // 4 ° caso inizio a bordo superiore

		printf("\nPartito da lato superiore  ");
	    if(x == 0){  
		printf("angolo sinistro ");

		if(maze[y+1][x] == 2){
		        maze[y][x] = 2;
		}else if(maze[y][x+1] == 2){
			maze[y][x] = 2;
		}else if(maze[y+1][x] == 0 ){ // libero sotto
			maze[y][x] = 2;
			y++;
		}else if(maze[y][x+1] == 0 ){ // libero davanti
			maze[y][x] = 2;
			x++;
		}else // bloccato
		        maze[y][x] = 2;
	    }else if(x == 11){
		printf("angolo destro ");
		
		if(maze[y][x-1] == 2){
			maze[y][x] = 2;
		}else if(maze[y+1][x] == 2){
			maze[y][x] = 2;
		}else if(maze[y][x-1] == 0 ){ // libero dietro
			maze[y][x] = 2;
			x--;
		}else if(maze[y+1][x] == 0 ){ // libero sotto
			maze[y][x] = 2;
			y++;
		}else // bloccato
			maze[y][x] = 2;
	    }else{ // 10 >= x >= 1
		printf("posizione di x : %d",x+1);
	
		if(maze[y+1][x] == 2){
			maze[y][x] = 2;
		}else if(maze[y][x-1] == 2){
			maze[y][x] = 2;
		}else if(maze[y][x+1] == 2){
			maze[y][x] = 2;
		}else if(maze[y][x-1] == 0){ // libero dietro
	       		maze[y][x] = 2;
   	    		x--;
	    	}else if(maze[y+1][x] == 0){ // libero sotto
	     	        maze[y][x] = 2;
	    		y++;
	        }else if(maze[y][x+1] == 0){ // libero avanti
		        maze[y][x] = 2;
			x++;
	        }else // bloccato
	    		maze[y][x] = 2;
	        	
	    }	    

	}else{// if(x > 0 && x < SIZE -1 && y >0 && y < SIZE - 1){ // interno quadrato

		if(maze[y][x-1] != 0){ // provenienza da sinistra

			// casi in cui giro a destra
			printf("\nProvengo da sinistra ");
			if(maze[y+1][x] == 0){ // giro a dx all'incrocio
				printf("giro a destra");
				maze[y][x] = 2;
				y++;
			}else if(maze[y][x+1] == 0){ // proseguo se dx è bloccato
				printf("tiro dritto!");
				maze[y][x] = 2;
				x++;
			}else if(maze[y-1][x] == 0){ // giro a sx se unica
				printf("giro a sinistra");
				maze[y][x] = 2;
				y--;
			}else{
				printf("sono in trappola");
				maze[y][x] = 2;
			}
		}else if (maze [y][x+1] != 0){ // provenienza da destra
			
			printf("\nProvengo da destra ");
			if(maze[y-1][x] == 0){ // giro a dx all'incrocio
				printf("giro a destra");
				maze[y][x] = 2;
				y--;
			}else if(maze[y][x-1] == 0){ // proseguo se dx è bloccato
				printf("tiro dritto!");
				maze[y][x] = 2;
				x--;
			}else if(maze[y+1][x] == 0){ // giro a sx se unica
				printf("giro a sinistra");
				maze[y][x] = 2;
				y++;
			}else{
				printf("sono in trappola");
				maze[y][x] = 2;
			}
		}else if (maze [y-1][x] != 0){ // provenienza da sopra

			// casi in cui giro a dx
			printf("\nProvengo da su ");
			if(maze[y][x-1] == 0) { // giro a dx se tutto libero
				printf("giro a destra");
				maze[y][x] = 2;
				x--;
			// casi in cui vado dritto
			}else if(maze[y+1][x] == 0){ // proseguo se dx è bloccato
				printf("tiro dritto!");
				maze[y][x] = 2;
				y++;
			// casi in cui giro a sx
			}else if(maze[y][x+1] == 0){  // giro a sx se unica
				printf("giro a sinistra");
				maze[y][x] = 2;
				x++;
			}else{
				printf("sono in trappola");
				maze[y][x] = 2;
			}
		}else if(maze[y+1][x] != 0){ // provengo dal basso
	
			printf("\nProvengo da giu ");

			// tutto libero giro a dx
			if(maze[y][x+1] == 0 ) { 
				printf("giro a destra");
				maze[y][x] = 2;
				x++;
			}else if(maze[y-1][x] == 0 ){
				printf("tiro dritto!");
				maze[y][x] = 2;
				y--;
			}else if(maze[y][x-1] == 0){
				printf("giro a sinistra");
				maze[y][x] = 2;
				x--;
			}else{
				printf("sono in trappola");
				maze[y][x] = 2;
			}
		}
		}
	
		
   	//mazePrint(maze);
	//getchar();

	if(x != xs || y != ys){
	    mazeTraverse(maze,y,x);
	}else
	    return;
    

}


void mazeCreation(int maze[][12]){

	int x, y;

	for(x = 0; x <= SIZE - 1; x++)
		for(y = 0; y <= SIZE - 1; y++)
			maze[x][y] = rand() % 2;

}
