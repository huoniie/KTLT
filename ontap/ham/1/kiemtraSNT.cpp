//viet ham kiem tra 1 so co phai so nguyen to khong
#include <stdio.h>
#include <math.h>
 
int KtraSNT ( int n )
{
	if ( n<2 ) 
	{
		printf("\nKhong phai la SNT: %d",n);
		return 0;
	}
	if ( n== 2) 
	{
		printf("\nLa SNT: %d",n);
		return 1;
	}
	if ( n%2==0 ) {
		printf("\nKhong phai la SNT: %d",n);
		return 0;
	}
	for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) 
        {
        	printf("\n khong phai la SNT: %d",n);
        	 return 0;
		}
    }
    printf("\nLa SNT: %d", n);
    return 1;
}
int main ()
{
	int n;
	printf("\nNhap 1 so ban muon kiem tra: ");
	scanf("%d",&n);
	
	KtraSNT (n);
}
