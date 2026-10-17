#include <stdio.h>
#include <stdlib.h>

void DocTep ( int* a , int* b ,int* m ,int* n){
	FILE* f = fopen ( "cau1de17.txt","r");
	if ( f== NULL ){
		printf("\nLoi mo file ");
		exit (1);
	}
	
	fscanf(f,"%d%d",m,n);
	printf("\nday a: ");
	for ( int i=0 ; i<*n ; i++ ){
		fscanf(f,"%d",&a[i]);
		printf("%d  ",a[i]);
	}
	
	printf("\nday b: ");
	for ( int i=0 ; i<*m ; i++ ){
		fscanf(f,"%d",&b[i]);
		printf("%d  ",b[i]);
	}
	
	printf("\nDa thanh cong doc du lieu tu tep");
	fclose(f);
}


void timMax ( int a[] , int b[] , int m ,int n){
	int maxA =b[0];
	for ( int i=0 ; i<m ; i++ ){
		if ( a[i]>maxA){
			maxA=a[i];
		}
	}
	printf("\nMax cua day a: %d",maxA);
	int minB =b[0];
	for ( int i=0 ; i<n ; i++ ){
		if ( b[i]<minB){
			minB=b[i];
		}
	}
	printf("\nMin cua day b: %d",minB);
}
void SapXep ( int a[] , int b[] , int m ,int n){
	printf("\nDay a (tang dan): ");
	for ( int i=0 ; i<m-1 ; i++ ){
		int key=i;
		for ( int j=i+1 ; j<m ;  j++ ){
			if ( a[key] > a[j]){
				key=j;
			}
		}
		if ( key!=i){
			int temp = a[i];
			a[i]=a[key];
			a[key]=temp;
		}
	}
	for (int i=0 ; i<m ; i++ ){
		printf("%d  ",a[i]);
	}
	
	printf("\nDay b (tang dan): ");
	for ( int i=0 ; i<n-1 ; i++ ){
		int key=i;
		for ( int j=i+1 ; j<n ;  j++ ){
			if ( b[key] > b[j]){
				key=j;
			}
		}
		if ( key!=i){
			int temp = b[i];
			b[i]=b[key];
			b[key]=temp;
		}
	}
	for (int i=0 ; i<m ; i++ ){
		printf("%d  ",b[i]);
	}
	
	
}
int main(){
	int m,n;
	int* a = (int*) malloc (100*sizeof(int));
	if ( a == NULL ){
		printf("\nLoi cap phat bo nho");
		exit(1);
	}
	int* b = (int*) malloc (100*sizeof(int));
	if ( b == NULL ){
		printf("\nLoi cap phat bo nho");
		exit(1);
	}
	
	DocTep(a,b,&m,&n);
	timMax(a,b,m,n);
	SapXep(a,b,m,n);
	free(a);
	free(b);
	
}


