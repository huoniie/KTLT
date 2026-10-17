#include <stdio.h>
#include<string.h>
int main( ){
	char s[4]="UTC";
	int n=strlen(s);
	printf("%d\n",n);
	printf("%s",strrev(s));
//	for(int i=n;i>=0;i--)
//	{
//		printf("%c",s[i]);
//	}
}
