#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	char* name;
	char gioi_tinh[10];
	float gpa;
}SinhVien;
void nhap(int n , SinhVien* s){
	for ( int i=0 ; i<n ; i++ ){
		s[i].name = ( char* ) malloc ( 30* sizeof (char ) );
		
		printf("\nSinh vien %d ", i + 1 );
		getchar();
		
		printf("\nNhap ten: ");
		fgets(s[i].name , 30 , stdin );
		s[i].name [strcspn (s[i].name,"\n")]=0;
		
		printf("Nhap gioi tinh: ");
		fgets(s[i].gioi_tinh , 30 , stdin );
		s[i].gioi_tinh [strcspn (s[i].gioi_tinh,"\n")]=0;
		
		printf("Nhap gpa: ");
		scanf( "%f",&s[i].gpa );
	} 
	
}

void sua( SinhVien* s_copy ){
	int i;
	printf("\nNhap stt muon sua: ");
	scanf("%d",&i);
	int vitri=i-1;
	
		printf("\nSinh vien %d ", i );
		getchar();
		
		printf("\nNhap ten: ");
		fgets(s_copy[vitri].name , 30 , stdin );
		s_copy[vitri].name [strcspn (s_copy[vitri].name,"\n")]=0;
		
		printf("Nhap gioi tinh: ");
		fgets(s_copy[vitri].gioi_tinh , 30 , stdin );
		s_copy[vitri].gioi_tinh [strcspn (s_copy[vitri].gioi_tinh,"\n")]=0;
		
		printf("Nhap gpa: ");
		scanf( "%f",&s_copy[vitri].gpa );
		
}

void copy_mang(SinhVien* a, SinhVien* b, int n) {
    for (int i = 0; i < n; i++) {
        b[i].gpa = a[i].gpa;
        strcpy(b[i].gioi_tinh, a[i].gioi_tinh);
        
        b[i].name = (char*)malloc(30 * sizeof(char));
        strcpy(b[i].name, a[i].name);//dich,nguon
    }
}

void in ( SinhVien* s , int n ){
	for ( int i=0 ; i<n ; i++ ){
		printf("\nSinh vien %d ", i + 1 );
		printf("\nten: %s ",s[i].name);
		printf("\gioi tinh: %s ",s[i].gioi_tinh);
		printf("\ngpa: %.2f",s[i].gpa);
	}
}

int main(){
	int n;
	printf("\nNhap so luong sinh vien: ");
	scanf("%d",&n);
	SinhVien* S = (SinhVien*)malloc(n * sizeof(SinhVien));
    SinhVien* S_copy = (SinhVien*)malloc(n * sizeof(SinhVien));
    
    nhap(n,S);
    copy_mang(S, S_copy, n);
    sua(S_copy);
    in(S,n);
    in(S_copy,n);
}
