/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 17 Oktober 2022
Topik       : Queue
Deskripsi   : Implementasi copyqueue.h
*/

#include <stdio.h>
#include "copyqueue.h"

void copyQueue(Queue *queueInput, Queue *queueOutput) {
    ElType val;
    for (int i = 0; i < length(*queueInput); i++) {
        dequeue(queueInput, &val);
        enqueue(queueInput, val);
        enqueue(queueOutput, val);
    }
}