#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char ht[30];
	int ns;
	int nkn;
}DoanVien;

DoanVien* DocTep ( FILE* f , int n ){
	
	DoanVien* dv = (DoanVien*) malloc ( n * sizeof (DoanVien));
	for ( int i=0 ; i<n ; i++ ){
		fscanf(f,"%[^\n]s", &dv[i].ht);
		fscanf ( f , "%d\n" ,&dv[i].ns );
		fscanf ( f , "%d\n" ,&dv[i].nkn );
		printf ("\n%5d %-30s %-10d %-10d ",i+1,dv[i].ht,dv[i].ns,dv[i].nkn);
	}
	return dv;
}

void SapXep ( DoanVien* dv , int n ){
	for ( int i=0 ; i<n ; i++ ){
		for ( int j=i+1 ; j<n ; j++ )
		if ( dv[i].nkn > dv[j].nkn ){
			int temp = dv[i].nkn;
			dv[i].nkn = dv[j].nkn;
			dv[j].nkn = temp;
		}
	}
}

void In ( DoanVien* dv , int n ){
	printf("\n======Danh sach doan vien=======\n");
	for ( int i=0 ; i<n ; i++ ){
		printf ("\n%-5d %-30s %-10d %-10d ",i+1,dv[i].ht,dv[i].ns,dv[i].nkn);
	}
}


void TuoiDoan ( DoanVien* dv , int n ){
	printf ("\n======Danh sach thanh vien theo tuoi doan=========\n");
	for ( int i=0 ; i<n ; i++ ){
		if ( dv[i].nkn >=2007&&dv[i].nkn <=2015 ){
			printf ("\n%-5d %-30s %-10d %-10d %-10d",i+1,dv[i].ht,dv[i].ns,dv[i].nkn,2015-dv[i].nkn);
		}
	}
}

void GhiTep (FILE* F , DoanVien* dv , int n){
	fprintf(F,"\n======Thong tin doan vien========\n");
	for ( int i=0 ; i<n ; i++ ){
			fprintf (F,"\n%-5d %-30s %-10d %-10d %-10d",i+1,dv[i].ht,dv[i].ns,dv[i].nkn,2015-dv[i].nkn);
	}
}

int main(){
	FILE* f;
	char tenf[30];
	printf("\nNhap ten tep: ");
//	scanf("%[^\n]s", tenf);
	
	f = fopen ( "input2.txt" , "r" );
	if ( f == NULL ){
		printf("\nLoi mo file! ");
		return 1;
	}
	int n;
	fscanf(f,"%d ",&n);
	printf("%d", n);
	DoanVien* dv = DocTep (f,n);
	SapXep(dv,n);
	In(dv,n);
	TuoiDoan(dv,n);
	fclose(f);
	FILE* F;
	
	F = fopen ( "ketqua.txt" , "w" );
	if ( F == NULL ){
		printf("\nLoi mo file! ");
		return 1;
	}
	GhiTep (F,dv,n);
	fclose (F);
	free(dv);
	
}
