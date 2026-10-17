//Cho t?p input.txt n
//a1 a2 a3 ... an
//Ð?c danh sách t? t?p.
//S?p x?p danh sách
//Tìm s? nguyên t? l?n nh?t trong danh sách.
//Xóa t?t c? các ph?n t? trùng l?p (gi? l?i l?n xu?t hi?n d?u tiên).
//Ghi k?t qu? ra output.txt.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

FILE* MoFile ( char* ten , char* CheDo){
	
	FILE* f = fopen ( ten,CheDo );
	
	if ( f == NULL ){
		printf("\nLoi mo file");
		exit(1);
	}
	return f;
}

int* DocFile ( FILE* f , int* n ){
	fscanf ( f , "%d" , n );
	
	if ( n == NULL ){
		printf("\nLoi doc file!");
		exit(1);
	}
	
	int* a = ( int* ) malloc ( *n * sizeof ( int ));
	 
	if ( a == NULL ){
	 	printf ("\nLoi cap phat bo nho!");
	 	exit (1);
	}
	 
	for ( int i=0 ; i<*n ; i++ ){
		fscanf( f , "%d" , &a[i] );
	}
	printf("\nDa doc thanh cong du lieu cua file!");
	return a;
}


void SapXep ( int* a , int n ){
	for ( int i=0 ; i<n-1 ; i++ ){
		int key = i ;
		for ( int j=i+1; j<n ; j++ ){
			if ( a[key] > a[j] )
			key = j;
		}
		if ( key != i){
			int temp = a[i];
			a[i] = a[key];
			a[key] = temp;
		}
	}
}
int KiemTraSNT(int x) {
    if (x < 2) return 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0; 
    }
    return 1;
}

int TimMaxSNT(int* a, int n) {
    int maxSNT = -1; 
    for (int i = 0; i < n; i++) {
        if (KiemTraSNT(a[i])) {
            if (maxSNT == -1 || a[i] > maxSNT) {
                maxSNT = a[i];
            }
        }
    }
    return maxSNT;
}
int XoaTrungLap(int* a, int n) {
    int k = 0; 
    
    for (int i = 0; i < n; i++) {
        int daXuatHien = 0; 
        for (int j = 0; j < k; j++) {
            if (a[i] == a[j]) {
                daXuatHien = 1;
                break;
            }
        }
        if (daXuatHien == 0) {
            a[k] = a[i];
            k++;
        }
    }
    return k; 
}
int main() {
    int n;
    FILE* f = MoFile("cau2de10.txt", "r");
    int* a = DocFile(f, &n);
    fclose ( f);
    
    FILE* F = MoFile("outputcau2de10.txt", "w");
    
    
    SapXep(a, n);
    fprintf(F, "sap xep: ");
    for (int i = 0; i < n; i++) fprintf(F, "%d ", a[i]);
    
    int max = TimMaxSNT(a, n);
    if (max!= -1) {
        fprintf(F, "\nSo nguyen to lon nhat la: %d\n", max);
    } else {
        fprintf(F, "\n2. Mang khong co so nguyen to nao.\n");
    }
    
    int soLuongMoi = XoaTrungLap(a, n);
    fprintf(F, "\nMang sau khi xoa phan tu trung lap ");
    for (int i = 0; i < soLuongMoi; i++) {
        fprintf(F, "%d ", a[i]);
    }
    
    fclose(F);
    free(a);
    return 0;
}
