#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int tu;
    int mau;
} PhanSo;

int TimUCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (a * b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return a + b;
}

void RutGon(PhanSo* ps) {
    if (ps->mau == 0) return; 
    
    int ucln = TimUCLN(ps->tu, ps->mau);
    ps->tu = ps->tu / ucln;
    ps->mau = ps->mau / ucln;
    
    if (ps->mau < 0) {
        ps->tu = -ps->tu;
        ps->mau = -ps->mau;
    }
}


void Nhap1PhanSo(PhanSo* ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tu);
    
    do {
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &ps->mau);
    } while (ps->mau == 0);
    
    RutGon(ps);
}

void In1PhanSo(PhanSo ps) {
    if (ps.tu == 0) {
        printf("0");
    } 
	else if (ps.mau == 1) {
        printf("%d", ps.tu); 
    } 
	else {
        printf("%d/%d", ps.tu, ps.mau);
    }
}

PhanSo Cong2PhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    ketQua.mau = ps1.mau * ps2.mau;
    
    RutGon(&ketQua); 
    return ketQua;
}

int main() {
    int n;
    
    printf("Nhap so luong phan so: ");
    scanf("%d", &n);
    
    PhanSo* ps = (PhanSo*)malloc(n * sizeof(PhanSo));
    if (ps == NULL) {
        printf("Loi cap phat bo nho!\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        printf("Phan so thu %d:\n", i + 1);
        Nhap1PhanSo(&ps[i]);
    }
    
    printf("\n--- DANH SACH PHAN SO (Da rut gon) ---\n");
    for (int i = 0; i < n; i++) {
        In1PhanSo(ps[i]);
        printf("\n");
    }
    printf("\n");
    
    PhanSo maxPS = ps[0];
    PhanSo tong = ps[0]; 
    
    for (int i = 1; i < n; i++) {
        tong = Cong2PhanSo(tong, ps[i]);
        
        float giaTriHienTai = (float)ps[i].tu / ps[i].mau;
        float giaTriMax = (float)maxPS.tu / maxPS.mau;
        
        if (giaTriHienTai > giaTriMax) {
            maxPS = ps[i];
        }
    }
    
    printf("Phan so lon nhat la: ");
    In1PhanSo(maxPS);
    
    printf("\nTong toan bo cac phan so: ");
    In1PhanSo(tong);
    printf("\n");
    
    free(ps);
    
    return 0;
}
