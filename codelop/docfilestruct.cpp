#include <stdio.h>
typedef struct{
	char ht[30];
	float t,l,h;
}kts;
int main()
{
	FILE* f;
	kts ts[50];
	char tenf[30];
	printf("Ten tep: ");
	gets(tenf);
	int n;
	f = fopen (tenf , "rt");
	fscanf( f , "%d\n" , &n );
	for ( int i=0 ; i<n ; i++ )
	{
		fgets(ts[i].ht , sizeof(ts[i].ht), f);
		fscanf( f , "%f%f%f\n ", &ts[i].t , &ts[i].l ,&ts[i].h);
		printf("\n%s %.2f %.2f %.2f",ts[i].ht ,ts[i].t , ts[i].l ,ts[i].h);
	}
}
