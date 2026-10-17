#include <stdio.h>
#include <string.h>
struct SinhVien{
	char ten[30];
	int tuoi;
	float luong;
};
int main(){
	int n;
	printf("\nNhap so luong sinh vien: ");
	scanf("%d",&n);
	SinhVien sv[n];
	for ( int i=0 ; i<n ; i++ ){
		printf("\nSinh vien %d",i+1);
		printf("\nNhap ten: ");
		fflush(stdin);
		fgets(sv[i].ten,30,stdin);
		printf("\nNhap tuoi: ");
		scanf("%d",&sv[i].tuoi);
		printf("\nNhap luong: ");
		scanf("%f",&sv[i].luong);
	}
	for ( int i=0 ; i<n ; i++ ){
		printf("\nSinh vien %d",i+1);
		printf("\nten: %s",sv[i].ten);
		printf("\ntuoi: %d",sv[i].tuoi);
		printf("\nluong: %f",sv[i].luong);
	}
}
