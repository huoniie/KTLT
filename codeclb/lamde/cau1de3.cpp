#include <stdio.h>
#include <math.h>
#include <stdlib.h>


FILE* MoFileDoc(){
	FILE* f ;
	f = fopen ("cau1de3.txt","r");
	
	if ( f == NULL ){
		printf("\nLoi mo file!");
		exit(1);
	}
	return f;
}

float* DocFile ( FILE* f , int n ){
	float* a = (float* ) malloc ( n*sizeof (float));
	
	if ( a == NULL ){
		printf ("\nCap phat bo nho that bai");
		exit(1);
	}
	for ( int i=0 ; i<n+1 ; i++ ){
		fscanf (f , "%f" , &a[i]);
		printf("%.2f  ",a[i]);
	}
	printf("\nDa doc thanh cong du lieu.\n");
	return a;
}
void TinhTaiX(float* a , int n ){
	float x;
	printf("Nhap gia tri x: ");
	scanf("%f",&x);
	float p=a[0];
	for ( int i=1 ; i<n ; i++ ){
		p+=a[i]*pow(x,i);
	}
	printf("\nP(%.2f)=%.2f",x,p);
}

void TinhDaoHam ( float* a , int n ){
	printf("\nDa thuc bac %d sau dao ham cap 1: ",n);
	
	float max = abs (a[0]);
	for ( int i=0 ; i< n+1 ; i++ ){
		printf ("\n%.2f",a[i]);
		if ( abs(a[i]) > max ){
			max = abs(a[i]);
		}
	}
	printf("\nHe so co tri tuyet doi lon nhat: %.2f",max);
	
}


int main (){
	FILE* f =MoFileDoc();
	int n;
	//check cai n kia nua.
	fscanf(f,"%d",&n);
	float* a = DocFile (f,n);
	TinhTaiX(a,n);
	TinhDaoHam (a,n);
	fclose (f);
	free(a);
}


