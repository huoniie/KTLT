#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
	char s[8];
	char l[20];
	float v;
	int sta;
}Sensor;


Sensor* DocTep ( int* n ){
	FILE* f = fopen ( "cau2de19.txt","r");
	if ( f == NULL ){
		printf("\nLoi mo file!");
		exit(1);
	}
	
	fscanf(f,"%d\n",n);
	
	Sensor* sen = (Sensor* ) malloc ((*n) * sizeof ( Sensor));
	if ( sen == NULL ){
		printf("\nLoi cap phat bo nho!");
		exit(1);
	}
	printf("\n");
	for ( int i=0 ; i<*n ; i++ ){
		fgets(sen[i].s,sizeof(sen[i].s),f);
		sen[i].s[strcspn ( sen[i].s,"\n")]=0;
		
		fgets(sen[i].l,sizeof(sen[i].l),f);
		sen[i].l[strcspn ( sen[i].l,"\n")]=0;
		fscanf ( f,"%f %d\n",&sen[i].v,&sen[i].sta);
		printf("\n%s, %s, %.2f, %d",sen[i].s,sen[i].l,sen[i].v,sen[i].sta);
		
	}
	
	fclose (f);
	return sen;
}

void TimTrangThaiLoi ( Sensor sen[], int n){
	printf("\n DANH SACH CAC SENSOR CO LOI NAY");
	for ( int i=0 ; i<n ; i++ ){
		if ( sen[i].sta == 0 || sen[i].sta == -1){
			printf("\n%s - %s" , sen[i].s,sen[i].l);
		}
	}
}

void SapXep ( Sensor sen[], int n){
	FILE* F = fopen ( "ketquacau2de19.txt","w");
	if ( F == NULL ){
		printf("\nLoi mo file!");
		exit(1);
	}
	for ( int i=0 ; i<n-1 ; i++ ){
		int key = i;
		for ( int j=i+1 ; j<n ; j++ ){
			if ( sen[j].sta >sen[key].sta||(sen[j].sta ==sen[key].sta&&sen[i].v>sen[key].v)){
				key = j;
			}
		}
		if ( key!= i){
			Sensor temp = sen[i];
			sen[i] = sen [key];
			sen[key];
		}
		printf("\n");
	}
	for ( int i=0 ; i<n ; i++ ){
		printf("\n%s, %s, %.2f, %d",sen[i].s,sen[i].l,sen[i].v,sen[i].sta);
		fprintf(F,"\n%s, %s, %.2f, %d",sen[i].s,sen[i].l,sen[i].v,sen[i].sta);
	}
	fclose(F);
	
}

int main (){
	int n;
	Sensor* sen = DocTep (&n);
	TimTrangThaiLoi(sen,n);
	SapXep(sen,n);
	free(sen);
}
