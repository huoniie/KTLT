#include <stdio.h>
int main(){
	int b[4];
	int* a=b;
	printf("nhap gia tri cua mang: \n");
	for ( int i=0 ; i<4 ;i ++ ){
		printf("b[%d]=",i);
		scanf("%d",&b[i]);
	}
	printf("mang vua nhap\n");
	for ( int i=0 ; i<4 ;i ++ ){
		printf("%2d ",*(a+i));
	}
	
}
