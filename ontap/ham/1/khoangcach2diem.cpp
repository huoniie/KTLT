//Tinh khoang cach giua 2 diem trong toa do 3 chieu
#include <stdio.h>
#include <math.h>

typedef struct
{
	float x;
	float y;
	float z;
}ToaDo;

ToaDo nhap(char tenDiem)
{
    ToaDo m;
    printf("\nNhap toa do diem %c(x, y, z) = ", tenDiem);
    scanf("%f %f %f", &m.x, &m.y, &m.z);
    return m; 
}

void TinhKhoangCach( ToaDo A , ToaDo B )
{
	float dx = B.x - A.x;
	float dy = B.y - A.y;
	float dz = B.z - A.z;
	
	float KhoangCach = sqrt (pow(dx,2)+pow(dy,2) +pow(dz,2));
	printf("\nKhoang cach giua 2 diem A va B %.2f",KhoangCach);
}

int main()
{
	printf("\nTinh khoang cach giua 2 diem A va B");
	ToaDo A = nhap ('A');
	ToaDo B = nhap ('B');
	TinhKhoangCach( A , B );
	
	
}
