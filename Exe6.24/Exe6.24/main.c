//
//  main.c
//  Exe6.24
//
//  Created by Francesco Parrucci on 02/03/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
/*
(IL GIRO DEL CAVALLO) UNO DEI PROBLEMI PIU INTERESSANTI PER GLI APPASSIONATI DEL GIOCO DEGLI SCACCHI E' QUELLO DEL GIRO DEL CAVALLO, PROPOSTO ORIGINARIAMENTE DAL MATEMATICO EULERO. LA QUESIONE E' QUESTA: PUO' ILPEZZO DEGLI SCACCHI CHIAMATO CAVALLO MUOVERSI IN UNA SCACCHIERA VUOTA, VISITANDO UNA SOLA VOLTA OGNUNA DELLE 64 CASELLE? STUDIEREMO APPROFONDITAMENTE QUESTO PROBLEMA AFFASCINANTE. IL CAVALLO COMPIE DELLE MOSSE AFORMA DI L: DUE CASELLE IN UNA DIREZIONE E UNA IN UNA DIRETTRICE PERPENDICOLARE A QUELLA PRECEDENTE. NE CONSEGUE CHE, DA UNA CASELLA CENTRALE DI UNA SCACCHIERA VUOTA, IL CAVALLO POTRA' ESEGUIRE OTTO DIFFERENTI 
MOSSE (NUMERATE DA 0 A 7). 
 
A) DISEGNATE UNA SCACCHIERA 8 PER 8 SU UN FOGLIO DI CARTA E TENTATE DI PORTARE A TERMINE MANUALMENTE UN GIRO DEL CAVALLO. INSERITE UN 1 NELLA PRIMA CASELLA IN CUI VI MUOVERETE, UN 2 NELLA SECONDA, UN 3 NELLA TERZA, ECC. PRIMA DI INCOMINCIARE IL GIRO, PROVATE A FARE UNA STIMA DELLE MOSSE CHE RIUSCIRETE A COMPIERE, RICORDANDO CHE UN GIRO COMPLETO CONSISTE DI 64 MOSSE. DOVE SIETE ARRIVATI? VI SIETE AVVICINATI ALLA VOSTRA STIMA?

B) ORA SVILUPPEREMO UN PROGRAMMA CHE MUOVERA' IL CAVALLO IN GIRO PER LA SCACCHIERA. LA SCACCHIERA STESSA SARA' RAPPRESENTATA DALLA MATRICE 8 PER 8 board. OGNUNA DELLE CASELLE SARA' INIZIALMENTE AZZERATA. DESCRIVEREMO OGNUNA INIZIALMENTE AZZERATA. DESCIVEREMO OGNUNA DELLE OTTO POSSIBILI MOSSE SCINDENDOLE NELLE LORO COMPONENTI ORIZZONTALI E VERTICALI. PER ESEMPIO, UNA MOSSA COME LA 0 MOSTRATA NELLA FIGURA  6.24 POTRA' 
ESSERE SCOMPOSTA IN UN MOVIMENTO ORIZZONTALE (DUE CASELLE A DESTRA) E IN UNO SPOSTAMENTO VERTICALE (UNA CASELLA IN ALTO). LA MOSSA 2 CONSISTERA' DI UNO SPOSTAMENTO ORIZZONTALE (UNA CASELLA A SINISTRA) E DI UNO SPOSTAMENTO VERTICALE (DUE CASELLE IN ALTO). LE MOSSE ORIZZONTALI A SINISTRA E QUELLE VERTICALI VERSO L'ALTO SARANNO INDICATE CON DEI NUMERI NEGATIVI. LE OTTO MOSSE POTRANNO ESSERE DESCRITTE DA DUE VETTORI UNIDIMENSIONALI, horizontal E vertical, COME SEGUE: 

 	 horizontal[0] =  2
	 horizontal[1] =  1
	 horizontal[2] = -1
  	 horizontal[3] = -2
 	 horizontal[4] = -2
	 horizontal[5] = -1
	 horizontal[6] =  1
	 horizontal[7] =  2

	 vertical [0] = -1
	 vertical [1] = -2
	 vertical [2] = -2
	 vertical [3] = -1
	 vertical [4] =  1
	 vertical [5] =  2
	 vertical [6] =  2
	 vertical [7] =  1
 
LE VARIABILI currentRow E currentColumn INDICHERANNO RISPETTIVAMENTE LA RIGA E LA COLONNA DELLA PRIMA POSIZIONE CORRENTE DEL CAVALLO. PER ESEGUIRE UNA MOSSA DI TIPO moveNumber, DOVE moveNumber SIA COMPRESO TRA 0E 7, IL VOSTRO PROGRAMMA UTILIZZERÀ QUESTE ESTRUZIONI:

	currentRow += vertical[moveNumber];
	currentColumn += horizontal[moveNumber];

UTILIZZATE UN CONTATORE CHE VARI NELL'INTERVALLO DA 1 A 64. REGISTRATE L'ULTIMO VALORE ASSUNTO DAL CONTANTORE DI OGNI CASELLA VISITATA DAL CAVALLO. RICORDATE DI VERIFICATE OGNI MOSSA POTENZIALE PER ASSICURARVI CHE IL CAVALLO NON CADA FUORI DELLA SCACCHIERA. ORA SCRIVETE UN PROGRAMMA CHE PORTI IL CAVALLO IN GIRO PER LASCACCHIERA. ESEGUITE IL PROGRAMMA. QUANTE MOSSE HA COMPIUTO IL CAVALLO?

C) DOPO AVER TENTATO DI SCRIVERE ED ESEGUIRE UN PROGRAMMA CHE RISOLVA IL PROBLEMA DEL GIRO DEL CAVALLO, AVRETE PROBABILMENTE SVILUPPATO QUALCHE PREZIOSA INTUIZIONE. UTILIZZEREMO PROPRIO QUELLE PER SVILUPPARE UN METODO EURISTICO (OVVEROSIA UNA STRATEGIA) PER MUOVERE IL CAVALLO. I METODI EURISTICI NON GARANTISCONO IL SUCCESSO MA, SE SVILUPPATI ACCURATAMENTE, AUMENTANO ENORMEMENTE LE PROBABILITA DI SUCCESSO. DOVRESTE AVER NOTATO CHE LE CASELLE PIU'  ESTRERNE SONO, IN UN CERTO SENSO, PIU' PROBLEMATICHE DI QUELLE PIU VICINE AL CENTRO DELLA SCACCHIERA. INFATTI, LE CASELLE PIU PROBLEMATICHE, O INACCESSIBILI, SONO PROPRIO QUELLE DEI 
QUATTTRO ANGOLI. 
L'INTUIZIONE POTRA' SUGGERIRVI CHE, AL PRINCIPIO, SARA MEGLIO TENTARE DI MUOVERE IL CAVALLO NELLE CASELLE PIU PROBLEMATICHE, LASCIANDO LIBERE QUELLE PIU FACILI DA RAGGIUNGIERE, IN MODO DA AVERE MAGGIORI PROBABILITA' DI SUCCESSO VERSO LA FINE DEL GIRO, QUANDO LA SCACCHIERA SARA' CONGESTIONATA. 
PROTREMO SVILUPPARE UNA "EURISTICA DELL'ACCESSIBILITA" , CLASSICFIAQFANDO OGNUNA DELLE CASELLE IN BASE ALLA LORO ACCESSIBILITA' E MUOVENDO CONSEGUENTEMENTE IL CAVALLO NELLA CASELLA MENO ACCESSIBILE TRA QUELLE RAGGIUNGIBILI DALSUO PARTICOLARE MOVIMENTO A L. ETICHIETTEREMO LA MATRICE accessibility CON DEI VALORI CHE INDICHI, PER OGNI CASELLA , IL NUMERO DI QUELLE DALLE QAUALI ESSA POTRAÌ ESSERE RAGGIUNTA. IN UNA SCACCHIERA VUOTA, LE CASELLE, DEL CENTRO SARANNO DUNQUE VALUTATE 8, QUELLE DEGLI ANGOLI 2, MENTRE LE ALTRE AVRANNO DEI VALORI D'ACCESSIBILITAÌ PARI A 3, 4  O 6, COME SEGUE:

	2 3 4 4 4 4 3 2
	3 4 6 6 6 6 4 3
	4 6 8 8 8 8 6 4
	4 6 8 8 8 8 6 4
	4 5 8 8 8 8 6 4
	4 6 8 8 8 8 6 4 
	3 4 6 6 6 6 4 3
	2 3 4 4 4 4 3 2

ORA SCRIVETE UNA VERSIONE DEL PROGRAMMA PER IL GIRO DEL CAVALLO CHE UTILIZZI L'EURISTICA DELL'ACCESSIBILITA. IN OGNI MOMENTO, IL CAVALLO DOVRA MUOVERSI NELLA CASELLA CON IL NUMERO DI ACCESSIBILITA' PIU BASSO. IN CASO DI PARITA' TRA CASELLE, IL CAVALLO POTRA MUOVERSI VERSO UNA QUALSIASI DI QUELLE A PARI MERITO, DI CONSEGUENZA, IL GIRO POTRAÌ COMINCIARE IN UNO QUALSIASI DE I QUATTTRO ANGOLI. (NOTA: IL VOSTRO PROGRAMMA DOVRA' RIDURRE I VALORI DI ACCESSIBILITA' POICHE' CON LO SPOSTAMENTO DEL CAVALLO SULLA SCACCHIERA AUMENTERA' IL NUMERO DI CASELLE GIA' VISITATE. IN QUESTO MODO , IN UNA QUALSIASI MOMENTO DEL GIRO, IL NUMERO DI ACCESSIBILITA' DI OGNI CASELLA RIMARRA' ESATTAMENTE UGUALE AL NUMERO DI CASELLE DALLE QUALI ESSA POTRAÌ ESSERE RAGGIUNTA). ESEGIUTE QUESTA VERSIONE DEL VOSTRO PROGRAMMA. AVETE OTTENUTO UN GIRO COMPLETO ? MODIFICATE ORA IL PROGRAMMA FACENDO IN MODO CHE IL CAVBALLO COPIA 64 
GIRI , PARTENDO DA OGNUNA DELLE CASELLE DELLA SCACCHIERA, QUANTRI GIRI COMPLETATI AVETE OTTENUTO?

D) SCRITETE UNAVESIONE DEL PROGRAMMA DEL GIRO DEL CAVALLO CHE, QUALORA SI IMBATTA IN UN PAREGGIO TRA DUE O PIU CASELLE, DECIDA QUALE SCEGLIERE DOPO AVER DATO UNO SGUARDO ALLE CASELLE CHE POTRANNO ESSERE RAGGIUNTYE DA QUELLE A "PARI MERITO". IL VOSTRO PROGRAMMA DOVRA' MUOVERE IL CAVALLO NELLA CASELLA DA CUI SARA' POSSIBILE RAGGIUNGERE QUELLA CON IL VALORE  DI ACCESSIBILITA' PIU BASSO. 
*/


