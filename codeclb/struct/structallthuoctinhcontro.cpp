#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	char* name;
	int* tuoi;
	char* gioi_tinh;
	float* diem;
	char* lop;
}student;
student* nhap( int n ){
	student* sv = (student*) malloc ( n* sizeof(student));
	for ( int i=0 ; i<n ; i++ ){
		sv[i].name = (char*) malloc(30 * sizeof(char));
        sv[i].tuoi = (int*) malloc(sizeof(int));
        sv[i].gioi_tinh = (char*) malloc(10 * sizeof(char));
        sv[i].diem = (float*) malloc(sizeof(float));
        sv[i].lop = (char*) malloc(10 * sizeof(char));
		printf("\nHoc sinh %d ", n );
		printf("\nNhap ten: ");
		fgets(sv[i].name,30,stdin);
		sv[i].name[strcspn(sv[i].name, "\n")] = 0;
		printf("Nhap tuoi: ");
		scanf("%d",sv[i].tuoi);
		getchar();
		printf("\nNhap gioi tinh: ");
		fgets(sv[i].gioi_tinh,30,stdin);
		sv[i].gioi_tinh[strcspn(sv[i].gioi_tinh, "\n")] = 0;
		printf("\nNhap diem: ");
		getchar();
		scanf("%f",sv[i].diem);
		printf("\nNhap lop: ");
		fgets(sv[i].lop,30,stdin);
		sv[i].lop[strcspn(sv[i].lop, "\n")] = 0;
		
	}
	return sv;
}
void in( student* sv , int n){
	for ( int i=0 ; i<n ; i++ ){
		printf("\nHoc sinh %d ", n );
		printf("\nten: %s ",sv[i].name);
		printf("tuoi: %d",*sv[i].tuoi);
		printf("\ngioi tinh:%s ",sv[i].gioi_tinh);
		printf("\ndiem: %.2f",*sv[i].diem);
		printf("\nlop: %s",sv[i].lop);
	}
}
int main(){
	int n;
	printf("\nNhap so luong hoc sinh: ");
	scanf("%d",&n);
	student* SV = nhap(n);
	in(SV,n);
}
