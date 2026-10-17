#include <stdio.h>
int main (){
	FILE* f;
	float a[50] , s = 0 ;
	int i=0;
	f = fopen ( "dayso.txt" , "rt");
//	if ( f == NULL ){
//		perror ("Xay ra loi khi mo huong.txt ");
//		return (-1);
//	}
	while (!feof(f))
	{
		i++;
		fscanf(f,"%f",&a[i]);
		s=s+a[i];
	}
	printf("%d\n",i-1);
	printf("Trung binh = %.2f",s/(i-1));
}
