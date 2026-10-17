#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
void nhap ( char* a )
{
	printf("\nNhap: ");
	fgets(a,30,stdin);
	a[strcspn(a, "\n")] = 0;
	printf("\nCai may vua nhap %s", a );
}

 
void DaoNguoc ( char* a )
{
	int n = strlen(a);
	char b;
	char* temp = &b;
    for (int i = 0; i < n / 2; i++) {
        *temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = *temp;
    }
    printf("\ndao nguoc cai vua nhap: %s",a);
} 

int main ()
{
	char* A; 
    A = (char*)malloc(30 * sizeof(char));
    nhap(A); 
	DaoNguoc(A);
}
