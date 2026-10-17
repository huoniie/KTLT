#include <stdio.h>
void nhap( int* a , int* b )
{
	scanf("%d%d",a,b);
	return;
}
int hieu( int* a , int* b ){
	int hieu=*a-*b;
	return hieu;
}

int main (){
	int m,n;
	int *a=&m,*b=&n;
	nhap(a,b);
	hieu(&m,&n);
	printf("hieu=%d",hieu(&m,&n));	
}

