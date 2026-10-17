#include <stdio.h>
int main (){
	FILE *fp;
	int c;
	int n = 0 ;
	fp = fopen ( "input.txt" , "rt");
	if ( fp == NULL ){
		perror ("Xay ra loi khi mo huong.txt ");
		return (-1);
	}
	
//	do {
//		c = fgetc (fp);
//		if ( feof ( fp ) )
//		break;
//		printf("%c",c);
//		
//	}
//	while(1);
 while (( c = fgetc (fp))!=EOF){
 	printf("%c",c);
 }
}