// Sviluppo TOP DOWN : MUOVERE IL CAVALLO SU SCACCHIERA  8 X 8 
//
// 1° RAFFINAMENTO
//
// DICHIARAZIONE MATRICE PER SCACCHIERA 8 X 8 board E INIZIALIZZA A 0
// DICHIARAZIONE DI VARIABILE INTERA COUNT, COUNT1 , currentRow , currentColumn, moveNumber
// DICHIARAZIONE DI VETTORI DI INTERI horizontal[8] = {2,1,-1,-2,-2,-1,1,2}, e vertical[8] = {-1,-2,-2,-1,1,2,2,1} 
// PER I VALORI DI COUNT DA 1 A 64 
//
// 	moveNumber UGUALE A UN NUMERO CASUALE DA 0 A 7 LA MOSSA
//
//	SE currentRow + vertical[moveNumber] E  currentColumn + vertical[moveNumber] SONO FUORI DALL'INTERVALLO 0 - 7
//		currentRow += vertical[moveNumber]
//		currentColumn += horizontal[moveNumber]
//		board[currentRow] [currentColumn]++ 
//
// PER COUNT DA 0 A 7
// 	PER COUNT1 DA 0 A 7
//		STAMPA board[COUNT] [COUNT1]
// STAMPA "\N"
//
// 2° RAFFINAMENTO 
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // insert code here...

    srand(time(NULL));	

    int count, count1 , board[8][8] = {0}, currentRow = 7 , currentColumn = 7, moveNumber, tempRow, tempColumn;
    int horizontal[8] = {2,1,-1,-2,-2,-1,1,2}, vertical[8] = {-1,-2,-2,-1,1,2,2,1};
    int temp;

    for( count = 1 ; count <= 64 ; count++){
    
    count1 = 0;

    	do{
		moveNumber = rand() % 8;
		tempRow = currentRow + vertical[moveNumber];
		tempColumn = currentColumn + horizontal[moveNumber];

    		if(((tempRow >= 0 || tempRow <= 7) && (tempColumn >= 0 || tempColumn <= 7)) && (board[tempRow][tempColumn] == 0)){
         		currentRow = tempRow;
			currentColumn = tempColumn;
			board[currentRow] [currentColumn] = count;
			break;
        	}
    	        
    	}while(count1++ < 7);
    }

    printf("\n");

    for (count = 0; count <= 7; count++){
	    for(count1 = 0; count1 <= 7; count1++)
		    printf("%3d",board[count][count1]);
    printf("\n");
    }

    printf("\nHello, World!\n");
    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // insert code here...

    srand(time(NULL));

    int count = 1, x, y,  count1 , board[8][8] = {0}, currentRow = 7 , currentColumn = 7, moveNumber, tempRow, tempColumn;
    int horizontal[8] = {2,1,-1,-2,-2,-1,1,2}, vertical[8] = {-1,-2,-2,-1,1,2,2,1};

    		for(x = 0; x <= 7 ; x++){
			for(y = 0; y <= 7; y++){
			
				if(x <= 2){
				count1 = 0;
				do{
                                	moveNumber =  rand() % 8;
                                	tempRow = currentRow + vertical[moveNumber];
                                	tempColumn = currentColumn + horizontal[moveNumber];

                                   if(((tempRow >= 0 || tempRow <= 7) && (tempColumn >= 0 || tempColumn <= 2)) && (board[tempRow][tempColumn] == 0)){
                                	currentRow = tempRow;
                                	currentColumn = tempColumn;
                                	board[currentRow] [currentColumn] = count++;
                                	break;
                        		}

                        	}while(count1++ < 7);
				}else if(x >= 5){
				count1 = 0;
                                do{
                                        moveNumber =  rand() % 8;
                                        tempRow = currentRow + vertical[moveNumber];
                                        tempColumn = currentColumn + horizontal[moveNumber];

                                   if(((tempRow >= 0 || tempRow <= 3) && (tempColumn >= 5 || tempColumn <= 7)) && (board[tempRow][tempColumn] == 0)){
                                        currentRow = tempRow;
                                        currentColumn = tempColumn;
                                        board[currentRow] [currentColumn] = count++;
                                        break;
                                        }

                                }while(count1++ < 7);
				count1 = 0;
				}else if(y <= 2){
                                do{
                                        moveNumber =  rand() % 8;
                                        tempRow = currentRow + vertical[moveNumber];
                                        tempColumn = currentColumn + horizontal[moveNumber];

                                   if(((tempRow >= 0 || tempRow <= 2 ) && (tempColumn >= 0 || tempColumn <= 7)) && (board[tempRow][tempColumn] == 0)){
                                        currentRow = tempRow;
                                        currentColumn = tempColumn;
                                        board[currentRow] [currentColumn] = count++;
                                        break;
                                        }

                                }while(count1++ < 7);

				}else if(y >= 5){
				count1 = 0;
                                do{
                                        moveNumber =  rand() % 8;
                                        tempRow = currentRow + vertical[moveNumber];
                                        tempColumn = currentColumn + horizontal[moveNumber];

                                   if(((tempRow >= 5 || tempRow <= 7) && (tempColumn >= 0 || tempColumn <= 7)) && (board[tempRow][tempColumn] == 0)){
                                        currentRow = tempRow;
                                        currentColumn = tempColumn;
                                        board[currentRow] [currentColumn] = count++;
                                        break;
                                        }

                                }while(count1++ < 7);
				}else{
                                count1 = 0;
                                do{
                                        moveNumber =  rand() % 8;
                                        tempRow = currentRow + vertical[moveNumber];
                                        tempColumn = currentColumn + horizontal[moveNumber];

                                   if(((tempRow >=3 || tempRow <= 4) && (tempColumn >= 3 || tempColumn <= 4)) && (board[tempRow][tempColumn] == 0)){
                                        currentRow = tempRow;
                                        currentColumn = tempColumn;
                                        board[currentRow] [currentColumn] = count++;
                                        break;
                                        }

                                }while(count1++ < 7);
				}
						
			}
		}
    printf("\n");

    for (count = 0; count <= 7; count++){
            for(count1 = 0; count1 <= 7; count1++)
                    printf("%3d",board[count][count1]);
    printf("\n");
    }

    printf("\nHello World!!!\n");

    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int angular(int, int);
