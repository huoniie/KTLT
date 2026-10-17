#include <stdio.h>
#include <stdlib.h>

void nhap ( int** mt , int m , int n )
{
	for ( int i=0 ; i<m ; i++ )
	{
		for ( int j=0 ; j<n ; j++ )
		{
			printf("A[%d,%d]= ",i+1,j+1);
			scanf("%d",* (mt+i)+j);
		}
	}
}

void in( int** mt , int m , int n )
{
 	for ( int i=0 ; i<m ; i++ )
	{
		for ( int j=0 ; j<n ; j++ )
		{
			printf(" %d",*(*(mt+i) +j ));
		}
		printf("\n");
	}
}


void max_duong_cheo_chinh ( int** mt , int m , int n  )
{
	int max = mt[0][0];
	for ( int i=0 ; i< n; i++ )
	{
		if ( max < mt [i][i] )
		{
			max = mt[i][i];
		}
	}
	printf("\nMax duong cheo chinh la: %d" , max );
}

void min_duong_cheo_phu ( int** mt , int m , int n)
{
	int min = mt[0][n-1];
	for (int i = 0; i < n; i++) {
        if (mt[i][n - 1 - i] < min) {
            min = mt[i][n - 1 - i]; 
        }
    }
    printf("\nMin duong cheo phu : %d" , min);
}

int main()
{
	int m , n ;
	printf("\nNhap so hang va cot cua ma tran: ");
	scanf("%d%d",&m,&n);
	
    int** mt = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        mt[i] = (int*)malloc(n * sizeof(int));
    }
	nhap(mt, m, n);
    in(mt, m, n);
    
    if (m == n) {
        max_duong_cheo_chinh(mt, m,n);
        min_duong_cheo_phu(mt,m, n);
    } else {
        printf("\nKhong phai ma tran vuong");
    }

    for (int i = 0; i < m; i++) 
	free(mt[i]);
    free(mt);
}
