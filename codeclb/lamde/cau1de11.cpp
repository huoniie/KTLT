#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* nhap (){
	char* chuoi = ( char* ) malloc ( 100 * sizeof ( char));
	if ( chuoi == NULL ){
		printf("\nLoi cao phat bo nho!");
		exit(1);
	}
	printf("\nNhap 1 chuoi lien nhau ( gom 0 va 1 ):");
	scanf ( "%s",chuoi);
	return chuoi;
}

void dem ( char chuoi[] , int n ){
	int dem1 =0;
	int dem2 =0;
	for ( int i=0 ; i<n ; i++ ){
		if ( chuoi[i] == '0') dem1++;
		else if ( chuoi[i] == '1') dem2++;
	}
	printf("\nSo luong bit cua 0 la %d va 1 la %d",dem1,dem2);
}
void DoiXung ( char chuoi[] , int n ){
int check = 1;
    for (int i = 0; i < n / 2; i++) {
        if (chuoi[i] != chuoi[n - 1 - i]) {
            check = 0; 
            break; 
        }
    }
    
    if (check == 1) {
        printf("\nChuoi nay la chuoi doi xung.\n");
    } else {
        printf("\nChuoi nay khong phai doi xung.\n");
    }

}

void ChuoiCon ( char chuoi[] , int n){
	int viTri = -1;
    for (int i = 0 ; i <= n-3; i++ ) {
        if (chuoi[i] == '1' && chuoi[i+1] == '0' && chuoi[i+2] == '1') {
            viTri = i; 
            break;
        }
    }
    
    if (viTri != -1) {
        printf("\n Chuoi '101' xuat hien lan dau tien tai vi tri  %d\n", viTri);
    } else {
        printf("\nKhong tim thay chuoi '101' trong chuoi.\n");
    }
}

int main(){
	char* chuoi = nhap();
	int n = strlen(chuoi);
	dem (chuoi,n);
	DoiXung(chuoi,n);
	ChuoiCon(chuoi,n);
	free(chuoi);
}
