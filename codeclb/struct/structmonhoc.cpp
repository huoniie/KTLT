#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char mon[30];
	float diem;
}Diem;

Diem* nhap ( int n ){
	Diem* d = ( Diem* ) malloc ( n* sizeof ( Diem ) );
	for ( int i=0 ; i<n ; i++ ){
		getchar();
		printf("\nNhap ten mon: ");
		fgets(d[i].mon,30,stdin);
		d[i].mon[strcspn(d[i].mon,"\n")]=0;
		
		printf("\nNhap diem: ");
		scanf("%f",&d[i].diem);
	}
	printf("\n");
	return d;
}
void in( Diem* d , int n){
	for ( int i=0 ; i<n ; i++ ){
		printf("\n ten mon: %s ",d[i].mon );
		printf("\nNhap diem: %.2f",d[i].diem);
	}
	printf("\n");
}
int main(){
	int n;
	printf("\nNhap so luong mon hoc: ");
	scanf("%d",&n);
	Diem* D = nhap(n);
	in(D,n);
}
 