int search (int [], int, int);
int board [8][8] = {0};

int main() {
    // insert code here...

    srand(time(NULL));

    int count = 1, count1 , currentRow = 0, currentColumn = 0, moveNumber, tempRow, tempColumn;
    int horizontal[8] = {2,1,-1,-2,-2,-1,1,2}; 
    int  vertical[8] = {-1,-2,-2,-1,1,2,2,1};
    int buffer[8] = {8};


    board[currentRow][currentColumn] = count++;
	
while(count <= 64){	
	moveNumber = angular(currentRow, currentColumn);
	tempRow = currentRow + vertical[moveNumber];
        tempColumn = currentColumn + horizontal[moveNumber];

       	if((tempRow > -1 && tempRow < 8) && (tempColumn > -1 && tempColumn < 8) && (board[tempRow][tempColumn] == 0)){
       		currentRow = tempRow;
       		currentColumn = tempColumn;
       		board[currentRow] [currentColumn] = count++;
          		
       	}else{
		count1 = 0;
       	 	for(count1 = 0; count1 <= 7; count1++){

			do{
			    buffer[count1] = rand() % 8;
			}while(search(buffer,buffer[count1],count1));
			
			tempRow = currentRow + vertical[buffer[count1]];
      			tempColumn = currentColumn + horizontal[buffer[count1]];

 	        if((tempRow > -1 && tempRow < 8) && (tempColumn > -1 && tempColumn < 8) && (board[tempRow][tempColumn] == 0)){
        	       currentRow = tempRow;
         	       currentColumn = tempColumn;
         	       board[currentRow] [currentColumn] = count++;
		       break;
		}
		}

	}

	if(count1 > 7 )	
            break;
}				
	
    
    printf("\n");

    for (count = 0; count <= 7; count++){
            for(count1 = 0; count1 <= 7; count1++)
                    printf("%3d",board[count][count1]);
    printf("\n");
    }

    printf("\nHello World!!!\n");

    return 0;
}


