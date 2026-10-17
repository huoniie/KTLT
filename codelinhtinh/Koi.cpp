// Koi
#include <stdio.h>
int main(){
	long long n;
//	printf("\nNhap n: ");
	scanf("%lld",&n);
	long long tich=1;
	int dem=0;
	while ( tich < n ){
		tich*=2;
		dem++;
	}
	printf("%d",dem);
	
}
 
