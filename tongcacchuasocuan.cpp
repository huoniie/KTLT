//Tinh tong cac chu so cua n
#include <stdio.h>
int main(){
	int n;
	printf("\nNhap so n: ");
	scanf("%d",&n);
	int tong=0;
	while (n!=0){
		tong+=n%10;
		n/=10;
	}
	printf("\nTong: %d",tong);
}
