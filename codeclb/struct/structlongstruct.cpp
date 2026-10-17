//Quan ly sinh vien bang struct trong struct va file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int day;
	int month;
	int year;
}Date;

typedef struct {
	int msv;
	char name[30];
	float diem;
	Date a;
}SinhVien;

SinhVien* read ( FILE* f , int n )
{
	SinhVien* sv = ( SinhVien* ) malloc ( n * sizeof ( SinhVien ));
	printf("\n=====Danh sach sinh vien======\n");
	printf("%-3s %-15s %-30s %-5s %-10s","STT","MA SINH VIEN","HO VA TEN","DIEM","NGAY SINH");
	for ( int i=0 ; i<n ; i++ )
	{
		fscanf(f,"%d\n",&sv[i].msv);
		fgets(sv[i].name, sizeof(sv[i].name), f);
		sv[i].name[strcspn (sv[i].name,"\n")]=0;
		fscanf(f,"%f\n",&sv[i].diem);
		fscanf(f,"%d %d %d \n",&sv[i].a.day,&sv[i].a.month,&sv[i].a.year);
		printf("\n%-3d %-15d %-30s %5.2f %02d/%02d/%d ",
		i+1,sv[i].msv,sv[i].name,sv[i].diem,
		sv[i].a.day,sv[i].a.month,sv[i].a.year);
	}
	printf("\nDa thanh cong doc thong tin sinh vien trong file.");
	return sv;
}

void lookfor( FILE* F , SinhVien* sv , int n)
{
	float max = sv[0].diem;
	for ( int i=0 ; i<n ; i++ )
	{
		if ( max < sv[i].diem)
		{
			max = sv[i].diem;
		}
	}
	fprintf(F,"\n=====Sinh vien co diem cao nhat=====\n");
    fprintf(F,"%-3s %-15s %-30s %-5s %-10s","STT","MA SINH VIEN","HO VA TEN","DIEM","NGAY SINH");
    
    int dem = 0;
    for (int i = 0; i < n; i++) 
	{
        if (sv[i].diem == max) 
		{
            fprintf(F,"\n%-3d %-15d %-30s %5.2f %02d/%02d/%d",
			i+1,sv[i].msv,sv[i].name,sv[i].diem,
			sv[i].a.day,sv[i].a.month,sv[i].a.year);
            dem++;
        }
    }
    fprintf(F,"\nCo %d sinh vien dat diem cao nhat.", dem);
}

void in ( 	SinhVien* sv , int n)
{
	printf("\n=====Danh sach sinh vien======\n");
	printf("%-3s %-15s %-30s %-5s %-10s","STT","MA SINH VIEN","HO VA TEN","DIEM","NGAY SINH");
	for ( int i=0 ; i<n ; i++ )
	{
		printf("\n%-3d %-15d %-30s %5.2f %02d/%02d/%d ",
		i+1,sv[i].msv,sv[i].name,sv[i].diem,
		sv[i].a.day,sv[i].a.month,sv[i].a.year);
	}
}

int main()
{
	FILE* f ;
	char tenf[30];
	printf("\nNhap ten file: ");
	fgets (tenf,sizeof(tenf),stdin);
	tenf[strcspn(tenf,"\n")]=0;
	
	f = fopen ( tenf , "r" );
	if ( f == NULL )
	{
		printf("\nLoi mo file!");
		return 1;
	}
	
	int n;
	fscanf(f,"%d",&n);
	SinhVien* sv = read (f,n);
	in (sv,n);
	fclose(f);
	
	FILE* F;
	char tenF[30];
	printf("\nNhap ten file: ");
	fgets (tenF,sizeof(tenF),stdin);
	tenF[strcspn(tenF,"\n")]=0;
	
	F = fopen ( tenF , "w" );
	if ( F == NULL )
	{
		printf("\nLoi mo file!");
		return 1;
	}
	lookfor(F,sv,n);
	printf("\nDa gi thanh cong danh sach sinh vien co diem cao nhat vao file %s",tenF);
	fclose(F);
	free(sv);	
}
