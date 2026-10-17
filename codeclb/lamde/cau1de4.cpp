#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE* MoFileDoc (){
	FILE* f ;
	f = fopen ("vanban.txt","r");
	
	if ( f == NULL ){
		printf("\nloi mo file");
		exit(1);
	}
	return f;
}

char* dem (FILE* f , int n){
	
	char* vb = (char*) malloc ( n * sizeof(char));
	fgets ( vb ,n, f);
	
	for ( int i=0 ; i<strlen(vb)-1 ; i++ ){
		printf ("%c",vb[i]);
	}
	
	int dem = 0;
	for ( int i=0 ; i<n ; i++ ){
		if ( vb[i] == ' '){
			dem++;
		}
	}
	
	if (dem != 0){
		printf("\nSo ki tu khoang trang trong chuoi %d",dem);
		printf("\nso tu trong chuoi %d\n" ,dem+1);
	}
	else {
		printf ("\nkhong co gi ca.\n");
	}
	return vb;
}

void TuDau ( char* vb , int n){
	
	for ( int i=0 ; i<n ; i++ ){
		printf ("%c",vb[i]);
		if ( vb[i] == ' '){
			return;
		}
	}

}


void timkiem( char* vb ){
	char x;
	printf ("\nnhap ki tu ban muon tim: ");
	scanf("%c",&x);
	int dem =0;
	for (int i=0 ; i<strlen(vb)-1; i++ ){
		if ( x == vb[i]){
			dem++;
		}
	}
	if ( dem!=0 ){
		printf("\nKi tu %c xuat hien %d lan",x,dem);
	}
	else {
		printf ("\nKi tu %c khong xuat hien trong chuoi.",x);
	}
}



int main(){
	FILE* f = MoFileDoc ();
	int n = 250 ;
	char* vb = dem(f,n);
	TuDau (vb,n);
	timkiem (vb);
	fclose(f);
}



