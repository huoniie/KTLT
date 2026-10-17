#include <stdio.h>
#include <math.h>
struct ToaDo{
	float x;
	float y;
};
int main(){
	struct ToaDo a,b;
	a.x=4;
	a.y=9;
	b.x=4;
	b.y=7;
	float dx = b.x - a.x;
	float dy = b.y - a.y;
//	float khoang_cach = sqrt(dx*dx+dy*dy);
    float khoang_cach = sqrt(pow(dx,2)+pow(dy,2));
	printf("Khoang cach: %.2f",khoang_cach);
}
