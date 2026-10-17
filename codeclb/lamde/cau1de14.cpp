/*Nh?p t? file ma tr?n nxn ph?n t? v?i dòng d?u là n 
và dòng sau là các ph?n t? trong ma tr?n. 
Vi?t chuong trình th?c hi?n các yêu c?u sau
S?p x?p các hàng trong ma tr?n t? l?n t?i bé
In ra file các ph?n t? trong du?ng chéo chính và du?ng chéo ph?
V? trídu?c g?i là "cùng t?n" N?u hàng + c?t là ch?n và giá tr?
 t?i dó l?. In k?t qu? dó*/
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int** DocTep ( int* n ){
	FILE* f = fopen ("cau1de14.txt","r");
	if ( f == NULL ){
		printf("\nLoi mo file!");
		exit(1);
	}
	
	fscanf(f,"%d",n);
	
	int** mt = (int**) malloc ((*n)*sizeof(int*));
	if ( mt == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	for ( int i=0 ; i<*n ; i++ ){
		mt[i]=(int*) malloc ((*n)*sizeof (int));
		for ( int j=0 ; j<*n ; j++ ){
			fscanf(f,"%d",&mt[i][j]);
			printf("%d  ",mt[i][j]);
		}
		printf("\n");
	}
	printf("\nDa doc thanh cong du kieu trong tep.\n");
	fclose(f);
	return mt;
}

void SapXep ( int** mt , int n){
	for ( int i=0 ; i<n ; i++ ){
		for ( int j=0 ; j<n-1 ; j++	){
			int key = j;
			for ( int k = j+1 ; k<n ; k++ ){
				if ( mt[i][key] < mt[i][k]){
					key = k;
				}
			}
			if ( key!=j){
				int temp = mt[i][j];
				mt[i][j] = mt[i][key];
				mt[i][key] = temp;
			}
		}
	}
	printf("\nMa tran sau khi da sap xep cac hang trong ma tran tu lon toi be.\n");
	for ( int i=0 ; i<n ; i++ ){
		for ( int j=0 ; j<n ; j++){
			printf("%d  ",mt[i][j]);
		}
		printf("\n");
	}
}

void InPhanTuDuongCheoChinhPhu(FILE* F, int** mt , int n){
	fprintf(F,"\nCac phan tu trong duong cheo chinh");
	for ( int i=0 ; i<n ; i++){
		fprintf(F,"%d  ",mt[i][i]);
	}
	fprintf(F,"\nCac phan tu trong duong cheo phu");
	for ( int i=0 ; i<n ;i++){
		fprintf(F,"%d  ",mt[i][n-1-i]);
	}
}

void TimCungTan (FILE* F,int** mt , int n ){
	bool cungTan = false;
	fprintf(F,"\nCac diem thoa man dieu kien cung tan.");
	for ( int i=0 ; i<n ; i++ ){
		for ( int j=0 ; j<n ; j++){
			if ( (i + j) % 2 == 0 && mt[i][j] % 2 != 0 ){
				cungTan = true;
				fprintf(F,"\nP(%d,%d)=%d",i,j,mt[i][j]);
			}
		}
	}
	if (cungTan == false){
		fprintf(F,"\nKhong co dien nao thoa man dieu kien cung tan!");
	}
}

int main (){
	int n ;
	int** mt = DocTep(&n);

	FILE* F = fopen ("ketquacau1de14.txt","w");
	if ( F == NULL ){
		printf("\nLoi mo file");
		exit(1);
	} 
	
	InPhanTuDuongCheoChinhPhu(F,mt,n);
	TimCungTan(F,mt,n);
	
	fclose(F);
	SapXep(mt,n);
	
	for ( int i=0 ; i<n ; i++){
		free (mt[i]);
	}
	free(mt);
}
