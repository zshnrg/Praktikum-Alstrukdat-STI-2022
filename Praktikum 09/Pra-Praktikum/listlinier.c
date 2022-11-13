/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 6 November 2022
Topik       : List Linier
Deskripsi   : Implementasi listlinier.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmpty (List L) {
    return First(L) == Nil;
}

void CreateEmpty (List *L) {
    First(*L) = Nil;
}


address Alokasi (infotype X) {
    address P;
    P = (address) malloc (sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    } else {
        return Nil;
    }
}

void Dealokasi (address *P) {
    free(*P);
}

address Search (List L, infotype X) {
    address P = First(L);
    while (P != Nil) {
        if (Info(P) == X) {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

void InsVFirst (List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        InsertFirst(L, P);
    }
    
}

void InsVLast (List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        InsertLast(L, P);
    }
}

void DelVFirst (List *L, infotype *X) {
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X) {
    address P;
    DelLast(L, &P);
    (*X) = Info(P);
    Dealokasi(&P);
}

void InsertFirst (List *L, address P) {
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P) {
    if (IsEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        address loc = First(*L);
        while (Next(loc) != Nil) {
            loc = Next(loc);
        }
        Next(loc) = P;
    }
}

void DelFirst (List *L, address *P) {
    (*P) = First(*L);
    First(*L) = Next(*P);
}

void DelP (List *L, infotype X) {
    address P = Search((*L), X);
    if (P != Nil) {
        if (P == First(*L)) {
            DelFirst(L, &P);
            Dealokasi(&P);
        } else { 
            address loc = First(*L);
            while (Next(loc) != P) {
                loc = Next(loc);
            }
            Next(loc) = Next(P);
            Dealokasi(&P);
        }
    }
}

void DelLast (List *L, address *P) {
    address loc = First(*L);
    address prec = Nil;
    while (Next(loc) != Nil) {
        prec = loc;
        loc = Next(loc);
    }
    (*P) = loc;
    if (prec == Nil) {
        First(*L) = Nil;
    } else {
        Next(prec) = Nil;
    }
}

void DelAfter (List *L, address *Pdel, address Prec) {
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

void PrintInfo (List L) {
    printf("[");
    address P = First(L);
    while (P != Nil) {
        printf("%d", Info(P));
        if (Next(P) != Nil) printf(",");
        P = Next(P);
    }
    printf("]");
}
int NbElmt (List L) {
    int n = 0;
    address P = First(L);
    while (P != Nil) {
        n++;
        P = Next(P);
    }
    return n;
}

infotype Max (List L) {
    address P = First(L);
    infotype max = Info(P);
    while (Next(P) != Nil) {
        P = Next(P);
        if (Info(P) > max) max = Info(P);
    }
    return max;
}

address AdrMax (List L) {
    address P = First(L);
    infotype max = Max(L);
    while (P != Nil) {
        if (Info(P) == max) return P;
        P = Next(P); 
    }
}

infotype Min (List L) {
    address P = First(L);
    infotype min = Info(P);
    while (Next(P) != Nil) {
        P = Next(P);
        if (Info(P) < min) min = Info(P);
    }
    return min;
}

address AdrMin (List L) {
    address P = First(L);
    infotype min = Min(L);
    while (P != Nil) {
        if (Info(P) == min) return P;
        P = Next(P); 
    }
}

float Average (List L) {
    address P = First(L);
    int sum = 0, count = 0;
    while (P != Nil) {
        sum += Info(P); count++;
        P = Next(P);
    }
    return sum / count;
}

void InversList (List *L) {
    int loop = NbElmt(*L);
    if (!IsEmpty(*L)) {
        address temp, prec;
        DelLast(L, &temp);
        InsertFirst(L, temp);
        prec = temp;
        for (int i = 1; i < loop; i++) {
            DelLast(L, &temp);
            InsertAfter(L, temp, prec);
            prec = temp;
        }
    }
}

void Konkat1 (List *L1, List *L2, List *L3) {
    First(*L3) = First(*L1);
    address P = First(*L3);
    if (P != Nil) {
        while (Next(P) != Nil) {
            P = Next(P);
        }
        Next(P) = First(*L2);
    } else {
        First(*L3) = First(*L2);
    }
    First(*L1) = Nil;
    First(*L2) = Nil;
}
