/*
Nama            : Rozan Ghosani
NIM             : 18221121
Tanggal         : 9 September 2022
Topik           : Pengenalan Bahasa C
Deskripsi       : Reverse Integer
*/

#include <stdio.h>

int main () {
    // KAMUS
    int n, i;
    // ALGORITMA
    scanf("%d", &n);
    while (n != 0) {
        printf("%d", n % 10);
        n = n / 10;
    }
    printf("\n");
    return 0;
}