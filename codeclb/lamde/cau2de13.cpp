#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char mkv[30];
	float ph;
	int wqi;
}MauDuLieu;


void In (MauDuLieu mdl[], int i){
	printf("\n%-5d %-20s %-10.1f %-20d ",
	i+1,mdl[i].mkv,mdl[i].ph,mdl[i].wqi);
}
MauDuLieu* DocTep ( int* n){
	FILE* f = fopen ( "cau2de13.txt","r");
	
	if ( f == NULL ){
		printf("\nLoi mo tep!");
		exit(1);
	}
	
	fscanf (f,"%d\n",n);
	
	
	MauDuLieu* mdl = ( MauDuLieu*) malloc ((*n)* sizeof (MauDuLieu));
	
	printf("\nDANH SACH MAU DU LIEU\n");
	printf("\n%-5s %-20s %-10s %-20s ",
	"STT","MA KHU VUC","DO pH","CHI SO WQI");
	for (int i=0 ; i<*n ; i++ ){
		fscanf ( f , "%s",&mdl[i].mkv);
		mdl[i].mkv[strcspn(mdl[i].mkv,"\n")]=0;
		
		fscanf(f,"%f",&mdl[i].ph);
		fscanf(f,"%d",&mdl[i].wqi);
		In(mdl,i);
	}
	fclose(f);
	return mdl;
}


void Ghi (FILE* F, MauDuLieu mdl[], int i){
	fprintf(F,"\n%-5d %-20s %-10.1f %-20d ",
	i+1,mdl[i].mkv,mdl[i].ph,mdl[i].wqi);
}

void DOpHNgoaiKhoangChuan ( MauDuLieu mdl[] ,int n){
	int check = 0;
	printf("\nDanh sach cac khu vuc co do ph ngoai khoang chuan");
	for ( int i=0 ; i<n ; i++ ){
		if ( mdl[i].ph<6.5||mdl[i].ph>8.5){
			In(mdl,i);
			check++;
		}
	}
	if (check==0){
		printf("\nKhong co mau nao nam ngoai khoang chuan.");
	}
}

void SapXep ( MauDuLieu mdl[] ,int n){
	FILE* F = fopen ("reportcau2de13.txt","w");
	
	if ( F == NULL ){
		printf("\nLoi mo tep!");
		exit(1);
	}
	
	for ( int i=0 ; i<n-1 ; i++ ){
		int key = i ;
		for ( int j=i+1 ; j<n ; j++ ){
			if ( mdl[key].wqi < mdl[j].wqi ){
				key = j;
			}
			if ( mdl[key].wqi == mdl[j].wqi && mdl[key].ph > mdl[j].ph ){
			key=j;
			}
		}
		if ( key!=i){
			MauDuLieu temp = mdl[i];
			mdl[i] = mdl[key];
			mdl[key]= temp;
			
		}
	}

	fprintf(F,"\nDANH SACH MAU DU LIEU\n");
	fprintf(F,"\n%-5s %-20s %-10s %-20s ",
	"STT","MA KHU VUC","DO pH","CHI SO WQI");
	
	for ( int i=0 ; i<n ; i++ ){
		Ghi (F,mdl,i);
	}
	fclose(F);
}

int main (){
	int n ; 
	MauDuLieu* mdl = DocTep(&n);
	DOpHNgoaiKhoangChuan(mdl,n);
	SapXep (mdl,n);
	free(mdl);
}
