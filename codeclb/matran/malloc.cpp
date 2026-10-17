#include <stdio.h>
#include <stdlib.h> 
int* tao_va_nhap_mang(int n) {
    int* p = (int*) malloc(n * sizeof(int));
    if (p == NULL) {
        printf("Het cho chua\n");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        printf("A[%d]: ", i);
        scanf("%d", (p + i)); 
    }

    return p; 
}
void in_mang(int* p, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
}
int main() {
    int n;
    printf("Nhap so luong phan tu cua mang");
    scanf("%d", &n);
    int* A = tao_va_nhap_mang(n);
    if (A != NULL) {
        
        printf("\nMang vua nhap la: ");
        in_mang(A, n);
        free(A);
      }

    return 0;
} 
