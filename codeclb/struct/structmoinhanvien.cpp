#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	char ten[30];
	int NamSinh;
	float luong;
	float HeSoLuong;
	char ChucVu[30];
}NhanVien;

NhanVien* nhap ( int n ){
	NhanVien* N = ( NhanVien* ) malloc ( n * sizeof ( NhanVien ) ); 
	
	for ( int i=0 ; i<n ; i++ ){
	
	printf("\nNhap ten: ");
	fgets(N[i].ten,30,stdin);
	N[i].ten[strcspn(N[i].ten,"\n")]=0;
	
	printf("Nhap nam sinh: ");
	scanf("%d",&N[i].NamSinh);getchar();
	
	printf("Nhap luong: ");
	scanf("%f",&N[i].luong);getchar();
	
	printf("Nhap he so luong: ");
	scanf("%f",&N[i].HeSoLuong);
	getchar();
	
	printf("Nhap chuc vu: ");
	fgets(N[i].ChucVu,30,stdin);
	N[i].ChucVu[strcspn(N[i].ChucVu,"\n")]=0;
	}
	return N;
}
void in(NhanVien* N , int n ){
	for ( int i=0 ; i<n ; i++ ){
	printf("\nten: %s ",N[i].ten);
	printf("\nnam sinh: %d ",N[i].NamSinh);
	printf("\nluong: %.2f ",N[i].luong);
	printf("\nhe so luong: %.2f",N[i].HeSoLuong);
	printf("\nchuc vu: %s",N[i].ChucVu);
	}
	printf("\n");
}
void sapxep(NhanVien* N , int n ){
	for ( int i=0 ; i<n-1 ; i++ ){
		if (N[i].luong < N[i+1].luong ){
			NhanVien temp = N[i];
			N[i]=N[i+1];
			N[i+1]=temp;
		}
	}
	in(N,n);
}
int main(){
	int n;
	printf("\nNhap so luong nhan vien: ");
	scanf("%d",&n); getchar();
	NhanVien* N=nhap(n);
	in(N,n);
	sapxep(N,n);
}
