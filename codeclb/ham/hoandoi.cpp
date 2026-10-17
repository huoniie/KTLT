#include <stdio.h>
#include <stdlib.h>

void HoanDoi ( int** a , int** b)
{
	
	int* temp = *a;
	*a = *b ;
	*b = temp;
}
 
int main()
{
	int x=10;
	int y=5;
	int* a = &x;
	int* b = &y;
	HoanDoi(&a,&b);
	printf("a=%d b=%d",*a,*b);
}

