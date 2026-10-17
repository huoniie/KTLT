//Xây d?ng chuong trình qu?n lý don hàng linh ki?n máy tính s? d?ng struct,
// con tr?, hàm, c?p phát d?ng và file. Khai báo c?u trúc DonHang g?m:
//  mã don hàng, tên khách hàng, tên s?n ph?m, s? lu?ng, don giá, thành ti?n. 
//  Th?c hi?n các ch?c nang sau: nh?p danh sách n don hàng b?ng c?p phát d?ng, 
//  tính thành ti?n theo công th?c:
//
//ThanhTien=SoLuong×DonGia

//1.ghi danh sách don hàng vào file donhang.txt 
//d?c d? li?u t? file và hi?n th? ra màn hình
//2.tìm don hàng có thành ti?n l?n nh?t, tính t?ng doanh thu
//3.s?p x?p danh sách gi?m d?n theo thành ti?n
//4. ghi các don hàng có thành ti?n trên 50 tri?u vào file vip.txt

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
	int mdh;
	char tenkh[50];
	char tensp[50];
	int sl;
	float gia;
	float thanhtien ;
}DonHang;


DonHang* nhap(int* n ){
	printf("\nNhap so luong don hang: ");
	scanf("%d",n);
	
	DonHang* dh = (DonHang*) malloc ( *n * sizeof(DonHang));
	if ( dh == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	
	for ( int i=0 ; i<*n ; i++ ){
		printf("\nma don hang: ");
		scanf("%d",&dh[i].mdh);
		
		getchar();
		printf("ten khach hang: ");
		fgets(dh[i].tenkh,sizeof(dh[i].tenkh),stdin);
		dh[i].tenkh[strcspn(dh[i].tenkh,"\n")]=0;

		printf("ten san pham: ");
		fgets(dh[i].tensp,sizeof(dh[i].tensp),stdin);
		dh[i].tensp[strcspn(dh[i].tensp,"\n")]=0;
		
		printf("so luong: ");
		scanf("%d",&dh[i].sl);
		
		printf("Don gia: ");
		scanf("%f",&dh[i].gia);
		dh[i].thanhtien = dh[i].sl*dh[i].gia;
		printf("%.3f",dh[i].thanhtien);
	}
	return dh;
}


void ghi (DonHang* dh , int* n ){
	FILE* f = fopen("donhang.txt", "w");
    if (f == NULL) {
        printf("\nLoi tao file donhang.txt!");
        return;
    } 
    
    
	float tong = 0;
	int max=0;
	fprintf(f,"\n=====DANH SACH DON HANG======\n");
	fprintf(f,"\n%-5s %-15s %-30s %-30s %-10s %-10s %-15s" , 
	"STT","MA SAN PHAM","TEN KHACH HANG","TEN SAN PHAM","SO LUONG","DON GIA","THANH TIEN");
	for ( int i=0 ; i<*n ; i++ ){
		fprintf(f,"\n%-5d %-15d %-30s %-30s %-10d %-10.3f %-15.3f",i+1,
		dh[i].mdh , dh[i].tenkh,dh[i].tensp,dh[i].sl,dh[i].gia,dh[i].thanhtien); 
		tong+= dh[i].thanhtien;
		if (dh[i].thanhtien > dh[max].thanhtien) {
            max = i;
        }
	} 
	getchar();
	fprintf(f,"\nDon hang co gia tri lon nhat la don hang: %d voi tri gia %.3f",max+1,dh[max].thanhtien);
	fprintf ( f,"\nTong doanh thu cua %d don hang: %.3f",*n,tong);
	printf("\nda ghi thanh cong don hang vao file donhang.txt");
	
	
	
	
	printf("\n=====DANH SACH DON HANG======\n");
	printf("\n%-5s %-15s %-30s %-30s %-10s %-10s %-15s" , 
	"STT","MA SAN PHAM","TEN KHACH HANG","TEN SAN PHAM","SO LUONG","DON GIA","THANH TIEN");
	for ( int i=0 ; i<*n ; i++ ){
		printf("\n%-5d %-15d %-30s %-30s %-10d %-10.3f %-15.3f",i+1,
		dh[i].mdh , dh[i].tenkh,dh[i].tensp,dh[i].sl,dh[i].gia,dh[i].thanhtien); 
	}
	printf("\nDon hang co gia tri lon nhat la don hang: %d voi tri gia %.3f",max+1,dh[max].thanhtien);
	printf ( "\nTong doanh thu cua %d don hang: %.3f",*n,tong);
	fclose(f);
}

void sapxep ( DonHang* dh , int* n){
	
	for ( int i=0 ; i<*n ; i++ ){
		int key=i;
		for ( int j = i+1 ; j<*n ; j++ ){
			if ( dh[i].thanhtien > dh[j].thanhtien ){
				key =j;
			}
		}
		if (key!=i){
			DonHang temp = dh[i];
			dh[i]=dh[key];
			dh[key]=temp;
		}
	}
	for ( int i=0 ; i<*n ; i++ ){
		printf("\n%-5d %-15d %-30s %-30s %-10d %-10.3f %-15.3f",i+1,
		dh[i].mdh , dh[i].tenkh,dh[i].tensp,dh[i].sl,dh[i].gia,dh[i].thanhtien); 
	} 
	FILE* f = fopen("vip.txt", "w");
    if (f == NULL) {
    	printf("\nLoi mo file vip.txt");
    	return ;
	}
	fprintf(f,"\n=====DANH SACH DON HANG(giam dan)======\n");
	fprintf(f,"\n%-5s %-15s %-30s %-30s %-10s %-10s %-15s" , 
	"STT","MA SAN PHAM","TEN KHACH HANG","TEN SAN PHAM","SO LUONG","DON GIA","THANH TIEN");
	
	for ( int i=0 ; i<*n ; i++ ){
		if ( dh[i].thanhtien >= 50000){
		fprintf(f,"\n%-5d %-15d %-30s %-30s %-10d %-10.3f %-15.3f",i+1,
		dh[i].mdh , dh[i].tenkh,dh[i].tensp,dh[i].sl,dh[i].gia,dh[i].thanhtien); 
		}
	}

	fclose(f);
}


int main(){
	int n;
	DonHang* dh = nhap(&n);
	ghi(dh,&n);
	sapxep(dh,&n);
	free(dh);
}


