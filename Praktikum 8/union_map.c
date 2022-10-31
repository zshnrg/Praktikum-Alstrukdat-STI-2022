/*
Nama		: Rozan Ghosani
NIM			: 18221121	
Tanggal		: 31 Oktober 2022
Topik		: Set, Map, dan Hash
Deskripsi	: Implementasi union_map.h
*/

#include <stdio.h>
#include "union_map.h"
#include "boolean.h"


Map UnionMap(Map m1, Map m2, boolean key_based ) 
    /* Menggabungkan m1 dengan m2 pada sebuah map baru dengan urutan yang ditentukan berdasarkan key_based
    apabila key_based true maka elemen dalam map baru ditambahkan mengurut membesar berdasarkan keynya
    apabila key_based false maka elemen dalam map baru ditambahkan mengurut membesar berdasarkan valuenya*/

    /*I.S : Map m1 dan m2 terdefinisi. m1 dan m2 TIDAK kosong dan TIDAK penuh
    F.S : Map m3 yang merupakan gabungan isi dari m1 dan m2 yang diisi berdasarkan nilai key_based. Jumlah elemen m3 TIDAK mungkin melebihi MaxEl*/

    /*Notes: 
        1. Apabila terdapat nilai key yg sama pada m1 dan m2, value yang akan ditambah pada map baru adalah value dari m1 pada key tersebut
        2. Ingat yang unik adalah key, bukan value
    Hint: Lakukan penambahan semua elemen dari m1 dan m2 ke m3 terlebih dahulu kemudian urutkan isinya menggunakan algoritma sorting*/
    
    /*
    Contoh:
        1.Input(format <key,value>):
            m1: {<7,1>,<1,2>,<20,3>}
            m2: {<8,100>,<11,10>}
            key_based: true
          Output:
            m3: {<1,2>,<7,1>,<8,100>,<11,10>,<20,3>}
        2.Input(format <key,value>):
            m1: {<7,1>,<1,2>,<20,3>}
            m2: {<8,100>,<11,10>}
            key_based: false
          Output:
            m3: {<7,1>,<1,2>,<20,3>,<11,10>,<8,100>}
    */
{
	Map Union;
	infotype temp;
	int i, j;
	CreateEmpty(&Union);
	
	for (i = 0; i < m1.Count; i++) {
		Insert(&Union, m1.Elements[i].Key, m1.Elements[i].Value);
	} for (i = 0; i < m2.Count; i++) {
		Insert(&Union, m2.Elements[i].Key, m2.Elements[i].Value);
	}
	
	Map Ordered; CreateEmpty(&Ordered);
	int loop = Union.Count;
	for (i = 0; i < loop; i++) {
		int keyMin = Union.Elements[0].Key;
		int valMin = Union.Elements[0].Value;
		for (j = 0; j < Union.Count; j++) {
			if (key_based) {
				if (Union.Elements[j].Key < keyMin) {
					keyMin = Union.Elements[j].Key;
					valMin = Union.Elements[j].Value;
				}
			} else {	
				if (Union.Elements[j].Value < valMin) {
					keyMin = Union.Elements[j].Key;
					valMin = Union.Elements[j].Value;
				}
			}
		}
		Insert(&Ordered, keyMin, valMin);
		Delete(&Union, keyMin);
	}
	return Ordered;
}