//LTOL
#include <stdio.h>
int main (){
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	for ( int i=1 ; i<=n ; i++ ){
		if(i%2!=0){
			printf("%d",i);
		}
		if( i%2==0 ){
			printf("L");
		}
		if ( i%4 == 0){
			printf("T");
		}
		if (i%8==0){
			printf("O");
		}
		if(i%16==0){
			printf("L");
		}
		printf("\n");
	}
}
