/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 13 November 2022
Topik       : Variasi List Linear
Deskripsi   : Mengembalikan elemen list ke N
*/

#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
    address P = First(L);
    for (int ctr = 0; ctr < r; ctr++) {
        P = Next(P);
    }
    return Info(P);
}

int main () {
    List L;
    int r;
  
    CreateEmpty(&L);
    do {
        scanf("%d", &r);
        if (r != 0) InsVLast(&L, r);
    } while (r != 0);

    scanf("%d", &r);
    if (!IsEmpty(L)) {
        printf("%d\n", ElemenKeN(L, r));
    } else {
        printf("List Kosong\n");
    }
    
    return 0;
}