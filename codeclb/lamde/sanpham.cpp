/*Struct sanpham (tên, so luong, don giá)  doc tu file

Kiem tra mat hàng có trùng tên hay ko
Xoa cac mat hang co so luong bang 0 
Sap xep giam dan theo gia tri 
Xuat ra file
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char tensp[30];
	int SoLuong;
	float gia;
}SanPham;

FILE* MoFileDoc (){
	char tenf[30];
	printf("\nNhap ten file: ");
	scanf (" %[^\n]s",&tenf);
	
	FILE* f = fopen ( tenf ,"r");
	
	if ( f == NULL ){
		printf("Loi mo file %s",tenf);
		exit(1);
	}
	return f;
}
FILE* MoFileGhi (){
	char tenF[30];
	printf("\nNhap ten file: ");
	scanf (" %[^\n]s",&tenF);
	
	FILE* F = fopen ( tenF ,"w");
	
	if ( F == NULL ){
		printf("Loi mo file %s",tenF);
		exit(1);
	}
	return F;
}

SanPham* DocSanPham(FILE* f , int n){
	SanPham* sp = (SanPham*)malloc (n*sizeof(SanPham));
	if (sp == NULL){
		printf("\nCap phat bo nho that bai");
		exit(1);
	}
	
		printf("\n%-5s %-30s %-10s %-10s ","STT","TEN SAN PHAM","SO LUONG","DON GIA");
	for ( int i=0 ; i<n ; i++ ){
		fscanf (f," %[^\n]s",&sp[i].tensp);
//		fgets(sp[i].tensp,sizeof(sp[i].tensp ),f);
//		sp[i].tensp[strcspn(sp[i].tensp,"\n")]=0;
		fscanf (f,"%d\n",&sp[i].SoLuong);
		fscanf (f,"%f\n",&sp[i].gia);
		printf("\n%-5d %-30s %-10d %-10.3f ", i+1 , sp[i].tensp,sp[i].SoLuong,sp[i].gia);
	}
	printf("\nDoc thong tin san phan thanh cong\n");
	return sp;
}

void sapxep(SanPham* sp , int n){
	printf("\nDanh sach da sap xep(theo gia tri giam dan)\n");
	printf("\n%-5s %-30s %-10s %-10s ","STT","TEN SAN PHAM","SO LUONG","DON GIA");
	for ( int i=0 ; i<n ; i++ ){
		int key=i;
		for ( int j=i+1; j<n ; j++ ){
			if ( sp[j].gia > sp[key].gia){
				key = j ;
			}
		}
		if ( key != i ){
			SanPham temp = sp[i];
			sp[i]=sp[key];
			sp[key]=temp;
		}
	}
	for ( int i=0 ; i<n ; i++ ){
		printf("\n%-5d %-30s %-10d %-10.3f ", i+1 , sp[i].tensp,sp[i].SoLuong,sp[i].gia);
	}
}

void KTSP_trung(SanPham* sp, int n) {
    int check = 0;
	printf("\nCAC SAN PHAM BI TRUNG:");
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(sp[i].tensp, sp[j].tensp) == 0) {
                printf("\nMat hang '%s' bi trung tai vi tri %d va %d!", sp[i].tensp, i + 1, j + 1);
                check = 1; 
            }
        }
    }
    if (!check) {
        printf("\nKhong co san pham nao trung ten.");
    }
    printf("\n");
}

void XoaSPHet (SanPham* sp , int *n){
	int check=0;
	printf("\nXOA CAC MAT HANG CO SO LUONG BANG 0:");
	for (int i = 0; i < *n; i++) {
	    if (sp[i].SoLuong == 0) {
	       	printf("\n%-5d %-30s %-10d %-10.3f ", i+1 , sp[i].tensp,sp[i].SoLuong,sp[i].gia);
	        for (int j = i; j < *n - 1; j++) {
	            sp[j] = sp[j + 1]; 
	        }
	        check=1;
	        (*n)--; 
	        i--;    
	    }
	}
	    printf("\nDa xoa cac mat hang co so luong bang 0.");
	if (!check){
	printf("\nKhong co san phan nao co so luong bang 0.\n");
	printf("\n");
	}
}

void GhiFile (FILE*F , SanPham* sp , int n){
	fprintf(F,"\n===DANH SACH SAN PHAM SAU KHI DA XU LY THANH CONG===\n");
	fprintf(F,"\n%-5s %-30s %-10s %-10s ","STT","TEN SAN PHAM","SO LUONG","DON GIA");
	for ( int i=0 ; i<n ; i++ ){
		fprintf(F,"\n%-5d %-30s %-10d %-10.3f ", i+1 , sp[i].tensp,sp[i].SoLuong,sp[i].gia);
	}
	printf("\nDa ghi thanh cong vao file" );
}
int main(){
	FILE*f = MoFileDoc ();
	int n;
	fscanf(f,"%d",&n);
	getchar();
	
	SanPham* sp = DocSanPham(f,n);
	fclose(f);
	KTSP_trung(sp,n);
	XoaSPHet ( sp,&n);
	sapxep(sp,n);
	FILE*F = MoFileGhi ();
	GhiFile(F,sp,n);
	fclose(F);
	free(sp);
}
