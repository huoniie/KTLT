//Xây d?ng chuong trình qu?n lý danh sách sinh viên 
//g?m các thông tin: MaSV, HoTen, DiemTB.
//Nh?p danh sách n sinh viên t? bàn phím.
//Th?c hi?n các yêu c?u sau:
//In danh sách sinh viên v?a nh?p ra màn hình.
//S?p x?p danh sách theo DiemTB gi?m d?n và in l?i danh sách.
//Tìm và in thông tin sinh viên có DiemTB cao nh?t.
//Tìm và in danh sách sinh viên có DiemTB >= 8.0 (sinh viên gi?i).
//Ghi danh sách sinh viên ra t?p sinhvien.txt.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int msv;
	char ht[30];
	float diemtb;
}SinhVien;

void in (SinhVien sv[] , int i ){
		printf("\n%-5d %-15d %-30s %-15.2f",
		i+1,sv[i].msv,sv[i].ht,sv[i].diemtb);
}

SinhVien* nhap ( int n ){
	
	SinhVien* sv = ( SinhVien* ) malloc ( n* sizeof ( SinhVien ));
	if ( sv == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	printf("\n===============NHAP THONG TIN SINH VIEN============\n");
	for ( int i=0 ; i<n ; i++ ){
		printf("\nSinh vien %d ", i+1);
		
		printf("\nMa sinh vien: ");
		scanf("%d",&sv[i].msv);
		getchar();
		
		printf("\nHo va ten: ");
		scanf("%[^\n]s",&sv[i].ht);
		sv[i].ht[strcspn(sv[i].ht,"\n")]=0;
		
		printf("\nDiem trung binh: ");
		scanf("%f",&sv[i].diemtb);
	}
	for ( int i=0 ; i<n ; i++ ){
		in ( sv,i);
	}
	return sv;
}

//void in (SinhVien sv[] , int i ){
//		printf("%-5d %-15d %-30s %-15.2f",
//		i+1,sv[i].msv,sv[i].ht,sv[i].diemtb);
//}

void SapXep ( SinhVien sv[] ,int n ){
	for ( int i=0 ; i<n-1 ; i++ ){
		int key = i;
		for ( int j = i+1 ; j<n ; j++ ){
			if ( sv[key].diemtb < sv[j].diemtb){
				key = j;
			}
		}
		if ( key!=i){
			SinhVien temp = sv[key];
			sv[key]= sv[i];
			sv[i]= temp;
		}
	}
	printf("\n==================DANH SACH SINH VIEN SAU KHI SAP XEP ( giam dan )====================");
	for ( int i=0 ; i<n ; i++ ){
		in(sv,i);
	}
}

void DiemCaoNhat ( SinhVien sv[] , int n){
	float max = sv[0].diemtb;
	int viTri = 0;
	for ( int i=0 ; i<n ; i++ ){
		if ( max < sv[i].diemtb){
			max = sv[i].diemtb;
			viTri = i;
		}
	}
	printf("\nSinh vien co diem trung binh cao nhat la: \n");
	in(sv,viTri);
}

void SinhVienGioi ( SinhVien sv[] , int n){
	printf("\n==========DANH SACH SINH VIEN GIOI==============\n");
	for ( int i=0 ; i<n ; i++ ){
		if ( sv[i].diemtb>=8.0){
			in(sv,i);
		}
	}
}

void ghi (SinhVien sv[] , int n){
	FILE* f = fopen ( "cau2de11sinhvien.txt","w");
	
	if ( f == NULL ){
		printf("\nLoi mo file!");
		exit(1);
	}
	for (int i=0 ; i<n ; i++ ){
		fprintf(f,"\n%-5d %-15d %-30s %-15.2f",
		i+1,sv[i].msv,sv[i].ht,sv[i].diemtb);
	}
	printf("\nDa ghi thanh cong danh sach sinh vien vao cau2de11sinhvien.txt");
	fclose(f);
}

int main (){
	int n;
	do {
		printf("\nNhap so luong sinh vien: ");
		scanf("%d",&n);
	}while (n<=0);
	
	SinhVien* sv = nhap(n);
	SapXep (sv,n);
	DiemCaoNhat ( sv,n);
	SinhVienGioi(sv,n);
	ghi(sv,n);
	free(sv);
	
}
