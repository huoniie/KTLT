#include <stdio.h>
#include <string.h>

int main(){
	FILE* f;
	f = fopen ( "output.txt","w");
	int msv;
	char ten[30];
	char lop[10];
	char khoa[10];
	printf("\nNhap ma sinh vien: ");
	scanf("%d",&msv);
	
	getchar();
	printf("\nNhap ten: ");
	fgets(ten,30,stdin);
	
	printf("\nNhap lop: ");
	fgets(lop,10,stdin);
	
	printf("\nNhap khoa: ");
	fgets(khoa,10,stdin);
	
	fprintf(f,"%d",msv);
	fprintf(f,"\n%s",ten);
	fprintf(f,"%s",lop);
	fprintf(f,"%s",khoa);
	
	fclose(f);
	
}
