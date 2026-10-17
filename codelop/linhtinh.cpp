#include <stdio.h>
#include <stdlib.h>

int* nhap( int n ){
	int* a = ( int*) malloc ( n* sizeof ( int ));
	if ( a==NULL){
		 printf("\nLoi cap phat bo nho!");
		 exit(1);
	}
	for ( int i=0 ; i<n ; i++){
		printf ( "a[%d]= ",i+1);
		scanf("%d",&a[i]);
	}
	return a;
}
 void TinhTong( int* a , int n){
 	int tong =0;
 	for ( int i=0 ; i<n ; i++ ){
 		tong+=a[i];
	 }
	 printf("\nTong cua day la %d" ,tong );
}
int main (){
	int n;
	printf("\nNhap so luong phan tu cua day: ");
	scanf("%d",&n);
	
	int* a = nhap(n);
	TinhTong(a,n);
	free(a);
}
