/*
Nama            : Rozan Ghosani
NIM             : 18221121
Tanggal         : 9 September 2022
Topik           : Pengenalan Bahasa C
Deskripsi       : Indeks Alstrukdat
*/

#include <stdio.h>

int main () {
    // KAMUS
    int n, mhs = 0, lulus = 0;
    float sum = 0;
    // ALGORITMA
    scanf("%d", &n);
    while (n != -999) {
        if (n >= 0 && n <= 4) {
            mhs++; sum += n;
            if (n >= 3) {
                lulus++;
            }
        }
        scanf("%d", &n);
    }
    if (mhs > 0) {
        printf("Jumlah mahasiswa yang lulus = %d\n", lulus);
        printf("Nilai rata-rata = %.2f\n", sum/mhs);
        printf("Indeks akhir kelas = ");
        if (sum/mhs < 1) {
            printf("E\n");
        } else if (sum/mhs < 2) {
            printf("D\n");
        } else if (sum/mhs < 3) {
            printf("C\n");
        } else if (sum/mhs < 4) {
            printf("B\n");
        } else if (sum/mhs == 4) {
            printf("A\n");
        }
    } else {
        printf("Tidak ada data\n");
    } 
    return 0;
}