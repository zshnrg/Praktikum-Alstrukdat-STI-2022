/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 21 Oktober 2022
Topik       : Stack
Deskripsi   : Program Palindrom
*/

#include <stdio.h>
#include "stack.h"

boolean isEq(Stack S1, Stack S2) {
    boolean diff = false;
    infotype val1, val2;
    while (!IsEmpty(S1) && !diff) {
        Pop(&S1, &val1);
        Pop(&S2, &val2);
        if (val1 != val2) {
            diff = true;
        }
    }
    return !diff;
}

int main() {
    Stack Kata, temp1, temp2;
    int com, val;
    CreateEmpty(&Kata);
    CreateEmpty(&temp1);
    CreateEmpty(&temp2);
    do {
        scanf("%d", &com);
        if (com != 0) {
            Push(&Kata, com);
        }
    } while (com != 0);
    if (!IsEmpty(Kata)) {
        temp1 = Kata;
        while (!IsEmpty(Kata)) {
            Pop(&Kata, &val);
            Push(&temp2, val);
        }
        if (isEq(temp1, temp2)) {
            printf("Palindrom\n");
        } else {
            printf("Bukan Palindrom\n");
        }
    } else {
        printf("Stack kosong\n");
    }
    return 0;
}