/*Nh?p m?t chu?i ch? g?m các ch? cái ti?ng Anh thý?ng.

Th?c hi?n các yêu c?u sau:

Ð?m s? nguyên âm và s? ph? âm trong chu?i.
Ki?m tra chu?i có ph?i là pangram hay không (ch?a ð? 26 ch? cái ti?ng Anh).
T?m k? t? xu?t hi?n nhi?u l?n nh?t trong chu?i.
S?p x?p các k? t? trong chu?i theo th? t? alphabet tãng d?n.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* nhap ( int* n){
	char* chuoi = (char*) malloc ( 200 * sizeof (char));
	if ( chuoi == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	
	printf("\nNhap so chuoi ban muon xu ly: ");
	scanf(" %[^\n]s",chuoi);
	*n = strlen(chuoi);
	return chuoi;
}

int* TaoMangDem(char chuoi[], int n) {
    int* dem = (int*) malloc(26 * sizeof(int));
    if (dem == NULL) {
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	
    for (int i = 0; i < 26; i++) {
        dem[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        dem[chuoi[i] - 'a']++; 
    }

    return dem; 
}

void DemNguyenAmPhuAm ( char chuoi[] , int n ){
	int nguyenAm = 0 ; 
	int phuAm = 0 ;
	for ( int i=0 ; i<n ; i++ ){
		if ( chuoi[i] == 'u' ||chuoi[i] == 'e'||chuoi[i] == 'o'||chuoi[i] == 'a'||chuoi[i] == 'i'){
			nguyenAm++;
		}
		else{
			phuAm++;
		}
	}
	
	printf("\nSo luong nguyen am %d || So luong phu am %d ", nguyenAm ,phuAm);
}

void KiemTraLaPangRam ( char chuoi[] , int n , int dem[]){
    int LaPangRam = 1;
    for (int i = 0; i < 26; i++) {
        if (dem[i] == 0) { 
            LaPangRam = 0;
            break;
        }
    }
    if (LaPangRam) printf("\nChuoi nay  la chuoi pangram  du 26 chu\n");
    else printf("\nChuoi nay khong phai la pangram.\n");
}

void TimChuXuatHienNhieuNhat ( char chuoi[], int n , int dem[]){
	int demMax = 0;
    int viTri = 0;
    for (int i = 0; i < 26; i++) {
        if (dem[i] > demMax) {
            demMax = dem[i];
            viTri = i;
        }
    }
    printf("Ky tu xuat hien nhieu nhat la: '%c' (%d lan)\n", viTri + 'a',demMax);
}

void SapXep (char chuoi[], int n){
	for ( int i=0 ; i<n-1 ; i++ ){
		int key = i;
		for ( int j=i+1 ; j<n ; j++ ){
			if (chuoi[key] > chuoi[j]){
				key = j;
			}
		}
		if (key!=i){
			char temp = chuoi[i];
			chuoi[i]=chuoi[key];
			chuoi[key]=temp;
		}
	}
	
	for ( int i=0 ; i<n ; i++ ){
		printf("%c",chuoi[i]);
	}
}

int main (){
	int n;
	char* chuoi = nhap(&n);
	int* dem = TaoMangDem (chuoi,n);
	DemNguyenAmPhuAm (chuoi,n);
	KiemTraLaPangRam(chuoi,n,dem);
	TimChuXuatHienNhieuNhat(chuoi,n,dem);
	SapXep ( chuoi,n);
	
	free(chuoi);
	free(dem);
}

