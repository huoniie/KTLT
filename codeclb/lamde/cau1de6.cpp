/*Vi?t chuong trình th?c hi?n các công vi?c sau:

Nh?p vào hai dãy s? th?c a1,a2,...,an và b1,b2,...,bn.
Coi hai dãy này là các t?a d? c?a m?t dãy n di?m:
M1(a1,b1), M2(a2,b2), ..., Mn(an,bn)
Ð?m s? di?m n?m trong góc ph?n tu th? II.
Tìm hai di?m n?m trong góc ph?n tu th? I và xa nhau nh?t.

Tính d? dài du?ng g?p khúc di qua l?n lu?t các di?m có ch? s? l?:
M1, M3, M5, ..*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
	float x;
	float y;
}ToaDo;

float KC2D(ToaDo A, ToaDo B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

ToaDo* nhap( int* n ){
	do{
	printf("\nNhap so luong diem cua a va b(bang nhau va lon hon 0): ");
	scanf("%d",n);
	}
	while ( n < 0);
	
	ToaDo* td = (ToaDo*) malloc ( *n* sizeof(ToaDo));
	
	for ( int i=0 ; i<*n ; i++ ){
			printf("M%d(%d,%d)=",i+1,i+1,i+1);
			scanf("%f%f",&td[i].x,&td[i].y);
	}
	for ( int i=0 ; i<*n ; i++ ){
		printf("\nM%d(%d,%d)=(%.2f;%.2f)",i+1,i+1,i+1,td[i].x,td[i].y);
	}
	return td;
}

void phantuII(ToaDo td[],int n){
	int dem =0;
	for ( int i=0 ; i<n ; i++ ){
		if ( td[i].x < 0 && td[i].y > 0){
			dem++;
		}
	}
	if ( dem > 0 ){
		printf("\nCo %d diem trong goc phan tu II ",dem);
	}
	else{
		printf("\nKhong co diem nao trong goc phan tu II");
	}
}

void kcmaxI ( ToaDo td[] , int n ){
	float max = -1; 
    int d1 = -1;
    int d2 = -1;
    for (int i = 0; i < n - 1; i++) {
        if (td[i].x > 0 && td[i].y > 0) {
            for (int j = i + 1; j < n; j++) {
                if (td[j].x > 0 && td[j].y > 0) {
                    float kc = KC2D(td[i], td[j]);
                    if (kc > max) {
                        max = kc;
                        d1 = i;
                        d2 = j;
                    }
                }
            }
        }
    }
    if (max == -1) {
        printf("\nKhong tim duoc 2 diem nao trong goc phan tu  I.");
    } else {
        printf("\nHai diem trong goc phan tu thu I xa nhau nhat la:\n");
        printf("M%d(%d, %d) va M%d(%d, %d)\n", 
               d1 + 1, td[d1].x, td[d1].y, 
               d2 + 1, td[d2].x, td[d2].y);
        printf("Khoang cach: %.2f\n", max);
	}
}

void DoDaiDuongGapKhucLe(ToaDo td[], int n) {
    float tongDoDai = 0;
    int coDiem = 0; 

    for (int i = 0; i + 2 < n; i += 2) {
        tongDoDai += KC2D(td[i], td[i+2]);
        coDiem = 1; 
        
    }

    if (coDiem == 0) {
        printf("\nKhong du diem le de tao duong gap khuc.");
    } 
	else {
        printf("\nDo dai duong gap khuc di qua cac diem le la: %.2f\n", tongDoDai);
    }
}


int main (){
	int n;
	ToaDo* td = nhap(&n);
	phantuII(td,n);
	kcmaxI(td,n);
	DoDaiDuongGapKhucLe(td,n);
	free(td);
}
