/*
Nama            : Rozan Ghosani
NIM             : 18221121
Tanggal         : 9 September 2022
Topik           : Pengenalan Bahasa C
Deskripsi       : Bilangan Cantik
*/

#include <stdio.h>
int jumlahcantik (int x);
int adatujuh (int x);

int main () {
    // KAMUS
    int n, i, m;
    // ALGORITMA
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        printf("%d\n", jumlahcantik(m));
    }
    return 0;
}

int adatujuh (int x) {
    // KAMUS
    int flag = 0;
    // ALGORITMA
    while (x != 0) {
        if (x % 10 == 7) {
            flag = 1;
        }
        x = x / 10;
    }
    return flag;
}

int jumlahcantik (int x) {
    // KAMUS
    int i, sum = 0;
    // ALGORITMA
    for (i = 1; i <= x; i++) {
        if (adatujuh(i) == 1 || (i % 7 == 0)) {
            sum += i;
        }
    }
    return sum;
}