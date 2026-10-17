#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float dai , rong;
}HCN;

HCN* DocTep ( int*n ){
	FILE* f = fopen ("cau11de18.txt","r");
	if ( f== NULL){
		printf("\nLoi mo tep!");
		exit(1);
	}
	
	fscanf(f,"%d",n);
	
	HCN* h = (HCN*) malloc ( (*n) *sizeof(HCN));
	if ( h== NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	printf("\nKICH THUOC CUA %d HINH CHU NHAT",*n);
	for ( int i=0 ; i<*n ; i++ ){
		fscanf(f,"%f %f",&h[i].dai,&h[i].rong);
		printf("\nHinh %d",i+1);
		printf("\n%.2f  %.2f ",h[i].dai,h[i].rong);
	}
	fclose(f);
	return h;
}

void DienTich ( HCN h[] , int n){
	
	float dienTich = h[0].dai * h[0].rong;
	float max = dienTich;
	int viTri = 0;
	for ( int i=0 ; i<n ; i++ ){
		dienTich = h[i].dai * h[i].rong;
		printf("\nHinh %d co dien tich %.2f" ,i+1,dienTich);
		if ( max < dienTich ){
			max = dienTich;
			viTri=i;
		}
	}
	
	printf("\nHinh %d co dien tich lon nhat = %.2f",viTri,max);
}

int main(){
	int n;
	HCN* h = DocTep(&n);
	DienTich(h,n);
	free(h);
}
