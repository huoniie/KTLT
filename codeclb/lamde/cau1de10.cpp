/*Cho t?p ch?a danh sách v?n d?ng viên v?i các tru?ng:
 Tên c?u th?, Môn, Ði?m, Câu l?c b? có c?u trúc nhu sau:
  dòng d?u ch?a s? v?n d?ng viên. T? dòng th? 2 tr? di, 
  c? 4 dòng là thông tin c?a m?t c?u th? l?n lu?t là: 
  Tên c?u th?, Môn (gi? s? có 3 môn: A, B, C), Ði?m thi (thang di?m 100),
   Câu l?c b?.
Nh?p danh sách c?u th? t? t?p và s?p x?p danh sách theo Môn.
Th?ng kê c?u th? theo câu l?c b? làm 2 2 cách (truy?n tham s? c?c b? và không)
Tìm v?n d?ng viên có di?m th?p nh?t.
Xu?t danh sách ra output.txt.*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
	char ht[50];
	char mon[10];
	float diem;
	char clb[50];
}CauThu;


FILE* MoFile (  char ten[] , char chedo[]){
	FILE* f = fopen ( ten , chedo);
	
	if ( f == NULL ){
		printf("\nLoi mo file! ");
		exit(1);
	}
	return f;
} 

CauThu* DocFile (  FILE* f , int n ){
	
//	fscanf ( f ,"%d\n" , n);
	
	if ( n == NULL ){
		printf("\nLoi doc file!");
		exit(1);
	}
	
	CauThu* ct = (CauThu*) malloc ( n * sizeof(CauThu));
	
	if ( ct == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	
	for ( int i=0 ; i<n ; i++ ){
		fscanf( f ," %[^\n]s",&ct[i].ht);
		ct[i].ht[strcspn(ct[i].ht,"\n")]=0;
		
		fscanf( f ," %[^\n]s",&ct[i].mon);
		ct[i].mon[strcspn(ct[i].mon,"\n")]=0;
		
		fscanf ( f , "%f\n" ,&ct[i].diem);
		
		fscanf( f ," %[^\n]s",&ct[i].clb);
		ct[i].clb[strcspn(ct[i].clb,"\n")]=0;
	}
	printf("\nDa doc thanh cong du lieu trong tep");
	return ct;
}

void in(FILE* f, CauThu ct[] , int n ,const char tendanhsach[] ){
	fprintf(f,"\n%s\n",tendanhsach);
	fprintf(f,"\n%-5s %-30s %-10s %-10s %-20s",
	"STT","HO VA TEN","MON","DIEM","CAU LAC BO\n");
	
	for ( int i=0 ; i<n ; i++ ){
		fprintf(f,"\n%-5d %-30s %-10s %-10.2f %-20s\n",
		i+1,ct[i].ht,ct[i].mon,ct[i].diem,ct[i].clb);
	}
}
void ghi (FILE* f, CauThu ct[] ,int i ){
		fprintf(f,"\n%-5d %-30s %-10s %-10.2f %-20s\n",
		i+1,ct[i].ht,ct[i].mon,ct[i].diem,ct[i].clb);
}

void SapXepTheoMon(FILE* f , CauThu ct[] , int n , const char mon[] ){
	fprintf(f,"\nDANH SACH CAU THU MON %s\n",mon);
	for ( int i=0 ; i<n ; i++ ){
		if ( strcmp ( ct[i].mon,mon)==0){
			ghi(f,ct,i);
		}
	}
}

void ThongKe(FILE* f,CauThu ct[] , int n, const char tenclb[] ){
	int dem =0;
	for  (int i=0 ; i<n ; i++ ){
		if ( strcmp (ct[i].clb,tenclb )==0){
			dem++;
		}
	}
	if ( dem > 0){
		fprintf(f,"\nCo %d cau thu thuoc clb %s",dem,tenclb);
	}
	else {
		fprintf(f,"\nKhong co cau thu nao thuoc clb %s",tenclb);
	}
}

void ThongKe2 ( FILE* f , CauThu ct[] , int n ) {
	bool checkClass1 = false;
	bool checkClass2 = false;
	bool checkClass3 = false;
	
	fprintf(f,"\nDanh sach cau thu cua cau lac bo X\n");
	for ( int i=0 ; i<n ; i++){
		if ( strcmp ( ct[i].clb,"X")==0){
			checkClass1 = true;
			ghi(f,ct,i);
		}
	}
	if (!checkClass1){
		fprintf(f,"\nkhong co cau thu nao cua clb nay");
	}
	
	fprintf(f,"\nDanh sach cau thu cua cau lac bo Y\n");
	for ( int i=0 ; i<n ; i++){
		if ( strcmp ( ct[i].clb,"Y")==0){
			checkClass2 = true;
			ghi(f,ct,i);
		}
	}
	
	if (!checkClass2){
		fprintf(f,"\nkhong co cau thu nao cua clb nay");
	}
	
	fprintf(f,"\nDanh sach cau thu cua cau lac bo Z\n");
	for ( int i=0 ; i<n ; i++){
		if ( strcmp ( ct[i].clb,"Z")==0){
			checkClass3 = true;
			ghi(f,ct,i);
		}
	}
	if (!checkClass3){
		fprintf(f,"\nkhong co cau thu nao cua clb nay");
	}
	
}

void min (FILE* f,CauThu ct[] , int n){
	float min = ct[0].diem;
	for ( int i=0 ; i<n ; i++ ){
		if ( min > ct[i].diem ){
			min = ct[i].diem;
		}
	}

	fprintf(f,"\nCau thu co diem thap nhat\n");
	for ( int i=0 ; i<n ; i++ ){
		if ( ct[i].diem == min){
			ghi(f,ct,i);
		}
	}
}

int main(){
	int n;
	FILE* f = MoFile ("cau1de10.txt","r");
	fscanf ( f ,"%d\n" , &n);
	CauThu* ct = DocFile (f,n);
	fclose(f);
	
	FILE* F = MoFile ("outputcau1de10.txt","w");
	in (F,ct,n,"DANH SACH CAU THU");
	min (F,ct,n);
	ThongKe2(f,ct,n);
	SapXepTheoMon (F,ct,n,"A");
	SapXepTheoMon (F,ct,n,"B");
	SapXepTheoMon (F,ct,n,"C");
	ThongKe (F,ct,n,"X");
	ThongKe (F,ct,n,"Y");
	ThongKe (F,ct,n,"Z");
	fclose (f);
	free(ct);
}