int angular(int y, int x)
{
	//int horizontal[8] = {2, 1,-1,-2,-2,-1,1,2};
	//int  vertical[8] = {-1,-2,-2,-1, 1, 2,2,1};

	int moveNumber = 0;

                // selezione per i quattro angoli
		
		if(y == 1 && x == 2)
                        moveNumber = 3;

                else if(y == 2 && x == 1)
                        moveNumber = 2;
                
		else if(y == 1 && x == 5)
                        moveNumber = 0;
                
		else if(y == 2 && x == 6)
                        moveNumber = 1;
                
		else if(y == 5 && x == 1)
                        moveNumber = 5;
                
		else if(y == 6 && x == 2)
                        moveNumber = 4;
                
		else if(y == 5 && x == 6)
                        moveNumber = 6;
                
		else if(y == 6 && x == 5)
                        moveNumber = 7;

		else if(y == 0 && x == 0)
                        moveNumber = board[1][2] ? 7 : 6;

		else if(y == 0 && x == 7)
		        moveNumber = board[2][6] ? 4 : 5;

		else if(y == 7 && x == 0)
                        moveNumber = board[5][1] ? 0 : 1;

		else if(y == 7 && x == 7)
                        moveNumber = board[6][5] ? 2 : 3;		

		else if((y <= 1 && x <= 1) || (y >= 6 && x <= 1))
                       moveNumber = rand() % 2 ? 7 : 0;

                else if((y <= 1  && x >= 6) || (y >= 6 && x >= 6))
                        moveNumber = 3 + rand() % 2 ;
		 
		//else if((y <= 1 && x <= 1) || (y <= 1 && x >= 6))
                //       moveNumber = 5 + rand() % 2;

                //else if((y >= 6 && x <= 1) || (y >= 6 && x >= 6))
                //        moveNumber = 1 + rand() % 2;

		else
			moveNumber = rand() % 8;
		
	return moveNumber;
}


