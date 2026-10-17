#include<stdio.h>
void nhap(float a[][20],int* m, int* n);
void in_bang(float a[][20],int m, int n);
float tong(float a[][20], int m, int n);
void nhanmt(float a[][20], float b[][20],float c[][20] , int m ,int n ,int p);
int main()
{
	float a[20][20];
	int n , m;
//printf("so hang, so cot");
//scanf("%d%d",&m,&n);
	nhap(a,&m,&n);

	nhanmt(a,b,c,m,n,p);
	printf("\nma tran A:\n");
	in_bang(a,m,n);
void nhap(float a[][20],int* m, int* n){
	int i,j;
	printf("So hang, so cot: ");
	scanf("%d%d",m,n);
	for ( i=1 ; i<= *m; ++i)
	   for (j=1; j<= *n; ++j)
	   {
	   	    printf("a[i][j]= ", i,j);
	   	    scanf("%f", &a[i][j]);
	   }
	printf("\nma tran B:\n");
	in_bang(b,n,p);
//void nhap(float b[][20],int* n, int* p){
//	int i,j;
//	printf("So hang, so cot: ");
//	scanf("%d%d",n,p);
//	for ( i=1 ; i<= *m; ++i)
//	   for (j=1; j<= *n; ++j)
//	   {
//	   	    printf("a[i][j]= ", i,j);
//	   	    scanf("%f", &a[i][j]);
//	   }
	printf("\nma tran C=A*B:\n");
	in_bang(c,m,p);
	printf("\nin ma tran duoi dang bang:\n");
	in_bang(a,m,n);
	printf("tong cua ma tran =%.2f",tong(a,m,n));
void nhap(float a[][20],int* m, int* n){
	int i,j;
	printf("So hang, so cot: ");
	scanf("%d%d",m,n);
	for ( i=1 ; i<= *m; ++i)
	   for (j=1; j<= *n; ++j)
	   {
	   	    printf("a[i][j]= ", i,j);
	   	    scanf("%f", &a[i][j]);
	   }
}
//	void in_bang(float a[][20],int m, int n)
//	{
//		int i,j;
//		
//	}
	void nhanmt (float a[][20], float b[][20],float c[][20] , int m ,int n ,int p)
	{
	 int i,j,k;
	 for ( i=1 ; i<=m ; ++i )
	 	for( j=1 ; j<=p ; ++j ){
	 		c[i][j]=0;
	 		for ( k=0 ; k<=n ; ++k )
	 		c[i][j]+=a[i][k]*b[k][j];
		 }
	}
}
