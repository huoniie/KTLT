#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	float x;
	float y;
}ToaDo;

//float KC2D (ToaDo d1 , ToaDo d2 ){
//	return sqrt (pow(d2.x-d1.x,2),pow(d2.y-d1.y,2));
//}

float KC2D ( ToaDo d1 , ToaDo d2){
	return sqrt (pow(d2.x-d1.x,2)+pow(d2.y-d1.y,2));
}
float KCO ( ToaDo d1 ){
	return sqrt (pow(d1.x,2)+pow(d1.y,2));
}


ToaDo* nhap( int* n ){
	FILE* f = fopen ( "diem2d.txt","r");
	
	if ( f == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	
	fscanf(f,"%d",n);
	
	ToaDo* td = (ToaDo*) malloc (*n*sizeof ( ToaDo));
	for ( int i=0 ; i<*n ; i++ ){
		fscanf (f,"%f%f",&td[i].x,&td[i].y);
		printf("\nM%d=(%.2f,%.2f)",i+1,td[i].x,td[i].y);
	}
	return td;
	
}

void kcth ( ToaDo* td , int n){
	float tong =0 ;
	for ( int i=0 ; i<n ; i++ ){
		tong+=td[i].y;
	}
	printf("\ntrung binh cong khoang cach dedn truc hoanh %.2f",tong/n);
}

void maxkc ( ToaDo* td , int n){
	float max =-1;
	for ( int i=0 ; i<n ; i++ ){
		for ( int j=0 ; j<n ; j++){
			if ( max < KC2D ( td[i] , td[j])){
				max =KC2D ( td[i] , td[j]);
			}
		}
	}
	printf("\nKoang cach lon nhat %.2f",max);
}

void maxkco (ToaDo* td , int n ){
	float max =-1;
	for ( int i=0 ; i<n ; i++ ){
			if ( max < KCO ( td[i] )){
				max =KCO ( td[i] );
			}
	}
	FILE* f = fopen ("output2d.txt","w");
	for ( int i=0 ; i<n ; i++){
		if (max =KCO ( td[i] ) )
		fprintf ( f , "%.2f\n",KCO ( td[i] ));
	}
	fclose(f);
}


int main(){
	int n;
	ToaDo* td = nhap(&n);
	kcth(td,n);
	maxkc(td,n);
	maxkco(td,n);
	free(td);
}
