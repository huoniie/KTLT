#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
	int tu;
	int mau;
}PhanSo;

int UCLN ( int a , int b){
	a = abs(a);
	b = abs(b);
	while ( a * b != 0 ){
		if ( a > b ){
			a = a % b;
		}
		else {
			b = b % a;
		}
	}
	return a + b ;
}

void RutGon ( PhanSo* ps ){
	if ( ps->mau == 0){
		printf("\nPhan so khong hop le! ");
		exit(1);
	}
	
	int ucln = UCLN ( ps->tu , ps->mau );
	ps->tu = ps->tu/ucln;
	ps->mau = ps->mau/ucln;
	
	if ( ps->mau < 0 ){
		ps->tu = -ps->tu;
		ps->mau = -ps->mau;
	}
}

void Nhap1PS ( PhanSo* ps){
	printf("\nNhap tu so: ");
	scanf ("%d",&ps->tu);
	
	do {
		printf("\nNhap mau so ( khac 0 ): ");
		scanf ("%d",&ps->mau);	
	}
	while ( ps->mau == 0);
}

void In1PS ( PhanSo* ps ){
	if ( ps->tu == 0 ){
		printf("0");
	}
	else if ( ps->mau == 1 ){
		printf ("%d",ps->tu);
	}
	else{
		printf("%d/%d",ps->tu,ps->mau );
	}
}

PhanSo Cong2PS ( PhanSo a , PhanSo b ){

	PhanSo tong;
	tong.tu = a.tu*b.mau + b.tu*a.mau;
	tong.mau = a.mau*b.mau;
	RutGon(&tong);
	return tong;
}

int main(){
	int n;
	do{
	printf("\nNhap so luong phan so: ");
	scanf("%d",&n);
	}
	while ( n <= 0 );
	PhanSo* ps = ( PhanSo* ) malloc ( n * sizeof ( PhanSo ));
	if ( ps == NULL ){
		printf ( "\nLoi cap phat bo nho!");
		return 1;
	}
	
	for ( int i=0 ; i<n ; i++ ){
		Nhap1PS(&ps[i]);
		printf("\n");
	}
	printf ("\nDanh sach phan so truoc khi rut gon\n");
	for ( int i=0 ; i<n ; i++ ){
		In1PS (&ps[i]);
		printf("\n");
	}
	
	printf ("\nDanh sach phan so sau khi rut gon\n");
	for ( int i=0 ; i<n ; i++ ){
		RutGon (&ps[i]);
		In1PS (&ps[i]);
		printf("\n");
	}
	
	
	PhanSo maxPS = ps[0];
	for ( int i=0 ; i<n ; i++ ){
		float c = ps[i].tu/ps[i].mau;
		float C = ps[0].tu/ps[0].mau;
		if ( C < c){
			maxPS = ps[i];
		}
	}
	printf("\nMax cua toan bo phan so la: ");
	In1PS (&maxPS);
	
	int x,y;
	printf("\nNhap vi tri phan so muon cong la: ");
	scanf("%d%d",&x,&y);
	PhanSo s = Cong2PS(ps[x],ps[y]);
	In1PS(&s);
	
	free(ps);
}
