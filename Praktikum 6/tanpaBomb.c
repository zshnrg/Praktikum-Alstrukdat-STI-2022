/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 17 Oktober 2022
Topik       : Queue
Deskripsi   : Implementasi tanpaBom.h
*/

#include <stdio.h>
#include "tanpaBomb.h"

Queue tanpaBomb(Queue queue, ElType bomb) {
    Queue New;
    ElType val;
    CreateQueue(&New);
    while (!isEmpty(queue)) {
        dequeue(&queue, &val);
        if (val != bomb) {
            enqueue(&New, val);
        }
    }
    return New;
}