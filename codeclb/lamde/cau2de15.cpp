#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	int MS;
	char tenSach[30];
	char tacGia[40];
	int nam;
	float gia;
}Sach;


void In ( Sach b[], int i){
	printf("\n%-5d %-15d %-30s %-30s %-10d %-15.2f ",
	i,b[i].MS,b[i].tenSach,b[i].tacGia,b[i].nam,b[i].gia);
}
void Ghi ( FILE* F,Sach b[], int i){
	fprintf(F,"\n%-5d %-15d %-30s %-30s %-10d %-15.2f ",
	i,b[i].MS,b[i].tenSach,b[i].tacGia,b[i].nam,b[i].gia);
}

Sach* DocTep (FILE* F, int* n){
	FILE* f = fopen ("cau2de15.txt","r");
	if ( f== NULL ){
		printf("\nLoi mo file ");
		exit(1);
	}
	
	fscanf(f,"%d",n);
	
	Sach* b = ( Sach* ) malloc ((*n)*sizeof(Sach));
	if( b == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit (1);
	}
	fprintf(F,"\nDANH SACH CAC CUON SACH\n");
	for ( int i=0 ; i<*n ; i++ ){
		fscanf(f,"%d\n",&b[i].MS);
		
		fgets(b[i].tenSach, sizeof(b[i].tenSach),f);
		b[i].tenSach[strcspn(b[i].tenSach,"\n")]=0;
		
		fgets(b[i].tacGia, sizeof(b[i].tacGia),f);
		b[i].tacGia[strcspn(b[i].tacGia,"\n")]=0;
		
		fscanf(f,"%d",&b[i].nam);
		fscanf(f,"%f",&b[i].gia);
		Ghi(F,b,i);
	}
	fclose(f);
	printf("\nDa doc thanh cong tep van ban");
	return b;
}

void SapXep ( FILE* F,Sach b[], int n ){
	fprintf(F,"\nDANH SACH THEO THU TU TANG DAN\n");
	for ( int i=0 ; i<n-1 ; i++){
		int key = i;
		for (int j=i+1 ; j<n ; j++){
			if ( b[key].gia > b[j].gia){
				key = j;
			}
		}
		if ( key!=i){
			Sach temp = b[i];
			b[i]=b[key];
			b[key] = temp;
		}
	}
	for ( int i=0 ; i<n ; i++){
		Ghi(F,b,i);
	}
	printf("\nDa sap xep thanh cong");
}
void TimKiem ( FILE* F,Sach b[], int n){
	char tenCanTim[40];
	int namCanTim ;
	printf("\nNhap sach ban can tim: ");
	fgets(tenCanTim,sizeof(tenCanTim),stdin);
	tenCanTim[strcspn(tenCanTim,"\n")]=0;
	
	printf("\nNhap nam xuat ban:");
	scanf("%d",&namCanTim);
	
	bool check = false;
	
	for ( int i=0 ; i<n ; i++ ){
		if ( strcmp ( tenCanTim,b[i].tenSach)==0&&namCanTim == b[i].nam){
			check = true;
			Ghi(F,b,i);
			In(b,i);
		}
	}
	if ( check == false){
		printf("\nKhong co cuon sach nao phu hop voi thong tin ban nhap!");
	}
}

int main(){
	int n; 
	FILE* F = fopen ("ketquacau2de15.txt","w");
	if ( F== NULL ){
		printf("\nLoi mo file ");
		exit(1);
	}
	Sach* b = DocTep (F,&n);
	SapXep(F,b,n);
	TimKiem(F,b,n);
	fclose(F);
	free(b);
}