int search(int buf[], int value, int stop){

int count ,ret = 0;
if(stop == 0)
	ret = 0;
else{
	for(count = 0; count <= stop - 1; count++)
		if(buf[count] == value)
			ret = 1;
}

return ret;
}
*/

#include <stdio.h>
#define SIZE 8

void stampa(int [][8]);
int ctrl(int [][8], int , int, int );
int reverse(int , int, int , int);
int obstacole(int);
void clean(int board[][8]);

int main(){

 int board [8][8] = {0}, y  ,x ;
        //            0  1  2  3  4  5 6 7
 int horizontal[8] = {2, 1,-1,-2,-2,-1,1,2};
 int vertical[8]  = {-1,-2,-2,-1, 1, 2,2,1};
 int count = 7, n = 1, move, count1 = -1 ;
 int result[8][8] = {0}, c1, c2; 
  
// printf("Immettere un valore per y e x :");
// scanf("%d%d",&y,&x);

 
for(c1 = 0; c1 <= 7; c1++){
	
  for(c2 = 0 , y = c1, x = c2, count = 7, count1 = -1, n = 1; c2 <= 7 ; c2++){
  clean(board);
  
  board[y][x] = n++;

  while(count1 < 7){
        
	move = ctrl(board,y,x,count);

	if(move < 0){
		count = obstacole(count);
		count1++;
	}else{	
		y += vertical[move];
        	x += horizontal[move];
        	board[y][x] = n++;
		count1 = -1;
		count = reverse(count ,n ,y , x);
	}
	
  }
  result[c1][c2] = n;
  printf("\nValore della caselle occupate: %d\n", n); 	   
	}

}
 stampa(result);

 return 0;
}

