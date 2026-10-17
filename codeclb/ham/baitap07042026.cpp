#include <stdio.h>
#include <stdlib.h>
int main(){
int n;
printf("\nNhap so luong phan tu cua mang: ");
scanf("%d",&n);
int* p = (int*) malloc(n* sizeof(int));
	for( int i=0 ; i<n ; i++ ){
		printf("A[%d]=", i );
		scanf("%d",( p+i ));
	}

	for ( int i=0 ; i<n ; i++ ){
		printf(" %d",*( p+i ));
	}
	
	int h,H;
	printf("\nNhap vi tri muon chen: ");
	scanf("%d",&h);
	printf("\nGia tri muon chen: ");
	scanf("%d",&H);
int*  q= (int*) malloc((n+1)* sizeof(int));
	for ( int i=n-1 ; i>h-1 ; i-- ){
		q[i+1]=p[i];
	}
	for ( int i=0 ; i<h+1 ; i++ ){
		q[i]=p[i];
	}
	q[h]=H;
for ( int i=0 ; i<n+1 ; i++ ){
		printf(" %d",*( q+i ));
	}
	

}
