#include <stdio.h>
int* nhap(int* A, int* a, int n) {
    for ( int i=0 ; i<n ; i++ ){
	printf("A[%d]=",i);
	scanf("%d",(A+i));
    }
    for (int i = 0; i < n; i++) {
        *(a + i) = *(A + i); 
    }
    return a; 
}
void in_mang(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");
}
int main() {
	int B[3];//manggoc
    int b[3];//mangcopy
    int n = 3;
    int* b_copy=nhap(B,b,n);
    printf("1. Mang goc ban dau : ");
    in_mang(B,n);
    printf("2. Mang moi  : ");
    in_mang(b_copy, n); 
    
    printf("3 Kiem tra lai goc : ");
    in_mang(B, n);  
	printf("\n1. Hien truong vua nhap xong:\n");
    printf("Mang GOC  (B) : "); in_mang(B, n);
    printf("Mang COPY (p) : "); in_mang(b_copy, n); 
    printf("\n--- them 999 len ban COPY ---\n");
    *b_copy  = 999; 
    
    printf("2. Kiem tra lai hien truong:\n");
    printf("Mang COPY (p) : "); in_mang(b_copy, n);
    printf("Mang GOC  (B) : "); in_mang(B, n);  
    
    return 0;
}
