//cau 1 cho t?p van b?n (tên t?p nh?p t? bàn phím) 
//ch?a các ph?n t? c?a m?t dãy s? nguyên. H
//ãy xây d?ng các hàm và vi?t chuong trình d? th?c hi?n:
//Ð?c d? li?u t? t?p.
//Tính giá tr? trung bình c?a dãy s?.
//Tìm ph?n t? có giá tr? l?n nh?t.

#include <stdio.h>
#include <stdlib.h>

FILE* MoFileDoc (){
	char tenf[50];
	printf("\nNhap ten file: ");
	scanf(" %[^\n]s" ,&tenf);
	FILE* f = fopen ( tenf , "r");
	
	if ( f == NULL ){
		printf("\nLoi mo tep!");
		exit(1);
	}
	return f;
}


int* DocFile ( FILE* f , int n ){
	int* a = (int*) malloc ( n* sizeof ( int ));
	
	if ( a == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	for ( int i=0 ; i<n ; i++ ){
		fscanf ( f, "%d" , &a[i]);
		printf ("%d  ",a[i]);
	}
	printf("\nDoc file thanh cong.\n");
	return a;
}
void TinhTb ( int* a , int n ){
	int tong = 0;
	for ( int i=0 ; i<n ; i++ ){
		tong+=a[i];
	}
	printf("\nTrung binh day a la: %.2f",(float)tong/n);
}

void TimMax ( int* a , int n ){
	int max =a[0];
	for ( int i=0 ; i<n ; i++ ){
		if ( max < a[i]) {
			max = a[i];
		}
	}
	
	printf("\nGia tri lon nhat cua day a la: %d" , max);
}

int main(){
	FILE*f = MoFileDoc();
	
	int n ;
	fscanf(f,"%d",&n);
	int*a = DocFile (f,n);
	TinhTb (a,n);
	TimMax (a,n);
	fclose(f);
	free(a);
}

