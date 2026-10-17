#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


float** DocTep ( int* n){
	FILE* f = fopen ( "cau1de16.txt","r");
	if ( f == NULL ){
		printf("\nLoi mo file");
		exit(1);
	}
	
	fscanf(f,"%d",n);
	
	float** mt = ( float** ) malloc ( (*n) * sizeof ( float* ));
	
	if ( mt == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	
	for ( int i=0 ; i<*n ; i++){
		mt[i] = ( float*) malloc ( (*n) * sizeof ( float));
		for ( int j=0 ; j<*n ; j++ ){
			fscanf (f,"%f",&mt[i][j]);
			printf("%.2f  ",mt[i][j]);
		}
		printf("\n");
	}
	printf("\nDa thanh cong doc du lieu trong tep");
	fclose (f);
	return mt;
}

void TimDiemCaoNhat ( float** mt , int n){
	int d1 = 0;
	int d2 = 0;
	float max =mt[0][0];
	for ( int i=0 ; i<n ; i++ ){
		for ( int j=0 ; j<n ; j++){
			if ( max < mt[i][j]){
				max = mt[i][j];
				d1=i;
				d2=j;
			}
		}
	}
	printf("\nDiem cao nhat la A(%d,%d)=%.2f",d1,d2,mt[d1][d2]);
}
void TimDiemThapNhat ( float** mt , int n){
	int d1 = 0;
	int d2 = 0;
	float min = mt[0][0];
	for ( int i=0 ; i<n ; i++ ){
		for ( int j=0 ; j<n ; j++){
			if ( min > mt[i][j]){
				min = mt[i][j];
				d1=i;
				d2=j;
			}
		}
	}
	printf("\nDiem thap nhat la A(%d,%d)=%.2f",d1,d2,mt[d1][d2]);
}

float DoCaoTrungBinh (float** mt , int n){
	float doCao = 0;
	for ( int i=0 ; i<n ; i++){
		for ( int j=0 ; j<n ; j++){
			doCao += mt[i][j];
		}
	}
	float doCaoTB = doCao/(n*n);
	printf("\nDo cao trung binh cua ban do la %.2f",doCaoTB);
	int dem = 0;
	bool check = false;
	for ( int i=0 ; i<n ; i++){
		for ( int j=0 ; j<n ; j++){
			if ( mt[i][j] > doCaoTB ){
				dem++;
				check = true;
		}
	}
	if (check == true)
	printf("\nCo %d diem lon hon do cao trung binh.",dem);
	else printf("\nKhong co diem nao lon hon do cao trung binh.");
	return doCaoTB;
	}
}

void HangCoTongDoCaoLonNhat ( float** mt , int n){
	int viTri = 0;
	float max =mt[0][0];
	for (int i=0 ; i<n ; i++ ){
		float tongHang= 0;
		for ( int j=0 ; j<n ;j++ ){
			tongHang += mt[i][j];
		}
		printf("\nTong hang %d la %.2f",i+1,tongHang);
		if ( tongHang>max){
			max=tongHang;
			viTri = i+1;
		}
	}
	printf("\nHang %d co tong do cao lon nhat.\n",viTri);
}

void BienDoiMaTran(float** mt,int n, float doCaoTB) {
    float khoangCachMin = fabs(mt[0][0] - doCaoTB);
    float khoangCachMax = fabs(mt[0][0] - doCaoTB);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float kc = fabs(mt[i][j] - doCaoTB);
            if (kc < khoangCachMin) khoangCachMin = kc;
            if (kc > khoangCachMax) khoangCachMax = kc;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float kc = fabs(mt[i][j] - doCaoTB);
            if (fabs(kc - khoangCachMin) < 0.0001) {
                mt[i][j] = 0;
            } 
            else if (fabs(kc - khoangCachMax) < 0.0001) {
                mt[i][j] = 1;
            }
        }
    }
    printf("\n4. Ma tran SAU KHI bien doi 0 (Gan TB nhat) va 1 (Xa TB nhat):\n");
    for ( int i=0 ; i<n ; i++ ){
		for (int j=0 ; j<n ; j++ ){
			printf("%.2f  ",mt[i][j]);
		}
		printf("\n");
	}
}
//
//void SapXep ( float** mt , int n){
//	for ( int i=0 ; i<n ; i++ ){
//		for ( int j = 0; j<n-1 ; j++ ){
//			int key = j;
//			for ( int k=j+1 ; k<n ; k++){
//				if ( mt[i][key] > mt[i][k]){
//					key = k ;
//				}
//			}
//			if ( key != j ){
//				float temp = mt[i][j];
//				mt[i][j] = mt[i][key];
//				mt[i][key] = temp;
//			}
//		}
//	}
//	
//	printf("\nmap sau khi da sap xep:\n");
//	for ( int i=0 ; i<n ; i++ ){
//		for (int j=0 ; j<n ; j++ ){
//			printf("%.2f  ",mt[i][j]);
//		}
//		printf("\n");
//	}
//}

int main(){
	int n;
	float** mt = DocTep (&n);
	TimDiemCaoNhat(mt,n);
	TimDiemThapNhat(mt,n);
	float doCaoTB = DoCaoTrungBinh (mt,n);
	HangCoTongDoCaoLonNhat(mt,n);
//	SapXep (mt,n);
	BienDoiMaTran(mt,n,doCaoTB);
	for (int i=0 ; i<n ; i++){
		free(mt[i]);
	}
	free(mt);
}



