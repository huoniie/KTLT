//câu 2 nh?p danh sách n các s?n ph?m
// t? t?p, m?i s?n ph?m g?m 
// 4 dòng bi?u di?n các tru?ng: 
// Tên, Giá, Lo?i (1,2,3), S? lu?ng. 
// Dòng d?u tiên c?a t?p là s? s?n ph?m. Yêu c?u:
//Th?ng kê s?n ph?m theo lo?i.
//Tìm s?n ph?m có lo?i 1 có Giá th?p nh?t.
//Xu?t danh sách ra output.txt.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
	char tensp[50];
	float gia;
	char loai[10];
	int soluong;
}SanPham;



SanPham* DocFile ( FILE* f , int n ){
	SanPham* sp = ( SanPham* ) malloc ( n* sizeof ( SanPham ));
	if ( sp == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	printf("\n=====DANH SACH SAN PHAM============\n");
	printf("%-5s %-30s %-15s %-10s %-10s",
			"STT","TEN SAN PHAM","GIA","LOAI(1,2,3)","SO LUONG");
	for ( int i=0 ; i<n ; i++ ){
		fscanf (f," %[^\n]s" , & sp[i].tensp );
		sp[i].tensp[strcspn ( sp[i].tensp,"\n" )]=0;
		fscanf (f," %f " ,&sp[i].gia );
		fscanf (f," %[^\n]s " , &sp[i].loai);
		fscanf (f,"%d" ,&sp[i].soluong);
		printf("\n%-5d %-30s %-15.3f %-10s %-10d",i+1,sp[i].tensp ,sp[i].gia ,sp[i].loai,sp[i].soluong);
	}
	printf("\nDa hoan thanh doc file");
	return sp;
}

void GhiFile ( FILE* F ,SanPham* sp , int n) {
	fprintf(F,"\n=====DANH SACH SAN PHAM============\n");
	fprintf(F,"%-5s %-30s %-15s %-10s %-10s",
			"STT","TEN SAN PHAM","GIA","LOAI(1,2,3)","SO LUONG");
	for ( int i=0 ; i<n ; i++ ){
		fprintf(F,"\n%-5d %-30s %-15.3f %-10s %-10d",i+1,sp[i].tensp ,sp[i].gia ,sp[i].loai,sp[i].soluong);
	}
	printf("\nDa ghi thanh cong du lieu vao file");
}

void ThongKeSP ( FILE* f , SanPham* sp , int n ){
	int l1=0;
	int l2=0;
	int l3=0;
	int minL1 = -1; 
	fprintf (f,"\n=====KET QUA THONG KE CAC LOAI SAN PHAM=====\n");
	for (int i = 0; i < n; i++) {
		if (strcmp(sp[i].loai, "Loai 1") == 0) {
			l1++;
			if (minL1 == -1 || sp[i].gia < sp[minL1].gia) {
				minL1 = i;
			}
		}
	}
	if (l1 == 0) fprintf(f, "\nKhong co san pham nao loai 1.");
	else fprintf(f, "\nCo %d san pham loai 1.", l1);
	
	for (int i = 0; i < n; i++) {
		if (strcmp(sp[i].loai, "Loai 2") == 0) {
			l2++;
		}
	}
	if (l2 == 0) fprintf(f, "Khong co san pham nao loai 2.\n");
	else fprintf(f, "\nCo %d san pham loai 2.", l2);

	
	for (int i = 0; i < n; i++) {
		if (strcmp(sp[i].loai, "Loai 3") == 0) {
			l3++;
		}
	}
	if (l3 == 0) fprintf(f, "\nKhong co san pham nao loai 3.");
	else fprintf(f, "\nCo %d san pham loai 3.", l3);

	if (minL1 != -1) {
		fprintf(f, "\nSan pham Loai 1 co gia thap nhat: %s (%.3f)\n", 
				sp[minL1].tensp, sp[minL1].gia);
	}

}

int main ()
{
	char tenf[50];
	printf("\nNhap ten file: ");
	scanf(" %[^\n]s" ,&tenf);
	FILE* f = fopen ( tenf , "a+");
	
	if ( f == NULL ){
		printf("\nLoi mo tep!");
		return 1;
	}
	rewind (f);
	int n;
	fscanf(f,"%d",&n);
	printf ("\n%d",n);
	SanPham* sp = DocFile(f,n);
	fseek ( f , 0 , SEEK_END );
	GhiFile(f,sp,n);
	ThongKeSP(f,sp,n);
	fclose(f);
	free(sp);
}


