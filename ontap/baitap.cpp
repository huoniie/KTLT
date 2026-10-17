#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>;
typedef struct {
	int msv;
	char name[30];
	float gpa;
}SinhVien;


void In ( SinhVien* sv , int a ){
	printf("%-5d %-10d %-30s %-10.2f \n", a, sv[a].msv,sv[a].name,sv[a].gpa);
}

SinhVien* nhap ( int *n ){
	printf("Nhap so luong sinh vien: ");
	scanf("%d",n);
	
	SinhVien* sv = ( SinhVien* ) malloc ( (*n)* sizeof ( SinhVien));
	if ( sv == NULL ){
		printf("\nCap phat that bai");
		exit(1);
		}
	
	for ( int i=0 ; i<*n ; i++ ){
		printf ("Sinh vien %d ",i+1);
		printf ("\nNhap MSV: ");
		scanf ("%d",&sv[i].msv );
		
		getchar();
		printf("Nhap ten: ");
		fgets ( sv[i].name ,sizeof ( sv[i].name ), stdin);
		sv[i].name[strcspn ( sv[i].name , "\n" )]=0;
		
		printf("Nhap gpa: ");
		scanf("%f",&sv[i].gpa);
	}
	printf("\nDanh sach sinh vien duoc hoc bong:");
	bool ktra = false;
	for ( int i=0 ; i<*n ; i++ ){
		if ( sv[i].gpa >= 9){
		In(sv,i);
		ktra = true;
	 }
	}
	if (ktra = false ){
		printf("\nKhong co sinh vien nao duoc hoc bong");
	}
	return sv;
}


typedef struct {
	int msvv;
	char namee[30];
	float gpaa;
	float drl;
}SinhVienBoSung;

SinhVienBoSung* ThemThuocTinh (SinhVien* sv , int n){
	
	SinhVienBoSung* SV = (SinhVienBoSung* ) malloc (n*sizeof(SinhVienBoSung));
	
	for  ( int i=0 ; i<n ; i++ ){
		SV[i].msvv=sv[i].msv;
		strcpy(SV[i].namee, sv[i].name);
		SV[i].gpaa =sv[i].gpa;
		
		printf("\nSinh vien%d",i+1);
		printf ("\nNhap diem ren luyen: ");
		scanf("%f",&SV[i].drl ); 
	}
	printf("\nDanh sach sinh vien duoc hoc bong:");
	bool check = false;
	for ( int i=0 ; i<n ; i++){
		if ( SV[i].drl >= 90 && SV[i].gpaa >= 9){
			printf("\n%-5d %-10d %-30s %-10.2f %-10.2f\n", i+1, SV[i].msvv,SV[i].namee,SV[i].gpaa,SV[i].drl );
			check = true;
		}
	}
	if (check = false ){
		printf("\nKhong co sinh vien nao duoc hoc bong");
	}
	return SV;
	
}

int main(){
	int n;
	SinhVien* sv = nhap(&n);
	SinhVienBoSung* SV =ThemThuocTinh(sv,n);
	free(sv);
	free(SV);
}
