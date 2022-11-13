/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 16 Oktober 2022
Topik       : Queue
Deskripsi   : Implementasi reverse.h
*/

#include <stdio.h>
#include "reverse.h"

void transferReverse(Queue* q1, Queue* q2)
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik
{
    int i = (*q1).TAIL;
    do {
        Push(q2, (*q1).Tab[i]);
        i = (i - 1 + (*q1).MaxEl) % (*q1).MaxEl;
    } while (i != (*q1).HEAD);
    Push(q2, Front(*q1));
}