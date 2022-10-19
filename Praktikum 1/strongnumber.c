/*
Nama            : Rozan Ghosani
NIM             : 18221121
Tanggal         : 5 September 2022
Topik           : Praktikum 1 - Pengenalan Praktikum
Deskripsi       : Supernumber
*/

#include <stdio.h>

int factorial (int x);

int main () {
    // KAMUS
    int n, tmp, digit, result = 0;

    // ALGORITMA
    scanf("%d", &n);
    tmp = n;

    while (tmp != 0) {
        digit = tmp % 10;
        result += factorial(digit);
        tmp = tmp / 10;
    }
    if (result == n) {
        printf("Y\n");
    } else {
        printf("N\n");
    }
}

int factorial (int x) {
    // KAMUS
    int i, result = 1;
    for (i = 1; i <= x; i++) {
        result = result * i;
    }
    return result;
}