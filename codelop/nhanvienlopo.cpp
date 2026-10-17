#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int day;
	int month;
	int year;
}Date;

typedef struct{
	char name [30];
	Date a;
	float luong;
	
}NhanVien;

NhanVien* nhap( int n)
{
	NhanVien* nv = (NhanVien*) malloc ( n* sizeof (NhanVien));
	for ( int i=0 ; i<n ; i++ )
	{
		printf("\nNhap ten: ");
		fgets ( nv[i].name , sizeof (nv[i].name) , stdin );
		nv[i].name[strcspn ( nv[i].name , "\n")]=0;
		
		
		printf("\nNhap ngay sinh: ");
		scanf("%d%d%d",&nv[i].a.day,&nv[i].a.month,&nv[i].a.year);
		
		printf("\nNhap luong: ");
		scanf( "%f",&nv[i].luong);
	}
	return nv;
}

void in(NhanVien* nv , int n)
{
	printf("\n=====DANH SACH NHAN VIEN======\n");
	printf("%-3s %-30s %-15s %-10s","STT","HO VA TEN","NGAY SINH","LUONG");
	for ( int i=0 ; i<n ; i++ )
	{
		printf("%-3d %-30s %-02d/%-02d/%d %-10.2f",)
	}
}
