/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 24 Oktober 2022
Topik       : Stack
Deskripsi   : Big integer substraction
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
// infotype stack yang digunakan adalah integer

void ReadIntToStack (Stack *S) {
    char *str; str = (char*) malloc (100 * sizeof(char));
    scanf("%s", str);
    int i = 0;
    while (str[i] != '\0' && i != 100) {
        Push(S, str[i] - '0');
        i++;        
    }
}

void DisplayStack(Stack S) {
    infotype val;
    // Ignore blank 0
    Pop(&S, &val);
    if (val == 0 && !IsEmpty(S)) {
        do {
            Pop(&S, &val);
        } while (val == 0 && !IsEmpty(S));
    }
    Push(&S, val);
    while (!IsEmpty(S)) {
        Pop(&S, &val);
        printf("%d", val);
    }
    printf("\n");
}

boolean GreaterOrEq(Stack S1, Stack S2) {
    infotype val1, val2;
    Stack temp1, temp2; CreateEmpty(&temp1); CreateEmpty(&temp2);

    while (!IsEmpty(S1) && !IsEmpty(S2)) {
        Pop(&S1, &val1); Push(&temp1, val1);
        Pop(&S2, &val2); Push(&temp2, val2);
    }
    do {
        Pop(&temp1, &val1); Pop(&temp2, &val2);
        if (val1 > val2) {
            return true;
        } else if (val1 < val2) {
            return false;
        }
    } while (!IsEmpty(temp1));
    return (IsEmpty(S2));
}

Stack Substract(Stack S1, Stack S2) {
    // I.S. S1 >= S2
    Stack result; CreateEmpty(&result);
    infotype val1, val2;
    while (!IsEmpty(S2)) {
        Pop(&S1, &val1); Pop(&S2, &val2);
        if (val1 - val2 < 0) {
            Push(&result, val1 + 10 - val2);
            Pop(&S1, &val1);
            Push(&S1, val1 - 1);
        } else {
            Push(&result, val1 - val2);
        }
    }
    while (!IsEmpty(S1)) {
        Pop(&S1, &val1); Push(&result, val1);
    }
    return result;
}

int main() {
    Stack int1, int2, result;

    CreateEmpty(&int1);
    CreateEmpty(&int2);
    CreateEmpty(&result);
    ReadIntToStack(&int1);
    ReadIntToStack(&int2);

    if (GreaterOrEq(int1, int2)) {
        result = Substract(int1, int2);
    } else {
        printf("-");
        result = Substract(int2, int1);
    }
    DisplayStack(result);
    return 0;
}