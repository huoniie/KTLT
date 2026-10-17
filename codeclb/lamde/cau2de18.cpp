#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	int mnv;
	char ten[50];
	float luong;
	char ban[10];
}NhanVien;


void In ( NhanVien nv[] , int i){
	printf("\n%-5d %-10d %-30s %-15.3f %-5s",
	i+1 ,nv[i].mnv,nv[i].ten,nv[i].luong,nv[i].ban);
}

void Ghi (FILE* F, NhanVien nv[] , int i){
	fprintf(F,"\n%-5d %-10d %-30s %-15.3f %-5s",
	i+1 ,nv[i].mnv,nv[i].ten,nv[i].luong,nv[i].ban);
}


NhanVien* DocTep ( int*n){
	FILE* f = fopen ("cau2de18.txt","r");
	if ( f== NULL){
		printf("\nLoi mo tep!");
		exit(1);
	}
	
	fscanf(f,"%d",n);
	
	NhanVien* nv = (NhanVien*) malloc ( (*n) *sizeof(NhanVien));
	if ( nv== NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	printf("\nDANH SACH NHAN VIEN\n");
	for ( int i=0 ; i<*n ; i++ ){
		fscanf (f,"%d\n",&nv[i].mnv);
		fscanf (f," %[^\n]s",&nv[i].ten);
		nv[i].ten[strcspn(nv[i].ten,"\n")]=0;
		
		fscanf(f,"%f\n ",&nv[i].luong);
		fscanf (f," %[^\n]s",&nv[i].ban);
		nv[i].ban[strcspn(nv[i].ban,"\n")]=0;
		In(nv,i);
	}
	
	fclose(f);
	return nv;
}


float TinhLuongTrungBinh (FILE* F, NhanVien nv[], int n,char a[] ){
	float luongTB = 0;
	int dem =0;
	for ( int i=0 ; i<n ; i++ ){
		if ( strcmp (nv[i].ban,a)==0){
			luongTB+=nv[i].luong;
			dem++;
		}
	}
	if (dem!=0){
	printf("\nLuong trung binh cua ban %s la%.3f",a,luongTB/dem);
	fprintf(F,"\nLuong trung binh cua ban %s la%.3f",a,luongTB);
	}
	else {
	printf("\nKhong co nhan vien ban %s nen khong co luong trung binh");
	fprintf(F,"\nKhong co nhan vien ban %s nen khong co luong trung binh");
	}
	return luongTB/dem;
}


void LuongTBCuaCacBan (FILE* F ,NhanVien nv[], int n ){
	float luongTBA= TinhLuongTrungBinh(F,nv,n,"A");
	float luongTBB=TinhLuongTrungBinh(F,nv,n,"B");
	float luongTBC=TinhLuongTrungBinh(F,nv,n,"C");
	float min = luongTBA;          
	char* tenBanMin = "A";        
	
	if (luongTBB < min) {
	    min = luongTBB;            
	    tenBanMin = "B";           
	}
	
	if (luongTBC < min) {
	    min = luongTBC;
	    tenBanMin = "C";
	}

    printf("\nLuong cua nhan vien ban %s co luong min: %.2f\n", tenBanMin, min);
}


void SapXep (FILE* F ,NhanVien nv[], int n){
	for ( int i=0 ; i<n-1 ; i++ ){
		int key = i ;
		for ( int j=i+1; j<n ; j++ ){
			if ( nv[key].luong < nv[j].luong){
				key = j;
			}
		}
		if ( key!=i){
			NhanVien temp = nv[i];
			nv[i] =nv[key];
			nv[key]=temp;
		}
	}
	
	printf("\nDanh sach nhan vien (sap xep giam dan theo luong)");
	fprintf(F,"\nDanh sach nhan vien (sap xep giam dan theo luong)");
	for ( int i=0 ; i<n ; i++ ){
		In (nv,i);
		Ghi (F,nv,i);
	}
}

int main(){
	int n ;
	NhanVien* nv = DocTep (&n);
	FILE* F = fopen ("ketquacau2de18.txt","w");
	if ( F== NULL){
		printf("\nLoi mo tep!");
		exit(1);
	}
	fprintf(F,"\nDANH SACH NHAN VIEN\n");
	for ( int i=0 ; i<n ; i++ ){
		Ghi (F,nv,i);
	}
	LuongTBCuaCacBan(F,nv,n);
	SapXep(F,nv,n);
	fclose(F);
	free(nv);
}