void clean(int board[][8]){
int count, count1;

for(count = 0; count <= 7; count++)
	for(count1 = 0; count1 <= 7 ; count1++)
		board[count][count1] = 0;
}

int obstacole(int count){


		if(count < 7)
			count++;
		else
			count = 0;

	return count;

}

void stampa(int bord[][8]){
    int count , count1;
    
    printf("\n");

    for (count = 0; count <= 7; count++){
            for(count1 = 0; count1 <= 7; count1++)
                    printf("%4d",bord[count][count1]);
    printf("\n\n");
    }

    printf("\n");
}


int ctrl(int board[][8], int y, int x, int dir){
   
               //            0  1  2  3  4  5 6 7
        int horizontal[8] = {2, 1,-1,-2,-2,-1,1,2};
        int vertical[8]  = {-1,-2,-2,-1, 1, 2,2,1};
	int tempRow, tempColumn; 

        tempRow = y + vertical[dir];
        tempColumn = x + horizontal[dir];

 	
	if(!((tempRow >= 0 && tempRow <= 7) && (tempColumn >= 0 && tempColumn <= 7)))
		return -1;       
	else if(board[tempRow][tempColumn] != 0)
		return -2;
	else
		return dir;
	
}


int reverse(int count, int n, int y ,int  x){
	       //              0  1  2  3  4  5 6 7
//        int horizontal[8] = {2, 1,-1,-2,-2,-1,1,2};
//        int vertical[8]  = {-1,-2,-2,-1, 1, 2,2,1};
int ret;

		switch (count){
			case 6:
	  		ret = 5;
	  		break;

			case 5:
	  		ret = 6;
	  		break;

			case 7:
	  		ret = 0;
	  		break;
	  
			case 0:
	  		ret = 7;
	  		break;
	
			case 3:
	  		ret = 4;
	  		break;

			case 4:
	  		ret = 3;
	  		break;

			case 2:
	  		ret = 1;
	  		break;

			case 1:
	  		ret = 2;
	  		break;

	 }

	

return ret;
}
