/*
Nama            : Rozan Ghosani
NIM             : 18221121
Tanggal         : 5 September 2022
Topik           : Praktikum 1 - Pengenalan Praktikum
Deskripsi       : Bilangan subset genap
*/

#include <stdio.h>

int main () {
    // KAMUS
    int n, i, flag = 0;
    // ALGORITMA
    scanf("%d", &n);
    for (i = 2; i < n; i += 2) {
        if ((n-i) % 2 == 0) {
            flag = 1; break;
        }
    }
    if (flag == 1) {
        printf("Ya\n");
    } else {
        printf("Tidak\n");
    }
    return 0;
}