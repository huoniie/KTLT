#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	char mhs[50];
	char ten[50];
	char lop[10];
	float toan,ly,hoa;
	float diemtb;
}HocSinh;

HocSinh* nhap( int* n){
	FILE* f = fopen ( "hocsinh.txt","r");
	if ( f == NULL ){
		printf ("\nloi mo tep!");
		exit(1);
	}
	
	fscanf(f,"%d\n",n);
	HocSinh* hs = (HocSinh* ) malloc ( *n*sizeof(HocSinh));
	float max = -1;
	int vitri = 0;

	for ( int i=0 ; i<*n ; i++ ){
		fgets ( hs[i].mhs , sizeof  (hs[i].mhs) ,f);
		hs[i].mhs [strcspn(hs[i].mhs,"\n")]=0;
		
		fgets ( hs[i].ten , sizeof  (hs[i].ten) ,f);
		hs[i].ten [strcspn(hs[i].ten,"\n")]=0;
		
		fgets ( hs[i].lop , sizeof  (hs[i].lop) ,f);
		hs[i].lop [strcspn(hs[i].lop,"\n")]=0;
		
		fscanf(f,"%f%f%f\n",&hs[i].toan,&hs[i].ly,&hs[i].hoa);
		
		if ( max < hs[i].ly){
			max = hs[i].ly;
			vitri =i;
		}
		hs[i].diemtb += hs[i].toan+hs[i].ly+hs[i].hoa;
	printf( "%-5d\n%-10s\n%-30s\n%-10s\n%-10.2f\n%-10.2f\n%-10.2f\n",
			i , hs[i].mhs ,hs[i].ten,hs[i].lop,hs[i].toan,hs[i].ly,hs[i].hoa);
	}
	printf("\nDiem ly cao nhat %.2f ",max);
	printf( "%-5d\n%-10s\n%-30s\n%-10s\n%-10.2f\n%-10.2f\n%-10.2f\n",
			vitri , hs[vitri].mhs ,hs[vitri].ten,hs[vitri].lop,hs[vitri].toan,hs[vitri].ly,hs[vitri].hoa);

	 
	fclose(f);
	return hs;
}

void ghi ( HocSinh* hs , int n){
	char a[50];
	printf("\nNhap ten lop ban muon thong ke: ");
	fgets ( a , sizeof  (a) ,stdin);
	a [strcspn(a,"\n")]=0;
	FILE* A = fopen ( a,"w");
	if ( A == NULL ){
		printf ("\nloi mo tep!");
		exit(1);
	}
	
	printf("xxxv");
	for ( int i=0 ; i<n ; i++ ){
		if ( strcmp ( hs[i].lop,a)==0){
			fprintf(A, "%-5d\n%-10s\n%-30s\n%-10s\n%-10.2f\n%-10.2f\n%-10.2f\n",
			i , hs[i].mhs ,hs[i].ten,hs[i].lop,hs[i].toan,hs[i].ly,hs[i].hoa);
			}
		}
	fclose(A);
	
}

void sapxep (HocSinh* hs , int n){
	for ( int i=0 ; i<n ; i++ ){
		int key = i ;
		for ( int j=i+1 ; j<n ; j++ ){
			if ( hs[i].diemtb > hs[j].diemtb ){
				key = j;
			}
		}
		for ( int i=0 ; i<n ; i++ ){
			HocSinh temp =  hs[i];
			 hs[i] = hs[key];
			 hs[key]= temp ; 
		}
	}
	
	for ( int i=0 ; i<n ; i++ ){
			printf( "%-5d\n%-10s\n%-30s\n%-10s\n%-10.2f\n%-10.2f\n%-10.2f\n",
			i , hs[i].mhs ,hs[i].ten,hs[i].lop,hs[i].toan,hs[i].ly,hs[i].hoa);
	}
	for ( int i=0 ; i<3 ; i++ ){
			printf( "%-5d\n%-10s\n%-30s\n%-10s\n%-10.2f\n%-10.2f\n%-10.2f\n%-10.2f\n",
			i , hs[i].mhs ,hs[i].ten,hs[i].lop,hs[i].toan,hs[i].ly,hs[i].hoa,hs[i].diemtb);
	}
}


int main(){
	int n;
	HocSinh* hs = nhap (&n);
	ghi(hs,n);
	sapxep(hs,n);
	free(hs);
}


