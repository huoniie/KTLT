#include <stdio.h>
#include <stdlib.h>
int* nhap( int* a ,int n){
	for ( int i = 0 ; i < n ; i++ ){
	printf("a[%d]=",i);
	scanf(" %d",(a+i));
}
	int* p = (int*) malloc ( n * sizeof(int));
	if ( p == NULL ){
		printf("Het cho roi\n");
		return NULL;
	}
	for ( int i=0 ; i < n ; i++ ){
		* ( p + i ) = * ( a + i );
	}
	return p;
}
void in_mang(int* a , int n ){
	for ( int i = 0 ; i < n ; i++ ){
		printf("%d",*(a+i));
	}
	printf("\n");
}
int main() {
	int n;
	printf("\nNhap so luong phan tu cua mang: ");
	scanf("%d",&n);
	int A[n];
	int* p = nhap(A,n);
	if ( p != NULL){
		printf("\nMang thuong:");
		in_mang(A,n);
		printf("\nMang malloc:");
		in_mang(p,n);
		
	free(p);
}
return 0;
	
}
