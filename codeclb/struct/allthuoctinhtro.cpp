#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char* name;
	int* tuoi;
	char* gioi_tinh;
	float* diem;
	char* lop;
} student;

student* nhap(int n) {
	student* sv = (student*) malloc(n * sizeof(student));
	for (int i = 0; i < n; i++) {
		sv[i].name = (char*) malloc(30 * sizeof(char));
		sv[i].tuoi = (int*) malloc(sizeof(int));
		sv[i].gioi_tinh = (char*) malloc(10 * sizeof(char));
		sv[i].diem = (float*) malloc(sizeof(float));
		sv[i].lop = (char*) malloc(10 * sizeof(char));
		
		printf("\nHoc sinh %d", i + 1); 		
		printf("\nNhap ten: ");
		fgets(sv[i].name, 30, stdin);
		sv[i].name[strcspn(sv[i].name, "\n")] = 0;
		
		printf("Nhap tuoi: ");
		scanf("%d", sv[i].tuoi);
		getchar(); 
		
		printf("Nhap gioi tinh: ");
		fgets(sv[i].gioi_tinh, 10, stdin);
		sv[i].gioi_tinh[strcspn(sv[i].gioi_tinh, "\n")] = 0;
		
		printf("Nhap diem: ");
		scanf("%f", sv[i].diem);
		getchar();
		
		printf("Nhap lop: ");
		fgets(sv[i].lop, 10, stdin);
		sv[i].lop[strcspn(sv[i].lop, "\n")] = 0;
	}
	return sv;
}

void sua(student* sv , int n ){
	int i;
	printf("\nNhap thu tu sinh vien muon sua: ");
	scanf("%d",&i);
	int vitri=i-1;
		getchar();
	    printf("\nNhap ten: ");
		fgets(sv[vitri].name, 30, stdin);
		sv[vitri].name[strcspn(sv[vitri].name, "\n")] = 0;
		
		printf("Nhap tuoi: ");
		scanf("%d", sv[vitri].tuoi);
		getchar(); 
		
		printf("Nhap gioi tinh: ");
		fgets(sv[vitri].gioi_tinh, 10, stdin);
		sv[vitri].gioi_tinh[strcspn(sv[vitri].gioi_tinh, "\n")] = 0;
		
		printf("Nhap diem: ");
		scanf("%f", sv[vitri].diem);
		getchar();
		
		printf("Nhap lop: ");
		fgets(sv[vitri].lop, 10, stdin);
		sv[vitri].lop[strcspn(sv[vitri].lop, "\n")] = 0;
}

void in(student* sv, int n) {
	for (int i = 0; i < n; i++) {
		printf("\nHoc sinh %d: ", i + 1); 
		printf("\nten: %s", sv[i].name);
		printf("\ntuoi: %d", *sv[i].tuoi); 
		printf("\ngioi tinh: %s", sv[i].gioi_tinh);
		printf("\ndiem: %.2f", *sv[i].diem);
		printf("\nlop: %s", sv[i].lop);
	}
}

int main() {
	int n;
	printf("Nhap so luong hoc sinh: ");
	scanf("%d", &n);
	getchar(); 
	student* SV = nhap(n);
	in(SV, n);
	sua(SV,n);
	in(SV,n);
	return 0;
}
