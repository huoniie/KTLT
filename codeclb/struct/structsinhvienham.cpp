#include <stdio.h>
#include <string.h>
struct SinhVien{
	char ten[30];
	int tuoi;
	int luong;
};
void nhap( SinhVien sv[] ,int n){
	for ( int i=0 ; i<n ; i++ ){
	printf("Sinh vien %d",i+1);
		printf("\nNhap ten: ");
		fflush(stdin);
		fgets(sv[i].ten,30,stdin);
		printf("Nhap tuoi: ");
		scanf("%d",&sv[i].tuoi);
		printf("Nhap luong: ");
		scanf("%d",&sv[i].luong);
	}
	
}
void in( SinhVien sv[] , int n){
	for ( int i=0 ; i<n ; i++ ){
		printf("\nSinh vien %d",i+1);
		printf("\nten: %s",sv[i].ten);
		printf("tuoi: %d",sv[i].tuoi);
		printf("\nluong: %d",sv[i].luong);
	}
}
int main(){
	int n;
	printf("\nNhap so luong sinh vien: ");
	scanf("%d",&n);
	SinhVien sv[n];
	nhap(sv,n);
	in(sv,n);
}
