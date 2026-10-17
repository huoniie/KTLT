//-	Viet các hàm tính dien tích và chu vi hình tròn 
#include <stdio.h>
#include <math.h>
#define PI 3.14

void ChuVi_DienTichO( int R )
{
	float C=2*R*PI;
	float S= PI*pow(R,2); 
	printf("\nChu vi cua hinh tron la: %.2f",C);
	printf("\nDien tich cua hinh tron la: %.2f",S);
}

int main (){
	float r;
	printf("\nNhap ban kinh cua hinh tron: ");
	scanf("%f",&r);
	
	ChuVi_DienTichO(r);
}
