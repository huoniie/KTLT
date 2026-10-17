/*Nh?p m?t chu?i bi?u di?n bi?n s? xe (ví d?: 30A12345).

Th?c hi?n các yêu c?u sau:

Tách ph?n ch? và ph?n s? c?a bi?n s?.
Tính t?ng các ch? s? xu?t hi?n trong bi?n s?.
Ki?m tra dãy s? có tang d?n hay không.
Ki?m tra bi?n s? có ch?a c?p s? gi?ng nhau liên ti?p hay không.
Tìm ch? s? xu?t hi?n nhi?u nh?t.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* NhapBienSo ( int*n ){
	char* bs = ( char* ) malloc ( 100 * sizeof ( char));
	if ( bs == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	
	printf("\nNhap bien so ban muon xu ly: ");
	scanf("%[^\n]s",bs);
	*n = strlen(bs);
	return bs;
}

void XuLyBienSo(char bs[] , int n ,char* phanSo, int* pS) {
    char phanChu[20] = "";
    int pC = 0; 
	*pS = 0;

    for (int i = 0; i < n; i++) {
        if ((bs[i] >= 'A' && bs[i] <= 'Z') || (bs[i] >= 'a' && bs[i] <= 'z')) {
            phanChu[pC] = bs[i];
            pC++;
        } 
        else if (bs[i] >= '0' && bs[i] <= '9') {
            phanSo[*pS] = bs[i];
            (*pS)++;
        }
    }
    phanChu[pC] = '\0';
    phanSo[*pS] = '\0';
    
    printf("\n Phan chu: %s  Phan so: %s\n", phanChu, phanSo);

    int tong = 0;
    for (int i = 0; i < *pS; i++) {
        tong += (phanSo[i] - '0'); 
    }
    printf("\nTong cac chu so la: %d\n", tong);
}
    
void KiemTraDayTang ( char phanSo[],int pS){
    int isTang = 1;
    if (pS < 2) isTang = 0; 
    
    for (int i = 0; i < pS - 1; i++) {
        if (phanSo[i] >= phanSo[i+1]) {
            isTang = 0; 
            break;
        }
    }
    if (isTang) printf("\nDay so la day tang dan.\n");
    else printf("\nDay so khong phai la day tang dan.\n");
}

void KiemTraLienTiep ( char bs[], int n){
    int coLienTiep = 0;
    for (int i = 0; i < n - 1; i++) {
        if ((bs[i] >= '0' && bs[i] <= '9') && (bs[i] == bs[i+1])) {
            coLienTiep = 1;
            break;
        }
    }
    if (coLienTiep) printf("Bien so CO chua cap so giong nhau lien tiep.\n");
    else printf("Bien so KHONG chua cap so giong nhau lien tiep.\n");
}

void SoXuatHienNhieuNhat ( char phanSo[] , int pS ){
	
    int dem[10] = {0}; 
    
    for (int i = 0; i < pS; i++) {
        dem[phanSo[i] - '0']++; 
    }

    int maxLan = 0;
    int soMax = 0;
    for (int i = 0; i < 10; i++) {
        if (dem[i] > maxLan) {
            maxLan = dem[i];
            soMax = i; 
        }
    }
    printf("\nChu so xuat hien nhieu nhat la: '%d' (%d lan)\n", soMax, maxLan);
}

int main() {
    int n;
    int pS;
    char phanSo[20];
    char* bs = NhapBienSo(&n);
    XuLyBienSo (bs,n,phanSo,&pS);
    KiemTraDayTang (phanSo,pS);
    KiemTraLienTiep(bs,n);
    SoXuatHienNhieuNhat (phanSo,n);
    
    free(bs);
}

