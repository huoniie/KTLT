#include <stdio.h>
int main() 
{
	
	int x =25 ;
	int *pt = &x;
	int **ppt=&pt;
	
	printf("&x=%d\n",&x);
	printf("pt=%d\n",pt);
	printf("*pt=%d\n",*pt);
	printf("&pt=%d\n",&pt);
	printf("\n") ;
	printf("ppt=%d\n",ppt);
	printf("*ppt=%d\n",*ppt);
	printf("**ppt=%d\n",**ppt);
	printf("&ppt=%d\n",&ppt);
	
}

 

