#include <stdio.h>
#include <stdlib.h>
int* nhap_mang( int n){
	int* c = (int*) malloc ( n * sizeof(int));
	for ( int i=0 ; i<n ; i++ ){
		printf("A[%d]=",i);
		scanf("%d", ( c+i ));
	}
	return c;
}
int* chen_phan_tu(int*c , int n ){
	int h,H;
	printf("\nNhap vi tri ban muon chen: ");
	scanf("%d",&h);
	printf("\nSo ban muon chen: ");
	scanf("%d",&H);
	int* D = (int*) malloc ( (n+1) * sizeof(int));
	for ( int i=n-1 ; i>h-i ; i-- ){
		*(D+i+1)=*(c+i);
	}
	for ( int i=0 ; i<h+1 ; i++ ){
		*(D+i)=*(c+i);
	}
	*(D+h)=H;
	return D;
}
void in_mang( int* a , int n ){
	for(int i=0 ; i<n ; i++ ){
	printf(" %d",*(a+i));
	}
}
int main(){
	int n,c;
	printf("\nNhap so luong phan tu cua mang: ");
	scanf("%d",&n);
	int* C = nhap_mang (n);
	in_mang(C,n);
	int* d = chen_phan_tu(C,n);
	in_mang(d,n+1);
	free(C);
	free(d);
}

