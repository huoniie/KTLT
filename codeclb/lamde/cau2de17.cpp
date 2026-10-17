#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char ten[50];
	int ns,nkn;
	int tuoiDoan;
}DoanVien;


void In ( DoanVien dv[] , int i ){
	printf("\n%-5d %-30s %-15d %-15d " ,i+1
	,dv[i].ten,dv[i].ns,dv[i].nkn);
}
void Ghi ( FILE* F,DoanVien dv[] , int i ){
	fprintf(F,"\n%-5d %-30s %-15d %-15d " ,i+1
	,dv[i].ten,dv[i].ns,dv[i].nkn);
}

DoanVien* DocTep ( int* n){
	FILE* f = fopen ( "cau2de17.txt","r");
	if ( f==NULL){
		printf("\nLoi mo file!");
		exit(1);
	}
	
	fscanf(f,"%d\n",n);
	
	DoanVien* dv = (DoanVien*) malloc ( (*n) * sizeof (DoanVien));
	
	if ( dv == NULL ){
		printf("\nLoi cap phat bo nho");
		exit(1);
	}
	printf("\nDANH SACH DOAN VIEN\n");
	for ( int i=0 ; i<*n ; i++ ){
		fscanf(f,"%[^\n]s" ,&dv[i].ten);
		dv[i].ten[strcspn(dv[i].ten,"\n")]=0;
		
		fscanf(f,"%d%d\n",&dv[i].ns,&dv[i].nkn);
		dv[i].tuoiDoan = 2015 - dv[i].nkn;
		In (dv,i);
	}
	fclose (f);
	return dv;
}

void SapXep (FILE* F, DoanVien dv[] ,int n){
	
	for ( int i=0 ; i<n-1 ; i++ ){
		int key = i ; 
		for ( int j=i+1 ; j<n ; j++ ){
			if ( dv[key].nkn > dv[j].nkn ){
				key = j;
			}
		}
		if ( key != i ){
			DoanVien temp = dv[i];
			dv[i] = dv[key];
			dv[key] = temp;
		}
	}
	printf("\nDANH SACH DOAN VIEN(theo nam ket nap)\n");
	fprintf(F,"\nDANH SACH DOAN VIEN(theo nam ket nap)\n");
	for ( int i=0 ; i<n ; i++ ){
		In (dv,i);
		Ghi(F,dv,i);
	}
}

void ThongKe (FILE* F , DoanVien dv[] ,int n){
	int dem = 0;
	for ( int i=0 ; i<n ; i++ ){
		if ( dv[i].nkn > 2007&& dv[i].nkn < 2015 ){
			dem++;
		}
	}
	if (dem==0){
		fprintf(F,"\nKhong co doan vien nao co tuoi doan thoa man ( 2007 < tuoidoan <2015)");
		printf("\nKhong co doan vien nao co tuoi doan thoa man ( 2007 < tuoidoan <2015)");
	}
	else {
		fprintf(F,"\nCo %d doan vien co tuoi doan trong ( 2007 < tuoidoan <2015)",dem);
		printf("\nCo %d doan vien co tuoi doan trong ( 2007 < tuoidoan <2015)",dem);
	}
}

int main(){
	int n;
	DoanVien* dv = DocTep (&n);
	
	FILE* F = fopen ("ketquacau2de17.txt","w");
	if ( F==NULL){
		printf("\nLoi mo file!");
		exit(1);
	}
	
	fprintf(F,"\nANH SACH DOAN VIEN\n");
	for ( int i =0 ; i<n ; i++ ){
		Ghi(F,dv,i);
	}
	ThongKe(F,dv,n);
	
	SapXep(F,dv,n);
	
	fclose(F);
	free(dv);
}

