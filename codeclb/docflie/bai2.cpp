/*Bai 2 lam bai 1 nhung thay mang bang ma tran mn (ham)*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int** DocTep( FILE* f ,int m , int n )
{
	int** mt = (int**) malloc (m*sizeof(int*));
	for ( int i=0 ; i<m ; i++ )
	{
		mt[i] = (int*) malloc (n*sizeof(int));
		for (int j=0 ; j<n ; j++ )
		{
			fscanf ( f , "%d" , &mt[i][j]);
			printf(" %d",mt[i][j]);
		}
		printf("\n");
	}
	return mt;
}

void GhiTep ( int m , int n , int** mt )
{
	printf( "%d %d\n", m, n);
	for ( int i=0 ; i<m ; i++ )
	{
		for ( int j=0 ; j<n ; j++ )
		
		{
			printf( "%-5d" , mt[i][j]*2);
		}
		printf("\n");
	}
}

int main()
{
	FILE* f;
	char tenf[30];
	printf("\nNhap ten file: ");
	fgets ( tenf , sizeof(tenf) , stdin );
	tenf[strcspn(tenf,"\n")]=0;
	
	f = fopen ( tenf ,"r");
	if ( f == NULL )
	{
		printf("\nFlie bi loi khong mo duoc: ");
		return 1;
	}
	
	
	int m,n;
	fscanf(f,"%d%d",&m,&n);
	int** mt = DocTep (f,m,n);
//	printf("\nDoc tep thanh cong");
	fclose (f);
//	fseek(f, 0, SEEK_END);
//	printf("\nGhi lai vao file voi mang gap doi ban dau");
//	GhiTep(m,n,mt);
//	printf("\nDa ghi ket qua vao file %s",tenf);
//	fclose(f);
	
	for ( int i=0 ; i<m ; i++ )
	{
		free(mt[i]);
	}
	free(mt);
	return 0 ;
}

