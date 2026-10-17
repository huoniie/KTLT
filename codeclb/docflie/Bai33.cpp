//lam bai 1 ket qua in ra file khac(ham)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* DocTep(FILE* f , int n)
{
	int* mang = (int*) malloc ( n*sizeof(int));
	for ( int i=0 ; i<n ; i++ )
	{
		fscanf(f,"%d",&mang[i]);
		printf(" %d",mang[i]);
	}
	return mang;
}

void GhiTep (FILE* F , int* mang , int n )
{
	for ( int i=0 ; i<n ; i++ )
	{
		fprintf(F," %d",mang[i]*2);
	}
}

int main()
{
	int n;
	FILE* f ;
	char tenf[30];
	printf("\nNhap ten tep: ");
	fgets( tenf , sizeof(tenf) , stdin );
	tenf[strcspn(tenf,"\n")]=0;
	
	f = fopen (tenf,"r");
	if ( f == NULL )
	{
		printf("\nFile loi khong mo duoc!");
		return 1;
	}
	fscanf(f,"%d\n",&n);
	int* mang = DocTep (f,n);
	printf("\nDoc thanh cong du lieu trong file.");
	fclose(f);
	
	FILE*F;
	char tenF[30];
	printf("\nNhap ten file ban muon luu ket qua: ");
	fgets ( tenF , sizeof(tenf) , stdin );
	tenF[strcspn(tenF,"\n")]=0;
	
	F = fopen ( tenF ,"w");
	if ( F == NULL )
	{
		printf("\nFlie bi loi khong mo duoc: ");
		return 1;
	}
	
	GhiTep(F,mang,n);
	printf("\nDa ghi ket qua vao file %s",tenF);
	fclose(F);
	
	free(mang);
}
