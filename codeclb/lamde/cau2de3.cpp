#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char msp[20];
	char tensp[50];
	int sl;
	float gia;
}NongSan;


FILE* MoFileDoc(){
	FILE* f ;
	f = fopen ("nongsan.txt","r");
	
	if ( f == NULL ){
		printf("\nLoi mo file!");
		exit(1);
	}
	return f;
}

NongSan* DocFile ( FILE* f , int n ){
	NongSan* ns = (NongSan* ) malloc ( n*sizeof (NongSan));
	
	if ( ns == NULL ){
		printf ("\nCap phat bo nho that bai");
		exit(1);
	}
	
	printf("\n %-5s %-20s %-30s %-10s %-10s %-30s","STT","MA SAN PHAM",
	"TEN SAN PHAM","SO LUONG","GIA","GIA TRI TON KHO");
	for ( int i=0 ; i<n; i++ ){
		fgets ( ns[i].msp , sizeof(ns[i].msp),f);
		ns[i].msp[strcspn(ns[i].msp,"\n")]=0;
		fgets ( ns[i].tensp , sizeof(ns[i].tensp),f);
		ns[i].tensp[strcspn(ns[i].tensp,"\n")]=0;
		fscanf (f,"%d %f\n",&ns[i].sl,&ns[i].gia);
		printf("\n %-5d %-20s %-30s %-10d %-10.3f %-30.3f",
		i+1,ns[i].msp,ns[i].tensp,ns[i].sl,ns[i].gia,ns[i].sl*ns[i].gia);
	}
	printf("\nDa doc thanh cong du lieu.\n");
	return ns;
}

void BaMatHang (NongSan* ns , int n ){
	printf ("\nBA MAT HANG CO DON GIA CAO NHAT");
	for ( int i=0 ; i<n ; i++ ){
		int key = i ;
		for (int j=i+1 ; j<n ; j++ ){
			if (ns[i].sl*ns[i].gia > ns[j].sl*ns[j].gia )
			key = j ;
		}
		for ( int i=0 ; i<n ; i++ ){
		if ( key!=i ){
			NongSan temp = ns[i];
			ns[i] = ns[key];
			ns[key] = temp;
			}
		}
	}
	
	for ( int i=0 ; i<3 ; i++ ){
		printf("\n %-5d %-20s %-30s %-10d %-10.3f %-30.3f",i+1
		,ns[i].msp,ns[i].tensp,ns[i].sl,ns[i].gia,ns[i].sl*ns[i].gia);
	}
	
}

int main (){
	FILE* f = MoFileDoc();
	int n;
	fscanf ( f, "%d\n",&n);
	NongSan* ns = DocFile (f,n);
	BaMatHang (ns,n);
	fclose(f);
	free(ns);
}

