//Bai tap viet ham nhap ma tran va xuat bang malloc va mang thuong
//Mang thuong
#include <stdio.h>

void nhap ( int hang, int cot , int mt[][cot] )
{
	for ( int i=0 ; i<hang ; i++ )
	{
		for (int j=0 ; j<cot ; j++ )
		{
			printf("A[%d][%d]= ", i + 1 , j + 1 );
			scanf("%d",&mt[i][j]);
		}
	}
}

void xuat ( int hang, int cot , int mt[][cot])
{
	for ( int i=0 ; i<hang ; i++ )
	{
		for (int j=0 ; j<cot ; j++ )
		{
			printf(" %d", mt[i][j] );
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
