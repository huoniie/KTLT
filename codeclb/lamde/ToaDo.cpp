/*Struct toa do doc tu file gom N diem x y

Tìm 2 diem gan nhau nhat

sap xep tang dan khoang cách các diem den goc toa do*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    char tend[10]; 
    float x;
    float y;
} ToaDo;

float tinhKC(ToaDo d1, ToaDo d2) {
    return sqrt(pow(d1.x - d2.x, 2) + pow(d1.y - d2.y, 2));
}

float tinhKCO(ToaDo d) {
    return sqrt(pow(d.x, 2) + pow(d.y, 2));
}

FILE* MoFileDoc() {
    char tenf[30];
    printf("\nNhap ten file: ");
    scanf(" %[^\n]", tenf);
    FILE* f = fopen(tenf, "r");
    if (f == NULL) {
        printf("\nLoi mo file! ");
        exit(1);
    }
    return f; 
}

ToaDo* DocFile(FILE* f, int n) {
    ToaDo* td = (ToaDo*)malloc(n * sizeof(ToaDo));
    for (int i = 0; i < n; i++) {
        fscanf(f, " %s %f %f", td[i].tend, &td[i].x, &td[i].y);
    }
    printf("\nDoc du lieu thanh cong!");
    return td;
}


void Tim2DiemGanNhat(ToaDo* td, int n) {
    if (n < 2) return;
    float min = tinhKC(td[0], td[1]);
    int id1 = 0, id2 = 1;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            float d = tinhKC(td[i], td[j]);
            if (d < min) {
                min = d;
                id1 = i;
                id2 = j;
            }
        }
    }
    printf("\n2 diem gan nhau nhat la: %s va %s (KC: %.2f)", td[id1].tend, td[id2].tend, min);
}

void SapXepTheoGocO(ToaDo* td, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tinhKCO(td[i]) > tinhKCO(td[j])) {
                ToaDo temp = td[i];
                td[i] = td[j];
                td[j] = temp;
            }
        }
    }
    printf("\nDanh sach sau khi sap xep tang dan den goc O:");
    for (int i = 0; i < n; i++) {
        printf("\n%s (%.1f, %.1f) - KC den O: %.2f", td[i].tend, td[i].x, td[i].y, tinhKCO(td[i]));
    }
}

int main() {
    int n;
    FILE* f = MoFileDoc();
    fscanf(f, "%d", &n); 
    
    ToaDo* td = DocFile(f, n);
    fclose(f);

    Tim2DiemGanNhat(td, n);
    SapXepTheoGocO(td, n);

    free(td);
    return 0;
}
