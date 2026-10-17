#include <stdio.h>
#include <stdlib.h>

int* DocTep1 ( FILE* f , int m){
	int* a = (int*) malloc ( m * sizeof (int));
	
	for ( int i=0 ; i<m ; i++ ){
		fscanf(f,"%d", &a[i]);
		printf("%d  ",a[i]);
	}
	printf("\n");
	return a;
}
int* DocTep2 ( FILE* f , int n){
	int* b = (int*) malloc ( n * sizeof (int));

	for ( int i=0 ; i<n ; i++ ){
		fscanf(f,"%d",&b[i]);
		printf("%d  ",b[i]);
	}
	printf("\n");
	return b;
}
void TinhMaxMin ( int* a, int* b , int m , int n ){
	int maxa=a[0];
	for ( int i=0 ; i<m ; i++ ){
		if ( maxa<a[i]){
			maxa=a[i];
		}
	}
	printf("\nMAX day a %d ",maxa);
	int minb=b[0];
	for ( int i=0 ; i<n ; i++ ){
		if ( minb<b[i]){
			minb=b[i];
		}
	}
	printf("\nMin day b %d ",minb);
}

void SapXep ( int* a, int* b , int m , int n ){
	for ( int i=0 ; i<m ; i++ ){
		for ( int j=i+1 ; j<m ; j++ )
		if ( a[i] > a[j] ){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	printf("\nDay a:");
	for ( int i=0 ; i<m ; i++ ){
		printf("%d  ",a[i]);
	}
	for ( int i=0 ; i<n ; i++ ){
		for ( int j=i+1 ; j<n ; j++ )
		if ( b[i] > b[j] ){
			int temp = b[i];
			b[i] = b[j];
			b[j] = temp;
		}
	}
	printf("\nDay b:");
	for ( int i=0 ; i<n ; i++ ){
		printf("%d  ",b[i]);
	}
	
}
int main(){
	FILE* f ;
	f = fopen ("input1.txt","r");
	if ( f == NULL ){
		printf("\nLoi tep!");
		return 1;
	}
	int m,n;
	fscanf(f,"%d%d",&m,&n);
	printf("%d %d\n",m,n);
	int*a = DocTep1(f,m);
	int* b = DocTep2(f,n);
	TinhMaxMin (a,b,m,n);
	SapXep(a,b,m,n);
	fclose(f);
	free(a);
	free(b);
	
}
