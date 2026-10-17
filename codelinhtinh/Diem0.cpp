//Diem 0
#include <stdio.h>
int main(){
	int n;
	printf("Nhap so luong sinh vien: ");
	scanf("%d",&n);
	int sv[n];
	printf("\nNhap diem cho sinh vien trong [0,10].");
	for ( int i=0 ; i<n ; i++ ){
		printf("\nSV[%d]: ", i+1 );
		scanf("%d",&sv[i]);
	}
	printf("\nSo diem ban dau\n");
	for ( int i=0 ; i<n ; i++ ){
		printf(" %d",sv[i]);
	}
	printf("\n");
	printf("\nSo diem khi loai bo 0\n");
	for ( int i=0 ; i<n ; i++ ){
		if( sv[i] != 0 ){
		printf(" %d",sv[i]);
	}
	}
	
}
 
