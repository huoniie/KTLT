#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char** Nhap(int* n) {
    do {
        printf("\nNhap so luong ten game: ");
        scanf("%d", n);
    } while (*n <= 0);

    char** tenGame = (char**) malloc((*n) * sizeof(char*));
    if (tenGame == NULL) exit(1);

    for (int i = 0; i < *n; i++) {
        tenGame[i] = (char*) malloc(100 * sizeof(char));
        
        printf("Game %d: ", i + 1);
        scanf(" %[^\n]", tenGame[i]); 
    }
    
    return tenGame;
}

void TenGameCoDoDaiLonNhat(char** tenGame, int n) {
    int max = strlen(tenGame[0]);
    int viTri = 0;
    
    for (int i = 1; i < n; i++) {
        if (strlen(tenGame[i]) > max) {
            max = strlen(tenGame[i]);
            viTri = i;
        }
    }
    printf("Ten game co do dai lon nhat la: '%s' (%d ky tu)\n", tenGame[viTri], max);
}

void DemGameCoInner(char** tenGame, int n) {
    int dem = 0;
    printf("\nCac game co chua tu 'inner':\n");
    
    for (int i = 0; i < n; i++) {
        if (strstr(tenGame[i], "inner") != NULL) {
            printf(" %s\n", tenGame[i]);
            dem++;
        }
    }
    
    if (dem > 0) printf("Co %d game.\n", dem);
    else printf("Khong co game nao chua tu 'inner'.\n");
}

void TimGameTheoKyTu(char** tenGame, int n) {
    char c;
    printf("\nNhap 1 ky tu bat dau de tim kiem: ");
    scanf(" %c", &c);
    
    int dem = 0;
    printf("Cac game bat dau bang ky tu '%c':\n", c);
    for (int i = 0; i < n; i++) {
        if (tenGame[i][0] == c) {
            printf("%s\n", tenGame[i]);
            dem++;
        }
    }
    if (dem == 0) printf("\nKHong co game nao co ki tu nhu the\n");
}

void SapXepGiamDan(char** tenGame, int n) {
    for (int i = 0; i < n - 1; i++) {
        int key = i;
        for (int j = i + 1; j < n; j++) {
            if (strlen(tenGame[j]) > strlen(tenGame[key])) {
                key = j;
            }
        }
        if (key != i) {
            char* temp = tenGame[i];
            tenGame[i] = tenGame[key];
            tenGame[key] = temp;
        }
    }
    
    printf("\nDanh sach game sau khi sap xep do dai giam dan\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s (%d ky tu)\n", i + 1, tenGame[i], (int)strlen(tenGame[i]));
    }
}

void TimKiemGame(char** tenGame, int n) {
    char tk[100];
    printf("\n5. Nhap ten game can tim khao sat: ");
    scanf(" %[^\n]", tk);
    
    bool thay = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(tenGame[i], tk) == 0) {
            thay = true;
            break;
        }
    }
    
    if (thay) printf("\ntim thay '%s' trong danh sach.\n", tk);
    else printf("\nKHong co trong danh sach\n", tk);
}

int main() {
    int n;
    char** dsGame = Nhap(&n);
    
    TenGameCoDoDaiLonNhat(dsGame, n);
    DemGameCoInner(dsGame, n);
    TimGameTheoKyTu(dsGame, n);
    SapXepGiamDan(dsGame, n);
    TimKiemGame(dsGame, n);
    
    for (int i = 0; i < n; i++) {
        free(dsGame[i]); 
    }
    free(dsGame); 
    
}
