/*bài 1 nhap mot file ma tran cap 2 bang malloc 
in các so duoi duong chéo phu ra file*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void DuoiDuongCP ( FILE* f , int** mt , int m , int n)
{
	if ( m == n )
	{
		printf("\nCac phan tu duoi duong cheo phu: ");
		for ( int i=0 ; i<m ; i++ )
		{	
			for ( int j=0 ; j<n ; j++ )
			{
				if (i + j > n - 1){
				fprintf(f,"%d ",mt[i][j]);
				}
			}
//			fprintf(f,"\n");
		}
		printf("\nDa ghi thanh cong cac phan tu duoi duong cheo phu vao file.");
	}
	else
	{
		printf("\nKhong phai ma tran vuong khong co duong cheo phu");
	}
}

int main ()
{  
	int hang , cot;
	printf ("\nNhap hang va cot cua ma tran: ");
	scanf("%d%d",&hang,&cot);
	
	int** mt = nhap ( hang , cot );
	in (mt,hang,cot);
	
	FILE* f;
	char tenf[30];
	getchar();
    printf("\nNhap ten file: ");
	fgets(tenf, sizeof (tenf) , stdin);
    tenf[strcspn(tenf, "\n")] = 0; 
	
	f = fopen(tenf, "w");
	
	if (f == NULL) 
	{
	    printf(" Loi: Khong tim thay file '%s'. Vui long kiem tra lai ten file!\n", tenf);
	}
    
	DuoiDuongCP ( f , mt , hang , cot );
	fclose(f);
	for ( int i=0 ; i<hang ; i++ )
	{
		free(mt[i]);
	}
	free(mt);
	return 0;		
}
