#include <stdio.h>
#include <string.h>
  
typedef struct{
	char name[30];
	float toan , ly , hoa;
	float tong;
}ThiSinh;

int main()
{
	int n;
	printf("Nhap so luong thi sinh : ");
	scanf("%d",&n);
	ThiSinh a[n];
	
	for ( int i=0 ; i<n ; i++ )
	{
		printf("\nThi sinh %d",i+1);
		getchar();
		printf("\nNhap ten: ");
		fgets(a[i].name,30,stdin);
		a[i].name[strcspn(a[i].name,"\n")]=0;
		
		printf("Nhap diem toan: ");
		scanf("%f",&a[i].toan);
		
		printf("Nhap diem ly: ");
		scanf("%f",&a[i].ly);
		
		printf("Nhap diem toan: ");
		scanf("%f",&a[i].hoa);
		
		a[i].tong=a[i].toan + a[i].ly + a[i].hoa;
		printf("diem chuan: %.2f " , a[i].tong);
		
	}
	
	
//	
//	for ( int i=0 ; i<n ; i++ )
//	{
//		printf("\nThi sinh %d",i+1);
//		printf("\nNhap ten: %s",a[i].name);
//		
//		printf("\ndiem toan: %.2f",a[i].toan);
//		
//		printf("\ndiem ly: %.2f" , a[i].ly);
//		
//		printf("\ndiem hoa: %.2f " , a[i].hoa);
//		
//		printf("\ndiem chuan: %.2f " , a[i].tong);
//	}
// Sap xep theo tong diem chuan
  
	
	for ( int i=0 ; i<n ; i++ )
	{
		for ( int j=1 ; j<n ; j++ )
		{
		if (a[j].tong >= a[i].tong){
			float x = a[i].tong;
			a[i].tong = a[j].tong;
			a[j].tong = x ;
		    }
		}
	}
	printf("\nDanh sach thi sinh tren diem chuan");
	float chuan;
	printf("\nNhap diem chuan: ");
	scanf("%f",&chuan);
	
	for ( int i=0 ; i<n ; i++ ){
		if (a[i].tong>=chuan){
			printf("\n%s %.2f %.2f %.2f",a[i].name,a[i].toan,a[i].ly,a[i].hoa,a[i].tong);
		}
	}
	
}
