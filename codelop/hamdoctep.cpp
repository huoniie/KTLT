#include <stdio.h>
#include <string.h>
typedef struct {
	char name[30];
	float toan,ly,hoa;
}Student;
void DocTuTep(FILE* f, Student hs[] , int* n)
{ 
	fscanf(f,"%d\n",n);
	for (int i=0; i<*n ; i++ ){
		fgets(hs[i].name, 30, f);
		hs[i].name[strcspn(hs[i].name, "\n")] = 0;
		fscanf(f,"%f%f%f\n", &hs[i].toan, &hs[i].ly,&hs[i].hoa);
		printf("\n%-20s  %.2f  %.2f  %.2f",hs[i].name, hs[i].toan, hs[i].ly,hs[i].hoa);
	}
}

void lookfor(  Student hs[], int n )
{
	int kt=0;
	char ten_tim[30];
	printf("\nNhap ho ten can tim: ");
	fgets(ten_tim,30,stdin);
	ten_tim[strcspn(ten_tim, "\n")] = 0;
	for ( int i=0 ; i<n ; i++ ){
		if(strcmp(hs[i].name,ten_tim)==0){
			printf("\n%-20s %.2f  %.2f  %.2f",hs[i].name,hs[i].toan,hs[i].ly,hs[i].hoa);
			kt=1;
		}
	}
	if(kt==0) 
		printf("\nKhong co hoc sinh nay!");
}

int main(){
	int n =0 ;
	FILE* f;
	char tenf[30];
	do {
        printf("\nNhap ten tep (vi du: hocsinh.txt): ");
        fgets(tenf, 30, stdin);
        tenf[strcspn(tenf, "\n")] = 0; 

        f = fopen(tenf, "rt");

        if (f == NULL) {
            printf("=> Loi: Khong tim thay file '%s'. Vui long kiem tra lai ten file!\n", tenf);
        }
    } while (f == NULL);
	
	Student hs[30];
	DocTuTep(f, hs, &n );
	lookfor(hs,n);
	
}
