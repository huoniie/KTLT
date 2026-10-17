//bài 2 Quan ly sinh viên(ma , ten ,diem ) nhap in, find theo diem

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int msv;
	char name[30];
	float diem;
}SinhVien;


SinhVien* nhap ( int n)
{
	SinhVien* sv = ( SinhVien* ) malloc ( n * sizeof ( SinhVien ));
	printf("\n=====Nhap thong tin sinh vien.=====\n");
	for ( int i=0 ; i<n ; i++ )
	{
		printf("\nSinh vien %d: ",i+1);
		
		printf("\nNhap ma sinh vien: ");
		scanf("%d",&sv[i].msv);
		
		getchar();
		printf("Nhap ho va ten: ");
		fgets ( sv[i].name , sizeof(sv[i].name), stdin);
		sv[i].name[strcspn ( sv[i].name , "\n" )]=0;
		
		printf("Nhap diem(thang 10): ");
		scanf("%f",&sv[i].diem);
		
	}
	return sv;
}

void in ( SinhVien* sv , int n )
{
	printf("\n=====Danh sach sinh vien======\n");
	printf("%-3s %-15s %-30s %-5s ","STT","MA SINH VIEN","HO VA TEN","DIEM");
	for ( int i=0 ; i<n ; i++ )
	{
		printf("\n%-3d %-15d %-30s %5.2f ",i+1,sv[i].msv,sv[i].name,sv[i].diem);
	}
}

void lookfor ( SinhVien* sv , int n )
{
	float x ;
	printf("\nNhap diem ban muon tim kiem: ");
	scanf ("%f",&x);
	int kt=0;
	for ( int i=0 ; i<n ; i++ )
	{
		if (  sv[i].diem == x )
		{
			printf("\n%-3d %-15d %-30s %5.2f ",i+1,sv[i].msv,sv[i].name,sv[i].diem);
			kt=1;
		}
		
	}
	if (kt==0){
		printf("\nKhong co sinh vien nao co so diem nhu vay.");
	}
}

int main()
{
	int n;
	printf("\nNhap so luong sinh vien: ");
	scanf("%d",&n);
	if ( n<=0 || n>1000)
	{
		printf("\nSo luong khong hop le!");
		return 1;
	}
	
	SinhVien* sv = nhap (n);
	in(sv,n);
	lookfor (sv,n);
	free(sv);
	
	return 0;
}
