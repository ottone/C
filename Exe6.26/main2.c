#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 8

void copy(char to[N][N],char fm[N][N]){
int i, j;
	for(i = 0; i <= N - 1; i++)
		for(j = 0; j <= N - 1; j++)
			to[i][j] = fm[i][j];
}

void stampa(char b[N][N]){
	
int i, j;

for(i = 0; i <= N - 1; i++)
       putchar('-');

printf("\n\n");

for(i = 0; i <= N - 1; i++){
	for(j = 0; j <= N-1 ; j++){
		putchar(b[i][j]);
		putchar(' ');
	}
	printf("\n");
}

printf("\n\n");

for(i = 0; i <= N - 1; i++)
       putchar('-');

printf("\n\n");

return ;
}

void sign(char b[N][N],int y, int x){
	
int i, j, dx, sx;

for(j = 0; j <= N - 1; j++){
	if(j == x) continue;
	b[y][j] = 'x';
}

for(dx = 1, sx = 1, i = y + 1; i <=  N - 1; i++, dx++, sx++){
	if((x - dx) >= 0 )
		b[i][x - dx] = 'x';

	if((x + sx) <= N - 1)
		b[i][x + sx] = 'x';

	b[i][x] = 'x';
}

b[y][x] = 'R';

stampa(b);

}	

void shift(int v[N]){
int m;
	for(m = 1; m <= N - 1;m++){
		v[m - 1] = v[m];
	}

}

void init(char b[N][N],int row){
int j;

for( ;row <= N - 1; row++)
	for(j = 0; j <= N - 1; j++)
		b[row][j] = '-';
}

int check(int v[N], char b[N][N],int row){
	int m, n;

	for(m = 0, n = 0 ; m <= N - 1; m++ )
		if(b[row][m] == '-') 
			v[n++] = m;

	return n;
}

void printVett(int v[N]){
int m;

printf("%2d",v[0]);

for (m = 1;m <= N -1 ; m++){
	if(v[m] != 0)
		printf("%2d", v[m] );

}
printf("\n");
}


	

int backTrack(char b[N][N], int row){
    int v[N] = {0}, m = 0, n = 0;
    char c[N][N];

    copy(c,b);
    m = check(v,c,row);

    printf("\nRiga %d, posti liberi: %d \n", row ,m);
    if(m != 0)
    printVett(v);
    getchar();

    if(row == N){
            stampa(b);
            return 0;
    }

    if(m == 0)
         return -1;
    else
         sign(c,row,v[n]);

    if(backTrack(c,row + 1) == -1){
        if(row == 0){
		init(b,row);
		copy(c,b);
		n += 1;
		sign(c,row,v[n]);
		backTrack(c,row + 1);
	}

	copy(c,b);
        stampa(c);
        n += 1;
        if(n == m)
                return -1;
        else{
        sign(c,row,v[n]);
        backTrack(c,row + 1);
        }
    }


}

int main(){

srand(time(NULL));

int k, row, l ,vett[N+1] = {0}, t, x , y;
char m[N][N];

init(m,0);// inizializzazoine della matrice 
stampa(m);

/*
for(row = 0; row <= N - 1; row++){
    for(l = 0, k = 0; k <= N - 1; k++)
	if(m[row][k] != 'x') vett[l++] = k; // ricerca posizioni

printf("\nInserire un valore a scelta tra i seguenti: ");

for(t = 0; t <= l - 1; t++){
 	printf("%-2d",vett[t]);
}
 scanf("%d",&l);
 sign(m,row,l);
 stampa(m); 
for(l = 0; l <= N - 1; l++)
	vett[l] = 0;
}
*/

while(backTrack(m,0) != 0)
	;

	
}
