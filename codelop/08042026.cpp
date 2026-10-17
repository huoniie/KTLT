#include <stdio.h>
 void main(){
	int n;
	printf("Nhap so luong phan tu mang: ");
	scanf("%d",&n);
	int a[n];
    for( int i=0 ; i<n ; i++ ){
		printf("A[%d]=", i );
		scanf("%d",&a[i]);
	}

	for ( int i=0 ; i<n ; i++ ){
		printf(" %d",a[i]);
	}
	int tong( int a[] , int n ){
	if (n==1) return a[1];
	else 
		return tong(a,n-1)+a[n];
	}
	printf("tong=%d",tong(a,n));
}
	

