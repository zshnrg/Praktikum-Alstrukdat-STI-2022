/*
Nama        : Rozan Ghosani
NIM         : 18221121
Tanggal     : 30 Oktober 2022
Topik       : Set, Map, dan Hash
Deskripsi   : implementasi hashmap.h
*/

#include <stdio.h>
#include "hashmap.h"


/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi key & value map Undefined */
{
    for (int i = 0; i < MaxEl; i++) {
        (*M).Elements[i].Key = Undefined;
        (*M).Elements[i].Value = Undefined;
    }
    (*M).Count == Nil;
}

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K)
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */
{
    return K % MaxEl;
}

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
{
    boolean found;
    int i = Hash(k);
    while (M.Elements[i].Key != Undefined && !found && i < MaxEl) {
        if (M.Elements[i].Key == k) {
            found = true;
        } else if (i < MaxEl - 1){
            i++;
        }
    }
    if (found) {
        return M.Elements[i].Value;
    } else {
        return Undefined;
    }
}

void Insert(HashMap *M, keytype k, valuetype v)
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing linear probing dengan interval 1 jika index sudah terisi    */
{
    boolean found = false;
    int i = Hash(k);
    while ((*M).Elements[i].Key != Undefined && !found && i < MaxEl) {
        if ((*M).Elements[i].Key == k) {
            found = true;
        } else if (i < MaxEl - 1){
            i++;
        }
    }
    if (!found && (*M).Elements[i].Key == Undefined) {
        (*M).Elements[i].Key = k;
        (*M).Elements[i].Value = v;
        (*M).Count++;
    }
}