#include <stdio.h>
int main(){
	FILE *f;
	int n , i , a[20] ;
	f = fopen ( "huong.txt","rt");
	fscanf(f,"%d",&n);
	
	
	for ( i=0 ; i<n ; i++ )
		fscanf ( f , "%d" , &a[i]);
		
	for ( i=0 ; i<n ; i++ )
		printf("%d",a[i]);
		
	f = fopen ("huong.txt","wt");
	
	for ( i=0 ; i<n ; i++ )
	fprintf(f,"d",a[i]);
}
