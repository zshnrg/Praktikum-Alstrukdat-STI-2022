/*
Nama            : Rozan Ghosani
NIM             : 18221121
Tanggal         : 9 September 2022
Topik           : Praktikum 2 - Pointer dan Array Dinamik
Deskripsi       : cetak persegi
*/

#include <stdio.h>

int main () {
    // KAMUS
    int n, i, j;
    // ALGORITMA
    scanf("%d", &n);
    for (i = 0; i < (2*n - 1); i++) {
        for (j = 0; j < (2*n - 1); j++) {
            if ((i + j) % 2 == 0) {
                printf("O");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
    return 0;
}