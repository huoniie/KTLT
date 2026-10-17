#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* MoFile (){
	char ten[30];
	char chedo[50];
	printf("\nNhap ten tep: ");
	scanf(" %[^\n]s",ten);
	ten[strcspn(ten,"\n")]=0;
	
	printf("\nNhap che do muon su dung: ");
    scanf(" %s", chedo);
	
	FILE* f = fopen ( ten , chedo );
	
	if ( f == NULL ){
		printf("\nLoi mo tep: ");
		exit(1);
	}
	return f;
}

float* doc( int* n){
	FILE* f=MoFile ();
	
	fscanf (f,"%d",n);
	
	float* a = (float*) malloc (* n * sizeof (float));
	
	if ( a == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	
	for ( int i=0 ; i<*n ; i++ ){
		fscanf ( f,"%f",&a[i]);
		printf("%.2f  ",a[i]);
	}
	fclose(f);
	return a;
}

void mina ( float*a , int n ){
	float min = a[0];
	for ( int i=0 ; i<n ; i++ ){
		if ( min > a[i]){
		min = a[i];
		}
	}
	printf("\nGia tri nho nhat cua day so la: %.2f",min);
}

void DemSoPhanTuAm ( float*a,int n){
	int dem=0;
	for ( int i=0 ; i<n ; i++ ){
		if ( a[i]<0){
			dem++;
		}
	}
	
	if (dem >0 ){
		printf("\nday so co %d gia tri la so am",dem);
	}
	else{
		printf("\nDay khong co gia tri nao la so am");
	}
}

void SapXep (float*a, int n){
	
	for (int i=0 ; i<n-1 ; i++){
		int key = i ;
		for ( int j=i+1 ; j<n ; j++ ){
			if ( a[key] > a[j]){
				key = j;
			}
		}
		if ( key != i){
			float temp = a[i];
            a[i] = a[key];
            a[key] = temp;
		}
	}
	FILE* f = MoFile();
	
	for ( int i=0 ; i<n ; i++){
		fprintf(f,"%.2f  ",a[i]);
	}
	fclose (f);
	
}
int main (){
	int n;
	float* a = doc(&n);
	mina (a,n);
	DemSoPhanTuAm (a,n);
	SapXep(a,n);
	free(a);
}
