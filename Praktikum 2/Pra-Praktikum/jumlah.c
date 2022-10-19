/*
Nama            : Rozan Ghosani
NIM             : 18221121
Tanggal         : 9 September 2022
Topik           : Praktikum 2 - Pointer dan Array Dinamik
Deskripsi       : Jumlah digit
*/

#include <stdio.h>

int main () {
    // KAMUS
    int n, sum = 0;
    // ALGORITMA
    scanf("%d", &n);
    while (n != 0) {
        sum += n % 10;
        n = n / 10;
    }
    printf("%d\n", sum);

    return 0;
}