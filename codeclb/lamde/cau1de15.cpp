#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	int x;
	int y;
}ToaDo;

float KC2D ( ToaDo d1 , ToaDo d2){
	return sqrt(pow(d2.x-d1.x,2)+pow(d2.y-d1.x,2));
}

ToaDo* DocTep ( int* n){
	FILE* f = fopen ("cau1de15.txt","r");
	if ( f== NULL ){
		printf("\nLoi mo file ");
		exit(1);
	}
	
	fscanf(f,"%d",n);
	
	ToaDo* td = ( ToaDo* ) malloc ((*n)*sizeof(ToaDo));
	if( td == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit (1);
	}
	
	for ( int i=0 ; i<*n ; i++ ){
			fscanf(f,"%d%d",&td[i].x,&td[i].y);
			printf("\nP(%d)=(%d ,%d)",i,td[i].x,td[i].y );
	}
	fclose(f);
	return td;
}

void MaxKhoangCach2Diem ( ToaDo td[] , int n ){
	float max = 0 ;
	for ( int i=0 ; i<n ; i++){
		for ( int j=i+1 ; j<n ; j++) {
			float khoangCach2Diem = KC2D (td[i],td[j]);
			if ( max < khoangCach2Diem );
			max =khoangCach2Diem;
		}
	}
	printf("\nKhoang cach 2 diem ... lon nhat la %.2f",max);
}

void TinhTongKhoangCachToiTRucHoanh( ToaDo td[] , int n){
	float tong = 0;
	for ( int i=0 ; i<n ; i++ ){
			tong += abs(td[i].y);
	}
	printf("\nTong khoang cach cua cac diem den truc hoanh %f",tong);
}

int main(){
	int n;
	ToaDo* td = DocTep(&n);
	TinhTongKhoangCachToiTRucHoanh(td,n);
	 MaxKhoangCach2Diem(td,n);
	free(td);
}
