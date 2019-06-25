//
//  main.c
//
//  Created by Francesco Parrucci on 04/06/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define size 100
#define word 20 


void BubbleSort(int [], int , int );
void ShellSort(int [], int, int );
void QuickSort(int [], int, int );
void print(int []);
int swap(int [], int , int );
int partition(int [] , int , int);

int main(){

	int s[word], count;
	
	srand(time(NULL));

	for(count = 0; count < word ; count++)
		s[count] = 1 + rand() % 100;
	
	print(s);

	//BubbleSort(s, 0 ,word);
	//ShellSort(s, 0, word-1);
	QuickSort(s, 0, word-1);
	//count = partition(s,0, word -1);
	//printf("\nValore di ritorno di partition : %d\n",count);
	
	print(s);
	
	return 0;
}

	
void print(int a[]){

	int count; 

	printf("\n\n");
	
	for(count = 0; count < word; count++)
			printf("   %2d ",count);

	printf("\n");
	
	for(count = 0; count < word; count++)
		printf("   %2d ",a[count]);


	printf("\n\n");

}

void BubbleSort(int a[], int l, int r){


	int i, j, temp;

	for(i = l; i < r; i++)
		for(j = r; j > i ; j--){
			if(a[j] < a[j-1]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
}


void ShellSort(int  a[], int l, int r){

	int i , j , h, temp;

	for(h = (r-l)/2; h > 0 ; h /= 2)
		for(i = l + h; i <= r; i++) 
		   for( j = i-h ; j < i; j++ ){
	   	    if(a[j] > a[i]){
			    temp = a[j];
			    a[j] = a[i];
			    a[i] = temp;
		    }else
			continue;	
		}	
		   
}		   
		   
		   
void QuickSort(int a[], int l, int r ){
	
	int i;

	if(l >= r)
	       	return;
	else{
		i = partition(a,l,r);
		//printf("\nValore di ritorno di partition : %d\n",i);
		//getchar();
		QuickSort(a, l, i-1);
		QuickSort(a, i + 1,r);}

}
	
int swap(int a[], int l, int r){
	int temp;

	temp = a[l];
	a[l] = a[r];
	a[r] = temp;

	return r;
}


int partition(int a[] , int l , int r)
{

	int i = l , j = r , p = l;

	while(1){

		while(j > i && a[p] < a[j]) j--;
			swap(a,p,j);
			p = j;
			if(j == i) break;
		
		while(i < j && a[p] >= a[i]) i++;
			swap(a,p,i);
			p = i;
			if(j == i) break;
		}
	
	
return p;

}
