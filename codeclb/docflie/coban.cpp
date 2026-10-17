#include <stdio.h>

int main()
{
	FILE* f;
	f = fopen ("huong.txt","rb");
	
	int n;
	printf("\nNhap vao gia tri so n: ");
	scanf("%d",& n);
	
	fprintf(f,"%d",&n);
}
