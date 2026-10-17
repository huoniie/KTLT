/*Struct sv (ten diem mSv) doc tu file 
Tim sv có diemm cao thu 2
Tim sv có diem gan trung binh nh?t
In kett qua ra file*/


#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

typedef struct {
	char ten[30];
	float diem;
	int msv;
}SinhVien;

SinhVien* read( FILE* f , int n)
{
	SinhVien* sv = ( SinhVien* ) malloc ( n * sizeof ( SinhVien ));
	printf("\n=====DANH SACH SINH VIEN=====\n");
	printf("%-5s %-30s %-5s %-10s","STT","HO VA TEN","DIEM","MA SINH VIEN");
	for ( int i=0 ; i<n ; i++ )
	{
		fgets ( sv[i].ten , sizeof(sv[i].ten ),f);
		sv[i].ten[ strcspn ( sv[i].ten , "\n")]=0;
		
		fscanf( f , "%f\n" , &sv[i].diem );
		fscanf( f , "%d\n" , &sv[i].msv );
		printf("\n%-5d %-30s %-5.2f %-10d",i+1,sv[i].ten,sv[i].diem,sv[i].msv);
	}
	return sv;
}

void result ( FILE* F , SinhVien* sv , int n)
{
	fprintf(F,"\n========KET QUA===========\n");
	float max = sv[0].diem;
	float tong = 0;
	
	for ( int i=0 ; i<n ; i++ ){
		tong += sv[i].diem;
		if ( max < sv[i].diem ) 
		{
			max = sv[i].diem;
		}
	}
	float tb = tong / n;
	
    float max2 = -1; 
    int coMax2 = 0;
    for (int i = 0; i < n; i++) 
	{
        if (sv[i].diem < max) 
		{
            if (!coMax2 || sv[i].diem > max2) 
			{
                max2 = sv[i].diem;
                coMax2 = 1;
            }
        }
    }

    float min = fabs(sv[0].diem - tb);
    for (int i = 1; i < n; i++) {
        if (fabs(sv[i].diem - tb) < min) {
            min = fabs(sv[i].diem - tb);
        }
    }
    fprintf(F, "Diem trung binh lop: %.2f\n", tb);

    if (coMax2) {
        fprintf(F, "\nSinh vien co diem cao thu hai.\n");
        for (int i = 0; i < n; i++) {
            if (sv[i].diem == max2) {
                fprintf(F,"\n%-30s %-5.2f %-10d",sv[i].ten,sv[i].diem,sv[i].msv);
            }
        }
    } else {
        fprintf(F, "\nKhong co sinh vien diem cao thu hai.\n");
    }

    fprintf(F, "\nSinh vien co diem gan trung binh nhat (cach %.2f diem):\n", min);
    for (int i = 0; i < n; i++) {
        if (fabs(fabs(sv[i].diem - tb) - min) < 0.0001) { 
            fprintf(F,"\n%-30s %-5.2f %-10d",sv[i].ten,sv[i].diem,sv[i].msv);
        }
    }
}


int main ()
{
	FILE* f;
	char tenf[30];
	printf("\nNhap ten file: ");
	fgets( tenf , sizeof(tenf),stdin);
	tenf[strcspn(tenf,"\n")]=0;
	
	f = fopen ( tenf ,"r");
	if ( f == NULL ){
		printf("\nLoi mo file! ");
		return 1;
	}
	
	int n;
	fscanf(f,"%d\n",&n);
	SinhVien* sv = read (f,n);
	printf("\nDa hoan thanh doc file.");
	fclose(f);
	
	FILE* F;
	char tenF[30];
	printf("\nNhap ten file: ");
	fgets( tenF , sizeof(tenF),stdin);
	tenF[strcspn(tenF,"\n")]=0;
	
	F = fopen ( tenF ,"w");
	if ( F == NULL ){
		printf("\nLoi mo file! ");
		return 1;
	}
	result (F,sv,n);
	printf("\nDa ghi thanh cong ket qua vao file %s",tenF);
	fclose(F);
	free(sv);
	return 0 ;
	
}
