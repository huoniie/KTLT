//Nhap ma tran tim tong cheo chinh tong cheo phu
#include <stdio.h>
#include <stdlib.h>

int** nhap ( int m , int n )
{
	printf("\nNhap gia tri cua ma tran\n");
	int** mt = ( int** ) malloc ( m * sizeof ( int* ));
	for ( int i=0 ; i<m ; i++ )
	{
		mt[i] = ( int* ) malloc ( n * sizeof ( int ));
		for ( int j=0 ; j<n ; j++ )
		{
			printf("A[%d][%d]= ", i+1 , j+1 );
			scanf( "%d" , &mt[i][j] );
		}
	}
	return mt;
}

void in ( int** mt , int m , int n )
{
	printf("\nMa tran vua nhap la: \n");
	for( int i=0 ; i<m ; i++ )
	{
		for ( int j=0 ; j<n ; j++ )
		{
			printf(" %d", mt[i][j] );  
		}
		printf("\n");
	}
}
//void TongCheoChinhPhu ( int** mt , int m , int n )
//{
//	if ( m==n ) 
//	{
//		int tong_chinh = 0 ;
//		int tong_phu = 0 ; 
//		for ( int i=0 ; i<m ; i++ )
//		{
//			tong_chinh+=mt[i][i];
//			tong_phu+=mt[i][n-1-i];
//		}
//		printf("\nTong duong cheo chinh: %d" ,tong_chinh);
//		printf("\nTong duong cheo phu: %d",tong_phu);
//      tong_trenduoi_cheochinh(mt,m,n);
//		tong_trenduoi_cheophu(mt,m,n);
//	}
//	else
//	printf("\nMa tran khong phai ma tran vuong nen khong co tong duong cheo chinh, cheo phu!");
//	
//}
// 
 
void tong_trenduoi_cheochinh( int** mt , int m , int n)
{   
	if(m==n){
		int tong_chinh=0 ;
		int tong_tren=0;
		int tong_duoi=0;
		for ( int i=0 ; i<n ; i++ )
		{
			
			for ( int j=0 ; j<n ; j++ )
			{
				if (i == j) 
	            {
	                tong_chinh += mt[i][j];
	            } 
	            else if (i < j) 
	            {
	                tong_tren += mt[i][j];
	            } 
	            else 
	            {
	                tong_duoi += mt[i][j];
	            }
			}
		}
		printf("\nTong duong cheo CHINH: %d" ,tong_chinh);
		printf("\nTong TREN duong cheo chinh: %d" ,tong_tren);
		printf("\nTong DUOI duong cheo chinh: %d" ,tong_duoi);
	}
	else
	printf("\nMa tran khong phai ma tran vuong nen khong co tong duong cheo chinh");
}

void tong_trenduoi_cheophu( int** mt , int m , int n)
{   
	if(m==n){
		int tong_chinh=0 ;
		int tong_tren=0;
		int tong_duoi=0;
		for ( int i=0 ; i<n ; i++ )
		{
			
			for ( int j=0 ; j<n ; j++ )
			{
				if (i + j == n - 1) 
	            {
	                tong_chinh += mt[i][j];
	            } 
	            else if (i + j < n - 1) 
	            {
	                tong_tren += mt[i][j];
	            } 
	            else 
	            {
	                tong_duoi += mt[i][j];
	            }
			}
		}
		printf("\nTong duong cheo PHU: %d" ,tong_chinh);
		printf("\nTong TREN duong cheo phu: %d" ,tong_tren);
		printf("\nTong DUOI duong cheo phu: %d" ,tong_duoi);
	}
	else
	printf("\nMa tran khong phai ma tran vuong nen khong co tong duong cheo phu!");
}
int main()
{
	int m,n;
	printf("\nNhap hang va cot cua ma tran: ");
	scanf("%d%d",&m,&n);
	
	int** mt = nhap (m,n);
	in(mt,m,n);
	
//	TongCheoChinhPhu(mt,m,n);
	
	tong_trenduoi_cheochinh(mt,m,n);
	printf("\n");
	tong_trenduoi_cheophu(mt,m,n);
	
	for ( int i=0 ; i<m ; i++ ){
		free(mt[i]);
	}
	free(mt);
}
