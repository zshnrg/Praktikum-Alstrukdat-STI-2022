/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 3 Oktober 2022
Topik       : Mesin
Deskripsi   : Realisasi fungsi hitungkarakter
*/

#include <stdio.h>
#include "mesinkarakter.h"
#include <string.h>

static FILE *pita;
char currentChar;
boolean EOP;

int hitungkarakter(char karakter) {
    // KAMUS
    int count = 0;
    // ALGORTIMA
    START();
    while (!IsEOP()) {
        if (tolower(karakter) == tolower(GetCC())) {
            count++;
        }
        ADV();
    }
    return count;
}