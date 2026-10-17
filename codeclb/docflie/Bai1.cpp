/*Bai 1 Nhap tu file gom n phan tu .
Roi ghi vao file nhap ket qua
voi gia tri gap doi ban dau*/

#include <stdio.h>
#include <string.h>

int main()
{
	FILE* f;
	char tenf[30];
	printf("\nNhap ten file: ");
	fgets ( tenf , sizeof(tenf) , stdin );
	tenf [  strcspn (tenf,"\n")]=0;
	
	f = fopen (tenf,"a+");
	if ( f == NULL )
	{
		printf("\nfile bi loi khong mo duoc!");
		return 1;
	}
//	rewind(f);
	int n;
	fscanf ( f , "%d\n" , &n );
	int a[n];
	for ( int i=0 ; i<n ; i++ )
	{
		fscanf ( f , "%d",&a[i]);
		printf(" %d",a[i]);
	}
	printf("\nDa hoan thanh doc file! ");
//	fclose(f);
	fseek(f, 0, SEEK_END);
//	SEEK_SET,SEEK_CUR;
// 	f = fopen (tenf,"a");
//	if ( f == NULL )
//	{
//		printf("\nfile bi loi khong mo duoc!");
//		return 1;
//	}

	 for ( int i=0 ; i<n ; i++ )
	 {
	 	fprintf( f , "%d " , a[i]*2);
	 	
	 }
	 
	 printf("\nDa nhap vao file %s! ",tenf);
	 fclose(f);
}
