//Bai tap viet ham nhap ma tran va xuat bang malloc va mang thuong
//	Mang malloc
#include <stdio.h>
#include <stdlib.h>

int** nhap( int m , int n)
{
	int** mt = ( int** ) malloc ( m * sizeof (int*));
	for ( int i=0 ; i<m ; i++ )
	{
		mt[i] = ( int* ) malloc ( n * sizeof ( int ));
		for ( int j=0 ; j<n ; j++ )
		{
			printf("A[%d][%d]= " , i+1 , j+1 );
			scanf("%d",&mt[i][j]);
		}
	}
	return mt;
}

void in(int** mt , int m , int n )
{
	for ( int i=0 ; i<n ; i++ )
	{
		for ( int j=0 ; j<n ; j++ )
		{
			printf(" %d" ,mt[i][j] );
		}
		printf("\n");
	}
}

int main()
{
	int hang,cot;
	printf("\nNhap hang va cot cua ma tran: ");
	scanf("%d%d",&hang,&cot);
	int** mt = nhap(hang,cot);
	in(mt,hang,cot);
}
