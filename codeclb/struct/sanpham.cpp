#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	char name[30];
	float cost;
	int code;
}product;
product*  nhap ( int n ){
	product* p = ( product* ) malloc ( n *sizeof( product ));
	for ( int i=0 ; i<n ; i++ ){
		printf("\nSan pham %d:", i+1 );
		getchar();
		printf("\nNhap ten: ");
		fgets(p[i].name , 30 , stdin );
		p[i].name [ strcspn (p[i].name , "\n" )]=0;
		printf("Nhap gia: ");
		scanf("%f",&p[i].cost );
		printf("Nhap ma: ");
		scanf("%d", &p[i].code );
	}
	printf("\n");
	
	return p;
}
void arrange ( product* p , int n ){
	printf("\nDanh sach sau khi sap xep theo gia: ");
	product* p_copy = ( product* ) malloc (n * sizeof(product));
    for (int i = 0; i < n; i++) {
        p_copy[i] = p[i];
    }
for( int i=0 ; i < n - 1 ; i++ ){
        for (int j = i + 1; j < n; j++) {
			if (p_copy[i].cost < p_copy[j].cost) { 
				product temp = p_copy[i];
				p_copy[i] = p_copy[j];
				p_copy[j] = temp;
			}
        }
	}
				for ( int k=0 ; k<n ; k++ ){
				printf("\nSan pham %d", k+1 );
				printf("\nTen: %s ", p_copy[k].name );
				printf("\nGia: %.2f",p_copy[k].cost );
				printf("\nMa: %d", p_copy[k].code );
			}
	printf("\n");
}

void lookfor ( product* p , int n){
	int c;
	int found=0;
	printf ("\nNhap ma san pham ban muon tim kiem: ");
	scanf("%d",&c);
for (int i = 0; i < n; i++) {
        if (p[i].code == c) { 
            printf("\n--- Da tim thay san pham ---");
            printf("\nVi tri trong danh sach: %d", i + 1);
            printf("\nTen: %s", p[i].name);
            printf("\nGia: %.2f", p[i].cost);
            printf("\nMa: %d\n", p[i].code);
            
            found = 1;
            break; 
        }
    }

    if (found == 0) {
        printf("\mKhong tim thay san pham nao co ma %d", c);
    }	
}
void print ( product* p , int n ){
	for ( int i=0 ; i<n ; i++ ){
	printf("\nSan pham %d", i+1 );
	printf("\nTen: %s ", p[i].name );
	printf("\nGia: %.2f",p[i].cost );
	printf("\nMa: %d", p[i].code );
	printf("\n");
	}
}
int main (){
	int n;
	printf("\nNhap so luong san pham: ");
	scanf("%d",&n);
	product* P = nhap(n);
	print(P,n);
	arrange (P,n);
	lookfor(P,n);
	print(P,n);
	free(P);
}

