#include <stdio.h>
#include <string.h>
typedef struct
{
  char ht[30];
  int ns;
  int luong;
}nhanvien;

int main(){
	int n;
	FILE* f;
	nhanvien nv[30];
	char ten[30];
	float s=0;
//	printf("Ten tep: ");
//	gets(ten);
	f = fopen ( "nhanvien.txt" , "rt");
	fscanf(f,"%d\n",&n);	
	
	for(int i=0; i<n; i++){
		fgets(nv[i].ht, 30, f);
		int n=strlen(nv[i].ht);
		printf("%d",n);
		nv[i].ht[strlen(nv[i].ht)-1]=0;
		fscanf(f,"%d%d\n", &nv[i].ns, &nv[i].luong);
//		int n=strlen(nv[i].ht);
//		printf("%d",n);
		printf("\n%-20s %-4d %-6d", nv[i].ht, nv[i].ns, nv[i].luong);
		s+=nv[i].luong;
//		if(2026-nv[i].ns<30 &&nv[i].)
	} 
	printf("\nLuong trung binh cua nhan vien %.1f",s/n);
	int kt=0;
	fflush(stdin);
	char ten_tim[30];
	printf("\nNhap ho ten can tim: ");
	gets(ten_tim);
	for ( int i=0 ; i<n ; i++ ){
		if(strcmp (nv[i].ht ,ten_tim)==0){
			printf("\n%-20s%4d%8d",nv[i].ht,nv[i].ns,nv[i].luong);
			kt=1;
		}
	}
	if(kt==0) 
		printf("\nKhong co nhan vien nay!");
	
	
	//3 tim nhung nhan vien co so
	
}
