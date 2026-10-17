#include <stdio.h>
#include <string.h>
int ispalin( char s[] , int start , int end ){
	if ( s[start]>= s[end]) return 1;
	if ( s[start]!= s[end] ) return 0;
	return ispalin( s , start + 1 , end -1 );
}
int main (){
	char str[100];
	int n;  
	printf("Nhap: ");
	gets(str);
	n=strlen(str);
	if (ispalin(str,0,n-1)==1)
		printf("la dung ");
	else 
		printf("khong phai");
}
