/*Cho t?p van b?n (tên t?p nh?p t? bàn phím) 
ch?a các h? s? c?a da th?c:P(x) = a_0 + a_1x + a_2x^2 +... + a_nx^n
Hãy xây d?ng các hàm d? th?c hi?n các vi?c sau dây:
Ð?c các h? s? c?a da th?c t? t?p.
Nh?p d1 và d2 t? bàn phím và tính: 
P(d_1)/P(d_2)
Tính h? s? c?a da th?c hi?u: 2025 + P'(x)*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

FILE* MoFileDoc (){
	FILE* f;
	char tenf[50];
	printf("\nNhap ten tep: ");
	scanf("%[^\n]s",&tenf);
	tenf[strcspn ( tenf , "\n" )]=0;
	
	f = fopen ( tenf , "r");
	
	if ( f == NULL ){
		printf ("\nLoi mo file! ");
		exit(1);
	}
	return f;
}

int* DocTep ( FILE* f , int n ){
	int* a = (int*) malloc ( n* sizeof ( int ));
	
	if ( a == NULL ){
		printf ("\nCap phat bo nho that bai!");
		exit(1);
	}
	for ( int i=0 ; i<n ; i++ ){
		fscanf ( f, "%d" ,&a[i]);
		printf("%d  ",a[i]);
	}
	printf("\nDa thanh cong doc du lieu trong file.");
	return a;
}
void tinhpd1d2 ( int* a , int n ){
	int d1,d2;
	printf ("\nNhap d1 va d2: ");
	scanf ("%d%d",&d1,&d2);
	int pd1 =a[0];
	int pd2 =a[0];
	for ( int i=1 ; i<n ; i++ ){
		pd1 += a[i]*pow(d1,i);
		pd2 += a[i]*pow(d2,i);
	}
	printf ( "%d %d",pd1,pd2);
	printf ("\nP(%d)/p(%d)= %.2f" ,d1,d2,(float)pd1/pd2);
}
void tinhp ( int* a , int n ){
	int x;
	printf ("\nNhap gia tri cua x: ");
	scanf ("%d",&x);
	printf ( "\nhe so moi cua da thuc : ");
	printf("\n%d",2025+a[1]);
	for ( int i=2; i<n ; i++ ){
		printf ( "\n%d  ",i*a[i]);
	}
	
}

int main (){
	FILE* f = MoFileDoc();
	int n;
	fscanf ( f,"%d",&n);
	int* a = DocTep(f,n);
	tinhpd1d2(a,n);
	tinhp(a,n);
	fclose(f);
	free (a);
	return 0;
	}
