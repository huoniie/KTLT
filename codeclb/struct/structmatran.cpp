//struct ma tran
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int hang;
	int cot;
	int matran[30][30]; 
}MaTran;
void nhap(MaTran* mt ){
	printf("\nNhap so hang: ");
	scanf("%d",&mt->hang);
	printf("\nNhap so cot: ");
	scanf("%d",&mt->cot);
	printf("\n"); 
	for ( int i=0 ; i<mt->hang ; i++ ){
		for ( int j=0 ; j<mt->cot ; j++ ){
			printf("M(%d,%d)=",i+1,j+1);
			scanf("%d",&mt->matran[i][j]);
		}
	}
}
void in (MaTran* mt ){
	for ( int i=0 ; i<mt->hang ; i++ ){
		for ( int j=0 ; j<mt->cot ; j++ ){
			printf(" %d",mt->matran[i][j]);
		}
		printf("\n");
	}
}
//void max_duong_cheo_chinh( MaTran* mt  )
//{	
//	int max = mt->matran[0][0];
//	for ( int i=0 ; i<mt->hang ; i++ ){
//		for ( int j=0 ; j<mt->cot ; j++ ){
//			if ( i=j && max < mt->matran[i][j]  )
//			{
//				max = mt->matran[i][j];
//			}
//		}
//		printf("\n");
//	}
//	printf("%d",max);
//}

int main(){
		MaTran mt;
		nhap(&mt);
		in(&mt);
//		max_duong_cheo_chinh(&mt);
}

