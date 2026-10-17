#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* DocTep (FILE* F , int* n) {
	FILE* f = fopen ( "cau1de19.txt","r");
	if ( f == NULL ){
		printf("\nLoi mo file!");
		exit(1);
	}
	
	fscanf(f,"%d\n",n);
	
	char* ma = ( char* ) malloc ((*n) * sizeof ( char));
	if ( ma == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
		fscanf (f ,"%s" ,ma);
		printf("\n%s",ma);
		fprintf(F,"\n%s",ma);
		fclose(f);
	return ma;
}

void check (FILE* F, int dem , char phan[]){
	if ( dem == 0 ){
		fprintf(F,"\nKhong co chu %s ",phan);
	}
	else {
		fprintf(F,"\nCo %d chu %s" , dem , phan);
	}
}

void PhanTachChuVaSo (FILE* F, char ma[] , int n){
	int phanChuHoa = 0 ;
	int phanChuThuong = 0 ;
	int phanSo = 0;
	for ( int i=0 ; i<n ; i++ ){
		if (  ma[i]>= 'A' && ma[i] <= 'Z' ){
			phanChuHoa ++;
		}
		else if ( ma[i]>='a' && ma[i] <= 'z'){
			phanChuThuong++;
		}
		else if (  ma[i] >='0' && ma[i] <= '9'){
			phanSo++;
		}
	}

	check (F,phanChuHoa,"CHU HOA" );
	check (F,phanChuThuong,"CHU THUONG" );
	check (F,phanSo ,"CHU SO" );

}

int main(){
	int n;
	FILE* F = fopen ( "ketquacau1de19.txt","w");
	if ( F == NULL ){
		printf("\nLoi mo file!");
		exit(1);
	}
	char* ma = DocTep (F,&n);
	PhanTachChuVaSo (F,ma,n);
	fclose(F);
	free(ma);
}
