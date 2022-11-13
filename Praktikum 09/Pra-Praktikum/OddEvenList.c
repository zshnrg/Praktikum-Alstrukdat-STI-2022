/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 6 November 2022
Topik       : List Linier
Deskripsi   : Implementasi OddEvenList.h
*/

#include <stdio.h>
#include "OddEvenList.h"

void sortList(List *L) {
    List temp;
    CreateEmpty(&temp);
    while (!IsEmpty(*L)) {
        address P;
        address max = AdrMax(*L);
        address precMax = First(*L);
        P = First(*L);
        while (P != max) {
            precMax = P;
            P = Next(P);
        }
        if (P == precMax) {
            DelFirst(L, &max);
        } else {
            DelAfter(L, &max, precMax);
        }
        InsertFirst(&temp, max);
    }
    First(*L) = First(temp);
}

void OddEvenList(List L, List *Odd, List *Even) {
    CreateEmpty(Odd);
    CreateEmpty(Even);

    address P = First(L);
    while (P != Nil) {
        if (Info(P) % 2 == 0) {
            InsVFirst(Even, Info(P));
        } else {
            InsVFirst(Odd, Info(P));
        }
        P = Next(P);
    }
    sortList(Odd);
    sortList(Even);
}