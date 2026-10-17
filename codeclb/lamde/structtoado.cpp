/*Struct toa do doc tu file gom N diem x y

Tìm 2 diem gan nhau nhat

sap xep tang dan khoang cách các diem den goc toa do*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	char tend[10];
	float x;
	float y;
}ToaDo;

float TinhKC (ToaDo d1 , ToaDo d2 ){
	return sqrt ( pow (d2.x - d1.x,2)+pow ( d2.y - d1.y ,2));
}

float TinhKCO ( ToaDo d ){
	return sqrt ( pow (d.x,2)+pow ( d.y,2));
}

int ThangHang(ToaDo d1 , ToaDo d2 , ToaDo d3) {
    float ketqua = (d2.x - d1.x) * (d3.y - d1.y) - (d3.x - d1.x) * (d2.y - d1.y);
    
    return (fabs(ketqua) < 0.0001); 
}

FILE* MoFileDoc(){
	char tenf[50];
	printf("\nNhap ten file: ");
	scanf(" %[^\n]s" ,&tenf);
	FILE* f = fopen ( tenf , "r");
	
	if ( f == NULL ){
		printf("\nLoi mo file!");
		exit(1);
	}
	return f;
}

ToaDo* DocFile ( FILE* f , int n ){
	ToaDo* d = ( ToaDo* ) malloc ( n* sizeof ( ToaDo ));
	for ( int i=0 ; i<n ; i++ ){
		fscanf (f," %s %f %f ",&d[i].tend ,&d[i].x,&d[i].y );
		printf("\n%s(%.1f;%.1f)",d[i].tend ,d[i].x,d[i].y);
	}
	printf("\nDa doc tep thanh cong");
	return d;
}

void TinhKC2diem ( ToaDo* d , int n ){
	if ( n<2 ){
		printf("\nCo it hon 2 diem khong the tinh!");
		return ;
	}
	
	float min = TinhKC (d[0],d[1]);
	int d1 = 0 , d2 = 1;
	for ( int i=0 ; i<n-1 ; i++ ){
		for ( int j=i+1 ; j<n ; j++ ){
			float c = TinhKC (d[i],d[j]);
			if ( c < min ){
				min = c;
				d1 = i ; 
				d2 = j ;
			}
		}
	}
	printf("\nHai diem gan nhau nhat la %s va %s: %.2f \n", d[d1].tend,d[d2].tend,min);
}

void TinhKCO_SX ( ToaDo* d , int n ){
	printf("\nKHOANG CACH TU CAC DIEM TOI GOC TOA DO");
	for ( int i=0 ; i<n-1 ; i++ ){
		for ( int j=i+1; j<n ; j++ ){
			if ( TinhKCO(d[i]) > TinhKCO (d[j])){
				ToaDo temp = d[i];
				d[i] = d[j];
				d[j] = temp;
			}
		}
	}
	for ( int i=0 ; i<n ; i++ ){
	printf ("\n %s(%.1f;%.1f) = %.2f",d[i].tend,d[i].x,d[i].y,TinhKCO(d[i]));
	}	
}

void Tim3ThangHang(ToaDo* d, int n) {
    int found = 0;
    printf("\nCAC BO 3 DIEM THANG HANG");
    
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (ThangHang(d[i], d[j], d[k])) {
                    printf("\n%s, %s, %s thang hang", d[i].tend, d[j].tend, d[k].tend);
                    found = 1;
                }
            }
        }
    }
    
    if (!found) printf("\nKhong co bo 3 nao thang hang.");
}
int main (){
	FILE*f = MoFileDoc ();
	int n;
	fscanf ( f , "%d" ,&n );
	ToaDo* d = DocFile (f,n);
	TinhKC2diem (d,n);
	TinhKCO_SX (d,n);
	Tim3ThangHang (d,n);
	fclose(f);
	free(d);
}
