#include <stdio.h>
void nhap( int* a , int n ){
	for ( int i=0 ; i<n ; i++ ){
		printf("a[%d]=",i);
		scanf("%d",(a+i));
	}
}
//int xoa_phan_tu( int* a , int n , int x ){
//	printf("\nNhap vi tri ban muon xoa: ");
//	scanf("%d",&x);
//    for(int j=x; j<n-1; j++){
//        a[j] = a[j+1];
//        
//    }
//    n--;
//   	return n;
//}
int chen_phan_tu(int* a , int n , int h , int H){
	printf("\nNhap vi tri muon chen: ");
	scanf("%d",&h);
	printf("\nSo muon chen: ");
	scanf("%d",&H);
	for ( int i=h ; i=n ; i++  ){
		*(a+i)=*(a+i-1); 
	}
	*(a+h)=H;
	n++;
	return n;
}

void in_mang( int* a , int n ){
	for ( int i=0 ; i<n ; i++ ){
		printf(" %d",*(a+i));
	}
}
int main(){
	int n,x,H;
	printf("\nNhap so luong phan tu cua mang: ");
	scanf("%d",&n);
	int A[n];
	nhap(A,n);
	in_mang(A,n);
//	n= xoa_phan_tu(A,n,x);
//	in_mang(A,n);
	int h=chen_phan_tu(A,n,h,H);
	in_mang(A,h);
}
