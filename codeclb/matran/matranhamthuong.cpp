//Bai tap viet ham nhap ma tran va xuat bang malloc va mang thuong
//Mang thuong
#include <stdio.h>

void nhap ( int hang, int cot , int mt[hang][cot] )
{
	for ( int i=0 ; i<hang ; i++ )
	{
		for (int j=0 ; j<cot ; j++ )
		{
			printf("A[%d][%d]= ", i + 1 , j + 1 );
			scanf("%d",&a[i][j]);
		}
	}
}

void xuat ( int hang, int cot , int mt[hang][cot])
{
	for ( int i=0 ; i<hang ; i++ )
	{
		for (int j=0 ; j<cot ; j++ )
		{
			printf(" %d", a[i][j] );
		}
		printf("\n");
	}
}

int main()
{
	int hang , cot ; 
	printf("\nNhap hang va cot cua ma tran: ");
	scanf("%d%d",&hang,&cot);
	int mt[hang][cot];
	nhap(hang,cot,mt);
	xuat(hang,cot,mt);
}
