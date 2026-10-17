#include <stdio.h>
#include <stdlib.h>
void ThayDoiGiaTri( int** a , int n )
{
	*a = (int*) malloc ( n * sizeof ( int ));
} 
int main ()
{
	int n;
	int* c=NULL;
	printf("%d\n",c);
	ThayDoiGiaTri(&c,n);
	c[0]=7;
	printf("%d",c[0]);
}
