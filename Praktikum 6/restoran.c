/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 17 Oktober 2022
Topik       : Queue
Deskripsi   : Realisasi restoran Ibu Gra
*/

#include <stdio.h>
#include "queue.h"

int main() {
    int N, jml = 0, min = 0, max = 0, time, val;
    Queue antrian;
    CreateQueue(&antrian);
    scanf("%d", &N);
    while (N != 0) {
        if (N == 1) {
            scanf("%d", &time);
            if (time > 0) {
                enqueue(&antrian, time);
            }
        }
        if (N == 2 && !isEmpty(antrian)) {
            dequeue(&antrian, &val);
            if (min == 0 || max == 0) {
                min = val; max = val;
            } if (min > val) {
                min = val;
            } if (max < val) {
                max = val;
            }
            jml++;
        }
        scanf("%d", &N);
    }
    printf("%d\n%d\n%d\n", jml, min, max);
}