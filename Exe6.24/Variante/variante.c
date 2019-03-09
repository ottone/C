#include <stdio.h>
#include <stdlib.h>
#define n 8
typedef enum {false, true} boolean;

boolean SearchOne (int b[n][n], int i, int j,int k){

//      int horizontal[8] = {2, 1,-1,-2,-2,-1,1,2};
//      int vertical[8]  = {-1,-2,-2,-1, 1, 2,2,1};

	int i1,j1, m;	
	for(m=1; m<=8;m++){
		if(m==1){i1=i-1; j1=j+2;}	 // 0
		else if(m==2){i1=i-2; j1=j+1;}   // 1
		else if(m==3){i1=i-2; j1=j-1;}   // 2
		else if(m==4){i1=i-1; j1=j-2;}   // 3
		else if(m==5){i1=i+1; j1=j-2;}   // 4
		else if(m==6){i1=i+2; j1=j-1;}   // 5
		else if(m==7){i1=i+2; j1=j+1;}   // 6
		else {i1=i+1; j1=j+2;}		 // 7
	
		if(0<=i1 && i1<=n-1 && 0<=j1 && j1<=n-1 && b[i1][j1]==0){
			b[i1][j1]=k;
			if(k==n*n || SearchOne(b,i1,j1,k+1)) 
				return true;
			b[i1][j1]=0;
		}
	}
	return false;
}

void main(){
	int i,j,r,c;

	printf("\n\n\t\t<<IL GIRO DEL CAVALLO>> \n\n");
	getchar();
	printf("\n\n\n");
	int b[n][n]={{0}};
	printf("\n\n\n riga di partenza:");
	scanf("%d",&r);
	if(r<0 || r>=n)return;
	printf("\n\n colonna di partenza:");
	scanf("%d",&c);
	if(c<0 || c>=n)return;
	b[r][c]=1;
	if(SearchOne(b,r,c,2)){
		printf("\n\n\n");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf(" %3d ",b[i][j]);
			}
			printf("\n\n");
		}
	}
	else printf("\n\nNON ESISTE SOLUZIONE\n\n");

}
