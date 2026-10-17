#include <stdio.h>
#include <stdlib.h>
void nhap(int* a , int n){
	for ( int i=0 ; i<n ; i++ ){
		printf("A[%d]=",i);
		scanf("%d",(a+i));
	}
}
	int* cong_hai_mang(int* a, int* b, int n){
    	int* c = (int*) malloc(n * sizeof(int));
    if (c == NULL) {
        printf("het cho\n");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        *(c + i) = *(a + i) + *(b + i);
    }
	return c; 
}
void in_mang(int* H, int n) {
    for (int i = 0 ; i < n ; i++ ) {
        printf("%d ", *(H + i));
    }
    printf("\n");
}
int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d",&n);
    int A[n]; 
    nhap(A, n);
    int* B = (int*) malloc(n * sizeof(int));
    if (B == NULL) return 1;
    nhap(B, n);
    int* C = cong_hai_mang(A, B, n);
    if (C != NULL) {
        in_mang(A, n);
        in_mang(B, n);
        in_mang(C, n);
        free(B);
        free(C);
    }
    return 0;
}
