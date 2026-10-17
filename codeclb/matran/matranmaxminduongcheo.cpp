#include <stdio.h>

void nhap (  int n , int mt[30][30] )
{
	for ( int i=0 ; i<n ; i++ )
	{
		for ( int j=0 ; j<n ; j++ )
		{
			printf( "\n A[%d,%d]=", i+1 , j+1 );
			scanf( "%d" , &mt[i][j]);
		}
	}
} 

void in ( int n , int mt[30][30] )
{
		for ( int i=0 ; i<n ; i++ )
	{
		for ( int j=0 ; j<n ; j++ )
		{
			printf( " %d", mt[i][j] );
		}
		 printf("\n");
	}
}
  
void max_duong_cheo_chinh ( int n , int mt[30][30] )
{
	int max = mt[0][0];
	for ( int i=0 ; i<n ; i++ )
	{
		if ( max < mt [i][i])
		{
			max = mt[i][i];
		}
	}
	printf("\nMax duong cheo chinh: %d", max );	 
	printf("\n");
}
void min_duong_cheo_phu(int n, int mt[30][30]) 
{
    int min = mt[0][n - 1]; 

    for (int i = 0; i < n; i++) {
        if (mt[i][n - 1 - i] < min) {
            min = mt[i][n - 1 - i]; 
        }
    }
    
    printf("\nMin duong cheo phu %d", min);
}
int main()
{
	int n;
	printf(" Nhap so hang va cot:  ");
	scanf( "%d" , &n );
	int mt[30][30];
	nhap(n,mt);
	in(n,mt);
	max_duong_cheo_chinh ( n,mt );
	min_duong_cheo_phu ( n,mt );
}
