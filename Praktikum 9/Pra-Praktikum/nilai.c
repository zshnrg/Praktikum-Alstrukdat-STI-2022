/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 6 November 2022
Topik       : List Linier
Deskripsi   : Program Pengelola Statistik Daftar Nilai
*/

#include <stdio.h>
#include "listlinier.h"

int main() {
    int comm;
    List nilai; CreateEmpty(&nilai);

    do {
        scanf("%d", &comm);
        if (comm >= 0 && comm <= 100) {
            InsVLast(&nilai, comm);
        }
    } while (comm >= 0 && comm <= 100);

    if (NbElmt(nilai) > 0) {
        printf("%d\n%d\n%d\n%.2f\n", NbElmt(nilai), Max(nilai), Min(nilai), Average(nilai));
        PrintInfo(nilai);
        InversList(&nilai);
        printf("\n"); 
        PrintInfo(nilai);
        printf("\n");
    } else {
        printf("Daftar nilai kosong\n");
    }
}