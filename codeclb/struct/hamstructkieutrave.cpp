//ham struct kieu tra ve Cach1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char ten[30];
	int tuoi;
	int luong;
}SinhVien;
SinhVien* nhap( int n ) {
	SinhVien* sv = (SinhVien*) malloc ( n * sizeof ( SinhVien ) );
	for ( int i=0 ; i<n ; i++ ){
		printf("Sinh vien %d ", i+1 );
		printf("\nNhap ten: ");
		getchar();
		fgets(sv[i].ten,30,stdin);
		printf("Nhap tuoi: ");
		scanf("%d",&sv[i].tuoi);
		printf("Nhap luong: ");
		scanf("%d",&sv[i].luong);
	}
	return sv;
}
void in (SinhVien sv[],int n){
	for ( int i=0 ; i<n ; i++ ){
		printf("\nSinh vien %d ", i+1 );
		printf("\nten:%s ",sv[i].ten);
		printf("tuoi: %d",sv[i].tuoi);
		printf("\nluong:%d ",sv[i].luong);
	}
}
int main(){
	int n;
	printf("\nNhap so luong sinh vien: ");
	scanf("%d",&n);
	SinhVien sv[n];
	SinhVien* SV =nhap(n);
	in(SV,n);
}

