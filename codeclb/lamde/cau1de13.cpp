////
////Câu 1. X? lý d? li?u không gian (S? d?ng c?p phát b? nh? d?ng)
////M?t khu v?c b?n d? d?ng lu?i 2D du?c bi?u di?n b?i m?t ma tr?n 
//vuông A kích thu?c n × n. Các ph?n t? trong ma tr?n là các s? nguyên d?i di?n cho d? cao c?a d?a hình t?i t?a d? dó.
////D? li?u du?c luu trong t?p van b?n map.txt (Tên t?p nh?p t? bàn phím),
// có c?u trúc: dòng d?u ghi s? nguyên n, n dòng ti?p theo m?i dòng ch?a n s? nguyên phân cách nhau b?i d?u cách.
////Hãy xây d?ng các hàm và hàm main() d? th?c hi?n:
////Ð?c d? li?u d? cao t? t?p vào ma tr?n có s? d?ng c?p phát b? nh? d?ng.
////Tìm và in ra màn hình t?a d? (i, j) c?a di?m có d? cao l?n nh?t.
// N?u có nhi?u di?m cùng d? cao l?n nh?t, in ra t?t c?.
////M?t di?m du?c g?i là "d?nh d?i" n?u d? cao c?a nó 
//l?n hon h?n t?t c? 4 ô k? c?nh v?i nó (trên, du?i, trái, ph?i). Vi?t hàm d?m s? lu?ng "d?nh d?i" có trên b?n d? (không xét các ô n?m ? du?ng biên c?a ma tr?n).
////Gi?i phóng b? nh? dã c?p phát.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int** DocTep ( int* n ){
	char tenf[30];
	printf("\nNhap ten tep: ");
	scanf("%[^\n]s",&tenf);
	tenf[strcspn(tenf,"\n")]=0;
	
	FILE* f = fopen ( tenf ,"r");
	
	if ( f == NULL ){
		printf("\nLoi mo tep!");
		exit(1);
	}
	
	fscanf (f,"%d",n);
	
	int** mt = (int**) malloc ( (*n) * sizeof (int*));
	for ( int i=0 ; i<*n ; i++ ){
		mt[i] = ( int*) malloc ( (*n)* sizeof ( int ));
		for ( int j=0 ; j<*n ; j++ ){
			fscanf(f,"%d",&mt[i][j]);
			printf("%d  ",mt[i][j]);
		}
		printf("\n");
		fprintf(f,"\n");
	}
	fclose(f);
	return mt;
}

void ToaDoLonNhat ( int** mt , int n ){
	int max = mt[0][0];
	for ( int i=0 ; i<n ; i++ ){
		for ( int j=0 ; j<n ; j++ ){
			if ( max < mt[i][j]){
				max = mt[i][j];
			}
		}
	}
	
	printf("\nToa do co do cao lon nhat\n");
	
	for ( int i=0 ; i<n ; i++ ){
		for ( int j=0 ; j<n ; j++ ){
			if ( max == mt[i][j]){
				printf("A(%d,%d) co do cao %d\n",i,j,mt[i][j]);
			}
		}
	}
}

void DemDinhDoi(int** mt, int n) {
    int dem = 0;
    
    for (int i=1; i<n-1; i++) {
        for (int j=1; j<n-1; j++) {
            
            if (mt[i][j] > mt[i-1][j] && 
                mt[i][j] > mt[i+1][j] && 
                mt[i][j] > mt[i][j-1] &&
                mt[i][j] > mt[i][j+1])   
            {
                dem++;
            }
        }
    }
    
    printf("So luong dinh doi tren ban do la: %d\n", dem);
}

int main(){
	int n;
	int** mt = DocTep(&n);
	ToaDoLonNhat (mt,n);
	DemDinhDoi(mt,n);
	for (int i = 0; i < n; i++) {
        free(mt[i]);
    }
	free(mt);
}
