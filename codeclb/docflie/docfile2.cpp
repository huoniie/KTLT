#include <stdio.h>
#include <string.h>

typedef struct {
	char ten[30];
	float toan,ly,hoa;
}SinhVien;

int main(){
	int n;
	FILE* f;
	char tenf[30];
	SinhVien sv[30];
	
	printf("\nTen tep: ");
	fgets(tenf,sizeof(tenf),stdin);
	tenf[strcspn(tenf,"\n")]=0;
	
	f = fopen (tenf,"r");
	if ( f == NULL ){
		printf("\nFile khong ton tai! ");
		return 1;
	}
	fscanf ( f ,"%d\n", &n );
	
	printf("\nDanh sach diem cua sinh vien: ");
	for ( int i=0 ; i<n ; i++ ){
		fgets(sv[i].ten, 30, f);
        sv[i].ten[strcspn(sv[i].ten, "\n")] = 0;
		fscanf(f,"%f%f%f\n",&sv[i].toan,&sv[i].ly,&sv[i].hoa);
		
		printf("\n%-30s  %.1f  %.1f  %.1f",sv[i].ten , sv[i].toan , sv[i].ly,sv[i].hoa);
	}
	
	for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            float tongI = sv[i].toan + sv[i].ly + sv[i].hoa;
            float tongJ = sv[j].toan + sv[j].ly + sv[j].hoa;
            
            if (tongI < tongJ) {
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
    
	int nguoi_tt = 0; 
    float tt = 4.0;
    printf("\nDanh sach sinh vien trung tuyen: ");
    for (int i = 0; i < n; i++) {
        if (sv[i].toan > tt && sv[i].ly > tt && sv[i].hoa > tt) {
            printf("\n%-30s  %.1f  %.1f  %.1f  ", sv[i].ten, sv[i].toan, sv[i].ly, sv[i].hoa);
            nguoi_tt++;
        }
    }

    if (nguoi_tt == 0) {
        printf("\nKhong co sinh vien nao trung tuyen!");
    }
	
	
	fclose(f);
}
