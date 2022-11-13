/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 26 September 2022
Topik       : ADT List
Deskripsi   : Implementasi MinMax.h
*/

#include <stdio.h>
#include "MinMax.h"

List MinMax(List L){
    IdxType i = 0,j = 0, IdxMax=0, IdxMin=0;
    ElType Max = L.A[0];
    ElType Min = L.A[0];
    for (i = 0; i <= LastIdx(L); i++) {
        if (L.A[i] < Min) {
            Min = L.A[i];
            IdxMin = i;
        }
    }
    DeleteAt(&L, IdxMin);
    InsertLast(&L, Min);

    for (j = 0; j <= LastIdx(L); j++) {
        if (L.A[j] > Max) {
            Max = L.A[j];
            IdxMax = j;
        }
    }        
    DeleteAt(&L, IdxMax);
    InsertLast(&L, Max);
    return L;
}

    