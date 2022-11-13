/*
Nama            : Rozan Ghosani
NIM             : 18221121
Tanggal         : 9 September 2022
Topik           : Praktikum 2 - Pointer dan Array Dinamik
Deskripsi       : Equal string
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    // KAMUS
    int i, flag = 1;
    char *str1, *str2;
    // ALGORITMA
    
    str1 = (char *) malloc (100 * sizeof (char));
    scanf("%s", str1);
    
    str2 = (char *) malloc (100 * sizeof (char));
    scanf("%s", str2);

    if (strlen(str1) == strlen(str2)) {
        for (i = 0; i < strlen(str1); i++) {
            if ((str1[i] != str2[i] + 32) && (str1[i] + 32 != str2[i]) && (str1[i] != str2[i])) {
                flag = 0;
            }
        }
    } else {
        flag = 0;
    }

    if (flag == 0) {
        printf("Tidak\n");
    } else {
        printf("Ya\n");
    }

    return 0;
}