#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	printf("Nhap so luong phan tu: ");
	scanf("%d",&n);
	int* a = (int*) malloc(n* sizeof(int));
	for ( int i=0 ; i<n ; i++ ){
		printf("A[%d]=",i);
		scanf("%d",( a+i ));
	}
	for ( int i=0 ; i<n ; i++ ){
		printf(" %d",*(a+i));
	}
	printf("\n");
	for ( int i=0; i<n/2 ; i++ ){
		int temp=a[i];
		a[i]=a[n-i-1];      
        a[n-1-i]=temp;
			
		}
		for ( int i=0 ; i<n ; i++ ){
		printf(" %d",*(a+i));
		
	}
}

