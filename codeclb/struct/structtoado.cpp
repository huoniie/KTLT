#include <stdio.h>
#include <math.h>
struct ToaDo{
	float x;
	float y;
	
};
int main(){
	struct ToaDo A,B;
	A.x=2;
	A.y=5;
	B.x=6;
	B.y=7;
	float dx = A.x - B.x;
	float dy = A.y - B.y;
	float a=sqrt(dx*dx+dy*dy);
	printf("\nKhoang cach: %.2f",a);
	}
 
