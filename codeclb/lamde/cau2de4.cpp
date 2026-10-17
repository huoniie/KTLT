
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char sbd[15];
	char ht[50];
	float d;
	char tr[10];
}ThiSinh;

FILE* MoFileDoc (){
	FILE* f ;
	f = fopen ("thisinh.txt","r");
	
	if ( f == NULL ){
		printf("\nloi mo file");
		exit(1);
	}
	return f;
}

ThiSinh* DocFile ( FILE* f , int* n){
	if (fscanf(f, "%d\n", n) != 1) { 
        printf("\nKhong doc duoc so luong thi sinh!");
        exit(1);
    }
	
	ThiSinh* ts = (ThiSinh*) malloc ( *n* sizeof ( ThiSinh));
	
	if (ts == NULL) exit(1);
	
	printf("\n======DANH SACH THI SINH==========\n");
	printf ("\n %-5s %-15s %-30s %-10s %-10s","STT","SO BAO DANH","HO VA TEN","DIEM","TRUONG");
	float tong =0;
	for ( int i=0 ; i<*n ; i++ ){
		fgets ( ts[i].sbd , sizeof ( ts[i].sbd) , f);
		ts[i].sbd[strcspn(ts[i].sbd,"\n")]=0;
		
		fgets ( ts[i].ht , sizeof ( ts[i].ht) , f);
		ts[i].ht[strcspn(ts[i].ht,"\n")]=0;
		
		fscanf ( f, "%f\n",&ts[i].d);
		
		fgets ( ts[i].tr , sizeof ( ts[i].tr) , f);
		ts[i].tr[strcspn(ts[i].tr,"\n")]=0;
		
		tong+=ts[i].d;
		
		printf ("\n%-5d %-15s %-30s %-10.2f %-10s" ,
		i+1,ts[i].sbd,ts[i].ht,ts[i].d,ts[i].tr);
	}
	printf("\nDiem trung binh cua toan bo thi sinh %.2f",tong/ *n);
	return ts;
}

void TimmaxA ( ThiSinh* ts , int*n ){
	float maxA = -1;
	int check =0;
	int vitri =1;
	for (int i=0 ; i<*n ; i++ ){
		if ( strcmp(ts[i].tr,"A")=0){
			check =1;
			if ( maxA < ts[i].d){
				maxA = ts[i].d;	
				vitri =i;	
			}
		}
	}
	if (!check){
		printf("\nKhong co thi sinh truong A");
		return;
	}
	printf("\nThi Sinh co diem cao nhat truong A.");
	printf ("\n%-5d %-15s %-30s %-10.2f %-10s" ,
		vitri+1,ts[vitri].sbd,ts[vitri].ht,ts[vitri].d,ts[vitri].tr);
	
}

void sapxep ( ThiSinh* ts , int*n){
	FILE* F ;
	F = fopen ("ketqua_ts.txt","w");
	
	if ( F == NULL ){
		printf("\nloi mo file");
		exit(1);
	}
	fprintf(F,"\n=======DANH SACH THI SINH=========\n");
	fprintf (F,"\n %-5s %-15s %-30s %-10s %-10s","STT","SO BAO DANH","HO VA TEN","DIEM","TRUONG");
	for ( int i=0 ; i<*n-1 ; i++ ){
		for ( int j=i+1 ; j<*n ; j++){
			if ( ts[i].d < ts[j].d){
				ThiSinh temp = ts[i];
				ts[i] = ts[j];
				ts[j]=temp;
			}
			else if (ts[i].d == ts[j].d) {
                if (strcmp(ts[i].sbd, ts[j].sbd) > 0) {
                    ThiSinh temp = ts[i];
                    ts[i] = ts[j];
                    ts[j] = temp;
                }
		}
	}
}
	
	for ( int i=0 ; i<*n ; i++ ){
		fprintf (F,"\n%-5d %-15s %-30s %-10.2f %-10s" ,
		i+1,ts[i].sbd,ts[i].ht,ts[i].d,ts[i].tr);
	}
	fclose(F);
}

int main (){
	FILE* f = MoFileDoc ();
	int n;
	ThiSinh* ts = DocFile(f,&n);
	TimmaxA (ts,&n);
	sapxep (ts,&n);
	fclose(f);
	free(ts);
}
