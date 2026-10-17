#include<stdio.h>
 void main(){
    int n,i; 
    printf("Nhap so phan tu: "); 
    scanf("%d", &n);
    float a[n]; 
	for(i=1; i<=n; i++){
		printf("a[%d]= ", i);
		scanf("%f", &a[i]); 
	} 
	printf("day vua nhap: ");
	for(i=1; i<=n; i++){
		printf("%.2f ", a[i]); 
	} 
	float tong_day(int n, float a[]){
		if(n==1)  return a[1];
		else 
		   return tong_day(n-1,a)+a[n];
	}  
	printf("Tong day = %.2f", tong_day(n,a));	
 } 
