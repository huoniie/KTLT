#include <stdio.h>
#include <string.h>
typedef struct {
	char name[30];
	float diem;
	char lop[10];
}student;
void nhap(student* sv  ){
		printf("\nNhap ten: ");
		fgets(sv->name, 30, stdin);
		sv->name[strcspn(sv->name, "\n")] = 0;
		printf("Nhap diem: ");
		scanf("%f",&sv->diem);
		getchar();
		printf("Nhap lop: ");
		fgets(sv->lop, 10, stdin);
		sv->lop[strcspn(sv->lop, "\n")] = 0; 
}
void sua(student* sv){
		printf("\nNhap ten: ");
		fgets(sv->name, 30, stdin);
		sv->name[strcspn(sv->name, "\n")] = 0;
		printf("Nhap diem: ");
		scanf("%f",&sv->diem);
		getchar();
		printf("Nhap lop: ");
		fgets(sv->lop, 10, stdin);
		sv->lop[strcspn(sv->lop, "\n")] = 0; 
}
void in(student sv ){
		printf("\nNhap ten: %s ",sv.name);
		printf("\nNhap diem:%.2f ",sv.diem);
		printf("\nNhap lop: %s",sv.lop);
}
int main(){
	student sv;
	nhap(&sv);
	in(sv);
	printf("\nSua lai het thong tin cho tao");
	sua(&sv);
	in(sv);
}
