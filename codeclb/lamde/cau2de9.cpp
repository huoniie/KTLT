#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char msv[20];
	char ten[50];
	char lop[20];
	float diem;
	int tc;
}SinhVien;

FILE* MoFile (){
	char ten[30];
	char chedo[50];
	printf("\nNhap ten tep: ");
	scanf(" %[^\n]s",ten);
	ten[strcspn(ten,"\n")]=0;
	
	printf("\nNhap che do muon su dung: ");
    scanf(" %s", chedo);
	
	FILE* f = fopen ( ten , chedo );
	
	if ( f == NULL ){
		printf("\nLoi mo tep: ");
		exit(1);
	}
	return f;
}

SinhVien* doc ( int *n ){
	FILE* f = MoFile();
	
	fscanf (f,"%d\n",n);
	
	SinhVien* sv = (SinhVien*) malloc (* n * sizeof (SinhVien));
	
	if ( sv == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	
	for ( int i=0 ; i<*n ; i++ ){
		fgets ( sv[i].msv , sizeof ( sv[i].msv ), f);
		sv[i].msv[strcspn(sv[i].msv,"\n")]=0;
		
		fgets ( sv[i].ten , sizeof ( sv[i].ten ), f);
		sv[i].ten[strcspn(sv[i].ten,"\n")]=0;
		
		fgets ( sv[i].lop , sizeof ( sv[i].lop ), f);
		sv[i].lop[strcspn(sv[i].lop,"\n")]=0;
		
		fscanf(f,"%f\n",&sv[i].diem);
		fscanf(f,"%d\n",&sv[i].tc);
		
	}
	fclose(f);
	return sv;
}

void ghi( SinhVien* sv , int n ){
	FILE* f = MoFile();
	fprintf (f, "\n===========DANH SACH SINH VIEN============\n");
	fprintf(f,"\n%-5s %-15s %-30s %-15s %-10s %-10s",
	"STT","MA SINH VIEN","HO VA TEN","LOP","DIEM TB","SO TIN CHI");
	
	int dem1=0;
	int dem2=0;
	int dem3=0;
	
	float max = sv[0].diem;
	
	for ( int i=0 ; i<n ; i++ ){
		if ( max < sv[i].diem ){
			max = sv[i].diem;
		}
		fprintf(f,"\n%-5d %-15s %-30s %-15s %-10.2f %-10d",
		i+1,sv[i].msv,sv[i].ten,sv[i].lop,sv[i].diem,sv[i].tc);
		if (strcmp(sv[i].lop,"CNTT1")==0){
			dem1++;
		}
		if (strcmp(sv[i].lop,"CNTT2")==0){
			dem2++;
		}
		if (strcmp(sv[i].lop,"CNTT3")==0){
			dem3++;
		}
	}
	if ( dem1 >0 ){
	fprintf(f,"\nCo %d sinh vien lop CNTT1.",dem1);
	}
	else{
		fprintf(f,"\nKhong co sinh vien lop CNTT1.");
	}
	
	
	if ( dem2 >0 ){
	fprintf(f,"\nCo %d sinh vien lop CNTT2.",dem2);
	}
	else{
		fprintf(f,"\nKhong co sinh vien lop CNTT2.");
	}
	
	
	if ( dem3>0 ){
	fprintf(f,"\nCo %d sinh vien lop CNTT3.",dem3);
	}
	else{
		fprintf(f,"\nKhong co sinh vien lop CNTT3.");
	}
	fprintf(f,"\nDiem trung binh cao nhat la: %.2f",max);
	fclose(f);
}


void SV100TC ( SinhVien* sv , int n){
	FILE* f = MoFile();
	fprintf (f, "\n===========DANH SACH SINH VIEN CO SO TIN CHI TREN 100============\n");
	fprintf(f,"\n%-5s %-15s %-30s %-15s %-10s %-10s",
	"STT","MA SINH VIEN","HO VA TEN","LOP","DIEM TB","SO TIN CHI");
	for ( int i=0 ; i<n ; i++ ){
		if ( sv[i].tc >= 100){
			fprintf(f,"\n%-5d %-15s %-30s %-15s %-10.2f %-10d",
			i+1,sv[i].msv,sv[i].ten,sv[i].lop,sv[i].diem,sv[i].tc);
		}
	}
	fclose(f);
	
}


int main(){
	int n;
	
	SinhVien* sv = doc (&n);
	ghi(sv,n);
	SV100TC(sv,n);
	
	free(sv);
	
	
}
